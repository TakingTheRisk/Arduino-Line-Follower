// ARduino Uno R3
// DC Motors are on pins 2,3,4,5
// IR Sensors on 6,7

int motorL1 = 5;
int motorL2 = 4;
int motorR1 = 3;
int motorR2 = 2;

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
}

void loop()
{
	int statusSensorL = digitalRead(7);
  	int statusSensorR = digitalRead(6);
  
  	if(statusSensorL == statusSensorR == 1)
    {
      digitalWrite(motorL1, LOW);
      digitalWrite(motorL2, LOW);
      digitalWrite(motorR1, LOW);
      digitalWrite(motorR2, LOW);
    }
    else if (statusSensorL == 0 == statusSensorR)
    {
     digitalWrite(motorR1, HIGH);
     digitalWrite(motorR2, HIGH);
     digitalWrite(motorL1, HIGH);
     digitalWrite(motorL2, HIGH);
    }
  	else if (statusSensorR == 1 != statusSensorL)
    {
     digitalWrite(motorL1, HIGH);
     digitalWrite(motorL2, HIGH);
     digitalWrite(motorR1, LOW);
     digitalWrite(motorR2, LOW);
    } 
  	else if (statusSensorL == 1 != statusSensorR)
    {
     digitalWrite(motorR1, HIGH);
     digitalWrite(motorR2, HIGH);
     digitalWrite(motorL1, LOW);
     digitalWrite(motorL2, LOW);
    }

  	
}
