#include "msp.h"
#include <stdint.h>
#include <stdio.h>
#include "struct.h"


/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief Main file for the C1M1V5 Video Demos
 *
 * @author Alex Fosdick
 * @date April 15 2017
 *
 *
 * @modified by: Rudy Flores Jr.
 * @date 07/31/23
 *
 *@brief added button presses and Timer32 to measure latency of different types of structs
 */






void Timer32_Init() {
    // Configure Timer32
    TIMER32_1->LOAD = 0xFFFFFFFF; // Set timer to count down from max value
    TIMER32_1->CONTROL = TIMER32_CONTROL_PRESCALE_0 | TIMER32_CONTROL_SIZE | TIMER32_CONTROL_MODE;
}


void Timer32_Start() {
    TIMER32_1->CONTROL |= TIMER32_CONTROL_ENABLE; // Start the timer
}


void Timer32_Stop() {
    TIMER32_1->CONTROL &= ~TIMER32_CONTROL_ENABLE; // Stop the timer
}


uint32_t Timer32_GetValue() {
    return TIMER32_1->VALUE; // Read the current timer value
}

void Timer32_Reset() {
    TIMER32_1->LOAD = 0xFFFFFFFF; // Reset the timer value to  0xFFFFFFFF
}

/**
 * main.c
 */


void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	/* Offboard Switch S4 is a PULLDOWN */
	P3->DIR &= ~(BIT6);
	P3->OUT &= ~(BIT6);


	/* Offboard Switch S3 is a PULLUP*/
	P2->DIR &= ~(BIT5);
	P2->OUT |= (BIT5);



	  ex_normal_t str0;
	  ex_packed_t str1;
	  ex_fast_t str2;

	  uint32_t outOneNormal;
	  uint32_t outTwoPacked;
	  uint32_t outThreeFast;


	  uint32_t oneThreeTimeValue;
      uint32_t twoTimeValue;

	  str0.x = 1;
	  str0.y = 2;
	  str0.z = 3;


	  str1.x = 1;
	  str1.y = 2;
	  str1.z = 3;


      str2.x = 1;
      str2.y = 2;
      str2.z = 3;

	  printf("Sizeof Normal Struct: %d\n", sizeof(str0));
	  printf("Sizeof Packed Struct: %d\n", sizeof(str1));
	  printf("Sizeof Fast Struct: %d\n",sizeof(str2));


	  printf("str0 address: %u\n", (uint32_t)(&(str0)));
	  printf("x address: %u\n", (uint32_t)(&(str0.x)));
	  printf("y address: %u\n", (uint32_t)(&(str0.y)));
	  printf("z address: %u\n", (uint32_t)(&(str0.z)));

	  printf("str1 address: %u\n", (uint32_t)(&(str1)));
	  printf("x address: %u\n", (uint32_t)(&(str1.x)));
	  printf("y address: %u\n", (uint32_t)(&(str1.y)));
	  printf("z address: %u\n", (uint32_t)(&(str1.z)));

	  printf("str2 address: %u\n", (uint32_t)(&(str2)));
	  printf("x address: %u\n", (uint32_t)(&(str2.x)));
	  printf("y address: %u\n", (uint32_t)(&(str2.y)));
	  printf("z address: %u\n", (uint32_t)(&(str2.z)));



	  printf("The size of 1 integar is %d \n.",sizeof(uint32_t));

	  Timer32_Init();


while (1) {



	      if((P3->IN & BIT6) == BIT6){
	            printf("Did the dobounce go here?\n");          //Printf to aid in debouncing
	            printf("Now adding all members of normal/fast struct\n");
	            Timer32_Start();
	     //   outOneNormal = str0.x + str0.y + str0.z;          //Feel free to swap out w/below v
                outThreeFast = str2.x + str2.y + str2.z;
	            Timer32_Stop();
	            oneThreeTimeValue = Timer32_GetValue();         //This can stay the same
	       // printf("The answer is %d\n",outOneNormal);
	            printf("The answer is %d\n",outThreeFast);      //Feel free to swap out w/above ^
                printf("It took %d\n",oneThreeTimeValue);
                Timer32_Reset();

	      }


	      else if( (P2->IN & BIT5) != BIT5){

	                       printf("Did the dobounce go here?\n");
	                       printf("Now adding all members of packed struct two\n");
	                       Timer32_Start();
	                       outTwoPacked = str1.x + str1.y + str1.z;
	                       Timer32_Stop();
	                       twoTimeValue = Timer32_GetValue();
	                       printf("The answer is %d\n",outTwoPacked);
	                       printf("It took %d\n",twoTimeValue);
	                       Timer32_Reset();
	                       __delay_cycles(111000);
	      }

	      else{

	      }




	  }




}
