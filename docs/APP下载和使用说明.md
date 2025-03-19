# APP下载和使用说明

## （1）安卓系统手机蓝牙APP（国内）：

下载链接：![](media/f1ebec09a6a924e66654e11bbf3e8827.png)<https://xiazai.keyesrobot.cn/APP/keyes%20IoT%20home.apk> ，下载完后，使用数据线转移到手机上去安装。



二维码下载（用手机浏览器上的扫描功能）：![](media/049a27bbb2e7410c404f8a03aa9f0eef.png)

下载安装后打开![](media/7ec5f89710521709c29fbe26f6e2ddb9.jpeg)，出现如下图界面。

![](media/fcb1414758ce8d42810f3e0c22e0d8fb.png)

![](media/8e7c339852876017b41a39d5a0b31323.png)

上传测试代码成功，上电后

1. 打开APP，选择WIFI

![](media/d1cf201be878301328acdb765b4ec3b1.png)

2. APP控制LED和风扇

手机需要和智能家居连接同一个WiFi，或者手机打开热点，智能家居连接手机的热点。

A. APP输入IP地址（LCD1602显示出分配到的IP地址）

B. 点击连接

C. 连接成功标志是显示区域显示ESP32 ip: 192.168.0.171

D. 然后就可以点击LED，可以看到智能家居的LED被打开

E. 点击Fan按钮，风扇被打开。如下图操作。

![](media/426c73480e4513751bf99667b3ea7e58.png)  

![](media/ffdb33832de6eefc32545d6ef4e49128.png)

## （2）苹果系统手机（平板电脑）APP：

打开 App Store。

![](media/eeccf6fd30106842b44464a3dc598f0c.png)

在 APP Store 上搜索 **keyes IoT home** ，点击获取，下载安装APP即可。

手机APP上各个按钮对应的控制字符和各个按钮对应的功能，这里我们整理了一个表格如下：

（<span style="color: rgb(255, 76, 65);">注意：</span>功能的实现需要上传第15课手机APP控制智能家居的程序）


|按钮:![](media/db273e84e03ad5f0fd80c96fbd0d8df5.png)|功能：选择WIFI模式||
|-|-|-|
|按钮:![](media/26cffb5adfc9219ef70e870aedb103d9.png)|功能：连接||
|按钮:![](media/e4485d32e33d2d479b6547c48e219987.png)|控制字符：点一下发送 “/led/on”； 再点一下发送“/led/off”。|功能：点一下，开启LED灯；再点一下，关闭LED灯。|
|按钮:![](media/bb5ec8ab3502d0c0ba2a4a486196bfbd.png)|控制字符：点一下发送 “/window/on”； 再点一下发送“/window/off”。|功能：点一下，开启窗户； 再点一下，关闭窗户。|
|按钮:![](media/62def1a4051fdc1bf34e61a04a7059da.png)|控制字符：点一下发送 “/music/on”。|功能：点一下，播放一首歌曲。|
|按钮:![](media/444d1fafe5f9b8944765144fbd5a0f12.png)|控制字符：点一下发送 “/buz/on”。|功能：点一下，蜂鸣器“哔”响一声。|
|按钮:![](media/5e489d6a591dbfa2dc085df4ee4b9e50.png)|控制字符：点一下发送 “/door/on”； 再点一下发送“/door/off”。|功能：点一下，开启门； 再点一下，关闭门。|
|按钮:![](media/b9bbc1adcfc17eab7a43867b2ccfe5af.png)|控制字符：点一下发送 “/fan/on”； 再点一下发送“/fan/off”。|功能：点一下，开启风扇； 再点一下，关闭风扇。|
|按钮:![](media/8d1864ce4b02bc1435b9d5f3c963f003.png)|控制字符：点一下发送 “/rain/on”； 再点一下发送“/rain/off”。|功能：点一下，显示区显示雨滴值；再点一下，显示区显示off。|
|按钮:![](media/1bf11cdaf889d8962ea00a55719fe3b4.png)|控制字符：点一下发送 “/gas/on”； 再点一下发送“/gas/off”。|功能：点一下，显示区显示危险气体状态safety或dangerous；再点一下，显示区显示off。|
|按钮:![](media/23ca9a4b18e3c7830c724b6e60f44e97.png)|控制字符：点一下发送 “/body/on”； 再点一下发送“/body/off”。|功能：点一下，显示区显示人体检测状态someone或no one；再点一下，显示区显示off。|
|按钮:![](media/ed6610e8c0b1bfbcc09a031928b696a7.png)|控制字符：点一下发送 “/temp/on”； 再点一下发送“/temp/off”。|功能：点一下，显示区显示温度数值；再点一下，显示区显示off。|
|按钮:![](media/9d73f8b84fd4921ffe2c6db36ee2e165.png)|控制字符：点一下发送 “/humidity/on”； 再点一下发送“/humidity/off”。|功能：点一下，显示区显示湿度数值；再点一下，显示区显示off。|
|按钮:![](media/fe27b6c64651eb180e9ee2a88bdf692b.png)|控制字符：点一下发送 “/sfx1/on”； 再点一下发送“sfx1/off”。|功能：点一下，RGB灯开启模式一氛围灯；再点一下，关闭RGB灯。|
|按钮:![](media/dfa0129c15a1af7746d954173fecb1a6.png)|控制字符：点一下发送 “/sfx2/on”； 再点一下发送“sfx2/off”。|功能：点一下，RGB灯开启模式二跑马灯；再点一下，关闭RGB灯。|
|按钮:![](media/b69863822fc8e54f53a866490e1913e1.png)|控制字符：点一下发送 “/red/on”； 再点一下发送“/red/off”。以此类推。|功能：点一下，RGB灯开启红色；再点一下，关闭RGB灯。以此类推。|






