import serial
import json
import curses
import threading

# Initialize serial port
# ser = serial.Serial('/dev/ttyACM0', 115200, timeout=0.1) # for Ubuntu
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
curses.init_pair(3, curses.COLOR_YELLOW, curses.COLOR_BLACK)

# Define servo angles
servo_angles = [0, 0, 0, 0, 0]

# Define maximum number of messages to display
max_message_lines = 10

# Define shared variable for received messages
received_message = ''

# Define function to send servo angles to STM32
def send_servo_angles():
    data = {"rc_servo": {}}
    for i in range(5):
        data["rc_servo"][str(i+1)] = servo_angles[i]
    json_data = json.dumps(data)
    ser.write(json_data.encode('utf-8'))

# Define function to display servo angles
def display_servo_angles():
    global screen, servo_angles, received_message
    screen.clear()
    screen.addstr(0, 0, "Use arrow keys to select servo, press +/- to change angle, press q to quit")
    for i in range(5):
        if i == selected_servo:
            screen.addstr(2+i, 0, f"Servo {i+1}: {servo_angles[i]}    ", curses.color_pair(1))
        else:
            screen.addstr(2+i, 0, f"Servo {i+1}: {servo_angles[i]}    ")
    screen.addstr(screen.getmaxyx()[0]-max_message_lines-1, 0, 'TX2 returned: ' + received_message, curses.color_pair(3))
    screen.refresh()

# Define function to receive messages from STM32
def receive_messages():
    global received_message
    while True:
        if ser.in_waiting > 0:
            message = ser.readline().decode('utf-8').rstrip()
            received_message = message

# Define function to send messages to TX2 and receive messages from TX2
def send_receive_messages():
    global screen, selected_servo, servo_angles, received_message

    # Initialize selected servo
    selected_servo = 0

    # Create thread to receive messages from STM32
    receive_thread = threading.Thread(target=receive_messages, daemon=True)
    receive_thread.start()

    # Main loop for sending and receiving messages
    while True:
        # Display servo angles
        display_servo_angles()

        # Wait for user input
        key = screen.getch()

        # Handle user input
        if key == curses.KEY_UP:
            selected_servo = (selected_servo - 1) % 5
        elif key == curses.KEY_DOWN:
            selected_servo = (selected_servo + 1) % 5
        elif key == ord('+'):
            servo_angles[selected_servo] += 1
            send_servo_angles()
        elif key == ord('-'):
            servo_angles[selected_servo] -= 1
            send_servo_angles()
        elif key == ord('q'):
            break

    # Cleanup curses and close serial port
    curses.nocbreak()
    screen.keypad(False)
    curses.echo()
    curses.endwin()
    ser.close()

# Call function to send and receive messages
send_receive_messages()

# Clean up curses
curses.nocbreak()
screen.keypad(False)
curses.echo()
curses.endwin()

# Close serial port
ser.close()