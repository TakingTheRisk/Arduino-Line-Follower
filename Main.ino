// Include Libraries
#include "Arduino.h"
#include "DCMDriverL298.h"

#define MotorDrive1 dcMotorDriverL298_1
#define MotorDrive2 dcMotorDriverL298_2
// Pin Definitions
#define M1C1	6
#define MotorDrive1ENB	3
#define M1C2	7
#define MotorDrive1ENA	2
#define M2C1	8
#define M2C2	9
#define M3C1	10
#define MotorDrive2ENB	5
#define M3C2	11
#define MotorDrive2ENA	4
#define M4C1	12
#define M4C2	13
#define IRLINEFOLLOW_1_PIN_OUT	14 // Left
#define IRLINEFOLLOW_2_PIN_OUT	15 // Mid
#define IRLINEFOLLOW_3_PIN_OUT	16 // Right

#define MotorDrive1 dcMotorDriverL298_1
#define MotorDrive2 dcMotorDriverL298_2


// Global variables and defines

// object initialization
DCMDriverL298 MotorDrive1(MotorDrive1ENA,M1C1,M1C2,MotorDrive1ENB,M2C1,M2C2);
DCMDriverL298 MotorDrive2(MotorDrive2ENA,M3C1,M3C2,MotorDrive2ENB,M4C1,M4C2);

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{  
    pinMode(IRLINEFOLLOW_1_PIN_OUT, INPUT);
    pinMode(IRLINEFOLLOW_2_PIN_OUT, INPUT);
    pinMode(IRLINEFOLLOW_3_PIN_OUT, INPUT);
}

void left()
{
    MotorDrive1.setMotorA(255,1);
    MotorDrive1.setMotorB(255,1);
    MotorDrive2.setMotorA(255,0);
    MotorDrive2.setMotorB(255,0);
}

void softLeft()
{
    MotorDrive1.setMotorA(127,1);
    MotorDrive1.setMotorB(127,1);
    MotorDrive2.setMotorA(127,0);
    MotorDrive2.setMotorB(127,0);
}

void forward()
{
    MotorDrive1.setMotorA(255,1);
    MotorDrive1.setMotorB(255,1);
    MotorDrive2.setMotorA(255,1);
    MotorDrive2.setMotorB(255,1);   
}

void softRight()
{
    MotorDrive1.setMotorA(127,0);
    MotorDrive1.setMotorB(127,0);
    MotorDrive2.setMotorA(127,1);
    MotorDrive2.setMotorB(127,1);
}

void left()
{
    MotorDrive1.setMotorA(255,0);
    MotorDrive1.setMotorB(255,0);
    MotorDrive2.setMotorA(255,1);
    MotorDrive2.setMotorB(255,1);
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    if(IRLINEFOLLOW_2_PIN_OUT == LOW != IRLINEFOLLOW_3_PIN_OUT != IRLINEFOLLOW_1_PIN_OUT)
    {
     forward();   
    } else if (IRLINEFOLLOW_2_PIN_OUT == LOW == IRLINEFOLLOW_1_PIN_OUT != IRLINEFOLLOW_3_PIN_OUT)
    {
        softRight();   
    } else if (IRLINEFOLLOW_2_PIN_OUT == LOW == IRLINEFOLLOW_3_PIN_OUT != IRLINEFOLLOW_1_PIN_OUT)
    {
        softLeft();   
    } else if(IRLINEFOLLOW_1_PIN_OUT == LOW != IRLINEFOLLOW_2_PIN_OUT != IRLINEFOLLOW_3_PIN_OUT)
    {
        right();   
    } else if(IRLINEFOLLOW_3_PIN_OUT == LOW != IRLINEFOLLOW_1_PIN_OUT != IRLINEFOLLOW_2_PIN_OUT)
    {
        left();   
    } else if(IRLINEFOLLOW_2_PIN_OUT == IRLINEFOLLOW_2_PIN_OUT == IRLINEFOLLOW_2_PIN_OUT == LOW)
    {
        
        MotorDrive1.stopMotors();
        MotorDrive2.stopMotors();
        
    } else if(IRLINEFOLLOW_1_PIN_OUT == IRLINEFOLLOW_2_PIN_OUT == IRLINEFOLLOW_3_PIN_OUT == HIGH)
    {
    MotorDrive1.setMotorA(255,0);
    MotorDrive1.setMotorB(255,0);
    MotorDrive2.setMotorA(255,0);
    MotorDrive2.setMotorB(255,0); 
    }
    


    
    
}
