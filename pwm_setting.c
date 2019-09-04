/*
 * pwm_setting.c
 *
 *  Created on: 2 Apr 2019
 *      Author: samli
 */
#include <msp430.h>
#include "pwm_setting.h"

void set_timer(void)
{
    TA1CTL = (TASSEL_2 | MC_1);    //source SMCLK
    TA1CCTL1 |= OUTMOD_7;            // set the mode
    TA1CCTL2 |= OUTMOD_7;
    TA1CCR0 = 200;                 // set TACCRO value
}

void backward(void)
{
    P2OUT |= BIT1;
    P2OUT &= ~BIT5;
    TA1CCR1 = 10;                 // set TACCR1 value
    TA1CCR2 = 10;                 // set TACCR2 value
}

void forward(void)
{
        P2OUT &= ~BIT1;
        P2OUT |= BIT5;
        TA1CCR1 = 45;                 // set TACCR1 value on right wheel
        TA1CCR2 = 45;                 // set TACCR2 value on left wheel
}

void turn_right(void)
{
        TA1CCR1 = 40;                 // reduce speed
        TA1CCR2 = 15;
}

void turn_left(void)
{
        TA1CCR1 = 15;
        TA1CCR2 = 40;                 // reduce speed
}


void stop_sambot(void)
{
    TA1CCR1 = 0;    // stop both wheels
    TA1CCR2 = 0;
}
