#define E1 5  // Enable Pin for motor 1
#define E2 6  // Enable Pin for motor 2

#define SFL 4 // Out Pin for IR sensor Far-Left
#define SL 3 // Out Pin for IR sensor Left
#define SM 2 // Out Pin for IR sensor Mid
#define SR 1 // Out Pin for IR sensor Right
#define SFR 0 // Out Pin for IR sensor Far-Right
 
#define I1 9  // Control pin 1 for motor 1
#define I2 8  // Control pin 2 for motor 1
#define I3 10  // Control pin 1 for motor 2
#define I4 11  // Control pin 2 for motor 2
 
void setup()
{
 
    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);
 	
  	pinMode(SFL, INPUT);
    pinMode(SL, INPUT);
    pinMode(SM, INPUT);
    pinMode(SR, INPUT);
    pinMode(SFR, INPUT);
  
    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);
    pinMode(I3, OUTPUT);
    pinMode(I4, OUTPUT);
}

void right()
{
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);	
}
  
void left() 
{
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
  
}

void forward() 
{
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
  
}

void backward() 
{
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
  
}

void loop()
{
  	analogWrite(E2, 0);
    analogWrite(E1, 0);
  
	if (SM == LOW)
    {
        analogWrite(E2, 255);
    	analogWrite(E1, 255);
      
      	forward();
    } else if ( SR == SM != SL == LOW) 
    {
        analogWrite(E2, 255);
    	analogWrite(E1, 127);
      	left();
    } else if ( SR != SM == SL == LOW)
    {
        analogWrite(E2, 127);
    	analogWrite(E1, 255);
      	right();
    } else if (SFR == LOW)
    {
        analogWrite(E2, 255);
    	analogWrite(E1, 0);
      	left();
    } else if (SFL == LOW)
    {
        analogWrite(E2, 0);
    	analogWrite(E1, 255);
      	right();
    } else 
    {
      backward(); 
    }
      
}
