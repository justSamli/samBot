/*
 * pin_config.c
 *
 *  Created on: 1 Apr 2019
 *      Author: samli
 */
#include <msp430.h>
#include "pin_config.h"

void set_pins(void) {
    P2SEL |= (BIT0|BIT2|BIT3|BIT4);     //set sensor pins for GPIO
    P2SEL &= ~(BIT1|BIT5);     //set motor pins for GPIO
    P2SEL2 &= ~(BIT0|BIT2|BIT3|BIT4);
    P2SEL2 &= ~(BIT1|BIT5);

    P2DIR |= (BIT2|BIT4);         //output pins PWM A and B motor speed
    P2DIR |= (BIT1|BIT5);         //output pins motors A and B motor direction
    P2DIR &= ~(BIT0|BIT3);        //input pins

    P1DIR &= ~(BIT2|BIT4);      //set inputs
    P1OUT &= ~(BIT2|BIT4);         //set output as low

}

