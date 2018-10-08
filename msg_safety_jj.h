/* 
 * msg_safety_jj.h - header file for DFR 'msg_safety_jj' module
 * 
 * Jennifer Jain, April 2018
 */

#ifndef __MSG_SAFETY_JJ_H
#define __MSG_SAFETY_JJ_H

#include "HMC_state_machine.h"

/**************** global types ****************/

/**************** global functions ****************/

int msg_safety_check(volatile CAN_msg_t *msgTable, uint32_t msgTableSize);


#endif //__MSG_SAFETY_JJ_H
