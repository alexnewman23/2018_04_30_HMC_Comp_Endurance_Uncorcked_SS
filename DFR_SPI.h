//	DFR_SPI.h


#ifndef DFR_SPI_H_
#define DFR_SPI_H_


#define	ENABLE_SPI1	(1)


#include <iso646.h>
#include <stdint.h>


#include	"misc.h"		//	be aware there are 2 versions (or more) of this file: one for the CMSIS 10x and another for the CMSIS 40x.
#include	"stm32f4xx_dma.h"
#include	"stm32f4xx_spi.h"

#include "SQ_IOM.h"

typedef	enum	ON_OFF_e
{
	OFF	=	0,
	ON	=	1,
	PRESSED = ON,
	NOT_PRESSED = OFF
}
ON_OFF_t;

typedef	struct	CLT_Read_s
{
	int	High	:	1;		//	This is bit 0
	int	Low		:	1;		//	This is bit 1
	int	PC4		:	1;		//	This is bit 1
	int	PC3		:	1;		//	This is bit 1

	int	PC2		:	1;		//	This is bit 1
	int	PC1		:	1;		//	This is bit 1
	int	OTA		:	1;		//	This is bit 1
	int	UVA		:	1;		//	This is bit 1

	int	IN1		:	1;		//	This is bit 1
	int	IN2		:	1;		//	This is bit 1
	int	IN3		:	1;		//	This is bit 1
	int	IN4		:	1;		//	This is bit 1
 	int	IN5		:	1;		//	This is bit 1
	int	IN6		:	1;		//	This is bit 1
	int	IN7		:	1;		//	This is bit 1
	int	IN8		:	1;		//	This is bit 1
}
CLT_Read_t;

typedef	struct	VNI_Read_s
{
	uint16_t	nP0		:	1;		//	This is bit 0
	uint16_t	P0		:	1;		//	This is bit 1
	uint16_t	P1		:	1;		//	This is bit 1
	uint16_t	P2		:	1;		//	This is bit 1

	uint16_t	PG		:	1;		//	This is bit 1			//	Power Good Status bit
	uint16_t	PC		:	1;		//	This is bit 1			//	Parity Check Status bit
	uint16_t	TWARN	:	1;		//	This is bit 1		//	Temperature Warning bit -- HIGH means that there is *NO* warning
	uint16_t	FBOK	:	1;		//	This is bit 1

	uint16_t	F1		:	1;		//	This is bit 1
	uint16_t	F2		:	1;		//	This is bit 1
	uint16_t	F3		:	1;		//	This is bit 1
	uint16_t	F4		:	1;		//	This is bit 1
	uint16_t	F5		:	1;		//	This is bit 1
	uint16_t	F6		:	1;		//	This is bit 1
	uint16_t	F7		:	1;		//	This is bit 1
	uint16_t	F8		:	1;		//	This is bit 1
}
VNI_Read_t;

typedef	struct	VNI_Write_s
{
	uint16_t	nP0		:	1;		//	This is bit 0
	uint16_t	P0		:	1;		//	This is bit 1
	uint16_t	P1		:	1;		//	This is bit 2
	uint16_t	P2		:	1;		//	This is bit 3

	uint16_t	SPARE		:	4;		//	This is bits 4-7

	uint16_t	IN1		:	1;		//	This is bit 9
	uint16_t	IN2		:	1;		//	This is bit 10
	uint16_t	IN3		:	1;		//	This is bit 11
	uint16_t	IN4		:	1;		//	This is bit 12
	uint16_t	IN5		:	1;		//	This is bit 13
	uint16_t	IN6		:	1;		//	This is bit 14
	uint16_t	IN7		:	1;		//	This is bit 15
	uint16_t	IN8		:	1;		//	This is bit 8
}
VNI_Write_t;


typedef	union	CLT_Read_u
{
	uint16_t		word;
	uint8_t			bytes[2];
	CLT_Read_t	bit;
}
CLT_Read_u_t;

typedef	union	VNI_Write_u
{
	uint16_t		word;
	VNI_Write_t	bit;
}
VNI_Write_u_t;

typedef	union	VNI_Read_u
{
	uint16_t		word;
	uint8_t			bytes[2];
	VNI_Read_t	bit;
}
VNI_Read_u_t;


extern volatile	CLT_Read_u_t	CLT_Read;
extern volatile	VNI_Read_u_t	VNI_Read;		//	This is the SPI output chip



typedef	struct	SPI_CR1_BIT_s
{
	unsigned	int	CPHA			:	1;	//	bit	00
	unsigned	int	CPOL			:	1;	//	bit	01
	unsigned	int	MSTR			:	1;	//	bit	02
	unsigned	int	BR				:	3;	//	bits	03-05

	unsigned	int	SPE				:	1;	//	bit	06
	unsigned	int	LSBFIRST	:	1;	//	bit	07
	unsigned	int	SSI				:	1;	//	bit	08
	unsigned	int	SSM				:	1;	//	bit	09

	unsigned	int	RXONLY		:	1;	//	bit	10
	unsigned	int	DFF				:	1;	//	bit	11
	unsigned	int	CRCNEXT		:	1;	//	bit	12
	unsigned	int	CRCEN			:	1;	//	bit	13
	unsigned	int	BIDIOE		:	1;	//	bit	14
	unsigned	int	BIDIMODE	:	1;	//	bit	15
}
SPI_CR1_BIT_t;


typedef	struct	SPI_SR_BIT_s
{
	unsigned	int	RXNE			:	1;	//	bit	00
	unsigned	int	TXE				:	1;	//	bit	01
	unsigned	int	CHSIDE		:	1;	//	bit	02
	unsigned	int	UDR				:	1;	//	bit	03

	unsigned	int	CRCERR		:	1;	//	bit	04
	unsigned	int	MODF			:	1;	//	bit	05
	unsigned	int	OVR				:	1;	//	bit	06
	unsigned	int	BSY				:	1;	//	bit	07

	unsigned	int	Reserved	:	8;
}
SPI_SR_BIT_t;

typedef enum SPI_io_states_t {
	wait_for_TIM3,
	wait_for_SPI_A,
	wait_for_SPI_B
	
} SPI_io_states_t;

extern volatile SPI_io_states_t SPI_io_state;
extern volatile	uint16_t	CLT_Write;	//	This is the SPI input chip

void GLVS_enable(void);
void GLVS_disable(void);
 

//	Choose !CS I/O options
#define	USE_GPIO_FOR_CS	(1)		//	Define to drive SPI2 pin NSS as a GPIO (instead of NSS alternate function)	[Assumes single EEPROM, no buffer/selector]
//#define	USE_INVERTED_CS	(1)		//	Define to drive SPI2 pin NSS as a GPIO (instead of NSS alternate function)	[Assumes single EEPROM, no buffer/selector]

#if		defined(SHRINK)
#define	SPI_MAX_BUFFER_SIZE	((size_t)(128))
#else
#define	SPI_MAX_BUFFER_SIZE	((size_t)(256))
#endif

//	Note that IOP Function codes for this driver are in IOM.h for now...


typedef	enum	SPI_Function_Extension_e
{
	//	We'll use lower 8 bits for VLUN index

	//	VLUN index is used to select one of several devices on a specific SPI UCB channel.
	//	FDOT Daughter card has 4 selects [chosen by GPIOs PC3 and PC2]

	//	We'll use lower 8 bits for the VLUN field

	SPI_VLUN_BASE				=	0,

	SPI_VLUN_0					=	(SPI_VLUN_BASE	+	0),		//	!CS0 on FDOT Daughter Card, SPI Flash EEPROM 0
	SPI_VLUN_1					=	(SPI_VLUN_BASE	+	1),		//	!CS0 on FDOT Daughter Card, (not used, reserved for GPIO extension)
	SPI_VLUN_2					=	(SPI_VLUN_BASE	+	2),		//	!CS2 on FDOT Daughter Card, SPI Flash EEPROM 1
	SPI_VLUN_3					=	(SPI_VLUN_BASE	+	3),		//	!CS3 on FDOT Daughter Card, SPI RTC (Maxim DS1390)

	SPI_EEPROM_0				=	SPI_VLUN_0,							//	!CS0 on FDOT Daughter Card, SPI Flash EEPROM 0

#if		(defined(SQ_MBL_HW)	or	defined(MA_0069_HW)		or	defined(MA_0070_HW)		or	defined(MA_0071_HW)	)
	#if		defined(SQ_MBL_HW_REV_A)
	SPI_GYRO						=	SPI_VLUN_1,							//	!NSS-GYRO
	#endif
#elif	defined(HW_MBD_T)	
	SPI_RTC							=	SPI_VLUN_1,							//	!CS2 on FDOT Daughter Card, SPI RTC (Maxim DS1390)
#else	
	SPI_EEPROM_1				=	SPI_VLUN_1,							//	!CS2 on FDOT Daughter Card, SPI Flash EEPROM 1
	SPI_RTC							=	SPI_VLUN_3,							//	!CS3 on FDOT Daughter Card, SPI RTC (Maxim DS1390)
#endif

	//	We'll use the upper 8 bits for SPI 'mode' bits

	SPI_MODE_BASE				=	(0x0100),								//	Bias to upper 8 bits

	//	First 3 bits for Speed, use bits 10-8

	SPI_NORMAL_SPEED		=	(SPI_MODE_BASE	*	0),		//	NOTE:  If not initialized (i.e. = 0x00) then we use 'Normal' Speed, currently 9 MHz, [9 MHz avoids potetnail bus contention issues between SPI2 and CAN Buffer]
	SPI_HALF_SPEED			=	(SPI_MODE_BASE	*	1),		//	'Half' 		Normal Speed
	SPI_QUARTER_SPEED		=	(SPI_MODE_BASE	*	2),		//	'Quarter' Normal Speed
	SPI_HIGH_SPEED			=	(SPI_MODE_BASE	*	3),		//	'Double'	Normal Speed

	SPI_18_MHZ_CLOCK		=	SPI_HIGH_SPEED,			
	SPI_9_MHZ_CLOCK			=	SPI_NORMAL_SPEED,
	SPI_4_5_MHZ_CLOCK		=	SPI_HALF_SPEED,
	SPI_2_25_MHZ_CLOCK	=	SPI_QUARTER_SPEED,

	SPI_MODE_BIT_11			=	(0x0800),		//	bit 11			 [reserve for 8 bit operations?]

//	SPI_8_BIT_MODE			=	 SPI_MODE_BIT_11,				//		NOTE:	Not the same as the 8 bit mode used for SPI_WRITE_8BIT, which uses lower 8 bits of 16 bit words, not true 8 bit DMA mode.

	SPI_MODE_BIT_12			=	(0x1000),		//	bit 12
	SPI_MODE_BIT_13			=	(0x2000),		//	bit 13
	SPI_MODE_BIT_14			=	(0x4000),		//	bit 14
	SPI_MODE_BIT_15			=	(0x8000)		//	bit 15
}
SPI_Function_Extension_t;


typedef	struct	SPI_Mode_Bits_s
{
	uint16_t	VLUN					:	8;		//	bits	7-0		Virtual LUN Index, multiplexes multiple devices/chip selects on a single UCB
	uint16_t	SPI_Speed			:	3;		//	bits	10-8	SPI Speed selection
	uint16_t	SPI_Mode_Bits	:	5;		//	bits	15-11	SPI Mode bits	[e.g. 8/16, special timing overlap, redundant reads, etc.  Not currently used, reserved.]
}
SPI_Mode_Bits_t;



typedef	struct	SPI_Context_s	
{
	DMA_Stream_TypeDef	*DMA_TX_Channel;
	DMA_Stream_TypeDef  *DMA_RX_Channel;

// #define DMA_FLAG_FEIF2                    ((uint32_t)0x10010000)
// #define DMA_FLAG_DMEIF2                   ((uint32_t)0x10040000)
// #define DMA_FLAG_TEIF2                    ((uint32_t)0x10080000)
// #define DMA_FLAG_HTIF2                    ((uint32_t)0x10100000)
// #define DMA_FLAG_TCIF2                    ((uint32_t)0x10200000)

	uint32_t	DMA_TX_FLAG;		//	uint32_t DMA_FLAG		TX:DMA1_FLAG_TC4		RX:DMA1_FLAG_TC5
	uint32_t	DMA_TX_IT;			//	uint32_t DMA_IT			TX:DMA1_IT_GL4			RX:DMA1_IT_GL5
                                
	uint32_t	DMA_RX_FLAG;		//	uint32_t DMA_FLAG		TX:DMA1_FLAG_TC4		RX:DMA1_FLAG_TC5
	uint32_t	DMA_RX_IT;			//	uint32_t DMA_IT			TX:DMA1_IT_GL4			RX:DMA1_IT_GL5

	DMA_InitTypeDef		DMA_TX_Init;
	DMA_InitTypeDef		DMA_RX_Init;

	SPI_InitTypeDef		SPIn_InitStructure;
}
SPI_Context_t;


typedef	struct	SPI_UCB_s
{
	UCB_t						UCB;
	SPI_Context_t	Context;
}
SPI_UCB_t;



typedef	volatile	struct	SPI_WRITE_IOPacket_s
{
	void								*Link;					//	Link pointer to next IOP in chain
	IOM_Device_Types_t	Device;					//	Device Type

	uint16_t						LUN;						//	Logical Unit Number
	uint16_t						Function_Ext;		//	Extended Function code

	FUNCTION_t					Function;				//	Operation to be performed
	IOP_status_t				Status;					//	Packet Status
	IOP_status_t 				(*Callback)(IOPacket_t *packet);	//	(*Callback)(struct IOPacket_s *packet);
	uint32_t						Header_Length;	//	Length of Header Buffer
	void								*Header;				//	Pointer to Header Buffer
	uint32_t						Output_Length;	//	Actual or Max. Length of Output Buffer
	void								*Output;				//	Pointer to Output Buffer
	uint32_t						P5;							//	parameter 5
	uint32_t						P6;							//	parameter 6
}
SPI_WRITE_IOPacket_t;


typedef	volatile	struct	SPI_READ_IOPacket_s
{
	void								*Link;					//	Link pointer to next IOP in chain
	IOM_Device_Types_t	Device;					//	Device Type

	uint16_t						LUN;						//	Logical Unit Number
	uint16_t						Function_Ext;		//	Extended Function code

	FUNCTION_t					Function;				//	Operation to be performed
	IOP_status_t				Status;					//	Packet Status
	IOP_status_t 				(*Callback)(IOPacket_t *packet);	//	(*Callback)(struct IOPacket_s *packet);
	uint32_t						Header_Length;	//	Length of Header Buffer
	void								*Header;				//	Pointer to Header Buffer
	uint32_t						Input_Length;		//	Actual or Max. Length of Input Buffer
	void								*Input;					//	Pointer to Input Buffer
	uint32_t						P5;							//	parameter 5
	uint32_t						P6;							//	parameter 6
}
SPI_READ_IOPacket_t;


typedef	volatile	struct	SPI_WRITE_8BIT_IOPacket_s
{
	void								*Link;					//	Link pointer to next IOP in chain
	IOM_Device_Types_t	Device;					//	Device Type

	uint16_t						LUN;						//	Logical Unit Number
	uint16_t						Function_Ext;		//	Extended Function code

	FUNCTION_t					Function;				//	Operation to be performed
	IOP_status_t				Status;					//	Packet Status
	IOP_status_t 				(*Callback)(IOPacket_t *packet);	//	(*Callback)(struct IOPacket_s *packet);
	uint32_t						Output_Length;	//	parameter 1
	void								*Output;				//	parameter 2
	uint32_t						P3;							//	parameter 3
	uint32_t						P4;							//	parameter 4
	uint32_t						P5;							//	parameter 5
	uint32_t						P6;							//	parameter 6
}
SPI_WRITE_8BIT_IOPacket_t;



typedef	union	SPI_IOPacket_u
{
	IOPacket_t								IOP;
	SPI_WRITE_IOPacket_t			READ;
	SPI_READ_IOPacket_t				WRITE;
	SPI_WRITE_8BIT_IOPacket_t	WRITE_8BIT;
}
SPI_IOPacket_union_t;


#if		defined(ENABLE_SPI1)
extern	SPI_UCB_t	SPI_UCB_1;
#endif

#if		defined(ENABLE_SPI2)
extern	SPI_UCB_t	SPI_UCB_2;		//extern	UCB_t	SPI_UCB_2;		//	Needed for UCB/DCB initialization, and in stm32f10x_it.c
#endif

void	DFR_SPI_Init(void);		//	called by main() to initialize this driver

IOP_status_t	SPI_Start(UCB_t	*UCB);
IOP_status_t	SPI_Qualify(IOPacket_t *packet);

IOP_status_t	SPI_ISR(UCB_t	*UCB);		//	Needed for now in stm32f10x_it.c


#if		defined(ENABLE_SPI1)		//	To clean up some compiler whining...
//Reference only:	#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000)

//#define	SPI2_DR_REGISTER	(SPI1 + offsetof(SPI_TypeDef, DR))		//	To make compiler happy in strict mode
#define	SPI1_DR_REGISTER	((uint32_t)(SPI1_BASE + (offsetof(SPI_TypeDef, DR))))		//	To make compiler happy in strict mode
#endif

#if		defined(ENABLE_SPI2)		//	To clean up some compiler whining...
//Reference only:	#define SPI2                ((SPI_TypeDef *) SPI2_BASE)

//#define	SPI2_DR_REGISTER	(SPI2 + offsetof(SPI_TypeDef, DR))		//	To make compiler happy in strict mode
#define	SPI2_DR_REGISTER	((uint32_t)(SPI2_BASE + (offsetof(SPI_TypeDef, DR))))		//	To make compiler happy in strict mode
#endif


bool	SPI_Active(void);	//SPI2_Active(void);


#if		001	//	Band-Aid
void	SPI_FSM(UCB_t	*UCB);
#endif


#endif	//	DFR_SPI_H_
