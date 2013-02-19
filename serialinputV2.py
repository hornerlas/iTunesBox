#!/usr/bin/python
import serial
import os

s = serial.Serial('/dev/tty.usbmodem411', 9600)

while 1:
	val = s.read()
	if val == "A"
		os.system('''osascript -e 'tell application "iTunes" to playpause' ''')
	else:
		os.system('''osascript -e 'set sound volume to (sound volume - 25)' ''')
s.close()


