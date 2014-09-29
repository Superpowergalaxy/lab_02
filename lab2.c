/*  Names: Yiyang Li & Jingyu Su
    Section: 1
    Date: 
    File name: lab_02.c
    Description: 
*/

#include <c8051_SDCC.h>// include files. This file is available online
#include <stdio.h>
#include <stdlib.h>


//-----------------------------------------------------------------------------
// Function Prototypes
//-----------------------------------------------------------------------------
void Port_Init(void);
void ADC_Init(void);
unsigned char read_AD_input(unsigned char n);
unsigned char random(void);

//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------

/* This program demonstrates how to perform an A/D Conversion */
void main(void)
{
	unsigned char result;
	Sys_Init(); // Initialize the C8051 board
	Port_Init(); // Configure P1.0 for analog input
	ADC_Init(); // Initialize A/D conversion
	while (1)
	{
		Buzzer = 0;
		LED0 = 0;
		LED1 = 0;
		LED2 = 0;
		LED3 = 0;
		BILED0 = 0;
		BILED1 = 0;
		counts = 0;
		printf("\rReady to start\n");
		ADC_value = read_AD_input(pin_number);
		voltage_value = ADC_value*2.4/256;
		for(i=0;i < 3;i++)
		{
			BILED0 = 0;
			BILED0 = 1;
			while (counts <); //wait for 3 seconds
			while () // loop until 2 collisions or 7 obstacles
			{
				random_number = random(void);
				if (random_number == ){}
				else if (random_number == ){}
				if ()
				{
					score++;
				}
				else
				{
					error++;
				}
				
			}
			while() //loop until ... same as above
			{}
		}
		while()
		result = read_AD_input(0); // Read the A/D value on P1.0
		//clear
		printf("\rScore: %d\n",score);
		while();
	}
}

void Port_Init(void)
{
	P1MDIN &= ~0x01; // Set P1.0 for analog input
	P1MDOUT &= ~0x01; // Set P1.0 to open drain
	P1 |= 0x01; // Send logic 1 to input pin P1.0
}

void ADC_Init(void)
{
	REF0CN = 0x03; // Set Vref to use internal reference voltage (2.4 V)
	ADC1CN = 0x80; // Enable A/D converter (ADC1)
	ADC1CF |= 0x01; // Set A/D converter gain to 1
}

unsigned char read_AD_input(unsigned char n)
{
	AMX1SL = n; // Set P1.n as the analog input for ADC1
	ADC1CN = ADC1CN & ~0x20; // Clear the conversion Completed” flag
	ADC1CN = ADC1CN | 0x10; // Initiate A/D conversion
	while ((ADC1CN & 0x20) == 0x00);// Wait for conversion to complete
	return ADC1; // Return digital value in ADC1 register
}

void Interrupt_Init(void)
{
  	IE |= 0x02;      // enable Timer0 Interrupt request
    EA = 1;       // enable global interrupts
}

//***************
void Timer_Init(void)
{

    CKCON |= 0x08;  // Timer0 uses SYSCLK as source
 	TMOD &= 0xF0;   // clear the 4 least significant bits
    TMOD |= 0x01;   // Timer0 in mode 1
    TR0 = 0;           // Stop Timer0
    TL0 = 0;           // Clear low byte of register T0
    TH0 = 0;           // Clear high byte of register T0

}

//***************
void Timer0_ISR(void) __interrupt 1
{
	TF0 = 0;
	Counts++;
// add interrupt code here, in this lab, the code will increment the 
// global variable 'counts'
}

unsigned char random(void)
{
    return (rand()%6);  // rand returns a random number between 0 and 32767.
                        // the mod operation (%) returns the remainder of 
                        // dividing this value by 6 and returns the result,
                        // a value of either 0,1,2,3,4,5.
}
