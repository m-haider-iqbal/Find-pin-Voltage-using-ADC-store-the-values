#include <Arduino.h>

void ADC_initialize();
float ADC_read(uint8_t haider);
float x;

void ADC_initialize()
{
  ADMUX = (1 << REFS0); //Multiplexer Selection Register_Reference Selection Bits
  ADCSRA |= (1 << ADEN) | (0 << ADSC) | (0 << ADATE); // ADC Enable_7 , ADC Start Conversion , ADC Auto Trigger Enable
  ADCSRB = 0x00; //ADC Control and Status Register B
}


float ADC_read(uint8_t haider)
{  
  ADCSRA |= (1 << ADSC); // Control and Status Register A _ ADC Start Conversion 6
  ADC = (ADCL | (ADCH << 8)); // ADC Data Register 
  x = ((ADC * 5.0) / 1024);
  return (x); // ADC Value Output 
}

void setup()
{
  Serial.begin(9600); // UART INIT
  ADC_initialize(); // CAlling 
}

void loop()
{
  float pot_read = ADC_read(A0); // Redaiunsigned long intng 
  Serial.print("Voltage = ");
  Serial.println(pot_read); // Writing 
  delay(500); // delay mili sec
}

// M Haider Iqbal 
