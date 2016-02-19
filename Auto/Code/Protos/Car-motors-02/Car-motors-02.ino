/*
  Arduino 

  Car kit

  Date          Version   Description
  08 jan 2016   0.1       Two motor contorl Using H bridge L928N

 */

#define DEBUG true

// Motor A == Front Wheel Left
int dir1MotA  = 2; // Pin 2 on Arduino board == direction 1 of motor A
int dir2MotA  = 3; // Pin 3 on Arduino board == driection 2 of motor A
int speedMotA = 9; // Pin 9 on Arduino board == speed of Motor A (PWM)


// Motor B == Front Wheel Right
int dir1MotB  = 4;  // Pin  4 on Arduino board == direction 1 of motor B
int dir2MotB  = 5;  // Pin  5 on Arduino board == driection 2 of motor B
int speedMotB = 10; // Pin 10 on Arduino board == speed of Motor B (PWM)

// Variables for motor control
int speed      = 0;
int direction  = 0;

int speedA     = 0; // TODO - work out one overall speed to determine speed for A and B
int speedB     = 0;
int directionA = 0; // TODO - work out one overall direction to determine direction for A and B
int directionB = 0;

// temp for demo
unsigned long time = 0;
int step = 0;

/* Arduino style, setup is only called one time at 'boot'
 *  
 *  
 */

void setup() {
  // For motor TODO - move to helper routine
  pinMode(dir1MotA  , OUTPUT);
  pinMode(dir2MotA  , OUTPUT);
  pinMode(speedMotA , OUTPUT);

  pinMode(dir1MotB  , OUTPUT);
  pinMode(dir2MotB  , OUTPUT);
  pinMode(speedMotB , OUTPUT);

  // For demo 
  time = millis();
  speedA     = speedB     = 0;
  directionA = directionB =0;
  
  // For debugging over serial port  
  Serial.begin(19200);
  debug("setup done");
}

/* Arduino style, loop is running continiously after setup  
 *  
 */

void loop() {

  // a == left
  if (millis() - time > 2500 && 0 == step) {  // 2.5 seconds passed?
      debug("A");

    digitalWrite(dir1MotA, LOW);  // backwards
    digitalWrite(dir2MotA, HIGH);
    analogWrite(speedMotA, 80); // 50 is to low

    digitalWrite(dir1MotB, LOW);
    digitalWrite(dir2MotB, HIGH);
    analogWrite(speedMotB, 80);
    step++;
  }

  if (millis() - time > 7500 && 1 == step) {  // 7.55 seconds passed?
      debug("B");

    analogWrite(speedMotA, 100);
    analogWrite(speedMotB, 100);
    step++;
  }
  if (millis() - time > 10000 && 2 == step) {  // 10 seconds passed?
      debug("C");

    analogWrite(speedMotA, 200); // faster
    analogWrite(speedMotB, 200);
    step++;
  }

  if (millis() - time > 15000 && 3 == step) {  // 10 seconds passed?
      debug("D");

    digitalWrite(dir1MotA, HIGH);  // forwards
    digitalWrite(dir2MotA, LOW);
    analogWrite(speedMotA, 250); // faster

    digitalWrite(dir1MotB, HIGH);
    digitalWrite(dir2MotB, LOW);
    analogWrite(speedMotB, 240);

    
    step++;
  }


  if (millis() - time > 20000 && 4 == step) {  // 5 seconds passed?
      debug("E");

    digitalWrite(dir1MotA, LOW); // nodir
    digitalWrite(dir2MotA, LOW);

    digitalWrite(dir1MotB, LOW);
    digitalWrite(dir2MotB, LOW);

    step++;
  }

  /*

  // TODO move to helper for direction and speed

  
  
  // Set direction A and B DEMO only no intelligence
  if (1 == direction) {
    digitalWrite(dir1MotA, LOW);
    digitalWrite(dir2MotA, HIGH);

    digitalWrite(dir1MotB, HIGH);
    digitalWrite(dir2MotB, LOW);
  } else {
    digitalWrite(dir1MotA, HIGH);
    digitalWrite(dir2MotA, LOW);

    digitalWrite(dir1MotB, LOW);
    digitalWrite(dir2MotB, HIGH);
  }
  
  analogWrite(speedMotA, speed);
  analogWrite(speedMotB, 255 - speed);
  
  // Check timing for demo
  if (millis() - time > 5000) {  // 5 seconds passed?
    time = millis();
    speed += 16;
    if (speed > 255) {
      speed = 0;
    }
    debug("speed now:" + String(speed));

    if (1 == direction) {
      direction = 0;
    } else {
      direction = 1;
    }
    debug("direction now:" + String(direction));
  }
  */
 
  delay(100);
  //debug("loop");
}


void debug(String Msg)
{
  if (DEBUG)
  {
    Serial.println(Msg);
  }
}

