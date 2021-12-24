#!/bin/python3


# import re
# import numpy as np
# import matplotlib
# matplotlib.use("TkAgg")
# import matplotlib.pyplot as plt
# import math
# import serial
# 
# ser = serial.Serial('/dev/ttyACM0', 115200)
# ser.flushInput()
# 
# plot_window = 200
# x_var = np.array(np.zeros([plot_window]))
# y_var = np.array(np.zeros([plot_window]))
# z_var = np.array(np.zeros([plot_window]))
# 
# plt.ion()
# fig, ax = plt.subplots()
# line, = ax.plot(y_var)
# 

# while True:
#     with serial.Serial('/dev/ttyACM0', 115200, timeout=10) as ser:
#         sensor_rawdata = ser.readline()  
#         sensor_rawdata = sensor_rawdata.decode('utf-8')
#         sensor_data = [float(s) for s in re.findall(r'-?\d+\.?\d*', sensor_rawdata)]
#         x_data = sensor_data[0::3]
#         y_data = sensor_data[1::3]
#         z_data = sensor_data[2::3]
#         # [ MES_0... MES_K] , und MES_i = x,y,z in diesem Fall 
#         print(sensor_data)
#         print(x_data)
#         print(y_data)
#         print(z_data)

# # Plot the data in each partition in different colors:
# plt.plot(x_train, y_train, 'b.', label="Train")
# plt.plot(x_test, y_test, 'r.', label="Test")
# plt.plot(x_val, y_val, 'y.', label="Validate")
# plt.legend()
# plt.show()


import serial
import numpy as np
from matplotlib import pyplot as plt
from threading import Thread,Event
import time
import re

#A simple ring buffer to keep the plotting data in
class RingBuffer(object):
    def __init__(self,size):
        self.size = size
        self._size = 2*size
        self._buffer = np.zeros(self._size)
        self._idx = 0

    def insert(self,val):
        idx = self._idx%self.size
        self._buffer[idx] = val
        self._buffer[idx+self.size] = val
        self._idx+=1
        if self._idx > self.size:
            self._idx-=self.size

    def get(self):
        start_idx = (self._idx)%self.size
        end_idx = start_idx+self.size
        return self._buffer[start_idx:end_idx]

#A thread to handle plotting and reading data from the serial port
class Plotter(Thread):
#     def __init__(self,stream,stop,pause):
    def __init__(self,stream):
        Thread.__init__(self)
        self.stream = stream
#         plt.ion()
#         plt.show()
#         self.fig = plt.figure()
#         self.ax = plt.axes()
#         self.size = 100
#         self.xdata = np.arange(self.size)
#         self.ydata = RingBuffer(self.size)
#         self.line, = self.ax.plot(self.ydata.get())
#         plt.ylim([24,29])                                                  
#         self.stop = stop
#         self.pause = pause

#The main loop of the thread, invoked with .start()
    def run(self):
#         while not self.stop.is_set():
#             if self.pause.is_set():
#                 continue
#             raw_data = self.stream.readline().rstrip()                     
        while True:
            raw_data = self.stream.readline().decode('utf-8')
#         sensor_rawdata = sensor_rawdata.decode('utf-8')
#         sensor_data = [float(s) for s in re.findall(r'-?\d+\.?\d*', sensor_rawdata)]
#         x_data = sensor_data[0::3]
#         y_data = sensor_data[1::3]
#         z_data = sensor_data[2::3]
#         # [ MES_0... MES_K] , und MES_i = x,y,z in diesem Fall 
#         print(sensor_data)
#         print(x_data)
#         print(y_data)
#         print(z_data)
#             if len(raw_data) <= 6:
            try:
#                     data = float(raw_data)
                data = [float(s) for s in re.findall(r'-?\d+\.?\d*', raw_data)]
                data = data[0::3]
                print(data)
            except ValueError:
                print ("Not a float")
#             else:
#                     if data <= 100:
#                 self.ydata.insert(data)
#                 self.line.set_xdata(self.xdata)
#                 self.line.set_ydata(self.ydata.get())
#                 plt.draw()

        #sleep statement to reduce processor load 
        time.sleep(1) 

#this is implemented to facilitate use through something like Ipython easily
class Controller(object):
    def __init__(self):
        #These events control execution of the thread main loop
#         self.stop = Event()
#         self.pause = Event()
        self.stream = serial.Serial('/dev/ttyACM0', 115200)
#         self.plotter_thread = Plotter(self.stream,self.stop,self.pause)
        self.plotter_thread = Plotter(self.stream)
        self.plotter_thread.start()

def main():
    con = Controller()
    #Loop over terminal input
    #possible commands are stop, pause and unpause
#     while True:
#         command = input("cmd >>>")
#         if command == "stop":
#             con.stop.set()
#             con.plotter_thread.join()
#             break
#         elif command == "pause":
#             con.pause.set()
#         elif command == "unpause":
#             con.pause.clear()
#         else:
#             print("unrecognised command")
# 
if __name__ == "__main__":
    main()
