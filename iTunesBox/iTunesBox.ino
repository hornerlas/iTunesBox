//PhotoResistor Pin
int lightPin = A0; //the analog pin the photoresistor is 
                  //connected to
                  //the photoresistor is not calibrated to any units so
                  //this is simply a raw sensor value (relative light)
//LED Pin
int ledPinRed = 8;   //the pin the LED is connected to
                  //we are controlling brightness so 
                  //we use one of the PWM (pulse width
                  // modulation pins)
                  
#define ECHOPIN 9        // Pin to receive echo pulse
#define TRIGPIN 10        // Pin to send trigger pulse
                  
void setup()
{
  Serial.begin(9600);
  pinMode(ledPinRed, OUTPUT); //sets the led pin to output
  pinMode(lightPin, INPUT); //sets the led pin to output
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}
 /*
 * loop() - this function will start after setup 
 * finishes and then repeat
 */
void loop()
{
 int lightLevel = analogRead(lightPin); //Read the lightlevel
 
 
 lightLevel = map(lightLevel, 0, 900, 0, 255); 
         //adjust the value 0 to 900 to
         //span 0 to 255
      
// analogWrite(ledPin, lightLevel);  //write the value
  if(lightLevel > 170)
  { 
     //playPause();
  } 

  int duration, distance;
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  duration = pulseIn(ECHOPIN,HIGH);
   distance = (duration/2) / 29.1;
   
  if(distance < 5)
  {
   playPause();
  } 

 // Serial.print("duration: ");
 // Serial.println(duration);
 // Serial.print("distance: ");
  //Serial.print(distance);
  //Serial.println(" cm");
  delay(50);
  

}

void playPause()
{
  Serial.print('A');
  analogWrite(ledPinRed, 255);
  delay(1000);
  int readBack = Serial.read();
  analogWrite(ledPinRed, 0);
};
