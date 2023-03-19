//Main Code of IoT PBL
//COde Of Smart shoes using buzzer,vibrztion motor and Gps Module

#include <TinyGPS++.h>
#include <SoftwareSerial.h>
static const int RXPin =4, TXPin = 3;
static const uint32_t GPSBaud = 9600;
// The TinyGPS++ object
TinyGPSPlus gps;
// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);
// For stats that happen every 5 seconds
unsigned long last = 0UL;
// defines pins numbers
int trigPin = 6;
int echoPin = 5;
int buzzer = 12;
int vibrationPin = 7;
long a;
 
// defines variables
float duration;
int distance;
int safetyDistance;
void setup() {
 Serial.begin(115200);
 ss.begin(GPSBaud);
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
 pinMode(echoPin, INPUT); // Sets the echoPin as an Input
 pinMode(buzzer, OUTPUT);
 pinMode(vibrationPin, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
    while (ss.available() > 0)
     gps.encode(ss.read());
   Serial.print(F("  Lat="));
   Serial.print(gps.location.lat(), 6);
   Serial.print(F(" Long="));
   Serial.println(gps.location.lng(), 6);
    if (gps.charsProcessed() < 10)
     {Serial.println(F("WARNING: No GPS data.  Check wiring."));
   last = millis();
   Serial.println();
     }
   // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
 
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
//delayMicroseconds(10);
digitalWrite(trigPin, LOW);
 
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
   distance= duration*0.034/2;
  
safetyDistance = distance;
if (safetyDistance <=25){
  digitalWrite(buzzer, HIGH);
  digitalWrite(vibrationPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(vibrationPin, LOW);
}
Serial.print("Distance: ");
Serial.println(distance);
}
