/*
  Arduino 

  Car kit

  Date          Version   Description
  09 jan 2016   0.1       oing thiny experiment

  HC-SR04 Ping distance sensor]
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 13 Trig to Arduino pin 12
Red POS to Arduino pin 11
Green POS to Arduino pin 10
560 ohm resistor to both LED NEG and GRD power rail
More info at: http://goo.gl/kJ8Gl
Original code improvements to the Ping sketch sourced from Trollmaker.com
Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
*/


#define DEBUG true

#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10


/* Arduino style, setup is only called one time at 'boot'
 *  
 *  
 */

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  
  // For debugging over serial port  
  Serial.begin(19200);
  debug("setup done");
}

/* Arduino style, loop is running continiously after setup  
 *  
 */

void loop() {
  long duration, distance;
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
 

  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.386; // speed of sound dry air at 20 °C, the speed of sound is 343.2 metres per second
  // 2,9137529137529137529137529137529e-5 s per cm
  if (distance < 4) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
    digitalWrite(led2,LOW);
  }
  else {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
  }
  
  if (distance >= 200 || distance <= 0){
    debug("Out of range");
  } else {
    debug("distance:" + String(distance) + "cm");
  }
  delay(500);
  debug("loop");
}


void debug(String Msg)
{
  if (DEBUG)
  {
    Serial.println(Msg);
  }
}

