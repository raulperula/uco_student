#include <DuinOS.h>

/*
DuinOS TwoLEDsBlinking

Blinks two LEDs with different freqs.

The circuit: ##Pins:
* LED connected from digital pin 14 to Vcc.
* LED connected from digital pin 15 to Vcc.

##Pins:
* Note: On most Comm.ProgUSB boards, there are already two LEDs on the board
connected to pins 14 and 15, so you don't need any extra components for this example.

Created 2009.10.26 (yyyy.mm.dd)
by Juli\u00e1n da Silva Gillig


Based on the original Blink code by David Cuartielles

*/
#include "WProgram.h"
void setup();
void loop();
int ledPinRed =  14;
int ledPinGreen =  15;
boolean redLED_isOn = false;


taskLoop(redLED)
{  
 redLED_isOn = false;
 delay(500);
 redLED_isOn = true;
 delay(500);
}


taskLoop(greenLED)
{
 static unsigned char counter = 0;

 digitalWrite(ledPinGreen, LOW);  // set the LED on
 delay(200);
 digitalWrite(ledPinGreen, HIGH);  // set the LED off
 delay(200);

 if (counter >= 29)
   suspend();      //After a while, the tasks suspends itself (forever)
 counter++;
}


// The setup() method runs once, when the sketch starts

void setup()  
{                
 // Initialize the digital pins as outputs:
 pinMode(ledPinRed, OUTPUT);
 pinMode(ledPinGreen, OUTPUT);
 
 createTaskLoop(redLED, LOW_PRIORITY);
 createTaskLoop(greenLED, NORMAL_PRIORITY);

 //A task can be suspended by it's name
 //suspendTask(redLED);
}


// This is the main loop() method, wich runs over and over again,
// as long as the Arduino has power. Is a LOW_PRIORITY loopTask:

void loop()                    
{
 if (redLED_isOn)
 {
   digitalWrite(ledPinRed, HIGH);  // set the LED off
   delay(25);                      // The OS can be tested reducing these delays, and seeing how both LEDs work together...
   digitalWrite(ledPinRed, LOW);   // set the LED on
   delay(25);    
 }
 else
 {
   digitalWrite(ledPinRed, HIGH);  //  LED is off
   //If nextTask is not called, the application will not hang, because the OS is preemptive. BUT, the current task
   //will consume a lot of computational resources (due to it's lack of a delay() in this branch), the application will
   //turn slower, and the other tasks may be affected by this, loossing precision in their timing:
   nextTask();
 }
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
