# Hack Hardware BU 2021

## Contents

* **Fire Mapper:** a solution to creating blueprints of buildings where visibility is an issue.

* **Overview:**
This project is something that I built as part of BU's hack Hardware hackathon.  I was given a small electronics kit and created a program that can map rooms with ultrasonic sensors.
Basically, the script sends out 3 ultrasonic pulses from two ultrasonic sensors that are 180 degrees apart. Then it takes the average of this number and sends it over serial to the python script.
Then the python takes the distance measurement and the angle converts it into Cartesian and plots a point cloud.
