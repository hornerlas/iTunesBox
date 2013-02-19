#!/usr/bin/python
import serial
import os

s = serial.Serial('/dev/tty.usbmodem411', 9600)

while 1:
	val = s.read()
	if val == "A"
		os.system('''osascript -e 'tell application "iTunes" to playpause' ''')
	else:
		('Something else')
s.close()


