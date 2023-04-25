# %%


# %%
import serial
import matplotlib.pyplot as plt
import numpy as np
from drawnow import *
import codecs
import re

def appendLiveFeed(str):
    paramArray = str.split(";")
    paramArray = ([x for x in paramArray if len(x) > 0])
    paramArray.remove('\n')
    values = []
    # print(str)
    for i in paramArray:
        arr = i.split("=")
        # print(int(arr[1]))
        values.append(int(arr[1]))

    return values
# %%
data = []
exp = "MQ4-1 =.*;MQ4-2 =.*;MQ4-3 =.*;MQ7-1 =.*;MQ7-2 =.*;MQ7-3 =.*;$"

fig = plt.figure()

def plotData():
    plt.title('Real-time data plot')
    plt.grid(True)
    plt.ylabel('Analog values')
    # plt.plot(data, '-ro')
    

    plt.subplot(2, 2, 1)
    plt.plot(data, '-ro')

    # plt.subplot(2, 2, 2)
    # plt.plot(x, y)

# %%
arduinoData = serial.Serial('/dev/ttyACM0', 9600)
counter = 0

while True:
    value = []
    while (arduinoData.inWaiting()==0):
        pass
    arduinoString = arduinoData.readline()
    arduinoString = codecs.decode(arduinoString)
    # arduinoString = ";MQ4-2 =347;MQ4-3 =394;MQ7-1 =167;MQ7-2 =173;MQ7-3 =229;"
    exist = re.search(exp, arduinoString)
    if exist:
        print(arduinoString)
        # appendLiveFeed(arduinoString)
        value = appendLiveFeed(arduinoString)
        # print(value)
        # print(value)
        data.append(float(value[0]))
        drawnow(plotData)
    else:
        print("error")
        continue
    