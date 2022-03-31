 // for pin declaration
int sensor1 = 0;
int sensor2 = 1;
int sensor3 = 2;
int sensor4 = 3;
int sensor5 = 4;
int sensor6 = 5;
int sensor7 = 6;
int sensor8 = 7;

// for ir sensor values
int s1 = 0;
int s2 = 0;
int s3 = 0;
int s4 = 0;
int s5 = 0;
int s6 = 0;
int s7 = 0;
int s8 = 0;

//sonar array declaration
int sonar1_trig = 0, sonar1_echo = 0; //top
int sonar2_trig = 0, sonar2_echo = 0; //left
int sonar3_trig = 0, sonar3_echo = 0; //center
int sonar4_trig = 0, sonar4_echo = 0; //right

//side sonar array values
int sonarleft_trig = 0, sonarleft_echo 0;
int sonarright_trig = 0, sonarright_echo = 0;

//front sonar array values
int son1 = 0;
int son2 = 0;
int son3 = 0;
int son1 = 0;

//side sonar array values
int sonl = 0;
int sonr = 0;

int threshold = 500;
int data = 0;

int lme=12, lmf=11, lmb=10, rme=9, rmf=8, rmb=7;

int sonar_max =6; // maximum number of sonars available
long duration; // variable for the duration of sound wave travel
int distance[sonar_max]; // variable for the distance measurement
int d_threshold = 10; //10cm distance threshold for initial judgment in sonarcalc

int BotRunning = 1;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing systems...");

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

  int trigs[6] = {sonar1_trig, sonar2_trig, sonar3_trig, sonar4_trig, sonarleft_trig, sonarright_trig};
  int echos[6] = {sonar1_echo, sonar2_echo, sonar3_echo, sonar4_echo, sonarleft_echo, sonarright_echo};
  int 

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
      if(data==0b000000)
      {
        motorRun(0,0);
      }    
      if(data==0b001100)
      {
        motorRun(255,255);
      }   
      if(data==0b000110)
      {
        motorRun(255,225);
      }  
      if(data==0b000011)
      {
        motorRun(255,200);
      }    
      if(data==0b000001)
      {
        motorRun(255,50);
      }    
        if(data==0b011000)
      {
        motorRun(225,255);
      }    
      if(data==0b110000)
      {
        motorRun(200,255);
      }    
      if(data==0b100000)
      {
        motorRun(50,255);
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
        u_turn();
      }

      if (d_binary == 0b0100) {
        turn_left() //*till 0010 or else continue/uturn
      }

      if (d_binary == 0b0001) {
        turn right() //*till 0010 or else continue/uturn
      }
      
      if (d_binary == 0b0110) {
        turn left() //*till 0010 or else continue/uturn
      }

      if (d_binary == 0b0011) {
        turn right() //*till 0010 or else continue/uturn
      }
         
  }
  while (flag==2) { //cleaning-mode manual
      //ENTIRELY BT CONTROLLED MOTION AND GRAB         
  }
  while (flag==3) { //stopbot
      BotRunning = 0;
  }


}
