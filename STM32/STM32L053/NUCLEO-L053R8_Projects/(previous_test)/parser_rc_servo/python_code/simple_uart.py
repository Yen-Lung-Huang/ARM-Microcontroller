import serial
import json

# Initialize serial port
# ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=0.1) # for Ubuntu
ser = serial.Serial('COM12', 115200, timeout=0.1) # for Windows

# Define function to receive messages from STM32
def receive_messages():
    global screen
    while True:
        if ser.in_waiting > 0:
            message = ser.readline().decode('utf-8').rstrip()
            print("RECEIVED: " + message)

# Main loop
while True:
    data = input("SENT: ")
    json_data = json.dumps(data)
    ser.write(json_data.encode('utf-8'))
    receive_messages()
