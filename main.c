#include <ADC.h>

#include "adc.h"
#include <msp430.h> 
#include "pin_config.h"
#include "pwm_setting.h"


/**
 * main.c
 */
int left_sense, right_sense, dist_sense_left, dist_sense_right;
void main(void)
{	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    ADC_init();     // initialise the ADC ports
	set_pins();
	set_timer();

	BCSCTL1= CALBC1_1MHZ;           //frequency of clock set to 1MHz
	DCOCTL= CALDCO_1MHZ;

//	forward();

	while(1)
	  {

//	    right_sense =  ADC_convert_and_read(2);
//        left_sense =  ADC_convert_and_read(1);

	    dist_sense_left = ADC_convert_and_read(3);
	    dist_sense_right = ADC_convert_and_read(4);

	    if((dist_sense_left > 420) || (dist_sense_right > 420))
	    {
	        stop_sambot();
	    }

	    else {

	     right_sense =  ADC_convert_and_read(2);
	     if(right_sense < 500)
	     {
	        turn_right();
	     }

	     left_sense =  ADC_convert_and_read(1);
	     if(left_sense < 500)
	     {
	        turn_left();
	     }

	     if((left_sense > 500) && (right_sense > 500))
	     {
	        forward();
	     }

	    }
	  }

}
