#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 


int myPins[] = {5, 30, 60, 90, 120,150,175};

char* amiibos[]={
  "Mario",
    "CFalc",
    "Kirby",
    "LilMac",
     "Marth",
     "Killager",
     "Fox"};

int pos = 0;    // variable to store the servo position 
int lastPos = -1;
int incomingByte = 0; 
void setup() 
{ 
   Serial.begin(9600); 
   // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
{
   
   
        if (Serial.available() > 0) {
          myservo.attach(10);
          delay(1000);
          incomingByte = Serial.read();
          if(((incomingByte-48) >= 0) && ((incomingByte-48) < 7))
          { 
                if(lastPos != (incomingByte-48))
                {
                  lastPos = incomingByte-48;
                  Serial.print("I received: ");
                  Serial.print(amiibos[incomingByte-48]);
                  Serial.println();
                  myservo.write(myPins[incomingByte -48]);
                }
               else
               {
                  Serial.print("DUPE ENTRY");
                  Serial.println();
               } 
          }
          else
          {
             Serial.print("INPUT OUT OF BOUNDS ");
             Serial.println();
          } 

       delay(1000);
        myservo.detach(); 
        
        }
        
 
}
