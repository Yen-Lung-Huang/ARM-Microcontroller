import curses
import serial
import json

# Initialize serial port
# ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=0.1) # for Ubuntu
ser = serial.Serial('COM12', 115200, timeout=0.1) # for Windows

def send_message(message):
    json_data = json.dumps(message)
    ser.write(json_data.encode('utf-8'))

# Initialize curses
screen = curses.initscr()
curses.cbreak()
screen.keypad(True)

# Main loop
try:
    while True:
        char = screen.getch()
        if char == curses.KEY_UP:
            send_message({"move": "forward"})
        elif char == curses.KEY_DOWN:
            send_message({"move": "backward"})
        elif char == curses.KEY_LEFT:
            send_message({"move": "turn_left"})
        elif char == curses.KEY_RIGHT:
            send_message({"move": "turn_right"})
finally:
    # Clean up curses
    curses.nocbreak()
    screen.keypad(False)
    curses.echo()
    curses.endwin()
    # Close serial port
    ser.close()
