// Include Libraries
#include "Arduino.h"
#include "DCMDriverL298.h"


// Pin Definitions
#define DCMOTORDRIVERL298_1_PIN_INT1	6
#define DCMOTORDRIVERL298_1_PIN_ENB	3
#define DCMOTORDRIVERL298_1_PIN_INT2	7
#define DCMOTORDRIVERL298_1_PIN_ENA	2
#define DCMOTORDRIVERL298_1_PIN_INT3	8
#define DCMOTORDRIVERL298_1_PIN_INT4	9
#define DCMOTORDRIVERL298_2_PIN_INT1	10
#define DCMOTORDRIVERL298_2_PIN_ENB	5
#define DCMOTORDRIVERL298_2_PIN_INT2	11
#define DCMOTORDRIVERL298_2_PIN_ENA	4
#define DCMOTORDRIVERL298_2_PIN_INT3	12
#define DCMOTORDRIVERL298_2_PIN_INT4	13
#define IRLINEFOLLOW_1_PIN_OUT	14
#define IRLINEFOLLOW_2_PIN_OUT	15
#define IRLINEFOLLOW_3_PIN_OUT	16



// Global variables and defines

// object initialization
DCMDriverL298 dcMotorDriverL298_1(DCMOTORDRIVERL298_1_PIN_ENA,DCMOTORDRIVERL298_1_PIN_INT1,DCMOTORDRIVERL298_1_PIN_INT2,DCMOTORDRIVERL298_1_PIN_ENB,DCMOTORDRIVERL298_1_PIN_INT3,DCMOTORDRIVERL298_1_PIN_INT4);
DCMDriverL298 dcMotorDriverL298_2(DCMOTORDRIVERL298_2_PIN_ENA,DCMOTORDRIVERL298_2_PIN_INT1,DCMOTORDRIVERL298_2_PIN_INT2,DCMOTORDRIVERL298_2_PIN_ENB,DCMOTORDRIVERL298_2_PIN_INT3,DCMOTORDRIVERL298_2_PIN_INT4);


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    pinMode(IRLINEFOLLOW_1_PIN_OUT, INPUT);
    pinMode(IRLINEFOLLOW_2_PIN_OUT, INPUT);
    pinMode(IRLINEFOLLOW_3_PIN_OUT, INPUT);
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {
    // L298N Motor Driver with Dual Hobby DC motors #1 - Test Code
    //Start both motors. note that rotation direction is determined by the motors connection to the driver.
    //You can change the speed by setting a value between 0-255, and set the direction by changing between 1 and 0.
    dcMotorDriverL298_1.setMotorA(200,1);
    dcMotorDriverL298_1.setMotorB(200,0);
    delay(2000);
    //Stop both motors
    dcMotorDriverL298_1.stopMotors();
    delay(2000);

    }
    else if(menuOption == '2') {
    // L298N Motor Driver with Dual Hobby DC motors #2 - Test Code
    //Start both motors. note that rotation direction is determined by the motors connection to the driver.
    //You can change the speed by setting a value between 0-255, and set the direction by changing between 1 and 0.
    dcMotorDriverL298_2.setMotorA(200,1);
    dcMotorDriverL298_2.setMotorB(200,0);
    delay(2000);
    //Stop both motors
    dcMotorDriverL298_2.stopMotors();
    delay(2000);

    }
    else if(menuOption == '3') {
    // IR Line Track Follower Sensor #1 - Test Code
    //Read IR Line Follower Sensor. irLineFollow_1Var will be '0' if a black line was detected
    bool irLineFollow_1Var = digitalRead(IRLINEFOLLOW_1_PIN_OUT);
    Serial.print(F("LineFollow: ")); Serial.println(irLineFollow_1Var);

    }
    else if(menuOption == '4') {
    // IR Line Track Follower Sensor #2 - Test Code
    //Read IR Line Follower Sensor. irLineFollow_2Var will be '0' if a black line was detected
    bool irLineFollow_2Var = digitalRead(IRLINEFOLLOW_2_PIN_OUT);
    Serial.print(F("LineFollow: ")); Serial.println(irLineFollow_2Var);

    }
    else if(menuOption == '5') {
    // IR Line Track Follower Sensor #3 - Test Code
    //Read IR Line Follower Sensor. irLineFollow_3Var will be '0' if a black line was detected
    bool irLineFollow_3Var = digitalRead(IRLINEFOLLOW_3_PIN_OUT);
    Serial.print(F("LineFollow: ")); Serial.println(irLineFollow_3Var);

    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) L298N Motor Driver with Dual Hobby DC motors #1"));
    Serial.println(F("(2) L298N Motor Driver with Dual Hobby DC motors #2"));
    Serial.println(F("(3) IR Line Track Follower Sensor #1"));
    Serial.println(F("(4) IR Line Track Follower Sensor #2"));
    Serial.println(F("(5) IR Line Track Follower Sensor #3"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing L298N Motor Driver with Dual Hobby DC motors #1"));
    		else if(c == '2') 
    			Serial.println(F("Now Testing L298N Motor Driver with Dual Hobby DC motors #2"));
    		else if(c == '3') 
    			Serial.println(F("Now Testing IR Line Track Follower Sensor #1"));
    		else if(c == '4') 
    			Serial.println(F("Now Testing IR Line Track Follower Sensor #2"));
    		else if(c == '5') 
    			Serial.println(F("Now Testing IR Line Track Follower Sensor #3"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}
