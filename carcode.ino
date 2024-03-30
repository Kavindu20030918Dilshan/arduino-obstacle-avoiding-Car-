#include <Ultrasonic.h>

#include <Servo.h> 
Servo Myservo = Servo();

#define trigPin 9          
#define echoPin 8        
#define MLa 4                   
#define MLb 5                  
#define MRa 6                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           //right motor 1st pin
#define MRb 7
#define MRS 3                
long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(MLa, OUTPUT);     
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);
   pinMode(MRS, OUTPUT);
  pinMode(trigPin, OUTPUT);      
  pinMode(echoPin, INPUT);        
  Myservo.attach(10);
  analogWrite(MRS ,50);
}
void loop() 
{
  Serial.begin(9600);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);      
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);        
  distance = duration / 58.2;                       
  Serial.println(distance);
  delay(10);
  if (distance > 20)                          
  {
    Myservo.write(90);
    digitalWrite(MRb, HIGH);       
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, HIGH);                                
    digitalWrite(MLa, LOW);                                                       
  }
  else if ((distance < 15)&&(distance > 0))        
  {
    digitalWrite(MRb, LOW);     // Stop  vehicle             
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, LOW);
    delay(100);
    
    Myservo.write(0);
    delay(500);
    Myservo.write(180);
    delay(500);
    Myservo.write(90);
    delay(500);
    
    digitalWrite(MRb, LOW);     // Move Backward   vehicle          
    digitalWrite(MRa, HIGH);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, HIGH);
    delay(500);
    digitalWrite(MRb, LOW);        //Stop   vehicle               
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, LOW);  
    delay(500);  
    digitalWrite(MRb, HIGH);     // Move Left   vehicle    
    digitalWrite(MRa, LOW);   
    digitalWrite(MLa, LOW);                                 
    digitalWrite(MLb, LOW);  
    delay(500);
  }

}
