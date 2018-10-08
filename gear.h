#include <stdint.h>
#include <string.h>
#include "stm32f4xx_can.h"
#include "HMC_state_machine.h"
#include 	"stm32f4xx_can.h"
#include "ring_buffer.h" // change
#include "DFR_SPI.h" // need for ready_to_drive_flag

uint8_t get_gear(void);
