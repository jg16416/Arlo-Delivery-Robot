#include <NewPing.h>

#include <Servo.h>                           // Include servo library
String directions[4] = {"Front:    ",         // Directions for display 
                        "Back:     ", 
                        "Left:     ", 
                        "Right:    "};
Servo servoLeft;                             // Declare left and right servos
Servo servoRight;
int pingPin[4] = {41, 40, 39, 38};              // Ping pins
int cmDist[4];                                // Cm distances
int i = 0;    
void setup()                                 // Built-in initialization block
{
  
  servoLeft.attach(36);                      // Attach left signal to pin 36
  servoRight.attach(37);                     // Attach right signal to pin 37
Serial.begin(9600); 
servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1300); 
}  
void loop()
 { 
  cmDist[0] = pingCm(pingPin[0]);     
  if (cmDist[i]<20)
  {
         // Right wheel clockwise
  //Go backword
    servoLeft.writeMicroseconds(1300);         // Left wheel clockwise
  servoRight.writeMicroseconds(1700); 
  delay(1000);
     servoLeft.writeMicroseconds(1300);         // Left wheel clockwise
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(2000); 
  
  //servoLeft.writeMicroseconds(1300);         // Left wheel clockwise
  //servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  //delay(1000); 
  //servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  //servoRight.writeMicroseconds(1700);        // Right wheel counterclockwise
  //delay(600);           // Right wheel counterclockwise 
  stop();
  delay(1000);
  
}  
 
                          
  }
  int pingCm(int pin)                           // Ping measurement function
{
  digitalWrite(pin, LOW);                     // Pin to output-low
  pinMode(pin, OUTPUT);                       
  delayMicroseconds(200);                     // Required between successive
  digitalWrite(pin, HIGH);                    // Send high pulse
  delayMicroseconds(5);                       // Must be at least 2 us
  digitalWrite(pin, LOW);                     // End pulse to start ping
  pinMode(pin, INPUT);                        // Change to input
}
void stop()
{
  digitalWrite(36,LOW);
  digitalWrite(37,LOW);
  }
