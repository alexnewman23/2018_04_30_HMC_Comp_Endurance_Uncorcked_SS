//		SPI I/O Mapping	
//	
//	SPI Inputs		(CLT)
//	
//	IN1		Red Button (Shift Down)
//	IN2		Green Button (Shift Up)
//	IN3 	ICE MODE (On/Off)
//	IN4		Motor MODE (On/Off)
//	*IN5* *Lock State* 
//	IN6		Spare
// 	IN7		Spare
// 	IN8		Spare
//
//	SPI Outputs		(VNI)
//	
//	OUT1	Solenoid 1 (Shift Down)
//	OUT2 	Solenoid 2 (Shift Up)
//	OUT3 	Safety		 (High = Ready, Low = Airs Open)
//	OUT4 	Ready to Drive (have to turn off after 5 seconds)
//	OUT5	RFG/RFE (Motor Enable)
//	OUT6		Spare
// 	OUT7		Spare
// 	OUT8		Spare
//	

//	Setup SPI for use with PLC01A1 board
//
//	It uses a CLT01-38SQ7 and a VNI8200XP
//												Morpho
//	Signal		CN5	Arduino	CN10		GPIO	MCU														Device
//	======		===	=======	======	====	============================	===========
//	SPI_SCK		6		D13			11			PA5		SPI1_SCK	Alternate Function
//	SPI_MISO	5		D12			13			PA6		SPI1_MISO	Alternate Function
//	SPI_MOSI	4		D11			15			PA7		SPI1_MOSI	Alternate Function
//	SPI_CS2		3		D10			17			PB6		GPIO													VNI8200XP
//	SPI_CS1		2		D9			19			PC7		GPIO													CLT01-38SQ7 
//
//	Signal		CN9	Arduino	CN10		GPIO	MCU														Device
//	======		===	=======	======	====	============================	===========
//	OUT_EN		7		D6			25			PB10	GPIO													VNI8200XP
//
//	So we need to ENABLE_SPI1, and configure PB6 & PC7 for Chip Selects
//


//#include	<stddef.h>

//#include	"stm32f4xx.h"
//#include	"stm32f4xx_gpio.h"
//#include	"stm32f4xx_spi.h"



#include	"DFR_SPI.h"
#include "HMC_state_machine.h"
#include	"SQ_IOM.h"

#if		defined(ENABLE_SPI2_SLAVE)
#include	"SQ_SPI_SLAVE.h"
#endif

#include	"stm32f4xx_gpio.h"

#define FORCE_PG (1) // TEMPORARY!



//===============================================
//	DEBUG STUFF
//===============================================

extern	volatile	uint32_t		JLM_Debug;
volatile SPI_io_states_t SPI_io_state = wait_for_TIM3;


//	!!! This needs to be made part of Context
const	u16	SPI_TX_Scratch_Buffer[(SPI_MAX_BUFFER_SIZE/(sizeof(u16)))]	=
{
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,	0xFFFF, 0xFFFF, 
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,	0xFFFF, 0xFFFF, 
																																	
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,	0xFFFF, 0xFFFF, 
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,	0xFFFF, 0xFFFF, 
																																	
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,	0xFFFF, 0xFFFF, 
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,	0xFFFF, 0xFFFF, 
																																	
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,	0xFFFF, 0xFFFF, 
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,	0xFFFF, 0xFFFF, 

#if		not	defined(SHRINK)
//#else

	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,	0xFFFF, 0xFFFF, 
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,	0xFFFF, 0xFFFF, 
																																	
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,	0xFFFF, 0xFFFF, 
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,	0xFFFF, 0xFFFF, 
																																	
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,	0xFFFF, 0xFFFF, 
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,	0xFFFF, 0xFFFF, 
																																	
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,	0xFFFF, 0xFFFF, 
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,	0xFFFF, 0xFFFF, 

#endif
};

volatile	uint16_t	SPI_RX_Scratch_Buffer[(SPI_MAX_BUFFER_SIZE/(sizeof(u16)))];

#if		defined(ENABLE_SPI2_SLAVE)
volatile	uint16_t	SPI_SLAVE_TX_Scratch_Buffer[SIZE_OF_SLAVE_BUFFER];	//40, //[(SPI_MAX_BUFFER_SIZE/(sizeof(u16)))];
#endif

typedef	volatile	enum	SPI_State_e
{
	SPI_FAULTED				=	-1,
	SPI_INIT					=	0,
	SPI_IDLE					=	1,
	SPI_LOAD_DMA			=	2,
	SPI_WAIT_HEADER		=	3,
	SPI_WAIT_DMA			=	4,
	SPI_COMPLETE_DMA	=	5,
	SPI_CALLBACK			=	6,

	SPI_EEPROM_PP_DELAY	=	7,
	SPI_EEPROM_SE_DELAY	=	8,
	SPI_EEPROM_BE_DELAY	=	9,

//	SPI_STARTING	=	10
}
SPI_State_t;


#if		defined(ENABLE_SPI1)

//	SPI1's UCB
SPI_UCB_t	SPI_UCB_1	=
{
	//	UCB_t						UCB;
	{
		NULL,																							//	IOPacket_t		*Head;
		NULL,																							//	IOPacket_t		*Tail;
		SPI1,																							//	void					*HW;
		SPI_INIT,																					//	u32						State;
		(IOP_status_t	(*)(struct	UCB_s	*))(&SPI_Start),	//	IOP_status_t	(*Start)(struct	UCB_s	*UCB);
		&SPI_Qualify,																			//	IOP_status_t	(*Qualify)(IOPacket_t *packet);
		NULL,																							//	void					*Private;
	},
	//	SPI_Context_t	Context;
	{
			//	DMA2:Channel3:Stream2 for SPI1_RX, Stream3 for SPI1_TX
			//	DMA2:Channel3:Stream2 for SPI1_RX
			//	DMA2:Channel3:Stream3 for SPI1_TX

																						//=====================================
		DMA2_Stream3,														// 	DMA_Stream_TypeDef	DMA_TX_Channel;
																						//=====================================
		                                    
																						//=====================================
		DMA2_Stream2,														// 	DMA_Stream_TypeDef  DMA_RX_Channel;
																						//=====================================
                                        
		DMA_FLAG_TCIF2,													// 	uint32_t	DMA_TX_FLAG;		//	uint32_t DMA_FLAG		TX:DMA1_FLAG_TC4		RX:DMA1_FLAG_TC5
		DMA_FLAG_TEIF2,													// 	uint32_t	DMA_TX_IT;			//	uint32_t DMA_IT			TX:DMA1_IT_GL4			RX:DMA1_IT_GL5
																						//                                 
		DMA_FLAG_TCIF3,													// 	uint32_t	DMA_RX_FLAG;		//	uint32_t DMA_FLAG		TX:DMA1_FLAG_TC4		RX:DMA1_FLAG_TC5
		DMA_FLAG_TEIF3,													// 	uint32_t	DMA_RX_IT;			//	uint32_t DMA_IT			TX:DMA1_IT_GL4			RX:DMA1_IT_GL5
                                        
																						//=====================================
																						// 	DMA_InitTypeDef		DMA_TX_Init;
																						//=====================================
		{                                   
			DMA_Channel_3,												//   uint32_t DMA_Channel;            /*!< Specifies the channel used for the specified stream. 
																						//                                         This parameter can be a value of @ref DMA_channel */
																						//  
			SPI1_DR_REGISTER,											//   uint32_t DMA_PeripheralBaseAddr; /*!< Specifies the peripheral base address for DMAy Streamx. */
																						//
#pragma	diag_suppress 1296	//	disable warning:  #1296-D: extended constant initialiser used
			(uint32_t)(&SPI_TX_Scratch_Buffer),		//   uint32_t DMA_Memory0BaseAddr;    /*!< Specifies the memory 0 base address for DMAy Streamx. 
																						//                                         This memory is the default memory used when double buffer mode is
																						//                                         not enabled. */
#pragma	diag_warning 1296	//	re-enable warning:  #1296-D: extended constant initialiser used
																						//
			DMA_DIR_MemoryToPeripheral,						//   uint32_t DMA_DIR;                /*!< Specifies if the data will be transferred from memory to peripheral, 
																						//                                         from memory to memory or from peripheral to memory.
																						//                                         This parameter can be a value of @ref DMA_data_transfer_direction */
																						//
			0,																		//   uint32_t DMA_BufferSize;         /*!< Specifies the buffer size, in data unit, of the specified Stream. 
																						//                                         The data unit is equal to the configuration set in DMA_PeripheralDataSize
																						//                                         or DMA_MemoryDataSize members depending in the transfer direction. */
																						//
			DMA_PeripheralInc_Disable,						//   uint32_t DMA_PeripheralInc;      /*!< Specifies whether the Peripheral address register should be incremented or not.
																						//                                         This parameter can be a value of @ref DMA_peripheral_incremented_mode */
																						//
			DMA_MemoryInc_Enable,									//   uint32_t DMA_MemoryInc;          /*!< Specifies whether the memory address register should be incremented or not.
																						//                                         This parameter can be a value of @ref DMA_memory_incremented_mode */
																						//
			DMA_PeripheralDataSize_HalfWord,			//   uint32_t DMA_PeripheralDataSize; /*!< Specifies the Peripheral data width.
																						//                                         This parameter can be a value of @ref DMA_peripheral_data_size */
																						//
			DMA_MemoryDataSize_HalfWord,					//   uint32_t DMA_MemoryDataSize;     /*!< Specifies the Memory data width.
																						//                                         This parameter can be a value of @ref DMA_memory_data_size */
																						//
			DMA_Mode_Normal,											//   uint32_t DMA_Mode;               /*!< Specifies the operation mode of the DMAy Streamx.
																						//                                         This parameter can be a value of @ref DMA_circular_normal_mode
																						//                                         @note The circular buffer mode cannot be used if the memory-to-memory
																						//                                               data transfer is configured on the selected Stream */
																						//
			DMA_Priority_High,										//   uint32_t DMA_Priority;           /*!< Specifies the software priority for the DMAy Streamx.
																						//                                         This parameter can be a value of @ref DMA_priority_level */
																						//
			DMA_FIFOMode_Disable,									//   uint32_t DMA_FIFOMode;          /*!< Specifies if the FIFO mode or Direct mode will be used for the specified Stream.
																						//                                         This parameter can be a value of @ref DMA_fifo_direct_mode
																						//                                         @note The Direct mode (FIFO mode disabled) cannot be used if the 
																						//                                                memory-to-memory data transfer is configured on the selected Stream */
																						//
			DMA_FIFOThreshold_HalfFull,						//   uint32_t DMA_FIFOThreshold;      /*!< Specifies the FIFO threshold level.
																						//                                         This parameter can be a value of @ref DMA_fifo_threshold_level */
																						//
			DMA_MemoryBurst_Single,								//   uint32_t DMA_MemoryBurst;        /*!< Specifies the Burst transfer configuration for the memory transfers. 
																						//                                         It specifies the amount of data to be transferred in a single non interruptable 
																						//                                         transaction. This parameter can be a value of @ref DMA_memory_burst 
																						//                                         @note The burst mode is possible only if the address Increment mode is enabled. */
																						//
			DMA_PeripheralBurst_Single,						//   uint32_t DMA_PeripheralBurst;    /*!< Specifies the Burst transfer configuration for the peripheral transfers. 
																						//                                         It specifies the amount of data to be transferred in a single non interruptable 
																						//                                         transaction. This parameter can be a value of @ref DMA_peripheral_burst
																						//                                         @note The burst mode is possible only if the address Increment mode is enabled. */  
		},                                  
																						//=====================================
																						// 	DMA_InitTypeDef		DMA_RX_Init;
																						//=====================================
		{                                   
			DMA_Channel_3,												//   uint32_t DMA_Channel;            /*!< Specifies the channel used for the specified stream. 
																						//                                         This parameter can be a value of @ref DMA_channel */
																						//  
#pragma	diag_suppress 1296	//	disable warning:  #1296-D: extended constant initialiser used
			SPI1_DR_REGISTER,											//   uint32_t DMA_PeripheralBaseAddr; /*!< Specifies the peripheral base address for DMAy Streamx. */
																						//
			(uint32_t)(&SPI_RX_Scratch_Buffer),		//   uint32_t DMA_Memory0BaseAddr;    /*!< Specifies the memory 0 base address for DMAy Streamx. 
																						//                                         This memory is the default memory used when double buffer mode is
																						//                                         not enabled. */
#pragma	diag_warning 1296	//	re-enable warning:  #1296-D: extended constant initialiser used
																						//
			DMA_DIR_PeripheralToMemory,						//   uint32_t DMA_DIR;                /*!< Specifies if the data will be transferred from memory to peripheral, 
																						//                                         from memory to memory or from peripheral to memory.
																						//                                         This parameter can be a value of @ref DMA_data_transfer_direction */
																						//
			0,																		//   uint32_t DMA_BufferSize;         /*!< Specifies the buffer size, in data unit, of the specified Stream. 
																						//                                         The data unit is equal to the configuration set in DMA_PeripheralDataSize
																						//                                         or DMA_MemoryDataSize members depending in the transfer direction. */
																						//
			DMA_PeripheralInc_Disable,						//   uint32_t DMA_PeripheralInc;      /*!< Specifies whether the Peripheral address register should be incremented or not.
																						//                                         This parameter can be a value of @ref DMA_peripheral_incremented_mode */
																						//
			DMA_MemoryInc_Enable,									//   uint32_t DMA_MemoryInc;          /*!< Specifies whether the memory address register should be incremented or not.
																						//                                         This parameter can be a value of @ref DMA_memory_incremented_mode */
																						//
			DMA_PeripheralDataSize_HalfWord,			//   uint32_t DMA_PeripheralDataSize; /*!< Specifies the Peripheral data width.
																						//                                         This parameter can be a value of @ref DMA_peripheral_data_size */
																						//
			DMA_MemoryDataSize_HalfWord,					//   uint32_t DMA_MemoryDataSize;     /*!< Specifies the Memory data width.
																						//                                         This parameter can be a value of @ref DMA_memory_data_size */
																						//
			DMA_Mode_Normal,											//   uint32_t DMA_Mode;               /*!< Specifies the operation mode of the DMAy Streamx.
																						//                                         This parameter can be a value of @ref DMA_circular_normal_mode
																						//                                         @note The circular buffer mode cannot be used if the memory-to-memory
																						//                                               data transfer is configured on the selected Stream */
																						//
			DMA_Priority_VeryHigh,								//   uint32_t DMA_Priority;           /*!< Specifies the software priority for the DMAy Streamx.
																						//                                         This parameter can be a value of @ref DMA_priority_level */
																						//
			DMA_FIFOMode_Disable,									//   uint32_t DMA_FIFOMode;          /*!< Specifies if the FIFO mode or Direct mode will be used for the specified Stream.
																						//                                         This parameter can be a value of @ref DMA_fifo_direct_mode
																						//                                         @note The Direct mode (FIFO mode disabled) cannot be used if the 
																						//                                                memory-to-memory data transfer is configured on the selected Stream */
																						//
			DMA_FIFOThreshold_HalfFull,						//   uint32_t DMA_FIFOThreshold;      /*!< Specifies the FIFO threshold level.
																						//                                         This parameter can be a value of @ref DMA_fifo_threshold_level */
																						//
			DMA_MemoryBurst_Single,								//   uint32_t DMA_MemoryBurst;        /*!< Specifies the Burst transfer configuration for the memory transfers. 
																						//                                         It specifies the amount of data to be transferred in a single non interruptable 
																						//                                         transaction. This parameter can be a value of @ref DMA_memory_burst 
																						//                                         @note The burst mode is possible only if the address Increment mode is enabled. */
																						//
			DMA_PeripheralBurst_Single,						//   uint32_t DMA_PeripheralBurst;    /*!< Specifies the Burst transfer configuration for the peripheral transfers. 
																						//                                         It specifies the amount of data to be transferred in a single non interruptable 
																						//                                         transaction. This parameter can be a value of @ref DMA_peripheral_burst
																						//                                         @note The burst mode is possible only if the address Increment mode is enabled. */  
		},                                  
																						//=====================================
																						// 	SPI_InitTypeDef		SPIn_InitStructure;
																						//=====================================
		{                                   
			SPI_Direction_2Lines_FullDuplex,			//   uint16_t SPI_Direction;           /*!< Specifies the SPI unidirectional or bidirectional data mode.
																						//                                          This parameter can be a value of @ref SPI_data_direction */
																						//
			SPI_Mode_Master,											//   uint16_t SPI_Mode;                /*!< Specifies the SPI operating mode.
																						//                                          This parameter can be a value of @ref SPI_mode */
																						//
			SPI_DataSize_16b,											//   uint16_t SPI_DataSize;            /*!< Specifies the SPI data size.
																						//                                          This parameter can be a value of @ref SPI_data_size */
																						//
//			SPI_CPOL_High,												//   uint16_t SPI_CPOL;                /*!< Specifies the serial clock steady state.
			SPI_CPOL_Low,												//   uint16_t SPI_CPOL;                /*!< Specifies the serial clock steady state.
																						//                                          This parameter can be a value of @ref SPI_Clock_Polarity */
																						//
//			SPI_CPHA_2Edge,												//   uint16_t SPI_CPHA;                /*!< Specifies the clock active edge for the bit capture.
			SPI_CPHA_1Edge,												//   uint16_t SPI_CPHA;                /*!< Specifies the clock active edge for the bit capture.
																						//                                          This parameter can be a value of @ref SPI_Clock_Phase */
																						//
			SPI_NSS_Soft,													//   uint16_t SPI_NSS;                 /*!< Specifies whether the NSS signal is managed by
																						//                                          hardware (NSS pin) or by software using the SSI bit.
																						//                                          This parameter can be a value of @ref SPI_Slave_Select_management */
//			// APB2 is 90 MHz here, so 90/16=5.625 MHz // pclk is 84 MHz here, so 84/16=5.25 MHz								//  
//			SPI_BaudRatePrescaler_16,							//   uint16_t SPI_BaudRatePrescaler;   /*!< Specifies the Baud Rate prescaler value which will be
			// APB2 is 90 MHz here, so 90/32=2.8125 MHz 								//  
			SPI_BaudRatePrescaler_32,							//   uint16_t SPI_BaudRatePrescaler;   /*!< Specifies the Baud Rate prescaler value which will be
																						//                                          used to configure the transmit and receive SCK clock.
																						//                                          This parameter can be a value of @ref SPI_BaudRate_Prescaler
																						//  18*(1./(90/32.))                                        @note The communication clock is derived from the master
																						//                                                clock. The slave clock does not need to be set. */
																						//
			SPI_FirstBit_MSB,											//   uint16_t SPI_FirstBit;            /*!< Specifies whether data transfers start from MSB or LSB bit.
																						//                                          This parameter can be a value of @ref SPI_MSB_LSB_transmission */
																						//
			7,																		//   uint16_t SPI_CRCPolynomial;       /*!< Specifies the polynomial used for the CRC calculation. */
		}
	},
};
#endif


void ConfigureGPIO(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin, GPIOMode_TypeDef GPIO_Mode, GPIOSpeed_TypeDef GPIO_Speed, GPIOOType_TypeDef GPIO_OType, GPIOPuPd_TypeDef GPIO_PuPd);


void	DFR_SPI_Init(void)
{
	//	===================================
	//	Initialize queues and FSMs
	//	===================================

	//	===================================
	//	Enable SPIn and DMAn and NOT!!! TIM6
	//	===================================

#if		defined(ENABLE_SPI1)
	//	DMA2:Channel3:Stream2 for SPI1_RX
	//	DMA2:Channel3:Stream3 for SPI1_TX
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
#endif

#if		defined(ENABLE_SPI2)
	// 	SPI2_RX 	DMA	4
	// 	SPI2_TX 	DMA	5
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE); 	// now xx Mhz
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);		//	NOTE: Possibly redundant.
#endif

	//	===================================
	//	Perform GPIO pin remapping here...
	//	===================================

//	{
	//	====================================
	//	SPI1
	//	====================================
	//  PA5   Pin 21  SNS_SPCK  Output
	//  PA6   Pin 22  SNS_MISO  Input
	//  PA7   Pin 23  SNS_MOSI  Output
	//	====================================

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, 	GPIO_AF_SPI1);
	ConfigureGPIO		(GPIOA,	GPIO_Pin_5,				GPIO_Mode_AF, GPIO_Speed_25MHz,	GPIO_OType_PP, GPIO_PuPd_DOWN);	//  PA5   Pin 21  SNS_SPCK  Output

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, 	GPIO_AF_SPI1);	
	ConfigureGPIO		(GPIOA, GPIO_Pin_6,				GPIO_Mode_AF, GPIO_Speed_25MHz, GPIO_OType_OD, GPIO_PuPd_UP);		//  PA6   Pin 22  SNS_MISO  Input

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, 	GPIO_AF_SPI1);	
	ConfigureGPIO		(GPIOA, GPIO_Pin_7, 			GPIO_Mode_AF, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL);//	PA7   Pin 23  SNS_MOSI  Output

	GPIO_SetBits(GPIOA, GPIO_Pin_5);    		 	//  PA5   Pin 21  SNS_SPCK  Output
//	GPIO_ResetBits(GPIOA, GPIO_Pin_6);     	//  PA6   Pin 22  SNS_MISO  Input
	GPIO_SetBits(GPIOA, GPIO_Pin_7);     			//  PA7   Pin 23  SNS_MOSI  Output

//	Configure:
//	==============================================================================
//	SPI_CS2		3		D10			17			PB6		GPIO													VNI8200XP
//	SPI_CS1		2		D9			19			PC7		GPIO													CLT01-38SQ7 
//	OUT_EN		7		D6			25			PB10	GPIO													VNI8200XP
	ConfigureGPIO		(GPIOB, GPIO_Pin_6,	GPIO_Mode_OUT,	GPIO_Speed_2MHz, GPIO_OType_PP,	GPIO_PuPd_NOPULL);	//	SPI_CS2	PB6		VNI8200XP
	ConfigureGPIO		(GPIOC, GPIO_Pin_7,	GPIO_Mode_OUT,	GPIO_Speed_2MHz, GPIO_OType_PP,	GPIO_PuPd_NOPULL);	//	SPI_CS1	PC7	CLT01-38SQ7
	ConfigureGPIO		(GPIOB, GPIO_Pin_10,	GPIO_Mode_OUT,	GPIO_Speed_2MHz, GPIO_OType_PP,	GPIO_PuPd_NOPULL);	//	SPI_CS1	PC7	CLT01-38SQ7

	GPIO_SetBits(GPIOB, GPIO_Pin_6);		//	SPI_CS2	PB6		VNI8200XP
	GPIO_SetBits(GPIOC, GPIO_Pin_7);		//	SPI_CS1	PC7		CLT01-38SQ7
	GPIO_SetBits(GPIOB, GPIO_Pin_10);		//	OUT_EN	PB10 	VNI8200XP

	#if		defined(ENABLE_SPI1)
		{
			/* SPI1 configuration */
			SPI_Init(SPI_UCB_1.UCB.HW, &(SPI_UCB_1.Context.SPIn_InitStructure));

			/* Enable SPI1  */
			SPI_Cmd(SPI_UCB_1.UCB.HW, ENABLE);
		}
	#endif
	#if		defined(ENABLE_SPI2)
		{
			/* SPI2 configuration */
			SPI_Init(SPI_UCB_2.UCB.HW, &(SPI_UCB_2.Context.SPIn_InitStructure));	//SPI_Init(SPI2, &SPI2_InitStructure);
			/* Enable SPI2  */
			SPI_Cmd(SPI_UCB_2.UCB.HW, ENABLE);	//			SPI_Cmd(SPI2, ENABLE);
		}
	#endif	//	ENABLE_SPI2
															
	//	===================================
	//	Setup Interrupt Vector(s)
	//	===================================

	DISABLE_INTERRUPTS;		//	__disable_irq();
	{
	#if		defined(ENABLE_SPI1)
		// 	SPI1_RX 	DMA	2
		// 	SPI1_TX 	DMA	3
		
		{
			//	Setup SPI1 ISR for SPI Error Interrupt (OVR handler)

		  NVIC_InitTypeDef NVIC_InitStructure;

		  NVIC_InitStructure.NVIC_IRQChannel = SPI1_IRQn;	//SPI1_IRQChannel;
		  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
		  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
		  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	
		  NVIC_Init(&NVIC_InitStructure);

			//	Clear any pending Interrupt first?
//			SPI_I2S_ITConfig(SPI_UCB_1.UCB.HW, SPI_I2S_IT_ERR, ENABLE);
			SPI_I2S_ITConfig(SPI_UCB_1.UCB.HW, SPI_I2S_IT_RXNE, ENABLE);
		}
	#endif	//	ENABLE_SPI1

	#if		defined(ENABLE_SPI2)
		//	Setup SPI2 RX	DMA Interrupt
		{
		  NVIC_InitTypeDef NVIC_InitStructure;
		#if		defined(CMSIS_3_5_0)
#define DMA1_Channel4_IRQChannel     ((u8)0x0E)  /* DMA1 Channel 4 global Interrupt */
		#endif			
		  NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel4_IRQChannel;
		  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
		  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//	8;	//	1;
		  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	
		  NVIC_Init(&NVIC_InitStructure);

//			NVIC_ClearIRQChannelPendingBit();		//	NVIC_ClearPendingIRQ();
		}

		{
			//	Setup SPI2 ISR for SPI Error Interrupt (OVR handler)

		  NVIC_InitTypeDef NVIC_InitStructure;
			#if		defined(CMSIS_3_5_0)
#define SPI2_IRQChannel              ((u8)0x24)  /* SPI2 global Interrupt */
			#endif			
		  NVIC_InitStructure.NVIC_IRQChannel = SPI2_IRQChannel;
		  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	//3;
		  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//1;
		  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	
		  NVIC_Init(&NVIC_InitStructure);

			//	Clear any pending Interrupt first?
			#if		defined(ENABLE_SPI2_SLAVE)
			SPI_I2S_ITConfig(SPI2, SPI_I2S_IT_RXNE, ENABLE);
			#else
			SPI_I2S_ITConfig(SPI2, SPI_I2S_IT_ERR, ENABLE);
			#endif
		}
	#endif	//	ENABLE_SPI2
	}
	ENABLE_INTERRUPTS;		//	__enable_irq();
}

//!!!JLM	Add code to verify (Input Length == Output Length)

IOP_status_t	SPI_Qualify(IOPacket_t *packet)
{
	IOP_status_t	status	=	packet->Status;

	SPI_Mode_Bits_t	SPI_Bits	=	*((SPI_Mode_Bits_t	*)(&(packet->Function_Ext)));

	int16_t	VLUN	=	SPI_Bits.VLUN;

JLM_Debug	=	status;	//packet->Status;

#if		000	//	This check is handled in the Start function.
	#if		defined(ENABLE_SPI1)
	if(packet->LUN	!=	SPI_UNIT_1)
	#else			
	if(packet->LUN	!=	SPI_UNIT_2)
	#endif	
	{
		//	...Invalid LUN...

		status	=	IOP_INVALID_DEVICE;
	}
	else
#endif

#if		(defined(SQ_CST_0342)	or	defined(SQ_RPS_0058)	or	defined(SQ_RPS_0059)	or	defined(ENABLE_SPI_GYRO)	)
	if((VLUN	<=	SPI_VLUN_0)	or	(VLUN	>	SPI_VLUN_3))
#else
	if(VLUN	>=	SPI_VLUN_2)	//if((VLUN	<=	SPI_VLUN_0)	or	(VLUN	>=	SPI_VLUN_3))
#endif
	{
		//	...Invalid VLUN...

		status	=	IOP_INVALID_DEVICE;
	}
	else
	if
	(			(packet->Function	==	IOP_READ)	
		or	(packet->Function	==	IOP_WRITE)
		or	(packet->Function	==	SPI_READ_WRITE)
		or	(packet->Function	==	SPI_READ)
		or	(packet->Function	==	SPI_WRITE)
		or	(packet->Function	==	SPI_WRITE_8BIT)
	)
	{
		//	...All is well...
	}
	else
	{
		//	...Invalid Function
JLM_Debug	=	packet->Function;	
		status	=	IOP_INVALID_FUNCTION;
	}

	return(status);	//(packet->Status);
}



//volatile	int	JLM_SPI_LOCK	=	0;


IOP_status_t	SPI_Start(UCB_t	*UCB)
{
	return(IOP_COMPLETED);
}


volatile	uint32_t	SPI1_DR	=	0;
volatile	uint32_t	SPI1_SR	=	0;
extern volatile SPI_output_vector_t SPI_output_vector;
extern volatile input_vector_t input_vector;

//typedef	struct	CLT_Read_s
//{
//	uint16_t	High	:	1;		//	This is bit 0
//	uint16_t	Low		:	1;		//	This is bit 1
//	uint16_t	PC4		:	1;		//	This is bit 1
//	uint16_t	PC3		:	1;		//	This is bit 1

//	uint16_t	PC2		:	1;		//	This is bit 1
//	uint16_t	PC1		:	1;		//	This is bit 1
//	uint16_t	OTA		:	1;		//	This is bit 1
//	uint16_t	UVA		:	1;		//	This is bit 1

//	uint16_t	IN1		:	1;		//	This is bit 1
//	uint16_t	IN2		:	1;		//	This is bit 1
//	uint16_t	IN3		:	1;		//	This is bit 1
//	uint16_t	IN4		:	1;		//	This is bit 1
// 	uint16_t	IN5		:	1;		//	This is bit 1
//	uint16_t	IN6		:	1;		//	This is bit 1
//	uint16_t	IN7		:	1;		//	This is bit 1
//	uint16_t	IN8		:	1;		//	This is bit 1
//}
//CLT_Read_t;

//typedef	struct	CLT_Read_s
//{
//	int	High	:	1;		//	This is bit 0
//	int	Low		:	1;		//	This is bit 1
//	int	PC4		:	1;		//	This is bit 1
//	int	PC3		:	1;		//	This is bit 1

//	int	PC2		:	1;		//	This is bit 1
//	int	PC1		:	1;		//	This is bit 1
//	int	OTA		:	1;		//	This is bit 1
//	int	UVA		:	1;		//	This is bit 1

//	int	IN1		:	1;		//	This is bit 1
//	int	IN2		:	1;		//	This is bit 1
//	int	IN3		:	1;		//	This is bit 1
//	int	IN4		:	1;		//	This is bit 1
// 	int	IN5		:	1;		//	This is bit 1
//	int	IN6		:	1;		//	This is bit 1
//	int	IN7		:	1;		//	This is bit 1
//	int	IN8		:	1;		//	This is bit 1
//}
//CLT_Read_t;

//typedef	struct	VNI_Read_s
//{
//	uint16_t	nP0		:	1;		//	This is bit 0
//	uint16_t	P0		:	1;		//	This is bit 1
//	uint16_t	P1		:	1;		//	This is bit 1
//	uint16_t	P2		:	1;		//	This is bit 1

//	uint16_t	PG		:	1;		//	This is bit 1			//	Power Good Status bit
//	uint16_t	PC		:	1;		//	This is bit 1			//	Parity Check Status bit
//	uint16_t	TWARN	:	1;		//	This is bit 1		//	Temperature Warning bit
//	uint16_t	FBOK	:	1;		//	This is bit 1

//	uint16_t	F1		:	1;		//	This is bit 1
//	uint16_t	F2		:	1;		//	This is bit 1
//	uint16_t	F3		:	1;		//	This is bit 1
//	uint16_t	F4		:	1;		//	This is bit 1
//	uint16_t	F5		:	1;		//	This is bit 1
//	uint16_t	F6		:	1;		//	This is bit 1
//	uint16_t	F7		:	1;		//	This is bit 1
//	uint16_t	F8		:	1;		//	This is bit 1
//}
//VNI_Read_t;


//typedef	union	CLT_Read_u
//{
//	uint16_t		word;
//	uint8_t			bytes[2];
//	CLT_Read_t	bit;
//}
//CLT_Read_u_t;

//typedef	union	VNI_Read_u
//{
//	uint16_t		word;
//	uint8_t			bytes[2];
//	VNI_Read_t	bit;
//}
//VNI_Read_u_t;


//typedef	struct	VNI_Write_s
//{
//	uint16_t	nP0		:	1;		//	This is bit 0
//	uint16_t	P0		:	1;		//	This is bit 1
//	uint16_t	P1		:	1;		//	This is bit 2
//	uint16_t	P2		:	1;		//	This is bit 3

//	uint16_t	SPARE		:	4;		//	This is bits 4-7

//	uint16_t	IN1		:	1;		//	This is bit 9
//	uint16_t	IN2		:	1;		//	This is bit 10
//	uint16_t	IN3		:	1;		//	This is bit 11
//	uint16_t	IN4		:	1;		//	This is bit 12
//	uint16_t	IN5		:	1;		//	This is bit 13
//	uint16_t	IN6		:	1;		//	This is bit 14
//	uint16_t	IN7		:	1;		//	This is bit 15
//	uint16_t	IN8		:	1;		//	This is bit 8
//}
//VNI_Write_t;


//typedef	union	VNI_Write_u
//{
//	uint16_t		word;
//	VNI_Write_t	bit;
//}
//VNI_Write_u_t;




volatile	CLT_Read_u_t	CLT_Read;		//	This is the SPI input chip
volatile	uint16_t	CLT_Write;			//	This is the SPI input chip

volatile	VNI_Read_u_t	VNI_Read;		//	This is the SPI output chip
volatile	VNI_Write_u_t	VNI_Write;			//	This is the SPI output chip

int SPI_ring_count = 0;
int SPI_read_idx = 0;
int SPI_write_idx = 0;
const int SPI_ring_size = 5;

volatile CLT_Read_u_t CLT_read_buff[SPI_ring_size] = {0};

bool add_to_SPI_ring(uint16_t x){
	
		
		CLT_read_buff[SPI_write_idx].word = x;
		SPI_write_idx++;
		
		if(SPI_write_idx >= SPI_ring_size){
			SPI_write_idx = 0;
		}
		
		SPI_ring_count++;
		
		return true;
}


CLT_Read_u_t all_ones; // AND them all
CLT_Read_u_t all_zeroes;
CLT_Read_u_t OR_temp;
CLT_Read_u_t debounced_data = {0}; // NEXT STATE

int i;
volatile uint16_t my_debug;
CLT_Read_u_t debounce_SPI_input(void){
	
		all_ones.word = 0xFFFF;
		OR_temp.word = 0;
	
		for(i = 0; i < SPI_ring_size; i++){
			all_ones.word &= CLT_read_buff[i].word; 		// AND all the contents of the ring buffer
			OR_temp.word |= (CLT_read_buff[i].word);		// Or them all 
		}
		my_debug = all_ones.word;
		all_zeroes.word = ~OR_temp.word;							// Negate OR so you get NOR
		
//  NEXT_STATE 					=  (A1 * A0) + (~A0 * S )  
// 	See State Diagram for logic
		
		debounced_data.word = (all_ones.word & (~all_zeroes.word))|((~all_zeroes.word)& debounced_data.word);
 
		return debounced_data;
}

//bool rising_edge(){


//}


void	Set_SPI_Outputs(volatile	VNI_Write_u_t	*WriteValue)
{
	//	Note:	We have numbered bits [1-8] to match the PCB markings 
	//				instead of [0-7] to match the data sheet.

//	WriteValue.bit.IN1	=	OFF;  test mechanism to force an output
// WriteValue->bit.IN2	=	ON;
//	WriteValue->bit.IN3	=	ON; // PUT THIS HIGH FOR DEBUGGING -- SOLVED: POWER ISSUE FROM BATTERY
														// set high for electrical pre-inspection
//	WriteValue.bit.IN4	=	OFF;
//	WriteValue.bit.IN5	=	OFF;
//	WriteValue.bit.IN6	=	OFF;
//	WriteValue.bit.IN7	=	OFF;
//	WriteValue.bit.IN8	=	OFF;
	
	WriteValue->bit.SPARE	=	0;
	
	WriteValue->bit.P0	=	
	(
			WriteValue->bit.IN1
		+ WriteValue->bit.IN2
		+ WriteValue->bit.IN3
		+ WriteValue->bit.IN4
		+ WriteValue->bit.IN5
		+ WriteValue->bit.IN6
		+ WriteValue->bit.IN7
		+	WriteValue->bit.IN8
	);
	
	WriteValue->bit.P1	=	
	(
			WriteValue->bit.IN2
		+ WriteValue->bit.IN4
		+ WriteValue->bit.IN6
		+	WriteValue->bit.IN8
	);
	
	WriteValue->bit.P2	=	
	(
			WriteValue->bit.IN1
		+ WriteValue->bit.IN3
		+ WriteValue->bit.IN5
		+ WriteValue->bit.IN7
	);
	
	WriteValue->bit.nP0	=	!(WriteValue->bit.P0);
}


void GLVS_enable(void) {
		SPI_output_vector.safety = ON;
}

void GLVS_disable(void){
	// called to shut down GLVS if there's an error...
	SPI_output_vector.safety = OFF;
}

volatile uint16_t my_test;
void	SPI1_IRQHandler(void)
{
	switch(SPI_io_state){
		//-----------------------------------------------------------
		case(wait_for_SPI_A):
		//-----------------------------------------------------------
			GPIO_SetBits(GPIOC, GPIO_Pin_7);			//	SPI_CS1	PC7	CLT01-38SQ7
			//	Read the Input chip data
			// CLT_Read.word	=	SPI1->DR;	//	Read it to clear it, in case there's something in there.
		#if 000
			my_test = SPI1->DR;
			add_to_SPI_ring(my_test);
		#else
			add_to_SPI_ring((uint16_t)SPI1->DR);
		#endif 
		
// CLT_Read.word =	(uint16_t)SPI1->DR;
		
			SPI1_SR	=	SPI1->SR;	//	Read it to clear it, in case there's something in there.
//			GPIO_ResetBits(GPIOB, GPIO_Pin_6);		//	SPI_CS2	PB6		VNI8200XP
		
	#if 000
		CLT_Read.word =	(uint16_t)SPI1->DR;
	#else
		 CLT_Read = debounce_SPI_input();
	#endif
		
			// put debouncing method here
			// ring buffer
		
			//	map inputs into Input Vector
		
			// place holder = CLT_Read.bit.IN1;
			input_vector.dash_brb_pressed = !CLT_Read.bit.IN2; // when pressed, the signal goes to zero, so flip it so the variable is high-true.
			input_vector.ice_mode = CLT_Read.bit.IN3;
			input_vector.motor_mode = CLT_Read.bit.IN4;
			input_vector.push_button_1 = CLT_Read.bit.IN5;
			input_vector.push_button_2 = CLT_Read.bit.IN6;
			// placeholder = CLT_Read.bit.IN7
			// placeholder = CLT_Read.bit.IN8
			
		
			//	Turn something on
			{
				// map SPI output vector to SPI output 
				VNI_Write.bit.IN1	=	OFF ;
				VNI_Write.bit.IN2	=	OFF;
				VNI_Write.bit.IN3	=	SPI_output_vector.safety;
				VNI_Write.bit.IN4	=	SPI_output_vector.ready_to_drive;
				VNI_Write.bit.IN5	=	SPI_output_vector.rfg;
				VNI_Write.bit.IN6	=	ON; // check this out
				VNI_Write.bit.IN7	=	OFF;
				VNI_Write.bit.IN8	=	OFF;
				Set_SPI_Outputs(&VNI_Write);
			}
			
			
			GPIO_ResetBits(GPIOB, GPIO_Pin_6);		//	SPI_CS2	PB6		VNI8200XP
			SPI_I2S_SendData(SPI1, VNI_Write.word);
			SPI_io_state = wait_for_SPI_B;
			break;
		//-----------------------------------------------------------
		case(wait_for_SPI_B):
		//-----------------------------------------------------------
			GPIO_SetBits(GPIOB, GPIO_Pin_6);		//	SPI_CS2	PB6		VNI8200XP
			//	Read the Output chip data
			VNI_Read.word	=	SPI1->DR;	//	Read it to clear it, in case there's something in there.
		
			#ifdef FORCE_PG
				VNI_Read.bit.PG = 1;
			#endif 
			SPI1_SR	=	SPI1->SR;	//	Read it to clear it, in case there's something in there.

			SPI_io_state = wait_for_TIM3;
			break;
		//-----------------------------------------------------------
		case(wait_for_TIM3):
		//-----------------------------------------------------------
		default:
		//-----------------------------------------------------------
			// do nothing
			break;
	}
	
}


