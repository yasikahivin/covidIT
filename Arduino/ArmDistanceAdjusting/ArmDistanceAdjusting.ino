
#include <Servo.h>

const int pingPin = 4; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 5; // Echo Pin of Ultrasonic Sensor

Servo myservo2; //servo2
int servo2IntState = 90;
long duration, cm;

int pos;

void setup() {
  Serial.begin(9600); // Starting Serial Terminal
  myservo2.attach(9);

  for (pos = 0; pos <= 180; pos += 1);
  myservo2.write(servo2IntState);


while (cm == 3) {
    
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(pingPin, LOW);
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    cm = microsecondsToCentimeters(duration);
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    delay(100);
    myservo2.write(servo2IntState++);
  }
}

void loop() {
}


long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
