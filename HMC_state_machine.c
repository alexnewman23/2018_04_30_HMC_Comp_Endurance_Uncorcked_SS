#include <stdint.h>
#include <string.h>
#include "stm32f4xx_can.h"
#include "HMC_state_machine.h"
#include 	"stm32f4xx_can.h"
#include "ring_buffer.h" // change
#include "DFR_SPI.h" // need for ready_to_drive_flag
#include "gear.h"


#define SUMMED_VOLTAGE_CONVERSION (2^16-1)
#define TRANSMIT_TO_BAMO_ID 0x500 // 0x210 

extern volatile input_vector_t input_vector;


volatile CanTxMsg bamocar_speed_msg = 
{
	TRANSMIT_TO_BAMO_ID,								//  uint32_t StdId;  /*!< Specifies the standard identifier.
										//                        This parameter can be a value between 0 to 0x7FF. */
										//
	0,					//  uint32_t ExtId;  /*!< Specifies the extended identifier.
										//                        This parameter can be a value between 0 to 0x1FFFFFFF. */
										//
	CAN_Id_Standard,	//  uint8_t IDE;     /*!< Specifies the type of identifier for the message that 
										//                        will be transmitted. This parameter can be a value 
										//                        of @ref CAN_identifier_type */
										//
	CAN_RTR_Data,			//  uint8_t RTR;     /*!< Specifies the type of frame for the message that will 
										//                        be transmitted. This parameter can be a value of 
										//                        @ref CAN_remote_transmission_request */
										//
	3,								//  uint8_t DLC;     /*!< Specifies the length of the frame that will be 
										//                        transmitted. This parameter can be a value between 
										//                        0 to 8 */
										//
										//  uint8_t Data[8]; /*!< Contains the data to be transmitted. It ranges from 0 
										//                        to 0xFF. */
	{0x31,    0, 0 , 0, 0, 0, 0, 0}
	// ^REGID
};
	
volatile CanTxMsg bamocar_torque_msg = 
{
	TRANSMIT_TO_BAMO_ID,								//  uint32_t StdId;  /*!< Specifies the standard identifier.
										//                        This parameter can be a value between 0 to 0x7FF. */
										//
	0,					//  uint32_t ExtId;  /*!< Specifies the extended identifier.
										//                        This parameter can be a value between 0 to 0x1FFFFFFF. */
										//
	CAN_Id_Standard,	//  uint8_t IDE;     /*!< Specifies the type of identifier for the message that 
										//                        will be transmitted. This parameter can be a value 
										//                        of @ref CAN_identifier_type */
										//
	CAN_RTR_Data,			//  uint8_t RTR;     /*!< Specifies the type of frame for the message that will 
										//                        be transmitted. This parameter can be a value of 
										//                        @ref CAN_remote_transmission_request */
										//
	5,								//  uint8_t DLC;     /*!< Specifies the length of the frame that will be 
										//                        transmitted. This parameter can be a value between 
										//                        0 to 8 */
										//
										//  uint8_t Data[8]; /*!< Contains the data to be transmitted. It ranges from 0 
										//                        to 0xFF. */
	{0x2F,    0, 0 , 00, 0x10, 0, 0, 0}
	// ^ OFFSET AND SCALE REGID (high and low)
	// Byte 3 and 4 (base 0), little endian for scale ... 0x1000 = 1.
	// if need be, scale of 2 would be 0x2000, 0x3000, 0x4000 and so on.
};




float desired_kP(void){

	
	int gear;

	/* Do we have to put in some timing thing????*/

	float kP_gear1 = .1;
	float kP_gear2 = .1;
	float kP_gear3 = .1;
	float kP_gear4 = .1;
	float kP_gear5 = .1;
	float kP_invalid = 0;
	float kP;

	gear = get_gear();

	switch(gear){

	case 1:
		kP = kP_gear1;
		break;
	case 2:
		kP = kP_gear2;
		break;
	case 3:
		kP = kP_gear3;
		break;
	case 4:
		kP = kP_gear4;
		break;
	case 5:
		kP = kP_gear5;
		break;
	case 0:
		kP = kP_invalid;
		break;
	}

	return kP;

}





#define RPM_MAX (3000.0f)
#define MIN_PACK_THRESHOLD (225.0f)
#define MAX_PACK_THRESHOLD (280.0f)
#define OFFSET_MAX (16384.0f)	
//#define OFFSET_MAX (4000.0f)

//float tps_percentage = ((input_vector.ice_tps - 5.0f)/(190.0f-10.0f));
// tps limit is now 183 max 4/24/18
#define LOWER_TPS_LIMIT (3.0f)
#define UPPER_TPS_LIMIT (194.0f)

float tps_percentage = 0.0f;
float calc_torque = 0.0f;
volatile float speed_command_debug;
volatile uint16_t torque_cmd;
int im_here = 0;


volatile bool	Tdebug;
volatile	uint32_t	DEBUG	=	0;


void electric_torque(bool torque_flag)
{
Tdebug = torque_flag;
	if (torque_flag)
	{
		// send torque command based on pedal position
		/* float temp = ((input_vector.accel_pot1-650.0f)/(1200.0f-650.0f))*OFFSET_MAX;
		*/
		// limits of ice tps ... low = 2 (so made it 3) high = 195 (so made it 194)
		float torqueDecayK;
		

		tps_percentage = ((input_vector.ice_tps- LOWER_TPS_LIMIT)/(UPPER_TPS_LIMIT-LOWER_TPS_LIMIT));
		
		if (input_vector.motor_mode) {
			torqueDecayK = 1;
		}
		else {
			if (input_vector.pack_voltage < MIN_PACK_THRESHOLD)
			{
					torqueDecayK = 0;
			}
			else if (input_vector.pack_voltage > MAX_PACK_THRESHOLD)
			{
				torqueDecayK = 1;
			}
			else
			{
				torqueDecayK = 1-((MAX_PACK_THRESHOLD-input_vector.pack_voltage)/(MAX_PACK_THRESHOLD-MIN_PACK_THRESHOLD));
			}
		}
		
		
		calc_torque = tps_percentage*torqueDecayK*OFFSET_MAX;
		
		if (calc_torque >= OFFSET_MAX) // fix...
		{
			calc_torque = OFFSET_MAX;
		}else
		if(calc_torque <= 0)
		{
			calc_torque = 0;
		}
		else
		{
			// leave it alone
		}
		
		torque_cmd = calc_torque; 
im_here = 1;
		//torque_cmd = 0;
		
//		bamocar_torque_msg.Data[1]	=	 (torque_cmd & 0x00FF);
//		bamocar_torque_msg.Data[2]	=	((torque_cmd & 0xFF00)>>8);
//		
//		add_to_output_ring(bamocar_torque_msg);
	}
	else
	{
DEBUG	=	torque_flag;
DEBUG++;
		// send 0 torque command
		torque_cmd = 0;
		
//		bamocar_torque_msg.Data[1]	=	 (torque_cmd & 0x00FF);
//		bamocar_torque_msg.Data[2]	=	((torque_cmd & 0xFF00)>>8);
//		
//		add_to_output_ring(bamocar_torque_msg);
	}

		bamocar_torque_msg.Data[1]	=	 (torque_cmd & 0x00FF);
		bamocar_torque_msg.Data[2]	=	((torque_cmd & 0xFF00)>>8);
		
		add_to_output_ring(bamocar_torque_msg);

}



float get_engine_torque(void){

	// float m_dot; /* mass air flow */
	// float temp
	float torque;
	float p_measured;
	float p_atm; // check units
	float temp_measured;
	float temp_atm; // check units, rankine or kelvin
	float torque_wot; // torque at Wide Open Throttle

	torque = torque_wot*p_measured/p_atm*temp_atm/temp_measured;

	torque = 1;
	/* torque = some function */
	// MAKE SURE THAT TORQUE IS IN NM!!!!! 

	return torque;

}
/* need calculator for torque */

	uint16_t current_output; // change type to some int
	float kT = .75f; // = Nm / (A rms) 
	uint16_t count = 2^15;
//	uint16_t max_current = 200; // Amps
		uint16_t max_current = 20; // Amps for testing

extern volatile CanTxMsg bamocar_msg;

/*
void torque_command(float motor_torque)
{
	current_output	=	(uint16_t)(motor_torque/kT)*(count/max_current);	
	
	bamocar_msg.Data[1]	=	 (current_output & 0x00FF);
	bamocar_msg.Data[2]	=	((current_output & 0xFF00)>>8);
	
	add_to_output_ring(bamocar_msg);
	
	//craft CAN message to output to torque */
	/* don't forget that the Unitek uses counts instead of torque */
	
	/* 
	should we put something for demoing in electric mode?
	*/

//}

volatile car_mode_t car_mode = car_init; // make external?
car_mode_t old_mode;


typedef enum lock_unlock_e {
	LU_UNLOCK = 0,
	LU_LOCK = 1,
}lock_unlock_t;

lock_unlock_t	lock_state = LU_UNLOCK;

uint8_t push_button_2_z1 = 0;

extern volatile int ready_to_drive_flag;
extern bool safety_init_done_flag;

//void lock_unlock_state(void){
//	
//	switch(lock_state){
//		case (LU_UNLOCK):
//		{
//			car_mode = (car_mode_t)( ((input_vector.motor_mode) |  input_vector.ice_mode << 1) + ((!safety_init_done_flag) << 2 )); // Double check with John to see if this makes sense

//			if(input_vector.push_button_2 & ~push_button_2_z1) // detect rising edge
//			{
//				lock_state = LU_LOCK;
//			}
//			else
//			{
//				// .. stay in LU_UNLOCK state
//			}
//		}
//		break;
//		
//		case(LU_LOCK):
//		{
//			if((!input_vector.motor_mode) && (!input_vector.ice_mode))
//			{
//				lock_state = LU_UNLOCK;
//			}
//			else
//			{
//				// .. stay in LU_UNLOCK state
//			}
//		}
//		break;
//	}
//	
//	push_button_2_z1 = input_vector.push_button_2;
//	old_mode = car_mode;
//	
//}

extern CAN_msg_t msgTable[];
// create vars for msg table indicies 

void assign_inputs(void){
	
	// Input Assignments
		
	// ATHENA inputs
	
	input_vector.engine_rpm = msgTable[0].data._16[1];
	input_vector.ice_tps = msgTable[0].data._8[4];
	input_vector.engine_MAP = msgTable[0].data._16[3];
	
	input_vector.eng_h2o_temp = msgTable[1].data._8[0]-40;
	input_vector.eng_air_temp = msgTable[1].data._8[1]-40;
	input_vector.eng_oil_temp = msgTable[1].data._8[2]-40;
	
	input_vector.eng_gear = msgTable[2].data._8[3];
	

	// EMUS BMS
	input_vector.pack_voltage_raw 		=  (msgTable[3].data._8[5] << 24) | (msgTable[3].data._8[6] << 16) | (msgTable[3].data._8[3] << 8) | (msgTable[3].data._8[3]); // test this
	input_vector.pack_voltage = (float)input_vector.pack_voltage_raw/100.0f;
	
	input_vector.min_cell_temp = msgTable[4].data._8[0] - 100; // offset by -100 (subtract 100)
	input_vector.max_cell_temp = msgTable[4].data._8[1] - 100; // offset by -100 (subtract 100)
	input_vector.avg_cell_temp= msgTable[4].data._8[2] - 100; // offset by -100 (subtract 100)
	
	input_vector.pack_current_raw = (msgTable[5].data._8[0] << 8) | (msgTable[5].data._8[1]); // endianness is weird.
	input_vector.pack_current = input_vector.pack_current_raw/(10.0f); // signed, divide by 10
	input_vector.pack_SOC = msgTable[5].data._8[6]; // raw val is percentage
	
	
		// ------ BAMOCAR inputs ------
		// Have to use memcpy() because it's 16bit data in an 8bit addres
		// find conversion rates
		
		// motor rpm
	memcpy((void*)&input_vector.motor_rpm_raw, (void*)&msgTable[6].data._8[1], sizeof(uint16_t));
	
	input_vector.motor_rpm = ((int32_t)input_vector.motor_rpm_raw*6000)/32767;
	
		// motor current
	memcpy((void*)&input_vector.motor_current, (void*)&msgTable[7].data._8[1], sizeof(uint16_t));
		// motor torque read value
	memcpy((void*)&input_vector.motor_torque_rdval, (void*)&msgTable[8].data._8[1], sizeof(uint16_t));
		// motor voltage
	memcpy((void*)&input_vector.motor_v_out, (void*)&msgTable[9].data._8[1], sizeof(uint16_t));
		// bamocar DOUT_2***************************
	memcpy((void*)&input_vector.bamocar_dout_2, (void*)&msgTable[10].data._8[1], sizeof(uint16_t));
		
		// motor fault
	memcpy((void*)&input_vector.bamocar_fault, (void*)&msgTable[11].data._8[1], sizeof(uint32_t));
	input_vector.bamocar_fault = input_vector.bamocar_fault & 0x93E70000; // **** MASK TO look at data ****
		
		// bamoar bus voltage
	memcpy((void*)&input_vector.bamocar_bus_voltage_raw, (void*)&msgTable[12].data._8[1], sizeof(uint16_t));
	
	input_vector.bamocar_bus_voltage = (float)input_vector.bamocar_bus_voltage_raw*96.0f/3600.0f;
	
		// bamocar DOUT_1 ***** MAKE SURE THIS IS THE RIGHT WAY TO GET DOUT1********
	memcpy((void*)&input_vector.bamocar_dout_1, (void*)&msgTable[13].data._8[1], sizeof(uint16_t));
	
	input_vector.motor_phase_voltage = (uint16_t)((input_vector.bamocar_bus_voltage/(1.41412f))*(input_vector.motor_current/4096)*(0.94f));
	
	// stand-ins to avoid erros
	input_vector.clutch_rdval = 0;
	
	// End of input assignments
}



	
