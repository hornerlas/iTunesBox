#!/usr/bin/python
import serial
import os

s = serial.Serial('/dev/tty.usbmodem411', 9600)

while 1:
	s.read()
	os.system('''osascript -e 'tell application "iTunes" to playpause' ''')
s.close()


