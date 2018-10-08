#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "stm32f4xx_can.h"
#include "ring_buffer.h" // will need to change
#include <stdbool.h>

// typedefs
typedef enum safety_states_e{
	safety_init,
	safety_off,
	safety_one,		// before AIRs engaged
	safety_two,		// after AIRs engaged
	safety_three,
	safety_four,
	safety_five,
	safety_fault,
	
} safety_states_t;






extern volatile int ready_to_drive_flag;

// Function declarations
bool safety_output_check(void);
bool ready_to_drive_func (void);
bool pedal_safety_check(void);
