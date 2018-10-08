#include <stdint.h>
#include <string.h>
#include "stm32f4xx_can.h"
#include 	"stm32f4xx_can.h"
#include "ring_buffer.h" // change
#include "DFR_SPI.h" // need for ready_to_drive_flag

extern volatile input_vector_t input_vector;


uint8_t get_gear(void){
	
	uint8_t gear;
	float current_gear_ratio;
	float gear_1_ratio = (13.0f/32.0f)*(24.0f/73.0f); // = .13356
	float gear_2_ratio = (16.0f/32.0f)*(24.0f/73.0f); // = .16438
	float gear_3_ratio = (17.0f/28.0f)*(24.0f*73.0f); // = .19961
	float gear_4_ratio = (19.0f/26.0f)*(24.0f/73.0f); // = .24025
	float gear_5_ratio = (21.0f/25.0f)*(24.0f/73.0f); // = .27616
	float bandwidth = .015f;

	current_gear_ratio = input_vector.motor_rpm/input_vector.engine_rpm;

	if ((current_gear_ratio <= gear_1_ratio + bandwidth) && (current_gear_ratio >= gear_1_ratio - bandwidth))			// create .02 band around each gear ratio
		{
			gear = 1;
		}
		else if ((current_gear_ratio <= gear_2_ratio + bandwidth) && (current_gear_ratio >= gear_2_ratio - bandwidth))
		{
			gear = 2;
		}
		else if ((current_gear_ratio <= gear_3_ratio + bandwidth) && (current_gear_ratio >= gear_3_ratio - bandwidth))
		{
			gear = 3;
		}
		else if ((current_gear_ratio <= gear_4_ratio + bandwidth) && (current_gear_ratio >= gear_4_ratio - bandwidth))
		{
			gear = 4;
		}
		else if ((current_gear_ratio <= gear_5_ratio + bandwidth) && (current_gear_ratio >= gear_5_ratio - bandwidth))
		{
			gear = 5;
		}
		else
		{
			gear = 0;
		}

	return gear;

}

