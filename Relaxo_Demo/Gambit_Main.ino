#include <Arduino.h>

#include "ServoEasing.hpp"

#include "PinDefinitionsAndMore.h"
/*
 * Pin mapping table for different platforms
 *
 * Platform     Servo1      Servo2      Servo3      Analog
 * -------------------------------------------------------
 * AVR + SAMD   9           10          11          A0
 * ESP8266      14 // D5    12 // D6    13 // D7    0
 * ESP32        5           18          19          A0
 * BluePill     PB7         PB8         PB9         PA0
 * APOLLO3      11          12          13          A3
 */
#define INFO // to see serial output of loop
#define SERVO1_PIN 4
#define SERVO2_PIN 5
#define SERVO3_PIN 6
#define SERVO4_PIN 7

ServoEasing Servo1;
ServoEasing Servo2;
ServoEasing Servo3;
ServoEasing Servo4;

#define START_DEGREE_VALUE  0 // The degree value written to the servo at time of attach.


//for BTModule
#include <SoftwareSerial.h>
SoftwareSerial mySerial(15, 14); // RX, TX

// for pin declaration
int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
int sensor4 = A3;
int sensor5 = A4;
int sensor6 = A5;
//int sensor7 = 6;
//int sensor8 = 7;

// for ir sensor values
int s1 = 0;
int s2 = 0;
int s3 = 0;
int s4 = 0;
int s5 = 0;
int s6 = 0;
//int s7 = 0;
//int s8 = 0;

//for ir binary values
int v1 = 0;
int v2 = 0;
int v3 = 0;
int v4 = 0;
int v5 = 0;
int v6 = 0;

// sensor calc init
int threshold = 500;
int sdata = 0;

//sonar array declaration
int sonar1_trig = 22, sonar1_echo = 23; //top
//int sonar2_trig = 0, sonar2_echo = 0; //left
//int sonar3_trig = 0, sonar3_echo = 0; //center
//int sonar4_trig = 0, sonar4_echo = 0; //right

//side sonar array values
//int sonarleft_trig = 0;
//int sonarleft_echo = 0;
//int sonarright_trig = 0;
//int sonarright_echo = 0;

//front sonar array values
int son1 = 0;
//int son2 = 0;
//int son3 = 0;
//int son4 = 0;

//side sonar array values
//int sonl = 0;
//int sonr = 0;

// debug code
//int trigs[6];
//int echos[6];

// initialize motor pins
int lme=2, lmf=52, lmb=53, rme=3, rmf=50, rmb=51; 

// pwm levels
int fast = 150;
int med = 100;
int slow = 75;
int off = 0;

//int sonar_max = 6; // maximum number of sonars available
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
//int d[6]; // array of variables for binary distance values
int d_threshold = 5; //5cm distance threshold for initial judgment in sonarcalc
//int d_binary = 0;

// declare functions
void TCRTSensorRead();
void motorRun(int a , int b);
void SonarSensorRead();
void irCheck();
void com_BT();
void init_BT();

//CONTROL BOARD
int BotRunning = 1;
int IRPower = 1;
int IRCheck = 1;
int motorPower = 1;
int servoPower = 0; //always keep 0, will be 1 if object is near, then undergo hardcoded motion
int flag = 0; //0 for lfr w/ arm, 1 for auto clean (WIP), 2 for manual clean via BT (WIP)

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);

    Serial.println("Initializing systems...");

    //Initializing Servos
#if defined(__AVR_ATmega32U4__) || defined(SERIAL_USB) || defined(SERIAL_PORT_USBVIRTUAL)  || defined(ARDUINO_attiny3217)
    delay(4000); // To be able to connect Serial monitor after reset or power up and before first print out. Do not wait for an attached Serial Monitor!
#endif
    // Just to know which program is running on my Arduino
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_SERVO_EASING));

    /********************************************************
     * Attach servo to pin and set servos to start position.
     * This is the position where the movement starts.
     *******************************************************/
    Serial.print("Attach servo at pin ");
    Serial.println(SERVO1_PIN);
    if (Servo1.attach(SERVO1_PIN, 72) == INVALID_SERVO) {
        Serial.println("Error attaching servo");
    }
    // Wait for servo1 to reach start position.
    delay(500);

    Serial.print("Attach servo at pin ");
    Serial.println(SERVO2_PIN);
    if (Servo2.attach(SERVO2_PIN, 92) == INVALID_SERVO) {
        Serial.println("Error attaching servo");
    }
    // Wait for servo2 to reach start position.
    delay(500);

    Serial.print("Attach servo at pin ");
    Serial.println(SERVO3_PIN);
    if (Servo3.attach(SERVO3_PIN, 130) == INVALID_SERVO) {
        Serial.println("Error attaching servo");
    }
    // Wait for servo3 to reach start position.
    delay(500);

    Serial.print("Attach servo at pin ");
    Serial.println(SERVO4_PIN);
    if (Servo4.attach(SERVO4_PIN, 45) == INVALID_SERVO) {
        Serial.println("Error attaching servo");
    }
    // Wait for servo4 to reach start position.
    delay(500);

    //Initialize BT
  init_BT();

  //ir array for lfr
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(sensor6, INPUT);
//  pinMode(sensor7, INPUT);
//  pinMode(sensor8, INPUT); 

//for front sonar array to detect trash
// Sets the echoPin as an INPUT
  pinMode(sonar1_echo, INPUT);
//  pinMode(sonar2_echo, INPUT);
//  pinMode(sonar3_echo, INPUT);
//  pinMode(sonar4_echo, INPUT);
//  pinMode(sonarleft_echo, INPUT);
//  pinMode(sonarright_echo, INPUT);
// Sets the trigPin as an OUTPUT
  pinMode(sonar1_trig, OUTPUT);
//  pinMode(sonar2_trig, OUTPUT);
//  pinMode(sonar3_trig, OUTPUT);
//  pinMode(sonar4_trig, OUTPUT);
//  pinMode(sonarleft_trig, OUTPUT);
//  pinMode(sonarright_trig, OUTPUT);

// debugging code
//  int trigs[6] = {sonar1_trig, sonar2_trig, sonar3_trig, sonar4_trig, sonarleft_trig, sonarright_trig};
//  int echos[6] = {sonar1_echo, sonar2_echo, sonar3_echo, sonar4_echo, sonarleft_echo, sonarright_echo};

// motor pin outs
  pinMode(lme, OUTPUT);
  pinMode(lmf, OUTPUT);
  pinMode(lmb, OUTPUT);
  pinMode(rme, OUTPUT);
  pinMode(rmf, OUTPUT);
  pinMode(rmb, OUTPUT);

  Serial.println("Relaxo is Ready!");
}

void loop() {
  while (BotRunning == 1) {
    while (flag==0) { //lfr-mode

      SonarSensorRead();
      if (distance<d_threshold) {
        servoPower = 1;
      }

      if (IRPower == 1) {
        TCRTSensorRead();
      }

      //ircheck
      if (IRCheck = 1) {
        irCheck();
        }

      com_BT();

      if (servoPower == 1) {
//        Serial.println("Trying to Grab...");
//   //rotate lower pivot
//     Servo1.easeTo(148, 72/2);
//     delay(2000);
//     Servo1.easeTo(0, 72/2);
//     delay(2000);
//     Servo1.easeTo(72, 72/2);
//     delay(2000);
//     delay(1000);
     //raise upper arm
       Servo3.easeTo(45, 45);
       delay(1000);
     //lower lower arm
       Servo2.easeTo(180, 44);
       delay(1000);
     //pickup
       Servo4.easeTo(110, 45);
       delay(1000);
     //raise lower arm
       Servo2.easeTo(90, 44);
       delay(1000);

     //lower upper arm
       Servo3.easeTo(130, 45);
       delay(1000);
     //place
       Servo4.easeTo(45, 45);
       delay(1000);
      }

      if (motorPower == 1) {
        //WHITE
        if(sdata==0b000000)
        {
          Serial.println("Stop-No Line");
//          delay(2000);
          motorRun(off,off);
        }    

        //FORWARD
        if(sdata==0b001100)
        {
          Serial.println("Forward-Line");
          motorRun(fast,fast);
        }   

        //RIGHT
        if(sdata==0b000110 || sdata==0b000100)
        {
          Serial.println("Low Right-Line");
          motorRun(fast,med);
        }  
        if(sdata==0b000010)
        {
          Serial.println("Med Right-Line");
          motorRun(fast,off);
        }    
        if(sdata==0b000011)
        {
          Serial.println("High Right-Line");
          motorRun(HIGH, off);
        }    
        if(sdata==0b000001)
        {
          Serial.println("Extreme Right-Line");
          motorRun(255, -100);
        }   

        //LEFT
        if(sdata==0b011000 || sdata==0b001000)
        {
          Serial.println("Low Left-Line");
          motorRun(med,fast);
        }    
        if(sdata==0b010000)
        {
          Serial.println("Med Left-Line");
          motorRun(off,fast);
        }    
        if(sdata==0b110000)
        {
          Serial.println("High Left-Line");
          motorRun(off,255);
        }
        if(sdata==0b100000)
        {
          Serial.println("Extreme Left-Line");
          motorRun(-100, 255);
        }   

        //BLACK
        if (sdata == 0b111111) {
          Serial.println("Idle Forward - Black");
          motorRun(med,med);
        }
        
      }
  }
  while (flag==1) { //cleaning-mode auto WORK IN PROGRESS
//      SonarSensorRead();
//
//      //if all front sonars show far, continue
//      if (d_binary == 0b1111) {
//        motorRun(100,100);
//      }
//      
//      //d[0] distance from top sonar is near, always avoid
//      if (d[0] == 0){
////        u_turn();
//      }
//
//      if (d_binary == 0b0100) {
////        turn_left() //*till 0010 or else continue/uturn
//      }
//
//      if (d_binary == 0b0001) {
////        turn right() //*till 0010 or else continue/uturn
//      }
//      
//      if (d_binary == 0b0110) {
////        turn left() //*till 0010 or else continue/uturn
//      }
//
//      if (d_binary == 0b0011) {
////        turn right() //*till 0010 or else continue/uturn
//      }
//         
  }
  while (flag==2) { //cleaning-mode manual
      //ENTIRELY BT CONTROLLED MOTION AND GRAB         
  }
  while (flag==3) { //stopbot
      BotRunning = 0;
  }
}
}
