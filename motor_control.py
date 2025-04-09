# motor_control.py
import RPi.GPIO as GPIO
import time

# Motor Driver Pins (BCM Mode)
IN1 = 17  # Motor A
IN2 = 18  # Motor A
IN3 = 22  # Motor B
IN4 = 23  # Motor B
ENA = 24  # PWM for Motor A
ENB = 25  # PWM for Motor B

# GPIO setup
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup([IN1, IN2, IN3, IN4, ENA, ENB], GPIO.OUT)

# PWM setup
pwmA = GPIO.PWM(ENA, 1000)  # 1kHz PWM
pwmB = GPIO.PWM(ENB, 1000)
pwmA.start(80)  # 80% duty cycle = 80% speed
pwmB.start(80)

# Movement functions
def forward():
    GPIO.output(IN1, True)
    GPIO.output(IN2, False)
    GPIO.output(IN3, True)
    GPIO.output(IN4, False)

def backward():
    GPIO.output(IN1, False)
    GPIO.output(IN2, True)
    GPIO.output(IN3, False)
    GPIO.output(IN4, True)

def left():
    GPIO.output(IN1, False)
    GPIO.output(IN2, True)
    GPIO.output(IN3, True)
    GPIO.output(IN4, False)

def right():
    GPIO.output(IN1, True)
    GPIO.output(IN2, False)
    GPIO.output(IN3, False)
    GPIO.output(IN4, True)

def stop():
    GPIO.output(IN1, False)
    GPIO.output(IN2, False)
    GPIO.output(IN3, False)
    GPIO.output(IN4, False)

def cleanup():
    stop()
    pwmA.stop()
    pwmB.stop()
    GPIO.cleanup()

