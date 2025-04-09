import motor_control.py as motor

motor.forward()
time.sleep(1)
motor.left()
time.sleep(0.5)
motor.stop()
motor.cleanup()

