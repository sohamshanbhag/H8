#include <SPI.h>

boolean stringComplete = false;
byte c = 0;
void setup (void)
{
  Serial.begin(9600);
  digitalWrite(SS, HIGH); 

  // Put SCK, MOSI, SS pins into output mode
  // also put SCK, MOSI into LOW state, and SS into HIGH state.
  // Then put SPI hardware into Master mode and turn SPI on
  SPI.begin ();

  SPI.setClockDivider(SPI_CLOCK_DIV8);

}

//For getting user input
void serialEvent() {
  while (Serial.available()) {
    c = Serial.parseInt();
    stringComplete = true;
  }
}

//Transfer data over SPI
byte data_transfer(const byte x){
  byte a = SPI.transfer(x);
  delayMicroseconds(20);
  return a;
}

void loop (void)
{

  while(stringComplete){
  byte a, b;

  digitalWrite(SS, LOW);    // SS is pin 10
  data_transfer(c);
  b = data_transfer(0);
  
  Serial.print("Twice of your number is: ");
  Serial.println(b,DEC);
  digitalWrite(SS, HIGH);

  delay (1000);  
  stringComplete = false;
  }
}
