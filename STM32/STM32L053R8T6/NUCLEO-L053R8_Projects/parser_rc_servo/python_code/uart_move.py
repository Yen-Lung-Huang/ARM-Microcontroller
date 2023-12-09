import curses
import serial
import json

# Initialize serial port
# ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=0.1) # for Ubuntu
ser = serial.Serial('COM12', 115200, timeout=0.1) # for Windows

# Initialize curses
screen = curses.initscr()
curses.noecho()
curses.cbreak()
screen.keypad(True)

# Define color pairs
curses.start_color()
curses.init_pair(1, curses.COLOR_RED, curses.COLOR_WHITE)
curses.init_pair(2, curses.COLOR_GREEN, curses.COLOR_BLACK)
curses.init_pair(3, curses.COLOR_MAGENTA, curses.COLOR_BLACK)
curses.init_pair(4, curses.COLOR_CYAN, curses.COLOR_BLACK)

# Define servo angles
servo_angles = [0, 0, 0, 0, 0]

# Define maximum number of messages to display
max_message_lines = 10

# Define function to send servo angles to STM32
def send_servo_angles():
    data = {"rc_servo": {}}
    for i in range(5):
        data["rc_servo"][str(i+1)] = servo_angles[i]
    json_data = json.dumps(data)
    ser.write(json_data.encode('utf-8'))
    screen.addstr(screen.getmaxyx()[0]-max_message_lines-1, 0, f"SENT: {json_data}", curses.color_pair(3))
    screen.refresh()

# Define function to display servo angles
def display_servo_angles():
    global screen, servo_angles
    screen.clear()
    screen.addstr(0, 0, "Use arrow keys to select servo, press +/- to change angle, press q to quit")
    for i in range(5):
        if i == selected_servo:
            screen.addstr(2+i, 0, f"Servo {i+1}: {servo_angles[i]}    ", curses.color_pair(1))
        else:
            screen.addstr(2+i, 0, f"Servo {i+1}: {servo_angles[i]}    ")
    screen.refresh()

# Define function to receive messages from STM32
def receive_messages():
    global screen
    while True:
        if ser.in_waiting > 0:
            message = ser.readline().decode('utf-8').rstrip()
            screen.addstr(screen.getmaxyx()[0]-max_message_lines, 0, f"RECEIVED: {message}\n", curses.color_pair(4))
            screen.refresh()

# Main loop
selected_servo = 0
display_servo_angles()
while True:
    c = screen.getch()
    if c == ord('q') or c == 27:
        break
    elif c == curses.KEY_DOWN:
        selected_servo = (selected_servo + 1) % 5
        display_servo_angles()
    elif c == curses.KEY_UP:
        selected_servo = (selected_servo - 1) % 5
        display_servo_angles()
    elif c == ord('+') or c == ord('='):
        servo_angles[selected_servo] = min(servo_angles[selected_servo]+5, 255)
        display_servo_angles()
        send_servo_angles()
    elif c == ord('-'):
        servo_angles[selected_servo] = max(servo_angles[selected_servo]-5, 0)
        display_servo_angles()
        send_servo_angles()

# Clean up
curses.nocbreak()
screen.keypad(False)
curses.echo()
curses.endwin()
ser.close