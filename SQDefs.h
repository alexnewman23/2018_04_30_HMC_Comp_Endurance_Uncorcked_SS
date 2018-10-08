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
** SQDefs.h
**
**     System configuration and initialization. 
**
*******************************************************************************
** $Id:$
******************************************************************************/

//*********************************************************************************************
#ifndef	SQDEFS_H_
//*********************************************************************************************
#define SQDEFS_H_
//*********************************************************************************************

//*********************************************************************************************
#if		defined(SCATTER_FILE)
//*********************************************************************************************

//	NOTE:		Must pick one of the following to drive the linker through the scatter file.:	[Need to do this better, ...later...not now.]

#define	STM32F427_437xx (1)		//	For STM32F4xx builds
//#define	STM32F10X_CL			(1)		//	For STM32F10x builds

//*********************************************************************************************
#else	//	defined(SCATTER_FILE)
//*********************************************************************************************

#include	<string.h>

// Firmware uses the type defs in stm32f10x_lib.h - so conditionally 
// include this for now.  Should probably break this out into a 
// SQTypes.h file someday - but those will conflict w/ the typedefs
// in stm32f10x_lib.h... 

#include	<stdint.h>
#include	<stddef.h>

#define	__USE_C99_MATH

#include	<math.h>
#include	<iso646.h>

//This block moved down below HW definition:
// #define	ARM_MATH_CM3	(1)
//
// #include	<arm_math.h>


#include	<stdbool.h>

#define	FALSE	(false)
#define	TRUE	(true)

//#include "SQSysConfig.h"

////#endif		//	not	defined(SCATTER_FILE)

//*********************************************************************************************
//******	Choose Product	*******************************************************************
//*********************************************************************************************

//	NOTE:	Listed in rough chronological development order (for the most part).

//#define	SQ_RPS_0022	(1)		//	Bobcat, Original

//#define	SQ_RPS_0026	(1)		//	Bobcat, Deutsch A keyed
//#define	SQ_RPS_0027	(1)		//	Bobcat, Deutsch B keyed
//#define	SQ_RPS_0028	(1)		//	Bobcat, M12
//#define	SQ_RPS_0031	(1)		//	Bobcat, Deutsch B keyed
//#define	SQ_GIX_200	(1)		//	SQ_GIX_200	Be sure to pick the right HW platform below. Pick one of: MA_0069_HW, MA_0070_HW or MA_0071_HW.
//#define	SQ_RPS_0032	(1)		//	Rust Sales (Bobcat like), Deutsch B keyed
//#define	SQ_GIX_0206	(1)		//	Whiterock 
//#define	SQ_GIX_0102	(1)		//	GIX based Bobcat, Deutsch A keyed
//#define	SQ_GIX_0103	(1)		//	GIX based Bobcat, Deutsch B keyed
//#define	SQ_GIX_0104	(1)		//	GIX based Bobcat, M12
//#define	SQ_GIX_0207	(1)		//	GIX based Bobcat, Deutsch B keyed
//#define	SQ_GIX_0208	(1)		//	Piraeus (spel?), Deutsch B keyed
//#define	SQ_GIX_0210	(1)		//	Excavating Solutions:	Bucket
//#define	SQ_GIX_0211	(1)		//	Excavating Solutions:	Dipper Stick
//#define	SQ_GIX_0212	(1)		//	Excavating Solutions:	Main Boom
//#define	SQ_GIX_0213	(1)		//	Excavating Solutions:	Third Boom
//#define	SQ_GIX_0214	(1)		//	Excavating Solutions:	Chassis
//#define	SQ_GIX_0221	(1)		//	Actronics
//#define	SQ_RPS_0034	(1)		//	Bobcat Bucket Sensor [non-GIX on GIX HW platform]
//#define	SQ_GIX_0107	(1)		//	GIX, M12 version of 0103(?)
//#define	SQ_GIX_0222	(1)		//	GIX, M12 version with Accel, of M12 version of SQ_GIX_0207(?), different CAN address
//#define	SQ_GIX_0223	(1)		//	GIX, M12 version, 18g
//#define	SQ_GIX_0220	(1)		//	GIX, M12 version, of M12 version of SQ_GIX_0207(?), GKD proprietary CAN protocol
//#define	SQ_GIX_0108	(1)		//	GIX, M12 version, of M12 version of SQ_GIX_0207(?), GKD proprietary CAN protocol, Single axis
//#define	SQ_GIX_0109	(1)		//	GIX, M12 version, of M12 version of SQ_GIX_0207(?), GKD proprietary CAN protocol, Single axis
//#define	SQ_GIX_0224	(1)		//	GIX, M12 version, Heave calculation
//#define	SQ_GIX_0225	(1)		//	GIX, M12 version, same as SQ_GIX_0210, except standard M12 pinout, and no CAN terminator, and SQ standard Orientation
//#define	SQ_RPS_0038	(1)		//	Non-GIX, 5g, Deutsch version, no CAN terminator, and SQ standard Orientation
//#define	SQ_GIX_0226	(1)		//	GIX, M12 version, same as SQ_GIX_0210, standard M12 pinout, and CAN terminator, and SQ standard Orientation
//#define	SQ_GIX_0021	(1)		//	LOCK CODE - GIX, ported to ION platform
//#define	SQ_RPS_0035	(1)		//	Based on SQ_RPS_0034, Bobcat Bucket Sensor [non-GIX on GIX HW platform], Address 0xA2 and without CAN Termination
//#define	SQ_RPS_0036	(1)		//	Based on SQ_RPS_0034, Bobcat Bucket Sensor [non-GIX on GIX HW platform], Address 0xA1 and without CAN Termination
//#define	SQ_GIX_0229	(1)		//	Based on SQ_GIX_0226, Dual axis, M12, no termination, connector down.
//#define	SQ_GIX_0230	(1)		//	LOCK CODE - Based on SQ-GIX-0229, Dual axis, M12, no termination, connector up,
//#define	GIX_THERMAL_TESTING	(1)		// based on SQ_RPS_0035
//#define	SQ_GIX_0022	(1)		//	LOCK CODE - GIX, ported to ION platform, based on SQ_GIX_0021, for BAE evaluation, has SI-SI2X-360DA like Serial protocol in addition to CAN.
//#define	SQ_GIX_0232	(1)		//	LOCK CODE - Based on SQ_GIX_0230, Dual axis, M12, no termination, connector up, for BAE evaluation,
//#define	SQ_GIX_0209	(1)		//	LOCK CODE - based on SQ_GIX_0210, standard M12 pinout, TRADE_SHOW_MESSAGES
//#define	SQ_GIX_0234	(1)		//	based on SQ_RPS_0034, standard M12, no CAN Terminator, Bobcat MX House Sensor 
//#define	SQ_GIX_0110	(1)		//	based on SQ_GIX_0229, standard M12, CAN Terminator, Bobcat MX Bucket Sensor 
//#define	SQ_GIX_0111	(1)		//	based on SQ_GIX_0229, standard M12, no CAN Terminator, Bobcat MX Arm Sensor 
//#define	SQ_GIX_0112	(1)		//	based on SQ_GIX_0229, standard M12, no CAN Terminator, Bobcat MX Boom Sensor 
//#define	SQ_GIX_0113	(1)		//	based on SQ_GIX_0229, standard M12, CAN Terminator, Bobcat LDR Bucket Sensor 
//#define	SQ_GIX_0114	(1)		//	based on SQ_GIX_0229, standard M12, no CAN Terminator, Bobcat LDR Arm Sensor 
//#define	SQ_GIX_0215	(1)		//	based on	SQ_GIX_0211,	Excavating Solutions:	Dipper Stick, non-standard Dual M12 pinout
//#define	SQ_GIX_0216	(1)		//	based on	SQ_GIX_0212,	Excavating Solutions:	Main Boom, non-standard Dual M12 pinout, Dual M12
//#define	SQ_GIX_0218	(1)		//	based on	SQ_GIX_0214,	Excavating Solutions:	Chassis, non-standard Dual M12 pinout
//#define	SQ_JSN_0111	(1)		//	based on	SQ_GIX_0111, for Magnetometer testing
//#define	SQ_JSN_0112	(1)		//	based on	SQ_GIX_0112, for Magnetometer testing
//#define	SQ_JSN_0234	(1)		//	based on 	SQ_GIX_0234, standard M12, CAN Terminator, Bobcat MX House Sensor 
//#define	SQ_GIX_0238	(1)		//	based on SQ_GIX_0210
//#define	SQ_RPS_0052	(1)		//	Based on SQ_RPS_0035, [non-GIX on GIX HW platform], Address 0xA2 and without CAN Termination
//#define	SQ_RPS_0053	(1)		//	Based on SQ_RPS_0052, [non-GIX on GIX HW platform], Address 0xA1 and without CAN Termination
//#define	SQ_GIX_0200	(1)		//	Not to be confused with: SQ_GIX_200 !, 	Be sure to pick the right HW platform below. Pick one of: MA_0069_HW, MA_0070_HW or MA_0071_HW.
//#define	SPI_GYRO_TEST	(1)		//	based on SQ_GIX_0210 & SQ_GIX_0022, but SQ Orientation #0, standard pinout, low cost SPI_GYRO code from ION
//#define	SQ_JSN_0113	(1)		//	based on	SQ_GIX_0111, for Magnetometer testing, Bucket with SPI GYRO
//#define	SQ_GIX_0241	(1)		//	LOCK CODE - Based on SQ_GIX_0200, Dual axis, Deutsch, no termination, for Danfoss evaluation,
//#define	SQ_CST_0331	(1)		//	Based on SQ_RPS_0034, Dual axis, originally MA-0127 HW, now MA-0134, no CAN termination, initially for AVL
//#define	SQ_MAG_0001		(1)		//	based on SQ_GIX_0234, CAN Terminator, Magnetometer code
//#define	SQ_GIX_0243	(1)		//	Based on SQ_GIX_0210, Dual axis, no CAN termination, CANopen 'Lite' protocol
//#define SQ_GIX_0287 (1)   // Based on SQ_GIX_0243.  Add configurable CAN bit rate.
/////#define	ENABLE_SPI_GYRO		(1)		//	L3GD20 or L3GD20H
//#define	SQ_GIX_0246	(1)		//	was:SQ_GIX_0220, now with GKD M12 pinout, M12 version of SQ_GIX_0207(?), GKD proprietary CAN protocol
//#define	SQ_GIX_0219	(1)		//	[LOCK CODE?] - North Point Gyro R&D unit
//#define	SQ_CST_0342	(1)		//	[LOCK CODE?] - New Trimble SPI Gyro
//#define	SQ_CST_0343	(1)		//	[LOCK CODE?] - New Trimble Analog (PP) Gyro
//#define	SQ_CST_0325	(1)		//	Based on SQ_CST_0331, which is based on SQ_RPS_0034, Dual axis, MA-0127 HW, no CAN termination, initially for AVL
//#define	SQ_RPS_0054	(1)		//	Based on SPI_GYRO_TEST, IMU, non GIX, SPI GYRO, 3 axis, inclinometer, accelerometer, gyro outputs, GIX HW, no CAN termination, initially for Pi-Innovo
//#define	SQ_GIX_0118	(1)		//	based on SQ_GIX_0110, but with address 06 and PGN 65286
//#define SQ_GIX_0119 (1)   //  based on SQ_GIX_0110, but with address 12 and PGN 65282
//#define	SQ_GIX_0120	(1)		//	based on SQ_GIX_0118, but 18g part (AD22037Z) and 6m radius
//#define	SQ_GIX_0121	(1)		//	based on SQ_GIX_0119, but 18g part (AD22037Z) and 6m radius
//#define SQ_GIX_0236 (1)   //  based on SQ_GIX_0210, Adds J1939 'Lite, adjustable SA, (non-J1939 standard, and changable orientation)
//#define SQ_GIX_0249 (1)   //  based on SQ_GIX_0236, Adds Full J1939, not 'Lite; NOT:first up is to add SQ_CAN driver (required) from Clever/FDOT.
//#define SQ_CST_0340 (1)     //  based on SQ_GIX_0210, enables both Analog and SPI_GYRO, puts SPI Gyro data into MAG for recording in oven and during test.
//#define SQ_GIX_0269 (1)       //  based on SQ_GIX_0200, with CAN baud rate of 125kbps
//#define SQ_GIX_0271 (1)     //  based on SQ_GIX_0236, Part number change only.
//#define SQ_GIX_0274 (1)     //  based on SQ_GIX_0200, Part number change only.

//#define	SQ_RPS_0058	(1)		//	Based on SQ_RPS_0052, which is based on SQ_RPS_0035, [non-GIX on GIX HW platform], Address 0xA2 and without CAN Termination
//#define	SQ_RPS_0059	(1)		//	Based on SQ_RPS_0053, which is based on SQ_RPS_0052, [non-GIX on GIX HW platform], Address 0xA1 and without CAN Termination
//#define	SQ_GIX_0289	(1)		//	Based on SQ_GIX_0270 (original Pfreund) and SQ_GIX_0261 (ported to MA_0219 [F103] platform
//#define SQ_GIX_0272_F105 (1)  // Based on SQ_GIX_0272 (original JCB) and SQ_GIX_0289 (ported to MA_0219 [F105] platform)

#if		000	//	???Better conditionalization???
	//===========================================================================================================================================
#define	SQ_GIX_0255	(1)		//Remember to increment FWBUILD		//	Based on SQ_CST_0343 and SQ_GIX_0249, and without CAN Termination
//	NOTE: SQ_GIX_0255 builds on either the MA_0192_105_TEST (aka MA_0219) or the MA_0166 HW platforms.  
//	NOTE: MA_0219 should ulitmately replace  MA_0192_105_TEST, deprecate MA_0192_105_TEST.
//	NOTE: The following is defined twice (again below) to deal with some precedence nonsense:	
//	We must pick a HW platform here for SQ-GIX-0255 since (at present) it builds on multiple HW platforms, (which will eventually be resolved).
//	#define	MA_0192_105_TEST		(1)	//	Uses MC-1201, aka MA_0219, new GEN III PCB Assembly, BUT WITH A STM32F105 instead of an STM32F446 
//#define	MA_0219	(1)	//	GEN III but with a STM32F105 instead of a STM32F446

//////Pick one of the following:  [Yes, this is a mess and it will be fixed up, but I was forced to merge in the middle of another merge.]
//#define	SQ_GIX_0286	(1)		//Note: Currently need SQ_GIX_0255 block enabled above.  Resolve another day. 	//needs completion	//	Trimble F105 build, based on SQ_GIX_0255 with MA_0219
//#define	MA_0192		(1)	//	Uses MC-1201, new GIX III PCB Assembly, STM32F446 
#define	SQ_GIX_0302	(1)		//Note: Currently need SQ_GIX_0255 block enabled above.  Resolve another day. 	//	based on SQ_GIX_0255	specifically 20160325_C_JLM	//Remember to increment FWBUILD		//	Based on SQ_CST_0343 and SQ_GIX_0249, and without CAN Termination
	//===========================================================================================================================================
#endif

//#define	SQ_GIX_0286	(1)		//	Trimble F105 build, based on SQ_GIX_0255 with MA_0219

//#define	SQ_GIX_0298	(1)		//	Based on SQ_GIX_0255 (MA_0219 [F103] HW platform)

//#define	SQ_GIX_0272	(1)		//	[LOCK CODE?] - based on SQ_CST_0343
//#define	SQ_GIX_0270	(1)		//	[LOCK CODE?] - based on SQ_GIX_0272
//#define	SQ_GIX_0273	(1)		//	[LOCK CODE?] - based on SQ_GIX_0236

//#define	SQ_RPS_0061	(1)		//	[LOCK CODE?] - based on SQ_RPS_0054 and SQ_GIX_0273

//#define	SQ_GIX_0290	(1)		//	Based on SQ-GIX-0114, but running on Gen III. ALSO SEARCH FOR SQ_GIX_0290_to_7 !!!
//#define SQ_GIX_0291 (1)   //	Based on SQ-GIX-0290. ALSO SEARCH FOR SQ_GIX_0290_to_7 !!!
//#define SQ_GIX_0292 (1)   //	Based on SQ-GIX-0290. ALSO SEARCH FOR SQ_GIX_0290_to_7 !!!
//#define SQ_GIX_0293 (1)   //	Based on SQ-GIX-0290. ALSO SEARCH FOR SQ_GIX_0290_to_7 !!!
//#define SQ_GIX_0294 (1)   //	Based on SQ-GIX-0290. ALSO SEARCH FOR SQ_GIX_0290_to_7 !!!
//#define SQ_GIX_0295 (1)   //	Based on SQ-GIX-0290. ALSO SEARCH FOR SQ_GIX_0290_to_7 !!!
//#define SQ_GIX_0296 (1)   //	Based on SQ-GIX-0290. ALSO SEARCH FOR SQ_GIX_0290_to_7 !!!
//#define SQ_GIX_0297 (1)   //	Based on SQ-GIX-0290. ALSO SEARCH FOR SQ_GIX_0290_to_7 !!!

//#define	SQ_RPS_0063	(1)		//	Based on SQ-RPS-0032, Rust Sales
//#define SQ_GIX_0299 (1)   //	Based on SQ-GIX-0270, but also like SQ-GIX-0287 = configurable rate 125,250,500,1000, no TPDO2

//#define	SQ_GIX_2001	(1)		//	Based on SQ_GIX_0270 (for HW) SQ_GIX_0289 (for SW) (original Pfreundt) upgrade to full CANopen stack
//#define	SQ_GIX_2003	(1)		//	Based on SQ_GIX_0298, Except RS-485 with MODBUS protocol (instead of RS-232 with a custom protocol)
//#define	SQ_GIX_2002	(1)		//	Based on SQ_GIX_2001, for Pfreundt, full CANopen stack
//#define	SQ_GIX_2004	(1)		//	Based on SQ_GIX_2001, for Pfreundt, full CANopen stack
//#define	SQ_GIX_2005	(1)		//	Based on SQ_GIX_2001, for Pfreundt, full CANopen stack
//#define SQ_GIX_2010 (1)   //	Based on SQ_GIX_0110, but Gen3 F446 platform, GIX300 algorithm, and linearization
//#define SQ_GIX_2011 (1)   //	Based on SQ_GIX_0110, but Gen3 F446 platform, GIX300 algorithm, and linearization
//#define SQ_GIX_2012 (1)   //	Based on SQ_GIX_0110, but Gen3 F446 platform, GIX300 algorithm, and linearization
//#define SQ_GIX_2013 (1)   //	Based on SQ_GIX_0110, but Gen3 F446 platform, GIX300 algorithm, and linearization
//#define SQ_GIX_2015 (1)   //	Based on SQ_GIX_2013, Gen3 F446 platform, GIX?00 algorithm, and linearization
//#define	SQ_GIX_2014	(1)		//	Based on SQ_GIX_2002, for Edge Automation, full CANopen stack
//#define	SQ_GIX_0303	(1)		//	Based on SQ_GIX_2014, for Walvoil, full CANopen stack
//#define	SQ_GIX_2017	(1)		//	Based on SQ_GIX_0303, for VEI, fuller CANopen stack (but not all the way to fullest yet).
//#define	SQ_RPS_0064	(1)		//	based on SQ-RPS-0063, Rust Sales, but resolution is 0.01deg, and a message is provided to identify this unit
//#define SQ_RPS_0065 (1)   //  based on SQ-RPS-0063, but uses 18g accelerometers, and uses the A2 TB slot Z-axis.  Transmits accelerometer messages only.

//#define	SQ_GIX_2020	(1)		//	Based on SQ_GIX_0286, for Trimble F446 build with GIX-309, Gyro fixes, enhanced status, BACKUP_CD, etc., based on SQ_GIX_0255
//#define	SQ_GIX_2022	(1)		//	Based on SQ_GIX_2002, but analog output.  Using this build because it doesn't transmit (except CANopen) in customer mode.
//#define	SQ_GIX_2026	(1)		//	Based on SQ_GIX_2003, but uses GIX300 algorithm.
//#define	SQ_GIX_2019	(1)		//	Based on SQ_GIX_2021, for Hylion, F446 build 
//#define	SQ_GIX_2027	(1)		//	Based on SQ_GIX_2019, for Darrigo, F446 build 
//#define	SQ_GIX_2023	(1)		//	Based on SQ_GIX_0298 (Fugro) RS-232 serial output, but uses FEFE protocol.  Also mainloop must run at 500Hz.
#define	SQ_GIX_2024	(1)		//	Based on SQ_GIX_2020, for Tigercat F446 build with GIX-309, Gyro fixes, enhanced status, BACKUP_CD, etc.

////DEBUG:
////#define	DISABLE_I2C	(1)
////#define	FORCE_TEST_MODE	(1)

//************ PRE POT BUILD *****************************************************************
//#define	PREPOT_VERSION	(1)	//	Used if we need a different Baud Rate, etc. for Prepot and Temp Comp to generate a 'PrePot' version of the FW.
//************ PRE POT BUILD *****************************************************************
//#define FORCE_VIN_GOOD (1) // PBT POWER TESTING

//**************************************************************************************************************
//	Enable Code Protection:	Build an image that explicitly Enables Code Protection  (RDP aka Read Data Protection)
//**************************************************************************************************************
//	NOTE:  Normally choose one or the other of these, ENABLE_CODE_PROTECTION_COMMAND is preferred.
//#define	ENABLE_CODE_PROTECTION	(1)
//Not here: Do on a build by build basis...	#define ENABLE_CODE_PROTECTION_COMMAND  (1)
#define CODE_PROTECTION_COMMAND_IN_TEST_MODE (1)  // Also set this to enable a standard command in test mode to lock code.  This should be used on all future builds.
//**************************************************************************************************************

//**************************************************************************************************************
//	Disable Code Protection:	Build Boot loadable image that explicitly Disables Code Protection
//**************************************************************************************************************
//	NOTE:	DON'T DO THIS ON A POTTED UNIT: It wipes the Boot Loader and everything else.
//**************************************************************************************************************
//#define	DISABLE_CODE_PROTECTION	(1)
//**************************************************************************************************************

//============================
#if 	defined(SQ_GIX_0274)
//============================
//#define	STM32F10X_CL 	(1)

/***
   THIS SECTION COPIED FROM SQ_GIX_2019 
***/

//#define ENABLE_CODE_PROTECTION_COMMAND  (1)

//#define	FORCE_FOR_CCT_TESTING	(1)
//obsolete:	#define	ENABLE_SOME_WRITES_TO_CANOPEN_COD	(1)
//obsolete:	#define	ENABLE_CANOPEN_STORE_PARAMETERS	(1)

#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

//////////////////////////////////////////////////////
//	ADC options for '446 ADC Linearization
//////////////////////////////////////////////////////
//#define PBT_LINEARIZATION_TYPE	(6)

//	float const ADC_linearization_table[1024];
//#define	lin_table	CD.ADC_linearization_table

//#define	GROUNDED_ADC_CHANNEL	(1)
//#define	SKIP_ADC_CHANNELS	(1)
//#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...
//////////////////////////////////////////////////////

//#define	ENHANCED_STATUS_BITS	(1)
//#define	ENABLE_DTC_FAULTS	(1)
//#define	ENABLE_DTC_FAULT_VECTOR_MESSAGE	(1)


#define	ZRU_ALG_3	(1)		//	Does this apply if we're running a GIX 300 algo?

#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)		//	Does this apply if we're running a GIX 300 algo?

//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
//#define	FORCE_DIGITAL_GYRO		(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO

//	Valid Combinations for GIX-300 and GIX-200
//																										[DEPTH of]			[1/MAINLOOP_RATE]
//	GIX_300	GIX_300_AT_250_HZ	DUAL_GIX	ISR (Hz)	&Buffer_Accel_5KHz	TS_Period (uSec)	ADC_SAMPLES_PER_CHANNEL
//	=======	=================	========	========	==================	================	=======================
//		0							0							0			2.5 KHz					N/A							4000										10							
//
//		0							0							1				N/A						N/A							N/A											N/A   					
//		0							1							0				N/A						N/A							N/A											N/A   					
//		0							1							1				N/A						N/A							N/A											N/A   
//
//		1							0							0			5.0 KHz					10							2000										10							
//		1							0							1			5.0 KHz					10							2000										10							
//		1							1							0			5.0 KHz					20							4000										20							
//		1							1							1			5.0 KHz					20							4000										20							
//

//////////////////////////////////////////////////////
//	GIX 309 options
//////////////////////////////////////////////////////
//#define	GIX_300		(1)

	#if		defined(GIX_300)
#define	GIX_300_AT_250_HZ	(1)
//#define	DUAL_GIX	(1)
	#endif

//#define	NO_A2_TB	(1)
//#define	BIAS_WALK_LIMIT_DUAL	(1)

//#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT

//#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp
//#define	LSM6DS3	(1)
//#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

//#define	ENABLE_SPI_GYRO	(1)
//#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
//#define ENABLE_SPI_GYRO_TEMP_COMP (1) // Needed to make CD sturcuture the proper size, so that linearization is at 0x14E8.

//#define	ENABLE_SPI_MAG	(1)		
//#define	NO_MAGS	(1)

//#define		GIX300		(1)
//#define		F4_BUILD	(1)




//============================
#elif	defined(SQ_RPS_0065)
//============================
/* Use A2 slot */
//#define	USE_A1_TB_Z_AXIS	(1)		//	Force us to use A1 TB slot for LOG Accel Z Axis, default is to use A2 slot.
#else
#define	USE_A1_TB_Z_AXIS	(1)		//	Force us to use A1 TB slot for LOG Accel Z Axis, default is to use A2 slot.
#endif

#define	NO_TRIMBLE_MASTER_SYNC	(1)
//#define	NO_TRIMBLE_TIME_UPDATE	(1)
//#define	NO_T4_UPDATE						(1)

#define	NO_SPI_GYRO_COMP	(1)		//	Disable SPI GYRO Comp Filter.
//#define	SPI_GYRO_20HZ			(1)		//	Force 20 Hz instead of 50 hz for SPI Gyro Comp. Filter.
//#define	DISABLE_CAN	(1)
//#define	ENABLE_I2C3	(1)
//#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
//#define	ENABLE_PIX_USART	(1)		//	Do not define for MODBUS_STACK???
//#define	FORCE_TEST_MODE	(1)

//F4 BUILD: THIS IS BROKEN: chase later...#define	ADC_USE_STREAM4	(1)


//#define	ACCEL_CAL_II	(1)		//	Newer cal. algo.: full 3x3		//DON'T USE

#if		001		//	relocated here
/* Useful.. */

//	From:	http://en.wikipedia.org/wiki/Gravity_of_Earth
//
//	"...Apparent gravity on the earth's surface varies by around 0.7%, 
//	from 9.7639 m/s2 on the Nevado Huascarán mountain in Peru to 
//	9.8337 m/s2 at the surface of the Arctic Ocean.[4] In large cities, 
//	it ranges from 9.766 in Kuala Lumpur, Mexico City, and Singapore 
//	to 9.825 in Oslo..."

#define GRAVITY         (9.80665f) //(9.8f) /* m/s^2 */
#endif

//============================
#if		defined(SQ_GIX_2022)
//============================
// DON'T EVER USE THIS SYMBOL AGAIN!!!  //#define ENABLE_IO_EXPANDER (1)
#define ENABLE_PIX_DAC    (1)
#define ENABLE_I2C3       (1)

#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

//////////////////////////////////////////////////////
//	ADC options for '446 ADC Linearization
//////////////////////////////////////////////////////
#define PBT_LINEARIZATION_TYPE	(6)

//	float const ADC_linearization_table[1024];
#define	lin_table	CD.ADC_linearization_table

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...
//////////////////////////////////////////////////////

//#define	ENHANCED_STATUS_BITS	(1)
//#define	ENABLE_DTC_FAULTS	(1)
//#define	ENABLE_DTC_FAULT_VECTOR_MESSAGE	(1)


#define	ZRU_ALG_3	(1)

#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)
//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
#define	FORCE_DIGITAL_GYRO		(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO

//	Valid Combinations for GIX-300 and GIX-200
//																										[DEPTH of]			[1/MAINLOOP_RATE]
//	GIX_300	GIX_300_AT_250_HZ	DUAL_GIX	ISR (Hz)	&Buffer_Accel_5KHz	TS_Period (uSec)	ADC_SAMPLES_PER_CHANNEL
//	=======	=================	========	========	==================	================	=======================
//		0							0							0			2.5 KHz					N/A							4000										10							
//
//		0							0							1				N/A						N/A							N/A											N/A   					
//		0							1							0				N/A						N/A							N/A											N/A   					
//		0							1							1				N/A						N/A							N/A											N/A   
//
//		1							0							0			5.0 KHz					10							2000										10							
//		1							0							1			5.0 KHz					10							2000										10							
//		1							1							0			5.0 KHz					20							4000										20							
//		1							1							1			5.0 KHz					20							4000										20							
//

//////////////////////////////////////////////////////
//	GIX 309 options
//////////////////////////////////////////////////////
#define	GIX_300		(1)

	#if		defined(GIX_300)
#define	GIX_300_AT_250_HZ	(1)
//#define	DUAL_GIX	(1)
	#endif

#define	NO_A2_TB	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT

#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp
#define	LSM6DS3	(1)
#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	ENABLE_SPI_GYRO	(1)
//#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define ENABLE_SPI_GYRO_TEMP_COMP (1) // Needed to make CD sturcuture the proper size, so that linearization is at 0x14E8.

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)

//#define		GIX300		(1)
#define		F4_BUILD	(1)


//============================
#elif	(defined(SQ_GIX_0290) or  defined(SQ_GIX_0291) or  defined(SQ_GIX_0292) or  defined(SQ_GIX_0293)  or  defined(SQ_GIX_0294)  or  defined(SQ_GIX_0295)  or  defined(SQ_GIX_0296)  or  defined(SQ_GIX_0297)  )
//============================

//#define	ENABLE_MSGID_7_TEST_MESSAGE	(1)		//	Used to generate GIX Angle message on MSGID_7 for comparison testing to Interpolated message on MSGID_3.

// This symbol represents the eight Bobcat builds SQ_GIX_0290 through SQ_GIX_0297
#define SQ_GIX_0290_to_7  (1) // Used for: SQ_GIX_0290 SQ_GIX_0291 SQ_GIX_0292 SQ_GIX_0293 SQ_GIX_0294 SQ_GIX_0295 SQ_GIX_0296 SQ_GIX_0297

#define	ENABLE_CAN_INTERRUPT_FOR_OLD_DRIVER	(1)		//	ENABLE for faster CAN TX messaging.

//#define	GIX_300_STATUS_MESSAGE	(1)	//	Generate MSGID_DB_1  Diagnostic message @ ~1 Hz  [64 bit Error bit Vector]

//#define	DEBUG_AT_5K	(1)
//#define	TRIPLE_FP_MESSAGES	(1)	//	not TRIMBLE here!!!

//////////////////////////////////////////////////////
//	ADC options for '446 ADC Linearization
//////////////////////////////////////////////////////
#define PBT_LINEARIZATION_TYPE	(6)

//	float const ADC_linearization_table[1024];
#define	lin_table	CD.ADC_linearization_table

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...
//////////////////////////////////////////////////////

//#define	GIX_300		(1)

#if		defined(GIX_300)
//#define	DUAL_GIX	(1)
#define	GIX_300_AT_250_HZ	(1)
#endif

//#if		not	defined(RUN_446_AT_72_MHZ)
//	ERROR!!!	"RUN_446_AT_72_MHZ" must be defined in the PreProcessor Symbols int the C/C++ Options Menu !!!
//#define	RUN_446_AT_72_MHZ	(1)	//	!!! MAKE SURE THIS IS PREDEFINED !!! [Should get macro redefined error here if it is.]
//#endif

#define	ZRU_ALG_3	(1)

#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)
#define	TRIMBLE_MESSAGE_SENT_DETECTION	(1)

//#define	FORCE_DIGITAL_GYRO	(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO
//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
//#define	NO_ANALOG_GYROS	(1)
#define	NO_A2_TB	(1)

//#define	DEFEAT_GIX_BIAS_TRIM	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)

//#define	FASTER_SPI	(1)
////use dual scheme	#define	BIAS_WALK_LIMIT		(15.0)	/* deg/sec */

//#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

#define	DEFEAT_TRIMBLE_SAMPLING_WARP	(1)
//#define SCAN_TEST	(1)
//#define	FORCE_R11	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)

//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp
//#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	ENABLE_SPI_GYRO	(1)   

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)
#define	NO_MAGS	(1)

#define		F4_BUILD	(1)
//============================
#elif		defined(SQ_GIX_0302)	//from:		(not	defined(SQ_GIX_0286))	and	defined(SQ_GIX_0255)
//============================

//#if		not	defined(RUN_446_AT_72_MHZ)
//	ERROR!!!	"RUN_446_AT_72_MHZ" must be defined in the PreProcessor Symbols int the C/C++ Options Menu !!!
//#define	RUN_446_AT_72_MHZ	(1)	//	!!! MAKE SURE THIS IS PREDEFINED !!! [Should get macro redefined error here if it is.]
//#endif

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...

///////////////////////////////////////////////////////////////////////////////////////////////////////
	#if		0001
///////////////////////////////////////////////////////////////////////////////////////////////////////

//#define	ZRU_ALG_4	(1)
#define	ZRU_ALG_3	(1)
//#define	OLD_ZRU_TEST	(1)		//Debug comparison testing only
#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)
#define	TRIMBLE_MESSAGE_SENT_DETECTION	(1)

//#define	FORCE_DIGITAL_GYRO	(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO
//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
//#define	NO_ANALOG_GYROS	(1)
#define	NO_A2_TB	(1)

//#define	TRIMBLE_DO_NOT_REQUIRE_TIME_SYNC_MASTER	(1)
//#define	ENABLE_TRIMBLE_MSGID_D	(1)

//#define	DEFEAT_GIX_BIAS_TRIM	(1)

#define	TRIMBLE_ODR_MESSAGE_INTERLOCK	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)

//#define	FASTER_SPI	(1)
////use dual scheme	#define	BIAS_WALK_LIMIT		(15.0)	/* deg/sec */
//#define	TRIMBLE_BREAK_J1939_MESSAGE_LENGTH	(1)		//	REMOVE THIS FEATURE

//#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

#define	DEFEAT_TRIMBLE_SAMPLING_WARP	(1)
//#define SCAN_TEST	(1)
//#define	FORCE_R11	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	HALT_TEST	(1)

		#if		000	//	SPI GYRO TEST code
//#define	TRIMBLE_DO_NOT_REQUIRE_TIME_SYNC_MASTER	(1)
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
//#define	TRIMBLE_TRIPLE_FP_MESSAGES	(1)		//	mutually exclusive against JLM_GYRO_TEST_2
#define	JLM_GYRO_TEST_2	(1)									//	mutually exclusive against TRIMBLE_TRIPLE_FP_MESSAGES
	#else
		#if		001		//DEBUG and FP messages
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	DEFEAT_TRIMBLE_FREQUENCY_LOCK	(1)		//	redundant with IGNORE_TRIMBLE_TIME_SYNC ???
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_DEBUG	(1)	//Bias and 'R' messages
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
#define	TRIMBLE_TRIPLE_FP_MESSAGES	(1)
		#else
			#if		00		//	test only, don't ship	//	Test code for Variance
#define	DEBUG_ONLINE_VARIANCE	(1)		//	Do not ship with this on.
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
			#else
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
			#endif
		#endif
	#endif
//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

#define	ENABLE_SPI_GYRO	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)
#define	NO_MAGS	(1)
//#define		GIX300		(1)	//	Older GIX300, deprecated
#define		F4_BUILD	(1)

///////////////////////////////////////////////////////////////////////////////////////////////////////
#else	//	0001
///////////////////////////////////////////////////////////////////////////////////////////////////////

//#define SCAN_TEST	(1)
//#define	FORCE_R11	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)
#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	HALT_TEST	(1)

	#if		0001		//DEBUG and FP messages
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	DEFEAT_TRIMBLE_FREQUENCY_LOCK	(1)		//	redundant with IGNORE_TRIMBLE_TIME_SYNC ???
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)
#define	TRIMBLE_DEBUG	(1)	//Bias and 'R' messages
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
#define	TRIMBLE_TRIPLE_FP_MESSAGES	(1)
	#else
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
	#endif

//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

#define	ENABLE_SPI_GYRO	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)
//#define		GIX300		(1)		//	Older GIX300, deprecated
#define		F4_BUILD	(1)
///////////////////////////////////////////////////////////////////////////////
#endif	//	0001
///////////////////////////////////////////////////////////////////////////////

//============================
#elif		(defined(SQ_GIX_2021)	or  defined(SQ_GIX_2019)	or	defined(SQ_GIX_2027)	)
//============================
//CANOPEN_STACK no longer needed(?) [CANOPEN_STACK should be defined in 'C' options? (or not...)]:	//defined in 'C' options for compiler command line: #define	CANOPEN_STACK	(1)
#define	CANOPEN_STACK	(1)

#define ENABLE_CODE_PROTECTION_COMMAND  (1)

//#define	FORCE_FOR_CCT_TESTING	(1)
//obsolete:	#define	ENABLE_SOME_WRITES_TO_CANOPEN_COD	(1)
//obsolete:	#define	ENABLE_CANOPEN_STORE_PARAMETERS	(1)

#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

//////////////////////////////////////////////////////
//	ADC options for '446 ADC Linearization
//////////////////////////////////////////////////////
#define PBT_LINEARIZATION_TYPE	(6)

//	float const ADC_linearization_table[1024];
#define	lin_table	CD.ADC_linearization_table

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...
//////////////////////////////////////////////////////

#define	ENHANCED_STATUS_BITS	(1)
#define	ENABLE_DTC_FAULTS	(1)
//#define	ENABLE_DTC_FAULT_VECTOR_MESSAGE	(1)


#define	ZRU_ALG_3	(1)		//	Does this apply if we're running a GIX 300 algo?

#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)		//	Does this apply if we're running a GIX 300 algo?

//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
#define	FORCE_DIGITAL_GYRO		(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO

//	Valid Combinations for GIX-300 and GIX-200
//																										[DEPTH of]			[1/MAINLOOP_RATE]
//	GIX_300	GIX_300_AT_250_HZ	DUAL_GIX	ISR (Hz)	&Buffer_Accel_5KHz	TS_Period (uSec)	ADC_SAMPLES_PER_CHANNEL
//	=======	=================	========	========	==================	================	=======================
//		0							0							0			2.5 KHz					N/A							4000										10							
//
//		0							0							1				N/A						N/A							N/A											N/A   					
//		0							1							0				N/A						N/A							N/A											N/A   					
//		0							1							1				N/A						N/A							N/A											N/A   
//
//		1							0							0			5.0 KHz					10							2000										10							
//		1							0							1			5.0 KHz					10							2000										10							
//		1							1							0			5.0 KHz					20							4000										20							
//		1							1							1			5.0 KHz					20							4000										20							
//

//////////////////////////////////////////////////////
//	GIX 309 options
//////////////////////////////////////////////////////
#define	GIX_300		(1)

	#if		defined(GIX_300)
#define	GIX_300_AT_250_HZ	(1)
//#define	DUAL_GIX	(1)
	#endif

#define	NO_A2_TB	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT

#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp
#define	LSM6DS3	(1)
#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	ENABLE_SPI_GYRO	(1)
//#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define ENABLE_SPI_GYRO_TEMP_COMP (1) // Needed to make CD sturcuture the proper size, so that linearization is at 0x14E8.

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)

//#define		GIX300		(1)
#define		F4_BUILD	(1)

//============================
#elif		(defined(SQ_GIX_2002)	or	defined(SQ_GIX_2004)	or	defined(SQ_GIX_2005)  or  defined(SQ_GIX_2014)  or  defined(SQ_GIX_0303)  or  defined(SQ_GIX_2017)	)	//	needs update for newest stuff from '-0255,e tc.
//============================
//No longer needed:	//defined in 'C' options for compiler command line: #define	CANOPEN_STACK	(1)
#define	CANOPEN_STACK	(1)

#define ENABLE_CODE_PROTECTION_COMMAND  (1)

//#define	FORCE_FOR_CCT_TESTING	(1)
#define	ENABLE_SOME_WRITES_TO_CANOPEN_COD	(1)
#define	ENABLE_CANOPEN_STORE_PARAMETERS	(1)

#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

//////////////////////////////////////////////////////
//	ADC options for '446 ADC Linearization
//////////////////////////////////////////////////////
#define PBT_LINEARIZATION_TYPE	(6)

//	float const ADC_linearization_table[1024];
#define	lin_table	CD.ADC_linearization_table

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...
//////////////////////////////////////////////////////

#define	ENHANCED_STATUS_BITS	(1)
#define	ENABLE_DTC_FAULTS	(1)
//#define	ENABLE_DTC_FAULT_VECTOR_MESSAGE	(1)


#define	ZRU_ALG_3	(1)

#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)
//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
#define	FORCE_DIGITAL_GYRO		(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO

//	Valid Combinations for GIX-300 and GIX-200
//																										[DEPTH of]			[1/MAINLOOP_RATE]
//	GIX_300	GIX_300_AT_250_HZ	DUAL_GIX	ISR (Hz)	&Buffer_Accel_5KHz	TS_Period (uSec)	ADC_SAMPLES_PER_CHANNEL
//	=======	=================	========	========	==================	================	=======================
//		0							0							0			2.5 KHz					N/A							4000										10							
//
//		0							0							1				N/A						N/A							N/A											N/A   					
//		0							1							0				N/A						N/A							N/A											N/A   					
//		0							1							1				N/A						N/A							N/A											N/A   
//
//		1							0							0			5.0 KHz					10							2000										10							
//		1							0							1			5.0 KHz					10							2000										10							
//		1							1							0			5.0 KHz					20							4000										20							
//		1							1							1			5.0 KHz					20							4000										20							
//

//////////////////////////////////////////////////////
//	GIX 309 options
//////////////////////////////////////////////////////
#define	GIX_300		(1)

	#if		defined(GIX_300)
#define	GIX_300_AT_250_HZ	(1)
//#define	DUAL_GIX	(1)
	#endif

#define	NO_A2_TB	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT

#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp
#define	LSM6DS3	(1)
#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	ENABLE_SPI_GYRO	(1)
//#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define ENABLE_SPI_GYRO_TEMP_COMP (1) // Needed to make CD sturcuture the proper size, so that linearization is at 0x14E8.

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)

//#define		GIX300		(1)
#define		F4_BUILD	(1)

//============================
#elif		(defined(SQ_GIX_2001)	)	//	needs update for newest stuff from '-0255,e tc.
//============================
//No longer needed:	//defined in 'C' options for compiler command line: #define	CANOPEN_STACK	(1)
#define	CANOPEN_STACK	(1)

#define	ENABLE_SOME_WRITES_TO_CANOPEN_COD	(1)
#define	ENABLE_CANOPEN_STORE_PARAMETERS	(1)

#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.


//////////////////////////////////////////////////////
//	ADC options for '446 ADC Linearization
//////////////////////////////////////////////////////
#define PBT_LINEARIZATION_TYPE	(6)

//	float const ADC_linearization_table[1024];
#define	lin_table	CD.ADC_linearization_table

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...
//////////////////////////////////////////////////////

#define	ZRU_ALG_3	(1)

#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)
#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
#define	NO_A2_TB	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)

//	Valid Combinations for GIX-300 and GIX-200
//																										[DEPTH of]			[1/MAINLOOP_RATE]
//	GIX_300	GIX_300_AT_250_HZ	DUAL_GIX	ISR (Hz)	&Buffer_Accel_5KHz	TS_Period (uSec)	ADC_SAMPLES_PER_CHANNEL
//	=======	=================	========	========	==================	================	=======================
//		0							0							0			2.5 KHz					N/A							4000										10							
//
//		0							0							1				N/A						N/A							N/A											N/A   					
//		0							1							0				N/A						N/A							N/A											N/A   					
//		0							1							1				N/A						N/A							N/A											N/A   
//
//		1							0							0			5.0 KHz					10							2000										10							
//		1							0							1			5.0 KHz					10							2000										10							
//		1							1							0			5.0 KHz					20							4000										20							
//		1							1							1			5.0 KHz					20							4000										20							
//

//////////////////////////////////////////////////////
//	GIX 309 options
//////////////////////////////////////////////////////
#define	GIX_300		(1)

	#if		defined(GIX_300)
#define	GIX_300_AT_250_HZ	(1)
//#define	DUAL_GIX	(1)
	#endif


#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT

#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp
#define	LSM6DS3	(1)
#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	ENABLE_SPI_GYRO	(1)
//#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)

//#define		GIX300		(1)
#define		F4_BUILD	(1)

//============================
#elif	(defined(SQ_RPS_0063)  or  defined(SQ_RPS_0064)	)
//============================

#define	MA_0192		(1)	//	Uses MC-1201, new GIX III PCB Assembly, STM32F446 

#define	NO_GYROS	(1)
#define	NO_HIG_ACCEL	(1)

#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.


#if		not	defined(RUN_446_AT_72_MHZ)
	ERROR!!!	"RUN_446_AT_72_MHZ" must be defined in the Preprocessor Symbols int the C/C++ Options Menu !!!
#define	RUN_446_AT_72_MHZ	(1)	//	!!! MAKE SURE THIS IS PREDEFINED !!! [Should get macro redefined error here if it is.]
#endif

//////////////////////////////////////////////////////
//	ADC options for '446 ADC Linearization
//////////////////////////////////////////////////////
#define PBT_LINEARIZATION_TYPE	(6)

//	float const ADC_linearization_table[1024];
#define	lin_table	CD.ADC_linearization_table
  
  
#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...

#define	ZRU_ALG_3	(1)
#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)

//#define	FORCE_DIGITAL_GYRO	(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO
#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
//#define	NO_ANALOG_GYROS	(1)
#define	NO_A2_TB	(1)

//#define	DEFEAT_GIX_BIAS_TRIM	(1)

#define	BIAS_WALK_LIMIT_DUAL	(1)

//#define	FASTER_SPI	(1)
////use dual scheme	#define	BIAS_WALK_LIMIT		(15.0)	/* deg/sec */

//#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

//#define	DEFEAT_TRIMBLE_SAMPLING_WARP	(1)
//#define SCAN_TEST	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)

//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)


//#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
//#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

//#define	ENABLE_SPI_GYRO	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
//#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

//#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

//#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)
//#define		GIX300		(1)		//	Older GIX300, deprecated
#define		F4_BUILD	(1)

//============================
#elif	(defined(SQ_RPS_0065)	)
//============================

#define	MA_0192		(1)	//	Uses MC-1201, new GIX III PCB Assembly, STM32F446 

#define	NO_GYROS	(1)
#define	NO_HIG_ACCEL	(1)

// SQ_RPS_0065 took these three lines out
//  #if		not	defined(RUN_446_AT_72_MHZ)
//#define	RUN_446_AT_72_MHZ	(1)	//	!!! MAKE SURE THIS IS PREDEFINED !!! [Should get macro redefined error here if it is.]
//  #endif

#define	ENABLE_50_HZ_SINGLE_POLE_ACCEL	(1)

//////////////////////////////////////////////////////
//	ADC options for '446 ADC Linearization
//////////////////////////////////////////////////////
#define PBT_LINEARIZATION_TYPE	(6)

//	float const ADC_linearization_table[1024];
#define	lin_table	CD.ADC_linearization_table

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...

#define	ZRU_ALG_3	(1)
#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)

//#define	FORCE_DIGITAL_GYRO	(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO
#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
//#define	NO_ANALOG_GYROS	(1)
//#define	NO_A2_TB	(1)  // CATERPILLAR HAS TB A2

//#define	DEFEAT_GIX_BIAS_TRIM	(1)

#define	BIAS_WALK_LIMIT_DUAL	(1)

//#define	FASTER_SPI	(1)
////use dual scheme	#define	BIAS_WALK_LIMIT		(15.0)	/* deg/sec */

//#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

//#define	DEFEAT_TRIMBLE_SAMPLING_WARP	(1)
//#define SCAN_TEST	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)

//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)


//#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
//#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

//#define	ENABLE_SPI_GYRO	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
//#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

//#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

//#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)
//#define		GIX300		(1)		//	Older GIX300, deprecated
#define		F4_BUILD	(1)

//============================
#elif	(defined(SQ_RPS_0061)	)
//============================
#define	MB_GYRO		(1)
#define	LSM330DLC	(1)
//#define	ENABLE_SPI_GYRO	(1)		//	Note: Enabled elsewhere.
//#define	ENABLE_SPI_MAG	(1)		
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.
#define	NO_MAGS	(1)
#define	ENHANCED_STATUS_BITS	(1)
#define	ENABLE_5_HZ_SINGLE_POLE_GYRO	(1)
//============================
#elif		(defined(SQ_RPS_0058)	or	defined(SQ_RPS_0059)	)
//============================
//#define	HALT_TEST	(1)
//#define	L3GD20H	(1)
#define	LSM6DS3	(1)

//	No longer mutually exclusive:
//#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

//#define	ENABLE_SPI_GYRO	(1)
//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)
//#define		GIX300		(1)		//	Older GIX300, deprecated
#define		F4_BUILD	(1)
//============================
#elif	defined(SQ_CST_0342)
//============================
//#define	HALT_TEST	(1)
//#define	L3GD20H	(1)
#define	LSM6DS3	(1)

//	No longer mutually exclusive:
#define	MB_GYRO	(1)
#define	A1_GYRO	(1)
#define	A2_GYRO	(1)

#define	ENABLE_SPI_GYRO	(1)
//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)
//#define		GIX300		(1)		//	Older GIX300, deprecated
#define		F4_BUILD	(1)
//============================
#elif		(defined(SQ_GIX_0270)	)
//============================
#define PBT_LINEARIZATION_TYPE	(6)

//	float const ADC_linearization_table[1024];
#define	lin_table	CD.ADC_linearization_table

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...

#define	ZRU_ALG_3	(1)

#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)
#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
#define	NO_A2_TB	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)

//#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT

#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp
#define	LSM6DS3	(1)
//#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	ENABLE_SPI_GYRO	(1)

#define	NO_MAGS	(1)

#define		F4_BUILD	(1)

//######################################################################################################

//============================
#elif   (defined(SQ_GIX_2015) )
//============================
#define	ENABLE_CAN_INTERRUPT_FOR_OLD_DRIVER	(1)		//	ENABLE for faster CAN TX messaging.

//#define	GIX_300_STATUS_MESSAGE	(1)	//	Generate MSGID_DB_1  Diagnostic message @ ~1 Hz  [64 bit Error bit Vector]

//#define	DEBUG_AT_5K	(1)
//#define	TRIPLE_FP_MESSAGES	(1)	//	not TRIMBLE here!!!

//////////////////////////////////////////////////////
//	ADC options for '446 ADC Linearization
//////////////////////////////////////////////////////
#define PBT_LINEARIZATION_TYPE	(6)

//	float const ADC_linearization_table[1024];
#define	lin_table	CD.ADC_linearization_table

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...
//////////////////////////////////////////////////////

#define	GIX_300		(1)

	#if		defined(GIX_300)
//#define	DUAL_GIX	(1)
#define	GIX_300_AT_250_HZ	(1)
	#endif

//#if		not	defined(RUN_446_AT_72_MHZ)
//	ERROR!!!	"RUN_446_AT_72_MHZ" must be defined in the PreProcessor Symbols int the C/C++ Options Menu !!!
//#define	RUN_446_AT_72_MHZ	(1)	//	!!! MAKE SURE THIS IS PREDEFINED !!! [Should get macro redefined error here if it is.]
//#endif

#define	ZRU_ALG_3	(1)

#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)
#define	TRIMBLE_MESSAGE_SENT_DETECTION	(1)

#define	FORCE_DIGITAL_GYRO	(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO
//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
#define	NO_ANALOG_GYROS	(1)
#define	NO_A2_TB	(1)

// This is how it was before I added the above -PBT
//#define	FORCE_DIGITAL_GYRO	(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO
//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
//#define	NO_ANALOG_GYROS	(1)
//#define	NO_A2_TB	(1)

//#define	DEFEAT_GIX_BIAS_TRIM	(1)

#define	BIAS_WALK_LIMIT_DUAL	(1)

//#define	FASTER_SPI	(1)
////use dual scheme	#define	BIAS_WALK_LIMIT		(15.0)	/* deg/sec */

#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

#define	DEFEAT_TRIMBLE_SAMPLING_WARP	(1)
//#define SCAN_TEST	(1)
//#define	FORCE_R11	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)

    #if		000	//	SPI GYRO TEST code
//#define	TRIMBLE_DO_NOT_REQUIRE_TIME_SYNC_MASTER	(1)
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	JLM_GYRO_TEST_2	(1)									//	mutually exclusive against TRIMBLE_TRIPLE_FP_MESSAGES
    #else
      #if		001		//DEBUG and FP messages
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
      #else
        #if		00		//	test only, don't ship	//	Test code for Variance
#define	DEBUG_ONLINE_VARIANCE	(1)		//	Do not ship with this on.
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
        #else
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
        #endif
      #endif
    #endif
//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

#define	ENABLE_SPI_GYRO	(1)   

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)
#define	NO_MAGS	(1)
//#define		GIX300		(1)	//	Older GIX300, deprecated
#define		F4_BUILD	(1)


//============================
#elif		(defined(SQ_GIX_2010)  or  defined(SQ_GIX_2011)  or  defined(SQ_GIX_2012)  or  defined(SQ_GIX_2013)	) //or	defined(SQ_GIX_2015)	)
//============================
#define	ENABLE_CAN_INTERRUPT_FOR_OLD_DRIVER	(1)		//	ENABLE for faster CAN TX messaging.

//#define	GIX_300_STATUS_MESSAGE	(1)	//	Generate MSGID_DB_1  Diagnostic message @ ~1 Hz  [64 bit Error bit Vector]

//#define	DEBUG_AT_5K	(1)
//#define	TRIPLE_FP_MESSAGES	(1)	//	not TRIMBLE here!!!

#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

//////////////////////////////////////////////////////
//	ADC options for '446 ADC Linearization
//////////////////////////////////////////////////////
#define PBT_LINEARIZATION_TYPE	(6)

//	float const ADC_linearization_table[1024];
#define	lin_table	CD.ADC_linearization_table

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...
//////////////////////////////////////////////////////

#define	GIX_300		(1)

	#if		defined(GIX_300)
//#define	DUAL_GIX	(1)
#define	GIX_300_AT_250_HZ	(1)
	#endif

//#if		not	defined(RUN_446_AT_72_MHZ)
//	ERROR!!!	"RUN_446_AT_72_MHZ" must be defined in the PreProcessor Symbols int the C/C++ Options Menu !!!
//#define	RUN_446_AT_72_MHZ	(1)	//	!!! MAKE SURE THIS IS PREDEFINED !!! [Should get macro redefined error here if it is.]
//#endif

#define	ZRU_ALG_3	(1)

#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)
#define	TRIMBLE_MESSAGE_SENT_DETECTION	(1)

//#define	FORCE_DIGITAL_GYRO	(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO
//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
//#define	NO_ANALOG_GYROS	(1)
#define	NO_A2_TB	(1)

//#define	DEFEAT_GIX_BIAS_TRIM	(1)

#define	BIAS_WALK_LIMIT_DUAL	(1)

//#define	FASTER_SPI	(1)
////use dual scheme	#define	BIAS_WALK_LIMIT		(15.0)	/* deg/sec */

//#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

#define	DEFEAT_TRIMBLE_SAMPLING_WARP	(1)
//#define SCAN_TEST	(1)
//#define	FORCE_R11	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)

    #if		000	//	SPI GYRO TEST code
//#define	TRIMBLE_DO_NOT_REQUIRE_TIME_SYNC_MASTER	(1)
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	JLM_GYRO_TEST_2	(1)									//	mutually exclusive against TRIMBLE_TRIPLE_FP_MESSAGES
    #else
      #if		001		//DEBUG and FP messages
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
      #else
        #if		00		//	test only, don't ship	//	Test code for Variance
#define	DEBUG_ONLINE_VARIANCE	(1)		//	Do not ship with this on.
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
        #else
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
        #endif
      #endif
    #endif
//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

#define	ENABLE_SPI_GYRO	(1)   

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)
#define	NO_MAGS	(1)
//#define		GIX300		(1)	//	Older GIX300, deprecated
#define		F4_BUILD	(1)

//============================
#elif		defined(SQ_GIX_0272)
//============================
//#define	FORCE_VIN_GOOD	(1)		//	For debugging P/S Brownout issues only!!!

#define	GIX_300_STATUS_MESSAGE	(1)	//	Generate MSGID_DB_1  Diagnostic message @ ~1 Hz  [64 bit Error bit Vector]
//#define GIX_300_Ra_MESSAGE      (1) //  Generate MSG PGN FFA2 containing Ra Noise Measurement diagnostics.

//	NOTE: GIX-300 will not currently run on '105 @ 72 MHZ
//#if		not	defined(RUN_446_AT_72_MHZ)
//	ERROR!!!	"RUN_446_AT_72_MHZ" must be defined in the PreProcessor Symbols int the C/C++ Options Menu !!!
//#define	RUN_446_AT_72_MHZ	(1)	//	!!! MAKE SURE THIS IS PREDEFINED !!! [Should get macro redefined error here if it is.]
//#endif

#define	ENHANCED_STATUS_BITS	(1)
#define	ENABLE_DTC_FAULTS	(1)
#define	ENABLE_DTC_FAULT_VECTOR_MESSAGE	(1)

//#define	ENABLE_CAN_INTERRUPT_FOR_OLD_DRIVER	(1)		//	ENABLE for faster CAN TX messaging.

//	Valid Combinations for GIX-300 and GIX-200
//																										[DEPTH of]			[1/MAINLOOP_RATE]
//	GIX_300	GIX_300_AT_250_HZ	DUAL_GIX	ISR (Hz)	&Buffer_Accel_5KHz	TS_Period (uSec)	ADC_SAMPLES_PER_CHANNEL
//	=======	=================	========	========	==================	================	=======================
//		0							0							0			2.5 KHz					N/A							4000										10							
//
//		0							0							1				N/A						N/A							N/A											N/A   					
//		0							1							0				N/A						N/A							N/A											N/A   					
//		0							1							1				N/A						N/A							N/A											N/A   
//
//		1							0							0			5.0 KHz					10							2000										10							
//		1							0							1			5.0 KHz					10							2000										10							
//		1							1							0			5.0 KHz					20							4000										20							
//		1							1							1			5.0 KHz					20							4000										20							
//

//////////////////////////////////////////////////////
//	GIX 309 options
//////////////////////////////////////////////////////
#define	GIX_300		(1)

	#if		defined(GIX_300)
#define	GIX_300_AT_250_HZ	(1)
//#define	DUAL_GIX	(1)
	#endif

//////////////////////////////////////////////////////
//	ADC options for '446 ADC Linearization
//////////////////////////////////////////////////////
#define PBT_LINEARIZATION_TYPE	(6)

#define	lin_table	CD.ADC_linearization_table

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...

//#define SCAN_TEST	(1)
//#define	FORCE_R11	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)


//////////////////////////////////////////////////////
//	GIX_200 Options
//////////////////////////////////////////////////////
#define	ZRU_ALG_3	(1)
//#define	OLD_ZRU_TEST	(1)		//Debug comparison testing only
#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)

///////////////////////////////////////////////////////////////////////////////////////////////////////
//	GYRO HW Option
///////////////////////////////////////////////////////////////////////////////////////////////////////
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp
#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	ENABLE_SPI_GYRO	(1)
//#define	FORCE_DIGITAL_GYRO	(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO
//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
//#define	NO_ANALOG_GYROS	(1)
#define	NO_A2_TB	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.
//#define	FASTER_SPI	(1)

//#define	ENABLE_SPI_MAG	(1)
#define	NO_MAGS	(1)
#define		F4_BUILD	(1)


///////////////////////////////////////////////////////////////////////////////////////////////////////
//	DEBUG BUILD
///////////////////////////////////////////////////////////////////////////////////////////////////////
	#if		0001	//	Enable Here for Customer Facing build
///////////////////////////////////////////////////////////////////////////////////////////////////////

	//	...

///////////////////////////////////////////////////////////////////////////////////////////////////////
	#else		//	!=0001	//	Here for 1000 kBaud Debug build
///////////////////////////////////////////////////////////////////////////////////////////////////////

#define	SQ_GIX_0272_DEBUG	(1)		//	Alter messaging

//#define	DEBUG_AT_5K	(1)
#define	TRIPLE_FP_MESSAGES	(1)	//	not TRIMBLE here!!!

		#if		000	//	SPI GYRO TEST code
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	JLM_GYRO_TEST_2	(1)									//	mutually exclusive against TRIMBLE_TRIPLE_FP_MESSAGES
		#else
			#if		001		//DEBUG and FP messages
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
			#else
				#if		000		//	test only, don't ship	//	Test code for Variance
#define	DEBUG_ONLINE_VARIANCE	(1)		//	Do not ship with this on.
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
				#else
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
				#endif
			#endif
		#endif

//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

///////////////////////////////////////////////////////////////////////////////
	#endif	//	0001
///////////////////////////////////////////////////////////////////////////////

//============================
#elif		(defined(SQ_GIX_0299)	)
//============================
#define PBT_LINEARIZATION_TYPE	(6)

//	float const ADC_linearization_table[1024];
#define	lin_table	CD.ADC_linearization_table

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...

#define	ZRU_ALG_3	(1)

#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)
#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
#define	NO_A2_TB	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)

//#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT

#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp
#define	LSM6DS3	(1)
//#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)
#define ENABLE_SPI_GYRO_TEMP_COMP (1) // Needed to make CD sturcuture the proper size, so that linearization is at 0x14E8.

#define	ENABLE_SPI_GYRO	(1)

#define	NO_MAGS	(1)

#define		F4_BUILD	(1)

//============================
#elif		(defined(SQ_CST_0343)	)
//============================
//#define	HALT_TEST	(1)
//#define	ENABLE_SPI_GYRO	(1)
//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)
//#define		GIX300		(1)		//	Older GIX300, deprecated
#define		F4_BUILD	(1)
//============================
#elif		defined(SQ_GIX_0219)
//============================
#define		GIX300		(1)		//	Older GIX300, deprecated
#define		F4_BUILD	(1)

//============================
#elif		(defined(SQ_GIX_0289) or  defined(SQ_GIX_0272_F105)	)
//============================
/*** STUFF from the SQ_GIX_0270 build ***/
#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT

//#define	HALT_TEST	(1)

#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp
#define	LSM6DS3	(1)
#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	ENABLE_SPI_GYRO	(1)
//#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)

//#define		GIX300		(1)		//	Older GIX300, deprecated
//#define		F4_BUILD	(1) /*PBT: Don't think this is an F4 build */

/*** STUFF from the SQ_GIX_0261 build ***/

// PBT: took this out because it is already defined further down
#define	MA_0219	//	GEN III but with a STM32F105 instead of a STM32F446

// PBT: FORCE_R11 does something with the kalman filter - sets one of the parameters for a fixed constant R_NOMINAL, instead of R_pitch_slow
// PBT: Whit says to turn FORCE_R11 OFF
//#define	FORCE_R11	(1)
// PBT: DEFEAT_GIX_BIAS_TRIM disables code in GIX200.C that adjusts the bias
// PBT: John and Whit say to leave this ON
#define	DEFEAT_GIX_BIAS_TRIM	(1)
// PBT: This looks like it sends additional messages containing all the SPI gyro readings
// PBT: John says to leave this ON
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.

// PBT: took these out because they were also set in the SQ_GIX_0270 build (look a few lines up from here)
//#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
//#define	DUAL_GYRO	(1)		//Only for some 255 derived builds //	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp
//#define	ENABLE_SPI_GYRO	(1)
//#define	MB_GYRO	(1)
//#define	LSM6DS3	(1)
//#define	NO_MAGS	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
// PBT: John says to leave this ON
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

// PBT: these were explicitly disabled in SQ_GIX_0270
// PBT: however, John says to leave these ON
#define	A1_GYRO	(1)
#define	A2_GYRO	(1)

//============================
#elif		defined(SQ_GIX_2026)
//============================
//#define	ENABLE_PIX_USART	(1)		//	Do not define for MODBUS_STACK???
#define	MODBUS_STACK	(1)

// ~PBT #define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)

//#define		GIX300		(1)
#define	F4_BUILD	(1) 
#define	DEFEAT_GIX_BIAS_TRIM	(1)

//////////////////////////////////////////////////////
//	ADC options for '446 ADC Linearization
//////////////////////////////////////////////////////
#define PBT_LINEARIZATION_TYPE	(6)

//	float const ADC_linearization_table[1024];
#define	lin_table	CD.ADC_linearization_table

//	Valid Combinations for GIX-300 and GIX-200
//																										[DEPTH of]			[1/MAINLOOP_RATE]
//	GIX_300	GIX_300_AT_250_HZ	DUAL_GIX	ISR (Hz)	&Buffer_Accel_5KHz	TS_Period (uSec)	ADC_SAMPLES_PER_CHANNEL
//	=======	=================	========	========	==================	================	=======================
//		0							0							0			2.5 KHz					N/A							4000										10							
//
//		0							0							1				N/A						N/A							N/A											N/A   					
//		0							1							0				N/A						N/A							N/A											N/A   					
//		0							1							1				N/A						N/A							N/A											N/A   
//
//		1							0							0			5.0 KHz					10							2000										10							
//		1							0							1			5.0 KHz					10							2000										10							
//		1							1							0			5.0 KHz					20							4000										20							
//		1							1							1			5.0 KHz					20							4000										20							
//

//////////////////////////////////////////////////////
//	GIX 309 options
//////////////////////////////////////////////////////
#define	GIX_300		(1)

	#if		defined(GIX_300)
#define	GIX_300_AT_250_HZ	(1)
//#define	DUAL_GIX	(1)
	#endif

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...

#define	ZRU_ALG_3	(1)
//#define	OLD_ZRU_TEST	(1)		//Debug comparison testing only
#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)

#define	FORCE_DIGITAL_GYRO	(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO
//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
//#define	NO_ANALOG_GYROS	(1)
#define	NO_A2_TB	(1)

//#define	DEFEAT_GIX_BIAS_TRIM	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)

#define	FASTER_SPI	(1)

//#define SCAN_TEST	(1)
//#define	FORCE_R11	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	HALT_TEST	(1)

#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

#define	ENABLE_SPI_GYRO	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)
#define	NO_MAGS	(1)
//#define		GIX300		(1)	//	Older GIX300, deprecated
#define		F4_BUILD	(1)

//============================
#elif		defined(SQ_GIX_2003)
//============================
//#define	ENABLE_PIX_USART	(1)		//	Do not define for MODBUS_STACK???
#define	MODBUS_STACK	(1)

// ~PBT #define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)

//#define		GIX300		(1)
#define	F4_BUILD	(1) 
#define	DEFEAT_GIX_BIAS_TRIM	(1)

//////////////////////////////////////////////////////
//	ADC options for '446 ADC Linearization
//////////////////////////////////////////////////////
#define PBT_LINEARIZATION_TYPE	(6)

//	float const ADC_linearization_table[1024];
#define	lin_table	CD.ADC_linearization_table

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...

#define	ZRU_ALG_3	(1)
//#define	OLD_ZRU_TEST	(1)		//Debug comparison testing only
#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)

//#define	FORCE_DIGITAL_GYRO	(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO
#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
//#define	NO_ANALOG_GYROS	(1)
#define	NO_A2_TB	(1)

//#define	DEFEAT_GIX_BIAS_TRIM	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)

#define	FASTER_SPI	(1)

//#define SCAN_TEST	(1)
//#define	FORCE_R11	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	HALT_TEST	(1)

#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

#define	ENABLE_SPI_GYRO	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

//~PBT #define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)
#define	NO_MAGS	(1)
//#define		GIX300		(1)	//	Older GIX300, deprecated
#define		F4_BUILD	(1)

//============================
#elif		defined(SQ_GIX_2023)
//============================

#define	ENABLE_I2C3	(1)					//	Need this to control MUX on PIX IO PCBA
#define	ENABLE_PIX_USART	(1)		//	Do not define for MODBUS_STACK???

#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

//////////////////////////////////////////////////////
//	ADC options for '446 ADC Linearization
//////////////////////////////////////////////////////
#define PBT_LINEARIZATION_TYPE	(6)

//	float const ADC_linearization_table[1024];
#define	lin_table	CD.ADC_linearization_table

//#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)

//#define		GIX300		(1)
#define		F4_BUILD	(1) 
#define	DEFEAT_GIX_BIAS_TRIM	(1)


//	Valid Combinations for GIX-300 and GIX-200
//																										[DEPTH of]			[1/MAINLOOP_RATE]
//	GIX_300	GIX_300_AT_250_HZ	DUAL_GIX	ISR (Hz)	&Buffer_Accel_5KHz	TS_Period (uSec)	ADC_SAMPLES_PER_CHANNEL
//	=======	=================	========	========	==================	================	=======================
//		0							0							0			2.5 KHz					N/A							4000										10							
//
//		0							0							1				N/A						N/A							N/A											N/A   					
//		0							1							0				N/A						N/A							N/A											N/A   					
//		0							1							1				N/A						N/A							N/A											N/A   
//
//		1							0							0			5.0 KHz					10							2000										10							
//		1							0							1			5.0 KHz					10							2000										10							
//		1							1							0			5.0 KHz					20							4000										20							
//		1							1							1			5.0 KHz					20							4000										20							
//

//////////////////////////////////////////////////////
//	GIX 309 options
//////////////////////////////////////////////////////
#define	GIX_300		(1)

	#if		defined(GIX_300)
// PBT NOTE:  This product is meant to run at 500Hz.
//#define	GIX_300_AT_250_HZ	(1)
//#define	DUAL_GIX	(1)
	#endif

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...

#define	ZRU_ALG_3	(1)
//#define	OLD_ZRU_TEST	(1)		//Debug comparison testing only
#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)

#define	FORCE_DIGITAL_GYRO	(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO
//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
//#define	NO_ANALOG_GYROS	(1)
#define	NO_A2_TB	(1)

//#define	DEFEAT_GIX_BIAS_TRIM	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)

#define	FASTER_SPI	(1)

//#define SCAN_TEST	(1)
//#define	FORCE_R11	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	HALT_TEST	(1)

#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

#define	ENABLE_SPI_GYRO	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)
//#define		GIX300		(1)	//	Older GIX300, deprecated


//============================
#elif		defined(SQ_GIX_0298)
//============================

// PBT - The following was elsewhere, and now I moved it here... //	JLM - The following belongs elsewhere...
#define	ENABLE_I2C3	(1)					//	Need this to control MUX on PIX IO PCBA
#define	ENABLE_PIX_USART	(1)		//	Do not define for MODBUS_STACK???
// ...

#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

//////////////////////////////////////////////////////
//	ADC options for '446 ADC Linearization
//////////////////////////////////////////////////////
#define PBT_LINEARIZATION_TYPE	(6)

//	float const ADC_linearization_table[1024];
#define	lin_table	CD.ADC_linearization_table

#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)

//#define		GIX300		(1)
#define		F4_BUILD	(1) 
#define	DEFEAT_GIX_BIAS_TRIM	(1)

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...

#define	ZRU_ALG_3	(1)
//#define	OLD_ZRU_TEST	(1)		//Debug comparison testing only
#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)

//#define	FORCE_DIGITAL_GYRO	(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO
//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
//#define	NO_ANALOG_GYROS	(1)
#define	NO_A2_TB	(1)

//#define	DEFEAT_GIX_BIAS_TRIM	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)

#define	FASTER_SPI	(1)

//#define SCAN_TEST	(1)
//#define	FORCE_R11	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	HALT_TEST	(1)

//#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

#define	ENABLE_SPI_GYRO	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)
#define	NO_MAGS	(1)
//#define		GIX300		(1)	//	Older GIX300, deprecated
#define		F4_BUILD	(1)

//============================
#elif		(defined(SQ_GIX_0261)	)
//============================

#define	MA_0219	//	GEN III but with a STM32F105 instead of a STM32F446

//#define SCAN_TEST	(1)
#define	FORCE_R11	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)
#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	HALT_TEST	(1)

//#define TRIMBLE_TRANSMIT_AT_START	(1)
//#define	DEFEAT_TRIMBLE_FREQUENCY_LOCK	(1)		//	redundant with IGNORE_TRIMBLE_TIME_SYNC ???
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
//#define	TRIMBLE_DEBUG	(1)	//Bias and 'R' messages
//#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate

//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	DUAL_GYRO	(1)		//Only for some 255 derived builds //	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

#define	ENABLE_SPI_GYRO	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)
//	NOTE: DISABLE 2ND AND 3RD GYROS TO PREVENT ANY POTENTIAL MISORDERING ISSUES FOR NOW...LIVE TO CHASE ANOTHER DAY.
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)
//#define		GIX300		(1)		//	Older GIX300, deprecated
//no F4 on MA_0192_105_TEST or 	or MA_0219 HW /*#define		F4_BUILD	(1)*/
//============================
#elif		(defined(SQ_GIX_0255)	and	(defined(MA_0192_105_TEST)	or	defined(MA_0219)	)	)
//============================
#define	ENHANCED_STATUS_BITS	(1)
#define	ENABLE_5_HZ_SINGLE_POLE_GYRO	(1)

//#define	ZRU_ALG_4	(1)
#define	ZRU_ALG_3	(1)
//#define	OLD_ZRU_TEST	(1)		//Debug comparison testing only
#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)
#define	TRIMBLE_MESSAGE_SENT_DETECTION	(1)

#define	FORCE_DIGITAL_GYRO	(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO
//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
#define	NO_ANALOG_GYROS	(1)
#define	NO_A2_TB	(1)

//#define	TRIMBLE_DO_NOT_REQUIRE_TIME_SYNC_MASTER	(1)
//#define	ENABLE_TRIMBLE_MSGID_D	(1)

//#define	DEFEAT_GIX_BIAS_TRIM	(1)

#define	TRIMBLE_ODR_MESSAGE_INTERLOCK	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)

//#define	FASTER_SPI	(1)
////use dual scheme	#define	BIAS_WALK_LIMIT		(15.0)	/* deg/sec */
//#define	TRIMBLE_BREAK_J1939_MESSAGE_LENGTH	(1)		//	REMOVE THIS FEATURE

#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

#define	DEFEAT_TRIMBLE_SAMPLING_WARP	(1)
#define SCAN_TEST	(1)
//#define	FORCE_R11	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)
//#define	HALT_TEST	(1)

#if		000	//	SPI GYRO TEST code
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
//#define	TRIMBLE_TRIPLE_FP_MESSAGES	(1)
#else
	#if		000		//DEBUG and FP messages
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	DEFEAT_TRIMBLE_FREQUENCY_LOCK	(1)		//	redundant with IGNORE_TRIMBLE_TIME_SYNC ???
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_DEBUG	(1)	//Bias and 'R' messages
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
#define	TRIMBLE_TRIPLE_FP_MESSAGES	(1)
	#else
		#if		00		//	test only, don't ship	//	Test code for Variance
#define	DEBUG_ONLINE_VARIANCE	(1)		//	Do not ship with this on.
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
		#else
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
		#endif
	#endif
#endif
//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

#define	ENABLE_SPI_GYRO	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)
//#define		GIX300		(1)		//	Older GIX300, deprecated
//no F4 on MA_0192_105_TEST HW or on MA_0219	/*#define		F4_BUILD	(1)*/
//============================
#elif		(not	defined(SQ_GIX_0286))	and	defined(SQ_GIX_0255)
//============================

//#if		not	defined(RUN_446_AT_72_MHZ)
//	ERROR!!!	"RUN_446_AT_72_MHZ" must be defined in the PreProcessor Symbols int the C/C++ Options Menu !!!
//#define	RUN_446_AT_72_MHZ	(1)	//	!!! MAKE SURE THIS IS PREDEFINED !!! [Should get macro redefined error here if it is.]
//#endif

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...

///////////////////////////////////////////////////////////////////////////////////////////////////////
#if		0001
///////////////////////////////////////////////////////////////////////////////////////////////////////

//#define	ZRU_ALG_4	(1)
#define	ZRU_ALG_3	(1)
//#define	OLD_ZRU_TEST	(1)		//Debug comparison testing only
#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)
#define	TRIMBLE_MESSAGE_SENT_DETECTION	(1)

//#define	FORCE_DIGITAL_GYRO	(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO
//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
//#define	NO_ANALOG_GYROS	(1)
#define	NO_A2_TB	(1)

//#define	TRIMBLE_DO_NOT_REQUIRE_TIME_SYNC_MASTER	(1)
//#define	ENABLE_TRIMBLE_MSGID_D	(1)

//#define	DEFEAT_GIX_BIAS_TRIM	(1)

#define	TRIMBLE_ODR_MESSAGE_INTERLOCK	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)

//#define	FASTER_SPI	(1)
////use dual scheme	#define	BIAS_WALK_LIMIT		(15.0)	/* deg/sec */
//#define	TRIMBLE_BREAK_J1939_MESSAGE_LENGTH	(1)		//	REMOVE THIS FEATURE

//#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

#define	DEFEAT_TRIMBLE_SAMPLING_WARP	(1)
//#define SCAN_TEST	(1)
//#define	FORCE_R11	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	HALT_TEST	(1)

#if	00	//	SPI GYRO TEST code
//#define	TRIMBLE_DO_NOT_REQUIRE_TIME_SYNC_MASTER	(1)
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
//#define	TRIMBLE_TRIPLE_FP_MESSAGES	(1)		//	mutually exclusive against JLM_GYRO_TEST_2
#define	JLM_GYRO_TEST_2	(1)									//	mutually exclusive against TRIMBLE_TRIPLE_FP_MESSAGES
#else
	#if		001		//DEBUG and FP messages
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	DEFEAT_TRIMBLE_FREQUENCY_LOCK	(1)		//	redundant with IGNORE_TRIMBLE_TIME_SYNC ???
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_DEBUG	(1)	//Bias and 'R' messages
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
#define	TRIMBLE_TRIPLE_FP_MESSAGES	(1)
	#else
		#if		00		//	test only, don't ship	//	Test code for Variance
#define	DEBUG_ONLINE_VARIANCE	(1)		//	Do not ship with this on.
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
		#else
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
		#endif
	#endif
#endif
//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

#define	ENABLE_SPI_GYRO	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)
//#define		GIX300		(1)		//	Older GIX300, deprecated
#define		F4_BUILD	(1)

///////////////////////////////////////////////////////////////////////////////////////////////////////
#else	//	0001
///////////////////////////////////////////////////////////////////////////////////////////////////////

//#define SCAN_TEST	(1)
//#define	FORCE_R11	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)
#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	HALT_TEST	(1)

	#if		0001		//DEBUG and FP messages
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	DEFEAT_TRIMBLE_FREQUENCY_LOCK	(1)		//	redundant with IGNORE_TRIMBLE_TIME_SYNC ???
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)
#define	TRIMBLE_DEBUG	(1)	//Bias and 'R' messages
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
#define	TRIMBLE_TRIPLE_FP_MESSAGES	(1)
	#else
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
	#endif

//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

#define	ENABLE_SPI_GYRO	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)
//#define		GIX300		(1)		//	Older GIX300, deprecated
#define		F4_BUILD	(1)
///////////////////////////////////////////////////////////////////////////////
#endif	//	0001
///////////////////////////////////////////////////////////////////////////////

//============================
#elif		defined(SQ_GIX_0302)
//============================
#define SCAN_TEST	(1)
#define	FORCE_R11	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)
#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	HALT_TEST	(1)
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	DEFEAT_TRIMBLE_FREQUENCY_LOCK	(1)		//	redundant with IGNORE_TRIMBLE_TIME_SYNC ???
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_DEBUG	(1)	//Bias and 'R' messages [not true]
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate

//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

#define	ENABLE_SPI_GYRO	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)
#define	A1_GYRO	(1)
#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)
//#define		GIX300		(1)
#define		F4_BUILD	(1)
//============================
#elif		defined(SQ_GIX_0286)
//============================

#define	PERSISTENT_ACCEL_GYRO_RANGE_FAULTS	(1)

//---------------------------------------------------------------------------------------------------------
//	DEBUG:  Need the following defines:
//---------------------------------------------------------------------------------------------------------
#if		000		//	DEBUG STUFF: start spewing on start without a Time Sync Master
#define	FORCE_VIN_GOOD	(1)		//	For debugging P/S Brownout issues only!!!
#define	TRIMBLE_DO_NOT_REQUIRE_TIME_SYNC_MASTER	(1)
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
	#endif
//---------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------
//	==========================
//	'Options' 'C/C++' Options:
//	==========================
//	105 version:	STM32F10X_CL CMSIS_3_5_0 HSE_VALUE=16000000
//	446 version:	STM32F427_437xx HSE_VALUE=16000000 PLL_M=16 USE_STDPERIPH_DRIVER __FPU_PRESENT
//#define	SQ_GIX_0255	(1)		//Remember to increment FWBUILD		//	Based on SQ_CST_0343 and SQ_GIX_0249, and without CAN Termination
#define	MA_0219	(1)	//	GEN III but with a STM32F105 instead of a STM32F446
//---------------------------------------------------------------------------------------------------------

#define	ENABLE_DTC_FAULTS	(1)
#define	TRIMBLE_EXTENDED_STATUS_BITS	(1)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	#if		001
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define	ENHANCED_STATUS_BITS	(1)
#define	ENABLE_5_HZ_SINGLE_POLE_GYRO	(1)

//#define	ZRU_ALG_4	(1)
#define	ZRU_ALG_3	(1)
//#define	OLD_ZRU_TEST	(1)		//Debug comparison testing only
#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)
#define	TRIMBLE_MESSAGE_SENT_DETECTION	(1)

#define	FORCE_DIGITAL_GYRO	(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO
//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
#define	NO_ANALOG_GYROS	(1)
#define	NO_A2_TB	(1)

//#define	TRIMBLE_DO_NOT_REQUIRE_TIME_SYNC_MASTER	(1)
//#define	ENABLE_TRIMBLE_MSGID_D	(1)

//#define	DEFEAT_GIX_BIAS_TRIM	(1)

#define	TRIMBLE_ODR_MESSAGE_INTERLOCK	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)

//#define	FASTER_SPI	(1)
////use dual scheme	#define	BIAS_WALK_LIMIT		(15.0)	/* deg/sec */
//#define	TRIMBLE_BREAK_J1939_MESSAGE_LENGTH	(1)		//	REMOVE THIS FEATURE

#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.

#define	DEFEAT_TRIMBLE_SAMPLING_WARP	(1)
#define SCAN_TEST	(1)
//#define	FORCE_R11	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)
//#define	HALT_TEST	(1)

		#if		000	//	SPI GYRO TEST code
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
//#define	TRIMBLE_TRIPLE_FP_MESSAGES	(1)
		#else
			#if		000		//DEBUG and FP messages
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	DEFEAT_TRIMBLE_FREQUENCY_LOCK	(1)		//	redundant with IGNORE_TRIMBLE_TIME_SYNC ???
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_DEBUG	(1)	//Bias and 'R' messages
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
#define	TRIMBLE_TRIPLE_FP_MESSAGES	(1)
			#else
				#if		00		//	test only, don't ship	//	Test code for Variance
#define	DEBUG_ONLINE_VARIANCE	(1)		//	Do not ship with this on.
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
				#else
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
				#endif
			#endif
		#endif
//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

#define	ENABLE_SPI_GYRO	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)
//#define		GIX300		(1)		//	Older GIX300, deprecated
//no F4 on MA_0192_105_TEST HW or on MA_0219	/*#define		F4_BUILD	(1)*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	#else	//	old, never funtional
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define SCAN_TEST	(1)
#define	FORCE_R11	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)
#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	HALT_TEST	(1)
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	DEFEAT_TRIMBLE_FREQUENCY_LOCK	(1)		//	redundant with IGNORE_TRIMBLE_TIME_SYNC ???
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_DEBUG	(1)	//Bias and 'R' messages [not true]
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate

//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

#define	ENABLE_SPI_GYRO	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)
#define	A1_GYRO	(1)
#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)
//#define		GIX300		(1)		(1)	//	Older GIX300, deprecated
#define		F4_BUILD	(1)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	#endif
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//============================
#elif		defined(SQ_GIX_2024)
//============================

// DON'T EVER USE THIS SYMBOL AGAIN!!!  //#define ENABLE_IO_EXPANDER (1)
/* PBT NOTE: Builds prior to this one that had I/O boards *ALL* used the IO Expander.
   If at this point, we add a symbol that says ENABLE_IO_EXPANDER, that symbol will not
   be defined for previously-existing builds (unless we have memorized all the builds 
   that use it, and remember to go in and change it for each of them.
   If, in the future, we were to build one of those older projects, they would not work.
   For this reason, I suggest that we not use the ENABLE_IO_EXPANDER, and use the following
   symbol instead... */
#define IO_BOARD_WITH_NO_EXPANDER (1)
#define ENABLE_PIX_DAC    (1)
#define ENABLE_I2C3       (1)

#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.
#define ENABLE_CODE_PROTECTION_COMMAND  (1)

//---------------------------------------------------------------------------------------------------------
//	==========================
//	'Options' 'C/C++' Options:
//	==========================
//	105 version:	STM32F10X_CL CMSIS_3_5_0 HSE_VALUE=16000000
//	446 version:	STM32F427_437xx HSE_VALUE=16000000 PLL_M=16 USE_STDPERIPH_DRIVER __FPU_PRESENT
//---------------------------------------------------------------------------------------------------------

////#define	TRIMBLE_EXTENDED_STATUS_BITS	(1)
#define	ENHANCED_STATUS_BITS	(1)
#define	ENABLE_DTC_FAULTS	(1)
//#define	ENABLE_DTC_FAULT_VECTOR_MESSAGE	(1)

//#define	ENABLE_CAN_INTERRUPT_FOR_OLD_DRIVER	(1)		//	ENABLE for faster CAN TX messaging.

//	Valid Combinations for GIX-300 and GIX-200
//																										[DEPTH of]			[1/MAINLOOP_RATE]
//	GIX_300	GIX_300_AT_250_HZ	DUAL_GIX	ISR (Hz)	&Buffer_Accel_5KHz	TS_Period (uSec)	ADC_SAMPLES_PER_CHANNEL
//	=======	=================	========	========	==================	================	=======================
//		0							0							0			2.5 KHz					N/A							4000										10							
//
//		0							0							1				N/A						N/A							N/A											N/A   					
//		0							1							0				N/A						N/A							N/A											N/A   					
//		0							1							1				N/A						N/A							N/A											N/A   
//
//		1							0							0			5.0 KHz					10							2000										10							
//		1							0							1			5.0 KHz					10							2000										10							
//		1							1							0			5.0 KHz					20							4000										20							
//		1							1							1			5.0 KHz					20							4000										20							
//

//////////////////////////////////////////////////////
//	GIX 309 options
//////////////////////////////////////////////////////
#define	GIX_300		(1)

	#if		defined(GIX_300)
#define	GIX_300_AT_250_HZ	(1)
//#define	DUAL_GIX	(1)
	#endif

//////////////////////////////////////////////////////
//	ADC options for '446 ADC Linearization
//////////////////////////////////////////////////////
#define PBT_LINEARIZATION_TYPE	(6)

#define	lin_table	CD.ADC_linearization_table

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...

//////////////////////////////////////////////////////
//	GIX_200 Options
//////////////////////////////////////////////////////
#if		((not	defined(GIX_300)	)	or	defined(DUAL_GIX)	)
#define	ZRU_ALG_3	(1)
//#define	OLD_ZRU_TEST	(1)		//Debug comparison testing only
#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////
//	GYRO HW Option
///////////////////////////////////////////////////////////////////////////////////////////////////////

#define	ENABLE_5_HZ_SINGLE_POLE_GYRO	(1)

#define	LSM6DS3	(1)
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp
#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	ENABLE_SPI_GYRO	(1)
//#define	FASTER_SPI	(1)

#define	FORCE_DIGITAL_GYRO	(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO
//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
#define	NO_ANALOG_GYROS	(1)
#define	NO_A2_TB	(1)

#define	MB_GYRO	(1)		//	redundant, above
//#define	A1_GYRO	(1)
	#if		not	defined(NO_A2_TB)
//#define	A2_GYRO	(1)
	#endif

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

//#define	ENABLE_SPI_MAG	(1)
#define	NO_MAGS	(1)
#define	F4_BUILD	(1)

//============================
#elif		defined(SQ_GIX_2020)
//============================
#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.
#define ENABLE_CODE_PROTECTION_COMMAND  (1)

//---------------------------------------------------------------------------------------------------------
//	Need the following two defines:
//---------------------------------------------------------------------------------------------------------
	#if		001		//	DEBUG STUFF: start spewing on start without a Time Sync Master
//#define	FORCE_VIN_GOOD	(1)		//	For debugging P/S Brownout issues only!!!
//#define	TRIMBLE_DO_NOT_REQUIRE_TIME_SYNC_MASTER	(1)
//#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
	#endif
//---------------------------------------------------------------------------------------------------------

#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate

//---------------------------------------------------------------------------------------------------------
//	==========================
//	'Options' 'C/C++' Options:
//	==========================
//	105 version:	STM32F10X_CL CMSIS_3_5_0 HSE_VALUE=16000000
//	446 version:	STM32F427_437xx HSE_VALUE=16000000 PLL_M=16 USE_STDPERIPH_DRIVER __FPU_PRESENT
//#define	SQ_GIX_0255	(1)		//Remember to increment FWBUILD		//	Based on SQ_CST_0343 and SQ_GIX_0249, and without CAN Termination
////////#define	MA_0219	(1)	//	GEN III but with a STM32F105 instead of a STM32F446
//---------------------------------------------------------------------------------------------------------

#define	GIX_300_STATUS_MESSAGE	(1)	//	Generate MSGID_DB_1  Diagnostic message @ ~1 Hz  [64 bit Error bit Vector]
//#define GIX_300_Ra_MESSAGE      (1) //  Generate MSG PGN FFA2 containing Ra Noise Measurement diagnostics.

//	NOTE: GIX-300 will not currently run on '105 @ 72 MHZ
//#if		not	defined(RUN_446_AT_72_MHZ)
//	ERROR!!!	"RUN_446_AT_72_MHZ" must be defined in the PreProcessor Symbols int the C/C++ Options Menu !!!
//#define	RUN_446_AT_72_MHZ	(1)	//	!!! MAKE SURE THIS IS PREDEFINED !!! [Should get macro redefined error here if it is.]
//#endif

#define	TRIMBLE_EXTENDED_STATUS_BITS	(1)
#define	ENHANCED_STATUS_BITS	(1)
#define	ENABLE_DTC_FAULTS	(1)
//#define	ENABLE_DTC_FAULT_VECTOR_MESSAGE	(1)

//#define	ENABLE_CAN_INTERRUPT_FOR_OLD_DRIVER	(1)		//	ENABLE for faster CAN TX messaging.

//	Valid Combinations for GIX-300 and GIX-200
//																										[DEPTH of]			[1/MAINLOOP_RATE]
//	GIX_300	GIX_300_AT_250_HZ	DUAL_GIX	ISR (Hz)	&Buffer_Accel_5KHz	TS_Period (uSec)	ADC_SAMPLES_PER_CHANNEL
//	=======	=================	========	========	==================	================	=======================
//		0							0							0			2.5 KHz					N/A							4000										10							
//
//		0							0							1				N/A						N/A							N/A											N/A   					
//		0							1							0				N/A						N/A							N/A											N/A   					
//		0							1							1				N/A						N/A							N/A											N/A   
//
//		1							0							0			5.0 KHz					10							2000										10							
//		1							0							1			5.0 KHz					10							2000										10							
//		1							1							0			5.0 KHz					20							4000										20							
//		1							1							1			5.0 KHz					20							4000										20							
//

//////////////////////////////////////////////////////
//	GIX 309 options
//////////////////////////////////////////////////////
#define	GIX_300		(1)

	#if		defined(GIX_300)
#define	GIX_300_AT_250_HZ	(1)
//#define	DUAL_GIX	(1)
	#endif

//////////////////////////////////////////////////////
//	ADC options for '446 ADC Linearization
//////////////////////////////////////////////////////
#define PBT_LINEARIZATION_TYPE	(6)

#define	lin_table	CD.ADC_linearization_table

#define	GROUNDED_ADC_CHANNEL	(1)
#define	SKIP_ADC_CHANNELS	(1)
#define	DOUBLE_ADC_CHANNELS	(1)	//	NOTE: currently requires SKIP_ADC_CHANNELS also...

//#define SCAN_TEST	(1)
//#define	FORCE_R11	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)


//////////////////////////////////////////////////////
//	GIX_200 Options
//////////////////////////////////////////////////////
#define	ZRU_ALG_3	(1)
//#define	OLD_ZRU_TEST	(1)		//Debug comparison testing only
#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)

///////////////////////////////////////////////////////////////////////////////////////////////////////
//	GYRO HW Option
///////////////////////////////////////////////////////////////////////////////////////////////////////
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp
#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	ENABLE_SPI_GYRO	(1)
//#define	FORCE_DIGITAL_GYRO	(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO
//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
//#define	NO_ANALOG_GYROS	(1)
#define	NO_A2_TB	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	BACKUP_CD_STRUCT	(1)		//	Now valid for both 'F446 and 'F105 memory map, not yet for 'F303/405, may not work for 'F103 or 'F101, needs review.
//#define	FASTER_SPI	(1)

//#define	ENABLE_SPI_MAG	(1)
#define	NO_MAGS	(1)
#define		F4_BUILD	(1)


///////////////////////////////////////////////////////////////////////////////////////////////////////
//	DEBUG BUILD
///////////////////////////////////////////////////////////////////////////////////////////////////////
	#if		0001	//	Enable Here for Customer Facing build
///////////////////////////////////////////////////////////////////////////////////////////////////////
	//	...
///////////////////////////////////////////////////////////////////////////////////////////////////////
	#else		//	!=0001	//	Here for 1000 kBaud Debug build
///////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
	#endif	//	0001
///////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	#if		001
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define	ENHANCED_STATUS_BITS	(1)		//	redundant, above
#define	ENABLE_5_HZ_SINGLE_POLE_GYRO	(1)

#define	ZRU_ALG_3	(1)			//	redundant, above
#define	HARD_LIMITS_FOR_BIAS_TRIM	(1)				//	redundant, above
#define	TRIMBLE_MESSAGE_SENT_DETECTION	(1)	

#define	FORCE_DIGITAL_GYRO	(1)		//	intended to be mutually exclusive with FORCE_ANALOG_GYRO
//#define	FORCE_ANALOG_GYRO		(1)		//	intended to be mutually exclusive with FORCE_DIGITAL_GYRO
#define	NO_ANALOG_GYROS	(1)
#define	NO_A2_TB	(1)

//#define	TRIMBLE_DO_NOT_REQUIRE_TIME_SYNC_MASTER	(1)
//#define	ENABLE_TRIMBLE_MSGID_D	(1)

//#define	DEFEAT_GIX_BIAS_TRIM	(1)

#define	TRIMBLE_ODR_MESSAGE_INTERLOCK	(1)
#define	BIAS_WALK_LIMIT_DUAL	(1)		//??? isn't this single gyro?

//#define	FASTER_SPI	(1)
////use dual scheme	#define	BIAS_WALK_LIMIT		(15.0)	/* deg/sec */
//#define	TRIMBLE_BREAK_J1939_MESSAGE_LENGTH	(1)		//	REMOVE THIS FEATURE

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#define	BACKUP_CD_STRUCT	(1)		//	Only valid for 'F105 memory map at present, needs tweak up for 'F446 or 'F303.

#define	DEFEAT_TRIMBLE_SAMPLING_WARP	(1)
#define SCAN_TEST	(1)
//#define	FORCE_R11	(1)
//#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)
//#define	HALT_TEST	(1)

		#if		000	//	SPI GYRO TEST code
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
//#define	TRIMBLE_TRIPLE_FP_MESSAGES	(1)
		#else
			#if		000		//DEBUG and FP messages
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	DEFEAT_TRIMBLE_FREQUENCY_LOCK	(1)		//	redundant with IGNORE_TRIMBLE_TIME_SYNC ???
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_DEBUG	(1)	//Bias and 'R' messages
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
#define	TRIMBLE_TRIPLE_FP_MESSAGES	(1)
			#else
				#if		000		//	test only, don't ship	//	Test code for Variance
#define	DEBUG_ONLINE_VARIANCE	(1)		//	Do not ship with this on.
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
				#else
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate
				#endif
			#endif
		#endif
//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

#define	ENABLE_SPI_GYRO	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)		//	redundant, above
//#define	A1_GYRO	(1)
//#define	A2_GYRO	(1)

#define	LSM6DS3	(1)		//	redundant, above

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)
//#define		GIX300		(1)		//	Older GIX300, deprecated
//no F4 on MA_0192_105_TEST HW or on MA_0219	/*#define		F4_BUILD	(1)*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	#else	//	old, never functional
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define SCAN_TEST	(1)
#define	FORCE_R11	(1)
//#define	SWAP_ADC_X_Y_ORDER	(1)
#define	DEFEAT_GIX_BIAS_TRIM	(1)
//#define	HALT_TEST	(1)
#define TRIMBLE_TRANSMIT_AT_START	(1)
#define	DEFEAT_TRIMBLE_FREQUENCY_LOCK	(1)		//	redundant with IGNORE_TRIMBLE_TIME_SYNC ???
#define	ENABLE_TRIPLE_GYRO_MESSAGES	(1)		//	Only Triple if all of MB_GYRO, A1_GYRO and A2_GYRO are defined.
#define	TRIMBLE_DEBUG	(1)	//Bias and 'R' messages [not true]
#define	TRIMBLE_250_HZ	(1)	//		Overide 40 Hz rate with a 250 Hz rate

//See (search) also: #define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		DISABLE_GYRO_MESSAGE_DECIMATION	(1)
//#define		JLM_GYRO_TEST	(1)

#define	GYRO_SELECT	CAN_Protocol	//	Use CD.CAN_Protocol to hold CD.GYRO_SELECT
#define	DUAL_GYRO	(1)		//	Will put MB SPI Gyro into HIG channel and use MCU Temp sensor.	//!!!not to be confused with ENABLE_DUAL_GYRO	//	Enable both Analog and SPI Gyro, store SPI Gyro Calibrations in HIG slot, likewise for Temp. Comp

#define	ENABLE_SPI_GYRO	(1)

////////	Do not ENABLE_SPI_GYRO_TEMP_COMP or  USE_MCU_FOR_SPI_GYRO_TEMP_COMP, only applies for non DUAL_GYRO [Check this note!!!]
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)
//////#define	USE_MCU_FOR_SPI_GYRO_TEMP_COMP	(1)		//	NOTE: ENABLE_SPI_GYRO_TEMP_COMP must be defined also.

#define	MB_GYRO	(1)
#define	A1_GYRO	(1)
#define	A2_GYRO	(1)

#define	LSM6DS3	(1)

//#define	ENABLE_SPI_MAG	(1)		
#define	NO_MAGS	(1)
//#define		GIX300		(1)		(1)	//	Older GIX300, deprecated
#define		F4_BUILD	(1)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	#endif
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//============================
#else
//============================
#define	NO_MAGS	(1)
//============================
#endif
//============================

#if		defined(F4_BUILD)
#define	ARM_MATH_CM4	(1)
#else
#define	ARM_MATH_CM3	(1)
#endif

#if		(defined(ARM_MATH_CM3)	or	defined(ARM_MATH_CM4)	)	//000	//not	defined(SCATTER_FILE)
#include	<arm_math.h>
#endif		//	not	defined(SCATTER_FILE)

//#include "SQSysConfig.h"

#if		(defined(SQ_GIX_0249)	or	defined(SQ_GIX_0255)	or	defined(SQ_GIX_0286)	or	defined(SQ_GIX_2020)	or	defined(SQ_GIX_2024)	)
#define	J1939_STACK	(1)
////#define	REWRITE_BOOTLOADER	(1)		//	Only applies to SQ_GIX_0249 [and possibly SQ_GIX_0255 or SQ_GIX_0298]

//Use CD.Ortho[1].xfactor to hold Trimble_Identity
#define	Trimble_Identity	(*((uint32_t	*)(&CD.Ortho[1].xfactor)))	//(*((unsigned long	*)(&CD.Ortho[1].xfactor)))
#endif

#if		defined(SQ_CST_0325)
#define	ENABLE_SPI_MAG	(1)
#endif

#if		(defined(SQ_CST_0331)	or	defined(SQ_CST_0325)	)
#define	DISABLE_Z_AXIS_SIGN	(1)
#endif

#if		001

#define	NEW_ADC_CAL			(1)	//	Newer ADC calibration in light of recent Reference Manual changes as of June 2014  [also define NO_ADC_CAL]
//#define	NO_ADC_CAL			(1)	//	define to disable ADC calibration
//NOTE: !!!bug: must have both ONE_BIT_OFFSET & PTRIPPETT defined.  With only ONE_BIT_OFFSET defined you get strange Accel offsets, need to chase this down.
#define	ONE_BIT_OFFSET	(1)	//	enable 1 bit Offset code for ADC readings.
#define	PTRIPPETT				(1)	//	enables Peter's new code in ADC_ReZero_FSM()
#define INTERPOLATE_TEMP_COMP (1) // enables interpolated temperature compensation

//Is the following necesary for Temp Comp runs?  I think so...
#define WRITE_OLD_TEMP_TABLE   (1) // Writes old temperature table during Temp Comp. calibration

#else

//#define	FARROW	(1)		//	Enable Farrow/Newton SPI GYRO ASRC interpolator.
#define	NEW_ADC_CAL			(1)	//	Newer ADC calibration in light of recent Reference Manual changes as of June 2014  [also define NO_ADC_CAL]
//#define	NO_ADC_CAL			(1)	//	define to disable ADC calibration
//NOTE: !!!bug: must have both ONE_BIT_OFFSET & PTRIPPETT defined.  With only ONE_BIT_OFFSET defined you get strange Accel offsets, need to chase this down.
#define	ONE_BIT_OFFSET	(1)	//	enable 1 bit Offset code for ADC readings.
#define	PTRIPPETT				(1)	//	enables Peter's new code in ADC_ReZero_FSM()
#define INTERPOLATE_TEMP_COMP (1) // enables interpolated temperature compensation
//#define RAW_TEMPERATURE_AND_VOLTAGE (1) // in test message 4
//#define WRITE_TEMPCOMP_TABLE (1) // NOTE:  Overwrites any existing Temp Comp data!!!	Write tempco data that is in the header file caldata_xxxxxxxx.h 
#define WRITE_OLD_TEMP_TABLE   (1) // Writes old temperature table during Temp Comp. calibration
//#define	TEMP_COMP_FUNCTION	(1)

#endif

#define	PERSISTENT_DR		(CD.Ortho[0].xfactor)

//**************************************************************************************************************
//	Enable Code Protection:	Build an image that explicitly Enables Code Protection  (RDP aka Read Data Protection)
//**************************************************************************************************************
//	NOTE:  Normally choose one or the other of these, ENABLE_CODE_PROTECTION_COMMAND is preferred.
//#define	ENABLE_CODE_PROTECTION	(1)
//Not here: Do on a build by build basis...	#define ENABLE_CODE_PROTECTION_COMMAND  (1)
#define CODE_PROTECTION_COMMAND_IN_TEST_MODE (1)  // Also set this to enable a standard command in test mode to lock code.  This should be used on all future builds.
//**************************************************************************************************************

//**************************************************************************************************************
//	Disable Code Protection:	Build Boot loadable image that explicitly Disables Code Protection
//**************************************************************************************************************
//	NOTE:	DON'T DO THIS ON A POTTED UNIT: It wipes the Boot Loader and everything else.
//**************************************************************************************************************
////#define	DISABLE_CODE_PROTECTION	(1)
//**************************************************************************************************************

#if		(defined(SQ_GIX_0302)	)
#define	GIX_300		(1)
#define	GIX_BUILD	(1)
#elif	(defined(SQ_GIX_200)	or	defined(SQ_GIX_0206)	or	defined(SQ_GIX_0102)	or	defined(SQ_GIX_0103)	or	defined(SQ_GIX_0104)	or	defined(SQ_GIX_0207)	or	defined(SQ_GIX_0208)		or	defined(SQ_GIX_0210)	or	defined(SQ_GIX_0211)	or	defined(SQ_GIX_0212)	or	defined(SQ_GIX_0213)	or	defined(SQ_GIX_0214)	or	defined(SQ_GIX_0221)	or	defined(SQ_GIX_0107)	or	defined(SQ_GIX_0222)	or	defined(SQ_GIX_0223)	or	defined(SQ_GIX_0220)	or	defined(SQ_GIX_0108)	or	defined(SQ_GIX_0109)	or	defined(SQ_GIX_0224)	or	defined(SQ_GIX_0225)	or	defined(SQ_GIX_0226)	or	defined(SQ_GIX_0021)	or	defined(SQ_GIX_0229)	or	defined(SQ_GIX_0230)	or	defined(SQ_GIX_0022)	or	defined(SQ_GIX_0232)	or	defined(SQ_GIX_0209)	or	defined(SQ_GIX_0234)	or	defined(SQ_GIX_0110)	or	defined(SQ_GIX_0111)	or	defined(SQ_GIX_0112)	or	defined(SQ_GIX_0113)	or	defined(SQ_GIX_0114)	or	defined(SQ_GIX_0215)	or	defined(SQ_GIX_0216)	or	defined(SQ_GIX_0218)	or	defined(SQ_JSN_0111)	or	defined(SQ_JSN_0112)	or	defined(SQ_GIX_0238)	or	defined(SQ_GIX_0200)	or	defined(SPI_GYRO_TEST)	or	defined(SQ_JSN_0113)	or	defined(SQ_GIX_0241)	or	defined(SQ_GIX_0243)	or	defined(SQ_GIX_0118)	or	defined(SQ_GIX_0119)	or	defined(SQ_GIX_0236)	or	defined(SQ_CST_0340)	or	defined(SQ_GIX_0269)	or	defined(SQ_GIX_0271)	or	defined(SQ_GIX_0274)	or	defined(SQ_GIX_0120)	or	defined(SQ_GIX_0121)	or	defined(SQ_GIX_0236)	or	defined(SQ_GIX_0249)	or	defined(SQ_GIX_0219)	or	defined(SQ_CST_0342)	or	defined(SQ_CST_0343)	or	defined(SQ_GIX_0255)	or	defined(SQ_GIX_0286)	or	defined(SQ_GIX_0272)	or	defined(SQ_GIX_0270)	or	defined(SQ_GIX_0273)	or	defined(SQ_GIX_0261)	or	defined(SQ_GIX_0289)  or  defined(SQ_GIX_0290_to_7)  or  defined(SQ_GIX_0299)	or	defined(SQ_GIX_2001)	or  defined(SQ_GIX_0298)	or	defined(SQ_GIX_0272_F105)  or  defined(SQ_GIX_2003)	or	defined(SQ_GIX_2002)	or	defined(SQ_GIX_2004)	or	defined(SQ_GIX_2005)  or  defined(SQ_GIX_2010)  or  defined(SQ_GIX_2011)  or  defined(SQ_GIX_2012)  or  defined(SQ_GIX_2013)	or	defined(SQ_GIX_2015)  or  defined(SQ_GIX_2014)	or	defined(SQ_GIX_2020)	or	defined(SQ_GIX_2024)	or  defined(SQ_GIX_0303)  or  defined(SQ_GIX_2017)  or  defined(SQ_GIX_2022)  or  defined(SQ_GIX_2026)  or  defined(SQ_GIX_2021)	or  defined(SQ_GIX_2019)	or	defined(SQ_GIX_2027)  or  defined(SQ_GIX_2023)	)

//	NOTE: This is implicitly a GIX 200 or GIX300 (deprecated) build.
#define	GIX_BUILD	(1)

#elif	(defined(SQ_RPS_0022)	or	defined(SQ_RPS_0026)	or	defined(SQ_RPS_0027)	or	defined(SQ_RPS_0028)	or	defined(SQ_RPS_0031)	or	defined(SQ_RPS_0032)	or	defined(SQ_RPS_0034)	or	defined(SQ_RPS_0038)	or	defined(SQ_RPS_0035)	or	defined(SQ_RPS_0036)	or	defined(GIX_THERMAL_TESTING)	or	defined(SQ_RPS_0052)	or	defined(SQ_RPS_0053)	or	defined(SQ_CST_0331)	or	defined(SQ_CST_0325)	or	defined(SQ_RPS_0054)	or	defined(SQ_RPS_0058)	or	defined(SQ_RPS_0059)	or	defined(SQ_RPS_0061)	or	defined(SQ_RPS_0063)  or  defined(SQ_RPS_0064)  or  defined(SQ_RPS_0065)	)

#define	NON_GIX_BUILD	(1)

#else
	ERROR: Build not properly defined.
#endif

//*********************************************************************************************


//*********************************************************************************************
//******	Choose HW Platform	*****************************************************************
//*********************************************************************************************

//---------------------------------------------------------------------------------------------
#if		defined(SQ_GIX_0261)  or  defined(SQ_GIX_0289)  or  defined(SQ_GIX_0272_F105)
//---------------------------------------------------------------------------------------------

#define	MA_0219	//	GEN III but with a STM32F105 instead of a STM32F446
	
//---------------------------------------------------------------------------------------------
#elif		defined(SQ_CST_0325)
//---------------------------------------------------------------------------------------------

//#define	MA_0130		(1)	//	currently uses 	Uses MC-1175 REV A, has magnetometer and hand wired mod's to support powering down the Accel's	//	[NOTE: Need Medium Line setup: define STM32F10X_MD instead of STM32F10X_HD and use startup_stm32f10x_md.s instead of startup_stm32f10x_hl.s]
#define	MA_0131		(1)	//	currently uses 	Uses MC-1181 REV 0, 	//	[NOTE: Need Medium Line setup: define STM32F10X_MD instead of STM32F10X_HD and use startup_stm32f10x_md.s instead of startup_stm32f10x_hl.s]

//---------------------------------------------------------------------------------------------
#elif		((defined(SQ_GIX_0255)	and	not	defined(SQ_GIX_0286)	)	or  defined(SQ_GIX_0290_to_7)	or	defined(SQ_GIX_2020)	or	defined(SQ_GIX_2024)	)
//---------------------------------------------------------------------------------------------

//#define	MA_0144		(1)	//	Uses MC-1191, new GIX II PCB Assembly, STM32F446 
//#define	MA_0166		(1)	//	Uses MC-1201, new GIX III PCB Assembly, STM32F446 
#define	MA_0192		(1)	//	Uses MC-1201, new GIX III PCB Assembly, STM32F446 
//#define	MA_0219		(1)	//	Uses MC-1201, new GIX III PCB Assembly, but with a STM32F105 instead of a STM32F446

//////DEPRECATED:
//////NOTE: that the following is defined twice to deal with some prcedence nonsense:	
//////#define	MA_0192_105_TEST		(1)	//	Uses MC-1201, new GIX III PCB Assembly, BUT WITH A STM32F105 instead of an STM32F446 

	#if		(defined(MA_0166)	or	defined(MA_0192)	or	defined(MA_0219)	or	defined(MA_0221)	)
	#else
		ERROR!!! No valid HW platform defined!
	#endif

//---------------------------------------------------------------------------------------------
#elif		(defined(SQ_GIX_2023)	)
//---------------------------------------------------------------------------------------------

#define MA_0286   (1)   //  Uses MC-1201, new GIX III PCB Assy, STM32F446 with PIXIO PCBA for RS-232/485 
  
  //---------------------------------------------------------------------------------------------
#elif		(defined(SQ_GIX_2022)	)
//---------------------------------------------------------------------------------------------
  
#define MA_0285   (1)   //  Uses MC-1201, new GIX III PCB Assy, STM32F446 with PIXIO PCBA for Analog Output only  

//---------------------------------------------------------------------------------------------
#elif		(defined(SQ_GIX_2003)  or  defined(SQ_GIX_2026)	)
//---------------------------------------------------------------------------------------------

#define	MA_0271		(1)		//	Uses MC-1201, new GIX III PCB Assembly, STM32F446, with PIXIO PCBA MA-0268 RS485 only

//---------------------------------------------------------------------------------------------
#elif		(not	defined(SQ_GIX_0286)	)	and	(defined(SQ_GIX_0255)	or	defined(SQ_RPS_0063)  or  defined(SQ_RPS_0064)  or  defined(SQ_RPS_0065) 	or	defined(SQ_GIX_0298)	or	defined(SQ_RPS_0063)	or	defined(SQ_GIX_0302)  or  defined(SQ_GIX_2003)  or  defined(SQ_GIX_2026)	or	defined(SQ_GIX_2019)	or	defined(SQ_GIX_2027)	or	defined(SQ_GIX_2020)	or	defined(SQ_GIX_2024)	)
//---------------------------------------------------------------------------------------------

//#define	MA_0144		(1)	//	Uses MC-1191, new GIX II PCB Assembly, STM32F446 
//#define	MA_0166		(1)	//	Uses MC-1201, new GIX III PCB Assembly, STM32F446 
#define	MA_0192		(1)	//	Uses MC-1201, new GIX III PCB Assembly, STM32F446 
//#define	MA_0219		(1)	//	Uses MC-1201, new GIX III PCB Assembly, but with a STM32F105 instead of a STM32F446

//////DEPRECATED:
//////NOTE: The following is defined twice to deal with some precedence nonsense:	
//////#define	MA_0192_105_TEST		(1)	//	Uses MC-1201, new GIX III PCB Assembly, BUT WITH A STM32F105 instead of an STM32F446 

	#if		(defined(MA_0166)	or	defined(MA_0192)	or	defined(MA_0219)	or	defined(MA_0221)	or	defined(MA_0271)  or  defined(MA_0285)  or  defined(MA_0286)	)
		//	...
	#else
		ERROR!!! No valid HW platform defined!
	#endif

//---------------------------------------------------------------------------------------------
#elif		(defined(SQ_GIX_0286)	or	defined(SQ_GIX_0302)	)
//---------------------------------------------------------------------------------------------

//#define	MA_0144		(1)	//	Uses MC-1191, new GIX II PCB Assembly, STM32F446 
//#define	MA_0166		(1)	//	Uses MC-1201, new GIX III PCB Assembly, STM32F446 
//#define	MA_0192		(1)	//	Uses MC-1201, new GIX III PCB Assembly, STM32F446 
#define	MA_0219		(1)	//	Uses MC-1201, new GIX III PCB Assembly, but with a STM32F105 instead of a STM32F446

//////DEPRECATED:
//////NOTE: that the following is defined twice to deal with some prcedence nonsense:	
//////#define	MA_0192_105_TEST		(1)	//	Uses MC-1201, new GIX III PCB Assembly, BUT WITH A STM32F105 instead of an STM32F446 

	#if		(defined(MA_0166)	or	defined(MA_0192)	or	defined(MA_0219)	or	defined(MA_0221)	or	defined(MA_0271)  or  defined(MA_0285)  or  defined(MA_0286)	)
	#else
		ERROR!!! No valid HW platform defined!
	#endif

//---------------------------------------------------------------------------------------------
#elif		(defined(SQ_CST_0342)	or	defined(SQ_CST_0343)	or	defined(SQ_RPS_0058)	or	defined(SQ_RPS_0059)	or	defined(SQ_GIX_0272)	or	defined(SQ_GIX_0270)  or  defined(SQ_GIX_0299)	or	defined(SQ_GIX_2001)	or	defined(SQ_GIX_2002)	or	defined(SQ_GIX_2004)	or	defined(SQ_GIX_2005)  or  defined(SQ_GIX_2010)  or  defined(SQ_GIX_2011)  or  defined(SQ_GIX_2012)  or  defined(SQ_GIX_2013)	or	defined(SQ_GIX_2015)  or  defined(SQ_GIX_2014)  or  defined(SQ_GIX_0303)  or  defined(SQ_GIX_2017)  or  defined(SQ_GIX_2022)	)
//---------------------------------------------------------------------------------------------

//#define	MA_0144		(1)	//	Uses MC-1191, new GIX II PCB Assembly, STM32F446 
#define	MA_0166		(1)	//	Uses MC-1201, new GIX III PCB Assembly, STM32F446 

//---------------------------------------------------------------------------------------------
#elif	defined(SQ_CST_0331)
//---------------------------------------------------------------------------------------------

//#define	MA_0127		(1)	//	currently uses 	Uses MC-1175 REV A	//	[NOTE: Need Medium Line setup: define STM32F10X_MD instead of STM32F10X_HD and use startup_stm32f10x_md.s instead of startup_stm32f10x_hl.s]
#define	MA_0134		(1)	//	currently uses 	Uses MC-1181 REV 0, 	//	[NOTE: Need Medium Line setup: define STM32F10X_MD instead of STM32F10X_HD and use startup_stm32f10x_md.s instead of startup_stm32f10x_hl.s]

//---------------------------------------------------------------------------------------------
#elif	(defined(SQ_RPS_0032)	or	defined(SQ_MAG_0001)	)
//---------------------------------------------------------------------------------------------

#define	SQ_MBL_HW	(1)					//	Build for latest (REV_B C?) MBL HW platform

// Make sure to define STM32F10X_HD and use startup_stm32f10x_hl.s		[MBL PCB is usually stuffed with the STM32F103RC or D or E]

//---------------------------------------------------------------------------------------------
#elif		(defined(SQ_GIX_0021)	or	defined(SQ_GIX_0022)	)
//---------------------------------------------------------------------------------------------

#define	SQ_ION_HW	(1)		//	currently uses SQ-ION REV D

//	Remember:
//
//	When switching hardware platforms, confirm the processor family.
//	For the ION build it is an STM32F103RB which is a "Medium Density", so:
//	- Adjust the predefined symbol from STM32F10X_CL to STM32F10X_MD
//	- Change Source files, use:
//		startup_stm32f10x_md.s instead of startup_stm32f10x_cl.s

//---------------------------------------------------------------------------------------------
#else
//---------------------------------------------------------------------------------------------

//#define	SQ_MBL_HW_REV_A	(1)		//	Build for older REV MBL_HW platform
//#define	SQ_MBL_HW_REV_B	(1)		//	Build for older REV MBL_HW platform
//#define	SQ_MBL_HW	(1)					//	Build for latest (REV_B C?) MBL HW platform

//Subvariants for SQ_MBL_HW:
// For first version of GIX-200 HW (prototype):
// Gyro X axis is -Roll
// Gyro Y axis is -Pitch
// Gyro Z axis is -Yaw

//#define	MA_0069_HW	// 	SQ_MBL_HW Variant, MA-0069	Main PCB, Populated, GIX, CRM200, SPI Module
//#define	MA_0070_HW	// 	SQ_MBL_HW Variant, MA-0070	Main PCB, Populated, GIX, CRM200, Module
//#define	MA_0071_HW	// 	SQ_MBL_HW Variant, MA-0071	Main PCB, Populated, GIX, TBD, Module

//  - Connectivity line devices are STM32F105xx and STM32F107xx microcontrollers.

// MA_0083	is normally stuffed with an STM32F105RB, which is a connectivity line MCU.
// Make sure to:
// - use the sartup_stm32f10x_CL.s file
// - define STM32F10X_CL in the C/C++ precompile defines
// - set Device to STM32F105RB
//NOTE:	MA_0083 (or MA_0092 or MA-????)  replaces incorrect: #define	MC_1144	(1)		//	Newer GIX platform, CAN2, etc.
//NOTE:	MA_0083 also applies to (most if not all) MA_0092 builds. [At presentl there is no reason for them to differ.]
//#define	MA_0083_REV_A	(1)	//	deprecated	Uses MC-1144 REV A
//#define	MA_0083_REV_B	(1)	//	deprecated	Uses MC-1144 REV B
#define	MA_0083		(1)	//	currently uses 	Uses MC-1144 REV C	//	[NOTE: Need Connectivity Line setup: define STM32F10X_CL instead of STM32F10X_HD and use startup_stm32f10x_cl.s instead of startup_stm32f10x_hl.s]	New Gix HW platform, CAN1

//---------------------------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------------------------

//*********************************************************************************************
//******	Choose Accelerometers and Gyros on HW Platform	*****************************************************************
//*********************************************************************************************

#if			(defined(SQ_GIX_0021)	or	defined(SQ_GIX_0022)	or	defined(SQ_GIX_0232)	or	defined(SQ_GIX_0234)	or	defined(SQ_GIX_0110)	or	defined(SQ_GIX_0111)	or	defined(SQ_GIX_0112)	or	defined(SQ_GIX_0113)	or	defined(SQ_GIX_0114)	or	defined(SQ_MAG_0001)  or  defined(SQ_GIX_0298)	)
/* 1.7g */
#define	LOG_ADXL203		(1)
#elif		(defined(SQ_RPS_0038)	or	defined(SQ_RPS_0052)	or	defined(SQ_RPS_0053)	or	defined(SQ_RPS_0058)	or	defined(SQ_RPS_0059)	or	defined(SQ_RPS_0063)  or  defined(SQ_RPS_0064)	)
/* 5g */
#define	LOG_ADXL22293	(1)
#elif		(defined(SQ_GIX_0223)	or	defined(SQ_GIX_0120)	or	defined(SQ_GIX_0121)	or	defined(SQ_GIX_0294)	or	defined(SQ_GIX_0295)	or	defined(SQ_GIX_0296)	or	defined(SQ_GIX_0297)  or  defined(SQ_RPS_0065)	)
/* 18g */
#define	LOG_ADXL22037	(1)
#elif		defined(GIX_BUILD)
/* 5g */
#define	LOG_ADXL22293	(1)
#elif	defined(NON_GIX_BUILD)
/* 1.7g */
#define	LOG_ADXL203		(1)
#else
	Error! LOG Accel type not defined.
#endif

//******************************************************************************************
//******** For GIX300 algorithm, set ACCEL_SATURATION_THRESHOLD based on accelerometer used
//******************************************************************************************

#if defined(LOG_ADXL203)
  #define ACCEL_SATURATION_THRESHOLD  (1.36f)   // 80% of 1.7g
#elif defined(LOG_ADXL22293)
  #define ACCEL_SATURATION_THRESHOLD  (4.00f)   // 80% of 5g
#elif defined(LOG_ADXL22037)
  #define ACCEL_SATURATION_THRESHOLD  (14.4f)   // 80% of 18g
#else
  #error "LOG Accel saturation threshold cannot be determined"
#endif
  
// #define	HIG_ADXL203		(1)
// #define	HIG_ADXL22293	(1)
// #define	HIG_LIS344ALH	(1)

#if		defined(F4_BUILD)		//	no SPI for now...
#define	GYRO_CRM100			(1)		//	Also CRM200
#elif		(defined(SQ_CST_0340)	)
#define	ENABLE_DUAL_GYRO	(1)		//	NOTE: Uses MAG entries in Cal and MAG messaging.
#define	ENABLE_SPI_GYRO		(1)		//	LSM330DLC
#elif	defined(SQ_ION_HW)
#define	ENABLE_SPI_GYRO		(1)		//	L3GD20 or L3GD20H or LSM6DS0 or LSM6DS3
#elif	(defined(MA_0083)	)	//or	defined(MA_0144)	or	defined(MA_0166)	or	defined(MA_0192)	or	defined(MA_0271)  or  defined(MA_0285)  or  defined(MA_0286)	)
	#if		(defined(SPI_GYRO_TEST)	or	defined(SQ_JSN_0113)	or	defined(GIX_THERMAL_TESTING)	or	defined(SQ_RPS_0054)	or	defined(SQ_RPS_0061)	)
#define	ENABLE_SPI_GYRO		(1)		//	LSM330DLC
	#else
#define	GYRO_CRM100				(1)		//	Also CRM200
	#endif	
#else

// #define	GYRO_LPY430				(1)
// #define	GYRO_LPR530				(1)
#define	GYRO_CRM100				(1)		//	Also CRM200

#endif

#if		(defined(ENABLE_SPI_GYRO)	and	not	defined(DUAL_GYRO)	)	and	(defined(SQ_RPS_0054)	)
#define	ENABLE_SPI_GYRO_TEMP_COMP	(1)		//	???Should the definition of ENABLE_SPI_GYRO_TEMP_COMP  be in SQDefs.h and per product???
#endif

#if		defined(F4_BUILD)		//no SPI for now.

#elif	(defined(MA_0083)	or	defined(CMSIS_3_5_0)	or	defined(MA_0144)	or	defined(MA_0166)	or	defined(MA_0192)	or	defined(MA_0192_105_TEST)	or	defined(MA_0219)	or	defined(MA_0271)  or  defined(MA_0285)  or  defined(MA_0286)	)
	#if		not	(defined(SQ_GIX_0220)	or	defined(SQ_GIX_0246)	)
#define	ENABLE_SPI1	(1)

/* SysTick counter state */
#define SysTick_Counter_Disable        ((u32)0xFFFFFFFE)
#define SysTick_Counter_Enable         ((u32)0x00000001)
#define SysTick_Counter_Clear          ((u32)0x00000000)

	#endif
#endif


#if		(defined(MA_0083)	or	defined(MA_0144)	or	defined(MA_0166)	or	defined(MA_0192)	or	defined(MA_0192_105_TEST)	or	defined(MA_0219)	or	defined(MA_0271)  or  defined(MA_0285)  or  defined(MA_0286)	)

//#define	ADC_9MHZ	(1)

#define	ENABLE_SPI1	(1)

/* SysTick counter state */
#define SysTick_Counter_Disable        ((u32)0xFFFFFFFE)
#define SysTick_Counter_Enable         ((u32)0x00000001)
#define SysTick_Counter_Clear          ((u32)0x00000000)

#endif


//**********************************************************************************************
#if		001	//not	defined(SCATTER_FILE)
//**********************************************************************************************
#if		defined(F4_BUILD)	and	(defined(MA_0083)	or	defined(MA_0144)	or	defined(MA_0144)	or	defined(MA_0166)	or	defined(MA_0192)	or	defined(MA_0271)  or  defined(MA_0285)  or  defined(MA_0286)	)

#include 	"stm32f4xx_adc.h"
#include 	"stm32f4xx_can.h"
#include 	"stm32f4xx_gpio.h"
//#include 	"stm32f4xx_flash.h"
#include 	"stm32f4xx_rcc.h"
#include 	"stm32f4xx_tim.h"

/* PBT NOTE:  Not sure why F4 builds are listed in this #elif statement... */
#elif	(defined(MA_0083)	or	defined(SQ_RPS_0032)	or	defined(SQ_ION_HW)	or	defined(MA_0127)	or	defined(MA_0130)	or	defined(MA_0131)	or	defined(MA_0134)or	defined(SQ_MAG_0001)	or	defined(MA_0144)	or	defined(MA_0166)	or	defined(MA_0192)	or	defined(MA_0192_105_TEST)	or	defined(MA_0219)	or	defined(MA_0271)  or  defined(MA_0285)  or  defined(MA_0286)	)

//#include	"core_cm3.h"

#include 	"stm32f10x_adc.h"
#include 	"stm32f10x_can.h"
#include 	"stm32f10x_gpio.h"
#include 	"stm32f10x_flash.h"
#include 	"stm32f10x_rcc.h"
#include 	"stm32f10x_tim.h"

//	For legacy definitions, include legacy header

//#include	"stm32f10x_type.h"

#else

#include "stm32f10x_lib.h"

#endif
//**********************************************************************************************
#endif		//	not	defined(SCATTER_FILE)
//**********************************************************************************************


//*********************************************************************************************
//******	Choose SPI Device Options (if applicable) ********************************************
//*********************************************************************************************
#if		001	//	Move this block here from SQ_SPI.h
	#if		(defined(MA_0130)	or	defined(MA_0131)	or	defined(MA_0134)	)
		#if		(defined(SQ_CST_0325)	)
#define	ENABLE_SPI1	(1)
//#define	ENABLE_SPI2	(1)
//#define	ENABLE_SPI2_SLAVE	(1)
//#define	ENABLE_SPI_GYRO	(1)
		#elif	(defined(SQ_CST_0331)	)
#define	ENABLE_SPI1	(1)
#define	ENABLE_SPI2	(1)
#define	ENABLE_SPI2_SLAVE	(1)
//#define	ENABLE_SPI_GYRO	(1)
		#endif
	#elif	(defined(MA_0127)	)
		#if		(defined(SQ_CST_0331)	)
#define	ENABLE_SPI1	(1)
#define	ENABLE_SPI2	(1)
#define	ENABLE_SPI2_SLAVE	(1)
//#define	ENABLE_SPI_GYRO	(1)
		#endif
	#elif	defined(ENABLE_SPI_GYRO)	//defined(SQ_ION_HW)
#define	ENABLE_SPI1	(1)
	#elif		(defined(SQ_MBL_HW)	or	defined(MA_0069_HW)		or	defined(MA_0070_HW)		or	defined(MA_0071_HW)	)
#define	ENABLE_SPI1	(1)
	#elif	(defined(MA_0083)	or	defined(MA_0144)	or	defined(MA_0166)	or	defined(MA_0192)	or	defined(MA_0192_105_TEST)	or	defined(MA_0219)	or	defined(MA_0271)  or  defined(MA_0285)  or  defined(MA_0286)	)
#define	ENABLE_SPI1	(1)
	#elif	defined(HW_MBD_T)
#define	ENABLE_SPI1	(1)
	#else
#define	ENABLE_SPI2	(1)
	#endif

//#define	SPI_DUAL_VLUN	(1)		//	Enable for original Flash Daughter card with 2 Flash EEPROMs and logic stuffed
#define	SPI_QUAD_VLUN	(1)		//	Enable for either MBD (discrete GPIO chip selects) or new FDOT-DC Flash Daughter card with 4 SPI chip selects via '139 MUX on daughter card.  [2 Flash EEPROMs, SPI RTC and GPIO extension]

#endif


//*********************************************************************************************
//******	Choose Device Addressing (if applicable) ********************************************
//*********************************************************************************************
// //*********************************************************************************************
// #if		defined(GIX_BUILD)
// //*********************************************************************************************

	#if		defined(SQ_GIX_200)
#define	CAN_ADDRESS	(0xB1)		//	for SQ_GIX_200
#define	BOOTLOADER_CRC			(0x6C98)	//	not currently used, reference only.		//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_RPS_0022)
#define	CAN_ADDRESS	(0xA1)
	#elif	defined(SQ_RPS_0023)
#define	CAN_ADDRESS	(0xA2)
	#elif	defined(SQ_RPS_0024)
#define	CAN_ADDRESS	(0xA3)
	#elif	defined(SQ_RPS_0026)
#define	CAN_ADDRESS	(0xA1)
	#elif	defined(SQ_RPS_0027)
#define	CAN_ADDRESS	(0xA2)
	#elif	defined(SQ_RPS_0028)
#define	CAN_ADDRESS	(0xA3)
	#elif	defined(SQ_RPS_0031)
#define	CAN_ADDRESS	(0xA4)
	#elif	defined(SQ_RPS_0032)
#define	CAN_ADDRESS	(0xA3)		//	Could also be 0xA2 for SQ_RPS_0032, it ships in at least 2 versions...
#define	BOOTLOADER_CRC			(0x6C98)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC						(0x1793)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0206)
#define	CAN_ADDRESS	(0xB1)

#define	BOOTLOADER_CRC			(0x6C98)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
	#elif	defined(SQ_GIX_0102)
#define	CAN_ADDRESS	(0xA1)

#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x45EE)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0103)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x5003)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0104)
#define	CAN_ADDRESS	(0xA3)

#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x8BDD)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0207)
#define	CAN_ADDRESS	(0xA4)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x982B)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0208)
#define	CAN_ADDRESS	(0xB1)

#define	BOOTLOADER_CRC			(0x6C98)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
	#elif	defined(SQ_GIX_0210)
#define	CAN_ADDRESS	(0xB1)

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xD3EA)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0211)
#define	CAN_ADDRESS	(0xB5)

#define	BOOTLOADER_CRC			(0x6C98)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
	#elif	defined(SQ_GIX_0212)
#define	CAN_ADDRESS	(0xB4)

#define	BOOTLOADER_CRC			(0x6C98)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
	#elif	defined(SQ_GIX_0213)
#define	CAN_ADDRESS	(0xB6)

#define	BOOTLOADER_CRC			(0x6C98)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
	#elif	defined(SQ_GIX_0214)
#define	CAN_ADDRESS	(0xB3)

#define	BOOTLOADER_CRC			(0x6C98)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
	#elif	defined(SQ_GIX_0221)
#define	CAN_ADDRESS	(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC			(0x6C98)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
	#elif	defined(SQ_RPS_0034)
#define	CAN_ADDRESS	(0xA3)

#define	BOOTLOADER_CRC			(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC			(0x4EA6)		//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0107)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x1650)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0222)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x991E)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0223)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xCBB6)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0220)
#define	CAN_ADDRESS	(0xA2)	//(0x01)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x7545)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0108)

#define	GIX_SINGLE_AXIS	(1)
#define	CAN_ADDRESS	(0x02)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xD915)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0109)

#define	GIX_SINGLE_AXIS	(1)
#define	CAN_ADDRESS	(0x03)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xF0E5)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0224)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x33F8)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0225)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x5AC0)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_RPS_0038)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x863A)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0226)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xEABD)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_RPS_0035)
#define	CAN_ADDRESS	(0xA2)

#define	BOOTLOADER_CRC			(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC			(0xB1A8)		//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_RPS_0036)
#define	CAN_ADDRESS	(0xA1)

#define	BOOTLOADER_CRC			(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC			(0x2633)		//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0229)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x0CE9)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0230)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x5B4E)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(GIX_THERMAL_TESTING)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC				(0x5A63)		//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0021)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xEED0)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0022)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xEABD)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0232)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x7637)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x6877)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0209)
	
#define	TRADE_SHOW_MESSAGES	(1)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x7637)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xFC53)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.

	#elif	defined(SQ_GIX_0234)
#define	CAN_ADDRESS	(0xA0)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC				(0x0371)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0110)
#define	CAN_ADDRESS	(0xA3)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC				(0xA8DA)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0111)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC				(0x5808)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0112)
#define	CAN_ADDRESS	(0xA1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC				(0x7ACE)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0113)
#define	CAN_ADDRESS	(0xA3)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC				(0x8CAB)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0114)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC				(0x386E)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0215)
#define	CAN_ADDRESS	(0xB5)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xEC1B)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0216)
#define	CAN_ADDRESS	(0xB4)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x8D4F)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0218)
#define	CAN_ADDRESS	(0xB3)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xF73F)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_JSN_0111)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC				(0x57A1)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_JSN_0112)
#define	CAN_ADDRESS	(0xA1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC				(0x57A1)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_JSN_0234)
#define	CAN_ADDRESS	(0xA3)	//(0xA0)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC				(0x57A1)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0238)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xC570)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_RPS_0052)
#define	CAN_ADDRESS	(0xA2)

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC				(0x53E1)		//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_RPS_0053)
#define	CAN_ADDRESS	(0xA1)

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC				(0xF6B2)		//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0200)
#define	CAN_ADDRESS	(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x7637)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x46AF)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SPI_GYRO_TEST)
#define	CAN_ADDRESS	(0xB1)

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xD3EA)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_JSN_0113)
#define	CAN_ADDRESS	(0xA1)	//normal Bucket address, (was):(0xA2), but we're mounting with a bucket already there and using Boom address (0xA1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xDBA4)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0241)
#define	CAN_ADDRESS	(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x7637)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x9F6D)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_CST_0331)
#define	CAN_ADDRESS	(0xA3)

#define	BOOTLOADER_CRC	(0xDBFE)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC				(0xE5E7)		//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0243)
#define	CAN_ADDRESS	(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x7637)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x39C1)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0287)
#define	CAN_ADDRESS	(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x7637)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xAF64)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.

	#elif	defined(SQ_GIX_0246)
#define	CAN_ADDRESS	(0xA2)	//(0x01)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x0A53)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_CST_0325)
#define	CAN_ADDRESS	(0xA3)

#define	BOOTLOADER_CRC	(0x8335)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC				(0x6B8F)		//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_RPS_0054)
	
#define	ENABLE_50_HZ_SINGLE_POLE_ACCEL	(1)

#define	CAN_ADDRESS	(0xB1)

#define	BOOTLOADER_CRC	(0x7637)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xE92E)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0118)
#define	GIX_SINGLE_AXIS	(1)
#define	CAN_ADDRESS	(0x06) 

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC				(0x50E7)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
//#warning "Set CODE_CRC before release to production."
	#elif	defined(SQ_GIX_0119)
#define	GIX_SINGLE_AXIS	(1)
#define	CAN_ADDRESS	(0x0C) 

#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC				(0x43B8)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
//#warning "Set CODE_CRC before release to production."

	#elif	defined(SQ_GIX_0120)
#define	GIX_SINGLE_AXIS	(1)
#define	CAN_ADDRESS	(0x06) 

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x7637)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC				(0x7915)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0121)
#define	GIX_SINGLE_AXIS	(1)
#define	CAN_ADDRESS	(0x0C) 

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x7637)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.

#define	CODE_CRC				(0x0946)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0236)
#define	CAN_ADDRESS	(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xC727)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_CST_0340)
#define	CAN_ADDRESS	(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0xB9BA)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xD3EA)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0269)
#define	CAN_ADDRESS	(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x7637)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xA08B)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0271)
#define	CAN_ADDRESS	(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0x7637)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xB8CD)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0274)
#define	CAN_ADDRESS	(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x7637)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x306C)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0249)
#define	CAN_ADDRESS	(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0x9928)	//Boot_Loader_CRC		not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xAF1E)	//ROM_Image_CRC			#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_CST_0342)
#define	CAN_ADDRESS	(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x05AC)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x46AF)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_CST_0343)
#define	CAN_ADDRESS	(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x05AC)	//	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x46AF)	//	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0272)
#define	J1939_PRIORITY	(0x03<<26)
		#if		defined(TRIPLE_FP_MESSAGES)
#define	CAN_ADDRESS	(0xB1)	//(0xB2)	//(0xE2)
		#else
#define	CAN_ADDRESS	(0xE2)
		#endif
#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xA11E)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0270)
#define	CAN_ADDRESS	(0xB2)	//(0xE2)

//#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x22EE)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x97E7)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_RPS_0058)
#define	CAN_ADDRESS	(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x22EE)	//Boot_Loader_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xBF7F)	//ROM_Image_CRC	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_RPS_0059)
#define	CAN_ADDRESS	(0xA1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x22EE)	//Boot_Loader_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xBEC4)	//ROM_Image_CRC	#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	(not	defined(SQ_GIX_0286)	)	and	defined(SQ_GIX_0255)
#define	CAN_ADDRESS	(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0xD85D)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
//	Remember to kick FWBUILD and/or FWVER
#define	CODE_CRC				(0x6C23)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0273)
#define	CAN_ADDRESS	(0xB2)	//(0xE2)

	//	The following belongs elsewhere...
#define	ENABLE_50_HZ_SINGLE_POLE_ACCEL	(1)
#define	ENABLE_50_HZ_SINGLE_POLE_GYRO		(1)
//#define	GIX_SINGLE_AXIS	(1)

	#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0x7637)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x24DC)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_RPS_0061)
//	The following belongs elsewhere...
#define	ENABLE_50_HZ_SINGLE_POLE_ACCEL	(1)
#define	CAN_ADDRESS	(0xB1)
#define	BOOTLOADER_CRC	(0xB9BA)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x786A)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0261)
#define	CAN_ADDRESS	(0xB1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0xED4D)	// Boot_Loader_CRC==BOOTLOADER_CRC		not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x78F4)	// ROM_Image_CRC==CODE_CRC						#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
//Prepot version	#define	CODE_CRC				(0x6C4A)	// ROM_Image_CRC==CODE_CRC						#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0289)
#define	CAN_ADDRESS	(0xB2)	//(0xE2)

//	The following belongs elsewhere...
//#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0xED4D)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x6A1E)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0290)
#define	CAN_ADDRESS	(0xA2)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x9462)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0291)
#define	CAN_ADDRESS	(0xA2)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x2097)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0292)
#define	CAN_ADDRESS	(0xA2)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xB78D)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0293)
#define	CAN_ADDRESS	(0xA2)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xF530)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0294)
#define	CAN_ADDRESS	(0xA2)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xC15E)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0295)
#define	CAN_ADDRESS	(0xA2)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x75AB)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0296)
#define	CAN_ADDRESS	(0xA2)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xE2B1)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0297)
#define	CAN_ADDRESS	(0xA2)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x9047)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0298)
#define	CAN_ADDRESS	(0xB1)	//(0xB2)	//(0xE2)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xB52B)	//(0xC078)?	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2023)
#define	CAN_ADDRESS	(0xB2)	//(0xB2)	//(0xE2)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xD8C7)	//(0xC078)?	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0272_F105)
#define	CAN_ADDRESS	(0xE2)

//	The following belongs elsewhere...
#define	GIX_SINGLE_AXIS	(1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0xED4D)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x77E4)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0286)
#define	CAN_ADDRESS	(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0xD85D)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
//	Remember to kick FWBUILD and/or FWVER & u8FirmwareVersion
#define	CODE_CRC				(0xB135)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2020)
#define	CAN_ADDRESS	(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
//	Remember to kick FWBUILD and/or FWVER
#define	CODE_CRC				(0xD70E)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_RPS_0063)
#define	CAN_ADDRESS	(0xA2)		//	Could also be 0xA2 for SQ_RPS_0032, it ships in at least 2 versions...
#define	BOOTLOADER_CRC			(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC						(0xC399)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_RPS_0064)
#define	CAN_ADDRESS	(0xA2)		//	Could also be 0xA2 for SQ_RPS_0032, it ships in at least 2 versions...
#define	BOOTLOADER_CRC			(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC						(0xA43E)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_RPS_0065)
#define	CAN_ADDRESS	(0x29)		//	Could also be 0xA2 for SQ_RPS_0032, it ships in at least 2 versions...
#define	BOOTLOADER_CRC			(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC						(0x2492)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0302)
#define	CAN_ADDRESS	(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0xD85D)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
//	Remember to kick FWBUILD and/or FWVER
#define	CODE_CRC				(0x2C8E)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
//    The following block can't possibly be included, look 19 lines above this one.
//	#elif	defined(SQ_RPS_0063)
//#define	CAN_ADDRESS	(0xA2)		//	Could also be 0xA2 for SQ_RPS_0032, it ships in at least 2 versions...
//#define	BOOTLOADER_CRC			(0x22EE)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
//#define	CODE_CRC						(0xE4AF)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0299)
#define	CAN_ADDRESS	(0xB2)	//(0xE2)

//	The following belongs elsewhere...
//#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x22EE)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x4FA4)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2001)
#define	CAN_ADDRESS	(0x0C)	//(0xE2)

//#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xCEB4)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	(not	defined(SQ_GIX_0302)	)	and	defined(SQ_GIX_0255)
#define	CAN_ADDRESS	(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0xD85D)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
//	Remember to kick FWBUILD and/or FWVER
#define	CODE_CRC				(0x6C23)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2003)
#define		F4_BUILD	(1)
#define	CAN_ADDRESS	(0xB1)	//(0xB2)	//(0xE2)

//	The following belongs elsewhere...
#define	ENABLE_I2C3	(1)				//	Need this to control MUX on PIX IO PCBA
#define	ENABLE_PIX_USART	(1)		//	Do not define for MODBUS_STACK???

//#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
  
#define MODBUS_DEFAULT_ID 0x01

#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xBECA)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2026)
#define		F4_BUILD	(1)
#define	CAN_ADDRESS	(0xB1)	//(0xB2)	//(0xE2)

//	The following belongs elsewhere...
#define	ENABLE_I2C3	(1)				//	Need this to control MUX on PIX IO PCBA
#define	ENABLE_PIX_USART	(1)		//	Do not define for MODBUS_STACK???

//#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
  
#define MODBUS_DEFAULT_ID 0x01

#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x1EF7)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2014)
#define	CAN_ADDRESS	(0x0A)	//(0xB2)	//(0xE2)

//#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x217A)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_0303)
#define	CAN_ADDRESS	(0x0A)	//(0xB2)	//(0xE2)

//#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xF82E)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2017)
#define	CAN_ADDRESS	(0x05)	//(0xB2)	//(0xE2)

//#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x59FD)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2002)
#define	CAN_ADDRESS	(0x0A)	//(0xB2)	//(0xE2)

//#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
//	update:	u8FirmwareVersion
#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xD903)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2004)
#define	CAN_ADDRESS	(0x0B)	//(0xB2)	//(0xE2)

//#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
//	update:	u8FirmwareVersion
#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xA695)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2005)
#define	CAN_ADDRESS	(0x0C)	//(0xB2)	//(0xE2)
//	update:	u8FirmwareVersion
//#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x3265)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2010)
#define	CAN_ADDRESS	(0xC3)	//(0xA3)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x2A6F)	//	Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xF6CE)	//	ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2013)
#define	CAN_ADDRESS	(0xC4)	//(0xA0)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x2A6F)	//	Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x8ACD)	//	ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2015)
#define	J1939_PRIORITY	(0x06<<26)
#define	CAN_ADDRESS	(0x01)	//(0xA0)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x2A6F)	//	Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x6C4F)	//	ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2011)
#define	CAN_ADDRESS	(0xC2)	//(0xA2)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x2A6F)	//	Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xB809)	//	ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2012)
#define	CAN_ADDRESS	(0xC1)	//(0xA1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */

#define	BOOTLOADER_CRC	(0x2A6F)	//	Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x0B02)	//	ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2022)
#define	CAN_ADDRESS	(0xB2)	//(0xB2)	//(0xE2)

//#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
//	update:	u8FirmwareVersion
#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0x95D7)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2019)
#define	CAN_ADDRESS	(0x11)	//(0x0A)	//(0x0B)	//(0xB2)	//(0xE2)

//#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
//	update:	u8FirmwareVersion
#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xD69C)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2027)
#define	CAN_ADDRESS	(0x11)	//(0x0A)	//(0x0B)	//(0xB2)	//(0xE2)

//#define	GIX_SINGLE_AXIS	(1)
#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
//	update:	u8FirmwareVersion
#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
#define	CODE_CRC				(0xD69C)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#elif	defined(SQ_GIX_2024)
#define	J1939_PRIORITY	(0x03)		//(0x03<<26)		//	Priority == 3
#define	CAN_ADDRESS	(0xE2)	//(0xB1)

#define	GIX_CENTRIPETAL_RADIUS_ESTIMATE	(6.0f)  /* [m] */
#define	BOOTLOADER_CRC	(0x2A6F)	// Boot_Loader_CRC==BOOTLOADER_CRC	not currently used, reference only.		Bootloader is included in CODE_CRC.
//	update:	u8FirmwareVersion
#define	CODE_CRC				(0xF4C3)	// ROM_Image_CRC==CODE_CRC					#define to enable CRC checking of Code in ROM, this also defines the CRC for Code in ROM.
	#else
#define	CAN_ADDRESS	(0xA1)
	#endif

//*********************************************************************************************


//*********************************************************************************************
//******	Choose Features	*********************************************************************
//*********************************************************************************************

//#define	TRADE_SHOW_MESSAGES	(1)		//	Additional Calibrated Accel and Gyro Messages for Trade Show

//#define	GIX_SINGLE_AXIS	(1)	//	!!!HACK !!!Need to add SQ_GIX_0100 build option instead


#if		(defined(SQ_GIX_0210)	or	defined(SQ_RPS_0034)	or	defined(SQ_GIX_0226)	or	defined(SQ_GIX_0209)	or	defined(SQ_GIX_0110)	or	defined(SQ_GIX_0113)	or	defined(SQ_GIX_0118)	or	defined(SQ_GIX_0119)	or	defined(SQ_GIX_0120)	or	defined(SQ_GIX_0121)	)
#define	FORCE_CAN_TERMINATOR_ON_BY_DEFAULT	(1)
#endif

#if		defined(GIX_BUILD)

//#define	BYPASS_CIC	(1)

#define	ENABLE_50_HZ_SINGLE_POLE_ACCEL	(1)
//#define	ENABLE_0_5_HZ_SINGLE_POLE_ACCEL	(1)
//#define	ENABLE_1_HZ_SINGLE_POLE_ACCEL		(1)
#define	ENABLE_2_HZ_SINGLE_POLE_ACCEL		(1)

#define	BYPASS_GYRO_FILTER	(1)
#define	BYPASS_GYRO_HPF_FILTER	(1)

#define	ENABLE_50_HZ_SINGLE_POLE_GYRO		(1)
//#define	ENABLE_5_HZ_SINGLE_POLE_GYRO		(1)

#endif

#if		defined(HALT_TEST)
#else
#define NO_HIG_ACCEL  (1)         	//  Use ADXL203/ADXL22293 for (nearly) all accel info, (no LIS344ALH)  [HIG still drives Raw stuff for Calibration and Temp. Comp., we switch at the calibrated level]
#endif

#define	ENABLE_SELF_TEST	(1)

//#define ENABLE_SELF_TEST_DIFFERENCING  (1)

#define	ENABLE_SELF_TEST_VIN_CHECK	(1)

//#define	PRODUCTION_TREF_UNIT	(1)		//	Define this to create an Oven Temperature Reference unit (needs to be calibrated though.)


//*********************************************************************************************
#if		(defined(MA_0127)	or	defined(MA_0130)	or	defined(MA_0131)	or	defined(MA_0134)	)
//*********************************************************************************************
#define USE_TB_Y_ACCEL_CHANNEL (1)	

	#if		(defined(MA_0131)	or	defined(MA_0134)	)
#define XL_ST_PORT       (GPIOB)      // Which port SNS_A_ST signal is on
#define XL_ST_PIN			   (GPIO_Pin_9)	// Which pin 	SNS_A_ST signal is on

#define TB_ST_PORT       (GPIOA)      // Which port SNS_A_TB_ST signal is on
#define TB_ST_PIN			   (GPIO_Pin_1)	// Which pin 	SNS_A_TB_ST signal is on
	#elif	defined(MA_0130)
#define XL_ST_PORT       (GPIOB)      // Which port SNS_A_ST signal is on
#define XL_ST_PIN			   (GPIO_Pin_7)	// Which pin 	SNS_A_ST signal is on

#define TB_ST_PORT       (GPIOA)      // Which port SNS_A_TB_ST signal is on
#define TB_ST_PIN			   (GPIO_Pin_1)	// Which pin 	SNS_A_TB_ST signal is on
	#elif	defined(MA_0127)
#define XL_ST_PORT       (GPIOB)      // Which port SNS_A_ST signal is on
#define XL_ST_PIN			   (GPIO_Pin_7)	// Which pin 	SNS_A_ST signal is on

#define TB_ST_PORT       (GPIOA)      // Which port SNS_A_TB_ST signal is on
#define TB_ST_PIN			   (GPIO_Pin_1)	// Which pin 	SNS_A_TB_ST signal is on
	#else
#warning XL_ST_PORT, XL_ST_PIN, TB_ST_PORT & TB_ST_PIN undefined.
	#endif

	#if		defined(SQ_CST_0331)

#define FWVER (0x08)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-CST-0331\0";
static const u8 u8FirmwareVersion[12] = "0.08       \0";

#define HWVER ('A')    // PCB Rev 
static const u8 u8HardwareVersion[12] = "MA-0127  A \0";	//	!!!Fixme: concatenate HWVER here.

	#elif		defined(SQ_CST_0325)

#define FWVER (0x08)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-CST-0325\0";
static const u8 u8FirmwareVersion[12] = "0.08       \0";

#define HWVER ('A')    // PCB Rev 
static const u8 u8HardwareVersion[12] = "MA-0127  A \0";	//	!!!Fixme: concatenate HWVER here.

	#else
	//	...
	#endif
//*********************************************************************************************
#elif	(defined(SQ_ION_HW)	)
//*********************************************************************************************
#define USE_TB_Y_ACCEL_CHANNEL (1)	

#define XL_ST_PORT       (GPIOA)      // Which port XL_ST signal is on
#define XL_ST_PIN			   (GPIO_Pin_1)	// Which pin XL_ST signal is on

	#if		defined(SQ_GIX_0021)

#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0021\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";

#define HWVER ('D')    // PCB Rev 
static const u8 u8HardwareVersion[12] = "SQ-ION   D \0";	//	!!!Fixme: concatenate HWVER here.

	#elif	defined(SQ_GIX_0022)

#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0022\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";

#define HWVER ('D')    // PCB Rev 
static const u8 u8HardwareVersion[12] = "SQ-ION   D \0";	//	!!!Fixme: concatenate HWVER here.

	#else
	//	...
	#endif
	
	
//*********************************************************************************************
#elif	(defined(SQ_MBL_HW)	or	defined(MA_0069_HW)		or	defined(MA_0070_HW)		or	defined(MA_0071_HW)	)
//*********************************************************************************************

#define USE_TB_Y_ACCEL_CHANNEL (1)	

//*********************************************************************************************
//#define	SQ_MBL_HW_REV_A	(1)		//	Build for older REV MBL_HW platform
//#define	SQ_MBL_HW_REV_B	(1)		//	Build for older REV MBL_HW platform

#define XL_ST_PORT       (GPIOC)        // Which port XL_ST signal is on
#define XL_ST_PIN			   (GPIO_Pin_13)  // Which pin XL_ST signal is on
	
	#if		not	(defined(SQ_RPS_0022)	or	defined(MA_0069_HW)		or	defined(MA_0070_HW)	or	defined(GIX_BUILD)	)
	
#define GY_ST_PORT       (GPIOB)
#define GY_ST_PIN        (GPIO_Pin_2)
	
	#endif

//*********************************************************************************************


//*********************************************************************************************
//******	Define System info   ****************************************************************
//*********************************************************************************************
// System Version Information

	#if		defined(SQ_GIX_200)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-GIX-0200\0";
static const u8 u8FirmwareVersion[12] = "0.01       \0";
	#elif	defined(SQ_RPS_0022)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-RPS-0022\0";
static const u8 u8FirmwareVersion[12] = "0.01.00    \0";
	#elif	defined(SQ_RPS_0026)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-RPS-0026\0";
static const u8 u8FirmwareVersion[12] = "0.01.00    \0";
	#elif	defined(SQ_RPS_0027)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-RPS-0027\0";
static const u8 u8FirmwareVersion[12] = "0.01.00    \0";
	#elif	defined(SQ_RPS_0028)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-RPS-0028\0";
static const u8 u8FirmwareVersion[12] = "0.01.00    \0";
	#elif	defined(SQ_RPS_0031)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-RPS-0031\0";
static const u8 u8FirmwareVersion[12] = "0.01.00    \0";
	#elif	defined(SQ_RPS_0032)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0032\0";
static const u8 u8FirmwareVersion[12] = "0.05.00    \0";
	#elif	defined(SQ_GIX_0206)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-GIX-0206\0";
static const u8 u8FirmwareVersion[12] = "0.01       \0";
	#elif	defined(SQ_GIX_0102)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0102\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif	defined(SQ_GIX_0103)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0103\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif	defined(SQ_GIX_0104)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0104\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif	defined(SQ_GIX_0207)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0207\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif	defined(SQ_GIX_0208)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-GIX-0208\0";
static const u8 u8FirmwareVersion[12] = "0.02       \0";
	#elif	defined(SQ_GIX_0210)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0210\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif	defined(SQ_GIX_0211)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-GIX-0211\0";
static const u8 u8FirmwareVersion[12] = "0.02       \0";
	#elif	defined(SQ_GIX_0212)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-GIX-0212\0";
static const u8 u8FirmwareVersion[12] = "0.02       \0";
	#elif	defined(SQ_GIX_0213)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-GIX-0213\0";
static const u8 u8FirmwareVersion[12] = "0.02       \0";
	#elif	defined(SQ_GIX_0214)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-GIX-0214\0";
static const u8 u8FirmwareVersion[12] = "0.02       \0";
	#elif	defined(SQ_GIX_0221)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-GIX-0221\0";
static const u8 u8FirmwareVersion[12] = "0.03       \0";	
	#elif	defined(SQ_RPS_0034)
static const u8 u8ProductName[12]     = "SQ-RPS-0034\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";	
	#elif	defined(SQ_GIX_0107)
#define FWVER (0x03)   // Version 0.03
static const u8 u8ProductName[12]     = "SQ-GIX-0107\0";
static const u8 u8FirmwareVersion[12] = "0.03       \0";
	#elif	defined(SQ_GIX_0222)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0222\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif	defined(SQ_GIX_0223)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0223\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif	defined(SQ_GIX_0220)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0220\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif	defined(SQ_GIX_0108)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0108\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif	defined(SQ_GIX_0109)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0109\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif	defined(SQ_GIX_0224)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0224\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif	defined(SQ_GIX_0225)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0225\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif	defined(SQ_RPS_0038)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-RPS-0038\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif	defined(SQ_GIX_0226)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0226\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif	defined(SQ_RPS_0035)
static const u8 u8ProductName[12]     = "SQ-RPS-0035\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";	
	#elif	defined(SQ_RPS_0036)
static const u8 u8ProductName[12]     = "SQ-RPS-0036\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";	
	#elif	defined(SQ_GIX_0229)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0229\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif	defined(SQ_GIX_0230)
#define FWVER (0x05)   // Version 0.05
static const u8 u8ProductName[12]     = "SQ-GIX-0230\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif	defined(GIX_THERMAL_TESTING)
static const u8 u8ProductName[12]     = "GIX_THERMAL\0";
static const u8 u8FirmwareVersion[12] = "0.07       \0";	
	#elif	defined(SQ_GIX_0232)
#define FWVER (0x05)   // Version 0.05
static const u8 u8ProductName[12]     = "SQ-GIX-0232\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif	defined(SQ_GIX_0209)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0209\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif	defined(SQ_GIX_0234)
static const u8 u8ProductName[12]     = "SQ-GIX-0234\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";	
	#elif	defined(SQ_GIX_0110)
static const u8 u8ProductName[12]     = "SQ-GIX-0110\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";	
	#elif	defined(SQ_GIX_0111)
static const u8 u8ProductName[12]     = "SQ-GIX-0111\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";	
	#elif	defined(SQ_GIX_0112)
static const u8 u8ProductName[12]     = "SQ-GIX-0112\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";	
	#elif	defined(SQ_GIX_0113)
static const u8 u8ProductName[12]     = "SQ-GIX-0113\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";	
	#elif	defined(SQ_MAG_0001)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-MAG-0001\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";	
	#elif	defined(SQ_GIX_0114)
static const u8 u8ProductName[12]     = "SQ-GIX-0114\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";	
	#elif	defined(SQ_GIX_0215)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0215\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif	defined(SQ_GIX_0216)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0216\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif	defined(SQ_GIX_0218)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0218\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif	defined(SQ_JSN_0111)
static const u8 u8ProductName[12]     = "SQ-JSN-0111\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";	
	#elif	defined(SQ_JSN_0112)
static const u8 u8ProductName[12]     = "SQ-JSN-0112\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";	
	#elif	defined(SQ_JSN_0234)
static const u8 u8ProductName[12]     = "SQ-JSN-0234\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";	
	#elif	defined(SQ_GIX_0238)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0238\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif	defined(SQ_RPS_0052)
static const u8 u8ProductName[12]     = "SQ-RPS-0052\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";	
	#elif	defined(SQ_RPS_0053)
static const u8 u8ProductName[12]     = "SQ-RPS-0053\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";	
	#elif		defined(SQ_GIX_0200)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0200\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";	
	#elif	defined(SPI_GYRO_TEST)
#define FWVER (0x06)   // Version 0.0n
static const u8 u8ProductName[12]     = "SPI_GYRO_00\0";
static const u8 u8FirmwareVersion[12] = "0.06       \0";
	#elif	defined(SQ_JSN_0113)
#define FWVER (0x07)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-JSN-0113\0";
static const u8 u8FirmwareVersion[12] = "0.07       \0";
	#elif	defined(SQ_GIX_0241)
#define FWVER (0x07)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0241\0";
static const u8 u8FirmwareVersion[12] = "0.07       \0";
	#elif	defined(SQ_GIX_0243)
#define FWVER (0x07)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0243\0";
static const u8 u8FirmwareVersion[12] = "0.07       \0";
	#elif		defined(SQ_GIX_0287)
#define FWVER (0x07)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0287\0";
static const u8 u8FirmwareVersion[12] = "20151028_A \0";
	#elif	defined(SQ_GIX_0246)
#define FWVER (0x07)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0246\0";
static const u8 u8FirmwareVersion[12] = "0.07       \0";
	#elif	defined(SQ_RPS_0054)
#define FWVER (0x09)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0054\0";
static const u8 u8FirmwareVersion[12] = "0.09       \0";
	#elif	defined(SQ_GIX_0118)
static const u8 u8ProductName[12]     = "SQ-GIX-0118\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif	defined(SQ_GIX_0119)
static const u8 u8ProductName[12]     = "SQ-GIX-0119\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif	defined(SQ_GIX_0120)
static const u8 u8ProductName[12]     = "SQ-GIX-0120\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif	defined(SQ_GIX_0121)
static const u8 u8ProductName[12]     = "SQ-GIX-0121\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif	defined(SQ_GIX_0236)
static const u8 u8ProductName[12]     = "SQ-GIX-0236\0";
static const u8 u8FirmwareVersion[12] = "0.10       \0";
	#elif	defined(SQ_GIX_0249)
static const u8 u8ProductName[12]     = "SQ-GIX-0249\0";
static const u8 u8FirmwareVersion[12] = "0.11       \0";
	#elif	defined(SQ_GIX_0219)
#define FWVER (0x08)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0219\0";
static const u8 u8FirmwareVersion[12] = "0.08       \0";
	#elif	defined(SQ_CST_0340)
static const u8 u8ProductName[12]     = "SQ-CST-0340\0";
static const u8 u8FirmwareVersion[12] = "0.12       \0";
	#elif		defined(SQ_GIX_0269)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0269\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif	defined(SQ_GIX_0271)
static const u8 u8ProductName[12]     = "SQ-GIX-0271\0";
static const u8 u8FirmwareVersion[12] = "0.10       \0";
	#elif		defined(SQ_GIX_0274)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0274\0";
static const u8 u8FirmwareVersion[12] = "20160908_B \0";
	#elif	defined(SQ_CST_0342)
#define FWVER (0x0B)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-CST-0342\0";
static const u8 u8FirmwareVersion[12] = "0.11       \0";
	#elif	defined(SQ_CST_0343)
#define FWVER (0x0B)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-CST-0343\0";
static const u8 u8FirmwareVersion[12] = "0.11       \0";
	#elif	defined(SQ_RPS_0058)
#define FWVER (0x0B)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0058\0";
static const u8 u8FirmwareVersion[12] = "0.12       \0";
	#elif	defined(SQ_RPS_0059)
#define FWVER (0x0B)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0059\0";
static const u8 u8FirmwareVersion[12] = "0.12       \0";
	#elif		(not	defined(SQ_GIX_0286)	)	and defined(SQ_GIX_0255)
static const u8 u8ProductName[12]     = "SQ-GIX-0255\0";
static const u8 u8FirmwareVersion[12] = "0.14       \0";
	#elif	defined(SQ_GIX_0272)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0272\0";
static const u8 u8FirmwareVersion[12] = "20160719_A \0";
	#elif	defined(SQ_GIX_0270)
#define FWVER (0x0C)   // Version 0.0n
		#if		defined(PREPOT_VERSION)
static const u8 u8ProductName[12]     = "SQ-PPT-0270\0";
		#else
static const u8 u8ProductName[12]     = "SQ-GIX-0270\0";
		#endif
static const u8 u8FirmwareVersion[12] = "0.12       \0";
	#elif	defined(SQ_GIX_0273)
#define FWVER (0x0C)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0273\0";
static const u8 u8FirmwareVersion[12] = "0.12       \0";
	#elif	defined(SQ_RPS_0061)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0061\0";
static const u8 u8FirmwareVersion[12] = "0.15       \0";
	#elif	defined(SQ_GIX_0261)
#define FWVER (0x07)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0261\0";
static const u8 u8FirmwareVersion[12] = "0.15       \0";
	#elif		defined(SQ_GIX_0289)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0289\0";
static const u8 u8FirmwareVersion[12] = "20151211_A \0";
	#elif		defined(SQ_GIX_0290)
#define FWVER 	(0x0F)	//  Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0290\0";
static const u8 u8FirmwareVersion[12] = "20151221_C \0";	
	#elif		defined(SQ_GIX_0291)
#define FWVER 	(0x0F)	//  Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0291\0";
static const u8 u8FirmwareVersion[12] = "20151221_A \0";	
	#elif		defined(SQ_GIX_0292)
#define FWVER 	(0x0F)	//  Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0292\0";
static const u8 u8FirmwareVersion[12] = "20151221_A \0";	
	#elif		defined(SQ_GIX_0293)
#define FWVER 	(0x0F)	//  Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0293\0";
static const u8 u8FirmwareVersion[12] = "20151221_A \0";	
	#elif		defined(SQ_GIX_0294)
#define FWVER 	(0x0F)	//  Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0294\0";
static const u8 u8FirmwareVersion[12] = "20151221_C \0";	
	#elif		defined(SQ_GIX_0295)
#define FWVER 	(0x0F)	//  Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0295\0";
static const u8 u8FirmwareVersion[12] = "20151221_A \0";	
	#elif		defined(SQ_GIX_0296)
#define FWVER 	(0x0F)	//  Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0296\0";
static const u8 u8FirmwareVersion[12] = "20151221_A \0";	
	#elif		defined(SQ_GIX_0297)
#define FWVER 	(0x0F)	//  Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0297\0";
static const u8 u8FirmwareVersion[12] = "20151221_A \0";	
	#elif	defined(SQ_GIX_0286)
static const u8 u8ProductName[12]     = "SQ-GIX-0286\0";
static const u8 u8FirmwareVersion[12] = "0.16       \0";
	#elif	defined(SQ_GIX_2020)
static const u8 u8ProductName[12]     = "SQ-GIX-2020\0";
static const u8 u8FirmwareVersion[12] = "0.16       \0";
	#elif	defined(SQ_RPS_0063)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0063\0";
static const u8 u8FirmwareVersion[12] = "0.15.00    \0";
	#elif	defined(SQ_RPS_0064)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0064\0";
static const u8 u8FirmwareVersion[12] = "20160812_A \0";
  #elif   defined(SQ_RPS_0065)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0065\0";
static const u8 u8FirmwareVersion[12] = "20160629_B \0";
	#elif		defined(SQ_GIX_0299)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0299\0";
static const u8 u8FirmwareVersion[12] = "20160712_E \0";
	#elif	defined(SQ_GIX_2001)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2001\0";
static const u8 u8FirmwareVersion[12] = "20160802_B \0";
	#elif		defined(SQ_GIX_0298)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0298\0";
static const u8 u8FirmwareVersion[12] = "20160819_A \0";
	#elif		defined(SQ_GIX_2023)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2023\0";
static const u8 u8FirmwareVersion[12] = "20160929_A \0";
	#elif		defined(SQ_GIX_2003)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2003\0";
static const u8 u8FirmwareVersion[12] = "20160519_A \0";
	#elif		defined(SQ_GIX_2026)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2026\0";
static const u8 u8FirmwareVersion[12] = "20160922_B \0";
	#elif	defined(SQ_GIX_0302)
static const u8 u8ProductName[12]     = "SQ-GIX-0302\0";
static const u8 u8FirmwareVersion[12] = "1.01       \0";
	#elif	defined(SQ_GIX_2014)
#define FWVER (0x0F)   // Version x.y, 0x17 = 1.07
static const u8 u8ProductName[12]     = "SQ-GIX-2014\0";
static const u8 u8FirmwareVersion[12] = "20160726_A \0";
	#elif	defined(SQ_GIX_0303)
#define FWVER (0x0F)   // Version x.y, 0x17 = 1.07
static const u8 u8ProductName[12]     = "SQ-GIX-0303\0";
static const u8 u8FirmwareVersion[12] = "20160715_B \0";
	#elif	defined(SQ_GIX_2017)
#define FWVER (0x0F)   // Version x.y, 0x17 = 1.07
static const u8 u8ProductName[12]     = "SQ-GIX-2017\0";
static const u8 u8FirmwareVersion[12] = "20160803_A \0";
  #elif	defined(SQ_GIX_2002)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2002\0";
static const u8 u8FirmwareVersion[12] = "20160728_A \0";
	#elif	defined(SQ_GIX_2004)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2004\0";
static const u8 u8FirmwareVersion[12] = "20160728_B \0";
	#elif	defined(SQ_GIX_2005)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2005\0";
static const u8 u8FirmwareVersion[12] = "20160728_C \0";
	#elif		defined(SQ_GIX_2010)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2010\0";
static const u8 u8FirmwareVersion[12] = "20160803_B \0";
	#elif		defined(SQ_GIX_2011)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2011\0";
static const u8 u8FirmwareVersion[12] = "20160803_C \0";
	#elif		defined(SQ_GIX_2012)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2012\0";
static const u8 u8FirmwareVersion[12] = "20160803_D \0";	
	#elif		defined(SQ_GIX_2013)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2013\0";
static const u8 u8FirmwareVersion[12] = "20160803_E \0";	
	#elif		defined(SQ_GIX_2015)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2015\0";
static const u8 u8FirmwareVersion[12] = "20160707_C \0";	
	#elif		defined(SQ_GIX_2022)
#define FWVER (0x0F)   // Version x.y, 0x17 = 1.07
static const u8 u8ProductName[12]     = "SQ-GIX-2022\0";
static const u8 u8FirmwareVersion[12] = "20160922_A \0";
	#elif	defined(SQ_GIX_2021)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2021\0";
static const u8 u8FirmwareVersion[12] = "20160824_B \0";
	#elif	defined(SQ_GIX_2019)
#define FWVER (0x10)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2019\0";
static const u8 u8FirmwareVersion[12] = "201608??_? \0";
	#elif	defined(SQ_GIX_2027)
#define FWVER (0x10)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2027\0";
static const u8 u8FirmwareVersion[12] = "201608??_? \0";
	#elif	defined(SQ_GIX_2024)
static const u8 u8ProductName[12]     = "SQ-GIX-2024\0";
static const u8 u8FirmwareVersion[12] = "20161020_B \0";
	#else
#define FWVER (0x21)   // Version 2.01	//	(0x1F)   // Version 1.15
static const u8 u8ProductName[12]     = "SQ-RPS-0004\0";
static const u8 u8FirmwareVersion[12] = "2.01.00    \0";	//"1.15.00    \0";
	#endif


	#if		defined(SQ_MBL_HW_REV_A)
#define HWVER ('A')    // PCB Rev 
static const u8 u8HardwareVersion[12] = "MBL Rev A  \0"; 
	#elif	defined(SQ_MBL_HW_REV_B)
#define HWVER ('B')    // PCB Rev 
static const u8 u8HardwareVersion[12] = "MBL Rev B  \0"; 
	#elif	defined(MA_0069_HW)
#define HWVER ('C')    // PCB Rev 
static const u8 u8HardwareVersion[12] = "MA_0069_HW \0";
	#elif	defined(MA_0070_HW)
#define HWVER ('C')    // PCB Rev 
static const u8 u8HardwareVersion[12] = "MA_0070_HW \0";
	#elif	defined(MA_0071_HW)
#define HWVER ('C')    // PCB Rev 
static const u8 u8HardwareVersion[12] = "MA_0071_HW \0";
	#else
#define HWVER ('C')    // PCB Rev 
static const u8 u8HardwareVersion[12] = "MBL Rev C  \0"; 
	#endif
	
	#if		not	(defined(SQ_GIX_200)	)
#define	ENABLE_SPI1	(1)
	#endif


//*********************************************************************************************
#elif	(defined(MA_0083)	or	defined(MA_0144)	or	defined(MA_0166)	or	defined(MA_0192)	or	defined(MA_0192_105_TEST)	or	defined(MA_0219)	or	defined(MA_0271)  or  defined(MA_0285)  or  defined(MA_0286)	)
//*********************************************************************************************
  #if     defined(MA_0286)
#define HWVER ('A')    // PCB Rev [not really applicable, this ought to be the MA level not the MC component level]
static const u8 u8HardwareVersion[12] = "MA-0286  A \0";	//	!!!Fixme: concatenate HWVER here.
  #elif     defined(MA_0285)
#define HWVER ('A')    // PCB Rev [not really applicable, this ought to be the MA level not the MC component level]
static const u8 u8HardwareVersion[12] = "MA-0285  A \0";	//	!!!Fixme: concatenate HWVER here.
	#elif		defined(MA_0271)
#define HWVER ('B')    // PCB Rev [not really applicable, this ought to be the MA level not the MC component level]
static const u8 u8HardwareVersion[12] = "MA-0271    \0";	//	!!!Fixme: concatenate HWVER here.
	#elif	(defined(MA_0192_105_TEST)	or	defined(MA_0219) )
#define HWVER ('A')    // PCB Rev [not really applicable, this ought to be the MA level not the MC component level]
static const u8 u8HardwareVersion[12] = "MA-0219  A \0";	//	!!!Fixme: concatenate HWVER here.
	#elif		(defined(MA_0192)	)
#define HWVER ('A')    // PCB Rev [not really applicable, this ought to be the MA level not the MC component level]
static const u8 u8HardwareVersion[12] = "MA-0192    \0";	//	!!!Fixme: concatenate HWVER here.
	#elif	(defined(MA_0144)	)
#define HWVER ('A')    // PCB Rev 
static const u8 u8HardwareVersion[12] = "MA-0144  A \0";	//	!!!Fixme: concatenate HWVER here.
	#elif	(defined(MA_0166)	)
#define HWVER ('A')    // PCB Rev 
static const u8 u8HardwareVersion[12] = "MA-0166  A \0";	//	!!!Fixme: concatenate HWVER here.
	#elif	defined(MA_0083)
#define HWVER ('C')    // PCB Rev 
static const u8 u8HardwareVersion[12] = "MA-0083  C \0";	//	!!!Fixme: concatenate HWVER here.
	#elif	defined(MA_0083_REV_B)
#define HWVER ('B')    // PCB Rev 
static const u8 u8HardwareVersion[12] = "MA-0083  B \0";	//	!!!Fixme: concatenate HWVER here.
	#elif	defined(MA_0083_REV_A)
#define HWVER ('A')    // PCB Rev 
static const u8 u8HardwareVersion[12] = "MA-0083  A \0";	//	!!!Fixme: concatenate HWVER here.
	#else
ERROR:	u8HardwareVersion not defined.
	#endif

	#if		000	//(defined(MA_0083)	)	//	CAN2 is on MC-1144 REV A, REV B and REV C use CAN1
#define	USE_CAN2	(1)		//	not to be confused with "DUAL_CAN"
	#endif

	#if		(defined(MA_0166)	or	defined(MA_0192)	or	defined(MA_0192_105_TEST)	or	defined(MA_0219)	or	defined(MA_0271)  or  defined(MA_0285)  or  defined(MA_0286)	)
//  PA11  Pin 44  ACCL_ST  Output

#define XL_ST_PORT       (GPIOA)        //  PA11  Pin 44  ACCL_ST  Output
#define XL_ST_PIN			   (GPIO_Pin_11)  //  PA11  Pin 44  ACCL_ST  Output

//#define TB_ST_PORT       (GPIOB)      	//  PB10  Pin 29  ACCLYZ_ST  			Output
//#define TB_ST_PIN			   (GPIO_Pin_10)	//  PB10  Pin 29  ACCLYZ_ST  			Output

		#if		(defined(SQ_CST_0343)	or	defined(SQ_GIX_0255)	or	defined(SQ_GIX_0286)	or	defined(SQ_GIX_2020)	or	defined(SQ_GIX_2024)	or	defined(SQ_GIX_0272)	or	defined(SQ_GIX_0270)	or	defined(MA_0219)	or	defined(SQ_GIX_0290_to_7)  or  defined(SQ_GIX_0299)	or	defined(SQ_GIX_2001)	or	defined(SQ_GIX_0298)	or	defined(SQ_GIX_0272_F105) or  defined(SQ_GIX_2003)  or  defined(SQ_GIX_2026)	or	defined(SQ_GIX_2002)	or	defined(SQ_GIX_2004)	or	defined(SQ_GIX_2005) or  defined(SQ_GIX_2010)  or  defined(SQ_GIX_2011)  or  defined(SQ_GIX_2012)  or  defined(SQ_GIX_2013)	or	defined(SQ_GIX_2015)  or  defined(SQ_GIX_2014)  or  defined(SQ_GIX_0303)  or  defined(SQ_GIX_2017)  or  defined(SQ_GIX_2022)	or  defined(SQ_GIX_2021)	or  defined(SQ_GIX_2019)	or	defined(SQ_GIX_2027)  or  defined(SQ_GIX_2023)	)
#define GY_ST_PORT       (GPIOB)				//  PB2   Pin 28  GYP_CBIT  Output
#define GY_ST_PIN        (GPIO_Pin_2)		//  PB2   Pin 28  GYP_CBIT  Output
		#endif
	#elif	(defined(MA_0144)	)

#define XL_ST_PORT       (GPIOC)        //  PC1   Pin  9  ACCLXZXY_ST  		Output
#define XL_ST_PIN			   (GPIO_Pin_1)	  //  PC1   Pin  9  ACCLXZXY_ST  		Output

#define TB_ST_PORT       (GPIOB)      	//  PB10  Pin 29  ACCLYZ_ST  			Output
#define TB_ST_PIN			   (GPIO_Pin_10)	//  PB10  Pin 29  ACCLYZ_ST  			Output

		#if		(defined(SQ_CST_0343)		or	defined(SQ_GIX_0255)	or	defined(SQ_GIX_0286)	or	defined(SQ_GIX_2020)	or	defined(SQ_GIX_2024)	or	defined(SQ_GIX_0272)	or	defined(SQ_GIX_0270)	or	defined(SQ_GIX_0290_to_7)  or  defined(SQ_GIX_0299)	or	defined(SQ_GIX_2001)  or  defined(SQ_GIX_0272_F105)	or	defined(SQ_GIX_2002)	or	defined(SQ_GIX_2004)	or	defined(SQ_GIX_2005)  or  defined(SQ_GIX_2014)  or  defined(SQ_GIX_0303)	or  defined(SQ_GIX_2017)	or  defined(SQ_GIX_2022)	or  defined(SQ_GIX_2021)	or  defined(SQ_GIX_2019)	or	defined(SQ_GIX_2027)	)
#define GY_ST_PORT       (GPIOA)				//  PA5   Pin 21  GYRO_SPCK/CBIT  Output
#define GY_ST_PIN        (GPIO_Pin_5)		//  PA5   Pin 21  GYRO_SPCK/CBIT  Output
		#endif

	#elif	defined(MA_0083)
#define XL_ST_PORT       (GPIOC)        // Which port XL_ST signal is on
#define XL_ST_PIN			   (GPIO_Pin_2)	  // Which pin XL_ST signal is on

#define GY_ST_PORT       (GPIOB)
#define GY_ST_PIN        (GPIO_Pin_6)		//	CRM200/100 CBIT pin
	#endif
	
//*********************************************************************************************
//******	Define System info   ****************************************************************
//*********************************************************************************************
// System Version Information

//	NOTE: The use of 'static' here avoids multiple definitions since this header file is included everywhere.
//				We really ought to do this better.

	#if		defined(SQ_GIX_200)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-GIX-0200\0";
static const u8 u8FirmwareVersion[12] = "0.01       \0";
	#elif	defined(SQ_RPS_0022)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-RPS-0022\0";
static const u8 u8FirmwareVersion[12] = "0.01.00    \0";
	#elif	defined(SQ_RPS_0026)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-RPS-0026\0";
static const u8 u8FirmwareVersion[12] = "0.01.00    \0";
	#elif	defined(SQ_RPS_0027)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-RPS-0027\0";
static const u8 u8FirmwareVersion[12] = "0.01.00    \0";
	#elif	defined(SQ_RPS_0028)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-RPS-0028\0";
static const u8 u8FirmwareVersion[12] = "0.01.00    \0";
	#elif	defined(SQ_RPS_0031)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-RPS-0031\0";
static const u8 u8FirmwareVersion[12] = "0.01.00    \0";
	#elif	defined(SQ_RPS_0032)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0032\0";
static const u8 u8FirmwareVersion[12] = "0.05.00    \0";
	#elif		defined(SQ_GIX_0206)
#define FWVER (0x01)   // Version 0.01
static const u8 u8ProductName[12]     = "SQ-GIX-0206\0";
static const u8 u8FirmwareVersion[12] = "0.01       \0";
	#elif		defined(SQ_GIX_0102)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0102\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif		defined(SQ_GIX_0103)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0103\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif		defined(SQ_GIX_0104)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0104\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif		defined(SQ_GIX_0207)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0207\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif		defined(SQ_GIX_0208)
#define FWVER (0x02)   // Version 0.02
static const u8 u8ProductName[12]     = "SQ-GIX-0208\0";
static const u8 u8FirmwareVersion[12] = "0.02       \0";
	#elif		defined(SQ_GIX_0210)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0210\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif		defined(SQ_GIX_0211)
#define FWVER (0x02)   // Version 0.02
static const u8 u8ProductName[12]     = "SQ-GIX-0211\0";
static const u8 u8FirmwareVersion[12] = "0.02       \0";
	#elif		defined(SQ_GIX_0212)
#define FWVER (0x02)   // Version 0.02
static const u8 u8ProductName[12]     = "SQ-GIX-0212\0";
static const u8 u8FirmwareVersion[12] = "0.02       \0";
	#elif		defined(SQ_GIX_0213)
#define FWVER (0x02)   // Version 0.02
static const u8 u8ProductName[12]     = "SQ-GIX-0213\0";
static const u8 u8FirmwareVersion[12] = "0.02       \0";
	#elif		defined(SQ_GIX_0214)
#define FWVER (0x02)   // Version 0.02
static const u8 u8ProductName[12]     = "SQ-GIX-0214\0";
static const u8 u8FirmwareVersion[12] = "0.02       \0";
	#elif		defined(SQ_GIX_0221)
#define FWVER (0x03)   // Version 0.03
static const u8 u8ProductName[12]     = "SQ-GIX-0221\0";
static const u8 u8FirmwareVersion[12] = "0.03       \0";
	#elif		defined(SQ_RPS_0034)
#define FWVER (0x04)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0034\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif		defined(SQ_GIX_0107)
#define FWVER (0x02)   // Version 0.02
static const u8 u8ProductName[12]     = "SQ-GIX-0107\0";
static const u8 u8FirmwareVersion[12] = "0.03       \0";
	#elif		defined(SQ_GIX_0222)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0222\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif		defined(SQ_GIX_0223)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0223\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif		defined(SQ_GIX_0220)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0220\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif		defined(SQ_GIX_0108)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0108\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif		defined(SQ_GIX_0109)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0109\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif		defined(SQ_GIX_0224)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0224\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif		defined(SQ_GIX_0225)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0225\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif		defined(SQ_RPS_0038)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-RPS-0038\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif		defined(SQ_GIX_0226)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-GIX-0226\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif		defined(SQ_RPS_0035)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-RPS-0035\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif		defined(SQ_RPS_0036)
#define FWVER (0x04)   // Version 0.04
static const u8 u8ProductName[12]     = "SQ-RPS-0036\0";
static const u8 u8FirmwareVersion[12] = "0.04       \0";
	#elif		defined(SQ_GIX_0229)
#define FWVER (0x07)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0229\0";
static const u8 u8FirmwareVersion[12] = "0.07       \0";
	#elif		defined(SQ_GIX_0230)
#define FWVER (0x05)   // Version 0.05
static const u8 u8ProductName[12]     = "SQ-GIX-0230\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(GIX_THERMAL_TESTING)
#define FWVER (0x07)   // Version 0.0n
static const u8 u8ProductName[12]     = "GIX_THERMAL\0";
static const u8 u8FirmwareVersion[12] = "0.07       \0";
	#elif		defined(SQ_GIX_0232)
#define FWVER (0x05)   // Version 0.05
static const u8 u8ProductName[12]     = "SQ-GIX-0232\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_GIX_0209)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0209\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_GIX_0234)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0234\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_GIX_0110)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0110\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_GIX_0111)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0111\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_GIX_0112)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0112\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_GIX_0113)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0113\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_GIX_0114)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0114\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_MAG_0001)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-MAG-0001\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_GIX_0215)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0215\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_GIX_0216)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0216\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_GIX_0218)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0218\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_JSN_0111)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-JSN-0111\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_JSN_0112)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-JSN-0112\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_JSN_0234)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-JSN-0234\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_GIX_0238)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0238\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_RPS_0052)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0052\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_RPS_0053)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0053\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_GIX_0200)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0200\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SPI_GYRO_TEST)
//#define	ENABLE_SPI_GYRO	(1)
#define FWVER (0x06)   // Version 0.0n
static const u8 u8ProductName[12]     = "SPI_GYRO_00\0";
static const u8 u8FirmwareVersion[12] = "0.06       \0";
	#elif		defined(SQ_JSN_0113)
//#define	ENABLE_SPI_GYRO	(1)
#define FWVER (0x07)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-JSN-0113\0";
static const u8 u8FirmwareVersion[12] = "0.07       \0";
	#elif		defined(SQ_GIX_0241)
#define FWVER (0x07)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0241\0";
static const u8 u8FirmwareVersion[12] = "0.07       \0";
	#elif		defined(SQ_GIX_0243)
#define FWVER (0x07)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0243\0";
static const u8 u8FirmwareVersion[12] = "0.07       \0";
	#elif		defined(SQ_GIX_0287)
#define FWVER (0x07)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0287\0";
static const u8 u8FirmwareVersion[12] = "20151028_A \0";
	#elif		defined(SQ_GIX_0246)
#define FWVER (0x07)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0246\0";
static const u8 u8FirmwareVersion[12] = "0.07       \0";
	#elif		defined(SQ_RPS_0054)
#define FWVER (0x09)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0054\0";
static const u8 u8FirmwareVersion[12] = "0.09       \0";
	#elif		defined(SQ_GIX_0118)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0118\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_GIX_0119)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0119\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_GIX_0120)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0120\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_GIX_0121)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0121\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_GIX_0236)
#define FWVER (0x09)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0236\0";
static const u8 u8FirmwareVersion[12] = "0.10       \0";
	#elif		defined(SQ_CST_0340)
#define FWVER (0x09)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-CST-0340\0";
static const u8 u8FirmwareVersion[12] = "0.11       \0";
	#elif		defined(SQ_GIX_0269)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0269\0";
static const u8 u8FirmwareVersion[12] = "0.05       \0";
	#elif		defined(SQ_GIX_0271)
#define FWVER (0x09)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0271\0";
static const u8 u8FirmwareVersion[12] = "0.10       \0";
	#elif		defined(SQ_GIX_0274)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0274\0";
static const u8 u8FirmwareVersion[12] = "20160908_B \0";
	#elif		defined(SQ_GIX_0249)
#define FWVER (0x09)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0249\0";
static const u8 u8FirmwareVersion[12] = "0.11       \0";
	#elif		defined(SQ_GIX_0219)
#define FWVER (0x08)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0219\0";
static const u8 u8FirmwareVersion[12] = "0.08       \0";
	#elif		defined(SQ_CST_0342)
#define FWVER (0x0B)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-CST-0342\0";
static const u8 u8FirmwareVersion[12] = "0.11       \0";
	#elif		defined(SQ_CST_0343)
#define FWVER (0x0B)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-CST-0343\0";
static const u8 u8FirmwareVersion[12] = "0.11       \0";
	#elif		defined(SQ_RPS_0058)
#define FWVER (0x0C)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0058\0";
static const u8 u8FirmwareVersion[12] = "0.12       \0";
	#elif		defined(SQ_RPS_0059)
#define FWVER (0x0C)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0059\0";
static const u8 u8FirmwareVersion[12] = "0.12       \0";
	#elif		(not	defined(SQ_GIX_0286)	)	and defined(SQ_GIX_0255)
//=================================================================================
#define FWVER 	(((0) << 4)	|	(10))		//(0x0A)	//  Version 0.0n, so 0x0A ==> 0.10
#define	FWBUILD	(0x10)	//	Trimble specific, should increment with every release.
//=================================================================================
static const u8 u8ProductName[12]     = "SQ-GIX-0255\0";
static const u8 u8FirmwareVersion[12] = "0.14       \0";
	#elif		defined(SQ_GIX_0272)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0272\0";
static const u8 u8FirmwareVersion[12] = "20160721_D \0";
	#elif		defined(SQ_GIX_0270)
#define FWVER (0x0C)   // Version 0.0n
		#if		defined(PREPOT_VERSION)
static const u8 u8ProductName[12]     = "SQ-PPT-0270\0";
		#else
static const u8 u8ProductName[12]     = "SQ-GIX-0270\0";
		#endif
static const u8 u8FirmwareVersion[12] = "0.12       \0";
	#elif		defined(SQ_GIX_0273)
#define FWVER (0x0C)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0273\0";
static const u8 u8FirmwareVersion[12] = "0.12       \0";
	#elif		defined(SQ_RPS_0061)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0061\0";
static const u8 u8FirmwareVersion[12] = "0.15       \0";
	#elif		defined(SQ_GIX_0261)
#define FWVER (0x07)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0261\0";
static const u8 u8FirmwareVersion[12] = "0.15       \0";
	#elif		defined(SQ_GIX_0289)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0289\0";
static const u8 u8FirmwareVersion[12] = "20151211_A \0";
	#elif		defined(SQ_GIX_0290)
#define FWVER 	(0x0F)	//  Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0290\0";
static const u8 u8FirmwareVersion[12] = "20151221_C \0";	
	#elif		defined(SQ_GIX_0291)
#define FWVER 	(0x0F)	//  Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0291\0";
static const u8 u8FirmwareVersion[12] = "20151221_A \0";	
	#elif		defined(SQ_GIX_0292)
#define FWVER 	(0x0F)	//  Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0292\0";
static const u8 u8FirmwareVersion[12] = "20151221_A \0";	
	#elif		defined(SQ_GIX_0293)
#define FWVER 	(0x0F)	//  Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0293\0";
static const u8 u8FirmwareVersion[12] = "20151221_A \0";	
	#elif		defined(SQ_GIX_0294)
#define FWVER 	(0x0F)	//  Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0294\0";
static const u8 u8FirmwareVersion[12] = "20151221_C \0";	
	#elif		defined(SQ_GIX_0295)
#define FWVER 	(0x0F)	//  Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0295\0";
static const u8 u8FirmwareVersion[12] = "20151221_A \0";	
	#elif		defined(SQ_GIX_0296)
#define FWVER 	(0x0F)	//  Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0296\0";
static const u8 u8FirmwareVersion[12] = "20151221_A \0";	
	#elif		defined(SQ_GIX_0297)
#define FWVER 	(0x0F)	//  Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0297\0";
static const u8 u8FirmwareVersion[12] = "20151221_A \0";	
	#elif		defined(SQ_GIX_0298)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0298\0";
static const u8 u8FirmwareVersion[12] = "20160819_A \0";
	#elif		defined(SQ_GIX_2023)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2023\0";
static const u8 u8FirmwareVersion[12] = "20160929_A \0";
	#elif		defined(SQ_GIX_0272_F105)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0272\0";
static const u8 u8FirmwareVersion[12] = "?????????? \0"; // accidentally changed when working on SQ_GIX_0272
	#elif		defined(SQ_GIX_0286)
//=================================================================================
#define FWVER 	(((0) << 4)	|	(11))		//(0x0A)	//  Version 0.0n, so 0x0A ==> 0.10
#define	FWBUILD	(0x15)	//	Trimble specific, should increment with every release.
//=================================================================================
static const u8 u8ProductName[12]     = "SQ-GIX-0286\0";
static const u8 u8FirmwareVersion[12] = "20160811_D \0";
	#elif		defined(SQ_GIX_2020)
//=================================================================================
#define FWVER 	(((0) << 4)	|	(01))		//(0x0A)	//  Version 0.0n, so 0x0A ==> 0.10
#define	FWBUILD	(0x16)	//	Trimble specific, should increment with every release.
//=================================================================================
static const u8 u8ProductName[12]     = "SQ-GIX-2020\0";
static const u8 u8FirmwareVersion[12] = "20160902_F \0";
	#elif	defined(SQ_RPS_0063)
#define FWVER (0x05)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0063\0";
static const u8 u8FirmwareVersion[12] = "0.15.00    \0";
	#elif	defined(SQ_RPS_0064)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0064\0";
static const u8 u8FirmwareVersion[12] = "20160812_A \0";
  #elif   defined(SQ_RPS_0065)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-RPS-0065\0";
static const u8 u8FirmwareVersion[12] = "20160629_B \0";
	#elif		defined(SQ_GIX_0299)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-0299\0";
static const u8 u8FirmwareVersion[12] = "20160712_E \0";
	#elif		defined(SQ_GIX_2001)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2001\0";
static const u8 u8FirmwareVersion[12] = "20160802_B \0";
	#elif		defined(SQ_GIX_0302)
//=================================================================================
#define FWVER 	(((0) << 4)	|	(10))		//(0x0A)	//  Version 0.0n, so 0x0A ==> 0.10
#define	FWBUILD	(0x11)	//	Trimble specific, should increment with every release.
//=================================================================================
static const u8 u8ProductName[12]     = "SQ-GIX-0302\0";
static const u8 u8FirmwareVersion[12] = "1.01       \0";
	#elif		(not	defined(SQ_GIX_0302)	)	and defined(SQ_GIX_0255)
//=================================================================================
#define FWVER 	(((0) << 4)	|	(10))		//(0x0A)	//  Version 0.0n, so 0x0A ==> 0.10
#define	FWBUILD	(0x0F)	//	Trimble specific, should increment with every release.
//=================================================================================
static const u8 u8ProductName[12]     = "SQ-GIX-0302\0";
static const u8 u8FirmwareVersion[12] = "1.01       \0";
	#elif		defined(SQ_GIX_2003)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2003\0";
static const u8 u8FirmwareVersion[12] = "20160519_A \0";
	#elif		defined(SQ_GIX_2026)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2026\0";
static const u8 u8FirmwareVersion[12] = "20160922_B \0";
	#elif	defined(SQ_GIX_2014)
#define FWVER (0x0F)   // Version x.y, 0x17 = 1.07
static const u8 u8ProductName[12]     = "SQ-GIX-2014\0";
static const u8 u8FirmwareVersion[12] = "20160726_A \0";
	#elif	defined(SQ_GIX_0303)
#define FWVER (0x0F)   // Version x.y, 0x17 = 1.07
static const u8 u8ProductName[12]     = "SQ-GIX-0303\0";
static const u8 u8FirmwareVersion[12] = "20160715_B \0";
	#elif	defined(SQ_GIX_2017)
#define FWVER (0x0F)   // Version x.y, 0x17 = 1.07
static const u8 u8ProductName[12]     = "SQ-GIX-2017\0";
static const u8 u8FirmwareVersion[12] = "20160803_A \0";
	#elif		defined(SQ_GIX_2002)
#define FWVER (0x0F)   // Version x.y, 0x17 = 1.07
static const u8 u8ProductName[12]     = "SQ-GIX-2002\0";
static const u8 u8FirmwareVersion[12] = "20160728_A \0";
	#elif		defined(SQ_GIX_2004)
#define FWVER (0x0F)   // Version x.y, 0x17 = 1.07
static const u8 u8ProductName[12]     = "SQ-GIX-2004\0";
static const u8 u8FirmwareVersion[12] = "20160728_B \0";
	#elif		defined(SQ_GIX_2005)
#define FWVER (0x0F)   // Version x.y, 0x17 = 1.07
static const u8 u8ProductName[12]     = "SQ-GIX-2005\0";
static const u8 u8FirmwareVersion[12] = "20160728_C \0";
	#elif		defined(SQ_GIX_2010)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2010\0";
static const u8 u8FirmwareVersion[12] = "20160803_B \0";
	#elif		defined(SQ_GIX_2011)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2011\0";
static const u8 u8FirmwareVersion[12] = "20160803_C \0";
	#elif		defined(SQ_GIX_2012)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2012\0";
static const u8 u8FirmwareVersion[12] = "20160803_D \0";
	#elif		defined(SQ_GIX_2013)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2013\0";
static const u8 u8FirmwareVersion[12] = "20160803_E \0";
	#elif		defined(SQ_GIX_2015)
#define FWVER (0x0F)   // Version 0.0n
static const u8 u8ProductName[12]     = "SQ-GIX-2015\0";
static const u8 u8FirmwareVersion[12] = "20160922_A \0";
	#elif		defined(SQ_GIX_2022)
#define FWVER (0x0F)   // Version x.y, 0x17 = 1.07
static const u8 u8ProductName[12]     = "SQ-GIX-2022\0";
static const u8 u8FirmwareVersion[12] = "20160920_A \0";
	#elif		defined(SQ_GIX_2019)
#define FWVER (0x10)   // Version x.y, 0x17 = 1.07
static const u8 u8ProductName[12]     = "SQ-GIX-2019\0";
static const u8 u8FirmwareVersion[12] = "20160923_D \0";
	#elif		defined(SQ_GIX_2019)
#define FWVER (0x10)   // Version x.y, 0x17 = 1.07
static const u8 u8ProductName[12]     = "SQ-GIX-2027\0";
static const u8 u8FirmwareVersion[12] = "20160923_X \0";
	#elif		defined(SQ_GIX_2024)
//=================================================================================
//	NOT TRIMBLE HERE !!!
//=================================================================================
#define FWVER 	(((0) << 4)	|	(01))		//(0x0A)	//  Version 0.0n, so 0x0A ==> 0.10
#define	FWBUILD	(0x18)	//	(NOT) Trimble specific, should increment with every release.
//=================================================================================
static const u8 u8ProductName[12]     = "SQ-GIX-2024\0";
static const u8 u8FirmwareVersion[12] = "20161021_B \0";
	#else
#define FWVER (0x21)   // Version 2.01	//	(0x1F)   // Version 1.15
static const u8 u8ProductName[12]     = "SQ-RPS-0004\0";
static const u8 u8FirmwareVersion[12] = "2.01.00    \0";	//"1.15.00    \0";
	#endif


//#define	ENABLE_SPI1	(1)
#define	ENABLE_SPI3	(1)		//	Connected to NEMO

//*********************************************************************************************
#else
//*********************************************************************************************

// System Version Information
#define HWVER ('L')    // PCB Rev K
#define FWVER (0x1C)   // Version 1.13
static const u8 u8ProductName[12]     = "SQ-RPS-0004\0";
static const u8 u8FirmwareVersion[12] = "1.13.00    \0";
static const u8 u8HardwareVersion[12] = "MBC Rev K  \0"; 

//*********************************************************************************************
#endif
//*********************************************************************************************

#define	HZ	(1.0)					//	Hz
#define	KHZ	(1000.0)			//	Hz/KHz
#define	MHZ	(1000000.0)		//	Hz/MHz

//	NOTE:		Ought to use SystemCoreClock here, but that wouldn't precompile...
#if		defined(RUN_446_AT_72_MHZ)
#define	SYSCLOCK_FREQ		(72.0 * MHZ)	//	Hertz
#elif	(defined(MA_0144)	or	defined(MA_0166)	or	defined(MA_0192)	or	defined(MA_0271)  or  defined(MA_0285)  or  defined(MA_0286)	)
#define	SYSCLOCK_FREQ		(180.0 * MHZ)	//	Hertz
#elif	(defined(SQ_CST_0325)	)
#define	SYSCLOCK_FREQ		(24.0 * MHZ)	//	Hertz
#elif	(defined(SQ_ION_HW)	or	defined(MA_0127)	or	defined(MA_0130)	or	defined(MA_0131)	or	defined(MA_0134)	)
#define	SYSCLOCK_FREQ		(64.0 * MHZ)	//	Hertz
#else
#define	SYSCLOCK_FREQ		(72.0 * MHZ)	//	Hertz
#endif

#define	SYSCLOCK_PERIOD	(1.0/SYSCLOCK_FREQ)	//	Seconds

#if		(defined(GIX_300)	and	not	defined(GIX_300_AT_250_HZ)	)
	#define MAINLOOP_RATE	(500 * HZ)    // Main Loop Rate at nnn Hz
#elif	defined(GIX_BUILD)
	#define MAINLOOP_RATE	(250 * HZ)    // Main Loop Rate at nnn Hz
#elif	defined(NON_GIX_BUILD)
	#define MAINLOOP_RATE	(500 * HZ)    // Main Loop Rate at nnn Hz
#else
	ERROR:	MAINLOOP_RATE not defined.
#endif

// When we're asked to trim, we wait N seconds before we capture new trim
#define DELAYED_TRIM_COUNTER_TICKS        (MAINLOOP_RATE * 4)


// TODO: Check coefficients for 500Hz mainloop rate
// DEBUGGING
// used to LPF raw data - for now...
// with a loop rate of 1kHz and targeting a 
// 10Hz fc we want A = e^(2*pi*fc) with fc = 0.01
#define ACOEF_10HZ (0.88191)

// Same thing for a 2Hz filter for angle/calibration
#define ACOEF_2HZ (0.97518f)

// Same thing for a 1HZ filter for RMS output
#define ACOEF_1HZ (0.98751f)

// Same thing for a 0.1HZ filter for gyro HPF output
#define ACOEF_01HZ (0.99874f)

// Same thing for a 0.01HZ filter for gyro HPF output (experimental)
#define ACOEF_001HZ (0.99987f)

// Used to LPF raw data with a sample-rate of 5kHz
#define ACOEF_FC_250HZ_FS_5000HZ  (0.73040)

// Filter with ~3.03 (~0.33 Hz) seconds settling time for RMS Vibration
#define ACOEF_TC3S (0.99586)

#if		(defined(MA_0127)	or	defined(MA_0130)	or	defined(MA_0131)	or	defined(MA_0134)	)

	//	Vin is estimate by resistive divider R51/R52 and fed into the ADC
	//
	//	R51	=	100 Kohm, and R52 = 4.99 Kohm, so Attenuation factor is 0.047528336	V/V
	//
	//	Vref is 3.3 V, Resolution is 12 bit, (4096 counts), so conversion ratio is 0.000805664	V/count
	//
	//	Input referred it is:  (0.000805664/0.047528336)	=	0.016951236	V/count	=	16.95123646	mV/count
	//
	//	However, the voltage sensed is after R54/D41/L41.  We'll estimate the combined voltage Drop as 0.7 Volts.

//	//		f32Voltage		=	(0.008862305f * u16Voltage) + 0.5f;		//	[Note: 0.50 V est. for Diode drop.]
	//		f32Voltage		=	(0.008862305f * u16Voltage) + 0.0f;		//	[Note: 0.0 V est. (Series Diode eliminated.)]

	//	Note that the f32Voltage scaling calculation is different from the LOG, HIG and GYRO, it's Y=(f32Scale*X)+f32Zero
	
#define	VREF	(f32Voltage1Hz)	//	estimate based on reading built in MCU Vref	//was:((float)(3.300))

#define	BIT		(1)
#define	BITS	(BIT)

#define	ADC_RESOLUTION	(12 * BITS)
#define	ADC_RANGE	(BIT << ADC_RESOLUTION)

#elif	(defined(SQ_MBL_HW)	or	defined(MA_0069_HW)		or	defined(MA_0070_HW)		or	defined(MA_0071_HW)	)

	//	Vin is attenuated by resistive divider R11/R12 and fed into the ADC
	//
	//	R11	=	1 Mohm, and R12 = 100 Kohm, so Attenuation factor is 0.090909091	V/V
	//
	//	Vref is 3.3 V, Resolution is 12 bit, (4096 counts), so conversion ratio is 0.000805664	V/count
	//
	//	Input referred it is:  (0.000805664/0.090909091)	=	0.008862305	V/count	=	8.862305	mV/count
	//
	//	However, the voltage sensed is after D1/L1.  We'll estimate the combined voltage Drop as 0.9 Volts [seems high?  0.7 V for diode and 0.2V/75mA = 2.7 Ohms?]

	//		f32Voltage		=	(0.008862305f * u16Voltage) + 0.5f;		//	[Note: 0.50 V est. for Diode drop.]

	//	Note that the f32Voltage scaling calculation is different from the LOG, HIG and GYRO, it's Y=(f32Scale*X)+f32Zero
	
#define	VREF	((float)(3.300))

#define	OHM		((float)1)
#define	KOHM	((float)1000 * OHM)
#define	MOHM	((float)1000 * KOHM)

#define	R11		((float)((float)(1)*MOHM))
#define	R12		((float)((float)(100)*KOHM))

#define	VIN_ATTENUATION	(R12/(R12+R11))

#define	BIT		(1)
#define	BITS	(BIT)

#define	ADC_RESOLUTION	(12 * BITS)
#define	ADC_RANGE	(BIT << ADC_RESOLUTION)

#define	DEFAULT_VIN_SCALE		((VREF/ADC_RANGE)/VIN_ATTENUATION)
#define	DEFAULT_VIN_OFFSET	((float)(0.5))

#elif	(defined(MA_0083)	or	defined(SQ_ION_HW)	or	defined(MA_0144)	or	defined(MA_0166)	or	defined(MA_0192)	or	defined(MA_0192_105_TEST)	or	defined(MA_0219)	or	defined(MA_0271)  or  defined(MA_0285)  or  defined(MA_0286)	)

	//	Vin is attenuated by resistive divider R51/R52 and fed into the ADC
	//
	//	R51	=	100 Kohm, and R52 = 4.99 Kohm, so Attenuation factor is 0.047528336	V/V
	//
	//	Vref is 3.3 V, Resolution is 12 bit, (4096 counts), so conversion ratio is 0.000805664	V/count
	//
	//	Input referred it is:  (0.000805664/0.047528336)	=	0.016951236	V/count	=	16.95123646	mV/count
	//
	//	However, the voltage sensed is after R54/D41/L41.  We'll estimate the combined voltage Drop as 0.7 Volts.

//	//		f32Voltage		=	(0.008862305f * u16Voltage) + 0.5f;		//	[Note: 0.50 V est. for Diode drop.]
	//		f32Voltage		=	(0.008862305f * u16Voltage) + 0.0f;		//	[Note: 0.0 V est. (Series Diode eliminated.)]

	//	Note that the f32Voltage scaling calculation is different from the LOG, HIG and GYRO, it's Y=(f32Scale*X)+f32Zero
	
	#if		defined(SQ_ION_HW)
#define	VREF	((float)(3.000))
	#else
#define	VREF	((float)(3.300))
	#endif

#define	OHM		((float)1)
#define	KOHM	((float)1000 * OHM)
#define	MOHM	((float)1000 * KOHM)

#define	R51		((float)((float)( 100)*KOHM))
#define	R52		((float)((float)(4.99)*KOHM))

#define	VIN_ATTENUATION	(R52/(R52+R51))

#define	BIT		(1)
#define	BITS	(BIT)

#define	ADC_RESOLUTION	(12 * BITS)
#define	ADC_RANGE	(BIT << ADC_RESOLUTION)

#define	DEFAULT_VIN_SCALE		((float)((VREF/ADC_RANGE)/VIN_ATTENUATION))
#define	DEFAULT_VIN_OFFSET	((float)(0.0))	//	Series diode eliminated.	//((float)(0.5))

#endif


// 	//	Note that the TEMP scaling calculation is different from the LOG, HIG and GYRO, it's Y=(f32Scale*X)+f32Zero
//   pCD->CalData[TEMP].f32Scale	=	(float)(-3.3/(4096.0*0.0043));		//	((-Vref * 2^-12)/Tslope)= -0.18736	
//   pCD->CalData[TEMP].f32Zero	= (float)((1.43/0.0043)+25.0); 			//	((Voffset/Tslope) + T25) = 357.56

#if		defined(F4_BUILD)

#define	VOLTS	(1)
#define	TEMP_REFERENCE_OFFSET	((float)(0.760*VOLTS))
#define	DEGREES_C	(1)
#define	TEMP_REFERENCE_TEMPERATURE	((float)(25.0*DEGREES_C))
#define	MVOLT_PER_DEGREE_C	(VOLTS/1000.0f)
#define	TEMP_SLOPE	((float)(-2.5*MVOLT_PER_DEGREE_C))

#else

#define	VOLTS	(1)
#define	TEMP_REFERENCE_OFFSET	((float)(1.43*VOLTS))
#define	DEGREES_C	(1)
#define	TEMP_REFERENCE_TEMPERATURE	((float)(25.0*DEGREES_C))
#define	MVOLT_PER_DEGREE_C	(VOLTS/1000.0f)
#define	TEMP_SLOPE	((float)(-4.3*MVOLT_PER_DEGREE_C))

#endif

#if		(defined(MA_0144)	or	defined(MA_0166)	or	defined(MA_0192)	or	defined(MA_0271)  or  defined(MA_0285)  or  defined(MA_0286)	)

#define	TS_CAL1		(*((uint16_t *)(0x1FFF7A2C)))
#define	TS_CAL2		(*((uint16_t *)(0x1FFF7A2E)))

#define	TS_CAL1_TEMPERATURE		( 30.0f)
#define	TS_CAL2_TEMPERATURE		(110.0f)

#define	DEFAULT_TEMP_SCALE		((TS_CAL2_TEMPERATURE- TS_CAL1_TEMPERATURE)/(TS_CAL2-TS_CAL1))
#define	DEFAULT_TEMP_OFFSET		 (TS_CAL1_TEMPERATURE-(TS_CAL1*DEFAULT_TEMP_SCALE))

#elif	(defined(MA_0127)	or	defined(MA_0130)	or	defined(MA_0131)	or	defined(MA_0134)	)
#define	DEFAULT_TEMP_SCALE	(3.300f/(ADC_RANGE*TEMP_SLOPE))	//-0.187363735
#define	DEFAULT_TEMP_OFFSET	((float)((TEMP_REFERENCE_OFFSET/(-TEMP_SLOPE))+TEMP_REFERENCE_TEMPERATURE))	//357.558139535 or F4: 329
#else
#define	DEFAULT_TEMP_SCALE	((float)(VREF/(ADC_RANGE*TEMP_SLOPE)))		//-0.187363735 or F4:-0.322265625
#define	DEFAULT_TEMP_OFFSET	((float)((TEMP_REFERENCE_OFFSET/(-TEMP_SLOPE))+TEMP_REFERENCE_TEMPERATURE))	//357.558139535 or F4: 329
#endif


typedef float f32;

// "Sensor Data 3-axis" structure for holding an X,Y,Z triplet
typedef struct SD3_t_ {
	f32 f32X;
	f32 f32Y;
	f32 f32Z;
} SD3_t;

typedef struct SDAngle_t_ {
  f32 f32Pitch;
  f32 f32Roll;
  f32 f32TPR;
} SDAngle_t;

#if		defined(DOUBLE_ADC_CHANNELS)
#define ADC_NUMBER_OF_CHANNELS    (14)
#else
#define ADC_NUMBER_OF_CHANNELS    (11)
#endif

#if		defined(F4_BUILD)
//#define ADC1_DR_Address	((uint32_t	*)(&ADC1->DR))	//0x4001204C
#else
#define ADC1_DR_Address           ((u32)0x4001244C)	
#endif

// This dictates the main loop rate.  Right now we
// run a 5 KHz (or 2.5 KHz) sampling frequency... so we'll hit the mainloop at 500/250 Hz w/ 2/4 mSec loop time budget
	
#if		(defined(GIX_300)	and	defined(GIX_300_AT_250_HZ)	)//(defined(GIX_300_AT_250_HZ)	or	defined(DUAL_GIX)	)	//(defined(GIX_300)	and	defined(GIX_300_AT_250_HZ)	)	//0000	///@@##$$	defined(GIX_300)	//	defined(GIX_300_AT_250_HZ)
#define ADC_SAMPLES_PER_CHANNEL   (20)
#else
#define ADC_SAMPLES_PER_CHANNEL   (10)
#endif

#define ADC_DMA_BUFFERSIZE        (ADC_NUMBER_OF_CHANNELS * ADC_SAMPLES_PER_CHANNEL)
#define ADC_DMA_RINGBUFFERSIZE    (ADC_DMA_BUFFERSIZE * 2)		//	Double size of buffer for DMA ping-pong'ing.

//==========================================================================================
#if		defined(F4_BUILD)
//==========================================================================================
	#if		(defined(MA_0144)	or	defined(MA_0166)	or	defined(MA_0192)	or	defined(MA_0192_105_TEST)	or	defined(MA_0219)	or	defined(MA_0271)  or  defined(MA_0285)  or  defined(MA_0286)	)

	//		NOTE:  THE FOLLOWING SECTION IS FOR A '446 based PCBA
	//
	//	From:	RM0390 STM32F446xx.pdf	DocID026976 Rev 1	page 63
	//
	//	3.3 Embedded Flash memory
	//
	//	The Flash memory has the following main features:
	//		• Capacity up to 512 KBytes
	//		• 128 bits wide data read
	//		• Byte, half-word, word and double word write
	//		• Sector and mass erase
	//		• Memory organization
	//		The Flash memory is organized as follows:
	//			– A main memory block divided into 4 sectors of 16 KBytes, 1 sector of 64 KBytes,
	//				and 3 sectors of 128 Kbytes
	//			– System memory from which the device boots in System memory boot mode
	//			– 512 OTP (one-time programmable) bytes for user data
	//				The OTP area contains 16 additional bytes used to lock the corresponding OTP
	//				data block.
	//			– Option bytes to configure read and write protection, BOR level, watchdog
	//				software/hardware and reset when the device is in Standby or Stop mode.
	//			• Low-power modes (for details refer to the Power control (PWR) section of the reference
	//				manual)
	//
	//	Table 4. Flash module organization
	//
	//	Block 				Name 			Block base addresses 			Size				Total
	//	=============	========	=========================	==========	=====
	//	Main memory		Sector 0 	0x08000000 - 0x08003FFF  	 16 Kbytes	 16		Bootloader 0x08000000 +0x00004000 (Low)
	//								Sector 1 	0x08004000 - 0x08007FFF  	 16 Kbytes	 32		0x08004000	CD struct in Flash
	//								Sector 2 	0x08008000 - 0x0800BFFF  	 16 Kbytes	 48		Bootloader 0x8008000 +0x00004000 (High)
	//								Sector 3 	0x0800C000 - 0x0800FFFF  	 16 Kbytes	 64		BACKUP CD
	//								Sector 4 	0x08010000 - 0x0801FFFF  	 64 Kbytes	128		0x08010000	Application		0x0801A000	backup CD
	//								Sector 5 	0x08020000 - 0x0803FFFF  	128 Kbytes	256		
	//	-----------------------------------------------------------------		
	//								Sector 6 	0x08040000 - 0x0805FFFF  	128 Kbytes	384		
	//								Sector 7 	0x08060000 - 0x0807FFFF  	128 Kbytes	512		
	//	-----------------------------------------------------------------		
	//	System memory 					0x1FFF0000 - 0x1FFF77FF 	 30 Kbytes
	//	OTP area 								0x1FFF7800 - 0x1FFF7A0F 	528  bytes
	//	Option bytes 						0x1FFFC000 - 0x1FFFC00F 	 16  bytes

//#define	SECTOR_SIZE				(0x00004000)
#define	SECTOR_SIZE				(0x00001000)

#define BLOCK_SIZE        (SECTOR_SIZE)	// Number of bytes per sector

#define	SECTOR_64K_BASE			(0x08010000)
#define	SECTOR_128K_BASE		(0x08020000)

#define FLASH_START_ADDRESS (0x08000000)

//#define CONFIG_ADDRESS     (0x08002000)   // (Page 4) Location of standard config page
#define CONFIG_ADDRESS      (0x08004000)   // (Sector 1) Location of standard config page

//#define APPLICATION_ADDRESS	0x08004800   // (Page 5) Base of applications
//#define APPLICATION_ADDRESS	0x08008000   // (Sector 2) Base of applications
#define APPLICATION_ADDRESS	(0x08010000)   // (Sector 2) Base of applications

#define BOOTMODE_ADDRESS    (CONFIG_ADDRESS)   // In the CONFIG Structure - determines boot mode

#define NVRAM_ADDRESS  			(CONFIG_ADDRESS)
#define NVRAM_BLOCKS      	(1)	//10		//	!!!Ought to be something like (int(sizeof(CD)/NVRAM_BLOCKSIZE)+1) or ((APPLICATION_ADDRESS-NVRAM_ADDRESS)/NVRAM_BLOCKSIZE)
#define NVRAM_BLOCKSIZE   	(SECTOR_SIZE)	//1024

	#else

// From:
// PM0059	STM32F205/215, STM32F207/217 Flash programming manual	
// DocID15687 Rev 5
// Pgs 7-
//
// Section 2.3 Flash memory
//
// The Flash memory has the following main features:
// • Capacity up to 1 Mbyte
// • 128 bits wide data read
// • Byte, half-word, word and double word write
// • Sector and mass erase
// • Memory organization
//
// The Flash memory is organized as follows:
// – Main memory block containing 
// 		- 4 sectors of 16 Kbytes, 
// 		- 1 sector 	of 64 Kbytes, and
// 		- 7 sectors of 128 Kbytes
// 		
// – System memory used to boot the device in System memory boot mode.
//
// 	This area is reserved for STMicroelectronics and contains the bootloader which is
// 	used to reprogram the Flash memory through one of the following interfaces:
// 	USART1, USART3, CAN2, USB OTG FS in Device mode (DFU: device firmware
// 	upgrade). The bootloader is programmed by ST when the device is manufactured,
// 	and protected against spurious write/erase operations.
// 		
// – 512 OTP (one-time programmable) bytes for user data
// 	The OTP area contains 16 additional bytes used to lock the corresponding OTP
// 	data block.
// – Option bytes: read and write protections, BOR level, watchdog software/hardware
// 	and reset when the device is in Standby or Stop mode.
// • Low power modes (for details refer to the Power control (PWR) section of the reference
// 	manual)
//
// Table 2. Flash module organization
//
// 	Block 				Name 		Block base addresses 				Size
// -----------	--------	-----------------------		----------	
// Main memory
// 							Sector 0 	0x08000000 - 0x08003FFF		  16 Kbytes
// 							Sector 1 	0x08004000 - 0x08007FFF		  16 Kbytes
// 							Sector 2 	0x08008000 - 0x0800BFFF		  16 Kbytes
// 							Sector 3 	0x0800C000 - 0x0800FFFF		  16 Kbytes
// 							Sector 4 	0x08010000 - 0x0801FFFF		  64 Kbytes
// 							Sector 5 	0x08020000 - 0x0803FFFF		 128 Kbytes
// 							Sector 6 	0x08040000 - 0x0805FFFF		 128 Kbytes
// 								... 			...												...
// 							Sector 11 0x080E0000 - 0x080FFFFF 	 128 Kbytes
// System memory 					0x1FFF0000 - 0x1FFF77FF 	  30 Kbytes
//
// OTP area 							0x1FFF7800 - 0x1FFF7A0F 	 528 bytes
// Option bytes 					0x1FFFC000 - 0x1FFFC00F 	  16 bytes
//

#define	SECTOR_SIZE					(0x00004000)

//#define BLOCK_SIZE          512          // Number of bytes per block * see notes in erase code below...
#define BLOCK_SIZE          (SECTOR_SIZE)          // Number of bytes per sector

#define	SECTOR_64K_BASE		(0x08010000)
#define	SECTOR_128K_BASE	(0x08020000)

#define FLASH_START_ADDRESS 0x08000000

//#define CONFIG_ADDRESS      0x08002000   // (Page 4) Location of standard config page
#define CONFIG_ADDRESS      0x08004000   // (Sector 1)) Location of standard config page

//#define APPLICATION_ADDRESS	0x08004800   // (Page 5) Base of applications
#define APPLICATION_ADDRESS	0x08008000   // (Sector 2) Base of applications

//#define BOOTMODE_ADDRESS    0x08002000   // In the CONFIG Structure - determines boot mode
#define BOOTMODE_ADDRESS    (CONFIG_ADDRESS)   // In the CONFIG Structure - determines boot mode

#define NVRAM_ADDRESS  		(CONFIG_ADDRESS)
#define NVRAM_BLOCKS      (1)	//10		//	!!!Ought to be something like (int(sizeof(CD)/NVRAM_BLOCKSIZE)+1) or ((APPLICATION_ADDRESS-NVRAM_ADDRESS)/NVRAM_BLOCKSIZE)
#define NVRAM_BLOCKSIZE   (SECTOR_SIZE)	//1024
	#endif
//==========================================================================================
#else	//	Primarily for 'F1xx based designs
//==========================================================================================

#define APPLICATION_ADDRESS	(0x08004800)   // (Page n) Base of applications

#define NVRAM_ADDRESS  (0x08002000)

	#if		defined(STM32F10X_CL)
#define NVRAM_BLOCKSIZE   (2*1024)
	#else
#define NVRAM_BLOCKSIZE   (1*1024)
	#endif

	#if		001
#define NVRAM_BLOCKS ( (sizeof(CD) + NVRAM_BLOCKSIZE - 1) / NVRAM_BLOCKSIZE )
	#else
#define NVRAM_BLOCKS  (10)		//	!!!Ought to be something like (int(sizeof(CD)/NVRAM_BLOCKSIZE)+1) or ((APPLICATION_ADDRESS-NVRAM_ADDRESS)/NVRAM_BLOCKSIZE)
	#endif
//==========================================================================================
#endif
//==========================================================================================

#if		001	//def	CODE_CRC

//	The CRC for the ROM image is kept at the top of the image.
//	However, this is not a fixed address.
//	So we keep a pointer to this location at a known address: PREDEFINED_CODE_CRC_ADDRESS_POINTER
//	PREDEFINED_CODE_CRC_ADDRESS_POINTER is the fixed address of a pointer to the CRC
//
//	The actual CRC is kept in PREDEFINED_CODE_CRC in the Linker section "CRC_Section" at the top of the ROM image.
//	We initialize PREDEFINED_CODE_CRC to the value PREDEFINED_CODE_CRC (defined in SQDefs.h)
//
//	If CODE_CRC is undefined, the Code space CRC is disabled.

extern	uint32_t	RESET$$Base;	
extern	size_t		RESET$$Length;
extern	uint32_t	RESET$$Limit;

extern	uint32_t	CRC_Section$$Base;	
extern	size_t		CRC_Section$$Length;
extern	uint32_t	CRC_Section$$Limit;

extern	uint32_t	Region$$Table$$Base;	
extern	size_t		Region$$Table$$Length;
extern	uint32_t	Region$$Table$$Limit;		//	For some reason this symbol returns '0x0000'

extern	uint32_t	RW_IRAM2_Section$$Base;	
extern	size_t		RW_IRAM2_Section$$Length;
extern	uint32_t	RW_IRAM2_Section$$Limit;

//	NOTE:	When we compute CRC, we'll include the Boot Loader, the Application up to CRC_Section, (we'll skip CRC_Section) and include the Region$$Table.

#define	ROM_BOOTLOADER_BASE		(0x08000000)
#define	ROM_BOOTLOADER_LENGTH	((size_t)(NVRAM_ADDRESS	-	ROM_BOOTLOADER_BASE))

#define	ROM_APPLICATION_BASE		(&RESET$$Base)
#define	ROM_APPLICATION_LENGTH	((size_t)(&CRC_Section$$Base) - (size_t)ROM_APPLICATION_BASE)

#define	ROM_REGION_TABLE_BASE		(&CRC_Section$$Limit)	//	Top of CRC Section	//	(&Region$$Table$$Base)
#define	ROM_REGION_TABLE_LENGTH	((size_t)(&Region$$Table$$Limit) - (size_t)(&Region$$Table$$Base))	//	This doesn't work, see definition: ((size_t)Region$$Table$$Length)

#define	RAM_APPLICATION_BASE		(&CD)

//Hard code this for now, figure out symbol syntax later...  [not correct for all HW]
#define	RAM_APPLICATION_LENGTH	(0x20000)	//((size_t)(&RW_IRAM2_Section$$Limit))
//RW_IRAM2


#if		defined(F4_BUILD)
#define	PREDEFINED_CODE_CRC_ADDRESS_POINTER	(APPLICATION_ADDRESS+0x0200)
#else
#define	PREDEFINED_CODE_CRC_ADDRESS_POINTER	(0x08004A00)
#endif


extern	const	uint16_t	PREDEFINED_CODE_CRC;
extern	const	uint16_t*	const	POINTER_TO_PREDEFINED_BOOTLOADER_CRC;
extern	const	uint16_t*	const	POINTER_TO_PREDEFINED_TABLE_CRC;
extern	const	uint16_t*	const	POINTER_TO_PREDEFINED_CODE_CRC;

#endif


#define USART1_TX_BUFFERSIZE 8   // header, 3 payload, checksum

#if		not	(defined(ARM_MATH_CM3)	or	defined(ARM_MATH_CM4)	)
#define	PI							(3.1415926535897932384626433832795)	//	from arm_math.h:	#define PI					 3.14159265358979f
#endif

#define RAD2DEG 	      (57.295779513082320876798154814105f)	//(57.2957795)
#define DEG2RAD					(0.0174532925199432957713077440637f)	// Touche...

#define SQ_CAN_TX_QUEUE_LENGTH 12

#if		not	(defined(MA_0083)	or	defined(SQ_RPS_0032)	or	defined(SQ_ION_HW)	or	defined(MA_0127)	or	defined(MA_0130)	or	defined(MA_0131)	or	defined(MA_0134)	or	defined(MA_0144)	or	defined(MA_0166)	or	defined(MA_0192)	or	defined(MA_0192_105_TEST)	or	defined(MA_0219)	or	defined(SQ_RPS_0063) or  defined(SQ_RPS_0064) or  defined(SQ_RPS_0065)	or	defined(MA_0271)  or  defined(MA_0285)  or  defined(MA_0286)	)
#define CAN_TSR_TME0     ((u32)0x04000000) /* Transmit mailbox 0 empty */
#endif

#define CAN_TMIDxR_TXRQ  ((u32)0x00000001) /* Transmit mailbox request */

// Data Status flags
#if		defined(ENHANCED_STATUS_BITS)
#define DSF_CANTXOVERFLOW  	   	 	(0x01)
#define DSF_BAD_ACCEL							(0x02)	//was:DSF_CANTRIGGER1ACTIVE (0x02)
#define DSF_BAD_GYRO							(0x04)	//was:DSF_CANTRIGGER2ACTIVE (0x04)
#define DSF_STUCK_ACCEL						(0x08)	//was:DSF_CANTRIGGER3ACTIVE (0x08)
#define DSF_STUCK_GYRO						(0x10)	//was:DSF_ANGLEMISMATCH     (0x10)
#define DSF_SPI_GYRO							(0x20)	//was:DSF_HIGHACCELERATION  (0x20)
#define DSF_TEMPCOMP				  		(0x40)	//was:DSF_UNUSED_1				  (0x40)
	#if 	defined(GIX300)	and	(defined(SQ_GIX_0219)	)
#define DSF_MAGNETOMETER_CAL_MODE (0x80)
	#else   
#define DSF_ALARMSUPPRESS 	  		(0x80)
	#endif
#else
#define DSF_CANTXOVERFLOW  	   	 	(0x01)
#define DSF_CANTRIGGER1ACTIVE 		(0x02)
#define DSF_CANTRIGGER2ACTIVE 		(0x04)
#define DSF_CANTRIGGER3ACTIVE 		(0x08)
#define DSF_ANGLEMISMATCH     		(0x10)
#define DSF_HIGHACCELERATION  		(0x20)
#define DSF_TEMPCOMP				  		(0x40)	//	was #define DSF_UNUSED_1				  (0x40)
	#if 	defined(GIX300)	and	(defined(SQ_GIX_0219)	)
#define DSF_MAGNETOMETER_CAL_MODE (0x80)
	#else   
#define DSF_ALARMSUPPRESS 	  		(0x80)
	#endif
#endif

//	NOTE:	This structure definition must match the DSF_CANTRIGGERxACTIVE definitions.

typedef	struct	Trigger_Bit_s
{
	//	Note:	This structure definition must match up with DSF_CANTRIGGER1ACTIVE, DSF_CANTRIGGER2ACTIVE and DSF_CANTRIGGER3ACTIVE bit definitions.

	u8	Unused_1	:	1;	
	u8	Trigger_1	:	1;	//	DSF_CANTRIGGER1ACTIVE
	u8	Trigger_2	:	1;	//	DSF_CANTRIGGER2ACTIVE	
	u8	Trigger_3	:	1;	//	DSF_CANTRIGGER3ACTIVE	
	u8	Unused_2	:	4;	
}
Trigger_Bit_t;


typedef	union	Trigger_Status_u
{
	Trigger_Bit_t	bit;
	u8						Byte;
}
Trigger_Status_t;


// Accel Characteristics
#define LOG_ACCEL_MIN          (-1.7f)
#define LOG_ACCEL_MAX          ( 1.7f)

// Angle mismatch "check"
#define DSF_TXOVERFLOW_ONTICKS (2000)
#define ANGLE_MISMATCH_TICKS   (1000)
#define ANGLE_MISMATCH_MARGIN  (3.0f)

// DevInfo flags
#if		defined(ENHANCED_STATUS_BITS)
#define DIF_TEMP        	    	(0x01)
#define DIF_ACCEL_OUT_OF_RANGE	(0x02)	//was:DIF_LIMPMODE          (0x02)
#define DIF_VOLTAGE           	(0x04)
#define DIF_TRIMNOTSET        	(0x08)
#define DIF_GYRO_OUT_OF_RANGE		(0x10)	//was:DIF_MEMFULL           (0x10)
#define DIF_SELFTESTFAIL      	(0x20)
#define DIF_SELFTESTACTIVE    	(0x40)
#define DIF_POST_MOVEMENT				(0x80)	//was:DIF_RESETDUETOFAULT   (0x80)
#else
#define DIF_TEMP        	    	(0x01)
#define DIF_LIMPMODE          	(0x02)
#define DIF_VOLTAGE           	(0x04)
#define DIF_TRIMNOTSET        	(0x08)
#define DIF_MEMFULL           	(0x10)
#define DIF_SELFTESTFAIL      	(0x20)
#define DIF_SELFTESTACTIVE    	(0x40)
#define DIF_RESETDUETOFAULT   	(0x80)
#endif

// For computing yaw acceleration from yaw rate
//#define YAW_HISTORY_BUFFER_LENGTH (10)

// Positions (ADC channels)of (RAW HARDWARE) sensor data in ADC->DMA buffer
#define ADXL203_X (0)
#define ADXL203_Y (1)
#define ADXL203_Z (2)
#define LIS344_X  (3)
#define LIS344_Y  (4)
#define LIS344_Z  (5)
#define LPR530_X  (6)
#define LPR530_Y  (7)
#define LY530_Z   (8)
#define VIN       (9)
#define TEMP      (10)

// USART RX'd COMMANDS
// Values >= 0x80 received by the USART are passed straight thru as
// commands.  Values < 0x80 (ie: ASCII text) are processed in the USART ISR
// and returned from the USART_ISR and command values < 0x80
#if		(defined(SQ_GIX_0021)	or	defined(SQ_CST_0325)	)	//	Partial implementation of legacy SI-360 command set.
#define CMD_INTERROGATE	(0x01)
#define CMD_STREAM      (0x02)
//#define CMD_DONT_USE 		(0x03)  Clashes with CMD_BOOTLOADER_GO 
#define CMD_STREAM_LONG (0x04)
	#if		defined(SQ_CST_0325)
#define CMD_STOP       	(0x18)	//	ASCII: CAN
	#endif
#define CMD_RESET       (0x83)
#endif
#define CMD_NONE             (0x00)
#define CMD_BOOTLOADER_GO	   (0x03)		//legacy issues clashing with legacy SI-360 command set, so we change it to 0x03, ought to be refactored.		//(0x01)
//deprecated:	#define CMD_LOADCONFIG       (0x02)

// 0x80-0x8F used for sensor configuration / config utility
#define CMD_SENDCONFIG   	   (0x80)
//deprecated:	#define CMD_SAVEACCELCAL     (0x82)
//deprecated:	#define CMD_SETGYROZERO      (0x83)
//deprecated:	#define CMD_SETGYROXSCALE    (0x84)
//deprecated:	#define CMD_SETGYROYSCALE    (0x85)
//deprecated:	#define CMD_SETGYROZSCALE    (0x86)
//deprecated:	#define CMD_SAVEGYROCAL      (0x87)
#define CMD_SETTRIM          (0x88)

// 0x90-0xA0 used to stream 3DOF data to DebugView, etc...
#define CMD_STREAM_NONE             (0x90)
#define CMD_STREAM_LOGACCELLPF10HZ  (0x91)
#define CMD_STREAM_HIGACCELLPF10HZ  (0x92)
#define CMD_STREAM_GYRORAW          (0x93)
#define CMD_STREAM_GYROLPF          (0x94)
#define CMD_STREAM_GYRO             (0x95)
#define CMD_STREAM_GYROHPF          (0x96)
#define CMD_STREAM_LOGANGLES        (0x97)
#define CMD_STREAM_HIGANGLES        (0x98)

//deprecated:	#define CMD_STREAM_ANGLEDIFF        (0x99)

#define CMD_STREAM_HIGACCEL         (0x9A)
#define CMD_STREAM_HIGACCELHPF      (0x9B)
#define CMD_STREAM_HIGACCELRMS      (0x9C)
#define CMD_STREAM_LOGACCELLPF2HZ   (0x9D)
#define CMD_STREAM_HIGACCELLPF2HZ   (0x9E)

//deprecated:	#define CMD_STREAM_YAWANDYAWACCEL   (0x9F)

#define CMD_STREAM_LOGACCEL         (0xA0)

//deprecated:	#define CMD_STREAM_ACCELMISMATCH    (0xA1)
//deprecated:	#define CMD_STREAM_ACCELMISMATCHLPF01HZ (0xA2)

#define CMD_STREAM_TEMPVOLTAGE1HZ   (0xA3)
#define CMD_STREAM_LOGRAWLPF2HZ     (0xA4)
#define CMD_STREAM_HIGRAWLPF2HZ     (0xA5)

//deprecated:	#define CMD_STREAM_STABILITY        (0xA6)

#define	CMD_FACTORY_VANDV						(0xAF)

#if		001	//	JLM Debug

#define CMD_JLM_DEBUG               (0xAA)

#define CMD_JLM_DEBUG_PTR           (0xC0)

#endif

//deprecated:	#define CMD_STREAM_MAZZA			(0xA7)


#define CMD_BINARY_DOWNLOAD         (0xB0)
#define CMD_BINARY_ACK			        (0xB1)
#define CMD_BINARY_NACK			        (0xB2)
#define CMD_BINARY_END			        (0xB3)
#define CMD_BINARY_ADDRESS	        (0xB4)
#define CMD_TRIGGER_NOW			        (0xB5)

//deprecated:	#define CMD_ERASE_ALL				        (0xB6)	//	No longer a single byte command


#define MSGID_0  (0x00FFF000	|	CAN_ADDRESS)
#define MSGID_1  (0x00FFF100	|	CAN_ADDRESS)
#define MSGID_2  (0x00FFF200	|	CAN_ADDRESS)
#define MSGID_3  (0x00FFF300	|	CAN_ADDRESS)
#define MSGID_4  (0x00FFF400	|	CAN_ADDRESS)
#define MSGID_5  (0x00FFF500	|	CAN_ADDRESS)
#define MSGID_6  (0x00FFF600	|	CAN_ADDRESS)
#define MSGID_7  (0x00FFF700	|	CAN_ADDRESS)
#define MSGID_9  (0x00FFF900	|	CAN_ADDRESS)

	#if		(defined(TRADE_SHOW_MESSAGES)	)
#define MSGID_A  (0x00FFFA00	|	CAN_ADDRESS)
#define MSGID_B  (0x00FFFB00	|	CAN_ADDRESS)
	#endif
	
#if		defined(SQ_GIX_0209)
#define MSGID_C  (0x00FFFC00	|	CAN_ADDRESS)
#define MSGID_C_SIZE (8)
#endif

// CAN Message Sizes, by ID
#define MSGID_0_SIZE  (8)
#define MSGID_1_SIZE  (8)
#define MSGID_2_SIZE  (8)
#define MSGID_3_SIZE  (8)
#define MSGID_4_SIZE  (8)
#define MSGID_5_SIZE  (8)
#define MSGID_6_SIZE  (8)
#define MSGID_7_SIZE  (8)
#define MSGID_8_SIZE  (8)
#define MSGID_9_SIZE  (8)


#if		not	defined(TRADE_SHOW_MESSAGES)

#define MSGID_10_SIZE (8)

#else

#define MSGID_A_SIZE (8)
#define MSGID_B_SIZE (8)

#endif


u8	Set_DevInfoStatus_Bits(u8	Bits);


#if		001
#define	DISABLE_INTERRUPTS	{__dsb(0); __dmb(0); __disable_irq();}		//	a little redundant but no time to chase this now...
#define	 ENABLE_INTERRUPTS	{__dsb(0); __dmb(0); __enable_irq();}			//	a little redundant but no time to chase this now...
#else
#define	DISABLE_INTERRUPTS	{__dmb(0); __disable_irq();}
#define	 ENABLE_INTERRUPTS	{__dmb(0); __enable_irq();}
#endif


#if 	001

#define	LIMIT(min, arg, max)	( (arg) > (max) ? (max) : (arg) < (min) ?	(min)	:	(arg)	)
#define	ULIMIT(min, arg, max)	( (arg) > (max) ? (max) : (min) == 0 ? (arg) : (arg) < (min) ?	(min)	:	(arg)	)

#define	UINT8_MIN	(0)
#define	UINT16_MIN	(0)

#define	int8_LIMIT(arg)		LIMIT((INT8_MIN), (arg), (INT8_MAX))
#define	int16_LIMIT(arg)	LIMIT((INT16_MIN), (arg), (INT16_MAX))

#define	uint8_LIMIT(arg)	ULIMIT((UINT8_MIN), (arg), (UINT8_MAX))
#define	uint16_LIMIT(arg)	ULIMIT((UINT16_MIN), (arg), (UINT16_MAX))

#else

//	try this on a rainy day...
static	inline	int16_t	LIMIT(int16_t	min, f32	arg, int16_t	max)
{
	if()
	{
	}
	else
	if()
	{
	}
	else
	{
	}

	return();
}

#endif


typedef enum DataRates_t {BAUD_9600, BAUD_38400, BAUD_115200} DataRate_t;


extern	volatile	u8 u8DevInfoStatus;		//	for SQ_SaveConfig()

#if		000
const	uint32_t	BIT0	=	(1<< 0),
const	uint32_t	BIT1	=	(1<< 1),
const	uint32_t	BIT2	=	(1<< 2),
const	uint32_t	BIT3	=	(1<< 3),
const	uint32_t	BIT4	=	(1<< 4),
const	uint32_t	BIT5	=	(1<< 5),
const	uint32_t	BIT6	=	(1<< 6),
const	uint32_t	BIT7	=	(1<< 7),
	
const	uint32_t	BIT8	=	(1<< 8),
const	uint32_t	BIT9	=	(1<< 9),
const	uint32_t	BIT10	=	(1<<10),
const	uint32_t	BIT11	=	(1<<11),
const	uint32_t	BIT12	=	(1<<12),
const	uint32_t	BIT13	=	(1<<13),
const	uint32_t	BIT14	=	(1<<14),
const	uint32_t	BIT15	=	(1<<15),
	    
const	uint32_t	BIT16	=	(1<<16),
const	uint32_t	BIT17	=	(1<<17),
const	uint32_t	BIT18	=	(1<<18),
const	uint32_t	BIT19	=	(1<<19),
const	uint32_t	BIT20	=	(1<<20),
const	uint32_t	BIT21	=	(1<<21),
const	uint32_t	BIT22	=	(1<<22),
const	uint32_t	BIT23	=	(1<<23),
	    
const	uint32_t	BIT24	=	(1<<24),
const	uint32_t	BIT25	=	(1<<25),
const	uint32_t	BIT26	=	(1<<26),
const	uint32_t	BIT27	=	(1<<27),
const	uint32_t	BIT28	=	(1<<28),
const	uint32_t	BIT29	=	(1<<29),
const	uint32_t	BIT30	=	(1<<30),
const	uint32_t	BIT31	=	((uint32_t)1<<31)
#else
typedef	enum	BIT_e
{
	BIT0	=	(1<< 0),
	BIT1	=	(1<< 1),
	BIT2	=	(1<< 2),
	BIT3	=	(1<< 3),
	BIT4	=	(1<< 4),
	BIT5	=	(1<< 5),
	BIT6	=	(1<< 6),
	BIT7	=	(1<< 7),
	
	BIT8	=	(1<< 8),
	BIT9	=	(1<< 9),
	BIT10	=	(1<<10),
	BIT11	=	(1<<11),
	BIT12	=	(1<<12),
	BIT13	=	(1<<13),
	BIT14	=	(1<<14),
	BIT15	=	(1<<15),
	    
	BIT16	=	(1<<16),
	BIT17	=	(1<<17),
	BIT18	=	(1<<18),
	BIT19	=	(1<<19),
	BIT20	=	(1<<20),
	BIT21	=	(1<<21),
	BIT22	=	(1<<22),
	BIT23	=	(1<<23),
	    
	BIT24	=	(1<<24),
	BIT25	=	(1<<25),
	BIT26	=	(1<<26),
	BIT27	=	(1<<27),
	BIT28	=	(1<<28),
	BIT29	=	(1<<29),
	BIT30	=	(1<<30),
	BIT31	=	0x8000	//((uint32_t)1<<31)
}
BIT_t;
#endif


typedef	struct	Two_Bit_Matrix_s
{
	int32_t	R1C1	:	2;	int32_t	R1C2	:	2;	int32_t	R1C3	:	2;	int32_t	R1C4	:	2;	
	int32_t	R2C1	:	2;	int32_t	R2C2	:	2;	int32_t	R2C3	:	2;	int32_t	R2C4	:	2;	
	int32_t	R3C1	:	2;	int32_t	R3C2	:	2;	int32_t	R3C3	:	2;	int32_t	R3C4	:	2;	
	int32_t	R4C1	:	2;	int32_t	R4C2	:	2;	int32_t	R4C3	:	2;	int32_t	R4C4	:	2;	
}
Two_Bit_Matrix_t;

typedef	struct	Eight_Bit_Row_Matrix_s
{
	#if		001
	uint8_t	Row[4];
	#else
	int32_t	R1C1_R1C2_R1C3_R1C4	:	8;	
	int32_t	R2C1_R2C2_R2C3_R2C4	:	8;	
	int32_t	R3C1_R3C2_R3C3_R3C4	:	8;	
	int32_t	R4C1_R4C2_R4C3_R4C4	:	8;	
	#endif
}
Eight_Bit_Row_Matrix_s;

typedef	union	Bit_Matrix_u
{
	Two_Bit_Matrix_t				RC;
	Eight_Bit_Row_Matrix_s	Row;
}
Bit_Matrix_t;

extern	const	Bit_Matrix_t	Orientation_Table[];


typedef	enum	Orientation_e		//Relocated here from SQ_J1939.h
{
	SQOR_00	=	 0,
	SQOR_01	=	 1,
	SQOR_02	=	 2,
	SQOR_03	=	 3,
	SQOR_04	=	 4,
	SQOR_05	=	 5,
	SQOR_06	=	 6,
	SQOR_07	=	 7,
	SQOR_08	=	 8,
	SQOR_09	=	 9,
	SQOR_10	=	10,
	SQOR_11	=	11,
	SQOR_12	=	12,
	SQOR_13	=	13,
	SQOR_14	=	14,
	SQOR_15	=	15,
	SQOR_16	=	16,
	SQOR_17	=	17,
	SQOR_18	=	18,
	SQOR_19	=	19,
	SQOR_20	=	20,
	SQOR_21	=	21,
	SQOR_22	=	22,
	SQOR_23	=	23,
}
Orientation_t;

#endif		//	not	defined(SCATTER_FILE)

//*********************************************************************************************
#endif // SQDEFS_H_
//*********************************************************************************************
