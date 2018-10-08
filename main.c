#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <iso646.h>

#include "Board_LED.h"                  // ::Board Support:LED
#include "Board_Buttons.h"              // ::Board Support:Buttons

#include "stm32f4xx.h"                  // Device header

#include 	"misc.h"
#include 	"stm32f4xx_tim.h"
//#include	"stm32f4xx_dma.h"
//#include	"stm32f4xx_usart.h"
//#include 	"stm32f4xx_adc.h"
#include 	"stm32f4xx_can.h"
#include 	"stm32f4xx_gpio.h"
//#include 	"stm32f4xx_flash.h"
//#include 	"stm32f4xx_rcc.h"
//#include 	"stm32f4xx_tim.h"
#include "HMC_state_machine.h"

#include <RTE_components.h>
#include "ring_buffer.h" // will need to change
#include	"DFR_SPI.h"
#include "gear.h"
#include "safety.h"
#include "msg_safety_jj.h"

// a small helper... 
#define	until(arg)	while(!(arg))

// Setting Up Message Table
const uint32_t STD = CAN_Id_Standard;
const uint32_t EXT = CAN_Id_Extended;
uint32_t msgTableSize;

//#pragma pack  
volatile	uint32_t		JLM_Debug;

const int column = 12;
// create message table

volatile CAN_msg_t msgTable[] =
{	
	// ATHENA ECU MSGS messages
	{0x200, STD, 0, 0, 1, 20, column, "ATHENA1",0,0,0}, //ATHENA 1 (0)
	{0x310, STD, 0, 0, 1, 20, column, "ATHENA2",0,0,0}, //ATHENA 1 (1)
	{0x312, STD, 0, 0, 1, 20, column, "ATHENA3",0,0,0}, //ATHENA 1 (2)
 
	// EMUS BMS messages
	{0x1B6, STD, 0, 0, 1, 7, column, "EMUS1",0,0,0}, // EMUS BMS (3)
	{0x1B7, STD, 0, 0, 1, 8, column, "EMUS2",0,0,0}, // EMSU BMS (4)
	{0x1BA, STD, 0, 0, 1, 8, column, "EMUS2",0,0,0}, // EMSU BMS (5)

	// BAMOCAR messages
	{0x180, STD, 0x30, 0, 1,12, column, "BAMO1",0,0,0}, // BAMOCAR 1 - Motor RPM (6)
	{0x180, STD, 0x5F, 0, 1,13, column, "BAMO2",0,0,0}, // BAMOCAR 2 - Motor Current // change to reg 27..? (7)
	{0x180, STD, 0xA0, 0, 1,14, column, "BAMO3",0,0,0}, // BAMOCAR 3 - Motor Torque (8)
	{0x180, STD, 0x8A, 0, 1,15, column, "BAMO4",0,0,0}, // BAMOCAR 4 - Motor Voltage (9)
	{0x180, STD, 0xE1, 0, 1,16, column, "BAMO5",0,0,0}, // BAMOCAR 5 - BAMOCAR D_OUT2 (10)
	{0x180, STD, 0x8F, 0, 1,17, column, "BAMO6",0,0,0}, // BAMOCAR 6 - BAMOCAR_Fault (11)
	{0x180, STD, 0xEB, 0, 1,18, column, "BAMO7",0,0,0}, // BAMOCAR 7 - BAMOCAR Bus Voltage (12)
	{0x180, STD, 0xE0, 0, 1,19, column, "BAMO8",0,0,0}, // BAMOCAR 8 - BAMOCAR D_OUT 1 (13)


	
	// ****** IF YOU CHANGE ANYTHING CHANGE MESSAGE TABLE SIZE IN THE WHILE LOOP FOR PARSING********
	// NOTE: Bamocar transmits on ONE CAN message ID
	// The REGID data field signifies what kind of BAMOCAR 
	// info it holds. This will be delt in parsing...
	// if you add /change to bamocar make sure to change bamocar init request messages

};


// CanRxMsg RxMessage;
CanRxMsg ringBuffer[50];
uint32_t readCount = 0;
uint32_t writeCount = 0;


void DFR_TIM3_Init(void);
void DFR_CAN_Init(uint32_t u32SensorID);

extern int stdout_init (void);
extern volatile CanTxMsg motec_msg;

volatile uint32_t msTicks;                            /* counts 1ms timeTicks */
/*----------------------------------------------------------------------------
 * SysTick_Handler:
 *----------------------------------------------------------------------------*/
void SysTick_Handler(void) 
{
  msTicks++;
}

/*----------------------------------------------------------------------------
 * Delay: delays a number of Systicks
 *----------------------------------------------------------------------------*/
void Delay (uint32_t dlyTicks) 
{
  uint32_t curTicks;

  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks) { __NOP(); }
}

/*----------------------------------------------------------------------------
 * SystemCoreClockConfigure: configure SystemCoreClock using HSI
                             (HSE is not populated on Nucleo board)
 *----------------------------------------------------------------------------*/
void SystemCoreClockConfigure(void) 
{

  RCC->CR |= ((uint32_t)RCC_CR_HSION);                     /* Enable HSI */
  while ((RCC->CR & RCC_CR_HSIRDY) == 0);                  /* Wait for HSI Ready */

  RCC->CFGR = RCC_CFGR_SW_HSI;                             /* HSI is system clock */
  while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);  /* Wait for HSI used as system clock */

  FLASH->ACR  = (FLASH_ACR_PRFTEN     |                    /* Enable Prefetch Buffer */
                 FLASH_ACR_ICEN       |                    /* Instruction cache enable */
                 FLASH_ACR_DCEN       |                    /* Data cache enable */
                 FLASH_ACR_LATENCY_5WS );                  /* Flash 5 wait state */

  RCC->CFGR |= (RCC_CFGR_HPRE_DIV1  |                      /* HCLK = SYSCLK */
                RCC_CFGR_PPRE1_DIV2 |                      /* APB1 = HCLK/2 */
                RCC_CFGR_PPRE2_DIV1  );                    /* APB2 = HCLK/1 */

  RCC->CR &= ~RCC_CR_PLLON;                                /* Disable PLL */

	
  /* PLL configuration:  VCO = HSI/M * N,  Sysclk = VCO/P */		//	Configure for SYSCLK of 180 MHz
  RCC->PLLCFGR = ( 16ul                   |                /* PLL_M =   8 */
                 (200ul <<  6)            |                /* PLL_N = 180 */
                 (  0ul << 16)            |                /* PLL_P =   2 */
                 (RCC_PLLCFGR_PLLSRC_HSI) |                /* PLL_SRC = HSI */
                 (  7ul << 24)            |                /* PLL_Q =   7 */
                 (  2ul << 28)             );              /* PLL_R =   2 */


  RCC->CR |= RCC_CR_PLLON;                                 /* Enable PLL */
  while((RCC->CR & RCC_CR_PLLRDY) == 0) __NOP();           /* Wait till PLL is ready */

  RCC->CFGR &= ~RCC_CFGR_SW;                               /* Select PLL as system clock source */
  RCC->CFGR |=  RCC_CFGR_SW_PLL;
  while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);  /* Wait till PLL is system clock src */
}



CanTxMsg	My_TX_message	=	
{
	0,								//  uint32_t StdId;  /*!< Specifies the standard identifier.
										//                        This parameter can be a value between 0 to 0x7FF. */
										//
	0x7E57,					//  uint32_t ExtId;  /*!< Specifies the extended identifier.
										//                        This parameter can be a value between 0 to 0x1FFFFFFF. */
										//
	CAN_Id_Extended,	//  uint8_t IDE;     /*!< Specifies the type of identifier for the message that 
										//                        will be transmitted. This parameter can be a value 
										//                        of @ref CAN_identifier_type */
										//
	CAN_RTR_Data,			//  uint8_t RTR;     /*!< Specifies the type of frame for the message that will 
										//                        be transmitted. This parameter can be a value of 
										//                        @ref CAN_remote_transmission_request */
										//
	8,								//  uint8_t DLC;     /*!< Specifies the length of the frame that will be 
										//                        transmitted. This parameter can be a value between 
										//                        0 to 8 */
										//
										//  uint8_t Data[8]; /*!< Contains the data to be transmitted. It ranges from 0 
										//                        to 0xFF. */
	{0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08}

	// 0CFFF048
};

CanRxMsg	My_RX_message;
volatile	bool	Print_Flag	=	false;
volatile	int	My_Time = 0;
input_vector_t input_vector;
volatile SPI_output_vector_t SPI_output_vector;

bool clutch_threashold_passed = NOT_PRESSED; // create implementation
bool safety_init_done_flag = false;
extern volatile safety_states_t safety_state;

volatile CAN_msg_t temp_msg;

extern volatile car_mode_t car_mode;

void updateTerminal(void);

/*----------------------------------------------------------------------------
 * main: blink LED and check button state
 *----------------------------------------------------------------------------*/
int main (void) 
{
  int32_t max_num = LED_GetCount();

	//SystemCoreClockConfigure();                              /* configure HSI as System Clock */
  SystemCoreClockUpdate();
  LED_Initialize();
  Buttons_Initialize();
  stdout_init();                                           /* Initialize Serial interface */
  SysTick_Config(SystemCoreClock / 1000);                  /* SysTick 1 msec interrupts */
	DFR_CAN_Init(0xFFFF12);
	DFR_SPI_Init();
	DFR_TIM3_Init();				//	Initialize TIM3 for a 1 mSec Interrupt  (TIM3 ISR)

	// test_shifter_algorithm();
	
	safety_init_done_flag = true; // also used for lock algorithm to sense when done initializing
	 
	int i = 0; 
	
  for (;;) 
	{
		assign_inputs(); // update all values in input vector
		
		if(Print_Flag)		//	TIM3_IRQHandler() ISR sets Print_Flag, we clear it here...
		{
			Print_Flag	=	false;
			My_Time	+=	5;						//	add another 5 seconds to My_Time
			//CAN_Transmit(CAN1, &My_TX_message);		//	Let's send a message...
			//JLM_Debug	=	CAN_TransmitStatus(CAN1, 0);
		}
		else
		{
			//	...
		}
		// CAN_Transmit(CAN1, &My_TX_message); // test
		//	If there's a CAN message, let's collect it...
			
		while(ringCounter>0)
		{
			DISABLE_INTERRUPTS;
			{
				readFromRing(&temp_msg);
			}
			ENABLE_INTERRUPTS;
				
			// so now parse temp...
				
			// parse the pending message in the buffer
			bool done = false;
			i = 0;
					
			msgTableSize = (sizeof(msgTable)/sizeof(CAN_msg_t));
			//while( (i < msgTableSize) ) { /*(done == false) &&  */  /*&& (isEmpty() == false)*/
			do
			{
				if ((temp_msg.messageID == 0x180) and (temp_msg.messageID == msgTable[i].messageID))
				//if ((temp_msg.messageID == 0x0CFFF248) and (temp_msg.messageID == msgTable[i].messageID))
				{
					JLM_Debug = temp_msg.messageID;
					JLM_Debug++;
				}
						
			 if( 
					((temp_msg.messageID == msgTable[i].messageID) && (temp_msg.data._8[0] == msgTable[i].REGID ) && (temp_msg.messageID == 0x180) )    || // Bamocar							
					((temp_msg.messageID == msgTable[i].messageID) && (temp_msg.messageType == msgTable[i].messageType) && temp_msg.messageID != 0x180) //||  // Regular
			 ) 
			 {
					//readFromRing(&msgTable[i]); // Fill in DOUBLE CHECK*****
					msgTable[i].data._64 = temp_msg.data._64;
					msgTable[i].update = 1;
					msgTable[i].msg_count++;
					done = true;
				} 
				else 
				{
					i++; // increment
				}
			}
			
			until(done or (i>=msgTableSize));
			JLM_Debug = i;
			JLM_Debug++;
		}	
		// updateTerminal();
  }
}


void DFR_TIM3_Init(void) 
{
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
  // Time Base Configuration
  TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);

  // TIM3 generates a 1 Msec tick for a 1 mSec ISR.


  // 180MHz clock / 2 = 90MHz.  90MHz / 9 (prescaler) = 10MHz.  10MHz / 10000 = 1KHz (1mS).
  TIM_TimeBaseStructure.TIM_Period 		= (10000-1);
  TIM_TimeBaseStructure.TIM_Prescaler = (90-1); 	// (9-1); (was this before5/2/17)
	
	
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode =  TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

  TIM_ARRPreloadConfig(TIM3, ENABLE);

	// Timer 3 Interrupt Handling
	
		NVIC_InitTypeDef NVIC_InitStructure;
		
		NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

		NVIC_Init(&NVIC_InitStructure);
	
	/* Enable Timer 3 Update Event Interrupt */
  TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	
	TIM_Cmd(TIM3, ENABLE);
}


void	_50_mSec_Tasks(void);

uint16_t	Print_Counter	=	10;
uint16_t _50_msec_counter = 50-1;
uint16_t temp;


void updateTerminal(void)
{
	int i;
	int c = 1;
	
	//temp = motec_msg.Data[1]/8 + motec_msg.Data[0];
	temp = input_vector.motor_rpm*6000/32767;
	for(i = 0; i < msgTableSize; i++)
	{
	/*
		if(msgTable[i].update == 1)
		{
			printf("\033[%d;%dH %s",msgTable[i].row,c,msgTable[i].name);
			printf("\033[%d;%dH %llu", msgTable[i].row, msgTable[i].col, msgTable[i].data._64 );
			//printf("%llu",msgTable[i].data);
			msgTable[i].update = 0;
		}
	}
	
		printf("\033[%d;%dH %s",15,c,"Engine RPM");
		printf("\033[%d;%dH %d", 15, 15, input_vector.engine_rpm);
	
		printf("\033[%d;%dH %s",16,c,"Engine MAP");
		printf("\033[%d;%dH %d", 16, 15, input_vector.engine_MAP);
	
		printf("\033[%d;%dH %s",17,c,"Engine Temp");
		printf("\033[%d;%dH %d", 17, 15, input_vector.engine_temp);
		*/
		printf("\033[%d;%dH %s",18,c,"Motor RPM count");
		printf("\033[%d;%dH %05d", 18, 15, input_vector.motor_rpm);
	
		printf("\033[%d;%dH %s",19,c,"Motor RPM "); // change back to Motor Torque
		printf("\033[%d;%dH %05d", 19, 15,temp); //msgTable[9].data.Bamo_data_16.REGID
		/*
		printf("\033[%d;%dH %s",19,c,"Motor Torque"); // change back to Motor Torque
		printf("\033[%d;%dH %d", 19, 15,input_vector.motor_torque_rdval); //msgTable[9].data.Bamo_data_16.REGID
	
		printf("\033[%d;%dH %s",20,c,"Accel. Pos.");
		printf("\033[%d;%dH %03d", 20, 15,input_vector.accel_rdval);
	
		printf("\033[%d;%dH %s",21,c,"Brake Pos.");
		printf("\033[%d;%dH %d", 21, 15,input_vector.brake_rdval);
	
		printf("\033[%d;%dH %s",22,c,"Clutch Pos.");
		printf("\033[%d;%dH %d", 22, 15,input_vector.clutch_rdval);
	
		printf("\033[%d;%dH %s",24,c,"Mode =");
		printf("\033[%d;%dH %d", 24, 10, car_mode);
*/ 
		// print statement for mode
		//	if (input_vector.mode_switch == 1){
		//		printf("\033[%d;%dH %s",23,c,"Hybrid Mode");
		//	}
		//	else{
		//		printf("\033[%d;%dH %s",23,c,"Electric Only Mode");
		//	}
		
	}
}

int _50_ms_task_delay = 0;

void TIM3_IRQHandler(void) 
{
	// Clear the interrupt pending flag
  TIM_ClearITPendingBit(TIM3, TIM_IT_Update);

	
	_50_ms_task_delay++;
	
	if(1){//(_50_ms_task_delay >= 6000){

		
		GPIO_ResetBits(GPIOC, GPIO_Pin_7);		//	SPI_CS1	PC7	CLT01-38SQ7
		SPI_I2S_SendData(SPI1, CLT_Write);
		SPI_io_state = wait_for_SPI_A;
		
		 
		if(_50_msec_counter)
		{
			_50_msec_counter--;
		}
		else
		{
			_50_msec_counter	=	5-1; // 5*10 ms          //= 50-1; was this before 5/2/2017
			Print_Flag	=	true;
			_50_mSec_Tasks();
		}
		
		// _50_ms_task_delay = 6001; // set high so you can run 50ms_task after 5second delay
	}
}


//void msg_safety_chk (void);
bool init_status = 0; // bamocar init not completed
volatile int CAN_error_flag = OFF; 

volatile	uint16_t	State	=	0;

float engine_torque;
float motor_torque;
float kP;
enum HMC_states hmc_state = prop_torque;


uint16_t motec_temp;
uint16_t motec_temp_chk;

volatile uint16_t torque_cmd_main = 0;

volatile CanTxMsg bamocar_torque_msg_main = 
{
	0x210,								//  uint32_t StdId;  /*!< Specifies the standard identifier.
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

int safety_check_temp = 1;

int msg_safety_timer_cnt = 0;

// calibrate these bad boys
uint16_t brake_threshold = 100;
int16_t clutch_threshold = 720;

void	_50_mSec_Tasks(void)
{
	if(init_status == 0)
	{
		init_status = bamocar_init();
		car_mode = car_hybrid;
	} 
	else 
	{
		init_status = 1;
	}
	
	msg_safety_timer_cnt++;
	
	// lock_unlock_state(); auto set to hybrid now
//	car_mode = car_hybrid; // put in init status
	
	// calculate the gear
	input_vector.gear = get_gear();
	
	
//	if(msg_safety_timer_cnt == 3 && safety_init_done_flag){ 
//		safety_check_temp = msg_safety_check(msgTable,msgTableSize);
////		if(safety_check_temp == 0) {
////			CAN_error_flag = ON;
////		}
//		msg_safety_timer_cnt = 0;
//	}
	


	
{
	
	switch(hmc_state){ // fix later...
		case brake_or_clutch:
		{
			if ((input_vector.clutch_rdval >= brake_threshold) or (input_vector.clutch_rdval >= clutch_threshold)){
				hmc_state = brake_or_clutch;
			} else {
				hmc_state = prop_torque;
			}
		}
			break;

		case prop_torque:
		{
			if (input_vector.clutch_rdval >= clutch_threshold){
				hmc_state = brake_or_clutch;
			} else {
				hmc_state = prop_torque;
			}
		}
			break;
		
	}
}
	
	// nested state  machine
	// first check what mode the car is in (hybrid, electric, or gas)
	// when in hybrid execture another state machine
	
if(safety_state == safety_five) 
{ 
	switch (car_mode)
	{
		case car_hybrid:
		{
			switch(hmc_state)
			{
				case brake_or_clutch:
				{
					electric_torque(false);
				}
				break;
				
				case prop_torque:
				{
					electric_torque(true);
				}
				break;
			}
		}
		break;
		
		case car_init:
		{
			electric_torque(false);
		}
		break;
	}	
}
else
{
	//...
}
	

	safety_output_check(); // NOT DONE YET, NEED MAX AND MIN INFO FROM JAKE
	pedal_safety_check();


	// Motor RPM
	motec_msg.Data[0] = (uint8_t)(input_vector.motor_rpm >> 8); 
	motec_msg.Data[1] = (uint8_t)(input_vector.motor_rpm & 0x00FF);
	motec_temp_chk = (motec_msg.Data[0]<<8) + motec_msg.Data[1];
	// Motor Current
	motec_msg.Data[2] = (uint8_t)(input_vector.engine_rpm >> 8); 
	motec_msg.Data[3] = (uint8_t)(input_vector.engine_rpm & 0x00FF);

	// Battery Pack Voltage
	memcpy((void*)&motec_msg.Data[4], (void*)&input_vector.pack_voltage_raw, sizeof(uint32_t));

	add_to_output_ring(motec_msg);

 
//	motec_msg.Data[4] = (uint8_t)(input_vector.motor_phase_voltage >> 8); 
//	motec_msg.Data[5] = (uint8_t)(input_vector.motor_phase_voltage & 0x00FF);
	


	
}


void ConfigureGPIO(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin, GPIOMode_TypeDef GPIO_Mode, GPIOSpeed_TypeDef GPIO_Speed, GPIOOType_TypeDef GPIO_OType, GPIOPuPd_TypeDef GPIO_PuPd)
{
GPIO_InitTypeDef GPIO_InitStructure;

GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed;
GPIO_InitStructure.GPIO_OType = GPIO_OType;
GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd;

GPIO_Init(GPIOx, &GPIO_InitStructure);
}

void DFR_CAN_Init(uint32_t u32SensorID)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	
	ConfigureGPIO(GPIOB, GPIO_Pin_8, GPIO_Mode_AF, GPIO_Speed_2MHz, GPIO_OType_OD, GPIO_PuPd_UP); //  PB8   Pin 61  CAN_RX/SER_RXD  Input
	ConfigureGPIO(GPIOB, GPIO_Pin_9, GPIO_Mode_AF, GPIO_Speed_2MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL); //  PB9   Pin 62  CAN_TX/SER_TXD  Output
	
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_CAN1);		//  PB8   Pin 61  CAN_RX  Input	
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_CAN1);		//  PB9   Pin 62  CAN_TX  Output

	/* CAN register init */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 | RCC_APB1Periph_CAN1, ENABLE);
	#if		defined(USE_CAN2)
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 | RCC_APB1Periph_CAN2, ENABLE);
	#endif
	CAN_DeInit(CAN1);		//	Always De-Init CAN1 even if we're not using it.
	#if		defined(USE_CAN2)
	CAN_DeInit(CAN2);
	#endif

	//	CAN Receive Message Filter Initialization
	
	CAN_FilterInitTypeDef CAN_FilterInitStructure;

// JLM_Debug	=	u32SensorID;

	// Prepare the extended ID for the filters list
	u32SensorID = ((u32SensorID<<3) | CAN_Id_Extended);	//CAN_ID_EXT;
// JLM_Debug	=	u32SensorID;

	CAN_FilterInitStructure.CAN_FilterNumber	=	0;		//	Filter  0 is the default for CAN1
	CAN_FilterInitStructure.CAN_FilterMode		=	CAN_FilterMode_IdMask;	//CAN_FilterMode_IdList;
	CAN_FilterInitStructure.CAN_FilterScale		=	CAN_FilterScale_32bit;

	CAN_FilterInitStructure.CAN_FilterIdHigh	=	0;	//((u32SensorID & 0xffff0000)>>16);
	CAN_FilterInitStructure.CAN_FilterIdLow		= 0;	// (u32SensorID & 0x0000ffff);
	CAN_FilterInitStructure.CAN_FilterMaskIdHigh	=	0;	//CAN_FilterInitStructure.CAN_FilterIdHigh;
	CAN_FilterInitStructure.CAN_FilterMaskIdLow		=	0;	//CAN_FilterInitStructure.CAN_FilterIdLow;

	CAN_FilterInitStructure.CAN_FilterFIFOAssignment	=	0;
	CAN_FilterInitStructure.CAN_FilterActivation			=	ENABLE;

	CAN_FilterInit(&CAN_FilterInitStructure);
	//	CAN Unit Initialization
	{
		CAN_InitTypeDef    		CAN_InitStructure;

		CAN_StructInit(&CAN_InitStructure);

		/* CAN cell init */
		CAN_InitStructure.CAN_TTCM			=	DISABLE;	//"...0: 	Time Triggered Communication mode disabled..."
		CAN_InitStructure.CAN_ABOM			=	ENABLE;		//"...1: 	The Bus-Off state is left automatically by hardware once 
																								//				128 occurrences of 11 recessive bits have been monitored.
		CAN_InitStructure.CAN_AWUM			=	DISABLE;	//"...0: 	The Sleep mode is left on software request by clearing the 
																								//				SLEEP bit of the CAN_MCR register...."
		CAN_InitStructure.CAN_NART			=	DISABLE;	//"...0: 	The CAN hardware will automatically retransmit the message until 
																								//				it has been successfully transmitted according to the CAN standard...."
		CAN_InitStructure.CAN_RFLM			=	DISABLE;	//"...0: 	Receive FIFO not locked on overrun. Once a receive FIFO is full the next 
																								//				incoming message will overwrite the previous one...."	
		CAN_InitStructure.CAN_TXFP			=	DISABLE;	//"...0: 	Priority driven by the identifier of the message..."

// #define		CAN_LOOP_BACK_MODE	(1)

	#if		defined(CAN_LOOP_BACK_MODE)		
		CAN_InitStructure.CAN_Mode			=	CAN_Mode_LoopBack;
	#else
		CAN_InitStructure.CAN_Mode			=	CAN_Mode_Normal;
	#endif
	
		//============
		//	500 Kbaud
		//============
		//	KBaud Rate = ((45 MHz/CAN_Prescaler)*(10^3))/(CAN_SJW+CAN_BS1+CAN_BS2)

		//	KBaud Rate = ((45 MHz/9)*(10^3))/(1+7+2) = ((5.0 MHz)*(10^3))/10 = (0.50 MHz)*(10^3) = 500 Kbaud

		CAN_InitStructure.CAN_SJW				=	CAN_SJW_1tq;
		CAN_InitStructure.CAN_BS1				=	CAN_BS1_7tq;		//	consider CAN_BS1_12tq
		CAN_InitStructure.CAN_BS2				=	CAN_BS2_2tq;		//	consider CAN_BS2_3tq, for 81.25% Sampling point  [(CAN_BS1_12tq+CAN_SJW_1tq)/(CAN_BS1_12tq+CAN_BS2_1tq+CAN_SJW_3tq)]
		CAN_InitStructure.CAN_Prescaler	=	9;     // 500 Kbaud
	
	#if		defined(USE_CAN2)
		CAN_Init(CAN2,	&CAN_InitStructure);
	#else
		CAN_Init(CAN1,	&CAN_InitStructure);

//void CAN_ITConfig(CAN_TypeDef* CANx, uint32_t CAN_IT, FunctionalState NewState)
		
		  {
   NVIC_InitTypeDef NVIC_InitStructure;
   // CAN TX Interrupt Handling
   NVIC_InitStructure.NVIC_IRQChannel = CAN1_TX_IRQn; //USB_HP_CAN_TX_IRQChannel;
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 5;
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
   // CAN RX Interrupt Handling
   NVIC_InitStructure.NVIC_IRQChannel = CAN1_RX0_IRQn; //USB_LP_CAN_RX0_IRQChannel;
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 6;
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);
  }
			
//		CAN_ITConfig(CAN1, CAN_IT_TME, ENABLE);
		CAN_ITConfig(CAN1, (CAN_IT_FMP0 | CAN_IT_FF0 | CAN_IT_TME), ENABLE);

	#endif
	}
}




void CAN1_TX_IRQHandler(void)
{
	if(send_from_output_buff (output_ring_buff))
	{
		// output buff not empty
		// we sent a message
		flag_can_busy = true;
	}
	else 
	{
		// buffer is empty
		// nothing to send
		flag_can_busy = false;
	}
	CAN_ClearITPendingBit(CAN1, CAN_IT_TME);
}

void CAN1_RX0_IRQHandler(void)
{
	
			if(CAN_MessagePending(CAN1, CAN_FIFO0)	)
			{ 	
//				bool done = false;
				
				CAN_Receive(CAN1, CAN_FIFO0, &My_RX_message);

//				My_TX_message.Data[0]++; // if we get a ring, we visually acknowledge it by incrementing

				addToRing(My_RX_message);

				CAN_FIFORelease(CAN1, CAN_FIFO0);
				
			}
			else
			{
				//	...
			}
	
	 CAN_ClearITPendingBit(CAN1, CAN_IT_FF0);


}
