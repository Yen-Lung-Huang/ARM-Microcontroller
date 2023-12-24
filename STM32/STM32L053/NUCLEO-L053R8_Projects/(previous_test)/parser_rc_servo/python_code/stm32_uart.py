import curses
import serial
import json
import threading

# Initialize serial port
# ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=0.1) # for Ubuntu
ser = serial.Serial('COM12', 115200, timeout=0.1) # for Windows

# Initialize curses
screen = curses.initscr()
curses.noecho()
curses.cbreak()
screen.keypad(True)

# Define function to receive messages from STM32
def receive_messages():
    global screen
    while True:
        if ser.in_waiting > 0:
            message = ser.readline().decode('utf-8').rstrip()
            screen.addstr(f"RECEIVED: {message}\n")
            screen.refresh()

# Define function to send messages to STM32
def send_messages():
    global screen
    while True:
        data = input("SENT: ")
        json_data = json.dumps(data)
        ser.write(json_data.encode('utf-8'))
        screen.addstr(f"SENT: {data}\n")
        screen.refresh()

# Start receive thread
receive_thread = threading.Thread(target=receive_messages)
receive_thread.start()

# Start send thread
send_thread = threading.Thread(target=send_messages)
send_thread.start()

# Wait for threads to finish
receive_thread.join()
send_thread.join()

# Clean up
curses.nocbreak()
screen.keypad(False)
curses.echo()
curses.endwin()
ser.close()
