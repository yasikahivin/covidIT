
import numpy as np
#import serial
from serial import Serial
import time
import sys
import cv2
import serial

#Setup Communication path for arduino
arduino = serial.Serial('COM4', 9600)
time.sleep(2)
print("Connection to arduino...")


face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

cap = cv2.VideoCapture(0)

#Read the image, convert it to Gray image and find faces
while 1:
    ret, img = cap.read()
    cv2.resizeWindow('img', 500,500)
    cv2.line(img,(500,250),(0,250),(0,255,0),1)
    cv2.line(img,(250,0),(250,500),(0,255,0),1)
    cv2.circle(img, (250, 250), 5, (255, 255, 255), -1)
    gray  = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, 1.3)

    for (x,y,w,h) in faces:
        cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),5)
        roi_gray  = gray[y:y+h, x:x+w]
        roi_color = img[y:y+h, x:x+w]

        arr = {y:y+h, x:x+w}
        print (arr)
        
        print ('X :' +str(x))
        print ('Y :'+str(y))
        print ('x+w :' +str(x+w))
        print ('y+h :' +str(y+h))

        xx = int(x+(x+h))/2
        yy = int(y+(y+w))/2

        print (xx)
        print (yy)

        center = (xx,yy)

        xxx=int(xx)
        yyy=int(yy)

        # sending data to arduino
        print("Center of Rectangle is :", center)
        data = "X{0:d}Y{1:d}Z".format(xxx, yyy)
        print ("output = '" +data+ "'")
        #arduino.write(data)
    

    cv2.imshow('CovidIT',img)
   
   # Esc to terminate
    k = cv2.waitKey(30) & 0xff
    if k == 27:
        break
