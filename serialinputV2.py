#!/usr/bin/python
import serial
import os

s = s = serial.Serial('/dev/tty.usbmodem411', 9600)

while True:
	pp = s.read()
	if pp > "A":
		os.system('''osascript -e 'tell application "iTunes" to playpause' ''')
s.close()

