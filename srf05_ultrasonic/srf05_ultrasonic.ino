#define ECHOPIN 2                            // Pin to receive echo pulse    
#define TRIGPIN 3                            // Pin to send trigger pulse
#define LEDRED 7
#define LEDGREEN 4

void setup(){
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(LEDRED, OUTPUT);
  pinMode(LEDGREEN, OUTPUT);
}

void loop(){
  digitalWrite(TRIGPIN, LOW);                   // Set the trigger pin to low for 2uS
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  // Send a 10uS high to trigger ranging
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   // Send pin low again
  int distance = pulseIn(ECHOPIN, HIGH);        // Read in times pulse
  distance = distance/58;  // Calculate distance from time of pulse
  if (distance > 15){
    Serial.println("Green");
    digitalWrite(LEDRED, LOW);
    digitalWrite(LEDGREEN, HIGH);
  }
  else {
    Serial.println("red");
    digitalWrite(LEDGREEN, LOW);
    digitalWrite(LEDRED, HIGH);
  }
                        
  Serial.println(distance);                     
  delay(50);                                    // Wait 50mS before next ranging
}
