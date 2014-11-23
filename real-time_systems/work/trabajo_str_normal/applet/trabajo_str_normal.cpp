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

// include the library code:
#include <LiquidCrystal.h>
#include <DuinOS.h>

// initialize the library with the numbers of the interface pins
#include "WProgram.h"
void setup();
void loop();
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensorBri;
int sensorBriPin = A0;    // select the input pin for the potentiometer
int sensorCon;
int sensorConPin = A1;
int sensorLum;
int sensorLumPin = A2;


int sensorTor;
int sensorTorPin = A3;
int sensorTem;
int sensorTemPin = A4;

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Lu: To: Te:");
    // initialize the serial communication:
  Serial.begin(9600);
}

void loop() {
   sensorBri = analogRead(sensorBriPin);
   sensorCon = analogRead(sensorConPin);
   sensorLum = analogRead(sensorLumPin);
   sensorTor = analogRead(sensorTorPin);
   sensorTem = analogRead(sensorTemPin);
 
   // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  // print the number of seconds since reset:
  //lcd.setCursor(0, 1);
  //lcd.print((int)(((1023.0-sensorBri)/1024.0)*100));
  //lcd.setCursor(4, 1);
  //lcd.print((int)(((1023.0-sensorCon)/1024.0)*100));
  lcd.setCursor(0,1);
  sensorLum = 100-(int)(((1023.0-sensorLum)/1024.0)*100);
  if(sensorLum < 10){
    lcd.setCursor(1,1);
    lcd.print(" ");
    lcd.setCursor(0,1);
  }
  lcd.print(sensorLum);
  lcd.setCursor(4,1);
  sensorTor = (int)(((1023.0-sensorTor)/1024.0)*100);
  if(sensorTor < 10){
    lcd.setCursor(5,1);
    lcd.print(" ");
    lcd.setCursor(4,1);
  }
  lcd.print(sensorTor);
  lcd.setCursor(8,1);
  sensorTem = (int)(((1023.0-sensorTem)/1024.0)*100);
  if(sensorTem < 10){
    lcd.setCursor(9,1);
    lcd.print(" ");
    lcd.setCursor(8,1);
  }
  lcd.print(sensorTem);
  
  Serial.print(sensorLum);
  Serial.print("    ");
  Serial.println(sensorTor);
  delay(10);
}


#include <WProgram.h>
#include "DuinOS.h"

unsigned portBASE_TYPE mainLoopPriority;

void main_Task(void *pvParameters)
{
	for(;;)
		loop();
}


int main(void)
{
	//This is made prior to setup(), so this priority could be changed in setup():
	mainLoopPriority = LOW_PRIORITY;

	init();
	setup();

	xTaskCreate(main_Task, (signed portCHAR *) "main", configMINIMAL_STACK_SIZE, NULL, mainLoopPriority, NULL);
	vTaskStartScheduler();

	//Will not get here unless a task calls vTaskEndScheduler():
	for (;;);

	return 0;
}
