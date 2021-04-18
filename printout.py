#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Apr 18 02:59:45 2021

@author: whorehay
"""
import serial 
import time
import numpy as np 
import matplotlib.pyplot as plt

#Serial takes two parameters: serial device and baudrate

ser = serial.Serial('/dev/ttyACM2', 9600, timeout=2)

angle = 0
distance = 0
read_line = ser.readline().decode("utf-8")
Polarpoints =[]
CartPoints = []
for i in range(9):
    read_line = ser.readline().decode("utf-8")
    codes = read_line.split(";")
    try:
        angle1 = int(codes[0])
        distance1 = int(codes[1])
        angle2 = int(codes[2])
        distance2 = int(codes[3])
    except:
        angle1 = 0
        distance1 = 0
        angle2 =0
        distance2 = 0
    
    
    
    point = (distance1,angle1)
    Polarpoints.append(point)
    point = (distance2,angle2)
    Polarpoints.append(point)
    
    point = (distance1*np.cos(angle1*3.14/180),distance1*np.sin(angle1*3.14/180))
    CartPoints.append(point)
    point = (distance2*np.cos(angle2*3.14/180),distance2*np.sin(angle2*3.14/180))
    CartPoints.append(point)
    time.sleep(2.2)
X = np.array(Polarpoints)
checks = X[:,0]
thresh = 60
Y = np.array(CartPoints)
ind1 = checks>thresh
ind2 = checks<thresh
x = Y[ind1]
x1 = Y[ind2]
plt.scatter(x[:,0],x[:,1],color = "blue")
plt.scatter(x1[:,0],x1[:,1],color = "red")
print(Y)

        