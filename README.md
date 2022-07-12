# Gambit
A User Friendly Line Follower Robot and RC Car with Detachable Robotic Arm for Cleaning and 
Retrieval Purposes.
 
## Team Name: Gamma (ϒ)

## Team Members:
Irfan Nafiz (EEE'19)\
Arnob Paul (EEE'19)\
Md Baktiar Alam Kabir (EEE'19)

## Overview:
Gambit is a multipurpose line follower robot, combined with wireless communication and a 2 degree of freedom robotic arm, capable of following a line with ease. Furthermore it has the capability of detecting objects in its way, which it can remove or hold with the arm according to given instructions.

It makes training an LFR simpler because of its user friendly BlueTooth to Phone/Laptop Serial Monitor data transfer, which allows live feedback of sensor data for quick and easy tuning.

## Purpose:
The main purpose of Gambit is to remove obstacles and carry it with the help of a robotic arm. 
Practically, it has the ability to conduct industrial work, cleaning roads and small object rescue operations from dangerous or hard to reach places.
Gambit was also a chance for us to hone our skills in creating an LFR, so we took the liberty to add as many features as we could to enhance our LFR.

| Parts List (with price) | Number of parts | Name of parts | Price |
| --- | --- | --- | --- |
| 01 | Arduino Mega (1) | --- | --- |
| 02 | IR Sensor Array (6) | --- | --- |
| 03 | Ultrasonic Sonar Sensor (1) | --- | --- |
| 04 | Servo (4) [3 high torque + *1 low torque] | --- | --- |
| 05 | 5V Small DC motor (2) | --- | --- |
| 06 | *Popsicle Sticks (~10) | --- | --- |
| 07 | *PVC Board | --- | --- |
| 08 | Jumper Wire Bundle (x1) | --- | --- |
| 09 | 7.4V Battery | --- | --- |
| 10 | Motor Driver | --- | --- |
| 11 | Wheels | --- | --- |
| 12 | *BT Module | --- | --- |
| --- | Total | --- |
 

*NOTE: Only the ones marked in '*' are taken extra for the Project Hunt\
## Construction:
Gambit is divided into two major parts.
1.   LFR: The base part of this bot consists of a few smaller parts including pvc board, Arduino Mega, DC motor, wheels,  6 array IR sensors, Sonar Sensor, Motor driver etc. PVC board is used for the main casing where other parts have been placed. DC motors are connected with the motor driver by wire. Under the pvc board, wheels are attached with the dc motors. IR sensors are linked in front of the board where the sensors face the ground. A microcontroller Arduino mega is placed on top of the board to control the whole structure by giving commands.
 
2.   Robotic arm: The second main part of the bot is its arm which is made of a few servo motors and some sticks. All the motors are connected via jumper wires to the Arduino mega.
Procedure:
1.   Arduino Mega, brain of Gambit, provides the required instructions to the whole bot.
2.   Battery, being heart of the bot, supplies power to the whole system.
3.   IR sensor is used mainly for tracking line by detecting colors of light. These sensors send the information to Arduino. Gambit gets the information to track the line properly.
4.   Getting the command from Arduino, Motor driver distributes voltage to the dc motors which eventually makes the wheels rotate.
5.   Robotic arm is used for capturing objects and placing it to the side. The mechanical part of the arm works by the servo motors where it is instructed by the Arduino via inverse kinematics.
 

## Future Goals and Improvements:
The prototype shows that it works as a line follower and obstacle remover. It can be used in different sectors. From natural disasters to industrial work, it can be used to move anything from one place to another. As all machines, it has some limitations too. In future, it should be able to identify details of the object using artificial intelligence and solve some more complex problems.
Some future goals are to make it a home assistant, where it will take instructions via BT from a phone and carry out relevant activities - Cleaning, RC Car, LFR, Scouting, or even just telling you the time, humidity, temperature or reading recent news headlines.
