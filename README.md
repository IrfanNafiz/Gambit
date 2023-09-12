# Gambit [Prototype]
A Prototype for a User Friendly Line Follower Robot and RC Car with Detachable Robotic Arm for Cleaning and 
Retrieval Purposes.

![image](https://github.com/IrfanNafiz/Gambit/assets/63298621/1d9551dd-4304-44ea-abd0-3baa70ebb5cf)
![garmbit arm](https://github.com/IrfanNafiz/Gambit/assets/63298621/bd38cb5f-46d6-4cd9-a5a4-24417c469cca)


## Team Name: Gamma (ϒ)

## Team Members:
Irfan Nafiz (EEE'19) ~ Team Lead \
Arnob Paul (EEE'19)\
Md Baktiar Alam Kabir (ME'19)\
Mirza Nihal Baig (CSE'18) ~ Team Mentor

## Achievement:
Runner-Up of RoboSUST Senior Project Hunt 2022

![image](https://github.com/IrfanNafiz/Gambit/assets/63298621/9e5e695d-2d92-4614-93c8-e0840409d080)

## Documentation:
### Overview:
Gambit is a multipurpose line follower robot, combined with wireless communication and a 2 degree of freedom robotic arm, capable of following a line with ease. Furthermore it has the capability of detecting objects in its way, which it can remove or hold with the arm according to given instructions.

It makes training an LFR simpler because of its user friendly BlueTooth to Phone/Laptop Serial Monitor data transfer, which allows live feedback of sensor data for quick and easy tuning.

### Purpose:
The main purpose of Gambit is to remove obstacles and carry it with the help of a robotic arm. 
Practically, it has the ability to conduct industrial work, cleaning roads and small object rescue operations from dangerous or hard to reach places.
Gambit was also a chance for us to hone our skills in creating an LFR, so we took the liberty to add as many features as we could to enhance our LFR.

### Parts List (with price): 
| No. | Name of Parts | Price |
| --- | --- | --- |
| 01 | Arduino Mega (1) | --- |
| 02 | IR Sensor Array (6) | --- |
| 03 | Ultrasonic Sonar Sensor (1) | --- |
| 04 | Servo (4) [3 high torque + *1 low torque] | --- |
| 05 | 5V Small DC motor (2) | --- |
| 06 | *Popsicle Sticks (~10) | --- |
| 07 | *PVC Board | --- | --- |
| 08 | Jumper Wire Bundle (x1) | --- |
| 09 | 7.4V Battery | --- | 
| 10 | Motor Driver | --- | 
| 11 | Wheels | --- |
| 12 | *BT Module | --- | 
| --- | Total | --- |
*NOTE*: Only the ones marked in '*' are taken extra for the Project Hunt

### Construction:
Gambit is divided into some major parts.
1.   LFR: The base part of this bot consists of a few smaller parts including pvc board, Arduino Mega, DC motor, wheels,  6 array IR sensors, Sonar Sensor, Motor driver etc. PVC board is used for the main casing where other parts have been placed. DC motors are connected with the motor driver by wire. Under the pvc board, wheels are attached with the dc motors. IR sensors are linked in front of the board where the sensors face the ground. A microcontroller Arduino mega is placed on top of the board to control the whole structure by giving commands.
2.   Robotic arm: The second main part of the bot is its arm which is made of a few servo motors and some sticks. All the motors are connected via jumper wires to the Arduino mega.

### Circuit Schematic:
*WORK IN PROGRESS*

### Code
Source code for Arduino Mega is included in the folder [src](/src/). 

### Future Goals and Improvements:
This prototype shows that it works as a line follower and obstacle remover and has some fundamental challenges moving forward, but is a plausible endeavor for future development. It can be used in different sectors. From natural disasters to industrial work, it can be used to move anything from one place to another. As all machines, it has some limitations too. In future, it should be able to identify details of the object using artificial intelligence and solve some more complex problems.
Some future goals are to make it a home assistant, where it will take instructions via BT from a phone and carry out relevant activities - Cleaning, RC Car, LFR, Scouting, or even just telling you the time, humidity, temperature or reading recent news headlines.

![gambit overall working](https://github.com/IrfanNafiz/Gambit/assets/63298621/a5d0f3ef-9653-4d72-b1c2-c7c25f3e6694)

