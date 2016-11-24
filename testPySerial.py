__author__ = 'unknown'
import serial
from time import sleep

def chksum_string(mystring):
    csum = 0
    for c in mystring:
       csum ^= ord(c)
    return csum

def sendMessage(send_message):
    print "Sending Message: " + send_message
    checksum = chksum_string(send_message)
    print "Checksum: " + str(checksum)
    ser.write(send_message + ',' + str(checksum) + '\n')
    ser.flush()

ser = serial.Serial('/dev/ttyACM0','9600', timeout=1)


sendMessage('This is a test!')
sleep(0.5)
received = ser.readline()
while not "Checksum MATCH!" in received:
    sleep(0.5)
    received = ser.readline()
    print('Received: ' + received)
    print('Resending Message')
    sendMessage('This is a test!')
print('Message sent successfully')



