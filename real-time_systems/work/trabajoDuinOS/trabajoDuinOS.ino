/*
 Trabajo DuinOS
 
 Blinks two LEDs. One LED shows two combined waves.
 
 The circuit: ##Pins:
 * LED connected from digital pin 14 to Vcc.
 * LED connected from digital pin 15 to Vcc.
 
 ##Pins:
 * Note: On most Comm.ProgUSB boards, there are already two LEDs on the board
 connected to pins 14 and 15, so you don't need any extra components for this example.
 */

/*
  La pantalla mostrara el porcentaje de brillo y contraste
 que vendra dado por dos potenciometros conectados a los
 reguladores correspondientes de la pantalla (Vss para brillo
 y Vee para contraste)
 
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 + salida del potenciometro del brillo a A0
 + salida del potenciometro del contraste a A1
 
 */

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// entradas analogicas
int sensorRes;
int sensorResPin = 5;
//int sensorBri;
//int sensorBriPin = 0;
//int sensorCon;
//int sensorConPin = 1;
//int sensorLum;
//int sensorLumPin = 2;

//int sensorTor;
//int sensorTorPin = 3;
//int sensorTem;
//int sensorTemPin = 4;

// salidas digitales
int ledV = 10;
int ledA = 9;
int ledR = 8;

//##################################################################################################################

// Forward declaration, to let redLED call to resumeTask(greenLED). It's not necessary if we put the greenLED
// itself here, but declareLoopTask may be usefull in more complex situations:
//declareTaskLoop(sensores);
//declareTaskLoop(lcd);

//##################################################################################################################

//taskLoop(sensores)
//{
//  
//}

//taskLoop(lcd)
//{
//  
//}

//##################################################################################################################

// The setup() method runs once, when the sketch starts
void setup()
{
  // 
  Serial.begin(9600);

  // Initialize the digital pins as outputs
  pinMode(ledV, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledR, OUTPUT);

  //  createTaskLoop(sensores, NORMAL_PRIORITY);
  //  createTaskLoop(lcd, LOW_PRIORITY);

  // set up the LCD's number of columns and rows: 
  //  lcd.begin(16, 2);
  // Print a message to the LCD.
  //  lcd.print("Res:");

}

// This is the main loop() method, wich runs over and over again,
// as long as the Arduino has power. Is a LOW_PRIORITY taskLoop:
void loop()
{
  //  sensorBri = analogRead(sensorBriPin);
  //  sensorCon = analogRead(sensorConPin);
  //  sensorLum = analogRead(sensorLumPin);
  //  sensorTor = analogRead(sensorTorPin);
  //  sensorTem = analogRead(sensorTemPin);

  // gestion de la pantalla lcd
  //  lcd.setCursor(0,1);
  //  sensorLum = 100-(int)(((1023.0-sensorLum)/1024.0)*100);
  //  if(sensorLum < 10){
  //    lcd.setCursor(1,1);
  //    lcd.print(" ");
  //    lcd.setCursor(0,1);
  //  }
  //  lcd.print(sensorLum);
  //  Serial.print("Lum: ");
  //  Serial.println(sensorLum);

  //  lcd.setCursor(4,1);
  //  sensorTor = (int)(((1023.0-sensorTor)/1024.0)*100);
  //  if(sensorTor < 10){
  //    lcd.setCursor(5,1);
  //    lcd.print(" ");
  //    lcd.setCursor(4,1);
  //  }
  //  lcd.print(sensorTor);
  //  
  //  lcd.setCursor(8,1);
  //  sensorTem = (int)(((1023.0-sensorTem)/1024.0)*100);
  //  if(sensorTem < 10){
  //    lcd.setCursor(9,1);
  //    lcd.print(" ");
  //    lcd.setCursor(8,1);
  //  }
  //  lcd.print(sensorTem);

  //  Serial.print(sensorLum);
  //  Serial.print("    ");
  //  Serial.println(sensorTor);
  //  delay(10);

  //----------------------------------------------

  sensorRes = analogRead(sensorResPin);

  //  lcd.setCursor(0,1);
  //  sensorRes = 100-(int)(((1023.0-sensorRes)/1024.0)*100);
  //  if(sensorRes < 10){
  //    lcd.setCursor(1,1);
  //    lcd.print(" ");
  //    lcd.setCursor(0,1);
  //  }
  //  lcd.print(sensorRes);
  Serial.print("Res: ");
  Serial.println(sensorRes, DEC);

  if(sensorRes < 25){
    digitalWrite(ledV, LOW);
    digitalWrite(ledA, LOW);
    digitalWrite(ledR, LOW);
  }
  else if(sensorRes > 25 && sensorRes < 50){
    digitalWrite(ledV, HIGH);
    digitalWrite(ledA, LOW);
    digitalWrite(ledR, LOW);
  }
  else if(sensorRes > 50 && sensorRes < 75){
    digitalWrite(ledV, HIGH);
    digitalWrite(ledA, HIGH);
    digitalWrite(ledR, LOW);
  }
  else{
    digitalWrite(ledV, HIGH);
    digitalWrite(ledA, HIGH);
    digitalWrite(ledR, HIGH);
  }
  delay(500);

  //----------------------------------------------

  //  if(redLED_isOn){
  //    digitalWrite(ledPinRed, LOW);  // set the LED off
  //    delay(25);                     // The OS can be tested reducing these delays, and seeing how both LEDs work together...
  //    digitalWrite(ledPinRed, HIGH); // set the LED on  
  //    delay(25);
  //  }
  //  else{
  //    digitalWrite(ledPinRed, LOW);  //  LED is off
  //    // If nextTask is not called, the application will not hang, because the OS is preemptive. BUT, the current task
  //    // will consume a lot of computational resources (due to it's lack of a delay() in this branch), the application will 
  //    // turn slower, and the other tasks may be affected by this, loossing precision in their timing:
  //    nextTask();
  //  }
}


