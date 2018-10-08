/******************************************************************************
** Copyright 2010 - SignalQuest, Inc.    PROPRIETARY & CONFIDENTIAL
*******************************************************************************
**
** This file is confidential and proprietary property of SignalQuest, Inc.
** All rights are reserved. This file may not be used, reproduced or
** distributed by any unauthorized party.  Unauthorized copies of this file
** must be deleted or destroyed immediately.
**
*******************************************************************************
**
** SQ_IOM.h
**
**     Queued I/O Manager Core
**
*******************************************************************************/

#ifndef SQ_IOM_H_
#define SQ_IOM_H_


#include <iso646.h>
#include <stddef.h>
#include <stdint.h>

#include	"SQDefs.h"


//*****************************************************************************
//Debugging stuff:
//*****************************************************************************
extern	volatile	uint32_t	JLM_Debug;


//================================================================================
//	not the 'right' place for these...
//================================================================================
#define	Get_SysTick()	(SysTick->VAL)


// a small helper...
#define	until(arg)	while(!(arg))
//================================================================================


typedef	volatile	enum	IOP_status_e
{
	//	Fault Statuses are Negative	(Status < IOP_COMPLETED)

	//	Completed Statuses are (Status <= IOP_COMPLETED)

	//	Completed within Driver and ready for Dequeue and Callback are (Status >= IOP_CALLBACK)

	IOP_PACKET_BUSY	=	-14L,

	IOP_DRIVER_NOT_INITIALIZED	=	-13L,
	IOP_NULL_UCB				=	-12L,
	IOP_NULL_DCB				=	-11L,
	IOP_NULL_BUFFER			=	-10L,
	IOP_INVALID_FUNCTION=	-9L,
	IOP_INVALID_LUN			=	-8L,
	IOP_INVALID_DEVICE	=	-7L,
	IOP_PACKET_NOT_COMPLETED		=	-6L,
	IOP_NOT_IN_QUEUE		=	-5L,
	IOP_UNKNOWN					=	-4L,
	IOP_LINK_NOT_NULL		=	-3L,
	IOP_NULL_PACKET			=	-2L,
	IOP_TIMED_OUT				=	-1L,

	IOP_COMPLETED			=	0,		 	//	Statuses here and above are final, completed statuses

	IOP_QUALIFYING		=	1,			//	Statuses here and below are in progress statuses
	IOP_QUEUED				=	2,
	IOP_ACTIVE				=	3,
	IOP_PENDING				=	4,

	IOP_MSG_COMPLETE	=	32,		//	indicates IO operation is finished and awaiting completion...(for USART Driver's usage to signal end of a parse, or other driver's usage)

	IOP_CALLBACK			=	64,		//	Statuses here and below, still belong to the Driver, and are faulted awaiting completion

//	IOP_DRIVER_NOT_INITIALIZED	+	IOP_FAULTED	=	246,
//	IOP_NULL_UCB	+	IOP_FAULTED				=	247,
//	IOP_NULL_DCB	+	IOP_FAULTED				=	248,
//	IOP_INVALID_LUN	+	IOP_FAULTED			=	249,
//	IOP_INVALID_DEVICE	+	IOP_FAULTED	=	250,
//	IOP_NOT_IN_QUEUE	+	IOP_FAULTED		=	251,
//	IOP_UNKNOWN	+	IOP_FAULTED					=	252,
//	IOP_LINK_NOT_NULL	+	IOP_FAULTED		=	253,
//	IOP_NULL_PACKET	+	IOP_FAULTED			=	254,
//	IOP_TIMED_OUT	+	IOP_FAULTED				=	255,

	IOP_FAULTED				=	256		//	Add to any Negative Status to signal Fault but packet not yet completed (DeQueued/Callback), [generates a positive status that indicates a fault].
}
IOP_status_t;


//	[Optionally] Comment out unneeded Device Types [NOTE:  must matchup with DCB table in IOM.c]
typedef	enum	IOM_Device_Types_e
{
	//	Physical Devices

//	IOM_DEV_ADC,
//	IOM_DEV_DAC,
//	IOM_DEV_TIMER,
//	IOM_DEV_RTC,
//	IOM_DEV_IWDG,
//	IOM_DEV_WWDG,
	IOM_DEV_SPI,
	IOM_DEV_I2C,
	IOM_DEV_USART,
//	IOM_DEV_FLASH,
//	IOM_DEV_CAN,

	//	Virtual Devices

	IOM_DEV_SPI_EEPROM,
#if		defined(MODBUS_STACK)
	IOM_DEV_L2_RX,
	IOM_DEV_L2_TX,
#endif
//	IOM_DEV_L7,

	IOM_DEV_USART_FD_TX,		//	Don't invoke directly, enter through the IOM_DEV_USART driver
//	IOM_DEV_L2_RX	HDLC_L2_RX_DCB
//	IOM_DEV_L2_TX	HDLC_L2_TX_DCB
//	IOM_DEV_L7	HDLC_L7_DCB
	IOM_DEV_SPI_RTC,

	IOM_DEV_NUMBER_OF_DEVICE_TYPES
}
IOM_Device_Types_t;


typedef	enum	FUNCTION_e
{
	NONE								=	0,
	IOP_READ						=	1,
	IOP_WRITE						=	2,
	IOP_READ_WRITE			=	3,

	//	Split these out later, leave here for now

	SPI_READ_WRITE			=	IOP_READ_WRITE,
	SPI_READ						=	4,	//	Optional Header and Optional Input Buffer, if neither, rejected	[Header and Input currently required. SPI_Qualify() needs to be upgraded to enforce this.  Dirver needs to be upgraded to allow for Optional.]
	SPI_WRITE						=	5,	//	Optional Header and Optional Input Buffer, if neither, rejected	[Header and Input currently required. SPI_Qualify() needs to be upgraded to enforce this.  Dirver needs to be upgraded to allow for Optional.]
	SPI_WRITE_8BIT			=	6,	//	NOTE:	SPI_WRITE_8BIT assumes one 8 bit byte per 16 bit half-word	[No header]

	//	Split these out later, leave them here for now

//	SPI_SECTOR_ERASE		=	7,	//	Header contains address
//	SPI_BULK_ERASE			=	8,	//	No Parameters

	SPI_EEPROM_WREN		 	=	9,
	SPI_EEPROM_WRDI		 	=	10,
	SPI_EEPROM_RDID		 	=	11,
	SPI_EEPROM_RDSR		 	=	12,
	SPI_EEPROM_WRSR		 	=	13,
	SPI_EEPROM_READ		 	=	14,
	SPI_EEPROM_FAST_READ	=	15,
	SPI_EEPROM_PP				=	16,
	SPI_EEPROM_SE				=	17,
	SPI_EEPROM_BE				=	18,
	SPI_EEPROM_DP				=	19,
	SPI_EEPROM_RES			=	20,

	AISG_L2_READ				=	21,
	AISG_L2_WRITE				=	22,

	//	Split these out later, leave them here for now

	CAN_TX_11_BIT				=	30,
	CAN_TX_29_BIT				=	31,

	CAN_TX_STD					=	CAN_TX_11_BIT,
	CAN_TX_EXT					=	CAN_TX_29_BIT,

	CAN_SET_FILTER			=	32,		//	TBD
	
	//	Split these out later, leave here for now

//	I2C_READ_WRITE			=	IOP_READ_WRITE,
	I2C_READ						=	33,	//	
	I2C_WRITE						=	34,	//	
	I2C_WRITE_READ			=	35,	//
}
FUNCTION_t;


#if 01

typedef	enum	SPI_Unit_e		//	this belongs elsewhere...
{
	SPI_UNIT_0,
	SPI_UNIT_1,
	SPI_UNIT_2,
	SPI_UNIT_3,
	SPI_NUMBER_OF_UNITS
}
SPI_Unit_t;

#endif

#if 01

typedef	enum	I2C_Unit_e		//	this belongs elsewhere...
{
	I2C_UNIT_0,
	I2C_UNIT_1,
	I2C_UNIT_2,
	I2C_UNIT_3,
	I2C_NUMBER_OF_UNITS
}
I2C_Unit_t;

#endif

#if 01

typedef	enum	CAN_Unit_e		//	this belongs elsewhere...
{
	CAN_UNIT_1,
	CAN_UNIT_1_TX,		//	!!!JLM  FIXME in CAN driver...
	CAN_UNIT_2,
	CAN_UNIT_2_TX,		//	!!!JLM  FIXME in CAN driver...
	CAN_NUMBER_OF_UNITS
}
CAN_Unit_t;

#endif

//	Keep these around for reference:
//
//					typedef IOP_status_t function_ptr_t(void *packet);
//
//					typedef void (*pfv)();								//	"pointer to a function returning void and taking no arguments"
//					typedef void (*pf_taking_pfv) (pfv);	//	"pointer to a function returning void and taking a pfv"
//					typedef IOP_status_t (*Parse_Function_ptr) (IO_PARSE_Packet_t *);	//	"pointer to a function returning IOP_status_t and taking a pointer to a IOPacket_t"

typedef	volatile	
struct	IOPacket_s	IOPacket_t;	//	typedef before the struct declaration to beat the self-referential issues in a monolithic 'typedef struct'
struct	IOPacket_s
{
	IOPacket_t					*Link;					//	Link pointer to next IOP in chain
	IOM_Device_Types_t	Device;					//	Device Type
	uint16_t						LUN;						//	Logical Unit Number
	uint16_t						Function_Ext;		//	Extended Function code
	FUNCTION_t					Function;				//	Operation to be performed
	IOP_status_t				Status;					//	Packet Status
	IOP_status_t 				(*Callback)(IOPacket_t *packet);
	uint32_t						P1;							//	parameter 1
	uint32_t						P2;							//	parameter 2
	uint32_t						P3;							//	parameter 3
	uint32_t						P4;							//	parameter 4
	uint32_t						P5;							//	parameter 5
	uint32_t						P6;							//	parameter 6
};


typedef	volatile	struct	IO_WRITE_Packet_s
{
	IOPacket_t					*Link;					//	Link pointer to next IOP in chain
	IOM_Device_Types_t	Device;					//	Device Type
	uint16_t						LUN;						//	Logical Unit Number
	uint16_t						Function_Ext;		//	Extended Function code
	FUNCTION_t					Function;				//	Operation to be performed
	IOP_status_t				Status;					//	Packet Status
	IOP_status_t 				(*Callback)(IOPacket_t *packet);
	uint32_t									Output_Length;	//	parameter 1
	void								*Output;				//	parameter 2
	uint32_t						P3;							//	parameter 3
	uint32_t						P4;							//	parameter 4
	uint32_t						P5;							//	parameter 5
	uint32_t						P6;							//	parameter 6
}
IO_WRITE_Packet_t;


typedef	volatile	struct	IO_READ_Packet_s
{
	IOPacket_t					*Link;					//	Link pointer to next IOP in chain
	IOM_Device_Types_t	Device;					//	Device Type
	uint16_t						LUN;						//	Logical Unit Number
	uint16_t						Function_Ext;		//	Extended Function code
	FUNCTION_t					Function;				//	Operation to be performed
	IOP_status_t				Status;					//	Packet Status
	IOP_status_t 				(*Callback)(IOPacket_t *packet);
	uint32_t						Input_Length;		//	parameter 1
	void								*Input;					//	parameter 2
	uint32_t						P3;							//	parameter 3
	uint32_t						P4;							//	parameter 4
	uint32_t						P5;							//	parameter 5
	uint32_t						P6;							//	parameter 6
}
IO_READ_Packet_t;


typedef	volatile	struct	IO_READ_WRITE_Packet_s
{
	IOPacket_t					*Link;					//	Link pointer to next IOP in chain
	IOM_Device_Types_t	Device;					//	Device Type
	uint16_t						LUN;						//	Logical Unit Number
	uint16_t						Function_Ext;		//	Extended Function code
	FUNCTION_t					Function;				//	Operation to be performed
	IOP_status_t				Status;					//	Packet Status
	IOP_status_t 				(*Callback)(IOPacket_t *packet);
	uint32_t						Input_Length;		//	parameter 1
	void								*Input;					//	parameter 2
	uint32_t						Output_Length;	//	parameter 3
	void								*Output;				//	parameter 4
	uint32_t						P5;							//	parameter 5
	uint32_t						P6;							//	parameter 6
}
IO_READ_WRITE_Packet_t;


typedef	volatile	struct	UCB_s
{
	IOPacket_t		*Head;
	IOPacket_t		*Tail;
	void					*HW;
	uint32_t			State;
	IOP_status_t	(*Start)(struct	UCB_s	*UCB);
	IOP_status_t	(*Qualify)(IOPacket_t *packet);

	void					*Private;
}
UCB_t;

typedef	volatile	struct	DCB_s
{
	void				*Device_Specific_struct;
	uint32_t		UCB_Index_Low;
	uint32_t		UCB_Index_High;
	UCB_t				*((*UCB)[]);
}
DCB_t;


extern	DCB_t	*IOM_DCB[IOM_DEV_NUMBER_OF_DEVICE_TYPES];		//	System DCB Table

#if		000

IOP_status_t	IOM(IOPacket_t *packet)	__attribute__ ((section ("ram_code")));		//	I/O Manager entry point, queueu I/O packets here

IOP_status_t	IOM_EnQueue(IOPacket_t	*packet, UCB_t	*UCB)	__attribute__ ((section ("ram_code")));
IOP_status_t	IOM_DeQueue(IOPacket_t	*packet, UCB_t	*UCB)	__attribute__ ((section ("ram_code")));

#else

IOP_status_t	IOM(IOPacket_t *packet);		//	I/O Manager entry point, queue I/O packets here

IOP_status_t	IOM_DeQueue(IOPacket_t	*packet, UCB_t	*UCB);

#endif

typedef	enum	System_Error_e
{
	SYSTEM_WARNING			=	0x0000,		//	Informative Errors, but not critical  (SYSTEM_WARNING < Error_Code < SYSTEM_MINOR_FAULT)
	SYSTEM_MINOR_FAULT	=	0x2000,		//	Minor Faults, we can continue/recover (SYSTEM_MINOR_FAULT < Error_Code < SYSTEM_MAJOR_FAULT)	
	SYSTEM_MAJOR_FAULT	=	0x8000,		//	Informative Errors, but not critical  (SYSTEM_MAJOR_FAULT >= Error_Code)  

	NO_FAULT						=	SYSTEM_WARNING,
	WARNING,

	FIRST_MINOR_FAULT		=	(SYSTEM_MINOR_FAULT + 1),

	MINOR_FAULT_USART_ISR_PARSE_STATE,
	MINOR_FAULT_USART_ISR_IDLE,
	MINOR_FAULT_USART_ISR_LOAD_DMA,


	FIRST_MAJOR_FAULT		=	(SYSTEM_MAJOR_FAULT + 1),

	MAJOR_FAULT_USART_ISR_UNKNOWN_STATE	=	FIRST_MAJOR_FAULT,
	MAJOR_FAULT_USART_ISR_USART_FAULTED,
	MAJOR_FAULT_USART_ISR_USART_CALLBACK,
	MAJOR_FAULT_USART_Start_UNKNOWN_FUNCTION,
	MAJOR_FAULT_USART_Start_USART_FAULTED,
	MAJOR_FAULT_USART_Start_UNKNOWN_STATE

}
System_Error_t;


#if 01
#define	System_Error(Error_Code, Value)
#else
void	System_Error(uint16_t	Error_Code, uint16_t	Value);		//	not a great place, but a place...
#endif


#endif	//	SQ_IOM_H_
