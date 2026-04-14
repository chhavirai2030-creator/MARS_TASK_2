# MARS_TASK_2
This project enables wireless control of a two-wheel robotic car using an Arduino UNO, an HC-05 Bluetooth module, and an L298N motor driver. Commands are sent from a smartphone via Bluetooth to control the movement of the robot.
📌 Features


Wireless motor control using Bluetooth


Supports forward, backward, left, right, and stop movements


Adjustable motor speed using PWM


Serial Monitor support for debugging



🧰 Components Required
ComponentQuantityArduino UNO1HC-05 Bluetooth Module1L298N Motor Driver1DC Motors2Robot Chassis with Wheels1Battery Pack (7–12V)1Jumper WiresAs requiredSmartphone with Bluetooth Terminal App1

🔌 Circuit Connections
HC-05 Bluetooth Module
HC-05 PinArduino UNO PinVCC5VGNDGNDTXDPin 10 (RX)RXDPin 11 (TX) (use a voltage divider if required)
L298N Motor Driver
L298N PinArduino UNO PinENAPin 5 (PWM)IN1Pin 9IN2Pin 10ENBPin 6 (PWM)IN3Pin 11IN4Pin 3OUT1 & OUT2Left MotorOUT3 & OUT4Right Motor12VBattery PositiveGNDBattery Ground & Arduino GND
⚠️ Note: Ensure all grounds are connected together.

⚠️ Important Pin Conflict
Pins 10 and 11 are used by both the HC-05 and the motor driver in the code. This will cause a conflict. Modify the motor pins as shown below:
#define ENA 5#define IN1 7#define IN2 8#define ENB 6#define IN3 9#define IN4 4
Update your wiring accordingly.

📱 Bluetooth Control Commands
CommandActionFMove ForwardBMove BackwardLTurn LeftRTurn RightSStop
You can use apps such as:


Serial Bluetooth Terminal


Bluetooth Terminal HC-05


Arduino Bluetooth Controller



💻 Installation & Setup


Install the Arduino IDE.


Connect the Arduino UNO to your computer via USB.


Copy and paste the provided code into the Arduino IDE.


Select:


Board: Arduino UNO


Port: Appropriate COM Port




Upload the code to the Arduino.


Power the motor driver using an external battery.


Pair the HC-05 with your smartphone:


Default Password: 1234 or 0000




Open a Bluetooth terminal app and send commands.



▶️ How It Works


The HC-05 receives commands from the smartphone via Bluetooth.


The Arduino reads the incoming data using SoftwareSerial.


Based on the received character, the Arduino controls the L298N motor driver.


PWM signals regulate motor speed for smooth motion.



📂 Project Structure
Arduino-Bluetooth-Motor-Control/│── Arduino_Bluetooth_Motor_Control.ino│── README.md

🧪 Sample Serial Monitor Output
Bluetooth Motor Control ReadyCommand: FCommand: LCommand: RCommand: S

🚀 Future Improvements


Add speed control using additional commands.


Integrate obstacle detection using ultrasonic sensors.


Include MPU6050 for gesture-based control.


Develop a custom mobile app.


Implement line-following capabilities.



🐞 Troubleshooting
IssueSolutionBluetooth not connectingCheck wiring and pairing passwordMotors not runningVerify battery power and connectionsErratic movementEnsure proper groundingUpload errorsDisconnect HC-05 RX/TX during uploadSlow responseConfirm baud rate is set to 9600

📜 License
This project is open-source and free to use for educational and personal purposes.

👩‍💻 Author
Chhavi Rai
Dual Degree in Electronics and Communication
IIIT Kancheepuram
