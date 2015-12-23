volatile boolean TurnDetected;  // need volatile for Interrupts
volatile boolean up;
 
// L9110 connections
#define L9110_B_IA 3 // Pin D10 --> Motor B Input A
#define L9110_B_IB 5 // Pin D11 --> Motor B Input B
 
// Motor Speed & Direction
#define MOTOR_B_PWM 3 //L9110_B_IA // Motor PWM Speed
#define MOTOR_B_DIR 5 //L9110_B_IB // Motor Direction


/*
 Requirements: 
 - L9110S H Bridge
 - DC motor
 - Arduino Uno
 - 5V power suply
 
 Setup:
 (Arduino) Pin 3 -> (L9110) B-1A
 (Arduino) Pin 5 -> (L9110) B-1B
 (Power suply) +5V -> (L9110) VCC
 (Power suply) -5V -> (L9110) GND
 (L9110) B-0A -> dc motor
 (L9110) B-0B -> dc motor
 
*/
 
void setup ()  {
 Serial.begin (9600);
 Serial.println("Start");
 pinMode( MOTOR_B_DIR, OUTPUT );
 pinMode( MOTOR_B_PWM, OUTPUT );
 digitalWrite( MOTOR_B_DIR, LOW ); // Set motor to off
 digitalWrite( MOTOR_B_PWM, LOW );
}
 
void loop ()  {
 digitalWrite( MOTOR_B_DIR, HIGH );
 analogWrite( MOTOR_B_PWM, 180 );
 delay(4000);
 digitalWrite( MOTOR_B_DIR, LOW );
 analogWrite( MOTOR_B_PWM, 0 );
 delay(1000);
 digitalWrite( MOTOR_B_DIR, LOW );
 analogWrite( MOTOR_B_PWM, 60 );
 delay(4000);
 digitalWrite( MOTOR_B_DIR, LOW );
 analogWrite( MOTOR_B_PWM, 0 );
 delay(1000);
 
 }

