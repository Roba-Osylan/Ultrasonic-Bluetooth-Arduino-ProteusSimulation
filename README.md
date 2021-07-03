# Ultrasonic-Bluetooth-Arduino-ProteusSimulation
In the previous project (see https://github.com/Roba-Osylan/Controlling-6-ServoMotors-RestaurantRobot-sArm), the circuit that controls the movements of the robot's arms was designed. Through this project two components will be added to the circuit in order to make it more efficient. 

The first component that will be added is the Ultrasonic sensor. Ultrasonic sensors are used to measure distances using ultrasonic waves and they are consist of trigger pin, echo pin, power and ground pins. The simple operation of the ultrasonic sensor is that the trigger (or transmitter) transmits the ultrasonic wave, then the echo (or receiver) receives the reflected wave after it hits an object. While the wave is traveling between the transmitter and the receiver, the ultrasonic measure the traveling time and use this information to measure the distanse using the fact that distance= time x speed, where the speed of the ultrasonic sound in air is 340 m/s. The benefit of the ultrasonic sensor in this project is to make the robot able to detect whether a person is standing in front of it or not. 

The second component is the bluetooth module, which is used to connect between two object wirelessly to send or receive information. The benefit of the bluetooth module in the project is to open a video screen (will be replaced with a vertual terminal in this project) when the ultrasonic sensor detect a person.

This project is done using Proteus 8. See the following links to add the Ultrasonic and Bluetooth modules and libraries to Proteus library.
Ultrasonic sensor: https://www.youtube.com/watch?v=fYzhpPNpK18
Bluetooth Module: https://projectiot123.com/2019/03/25/bluetooth-module-simulation-in-proteus/
(see my previous repository to download the arduino library https://github.com/Roba-Osylan/Controlling-DC.Motors-L298-Arduino-Proteus).

# Circuit 

The circuit is shown in the figure below. The components used are: 
-Arduino Uno. 
-6x Servo Motors. 
-Ultrasonic Sensor.
-Bluetooth Module.
-Vertual Terminal.
-400 ohm potentiometer.
-LED (used to indicate whether the condition of the if statement in the program is satisfied or not since the vertual terminal will not work properly without a real bluetooth port). 
-340 ohm resistor.
-3x 5V battery, one for the Arduino, one for the ultrasonic sensor and the potentiometer and the other for the servo motors (4 used in the simulation for organization purpose).

![Restaurant Robot Circuit](https://user-images.githubusercontent.com/85955049/124361609-7b4f3580-dc38-11eb-90cc-36dc67c6265a.png)

Connection:
-The Servos are connected to digital pins 6, 5, 3, 9, 10, 11 of the Arduino.
-The trigger and echo pin of the Ultrasonic are connected to pins 12 and 8 repectively.
-The RX and TX of the Bluetooth module are conected to the TX and RX pins of the Arduino respectively. 
-The RX and TX of the vertual terminal are connected to the TX and RX of the bluetooth module respectively.
-The LED is connected to pin 13 of the Arduino. 

# Code
The program (ReataurantRobot) is written to program the circuit such that the robot interface starts when a person is 50 cm away from the robot. 
The picture below shows the **first part** of the program where the servo and software serial (vertual terminal) libraries are included. The first block is used to define the pins of the servos an then to create servo objects. The second block defines the pins of the trigger and echo pins as well as defining the variables duration and distance as float value. The last block is used to define the pins of the RX (receiver mode) and TX (transmitter mode) of the serial monitor.
![Screen Shot 1442-11-23 at 8 14 31 PM](https://user-images.githubusercontent.com/85955049/124363357-70e66900-dc43-11eb-944b-8313fab47192.png)

The picture below shows the **second part** of the program where the serial starts and the mode of the trigger, echo and the LED pins are defined as well as attaching the Servo objects with the defined servos pins.
![Screen Shot 1442-11-23 at 8 15 06 PM](https://user-images.githubusercontent.com/85955049/124363340-53b19a80-dc43-11eb-9c55-1939b028b3fc.png)

The **third part** of the program is shown in the following two pictures. Firstly, the trigger pin is set to low for to microseconds then a wave is generated for 3 seconds. After that, the pulseIn function measures the duration of the generated wave. Finally, the distance is calculated to set the conditions for the "if" statement. Note: the duration is divided by 2 to only concider the time of "receving" the wave (not the time of transmitting). 

The condition of the if statement is satisfied as long as the person is near the robot by less than or equal 2 cm and far by more than 50 cm, where the robot will not turned on. Otherwise, as soon as the distance becomes between 3-53 cm, the robot is turned on which means the video screen and the servos (robot's arm) are turned on. 
![Screen Shot 1442-11-23 at 8 19 41 PM](https://user-images.githubusercontent.com/85955049/124363288-033a3d00-dc43-11eb-99fb-f9b200c538a1.png)

![Screen Shot 1442-11-23 at 8 19 53 PM](https://user-images.githubusercontent.com/85955049/124363317-2c5acd80-dc43-11eb-9153-56477f75a512.png)

# Simulation Results
