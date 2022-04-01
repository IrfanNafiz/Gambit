#include <ServoEasing.h>

#define START_DEGREE_VALUE  0 // The degree value written to the servo at time of attach.

ServoEasing servobot;
ServoEasing servoarm1;
ServoEasing servoarm2;
ServoEasing servoclaw;

// for pin declaration
int sensor1 = 0;
int sensor2 = 1;
int sensor3 = 2;
int sensor4 = 3;
int sensor5 = 4;
int sensor6 = 5;
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
int sonar1_trig = 0, sonar1_echo = 0; //top
int sonar2_trig = 0, sonar2_echo = 0; //left
int sonar3_trig = 0, sonar3_echo = 0; //center
int sonar4_trig = 0, sonar4_echo = 0; //right

//side sonar array values
int sonarleft_trig = 0;
int sonarleft_echo = 0;
int sonarright_trig = 0;
int sonarright_echo = 0;

//front sonar array values
int son1 = 0;
int son2 = 0;
int son3 = 0;
int son4 = 0;

//side sonar array values
int sonl = 0;
int sonr = 0;

// debug code
//int trigs[6];
//int echos[6];

// initialize motor pins
int lme=2, lmf=52, lmb=53, rme=3, rmf=50, rmb=51; 

// pwn levels
int fast = 150;
int med = 100;
int slow = 75;
int off = 0;

int sonar_max = 6; // maximum number of sonars available
long duration; // variable for the duration of sound wave travel
int distance[6]; // variable for the distance measurement
int d[6]; // array of variables for binary distance values
int d_threshold = 10; //10cm distance threshold for initial judgment in sonarcalc
int d_binary = 0;

// declare functions
void TCRTSensorRead();
void motorRun(int a , int b);
void SonarSensorRead();

//CONTROL BOARD
int BotRunning = 1;
int IRCheck = 1;
int motorPower = 0;
int servoPower = 1;
int flag = 0; //0 for lfr, 1 for auto clean, 2 for manual clean

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing systems...");

  //init servos for arm (pwm)
  servobot.attach(4);
  servoarm1.attach(5);
  servoarm2.attach(6);
  servoclaw.attach(7);

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
  pinMode(sonar2_echo, INPUT);
  pinMode(sonar3_echo, INPUT);
  pinMode(sonar4_echo, INPUT);
  pinMode(sonarleft_echo, INPUT);
  pinMode(sonarright_echo, INPUT);
// Sets the trigPin as an OUTPUT
  pinMode(sonar1_trig, OUTPUT);
  pinMode(sonar2_trig, OUTPUT);
  pinMode(sonar3_trig, OUTPUT);
  pinMode(sonar4_trig, OUTPUT);
  pinMode(sonarleft_trig, OUTPUT);
  pinMode(sonarright_trig, OUTPUT);

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
      TCRTSensorRead();

      if (servoPower == 1) {
        servobot.easeTo(0);
        servoarm1.easeTo(0);
        servoarm2.easeTo(0);
      }

      //ircheck
      if (IRCheck = 1) {
//        Serial.print("Analog: ");
//        Serial.print(analogRead(sensor1));
//        Serial.print(" ");
//        Serial.print(analogRead(sensor2));
//        Serial.print(" ");
//        Serial.print(analogRead(sensor3));
//        Serial.print(" ");
//        Serial.print(analogRead(sensor4));
//        Serial.print(" ");
//        Serial.print(analogRead(sensor5));
//        Serial.print(" ");
//        Serial.print(analogRead(sensor6));
//        Serial.print(" ");

        Serial.print("BIN: ");
        Serial.print(v1);
        Serial.print(" ");
        Serial.print(v2);
        Serial.print(" ");
        Serial.print(v3);
        Serial.print(" ");
        Serial.print(v4);
        Serial.print(" ");
        Serial.print(v5);
        Serial.print(" ");
        Serial.print(v6);
        Serial.print(" ");
        
        Serial.print("DATA: ");
        Serial.print(sdata, BIN);
        Serial.print(" ");

      }

//      Serial.println("Checking IR for motion.");
//      Serial.println(data);

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
  while (flag==1) { //cleaning-mode auto
      SonarSensorRead();

      //if all front sonars show far, continue
      if (d_binary == 0b1111) {
        motorRun(100,100);
      }
      
      //d[0] distance from top sonar is near, always avoid
      if (d[0] == 0){
//        u_turn();
      }

      if (d_binary == 0b0100) {
//        turn_left() //*till 0010 or else continue/uturn
      }

      if (d_binary == 0b0001) {
//        turn right() //*till 0010 or else continue/uturn
      }
      
      if (d_binary == 0b0110) {
//        turn left() //*till 0010 or else continue/uturn
      }

      if (d_binary == 0b0011) {
//        turn right() //*till 0010 or else continue/uturn
      }
         
  }
  while (flag==2) { //cleaning-mode manual
      //ENTIRELY BT CONTROLLED MOTION AND GRAB         
  }
  while (flag==3) { //stopbot
      BotRunning = 0;
  }
}
}
