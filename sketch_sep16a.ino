 
#include "max6675.h" // max6675.h file is part of the library that you should download from Robojax.com

int soPin = 4;// SO=Serial Out
int csPin = 5;// CS = chip select CS pin
int sckPin = 6;// SCK = Serial Clock pin

MAX6675 robojax(sckPin, csPin, soPin);// create instance object of MAX6675


void setup() {

          
  Serial.begin(115200);// initialize serial monitor with 9600 baud
 
}
float T_read, T_real;

const float M = 1.53;
const float C = -13.91;

void loop() {
   T_read=robojax.readCelsius();
   
   //According to Cal data:
   // T_read = 1.53 * T_real - 13.91
   
   T_real=(T_read -C)/M;
   
   Serial.println(T_real);

   delay(1000);
}
