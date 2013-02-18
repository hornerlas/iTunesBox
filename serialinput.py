#!/usr/bin/python
import serial
import os

s = s = serial.Serial('/dev/tty.usbmodem411', 9600)

while True:
	s.read()
	os.system('''osascript -e 'tell application "iTunes" to playpause' ''')
s.close()

