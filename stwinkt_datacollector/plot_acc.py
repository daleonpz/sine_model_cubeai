#!/bin/python3


import re
import numpy as np
import matplotlib
matplotlib.use("TkAgg")
import matplotlib.pyplot as plt
import math
import serial

ser = serial.Serial('/dev/ttyACM0', 115200)
ser.flushInput()

# plot_window = 200
# x_var = np.array(np.zeros([plot_window]))
# y_var = np.array(np.zeros([plot_window]))
# z_var = np.array(np.zeros([plot_window]))

# plt.ion()
# fig, ax = plt.subplots()
# line, = ax.plot(y_var)


while True:
    with serial.Serial('/dev/ttyACM0', 115200, timeout=10) as ser:
            sensor_rawdata = ser.readline()  
            sensor_rawdata = sensor_rawdata.decode('utf-8')
            sensor_data = [float(s) for s in re.findall(r'-?\d+\.?\d*', sensor_rawdata)]
            x_data = sensor_data[0::3]
            y_data = sensor_data[1::3]
            z_data = sensor_data[2::3]
            # [ MES_0... MES_K] , und MES_i = x,y,z in diesem Fall 
            print(sensor_data)
            print(x_data)
            print(y_data)
            print(z_data)

# # Plot the data in each partition in different colors:
# plt.plot(x_train, y_train, 'b.', label="Train")
# plt.plot(x_test, y_test, 'r.', label="Test")
# plt.plot(x_val, y_val, 'y.', label="Validate")
# plt.legend()
# plt.show()



