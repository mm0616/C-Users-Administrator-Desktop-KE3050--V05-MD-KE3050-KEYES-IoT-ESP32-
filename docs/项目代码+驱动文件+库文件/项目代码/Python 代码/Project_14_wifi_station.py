# 作者 : www.keyes-robot.com

import time
import network #引入network模块

#请输入正确的路由器名称和密码
ssidRouter     = 'ChinaNet-2.4G-0DF0' #输入路由器名称
passwordRouter = 'ChinaNet@233' #输入路由器密码

def STA_Setup(ssidRouter,passwordRouter):
    print("Setup start")
    sta_if = network.WLAN(network.STA_IF) #设置ESP32为Station模式
    if not sta_if.isconnected():
        print('connecting to',ssidRouter)
#激活ESP32的工作站模式，向路由器发起连接请求并输入连接密码.
        sta_if.active(True)
        sta_if.connect(ssidRouter,passwordRouter)
#等待ESP32连接路由器，直到两台路由器连接成功.
        while not sta_if.isconnected():
            pass
#在“Shell”窗口中打印ESP32的IP地址.
    print('Connected, IP address:', sta_if.ifconfig())
    print("Setup End")

try:
    STA_Setup(ssidRouter,passwordRouter)
except:
    sta_if.disconnect()
