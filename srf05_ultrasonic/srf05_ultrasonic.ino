#define ECHOPIN 2                            // Pin to receive echo pulse    
#define TRIGPIN 3                            // Pin to send trigger pulse
#define LEDRED 7
#define LEDGREEN 4

int distance = -1;
int pulse_in = 0;

void setup(){
  Serial.begin(9600);
  Serial.println("Ready");
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
  pulse_in = pulseIn(ECHOPIN, HIGH);        // Read in times pulse
  distance = pulse_in/58;  // Calculate distance from time of pulse
  Serial.println(distance);
  if (distance > 15){
    //Serial.println("Green");
    digitalWrite(LEDRED, LOW);
    digitalWrite(LEDGREEN, HIGH);
  }
  else {
    //Serial.println("red");
    digitalWrite(LEDGREEN, LOW);
    digitalWrite(LEDRED, HIGH);
  }                   
  delay(50);                                    // Wait 50mS before next ranging
}
