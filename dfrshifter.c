/*
 * Include Necessary Headers and Libraries
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>
#include "HMC_state_machine.h"
#include "dfrshifter.h"
#include "DFR_SPI.h"

int timer = 0;		//Counting timer for shifting state of shifter function
int thresh = 3; 	//number of times method should be called before turning off shift solenoids
int gr = 0; 		//placeholder for gear for debugging)
int shiftTarget; 	//gear that is being shifted to currently (while in state 6)
enum gear t_gear; 	//Enum gear variable for target gear for shift
extern input_vector_t input_vector;

enum gear get_gear(void){
	

	float motor_shaft_speed = input_vector.motor_rpm; 
	float engine_rpm_speed = input_vector.engine_rpm;

	enum gear gear_calc;
	float current_gear_ratio;
	float gear_1_ratio = (13.0f/32.0f)*(24.0f/73.0f); // = .13356
	float gear_2_ratio = (16.0f/32.0f)*(24.0f/73.0f); // = .16438
	float gear_3_ratio = (17.0f/28.0f)*(24.0f/73.0f); // = .19961
	float gear_4_ratio = (19.0f/26.0f)*(24.0f/73.0f); // = .24025
	float gear_5_ratio = (21.0f/25.0f)*(24.0f/73.0f); // = .27616

	current_gear_ratio = motor_shaft_speed/engine_rpm_speed;

	if (current_gear_ratio <= gear_1_ratio + .01f && current_gear_ratio >= gear_1_ratio -.01f)			// create .02 band around each gear ratio
		{
			gear_calc = Gear1;
		}
		else if (current_gear_ratio <= gear_2_ratio + .01f && current_gear_ratio >= gear_2_ratio -.01f)
		{
			gear_calc = Gear1;
		}
		else if (current_gear_ratio <= gear_3_ratio + .01f && current_gear_ratio >= gear_3_ratio -.01f)
		{
			gear_calc = Gear3;
		}
		else if (current_gear_ratio <= gear_4_ratio + .01f && current_gear_ratio >= gear_4_ratio -.01f)
		{
			gear_calc = Gear4;
		}
		else if (current_gear_ratio <= gear_5_ratio + .01f && current_gear_ratio >= gear_5_ratio -.01f)
		{
			gear_calc = Gear5;
		}
		else
		{
			gear_calc = Shifting;
		}

	return gear_calc;

}


enum gear shifter_hybrid_mode(enum gear c_gear, int RPM, bool uPressed, bool dPressed, bool cPressed)
{
    /*
    function takes in current state and returns state at end

    state: current gear position where:
        0 = neutral
        1-5 = gear number
        6 = currently shifting

    RPM = current wheel speed
    uPressed = upshift button depressed
    dPressed = downshift button depressed
    cPressed = clutch is depressed
    */

	//conditional for who controls gear
	if((cPressed) && (c_gear != Shifting)){		//if clutch is out and state is not shifting ??OR NEUTRAL>>>
		c_gear = get_gear();
	}else{
		// use the gear that was passed in for the switch statement...
	}
	
	switch(c_gear)
	{
     	 case Neutral:
     		 /*Print Current Gear*/
     		 printf("neutral\n\r");
					
					//Both Buttons Pressed So Do Nothing
					if (dPressed && uPressed)
					{
						printf("Both buttons pressed. Invalid Shift\n\r");
						return c_gear;
					}
				
     		 if (dPressed && validShift(1, RPM) && cPressed)
     		 {
     			 //shift is valid, set timer to 0 and go to shifting state
     			 timer = 0;
     			 downshift();
     			 t_gear = Gear1;
     			 return Shifting;
     		 }

     		 /*Valid Upshift*/
     		 if (uPressed && cPressed)
     		 {
     			//shift is valid, set timer to 0 and go to shifting state
     			 timer = 0;
     			 upshift();
     			 t_gear = Gear2;
     			 return Shifting;
     		 }

     		 /*Invalid Shift Request*/
     		 if (uPressed)
     		 {
     			 printf("invalid shift\n\r");
     			 return c_gear;
     		 }

     		 /*No Shift Request*/
     		 else
     		 {
     			 return c_gear;
     		 }
     		 // break;

     	 case Gear1:
     		 /*Print Current Gear*/
     		 printf("one\n\r");
			 
					//Both Buttons Pressed So Do Nothing
					if (dPressed && uPressed)
					{
						printf("Both buttons pressed. Invalid Shift\n\r");
						return c_gear;
					}

     		 /*Cannot Down shift in First Gear*/
     		 if (dPressed)
     		 {
     			 printf("cannot down shift from gear 1\n\r");
     			 return c_gear;
     		 }

     		 /*Valid Upshift Request*/
     		 if (uPressed && validShift(2, RPM) && cPressed)
     		 {
     			 //shift is valid, set timer to 0 and go to shifting state
     			 timer = 0;
     			 upshift();
     			 t_gear = Gear2;
     			 return Shifting;
     		 }

     		 /*Invalid Shift Request*/
     		 if (uPressed)
     		 {
     			 printf("invalid shift\n\r");
     			 return c_gear;
     		 }

     		 /*No Shift Request*/
     		 else
     		 {
     			 return c_gear;
     		 }
     		 //break;

     	 case Gear2:
     		 /*Print Current Gear*/
     		 printf("two\n\r");
			 
					//Both Buttons Pressed So Do Nothing
					if (dPressed && uPressed)
					{
						printf("Both buttons pressed. Invalid Shift\n\r");
						return c_gear;
					}

     		 /*Valid Down shift Request*/
     		 if (dPressed && validShift(1, RPM) && cPressed)
     		 {
     			 //shift is valid, set timer to 0 and go to shifting state
     			 timer = 0;
     			 downshift();
     			 t_gear = Gear1;
     			 return Shifting;
     		 }

     		 /*Valid Up Shift Request*/
     		 if (uPressed && validShift(3, RPM) && cPressed)
     		 {
     			//shift is valid, set timer to 0 and go to shifting state
     			 timer = 0;
     			 upshift();
     			 t_gear = Gear3;
     			 return Shifting;
     		 }

     		 /*Invalid Shift Request*/
     		 if (uPressed || dPressed)
     		 {
     			 printf("invalid shift\n\r");
     			 return c_gear;
     		 }

     		 /*No Shift Request*/
     		 else
     		 {
     			 return c_gear;
     		 }
     		 //break;

     	 case Gear3:
     		 /*Print Current Gear*/
     		 printf("three\n\r");
			 
					//Both Buttons Pressed So Do Nothing
					if (dPressed && uPressed)
					{
						printf("Both buttons pressed. Invalid Shift\n\r");
						return c_gear;
					}

     		 /*Valid Down shift Request*/
     		 if (dPressed && validShift(2, RPM) && cPressed)
     		 {
     			 //shift is valid, set timer to 0 and go to shifting state
     		     timer = 0;
     		     downshift();
     		     t_gear = Gear2;
     		     return Shifting;
     		 }

     		 /*Valid Up Shift Request*/
     		 if (uPressed && validShift(4, RPM) && cPressed)
     		 {
     			//shift is valid, set timer to 0 and go to shifting state
     			 timer = 0;
     			 upshift();
     			 t_gear = Gear4;
     			 return Shifting;
     		 }

     		 /*Invalid Shift Request*/
     		 if (dPressed || uPressed)
     		 {
     			 printf("invalid shift\n\r");
     			 return c_gear;
     		 }

     		 /*No Shift Request*/
     		 else
     		 {
     			 return c_gear;
     		 }
     		// break;

     	 case Gear4:
     		 /*Print Current Gear*/
     		 printf("four\n\r");
			 
					//Both Buttons Pressed So Do Nothing
					if (dPressed && uPressed)
					{
						printf("Both buttons pressed. Invalid Shift\n\r");
						return c_gear;
					}

     		 /*Valid Down Shift*/
     		 if (dPressed && validShift(3, RPM) && cPressed)
     		 {
     			//shift is valid, set timer to 0 and go to shifting state
     			 timer = 0;
     			 downshift();
     			 t_gear = Gear3;
     			 return Shifting;
     		 }

     		 /*Valid Up Shift*/
     		 if (uPressed && validShift(5, RPM) && cPressed)
     		 {
     			//shift is valid, set timer to 0 and go to shifting state
     			 timer = 0;
     			 upshift();
     			 t_gear = Gear5;
     			 return Shifting;
     		 }

     		 /*Invalid Shift Request*/
     		 if (uPressed || dPressed)
     		 {
     			 printf("invalid shift\n\r");
     			 return c_gear;
     		 }

     		 /*No Shift Request*/
     		 else
     		 {
     			 return c_gear;
     		 }
     		 // break;

     	 case Gear5:
     		 /*Print Current Gear*/
     		 printf("five\n\r");
			 
					//Both Buttons Pressed So Do Nothing
					if (dPressed && uPressed)
					{
						printf("Both buttons pressed. Invalid Shift\n\r");
						return c_gear;
					}

     		 /*Can't Upshift in 5th Gear*/
     		 if (uPressed)
     		 {
     			 printf("cannot upshift in Gear 5\n\r");
     			 return c_gear;
     		 }

     		 /*Valid Down Shift*/
     		 if (dPressed && validShift(4, RPM) && cPressed)
     		 {
     			//shift is valid, set timer to 0 and go to shifting state
     			 timer = 0;
     			 downshift();
     			 t_gear = Gear4;
     			 return Shifting;
     		 }

     		 /*Invalid Shift Request*/
     		 if (dPressed)
     		 {
     			 printf("invalid shift\n\r");
     			 return c_gear;
     		 }

     		 /*No Shift Requested*/
     		 else
     		 {
     			 return c_gear;
     		 }
     	//	 break;

     	 case Shifting:
            timer++;
						printf("Shifting, current timer value is: %d\n\r",timer);
            if (timer >= thresh) //RENAME to shifter time threshold 
            {
                offshift();
                return t_gear;
							
            }
            return Shifting;
       // break;

     default :
        printf("not recognized\n\r");
        return c_gear;
  }
}

typedef enum gas_shift_e{
	gas_shift_upshift,
	gas_shift_downshift,
	gas_shift_off,
	gas_shift_timer_out,
	
} gas_shift_t;

gas_shift_t gas_shift_state;
int gas_shift_countdown;
#define GAS_SHIFT_COUNTDOWN_LOAD 5

enum gear shifter_gas_mode(enum gear c_gear, int RPM, bool uPressed, bool dPressed, bool cPressed)
{
	if(gas_shift_countdown > GAS_SHIFT_COUNTDOWN_LOAD)
		{
			// logic fault.. recover
			gas_shift_state = gas_shift_off;
		}
		else
		if (~cPressed)
		{
			gas_shift_state = gas_shift_off;
		}
		else
		if (gas_shift_countdown)
		{
			gas_shift_countdown--;
		}
		else
		{
				// do nothing
		}

	switch(gas_shift_state)
	{
		default:
		case gas_shift_off:
		{
			SPI_output_vector.solenoid_1 = OFF;
			SPI_output_vector.solenoid_2 = OFF;
			
			if(input_vector.green_button){
				gas_shift_state = gas_shift_upshift;
				gas_shift_countdown = GAS_SHIFT_COUNTDOWN_LOAD;
			} else if(input_vector.red_button){
				gas_shift_state = gas_shift_downshift;
				gas_shift_countdown = GAS_SHIFT_COUNTDOWN_LOAD;
			} else {
				gas_shift_state = gas_shift_off;
			}
		}
		break;
		
		case gas_shift_upshift:
		{
			SPI_output_vector.solenoid_1 = OFF;
			SPI_output_vector.solenoid_2 = ON;
			
			if(gas_shift_countdown > 0)
			{
				gas_shift_state = gas_shift_upshift;
			} else {
				gas_shift_state = gas_shift_timer_out;
			}
		}
		break;
		
			case gas_shift_downshift:
		{
			SPI_output_vector.solenoid_1 = ON;
			SPI_output_vector.solenoid_2 = OFF;
			
			if(gas_shift_countdown > 0)
			{
				gas_shift_state = gas_shift_downshift;
			} else {
				gas_shift_state = gas_shift_timer_out;
			}
		}
		break;
		
		
		case gas_shift_timer_out:
		{
			SPI_output_vector.solenoid_1 = OFF;
			SPI_output_vector.solenoid_2 = OFF;
			
			if(!input_vector.green_button & !input_vector.red_button){
				gas_shift_state = gas_shift_off;
			} else {
				gas_shift_state = gas_shift_timer_out;
		}
		break;
		}
	} 
}

  
bool validShift(int target, int RPM)
{
		float PR = 24./73; //primary reduction gear ratio
    float gears[6] = {0,13./32,16./32,17./28,19./26,21./25}; //gear ratios of transmission, uses 0 so that indices match gear
    float ratios[6] = {0,(PR*gears[1]),(PR*gears[2]),(PR*gears[3]),(PR*gears[4]),(PR*gears[5])}; //PR*gear, gives actual ratio, ratio[x] is the ratio for gear X 
		
    //printf("Ratios: %f, %f, %f, %f, %f \n",1./ratios[0],1./ratios[1],1./ratios[2],1./ratios[3],1./ratios[4]);

    //int lugRPM = 2400; //RPM below which engine may lug
    int redline = 12000; //RPM for redline

    if (redline > 14000) //DO NOT DELETE
        redline = 14000; //safety measure to cap redline at 14,000


    int newVal = (int)(RPM*(1/ratios[target])); //value for current engine RPM given wheelspeed in target gear

    //if ((newVal > lugRPM) && (newVal< redline))
	  if (newVal< redline)
    {
        printf("Gear Target Value: %d, RPM: %d\n\r",target,newVal);
        printf("valid\n\r");
        return true;
    } else {
        printf("Gear Target Value: %d, New RPM: %d\n\r",target,newVal);
        printf("invalid\n\r");
        return false;
    }

}

//Upshift function
void upshift(void)
{
	//shiftTarget=st;
    //send upshift to output matrix
    printf("DID UPSHIFT!\n\r");
		SPI_output_vector.solenoid_2 = ON;
}

//Down shift function
void downshift(void)
{
    //send downshift to output matrix
	//shiftTarget=st;
    printf("DID DOWNSHIFT!\n\r");
		SPI_output_vector.solenoid_1 = ON;
}

//Off Shift Function
void offshift(void)
{
	printf("Turned off solenoid\n\r");
    //output shifter solenoids both off
	SPI_output_vector.solenoid_1 = OFF;
	SPI_output_vector.solenoid_2 = OFF;
}








#if 000
int main()
{
    printf("Hello, World!\n\");
    validShift(0, 500);
    validShift(2, 1000);
	gr = shifter(gr, 500, true, false, true);
	printf("Current Value for gr: %d",gr);
	gr = shifter(gr, 500, true, false, true);
	printf("Current Value for gr: %d",gr);
	gr = shifter(gr, 500, true, false, true);
	printf("Current Value for gr: %d",gr);
    return 0;
}

#endif 


void test_shifter_algorithm (void) {
	
	 //Declare Test Variables
    enum gear test_gear;
    int t_eRPM;
    bool t_upressed;
    bool t_dpressed;
    bool t_cpressed;

    //Start Gear Test in Neutral
    test_gear = Neutral;
    t_eRPM = 0;
    t_upressed = false;
    t_dpressed = false;
    t_cpressed = false;

#if 001
    /**********************************Neutral to Gear1 Testing**************************************/
    printf("Begin Test\n\r");
    printf("****************Neutral to Gear1 Up Shift Testing****************\n\r");
    //Shift down neutral to 1st
    t_eRPM = 0;
    t_upressed = false;
    t_dpressed = true;
    t_cpressed = true;
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);
		test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 1
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 2
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 3 then timer  = 0
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//Make sure it stays in gear
		printf("Neutral --> 1 complete \n\r");

    //Test invalid up shift to Gear 1 (Missing Clutch Press)
    t_eRPM = 0;
    t_upressed = true;
    t_dpressed = false;
    t_cpressed = false;
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);

    //Test valid up shift to Gear 1
    t_eRPM = 0;
    t_upressed = true;
    t_dpressed = false;
    t_cpressed = true;
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);
    t_upressed = t_cpressed = false;
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 1
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 2
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 3 then timer  = 0
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//Make sure it stays in gear
    printf("\n\n\n");

    /**********************************Gear1 to Gear2 Testing**************************************/
    printf("****************Gear1 to Gear2 Up Shift Testing****************\n\r");
//    //Test invalid up shift to Gear 2 (Stall Out) THIS SHOULD NOW WORK HAVING COMMENTED OUT LUG PROTECTION
//    t_eRPM = 329;
//    t_upressed = true;
//    t_dpressed = false;
//    t_cpressed = true;
//    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);

    //Test invalid up shift to Gear 2 (Missing Clutch Press)
    t_eRPM = 1096;
    t_upressed = true;
    t_dpressed = false;
    t_cpressed = false;
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);

    //Test valid up shift to Gear 2
    t_eRPM = 1096;
    t_upressed = true;
    t_dpressed = false;
    t_cpressed = true;
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);
    t_upressed = t_cpressed = false;
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 1
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 2
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 3 then timer  = 0
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//Make sure it stays in gear
    printf("\n\n\n");

    /**********************************Gear2 to Gear3 Testing**************************************/
    printf("****************Gear2 to Gear3 Up Shift Testing****************\n\r");
//    //Test invalid up shift to Gear 3 (Stall Out)
//    t_eRPM = 399;
//    t_upressed = true;
//    t_dpressed = false;
//    t_cpressed = true;
//    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);

    //Test invalid up shift to Gear 3 (Missing Clutch Press)
    t_eRPM = 1331;
    t_upressed = true;
    t_dpressed = false;
    t_cpressed = false;
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);

    //Test valid up shift to Gear 3
    t_eRPM = 1331;
    t_upressed = true;
    t_dpressed = false;
    t_cpressed = true;
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);
    t_upressed = t_cpressed = false;
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 1
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 2
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 3 then timer  = 0
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//Make sure it stays in gear
    printf("\n\n\n");

    /**********************************Gear3 to Gear4 Testing**************************************/
    printf("****************Gear3 to Gear4 Up Shift Testing****************\n\r");
//    //Test invalid up shift to Gear 4 (Stall Out)
//    t_eRPM = 480;
//    t_upressed = true;
//    t_dpressed = false;
//    t_cpressed = true;
//    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);

    //Test invalid up shift to Gear 4 (Missing Clutch Press)
    t_eRPM = 1601;
    t_upressed = true;
    t_dpressed = false;
    t_cpressed = false;
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);

    //Test valid up shift to Gear 4
    t_eRPM = 1601;
    t_upressed = true;
    t_dpressed = false;
    t_cpressed = true;
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);
    t_upressed = t_cpressed = false;
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 1
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 2
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 3 then timer  = 0
    test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//Make sure it stays in gear
    printf("\n\n\n");

    /**********************************Gear4 to Gear5 Testing**************************************/
    printf("****************Gear4 to Gear5 Up Shift Testing****************\n\r");
//    //Test invalid up shift to Gear 5 (Stall Out)
//    t_eRPM = 552;
//    t_upressed = true;
//    t_dpressed = false;
//    t_cpressed = true;
//	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);

	//Test invalid up shift to Gear 5 (Missing Clutch Press)
	t_eRPM = 1841;
	t_upressed = true;
	t_dpressed = false;
	t_cpressed = false;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);

	//Test valid up shift to Gear 5
	t_eRPM = 1841;
	t_upressed = true;
	t_dpressed = false;
	t_cpressed = true;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);
	t_upressed = t_cpressed = false;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 1
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 2
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 3 then timer  = 0
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//Make sure it stays in gear
	printf("\n\n\n");

	/**********************************Gear5 to Gear4 Testing**************************************/
	printf("****************Gear5 to Gear4 Down Shift Testing****************\n\r");
	//Ensure that Driver cannot shift up in Gear5
	t_eRPM = 1841;
	t_upressed = true;
	t_dpressed = false;
	t_cpressed = true;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);

	//Test invalid down shift to Gear4 (Redline)
	t_eRPM = 3844;
	t_upressed = false;
	t_dpressed = true;
	t_cpressed = true;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);

	//Test invalid down shift to Gear4 (Missing Clutch Press)
	t_eRPM = 1601;
	t_upressed = false;
	t_dpressed = true;
	t_cpressed = false;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);

	//Test valid down shift to Gear4
	t_eRPM = 1601;
	t_upressed = false;
	t_dpressed = true;
	t_cpressed = true;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);
	t_dpressed = t_cpressed = false;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 1
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 2
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 3 then timer  = 0
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//Make sure it stays in gear
	printf("\n\n\n");

	/**********************************Gear4 to Gear3 Testing**************************************/
	printf("****************Gear4 to Gear3 Down Shift Testing****************\n\r");
	//Test invalid down shift to Gear3 (Redline)
	t_eRPM = 3194;
	t_upressed = false;
	t_dpressed = true;
	t_cpressed = true;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);

	//Test invalid down shift to Gear3 (Missing Clutch Press)
	t_eRPM = 1331;
	t_upressed = false;
	t_dpressed = true;
	t_cpressed = false;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);

	//Test valid down shift to Gear3
	t_eRPM = 1331;
	t_upressed = false;
	t_dpressed = true;
	t_cpressed = true;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);
	t_dpressed = t_cpressed = false;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 1
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 2
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 3 then timer  = 0
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//Make sure it stays in gear
	printf("\n\n\n");

	/**********************************Gear3 to Gear2 Testing**************************************/
	printf("****************Gear3 to Gear2 Down Shift Testing****************\n\r");
	//Test invalid down shift to Gear2 (Redline)
	t_eRPM = 2630;
	t_upressed = false;
	t_dpressed = true;
	t_cpressed = true;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);

	//Test invalid down shift to Gear2 (Missing Clutch Press)
	t_eRPM = 1096;
	t_upressed = false;
	t_dpressed = true;
	t_cpressed = false;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);

	//Test valid down shift to Gear2
	t_eRPM = 1096;
	t_upressed = false;
	t_dpressed = true;
	t_cpressed = true;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);
	t_dpressed = t_cpressed = false;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 1
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 2
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 3 then timer  = 0
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//Make sure it stays in gear
	printf("\n\n\n");

	/**********************************Gear2 to Gear1 Testing**************************************/
	printf("****************Gear2 to Gear1 Down Shift Testing****************\n\r");
	//Test invalid down shift to Gear1 (Redline)
	t_eRPM = 2137;
	t_upressed = false;
	t_dpressed = true;
	t_cpressed = true;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);

	//Test invalid down shift to Gear1 (Missing Clutch Press)
	t_eRPM = 890;
	t_upressed = false;
	t_dpressed = true;
	t_cpressed = false;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);

	//Test valid down shift to Gear1
	t_eRPM = 890;
	t_upressed = false;
	t_dpressed = true;
	t_cpressed = true;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);
	t_dpressed = t_cpressed = false;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 1
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 2
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//timer = 3 then timer  = 0
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);		//Make sure it stays in gear
	printf("\n\n\n\r");
	
	/**********************************Double Button Error Testing**************************************/
	printf("****************Double Button Error Testing****************\n\r");
		
	//Gear1 Test
	t_eRPM = 2630;
	t_upressed = true;
	t_dpressed = true;
	t_cpressed = true;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);
	//Gear2 Test
	test_gear = Gear2;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);
	//Gear3 Test
	test_gear = Gear3;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);
	//Gear4 Test
	test_gear = Gear4;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);
	//Gear5 Test
	test_gear = Gear5;
	test_gear = shifter_hybrid_mode(test_gear, t_eRPM, t_upressed, t_dpressed, t_cpressed);
	printf("\n\n\n\r");

	printf("Testing Complete\n\r");
	
	
	#endif

}

