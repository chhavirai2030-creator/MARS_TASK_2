/*
  Arduino UNO Bluetooth Motor Control
  Components:
    - Arduino UNO
    - HC-05 Bluetooth Module (RX to pin 10, TX to pin 11)
    - L298N Motor Driver
    - 2 DC Motors (Left & Right)
  Commands from Bluetooth:
    'F' = Forward
    'B' = Backward
    'L' = Left
    'R' = Right
    'S' = Stop
*/

#include <SoftwareSerial.h>

// Bluetooth module pins
SoftwareSerial BT(10, 11); // RX, TX

// L298N Motor Driver pins
#define ENA 5   // Enable pin for Motor A (PWM)
#define IN1 9
#define IN2 10
#define ENB 6   // Enable pin for Motor B (PWM)
#define IN3 11
#define IN4 3

// Motor speed (0-255)
int motorSpeed = 180;

void setup() {
  // Motor pins as output
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Start serial communication
  Serial.begin(9600);  // For debugging
  BT.begin(9600);      // HC-05 default baud rate

  Serial.println("Bluetooth Motor Control Ready");
}

void loop() {
  if (BT.available()) {
    char command = BT.read();
    Serial.print("Command: ");
    Serial.println(command);

    switch (command) {
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      case 'S': stopMotors(); break;
      default: Serial.println("Invalid Command"); break;
    }
  }
}

// Motor control functions
void forward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
