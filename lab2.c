/* This program demonstrates how to perform an A/D Conversion */
main()
{
  unsigned char result;
  Sys_Init(); // Initialize the C8051 board
  Port_Init(); // Configure P1.0 for analog input
  ADC_Init(); // Initialize A/D conversion
  while (1)
  {
    result = read_AD_input(0); // Read the A/D value on P1.0
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
  ADC1CN = ADC1CN & ~0x20; // Clear the “Conversion Completed” flag
  ADC1CN = ADC1CN | 0x10; // Initiate A/D conversion
  
  while ((ADC1CN & 0x20) == 0x00);// Wait for conversion to complete
  
  return ADC1; // Return digital value in ADC1 register
}
