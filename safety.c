#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "stm32f4xx_can.h"
#include <stdbool.h>
#include "safety.h"
#include "HMC_state_machine.h"
#include "DFR_SPI.h"
#include "ring_buffer.h"

volatile safety_states_t safety_state = safety_init;

extern bool safety_init_done_flag;
extern volatile	CLT_Read_u_t	CLT_Read;
extern volatile int CAN_error_flag;
extern volatile int ready_to_drive_flag;
extern input_vector_t input_vector;
extern volatile car_mode_t car_mode;
extern volatile	uint32_t		JLM_Debug;
extern volatile CanTxMsg bamocar_var1_msg;
extern volatile CanTxMsg bamocar_var1_reset_msg;
int safety_error_count = 0;
#define SAFETY_ERROR_COUNT_LOAD 5
#define BUZZER_TIMER_LOAD 60 // 2000/50 = 60 --> 2 seconds
#define PRE_CHARGE_TIMER_LOAD 50 // 2500/50 = 50 --> 2.5 seconds

int ready_to_drive_count = 0;
volatile int ready_to_drive_flag = OFF; // make external, use in initialize

bool buzzer_done = false;
bool ready_to_drive_func (void)
{
	if(ready_to_drive_flag)
	{
		if(SPI_output_vector.ready_to_drive == OFF)
		{
			SPI_output_vector.ready_to_drive = ON;
			ready_to_drive_count++;
		} 
		else if(SPI_output_vector.ready_to_drive == ON && ready_to_drive_count >= (10000/50)) 
		{ // Nmilliseconds / 50
			ready_to_drive_flag = OFF;
			SPI_output_vector.ready_to_drive = OFF;
			ready_to_drive_count = 0;
			return true;
		}
		else 
		{
			ready_to_drive_count++;
		}
	} 
	else 
	{
		return false;
	}
	
	return false;
}
// need to set these
const float CLUTCH_POT1_MAX = 100.0f;
const float CLUTCH_POT2_MAX = 100.0f;
const float CLUTCH_TOL = 0.3f;

const float ACCEL_POT1_MAX = 100.0f;
const float ACCEL_POT2_MAX = 100.0f;
const float ACCEL_TOL = 0.3f;

float clutch_pot1_weighted;
float clutch_pot2_weighted;

float accel_pot1_weighted;
float accel_pot2_weighted;
float tps_weighted;

#define TPS_UPPER_THRESHOLD (0xD7)
#define TPS_LOWER_THRESHOLD (0x00)


volatile bool ACCEL_PEDAL_FAULT = false; 

typedef enum accel_pedal_fault_e {
	
	no_fault_state,
	fault_state,
} accel_pedal_fault_t;

accel_pedal_fault_t accel_pedal_fault_state = no_fault_state;

int accel_pedal_fault_state_count = 0;


bool pedal_safety_check(void)
{
		if(safety_state >= safety_three) {
			if(((int)input_vector.ice_tps >= TPS_UPPER_THRESHOLD) or ((int)input_vector.ice_tps <= TPS_LOWER_THRESHOLD))
				// fix this later... re-calibrate TPS
			{
				accel_pedal_fault_state_count++;
			}
			else
			{
				accel_pedal_fault_state_count = 0;
			}
			
			if(accel_pedal_fault_state_count >= 4)
			{
				accel_pedal_fault_state = fault_state;
				ACCEL_PEDAL_FAULT = true;
				accel_pedal_fault_state_count = 0;
			}
			else 
			{
				// stay here
			}
		}
		else {
			// do nothing
		}
		
	
	return ACCEL_PEDAL_FAULT;

}

int buzzer_timer = 0;
int pre_charge_timer = 0;
bool pre_charge_done_flag = false;
bool pre_charge_count_begin = false;
bool pre_charge_90p_voltage = false;



bool safety_output_check(void)
{
	
	 if (buzzer_timer)
	 {
				buzzer_timer--;
			SPI_output_vector.ready_to_drive = ON;
	 }
	 else
	 {
			SPI_output_vector.ready_to_drive = OFF;
			//
	 }
	 
	 if (pre_charge_timer){
		 pre_charge_timer--;
		 if(pre_charge_timer == 0){
			 pre_charge_done_flag = true;
		 }
		 else{
			 pre_charge_done_flag = false;
		 }
	 }
	 else{
		 //
	 }
	 
	 if(((input_vector.bamocar_bus_voltage < 100.0f) or (input_vector.dash_brb_pressed)) and 
		  (safety_state > safety_off) and (safety_state < safety_fault)){
					safety_state = safety_one;
					pre_charge_done_flag = false;
					pre_charge_count_begin = false;
					pre_charge_90p_voltage = false;
	 }
	 else {
		 // do nothing 
		 safety_state = safety_state;
	 }
	 
	 
	switch(safety_state)
	{
		
		case safety_init: // SAFETY_INIT COMES BEFORE SAFETY OFF!
		{
			SPI_output_vector.safety = OFF;
			SPI_output_vector.rfg = OFF;
			ready_to_drive_flag = OFF;  //buzzer
			
			if(safety_init_done_flag)
			{
				safety_state = safety_off;
			} 
			else 
			{
				safety_state = safety_init;  //wait for it
			}
		}
		break;
		
		case safety_off:
		{
			SPI_output_vector.safety = OFF;
			SPI_output_vector.rfg = OFF;
			ready_to_drive_flag = OFF;
			
			if
			(		  VNI_Read.bit.PG
				and !VNI_Read.bit.TWARN
				// and (VNI_Read.bit.nP0 == !VNI_Read.bit.P0)
				and (!CAN_error_flag)
			)
			{ // low true, double check if this works with John 
				safety_state = safety_one;
				safety_error_count = 0;
			}
			else
			{
				safety_error_count++;
				if(safety_error_count >= SAFETY_ERROR_COUNT_LOAD)
				{
					safety_error_count = 0;
					safety_state = safety_fault;
				}
				else
				{
					safety_state = safety_off;
				}
			}
		}
		break;
		
		case safety_one:
		{
			SPI_output_vector.safety = ON;
			SPI_output_vector.rfg = OFF;
			ready_to_drive_flag = OFF;
			
			// ****************SEND RESET MSG TO BAMOCAR***********************
			add_to_output_ring(bamocar_var1_reset_msg);
			
			if
			(			 VNI_Read.bit.PG
				and !VNI_Read.bit.TWARN
//				and (VNI_Read.bit.nP0 == ~VNI_Read.bit.P0)
				and (!CAN_error_flag)							// low true, double check if this works with John
				)
			{ 
				
				if (car_mode == car_hybrid) {
						safety_state = safety_two;
				} 
				else {
						safety_state = safety_one;
				}
			} 
			else
			{
				safety_error_count++;
				
				if(safety_error_count >= SAFETY_ERROR_COUNT_LOAD)
				{
					safety_error_count = 0;
					SPI_output_vector.ready_to_drive = OFF;
					safety_state = safety_fault;
				}
				else
				{
					safety_state = safety_four;
				}
			}
		}
		break;
		
		case safety_two:
		{
			SPI_output_vector.safety = ON;
			SPI_output_vector.rfg = OFF;
			// ready_to_drive_flag = OFF; // ***** PUT BACK!******
			
			if
			(			 VNI_Read.bit.PG
				and !VNI_Read.bit.TWARN
			//and (VNI_Read.bit.nP0 == ~VNI_Read.bit.P0)
				and (!CAN_error_flag)							// low true, double check if this works with John
				)
			{ 
				if(input_vector.pack_voltage > 150.0f){ // figure out why this is here ********* was 90.0f before
					if ((input_vector.bamocar_bus_voltage >= input_vector.pack_voltage * 0.8f)){
						pre_charge_90p_voltage = true;
					}
					else {
						pre_charge_90p_voltage = false;
					}
				}
				else {
					// do nothing...
				}
				
				if ((pre_charge_90p_voltage == true) && (pre_charge_count_begin == false)){
					pre_charge_timer = PRE_CHARGE_TIMER_LOAD;
					pre_charge_count_begin = true;
				}
				else{
				//
				}
				
				if ((pre_charge_90p_voltage ==  true) && (pre_charge_done_flag == true)) 
				{
					// ****************SEND SET MSG TO BAMOCAR***********************
					add_to_output_ring(bamocar_var1_msg);
					safety_state = safety_three;
					// reset all the pre-charge flags so when the brb is hit, it goes through
					// safety states over again instead of jumping through them.
					pre_charge_done_flag = false;
					pre_charge_count_begin = false;
					pre_charge_90p_voltage = false;
				} 
				else 
				{
					safety_state = safety_two;
				}
			} 
			else
			{				
				if(safety_error_count >= SAFETY_ERROR_COUNT_LOAD)
				{
					safety_error_count = 0;
					safety_state = safety_fault;
				}
				else
				{
					// do nothing
				}
			}
		}
		break;
		
		case safety_three:
		{
			SPI_output_vector.safety = ON;
			SPI_output_vector.rfg = OFF;
			// ready_to_drive_flag = OFF; // ***** PUT BACK!******
			
			if
			(			 VNI_Read.bit.PG
				and !VNI_Read.bit.TWARN
			//and (VNI_Read.bit.nP0 == ~VNI_Read.bit.P0)
				and (!CAN_error_flag)							// low true, double check if this works with John
				)
			{ 
				
				if (input_vector.push_button_2 == ON)
				{
					buzzer_timer = BUZZER_TIMER_LOAD;
					safety_state = safety_four;
				} 
				else 
				{
					safety_state = safety_three;
				}
			} 
			else
			{				
				if(safety_error_count >= SAFETY_ERROR_COUNT_LOAD)
				{
					safety_error_count = 0;
					safety_state = safety_fault;
				}
				else
				{
					// do nothing
				}
			}
			
		}
		break;
		
		case safety_four:
		{
			SPI_output_vector.safety = ON;
			SPI_output_vector.rfg = OFF;
			
			
			// buzzer_done = ready_to_drive_func();
			// below is to check if the switch for IC somehow goes low
//			if((car_mode == car_hybrid) & (!input_vector.ice_mode))
//				{	
//					SPI_output_vector.ready_to_drive = OFF;
//					safety_state = safety_init;
//				}
//				else 
			if (	//		CLT_Read.bit.PC1
				//and	CLT_Read.bit.PC2
						VNI_Read.bit.PG
				and !VNI_Read.bit.TWARN
				//and (VNI_Read.bit.nP0 == ~VNI_Read.bit.P0)
				and (!CAN_error_flag)							// low true, double check if this works with John
				)
				{ 
					if (buzzer_timer == 0)
					{
						SPI_output_vector.ready_to_drive = OFF;
						safety_state = safety_five;
					} 
					else 
					{
						safety_state = safety_four;
					}
				} 
				else
				{
					safety_error_count++;
					
					if(safety_error_count >= SAFETY_ERROR_COUNT_LOAD)
					{
						safety_error_count = 0;
						SPI_output_vector.ready_to_drive = OFF;
						safety_state = safety_fault;
					}
					else
					{
						// do nothing
					}
				}
		}
		break;
		
		case safety_five:
		{
			SPI_output_vector.safety = ON;
			SPI_output_vector.rfg = ON;
			ready_to_drive_flag = OFF;
			
//			if((car_mode == car_hybrid) and (!input_vector.ice_mode)) 
//			{
//				safety_state = safety_fault;
//			}
//			else 
				
			if(	//		CLT_Read.bit.PC1
				//and	CLT_Read.bit.PC2
					VNI_Read.bit.PG
				and !VNI_Read.bit.TWARN
//				and (VNI_Read.bit.nP0 == ~VNI_Read.bit.P0)
//				and (!CAN_error_flag)							// low true, double check if this works with John
//				and (input_vector.bamocar_bus_voltage <= 14000 && input_vector.bamocar_bus_voltage >= 11000) // voltage check
//				and (input_vector.motor_rpm <= 3000) // rpm limiter for driving
				and (!ACCEL_PEDAL_FAULT)
			//and (input_vector.motor_rpm <= 500) // rpm limiter for testing/demo for inspection

			)
			{ 
				
				safety_state = safety_five;
//				if(input_vector.dash_brb_pressed){
//					safety_state = safety_five;
//				}
//				else{
//					safety_state = safety_one;
//				}
			} 
			else
			{
				safety_error_count++;
			}
			
			if(safety_error_count >= SAFETY_ERROR_COUNT_LOAD)
			{
				safety_error_count = 0;
				safety_state = safety_fault; // if all else fails, comment out
			}
			else
			{
				// do nothing
			}
		}
		break;
		
		case safety_fault:
		{
			SPI_output_vector.safety = OFF;
			SPI_output_vector.rfg = OFF;
			ready_to_drive_flag = OFF;
			
			/* **** FOR DEMO ONLY!***** */
			safety_state = safety_fault;
			
			// reset CAN Error flag after 
		}
		break;
	}
	return true;
} 

