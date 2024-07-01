#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


#define SERVO_FREQ 50 


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMAX 337 
#define SERVOMIN 250
#define SERVOCHANNEL 14


int currentpos = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Servos range");

  pwm.begin();

  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
  pwm.setPWM(14, 0, SERVOMIN);
  currentpos = SERVOMIN;
  Serial.println("MIN");

  delay(10);
}

void loop() {
  while(currentpos < SERVOMAX){
    currentpos++;
    pwm.setPWM(14, 0, currentpos);
    delay(10);
  }
  Serial.println("MAX");
  Serial.println(currentpos);
  delay(2000);
  while(currentpos > SERVOMIN){
    currentpos--;
    pwm.setPWM(14, 0, currentpos);
    delay(10);
  }
  Serial.println("MIN");
  Serial.println(currentpos);
  delay(2000);

}


