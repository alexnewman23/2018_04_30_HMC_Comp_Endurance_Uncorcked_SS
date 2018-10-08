// Shaun Sengupta
// DFR HMC Code
// December 7 2016

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

const uint32_t STD = 0;
const uint32_t EXT = 1;
const uint32_t msgTableSize = 20;

typedef struct CAN_msg_s {
	uint32_t messageID;
	uint32_t messageType;
	uint64_t data;

} CAN_msg_t;

typedef struct
{
  uint32_t StdId;  /*!< Specifies the standard identifier.
                        This parameter can be a value between 0 to 0x7FF. */

  uint32_t ExtId;  /*!< Specifies the extended identifier.
                        This parameter can be a value between 0 to 0x1FFFFFFF. */

  uint8_t IDE;     /*!< Specifies the type of identifier for the message that 
                        will be transmitted. This parameter can be a value 
                        of @ref CAN_identifier_type */

  uint8_t RTR;     /*!< Specifies the type of frame for the message that will 
                        be transmitted. This parameter can be a value of 
                        @ref CAN_remote_transmission_request */

  uint8_t DLC;     /*!< Specifies the length of the frame that will be 
                        transmitted. This parameter can be a value between 
                        0 to 8 */

  uint8_t Data[8]; /*!< Contains the data to be transmitted. It ranges from 0 
                        to 0xFF. */
} CanTxMsg;

/** 
  * @brief  CAN Rx message structure definition  
  */
typedef struct
{
  uint32_t StdId;  /*!< Specifies the standard identifier.
                        This parameter can be a value between 0 to 0x7FF. */

  uint32_t ExtId;  /*!< Specifies the extended identifier.
                        This parameter can be a value between 0 to 0x1FFFFFFF. */

  uint8_t IDE;     /*!< Specifies the type of identifier for the message that 
                        will be received. This parameter can be a value of 
                        @ref CAN_identifier_type */

  uint8_t RTR;     /*!< Specifies the type of frame for the received message.
                        This parameter can be a value of 
                        @ref CAN_remote_transmission_request */

  uint8_t DLC;     /*!< Specifies the length of the frame that will be received.
                        This parameter can be a value between 0 to 8 */

  uint8_t Data[8]; /*!< Contains the data to be received. It ranges from 0 to 
                        0xFF. */

  uint8_t FMI;     /*!< Specifies the index of the filter the message stored in 
                        the mailbox passes through. This parameter can be a 
                        value between 0 to 0xFF */
} CanRxMsg;

CAN_msg_t msgTable[msgTableSize] = 
{	
	// PE3 messages
	{0x0CFFF048, EXT, 0}, //PE3 1
	{0x0CFFF148, EXT, 0}, //PE3 2
	{0x0CFFF548, EXT, 0}, //PE3 6
	{0x0CFFFB48, EXT, 0}, //PE3 12

	// Orion messages
	{0x03B, STD, 0}, // BMS 1
	{0x3CB, STD, 0}, // BMS 2
	//{0x000, STD, 0} // BMS 3
	//{0x000, STD, 0} // BMS 4
	//{0x000, STD, 0} // BMS 5
	//{0x00, STD, 0} // BMS 6

	// BAMOCAR messages
	{0x180, STD, 0} // BAMOCAR 1

	// NOTE: Bamocar transmits on ONE CAN message ID
	// The REGID data field signifies what kind of
	// info it holds. This will be delt in parsing...

};

const int ringBufferSize = 50;
int i = 0;

CanRxMsg RxMessage; // HOW DO WE GET THE CAN MESSAGE TO FILL RxMessage????*****
CanRxMsg ringBuffer[50];
uint32_t readCount = 0;
uint32_t writeCount = 0;



int main() {
	
	bool done = false;

// parse new message
	while(done == false) {

		if( (RxMessage.StdId == msgTable[i].messageID && RxMessage.IDE == msgTable[i].messageType) || 
			(RxMessage.ExtId == msgTable[i].messageID && RxMessage.IDE == msgTable[i].messageType)
		) {
			
			msgTable[i].data = *((uint64_t *)(&(RxMessage.Data)));
			done = true;
		} else {
			i++; // increment
			if (i > msgTableSize){ // remember that indexing from 0
				i = 0;
			} else {
				//
			}
		}
	}



	//printf("%x\n", msgTable[0].messageID);
	//int input;
	//char str[20];

	//scanf("%d", &input);
	//printf("%d\n", input * 2);

	//fgets(str,20,stdin);
	//printf("%s", str);

};