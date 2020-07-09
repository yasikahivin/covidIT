#include <Servo.h>
//test
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;

int state;
int pos;

int servo1IntState = 90;
int servo2IntState = 90;
int servo3IntState = 100;
int servo4IntState = 90;
int servo5IntState = 90;

int servo1state;
int servo2state;
int servo3state;
int servo4state;
int servo5state;

// servo 1 8 55-100-145 0-100
// servo 2 9 40-90-140  100-200
// servo 3 10 90-170    200-300
// servo 4 11 10-170    300-500
// servo 5 12 40-140    500-600


#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement


void setup()

{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  

  Serial.begin(9600);
  while (!Serial);
  myservo1.attach(8);
  myservo2.attach(9);
  //myservo3.attach(10);
  myservo4.attach(11);
  myservo5.attach(12);

  for (pos = 0; pos <= 180; pos += 1);
  myservo1.write(servo1IntState);
  myservo2.write(servo2IntState);
  myservo3.write(servo3IntState);
  myservo4.write(servo4IntState);
  myservo5.write(servo5IntState);
}


void loop() {
//// Clears the trigPin condition
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(250);
//  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(250);
//  digitalWrite(trigPin, LOW);
//  // Reads the echoPin, returns the sound wave travel time in microseconds
//  duration = pulseIn(echoPin, HIGH);
//  // Calculating the distance
//  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
//  
//
//  myservo2.write(150);
//  if(distance <= 10){
//  myservo2.write(120);
//  }
  

  //for (pos = 0; pos <= 180; pos += 1)
    if (Serial.available()) {
      int state = Serial.parseInt();


if (state < 10)

      {
        Serial.print(">");
        Serial.println(state);
        Serial.println("reverse current10");

      }

      
      if (state >= 10 && state < 100) {
        moveServo1(state, servo1state);
        servo1state = state;
        //Serial.println("turning servo 1");
      } else if (state >= 100 && state < 200) {
        moveServo2(state, servo2state);
        servo2state = state;
      } else if (state >= 200 && state < 300) {
        moveServo3(state, servo3state);
        servo3state = state;
      } else if (state >= 300 && state < 500) {
        moveServo4(state, servo4state);
        servo4state = state;
      } else if (state >= 500 && state < 600) {
        moveServo5(state, servo5state);
        servo5state = state;
      }else if (state ==1000) {
        stateInitialReset();
        
      }
      //Serial.println("turning servo 11");

    }

}


void moveServo1(int stateTochange, int previousState) {
  stateTochange=stateTochange+55;
  previousState=previousState+55;
  if (previousState < stateTochange) {
    for (pos = previousState; pos <= stateTochange; pos++) {
      myservo1.write(pos);
      delay(40);
    }
  } else {
    for (pos = previousState; pos >= stateTochange ; pos--) {
      myservo1.write(pos);
      delay(40);
    }
  }
  //Serial.println("turning servo 11111 ");
  //servo1state = stateTochange;
}

void moveServo2(int stateTochange, int previousState) {
  stateTochange=stateTochange-60;
  previousState=previousState-60;
  if (previousState < stateTochange) {
    for (pos = previousState; pos <= stateTochange; pos++) {
      myservo2.write(pos);
      delay(40);
    }
  } else {
    for (pos = previousState; pos >= stateTochange ; pos--) {
      myservo2.write(pos);
      delay(40);
    }
  }
  Serial.println("turning servo 2");
  //servo2state = stateTochange;
}

void moveServo3(int stateTochange, int previousState) {
  stateTochange=stateTochange-110;
  previousState=previousState-110;
  if (previousState < stateTochange) {
    for (pos = previousState; pos <= stateTochange; pos++) {
      myservo3.write(pos);
      delay(40);
    }
  } else {
    for (pos = previousState; pos >= stateTochange ; pos--) {
      myservo3.write(pos);
      delay(40);
    }
  }
  //servo3state = stateTochange;
}

void moveServo4(int stateTochange, int previousState) {
  stateTochange=stateTochange-290;
  previousState=previousState-290;
  if (previousState < stateTochange) {
    for (pos = previousState; pos <= stateTochange; pos++) {
      myservo4.write(pos);
      delay(40);
    }
  } else {
    for (pos = previousState; pos >= stateTochange ; pos--) {
      myservo4.write(pos);
      delay(40);
    }
  }
  //servo4state = stateTochange;
}

void moveServo5(int stateTochange, int previousState) {
  stateTochange=stateTochange-450;
  previousState=previousState-450;
  if (previousState < stateTochange) {
    for (pos = previousState; pos <= stateTochange; pos++) {
      myservo5.write(pos);
      delay(40);
    }
  } else {
    for (pos = previousState; pos >= stateTochange ; pos--) {
      myservo5.write(pos);
      delay(40);
    }
  }
  //servo5state = stateTochange;
}


void stateInitialReset() {
  for (pos = 0; pos <= 180; pos += 1);
  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(90);
  myservo4.write(90);
  myservo5.write(90);
  
}

void testingState(){
  
  }

void DistanceSensing(){
  
  }

//void servoIdentify(){
//
//  }
