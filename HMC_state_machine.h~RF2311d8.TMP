#ifndef	_HMC_STATE_MACHINE_H_
#define	_HMC_STATE_MACHINE_H_	(1)

#include   <stdint.h>
#include   <string.h>
#include   <stdbool.h>
//#include 	"stm32f4xx_can.h"

/*
 * Enum Values Declarations
 */
enum gear {Gear1, Gear2, Gear3, Gear4, Gear5, Neutral, Shifting}; /*Gear State Enum Variable Declaration*/
enum shifter_io {on, off}; /*Shifter State Enum Variable Declaration*/

typedef enum car_mode_e{
	hybrid = 3,
	gas = 2,
	electric = 1,
	car_off = 0, 		// don't renumber them
	
	init = 4,
} car_mode_t;

enum HMC_states{
	brake,
	clutch,
	prop_torque,
}; 

/*
 * Various Funcion Declarations
 */
float desired_kP(void);
float electric_torque(void);
//int get_gear(void);
float get_engine_torque(void);
void torque_command(float motor_torque);
enum gear shifter_gas_mode(enum gear c_gear, int RPM, bool uPressed, bool dPressed, bool cPressed);
enum gear shifter_hybrid_mode(enum gear c_gear, int RPM, bool uPressed, bool dPressed, bool cPressed);
enum gear shifter_electric_mode(enum gear c_gear, int RPM, bool uPressed, bool dPressed, bool cPressed);
void set_mode (void);
void lock_unlock_state(void);

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

} CAN_msg_t;


volatile typedef struct input_vector_s {
	// ------- PE3 inputs ------
	
	uint16_t	engine_rpm;
	int16_t	engine_MAP;
	int16_t	engine_temp;
	
	int16_t	brake_rdval;
	int16_t clutch_rdval;
	int16_t	clutch_pot1;
	int16_t	clutch_pot2;
	
	int16_t	accel_rdval; // TPS
	int16_t accel_pot1;
	int16_t	accel_pot2;
	
	// ------- BMS inputs -------
	
	// CAN ID: 0x03B
	short	pack_current;
	int8_t		high_temp;
	int8_t		low_temp;
	int8_t		avg_temp;
	int8_t		internal_temp;
	
	// CAN ID: 0x3CB
	uint16_t	pack_inst_voltage;
	uint16_t	pack_open_voltage;
	uint8_t		pack_DOD;
	uint8_t		pack_health;
	uint16_t	max_pack_voltage;
	
	// CAN ID: 0x6B2
	uint16_t	min_pack_voltage;
	uint16_t	low_cell_voltage;
	uint16_t	high_cell_voltage;
	uint8_t		low_cell_voltage_id;
	uint8_t		high_cell_voltage_id;
	
	// CAN ID: 0x6B2
	uint16_t	pack_SOC;
	uint16_t	pack_amphours;
	uint8_t		high_opencell_id;
	uint8_t		low_opencell_id;
	uint8_t		high_thermistor_ID;
	uint8_t		low_thermistor_ID;
	
	// CAN ID: 0x195
	uint16_t	high_opencell_voltage;
	uint16_t	low_opencell_voltage;
	uint16_t	pack_resistance;
	uint16_t	pack_summed_voltage;
	
	// ------ BAMOCAR inputs ------
	
	uint16_t	motor_rpm;
	uint16_t	motor_current;
	uint16_t	motor_torque_rdval;
	uint16_t 	motor_voltage;
	uint16_t	motor_temp;
	uint16_t	bamocar_fault;
	uint16_t	bamocar_bus_voltage;
	uint16_t	bamocar_dout_1;
	

	// ------ Shifter algorithm inputs -----
	enum gear c_gear; // Current Gear Position
	

	// ------ SPI inputs --------
	enum shifter_io usher_shift; // Up Shift (John said to give it a chill name)
	enum shifter_io drake_shift; // Down Shift (Shout out 6 God)
	
	uint8_t red_button; // downshift button -- double check that this is the converntion everywhere
	uint8_t green_button; // upshift button
	uint8_t ice_mode;
	uint8_t motor_mode;
	uint8_t push_button_1;
	uint8_t push_button_2; // link to GO BUTTON!
	
	// probably don't need 'mode_switch' but keep for now so code compiles
	uint8_t mode_switch; // talk to Jake/John about switches
	
	
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


