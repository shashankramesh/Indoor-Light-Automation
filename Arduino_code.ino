/********************************************************* Intelligent Lighting System ************************************************************/
/************************************************** Prototype - 2: Indoor Sensor Testing Module****************************************************/
/*  It is advisable to read the document first which explains the code and then proceed further.
 *  The pinout of ATtiny85 is given below
 *                           ----------
 *                    RST - | 1      8 | - VCC
 *                    A2 -  | 2      7 | - A1
 *                    A3 -  | 3      6 | - Pin 0 / PB0
 *                    GND - | 4      5 | - Pin 1 / PB1
 *                           ----------
 *  The microcontroller needs to be programmed using Arduino as an In-system Programmer (Arduino as ISP). The instruction for the same can be found in the link:
 *          https://create.arduino.cc/projecthub/arjun/programming-attiny85-with-arduino-uno-afb829
 */

void setup() 
{
  //pins A1 and 0 are declared as analog input and digital output respectively.
  pinMode(A1, INPUT);
  pinMode(0, OUTPUT);
}

//Delay function for long time delays
void Dly(int dly) //The microcontroller delays for a dead time of 'dly' seconds.
{
  int j = 1;
  for(j = 1; j <= dly; j++)
  {
    delay(1000);
  }
}

void loop() {
  int d = analogRead(A1); //d has the analog input value.
  if(d >= 600)
  {
    digitalWrite(0, HIGH);
    Dly(30);
  } //If the d value is above 600 or 3V then a dead time delay of 30 seconds during which the pin 0 is driven HIGH, prevails.
  else
  {
    int i = 0;
    while((i <= 299) && (d <= 600))
    {
      d = analogRead(A1);
      delay(100);
      i++; //Else the microcontroller reads analog input for every 100 ms.
      if(i == 299)
      {
        digitalWrite(0, LOW);
        delay(100);
      } // If no sensor value is detected, only then the pin 0 goes LOW.
    }
  }
}
