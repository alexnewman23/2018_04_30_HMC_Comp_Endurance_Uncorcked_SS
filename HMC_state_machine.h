#ifndef	_HMC_STATE_MACHINE_H_
#define	_HMC_STATE_MACHINE_H_	(1)

#include   <stdint.h>
#include   <string.h>
#include   <stdbool.h>
#include 	"stm32f4xx_can.h"


typedef enum car_mode_e{
	car_hybrid = 3,
	car_init = 4,
} car_mode_t;

enum HMC_states{
	brake_or_clutch,
	prop_torque,
}; 

/*
 * Various Funcion Declarations
 */
float desired_kP(void);
void electric_torque(bool);
float get_engine_torque(void);
//void torque_command(float motor_torque);

void set_mode (void);
void lock_unlock_state(void);
extern volatile CanTxMsg bamocar_torque_msg;

typedef struct Bamo_data_16_s{
	uint8_t REGID; // change back to uint8_t
	uint16_t data;
} Bamo_data_16_t;

typedef union CAN_data_u {
	uint64_t   _64;
	uint8_t    _8[8];
  uint16_t   _16[4];
  uint32_t   _32[2];
  float      _float[2];
  double     _double;

	Bamo_data_16_t Bamo_data_16;

	//Bamo_data_32_t Bamo_data_32;

} CAN_data_t;

typedef struct CAN_msg_s {
	uint32_t messageID;
	uint32_t messageType;
	uint32_t REGID;
 	CAN_data_t data;
	uint32_t update;
	int row;
	int col;
	char name[10];
	int msg_count;
	int old_count;
	int err_count;

} CAN_msg_t;


volatile typedef struct input_vector_s {
	
	
	// ------- ATHENA inputs --------
	
	uint16_t engine_rpm;
	uint8_t ice_tps;
	int16_t	engine_MAP;
	
	uint8_t eng_h2o_temp;
	uint8_t eng_air_temp;
	uint8_t eng_oil_temp;
	
	uint8_t eng_gear;
	
	// ------- BMS inputs -------
	
	// CAN ID: 0x03B
	int32_t	pack_voltage_raw;
	float pack_voltage;
	
	uint8_t min_cell_temp; // offset by -100 (subtract 100)
	uint8_t max_cell_temp; // offset by -100 (subtract 100)
	uint8_t avg_cell_temp; // offset by -100 (subtract 100)
	int16_t pack_current_raw; // signed, divide by 10
	float pack_current;

	uint8_t pack_SOC; // raw val is percentage
	
	
	// ------ BAMOCAR inputs ------
	
	 int16_t  motor_rpm_raw;
	 int16_t  motor_rpm;
	uint16_t	motor_current;
	uint16_t	motor_torque_rdval;
	uint16_t 	motor_v_out;
	uint16_t	bamocar_dout_2;
	uint16_t	bamocar_fault;
	uint16_t	bamocar_bus_voltage_raw;
	float			bamocar_bus_voltage;
	uint16_t	bamocar_dout_1;
	
	uint16_t	motor_phase_voltage;

	// ------ Gear -----
	uint8_t		gear; 
		
	// Clutch and Brake
	uint8_t clutch_val;
	uint8_t brake_val;
	


	uint8_t dash_brb_pressed; 
	uint8_t ice_mode;
	uint8_t motor_mode;
	uint8_t push_button_1;
	uint8_t push_button_2; // link to GO BUTTON!
	
	// stand-ins to resolve errors
	uint8_t clutch_rdval;
	
} input_vector_t;

extern volatile input_vector_t input_vector;
extern volatile car_mode_t mode;

bool bamocar_init (void);

volatile typedef struct SPI_output_vector_s{
	
	uint8_t solenoid_1; // downshift solenoid -- linked to red button
	uint8_t solenoid_2; // upshift solenoid -- linked to green button
	uint8_t safety;
	uint8_t ready_to_drive;
	uint8_t rfg;
	
}SPI_output_vector_t;

extern volatile SPI_output_vector_t SPI_output_vector;

void assign_inputs (void);

#endif	// _HMC_STATE_MACHINE_H_


