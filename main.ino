const int AIN1 = 13;
const int AIN2 = 12;
const int PWMA = 11;
const int BIN1 = 8;
const int BIN2 = 9;
const int PWMB = 10;
int switchPin = 7;
int tooclose = 500;



#include <RedBot.h>

RedBotSensor right = RedBotSensor(A3);   // initialize a left sensor object on A3
RedBotSensor center = RedBotSensor(A4); // initialize a center sensor object on A6
RedBotSensor left = RedBotSensor(A5);  // initialize a right sensor object on A7
RedBotSensor Distr = RedBotSensor(A0); 
RedBotSensor Distc = RedBotSensor(A1);
RedBotSensor Distl = RedBotSensor(A2);
// constants that are used in the code. LINETHRESHOLD is the level to detect 
// if the sensor is on the line or not. If the sensor value is greater than this
// the sensor is above a DARK line.
//
// SPEED sets the nominal speed

#define LINETHRESHOLDl 980      //good 990
#define LINETHRESHOLDr 800      //good 700
#define LINETHRESHOLDc 980      //good 850
#define SPEEDr 170    // sets the nominal speed. Set to any number from 0 - 255.  //140
#define SPEEDl 175       //145
#define TURN 30         //good 45

//left sensor red: (800,920)
//center sensor red: (770,925)
//right sensor red: (0,590)

//start of distance sensor code

#include <SharpIR.h>

#define IR1 A0 // define signal pin
#define IR2 A1 // define signal pin
#define IR3 A2

#define model1 1080 // for GP2Y0A21YK0F  used 1080
#define model2 1080 // for GP2Y0A21YK0F  used 1080
#define model3 1080 

// Sharp IR code for Robojax.com
// ir: the pin where your sensor is attached
/*
10 to 80 cm GP2Y0A21YK0F  use 1080

*/
SharpIR SharpIR1(IR1, model1);
SharpIR SharpIR2(IR2, model2);
SharpIR SharpIR3(IR3, model3);

//end of distance sensor presetup code

//left sensor red: (870,920)
//center sensor red: (885,925)
//right sensor red: (480,590)

RedBotMotors motors;
int motorSpeedR = 0;
int motorSpeedL = 0;

int Highway = 0;
int Exits = 0;
int Highwaycounter = 0;
int STOP = 0;


//int motorSpeedL;   // variable used to store the leftMotor speed. From line follower
//int motorSpeedR;  // variable used to store the rightMotor speed






void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter motor speed (0-255)... ");




  Serial.begin(9600);
    Serial.println("Welcome to experiment 6.2 - Line Following");         //From line follower
    Serial.println("------------------------------------------");
    delay(2000);
    Serial.println("IR Sensor Readings: ");
    delay(500);
    // Multiple Sharp IR Distance meter code for Robojax.com
 Serial.println("Robojax Sharp IR  ");

 /* // extra pin for 5V if needed
 pinMode(2,OUTPUT);// define pin 2 as output
 digitalWrite(2, HIGH);// set pin 2 HIGH so it always have 5V
  // Robojax.com 20181201 */
}

void loop() {

  if(Serial.available() > 0){
    
    motorSpeedR = Serial.parseInt();        
    motorSpeedL = Serial.parseInt();

    
  }
  

void spinMotorL(int motorSpeedL); 
void spinMotorR(int motorSpeedR);
{
  if(motorSpeedL > 0){
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  } else if(motorSpeedL < 0){
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
  } else{
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
  }
}
  {
  if(motorSpeedR > 0){
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  } else if(motorSpeedR < 0){
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
  } else{
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
  }
  analogWrite(PWMA, abs(motorSpeedL));
  analogWrite(PWMB, abs(motorSpeedR));

//void spinMotorR(int motorSpeedR)
//{
 // if(motorSpeedR > 0){
 //   digitalWrite(BIN1, HIGH);
  //  digitalWrite(BIN2, LOW);
  //} else if(motorSpeedR < 0){
  //  digitalWrite(BIN1, LOW);
  //  digitalWrite(BIN2, HIGH);
  //} else{
  //  digitalWrite(BIN1, LOW);
  //  digitalWrite(BIN2, LOW);
  //}
  //analogWrite(PWMB, abs(motorSpeedR));




  Serial.print(left.read());                          //The rest is from the line follower
    Serial.print("\t");  // tab character
    Serial.print(center.read());
    Serial.print("\t");  // tab character
    Serial.print(right.read());
    Serial.println();
    Serial.print("Motor SpeedL: ");
    Serial.println(motorSpeedL);
    Serial.print("Motor SpeedR: ");
    Serial.println(motorSpeedR);
    Serial.print("Highway = ");
    Serial.println(Highway);
    Serial.print("Highway counter: ");
    Serial.println(Highwaycounter);
    Serial.print("STOP: ");
    Serial.println(STOP);
    Serial.print("Exit = ");
    Serial.println(Exits);
    //Serial.print("\r");
    //Serial.println(motorSpeedL);
    //Serial.print("\r");
    //Serial.println(motorSpeedR);
    
    
// Sharp IR code for Robojax.com 20181201
  //  delay(500);   

  //unsigned long startTime=millis();  // takes the time before the loop on the library begins

  //int dis1=SharpIR1.distance();  // this returns the distance for sensor 1
  //int dis2=SharpIR2.distance();  // this returns the distance for sensor 2
  //int dis3=SharpIR3.distance();  // this returns the distance for sensor 3
  // Sharp IR code for Robojax.com 20181201

 /* Serial.print("Right (1): ");
  Serial.print(dis1);
  Serial.println("cm");

  Serial.print("Middle (2): ");
  Serial.print(dis2);
  Serial.println("cm"); */

  /*Serial.print("Left (3): ");
  Serial.print(dis3);
  Serial.println("cm"); */

  Serial.println("Right: ");
  Serial.println(analogRead(A0));

  Serial.println("Front: ");
  Serial.println(analogRead(A1));

  Serial.println("Left: ");
  Serial.println(analogRead(A2));


//Normal:
 
   //if on the line drive left and right at the same speed (left is CCW / right is CW)
    if(center.read() > LINETHRESHOLDc && left.read() < LINETHRESHOLDl && right.read() < LINETHRESHOLDr)
    {
      Highway = 0;
        Serial.println("forward");
        motorSpeedL = SPEEDl; 
        motorSpeedR = SPEEDr;
    }
 // if the line is under the right sensor, adjust relative speeds to turn to the right
    else if(right.read() > LINETHRESHOLDr)
    {
           Highway = 0;
        Serial.println("right");
        motorSpeedL = (SPEEDl + TURN);
        motorSpeedR = (0);
    }

 // if the line is under the left sensor, adjust relative speeds to turn to the left
    else if(left.read() > LINETHRESHOLDl)
    {
           Highway = 0;
        Serial.println("left");
        motorSpeedL = (0);
        motorSpeedR = SPEEDr + TURN;
    }

 // if line is under the left and center sensor, make a sharp left turn
   else if(left.read() > LINETHRESHOLDl && center.read() > LINETHRESHOLDc)
    {
           Highway = 0;
        Serial.println("sharp left");
        motorSpeedL = 0 - 6*TURN; 
        motorSpeedR = SPEEDr + 1.4*TURN;
    }
 // if line is under the right and center sensor, make a sharp right turn
   else if(right.read() > LINETHRESHOLDr && center.read() > LINETHRESHOLDc)
    {
           Highway = 0;
        Serial.println("sharp right");
        motorSpeedR = 0 - 6*TURN; 
        motorSpeedL = SPEEDl + 1.4*TURN;
    }

     
      }



//If all three sensors are black, then move fast (highway)
    if(right.read() > LINETHRESHOLDr && center.read() > LINETHRESHOLDc && left.read() > LINETHRESHOLDl)
       {
        Highway = 1;
        Highwaycounter ++;
        //goto Highway;
       }
   /*    
     if(800 < left.read() && left.read() > 920 && 770 < center.read() && center.read() < 925 && 0 < right.read() && right.read() < 590)
      {
        Highway = 0;
        STOP = 1;
        motorSpeedR = 0;
        motorSpeedL = 0;
        delay(30000);
      }
       */

   if(right.read() > LINETHRESHOLDr && center.read() > LINETHRESHOLDc && left.read() > LINETHRESHOLDl && Highway == 1)
    {
        motorSpeedL = 1.2*SPEEDl; 
        motorSpeedR = 1.2*SPEEDr;
        Serial.println("Highway Forward");
    }

    else if(right.read() > LINETHRESHOLDr && center.read() > LINETHRESHOLDc && Highway == 1)
      {
        motorSpeedR = 1.2*SPEEDr - .5*TURN;
        motorSpeedL = 1.2*SPEEDl;
        Serial.println("Highway right fix");
      }

    else if(left.read() > LINETHRESHOLDl && center.read() > LINETHRESHOLDc && Highway == 1)
      {
        motorSpeedL = 1.2*SPEEDl - .5*TURN;
        motorSpeedR = 1.2*SPEEDr;
        Serial.println("Highway left fix");
      }
      
    else if(center.read() > LINETHRESHOLDc && left.read() > LINETHRESHOLDl)
      {
          Highway = 0;
          Exits = 1;
          Serial.print("exiting");
          motorSpeedR = 1.1*SPEEDr;
          motorSpeedL = .9*SPEEDl;
          delay(500);
      }
     else if(analogRead(A1) > tooclose && Exits == 1)
     {
          Exits = 1;
          Highway = 0;
          Serial.print("blocked");
          motorSpeedR = SPEEDr;
          motorSpeedL = -SPEEDl;
          delay(1500);
      
     }



        //If all three sensors are white, base motors on distance (Safe distance)
    if(right.read() < LINETHRESHOLDr && center.read() < LINETHRESHOLDc && left.read() < LINETHRESHOLDl && analogRead(A2) < tooclose && analogRead(A0) < tooclose )
      { motorSpeedL = SPEEDl;
        motorSpeedR = SPEEDr;
      }
      
       //If all three sensors are white, base motors on distance (Too close to the left, turn right)
    if(right.read() < LINETHRESHOLDr && center.read() < LINETHRESHOLDc && left.read() < LINETHRESHOLDl && analogRead(A2) > tooclose )
      { motorSpeedL = (SPEEDl + TURN);
        motorSpeedR = (SPEEDr - TURN);
      }

      //If all three sensors are white, base motors on distance (Too close to the right, turn left)
    if(right.read() < LINETHRESHOLDr && center.read() < LINETHRESHOLDc && left.read() < LINETHRESHOLDl && analogRead(A0) > tooclose )
      { motorSpeedL = (SPEEDl - TURN);
        motorSpeedR = (SPEEDr + TURN);
      }

      //If all three sensors are white, base motors on distance (Too close both sides)
    if(right.read() < LINETHRESHOLDr && center.read() < LINETHRESHOLDc && left.read() < LINETHRESHOLDl && analogRead(A2) > tooclose && analogRead(A0) > tooclose )
      { motorSpeedL = SPEEDl;
        motorSpeedR = SPEEDr;
      }





  
 

  
      

  //  if(center.read() > LINETHRESHOLDc &&)
   // {
   //   Highway = 0;
    //  Serial.println(Highway);
     // Exits = 1;
    //  Serial.println(Exits);
    //    goto Exits
    //}
  
 //Exits:
 
      

    // if all sensors are on black or up in the air, stop the motors.
    // otherwise, run motors given the control speeds above.
   // if((left.read() > LINETHRESHOLDl) && (center.read() > LINETHRESHOLDc) && (right.read() > LINETHRESHOLDr) )
   // {
   //     motors.stop();
   // }
   // else
  //  {
   //     motors.leftMotor(motorSpeedL);
  //      motors.rightMotor(motorSpeedR);
  
  //}

    delay(50);  // add a delay to decrease sensitivity.

}
