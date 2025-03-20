# 作者 : www.keyes-robot.com

#导入Pin, neopiexl和time模块.
from machine import Pin
import neopixel
import time

#定义连接到新像素的引脚和led的数量.
pin = Pin(26, Pin.OUT)
np = neopixel.NeoPixel(pin, 4) 

#亮度:0 - 255
brightness=100                                
colors=[[brightness,0,0],                    #红
        [0,brightness,0],                    #绿
        [0,0,brightness],                    #蓝
        [brightness,brightness,brightness],  #白
        [0,0,0]]                             #关闭

#嵌套两个for循环，使模块重复显示红、绿、蓝、白和OFF五种状态。    
while True:
    for i in range(0,5):
        for j in range(0,4):
            np[j]=colors[i]
            np.write()
            time.sleep_ms(50)
        time.sleep_ms(500)
    time.sleep_ms(500)
