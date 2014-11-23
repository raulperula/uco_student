int sensor;
int sensorPin = 0; // select the input pin for the potentiometer
int ledV = 10;
int ledA = 9;
int ledB = 8;

void setup()
{
  // open the serial port at 9600 bps
  Serial.begin(9600);
 
  pinMode(10, OUTPUT);    
  pinMode(9, OUTPUT);    
  pinMode(8, OUTPUT);
}

void loop()
{
 sensor = analogRead(sensorPin);
 Serial.print("Valor: ");
 Serial.println(sensor);
 
 if(sensor < 256){
   digitalWrite(10, LOW);
   digitalWrite(9, LOW);
   digitalWrite(8, LOW);
 }
 else if(sensor < 512){
   digitalWrite(10, HIGH); 
   digitalWrite(9, LOW);
   digitalWrite(8, LOW);
 }
 else if(sensor < 768){
   digitalWrite(10, HIGH);
   digitalWrite(9, HIGH);
   digitalWrite(8, LOW);
 }
 else{
   digitalWrite(10, HIGH);
   digitalWrite(9, HIGH);
   digitalWrite(8, HIGH);
 }
 delay(50); // 50 ms
} 
