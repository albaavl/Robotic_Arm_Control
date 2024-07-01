
#define BLYNK_TEMPLATE_ID "TMPL5ruKXMFB_"
#define BLYNK_TEMPLATE_NAME "Arm"
#define BLYNK_AUTH_TOKEN "uqktkHaDWt_SV9I1tV_6yO7yVTO8HpUJ"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


#define SERVO_FREQ 50  

char ssid[] = "Albaa";
char pass[] = "1234567a";

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();



//Thumb servos

#define SERVOMIN_THUMB_OUT 337  // thumb outer servo min         RED1      id5
#define SERVOMAX_THUMB_OUT 490  // thumb outer servo max         RED1      id5
#define SERVOMIN_THUMB_IN 122   // thumb inner servo min         RED2      id0  122
#define SERVOMAX_THUMB_IN 378   // thumb inner servo max         RED2      id0

int CPThumb_IN = 0;
int CPThumb_OUT = 0;

/**
 * Palm Servo
 * id=11
*/


#define SERVOMAX_PALM 163  //thumb hacia fuera
#define SERVOMIN_PALM 61   //thumb hacia dentro
int CPPalm = 0;

//Index finger servos


#define SERVOMIN_INDEX_OUT 122  // index outer servo min         YELLOW1   id6  122
#define SERVOMAX_INDEX_OUT 409  // index outer servo max         YELLOW1   id6
#define SERVOMIN_INDEX_IN 276   // index inner servo min         YELLOW2   id1
#define SERVOMAX_INDEX_IN 503   // index inner servo max         YELLOW2   id1

int CPIndex_IN = 0;
int CPIndex_OUT = 0;

//Middle finger servos


#define SERVOMIN_MIDDLE_OUT 122  // middle outer servo min       BLUE1     id7  122
#define SERVOMAX_MIDDLE_OUT 490  // middle outer servo max       BLUE1     id7
#define SERVOMIN_MIDDLE_IN 163   // middle inner servo min       BLUE2     id2
#define SERVOMAX_MIDDLE_IN 347   // middle inner servo max       BLUE2     id2

int CPMiddle_IN = 0;
int CPMiddle_OUT = 0;

//Ring finger servos

#define SERVOMIN_RING_OUT 115  // ring outer servo min           GREEN1    id8  122
#define SERVOMAX_RING_OUT 419  // ring outer servo max           GREEN1    id8
#define SERVOMIN_RING_IN 245   // ring inner servo min           GREEN2    id3
#define SERVOMAX_RING_IN 419   // ring inner servo max          GREEN2    id3

int CPRing_IN = 0;
int CPRing_OUT = 0;

//Pinky finger servos

#define SERVOMIN_PINKY_OUT 122  // pinky outer servo min         GRAY1     id9  122
#define SERVOMAX_PINKY_OUT 398  // pinky outer servo max         GRAY1     id9
#define SERVOMIN_PINKY_IN 122   // pinky inner servo min         GRAY2     id4  122
#define SERVOMAX_PINKY_IN 306   // pinky inner servo max         GRAY2     id4

int CPPinky_IN = 0;
int CPPinky_OUT = 0;
/**
 * Wrist Servo
 * id=12
*/


#define SERVOMAX_WRIST 449  //HACIA ANTEBRAZO
#define SERVOMIN_WRIST 195  //HACIA FUERA

int CPWrist = 0;

/**
 * Forearm Servo
 * id=13
*/



#define SERVOMAX_WRIST_PRONATION 479  //SENTIDO HORARIO MAX
#define SERVOMIN_WRIST_PRONATION 285  //SENTIDO ANTIHORARIO MAX
int CPWristPronation = 0;

/**
 * Biceps Servo
 * id=14
*/


#define SERVOMAX_BICEPS 355 //FLEXION
#define SERVOMIN_BICEPS 265  //EXTENSION
#define GESTURE_POSITION_BICEPS 330

int CPBiceps = SERVOMAX_BICEPS;

/**
 * Shoulder Servo
 * id=15
*/

// #define USMAX_SHOULDER 2000 //HOMBRO HACIA "DENTRO"
// #define USMIN_SHOULDER 1200  //hOMBRO HACIA "FUERA"

#define SERVOMAX_SHOULDER 408  //lo mas levantado posible
#define SERVOMIN_SHOULDER 245  //pegado a la mesa

int CPShoulder = SERVOMIN_SHOULDER;



//as soon as device connects to the internet, it returns to the default position #openhand
BLYNK_CONNECTED() {
   Serial.println("Connected and ready!");
   openHand();
}


//geture menu control
BLYNK_WRITE(V0) {
  int i = param.asInt();
  switch (i) {
    case 0:
      openHand();
      break;
    case 1:
      closeHand();
      break;
    case 2:
      pointIndex();
      break;
    case 3:
      spiderman();
      break;
    case 4:
      perfect();
      break;
    case 5:
      numberTwo();
      break;
    case 6:
      numberThree();
      break;
    case 7:
      rockAndRoll();
      break;
    case 8:
      sayHi();
      break;
    case 9:
      sayNo();
      break;
  }
}



//hand fully extended
void openHand() {
  pwm.setPWM(0, 0, SERVOMAX_THUMB_IN);
  CPThumb_IN = SERVOMAX_THUMB_IN;
  pwm.setPWM(1, 0, SERVOMAX_INDEX_IN);
  CPIndex_IN = SERVOMAX_INDEX_IN;
  pwm.setPWM(2, 0, SERVOMAX_MIDDLE_IN);
  CPMiddle_IN = SERVOMAX_MIDDLE_IN;
  pwm.setPWM(3, 0, SERVOMAX_RING_IN);
  CPRing_IN = SERVOMAX_RING_IN;
  pwm.setPWM(4, 0, SERVOMAX_PINKY_IN);
  CPPinky_IN = SERVOMAX_PINKY_IN;
  pwm.setPWM(5, 0, SERVOMAX_THUMB_OUT);
  CPThumb_OUT = SERVOMAX_THUMB_OUT;
  pwm.setPWM(6, 0, SERVOMAX_INDEX_OUT);
  CPIndex_OUT = SERVOMAX_INDEX_OUT;
  pwm.setPWM(7, 0, SERVOMAX_MIDDLE_OUT);
  CPMiddle_OUT = SERVOMAX_MIDDLE_OUT;
  pwm.setPWM(8, 0, SERVOMAX_RING_OUT);
  CPRing_OUT = SERVOMAX_RING_OUT;
  pwm.setPWM(9, 0, SERVOMAX_PINKY_OUT);
  CPPinky_OUT = SERVOMAX_PINKY_OUT;
  pwm.setPWM(11, 0, SERVOMIN_PALM);
  CPPalm = SERVOMIN_PALM;
  pwm.setPWM(12, 0, SERVOMIN_WRIST);
  CPWrist = SERVOMIN_WRIST;
  biceps_shoulder_position(GESTURE_POSITION_BICEPS, SERVOMIN_SHOULDER);
}

//hand fully closed
void closeHand() {
  pwm.setPWM(0, 0, SERVOMIN_THUMB_IN);
  CPThumb_IN = SERVOMIN_THUMB_IN;
  pwm.setPWM(1, 0, SERVOMIN_INDEX_IN);
  CPIndex_IN = SERVOMIN_INDEX_IN;
  pwm.setPWM(2, 0, SERVOMIN_MIDDLE_IN);
  CPMiddle_IN = SERVOMIN_MIDDLE_IN;
  pwm.setPWM(3, 0, SERVOMIN_RING_IN);
  CPRing_IN = SERVOMIN_RING_IN;
  pwm.setPWM(4, 0, SERVOMIN_PINKY_IN);
  CPPinky_IN = SERVOMIN_PINKY_IN;
  pwm.setPWM(5, 0, SERVOMIN_THUMB_OUT);
  CPThumb_OUT = SERVOMIN_THUMB_OUT;
  pwm.setPWM(6, 0, SERVOMIN_INDEX_OUT);
  CPIndex_OUT = SERVOMIN_INDEX_OUT;
  pwm.setPWM(7, 0, SERVOMIN_MIDDLE_OUT);
  CPMiddle_OUT = SERVOMIN_MIDDLE_OUT;
  pwm.setPWM(8, 0, SERVOMIN_RING_OUT);
  CPRing_OUT = SERVOMIN_RING_OUT;
  pwm.setPWM(9, 0, SERVOMIN_PINKY_OUT);
  CPPinky_OUT = SERVOMIN_PINKY_OUT;
  pwm.setPWM(11, 0, SERVOMAX_PALM);
  CPPalm = SERVOMAX_PALM;
  pwm.setPWM(12, 0, SERVOMAX_WRIST);
  CPWrist = SERVOMAX_WRIST;
  biceps_shoulder_position(GESTURE_POSITION_BICEPS, SERVOMIN_SHOULDER);
}

//hand fully closed, index extended
void pointIndex() {
  pwm.setPWM(0, 0, SERVOMIN_THUMB_IN);
  CPThumb_IN = SERVOMIN_THUMB_IN;
  pwm.setPWM(1, 0, SERVOMAX_INDEX_IN);
  CPIndex_IN = SERVOMAX_INDEX_IN;
  pwm.setPWM(2, 0, SERVOMIN_MIDDLE_IN);
  CPMiddle_IN = SERVOMIN_MIDDLE_IN;
  pwm.setPWM(3, 0, SERVOMIN_RING_IN);
  CPRing_IN = SERVOMIN_RING_IN;
  pwm.setPWM(4, 0, SERVOMIN_PINKY_IN);
  CPPinky_IN = SERVOMIN_PINKY_IN;
  pwm.setPWM(5, 0, SERVOMIN_THUMB_OUT);
  CPThumb_OUT = SERVOMIN_THUMB_OUT;
  pwm.setPWM(6, 0, SERVOMAX_INDEX_OUT);
  CPIndex_OUT = SERVOMAX_INDEX_OUT;
  pwm.setPWM(7, 0, SERVOMIN_MIDDLE_OUT);
  CPMiddle_OUT = SERVOMIN_MIDDLE_OUT;
  pwm.setPWM(8, 0, SERVOMIN_RING_OUT);
  CPRing_OUT = SERVOMIN_RING_OUT;
  pwm.setPWM(9, 0, SERVOMIN_PINKY_OUT);
  CPPinky_OUT = SERVOMIN_PINKY_OUT;
  pwm.setPWM(11, 0, SERVOMAX_PALM);
  CPPalm = SERVOMAX_PALM;
  pwm.setPWM(12, 0, SERVOMIN_WRIST);
  CPWrist = SERVOMIN_WRIST;
  biceps_shoulder_position(GESTURE_POSITION_BICEPS, SERVOMIN_SHOULDER);
}




void spiderman() {
  pwm.setPWM(0, 0, SERVOMIN_THUMB_IN);
  CPThumb_IN = SERVOMIN_THUMB_IN;
  pwm.setPWM(1, 0, SERVOMAX_INDEX_IN);
  CPIndex_IN = SERVOMAX_INDEX_IN;
  pwm.setPWM(2, 0, SERVOMIN_MIDDLE_IN);
  CPMiddle_IN = SERVOMIN_MIDDLE_IN;
  pwm.setPWM(3, 0, SERVOMIN_RING_IN);
  CPRing_IN = SERVOMIN_RING_IN;
  pwm.setPWM(4, 0, SERVOMAX_PINKY_IN);
  CPPinky_IN = SERVOMAX_PINKY_IN;
  pwm.setPWM(5, 0, SERVOMIN_THUMB_OUT);
  CPThumb_OUT = SERVOMIN_THUMB_OUT;
  pwm.setPWM(6, 0, SERVOMAX_INDEX_OUT);
  CPIndex_OUT = SERVOMAX_INDEX_OUT;
  pwm.setPWM(7, 0, SERVOMIN_MIDDLE_OUT);
  CPMiddle_OUT = SERVOMIN_MIDDLE_OUT;
  pwm.setPWM(8, 0, SERVOMIN_RING_OUT);
  CPRing_OUT = SERVOMIN_RING_OUT;
  pwm.setPWM(9, 0, SERVOMAX_PINKY_OUT);
  CPPinky_OUT = SERVOMAX_PINKY_OUT;
  pwm.setPWM(11, 0, SERVOMAX_PALM);
  CPPalm = SERVOMAX_PALM;
  pwm.setPWM(12, 0, SERVOMAX_WRIST);
  CPWrist = SERVOMAX_WRIST;
  biceps_shoulder_position(GESTURE_POSITION_BICEPS, SERVOMIN_SHOULDER);
}



//index and thumb closed, other fingers extended
void perfect() {
  pwm.setPWM(0, 0, SERVOMIN_THUMB_IN);
  CPThumb_IN = SERVOMIN_THUMB_IN;
  pwm.setPWM(1, 0, SERVOMIN_INDEX_IN);
  CPIndex_IN = SERVOMIN_INDEX_IN;
  pwm.setPWM(2, 0, SERVOMAX_MIDDLE_IN);
  CPMiddle_IN = SERVOMAX_MIDDLE_IN;
  pwm.setPWM(3, 0, SERVOMAX_RING_IN);
  CPRing_IN = SERVOMAX_RING_IN;
  pwm.setPWM(4, 0, SERVOMAX_PINKY_IN);
  CPPinky_IN = SERVOMAX_PINKY_IN;
  pwm.setPWM(5, 0, SERVOMIN_THUMB_OUT);
  CPThumb_OUT = SERVOMIN_THUMB_OUT;
  pwm.setPWM(6, 0, SERVOMIN_INDEX_OUT);
  CPIndex_OUT = SERVOMIN_INDEX_OUT;
  pwm.setPWM(7, 0, SERVOMAX_MIDDLE_OUT);
  CPMiddle_OUT = SERVOMAX_MIDDLE_OUT;
  pwm.setPWM(8, 0, SERVOMAX_RING_OUT);
  CPRing_OUT = SERVOMAX_RING_OUT;
  pwm.setPWM(9, 0, SERVOMAX_PINKY_OUT);
  CPPinky_OUT = SERVOMAX_PINKY_OUT;
  pwm.setPWM(11, 0, SERVOMAX_PALM);
  CPPalm = SERVOMAX_PALM;
  pwm.setPWM(12, 0, SERVOMIN_WRIST);
  CPWrist = SERVOMIN_WRIST;
  biceps_shoulder_position(GESTURE_POSITION_BICEPS, SERVOMIN_SHOULDER);
}



//Index and middle extended, everything else closed
void numberTwo() {
  pwm.setPWM(0, 0, SERVOMIN_THUMB_IN);
  CPThumb_IN = SERVOMIN_THUMB_IN;
  pwm.setPWM(1, 0, SERVOMAX_INDEX_IN);
  CPIndex_IN = SERVOMAX_INDEX_IN;
  pwm.setPWM(2, 0, SERVOMAX_MIDDLE_IN);
  CPMiddle_IN = SERVOMAX_MIDDLE_IN;
  pwm.setPWM(3, 0, SERVOMIN_RING_IN);
  CPRing_IN = SERVOMIN_RING_IN;
  pwm.setPWM(4, 0, SERVOMIN_PINKY_IN);
  CPPinky_IN = SERVOMIN_PINKY_IN;
  pwm.setPWM(5, 0, SERVOMIN_THUMB_OUT);
  CPThumb_OUT = SERVOMIN_THUMB_OUT;
  pwm.setPWM(6, 0, SERVOMAX_INDEX_OUT);
  CPIndex_OUT = SERVOMAX_INDEX_OUT;
  pwm.setPWM(7, 0, SERVOMAX_MIDDLE_OUT);
  CPMiddle_OUT = SERVOMAX_MIDDLE_OUT;
  pwm.setPWM(8, 0, SERVOMIN_RING_OUT);
  CPRing_OUT = SERVOMIN_RING_OUT;
  pwm.setPWM(9, 0, SERVOMIN_PINKY_OUT);
  CPPinky_OUT = SERVOMIN_PINKY_OUT;
  pwm.setPWM(11, 0, SERVOMAX_PALM);
  CPPalm = SERVOMAX_PALM;
  pwm.setPWM(12, 0, SERVOMIN_WRIST);
  CPWrist = SERVOMIN_WRIST;
  biceps_shoulder_position(GESTURE_POSITION_BICEPS, SERVOMIN_SHOULDER);
  }




//Index, middle and thumb extended, everything else closed
void numberThree() {
  pwm.setPWM(0, 0, SERVOMAX_THUMB_IN);
  CPThumb_IN = SERVOMAX_THUMB_IN;
  pwm.setPWM(1, 0, SERVOMAX_INDEX_IN);
  CPIndex_IN = SERVOMAX_INDEX_IN;
  pwm.setPWM(2, 0, SERVOMAX_MIDDLE_IN);
  CPMiddle_IN = SERVOMAX_MIDDLE_IN;
  pwm.setPWM(3, 0, SERVOMIN_RING_IN);
  CPRing_IN = SERVOMIN_RING_IN;
  pwm.setPWM(4, 0, SERVOMIN_PINKY_IN);
  CPPinky_IN = SERVOMIN_PINKY_IN;
  pwm.setPWM(5, 0, SERVOMAX_THUMB_OUT);
  CPThumb_OUT = SERVOMAX_THUMB_OUT;
  pwm.setPWM(6, 0, SERVOMAX_INDEX_OUT);
  CPIndex_OUT = SERVOMAX_INDEX_OUT;
  pwm.setPWM(7, 0, SERVOMAX_MIDDLE_OUT);
  CPMiddle_OUT = SERVOMAX_MIDDLE_OUT;
  pwm.setPWM(8, 0, SERVOMIN_RING_OUT);
  CPRing_OUT = SERVOMIN_RING_OUT;
  pwm.setPWM(9, 0, SERVOMIN_PINKY_OUT);
  CPPinky_OUT = SERVOMIN_PINKY_OUT;
  pwm.setPWM(11, 0, SERVOMAX_PALM);
  CPPalm = SERVOMAX_PALM;
  pwm.setPWM(12, 0, SERVOMIN_WRIST);
  CPWrist = SERVOMIN_WRIST;
  biceps_shoulder_position(GESTURE_POSITION_BICEPS, SERVOMIN_SHOULDER);
}




//rock and roll -> thumb and pinky extended, everything else closed
void rockAndRoll() {
  pwm.setPWM(0, 0, SERVOMAX_THUMB_IN);
  CPThumb_IN = SERVOMAX_THUMB_IN;
  pwm.setPWM(1, 0, SERVOMIN_INDEX_IN);
  CPIndex_IN = SERVOMIN_INDEX_IN;
  pwm.setPWM(2, 0, SERVOMIN_MIDDLE_IN);
  CPMiddle_IN = SERVOMIN_MIDDLE_IN;
  pwm.setPWM(3, 0, SERVOMIN_RING_IN);
  CPRing_IN = SERVOMIN_RING_IN;
  pwm.setPWM(4, 0, SERVOMAX_PINKY_IN);
  CPPinky_IN = SERVOMAX_PINKY_IN;
  pwm.setPWM(5, 0, SERVOMAX_THUMB_OUT);
  CPThumb_OUT = SERVOMAX_THUMB_OUT;
  pwm.setPWM(6, 0, SERVOMIN_INDEX_OUT);
  CPIndex_OUT = SERVOMIN_INDEX_OUT;
  pwm.setPWM(7, 0, SERVOMIN_MIDDLE_OUT);
  CPMiddle_OUT = SERVOMIN_MIDDLE_OUT;
  pwm.setPWM(8, 0, SERVOMIN_RING_OUT);
  CPRing_OUT = SERVOMIN_RING_OUT;
  pwm.setPWM(9, 0, SERVOMAX_PINKY_OUT);
  CPPinky_OUT = SERVOMAX_PINKY_OUT;
  pwm.setPWM(11, 0, SERVOMIN_PALM);
  CPPalm = SERVOMIN_PALM;
  pwm.setPWM(12, 0, SERVOMIN_WRIST);
  CPWrist = SERVOMIN_WRIST;
  biceps_shoulder_position(GESTURE_POSITION_BICEPS, SERVOMIN_SHOULDER);
}

//openhand + side to side movement of the biceps servo
void sayHi() {

  openHand();
  int j = 0;
  while (j<5){
     while(CPBiceps < SERVOMAX_BICEPS){
      CPBiceps++;
      pwm.setPWM(14, 0, CPBiceps);
      delay(10);
    }
    delay(1000);
    while(CPBiceps > SERVOMIN_BICEPS){
      CPBiceps--;
      pwm.setPWM(14, 0, CPBiceps);
      delay(10);
    }
   
    j++;
    delay(1000);
  }

}

//point index + side to side movement of the biceps servo
void sayNo() {
  pointIndex();
  int j = 0;
  while (j<5){
     while(CPBiceps < SERVOMAX_BICEPS){
      CPBiceps++;
      pwm.setPWM(14, 0, CPBiceps);
      delay(10);
    }
    delay(1000);
    while(CPBiceps > SERVOMIN_BICEPS){
      CPBiceps--;
      pwm.setPWM(14, 0, CPBiceps);
      delay(10);
    }
   
    j++;
    delay(1000);
  }
}


void biceps_shoulder_position(int biceps_position, int shoulder_position){
  while(CPBiceps > biceps_position){
    CPBiceps--;
    pwm.setPWM(14, 0, CPBiceps);
    delay(10);
  }
  while(CPBiceps < biceps_position){
    CPBiceps++;
    pwm.setPWM(14, 0, CPBiceps);
    delay(10);
  }
  while(CPShoulder > shoulder_position) {
    CPShoulder--;
    pwm.setPWM(15, 0, CPShoulder);
    delay(10);
  }
  while(CPShoulder < shoulder_position) {
    CPShoulder++;
    pwm.setPWM(15, 0, CPShoulder);
    delay(10);
  }
}

//JOYSTICKS CODE

//THUMB JOYSTICK
BLYNK_WRITE(V1) {
  int x = param[0].asInt();
  int y = param[1].asInt();

  if (y < 126 && CPThumb_IN > SERVOMIN_THUMB_IN + 5 && CPThumb_OUT > SERVOMIN_THUMB_OUT + 5) {
    CPThumb_IN = CPThumb_IN - 5;
    CPThumb_OUT = CPThumb_OUT - 5;
  } else if (y > 128 && CPThumb_IN < SERVOMAX_THUMB_IN - 5 && CPThumb_OUT < SERVOMAX_THUMB_OUT - 5) {
    CPThumb_IN = CPThumb_IN + 5;
    CPThumb_OUT = CPThumb_OUT + 5;
  }
  
  if (x < 126 && CPPalm < SERVOMAX_PALM - 5) {
    CPPalm = CPPalm + 5;
  } else if (x > 128 && CPPalm > SERVOMIN_PALM + 5) {
    CPPalm = CPPalm - 5;
  }
  
  pwm.setPWM(0, 0, CPThumb_IN);
  pwm.setPWM(5, 0, CPThumb_OUT);
  pwm.setPWM(11, 0, CPPalm);
}

//INDEX JOYSTICK
BLYNK_WRITE(V2) {
  int x = param[0].asInt();
  int y = param[1].asInt();

  if (y < 126 && CPIndex_IN > SERVOMIN_INDEX_IN + 5 && CPIndex_OUT > SERVOMIN_INDEX_OUT + 5) {
    CPIndex_IN = CPIndex_IN - 5;
    CPIndex_OUT = CPIndex_OUT - 5;
  } else if (y > 128 && CPIndex_IN < SERVOMAX_INDEX_IN - 5 && CPIndex_OUT < SERVOMAX_INDEX_OUT - 5) {
    CPIndex_IN = CPIndex_IN + 5;
    CPIndex_OUT = CPIndex_OUT + 5;
  }

  pwm.setPWM(1, 0, CPIndex_IN);
  pwm.setPWM(6, 0, CPIndex_OUT);
}

//MIDDLE JOYSTICK
BLYNK_WRITE(V3) {
  int x = param[0].asInt();
  int y = param[1].asInt();

  if (y < 126 && CPMiddle_IN > SERVOMIN_MIDDLE_IN + 5 && CPMiddle_OUT > SERVOMIN_MIDDLE_OUT + 5) {
    CPMiddle_IN = CPMiddle_IN - 5;
    CPMiddle_OUT = CPMiddle_OUT - 5;
  } else if (y > 128 && CPMiddle_IN < SERVOMAX_MIDDLE_IN - 5 && CPMiddle_OUT < SERVOMAX_MIDDLE_OUT - 5) {
    CPMiddle_IN = CPMiddle_IN + 5;
    CPMiddle_OUT = CPMiddle_OUT + 5;
  }

  pwm.setPWM(2, 0, CPMiddle_IN);
  pwm.setPWM(7, 0, CPMiddle_OUT);
}

//RING JOYSTICK
BLYNK_WRITE(V4) {
  int x = param[0].asInt();
  int y = param[1].asInt();

  if (y < 126 && CPRing_IN > SERVOMIN_RING_IN + 5 && CPRing_OUT > SERVOMIN_RING_OUT + 5) {
    CPRing_IN = CPRing_IN - 5;
    CPRing_OUT = CPRing_OUT - 5;
  } else if (y > 128 && CPRing_IN < SERVOMAX_RING_IN - 5 && CPRing_OUT < SERVOMAX_RING_OUT - 5) {
    CPRing_IN = CPRing_IN + 5;
    CPRing_OUT = CPRing_OUT + 5;
  }

  pwm.setPWM(3, 0, CPRing_IN);
  pwm.setPWM(8, 0, CPRing_OUT);
}

//PINKY JOYSTICK
BLYNK_WRITE(V5) {
  int x = param[0].asInt();
  int y = param[1].asInt();

  if (y < 126 && CPPinky_IN > SERVOMIN_PINKY_IN + 5 && CPRing_OUT > SERVOMIN_PINKY_OUT + 5) {
    CPPinky_IN = CPPinky_IN - 5;
    CPPinky_OUT = CPPinky_OUT - 5;
  } else if (y > 128 && CPPinky_IN < SERVOMAX_PINKY_IN - 5 && CPPinky_OUT < SERVOMAX_PINKY_OUT - 5) {
    CPPinky_IN = CPPinky_IN + 5;
    CPPinky_OUT = CPPinky_OUT + 5;
  }

  pwm.setPWM(4, 0, CPPinky_IN);
  pwm.setPWM(9, 0, CPPinky_OUT);
}


//WRIST JOYSTICK
BLYNK_WRITE(V6) {
  int x = param[0].asInt();
  int y = param[1].asInt();

  if (y < 126 && CPWrist < SERVOMAX_WRIST - 5) {
    CPWrist = CPWrist + 5;
  } else if (y > 128 && CPWrist > SERVOMIN_WRIST + 5) {
    CPWrist = CPWrist - 5;
  }
  
  if (x < 126 && CPWristPronation > SERVOMIN_WRIST_PRONATION + 5) {
    CPWristPronation = CPWristPronation - 5;
  } else if (x > 126 && CPWristPronation < SERVOMAX_WRIST_PRONATION - 5) {
    CPWristPronation = CPWristPronation + 5;
  }
  
  pwm.setPWM(12, 0, CPWrist);
  pwm.setPWM(13, 0, CPWristPronation);
}

//ELBOW JOYSTICK
BLYNK_WRITE(V7) {
  int x = param[0].asInt();
  int y = param[1].asInt();

  if (y < 126 && CPShoulder > SERVOMIN_SHOULDER + 5) {
    CPShoulder = CPShoulder - 5;
  } else if (y > 128 && CPShoulder < SERVOMAX_SHOULDER - 5) {
    CPShoulder = CPShoulder + 5;
  }
  
  if (x < 126 && CPBiceps > SERVOMIN_BICEPS + 5) {
    CPBiceps = CPBiceps - 5;
  } else if (x > 126 && CPBiceps < SERVOMAX_BICEPS - 5) {
    CPBiceps = CPBiceps + 5;
  }
  
  pwm.setPWM(14, 0, CPBiceps);
  pwm.setPWM(15, 0, CPShoulder);
}

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("Set up done!");
}

void loop() {
  Blynk.run();
}