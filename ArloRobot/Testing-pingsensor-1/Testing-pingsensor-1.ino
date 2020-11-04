#include <SoftwareSerial.h>

String directions[4] = {"Front:    ",         // Directions for display 
                        "Back:     ", 
                        "Left:     ", 
                        "Right:    "};
int pingPin[4] = {41, 40, 39, 38};              // Ping pins
int cmDist[4];                                // Cm distances
int i = 0; 
const int distance = 33;
 long duration, inches, cm;
int pingCm(int pin); 
  int pin;

void setup()                                  // Setup function
{
  Serial.begin(115200);                         // Start terminal communication
}

void loop()                                   // Main loop
{
  cmDist[i] = pingCm(pingPin[i]);             // Get distance
  
  Serial.print(directions[i]);                // Display direction
  Serial.print("cmDist[");                    // Display variable name
  Serial.print(i);                            // Display variable index
  Serial.print("] = ");                       // Display ] & =
  Serial.println(cmDist[i]);                  // Display value
  i++;                                        // Increase index by 1
  if(i == 4)                                  // If index is 4
  {
    i = 0;                                    // Reset index to 0
    delay(1000);                              // Wait a second
    Serial.println();                         // Print a blank line
  }
}

  int pingCm(int pin)                      // Ping measurement function
  {
  digitalWrite(pin, LOW);                     // Pin to output-low
  pinMode(pin, OUTPUT);                       
  delayMicroseconds(200);                     // Required between successive
  digitalWrite(pin, HIGH);                    // Send high pulse
  delayMicroseconds(5);                       // Must be at least 2 us
  digitalWrite(pin, LOW);                     // End pulse to start ping
  pinMode(pin, INPUT);                        // Change to input
  long microseconds = pulseIn(pin, HIGH);     // Wait for echo to reflect
  return microseconds / 29 / 2;               // Convert us echo to cm
}
