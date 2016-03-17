#include <SPI.h>

void setup (void)
{
  Serial.begin(9600);
  // turn on SPI in slave mode
  SPCR |= _BV(SPE);
  SPCR |= _BV(SPIE);

  // have to send on master in, *slave out*
  pinMode (MISO, OUTPUT);

}  


ISR (SPI_STC_vect)
{
  byte c = SPDR;
  SPDR = c*2;
} 


void loop (void)
{}
