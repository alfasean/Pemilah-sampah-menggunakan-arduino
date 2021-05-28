#include <NewPing.h>
#include <Servo.h> 

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     13  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters).
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo pemisah;
int a;
void setup() {
  Serial.begin(9600);
  pemisah.attach(11);
  pinMode(3,OUTPUT);
  analogWrite(3,105);
}

void loop() {
cek:

int jarak=(sonar.ping_cm());
  delay(50);                     
  Serial.println(jarak);
  if(jarak>=2&&jarak<=6)
  {a=0;pemisah.write(90);goto cek2;}
  else if(jarak<2)
  {jarak=0;}
  else{goto cek;}
  goto cek;

 
  cek2:
  Serial.print("ke2");
  Serial.println((sonar.ping_cm()));
  if(analogRead(A0)<=500)
  {pemisah.write(120);a=0;delay(1500);pemisah.write(90);goto cek;}
  a=a+1;
  if(a>=50)
  {pemisah.write(50);a=0;delay(1500);pemisah.write(90);goto cek;}
  else{goto cek2;}
  delay(50);
  
  goto cek2;
  }
