/* 
 * msg_safety_jj.c - DFR code to detect whether data is not recieved from a particular device
 *
 * see msg_safety_jj.h for more information.
 * 
 * Jennifer Jain, April 2018
 * 
 */

/* Package declerations */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <iso646.h>
#include <inttypes.h>

#include "msg_safety_jj.h"



/**************** global types ****************/

/**************** local functions ****************/
/* not visible outside this file */


/**************** global functions ****************/
/* that is, visible outside this file */


/**************** msg_safety_check() ****************/

//returns 0 if message error occurs, reutrns 1 if messages are good

int msg_idx = 0;
int loop_count = 0;
int error_not_present = 1;

int msg_safety_check(volatile CAN_msg_t *msgTable,  uint32_t msgTableSize) 
	{
    int error_lim = 38;
	msg_idx = 0;
	for(msg_idx = 0; msg_idx<(msgTableSize-1); msg_idx++)
	{
		// logic of the safety control

		// no messages recieved since last check
		if(msgTable[msg_idx].msg_count == msgTable[msg_idx].old_count) {
 			msgTable[msg_idx].err_count++;
 		} 

 		// handle tiemout from error_cnt
 		if(msgTable[msg_idx].err_count >= error_lim) {
 			//printf("msg id: %d has not been recieving messages. Error code %d, terminating program.", msg_table[i].id, code)
 			
 			// print error message
			printf("\033[%d;%dH Crit. Msg Error for %s, shut down",15,25, msgTable[msg_idx].name);
			//CAN_error_flag = ON;

			// exit function (break or return exit code)
			error_not_present = 0;
			break;
			
 		}

 		// new messages have been recieved
 		else if(msgTable[msg_idx].msg_count != msgTable[msg_idx].old_count) {
 			// reset error count 
 			msgTable[msg_idx].err_count = 0;

 			// update old count
 			msgTable[msg_idx].old_count = msgTable[msg_idx].msg_count;
 		}
		
	 // 	// for debugging purposes
		// printf(" msg id: %d \n", msgTable[i].id);
		// printf(" old_cnt: %d \n", msgTable[i].old_count);
		// printf(" curr_cnt: %d \n", msgTable[i].msg_count);
		// printf(" error_cnt: %d\n\n", msgTable[i].error_count);
	}
	loop_count++;
	return error_not_present;
}
