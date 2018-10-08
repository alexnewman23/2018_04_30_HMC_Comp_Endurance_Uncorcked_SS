// rename to input_output.h
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "stm32f4xx_can.h"
#include <stdbool.h>
#include "HMC_state_machine.h"

// shouldn't need these in main
//extern volatile int out_read_idx;
//extern volatile int out_write_idx;
//extern volatile int out_ring_count;
//extern volatile bool flag_can_busy;

// input ring variables

#define BUFFER_SIZE 100
extern CanRxMsg buffer[BUFFER_SIZE];
extern volatile int readIdx;
extern volatile int writeIdx;
extern volatile int ringCounter;

// output ring variables

#define BAMOCAR_CAN_ID 0x180
#define OUTPUT_RING_SIZE 100
extern volatile int out_read_idx;
extern volatile int out_write_idx;
extern volatile int out_ring_count;
extern volatile bool flag_can_busy;
extern volatile CanTxMsg bamocar_msg;
extern volatile CanTxMsg output_ring_buff[OUTPUT_RING_SIZE];
extern volatile CanTxMsg bamocar_var1_msg;
extern volatile CanTxMsg bamocar_var1_reset_msg;

/* typedef enum output_s {
	motor_torque_out,
	glvs_shutdown,
	ready_to_drive,
	shift_up,
	shift_down,
	
} output_t;


volatile typedef struct output_vector_s{
	uint16_t data;
	output_t select;
	uint32_t update;
	uint32_t CANID;
	
} output_vector_t; */


// input ring buff stuff
void addToRing (CanRxMsg x);
bool readFromRing (volatile CAN_msg_t *msgTable);
bool isEmpty (void);

// output stuff
// void send_output_msg(output_vector_t output_vector[]);
// void update_output_vector(uint16_t data, output_t select);
void add_to_output_ring (CanTxMsg x);
bool send_from_output_buff (volatile CanTxMsg output_ring_buff[]);

#define OUTPUT_VECTOR_SIZE 5



