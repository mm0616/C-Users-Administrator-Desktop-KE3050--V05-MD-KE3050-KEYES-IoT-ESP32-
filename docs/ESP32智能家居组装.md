# ESP32智能家居组装步骤


<span style="color: rgb(255, 76, 65);">注意：</span>这个套件的亚克力板使用时需要先撕去上面的保护膜。

![](media/efad109ebb91c45ea26c5f053e4de03d.png)

**安装1**

安装所需零件

![](media/914c2504e5117a823623a093f4a95d89.png)

安装

![](media/57c729f635a13c76c2db4ada3d24a0fe.jpg)

完成

![](media/170c616c9189b8733759206d866beb7d.jpg)

**安装2**

安装所需零件

![](media/e030cdaf6ae5d92d9a499ba1b3f05a8e.png)

安装

![](media/ba7aa4ff49474ecab963e4ce958213b4.png)

完成

![](media/afe345abfe706015806768aba3c0a80d.jpg)

**安装3**

安装所需零件

![](media/058fdce7eeadc497f2e9233bb592e563.png)

安装（注意电池盒线材朝下安装）

![](media/76a0e453a2bb47075066471534e5e475.jpg)

完成

![](media/bff1c4c50a8798708795d16d4068ac60.jpg)

**安装4**

安装所需零件

![](media/fc08ad51c8e2dbf4870c984a2a4cec11.png)

安装

![](media/585389f33b61a83dc34a9310637ed44b.png)

完成

![](media/ebff5959a6f9acebedb5da06a8d282dd.png)

**安装5**

安装所需零件

![](media/08027805420edea8cab7b8a309258011.png)

安装

![](media/4be9e79bfc2b10ed7a4255e6ee09cfac.png)

完成

![](media/eed5924a1d2e6a0703dd2464aabb45ee.png)

**安装6**

安装所需零件

![](media/a1a03ba698895f7fb9cf354c8f693d5b.png)

安装（<span style="color: rgb(255, 76, 65);">注意自锁螺母不可拧紧</span>）

![](media/69927ad8a11b45d7fcae9dee8e55d5b8.png)

完成

![](media/0b8cd00433a9a0f7ac70d3880f39e543.png)

**安装7**

安装所需零件

![](media/99_1.png)

<span style="color: rgb(255, 76, 65);">安装前需要调节舵机角度，我们需要将窗户的舵机调整到0度再安装</span>

|    舵机    |     主板     |
| :---------: | :---------: |
| 棕线  |      G      |
|  红线   |     V      |
| 橙黄线 | IO5 |

![Img](./media/img-20250220082715.png)


**方法一：Arduino 代码**

<span style="color: rgb(255, 76, 65);">**⚠️特别提示:** </span> 在编写代码并上传之前，必须安装Arduino IDE，请进入链接：[关于Arduino IDE](https://www.keyesrobot.cn/projects/KE3050/zh-cn/latest/docs/Arduino%20%E6%95%99%E7%A8%8B/Arduino%20%E6%95%99%E7%A8%8B.html#arduino-ide)

```c++
#include <ESP32_Servo.h>
Servo myservo;
#define servoPin 5

void setup() {
  myservo.attach(servoPin,500,2500);
  myservo.write(0);
  delay(300);
  myservo.write(90);
  delay(300);
  myservo.write(0);
  delay(300);
}

void loop() {
  // put your main code here, to run repeatedly:
}

```
如何得到它？

资料提供了调整窗户舵机的代码，请打开并烧录到主板，如下图所示。在文件夹 **..\项目代码+驱动文件+库文件\项目代码\窗户上的舵机初始化角度_代码** ，打开文件**window_servo.ino**。或将上述测试代码复制粘贴到Arduino IDE中。

![Img](./media/img-20250220084308.png)

将上述测试代码上传至主板之后，未发现舵机转动，可以按下主板上的复位键。

**方法二：Python 代码**

<span style="color: rgb(255, 76, 65);">**⚠️特别提示:** </span> 在编写代码并上传之前，必须安装 Thonny IDE，请进入链接：[关于Thonny IDE](https://www.keyesrobot.cn/projects/KE3050/zh-cn/latest/docs/Python%20%E6%95%99%E7%A8%8B/Python%20%E6%95%99%E7%A8%8B.html#thonny-ide)

```python
# 作者 : www.keyes-robot.com

from machine import Pin, PWM
import time
pwm = PWM(Pin(5))  
pwm.freq(50)

'''
与角度对应的占空比 
0°----2.5%----25
45°----5%----51.2
90°----7.5%----77
135°----10%----102.4
180°----12.5%----128
'''
angle_0 = 25
angle_90 = 77
angle_180 = 128

pwm.duty(angle_0)
time.sleep(1)
pwm.duty(angle_90)
time.sleep(1)
pwm.duty(angle_0)
time.sleep(1)

# while True:
```
如何得到它？

资料提供了调整窗户舵机的代码，请打开并烧录到主板，如下图所示。在文件夹 **..\项目代码+驱动文件+库文件\项目代码\窗户上的舵机初始化角度_代码** ，打开文件**window_servo.py**。或将上述测试代码复制粘贴到Thonny IDE中。

![Img](./media/img-20250220090138.png)

单击![Img](./media/img-20250220090039.png)运行上述测试代码，未发现舵机转动，可以按下主板上的复位键。

**方法三：Mixly 代码**

<span style="color: rgb(255, 76, 65);">**⚠️特别提示:** </span> 在编写代码并上传之前，必须安装 Mixly IDE，请进入链接：[关于Mixly IDE](https://www.keyesrobot.cn/projects/KE3050/zh-cn/latest/docs/Mixly%20%E6%95%99%E7%A8%8B/Mixly%20%E6%95%99%E7%A8%8B.html#mixly-ide)

![Img](./media/img-20250220091002.png)

如何得到它？

资料提供了调整窗户舵机的代码，请打开并烧录到主板，如下图所示。在文件夹 **..\项目代码+驱动文件+库文件\项目代码\窗户上的舵机初始化角度_代码** ，使用 Mixly IDE 打开文件**window_servo.mix**。或在Mixly IDE中直接拖动代码块编写上述测试代码。

![Img](./media/img-20250220091427.png)

单击![Img](./media/img-20250220090039.png)运行上述测试代码，未发现舵机转动，可以按下主板上的复位键。

**方法四：KidsBlock(Scratch) 代码**

<span style="color: rgb(255, 76, 65);">**⚠️特别提示:** </span> 在编写代码并上传之前，必须安装 KidsBlock IDE，请进入链接：[关于KidsBlock IDE](https://www.keyesrobot.cn/projects/KE3050/zh-cn/latest/docs/Scratch%20%E6%95%99%E7%A8%8B/Scratch%20%E6%95%99%E7%A8%8B.html#kidsblock-ide)

![Img](./media/img-20250220091934.png)

如何得到它？

资料提供了调整窗户舵机的代码，请打开并烧录到主板，如下图所示。在文件夹 **..\项目代码+驱动文件+库文件\项目代码\窗户上的舵机初始化角度_代码** ，使用 KidsBlock IDE 打开文件**window_servo.sb3**。或在KidsBlock IDE中直接拖动代码块编写上述测试代码。

![Img](./media/img-20250220092048.png)

单击![Img](./media/img-20250220090039.png)运行上述测试代码，未发现舵机转动，可以按下主板上的复位键。



安装（需按照下图姿态安装）

![](media/99_2.png)

<span style="background: rgb(255, 251, 0);">若使用为M1.4*6MM自攻螺丝时，如下图</span>

![](media/100.png)

完成

![](media/99_3.png)

**安装8**

安装所需零件

![](media/f73c6542689eca857be51d76f8e0d680.png)

安装

![](media/9a897c0cde9723d3cae2f719d3860717.png)

完成

![](media/65621fdc9bb050c47cd002109ae09946.png)

**安装9**

安装所需零件

![](media/fc849e1fd6cfd6dbdc09341c1e767c8d.png)

安装

![](media/9c6150e424e4285e52a78927b0b994cf.png)

完成

![](media/2c5653341375941609b4adf8f4f99aec.png)

**安装10**

安装所需零件

![](media/a4bb72ed509f484800fce825c197a6ed.png)

安装

![](media/6376ef59986a5c2a9499aa2802c88232.png)

完成

![](media/bf277d89c7307d7a38f191450682d421.png)

**安装11**

安装所需零件

![](media/2dca2e6e2fccd332cf9ef6be1faae203.jpg)

安装

![](media/9ca86e1657b44261be1b00145317d682.jpg)

完成

![](media/b7e75bdf6d9d5b048862c6f8dc0799c1.jpg)

**安装12**

安装所需零件

![](media/cb490304bfba4d2a6ce83dbf64f79065.jpg)

安装

![](media/2015a03f9382641aac5b61f353e062aa.jpg)

完成

![](media/13c31df60683b045b4775d16e468eedc.jpg)

**安装13**

安装所需零件

![](media/a432312b304229a0e34933bca7adfc1c.jpg)

安装

![](media/b31e2a3440bfd90e1ca29ecf9e2c1f39.jpg)

完成

![](media/a6c57fe82c1d16d25b1e81212ae8b0ad.jpg)

**安装14**

安装所需零件

![](media/cb57cffe4bddb3cd3c55ee80c0d44450.jpg)

安装

![](media/c2cb7cc9cdda36245e3f034cab8b266e.jpg)

完成

![](media/79c9358a1c4cedb5719777be16fb30f3.jpg)

**安装15**

安装所需零件

![](media/aae3a96511a2896a5ca6716301c79d4a.jpg)

安装

![](media/e58c3ffb38b1ef5048fae34a232e07ae.jpg)

完成

![](media/4e643a113edffc5f2c1b03ca666d4e52.jpg)

**安装16**

安装所需零件

![](media/10be6f1b22711d32144f3b8cb1b8233a.jpg)

安装

![](media/3f00d58bcee1e2dc2297edb8d3bd32f0.jpg)

完成

![](media/d9d75dfafa71cc49c1d5b73b82cfaf00.jpg)

**安装17**

安装所需零件

![](media/dbdf32cfc079a9ecb59370ecea7b71ba.jpg)

安装

![](media/c745e4f5d9910bb0fc8aa0484c5687fe.jpg)

完成

![](media/4b60c74b0e811d128af89305a37ccf19.png)

**安装18**

安装所需零件

![](media/c3b993fc0ecf7484321375872d243a0c.jpg)

安装

![](media/2b3d98ba2ee1faae335cebc00cd44e05.jpg)

完成

![](media/d788f9faa724e2b6d8d388687d8f0bed.jpg)

**安装19**

安装所需零件

![](media/dc4e289d327a1999c5c7968929655783.jpg)

安装

![](media/ed68f4797fdb70aed5acbd1d7669d5c0.jpg)

完成

![](media/8423b92ec9195d2ed34108f580942d01.jpg)

**接线部分**


将温湿度模块接到io17接口

![](media/0e87e70216f2e1c07fbe5d35200c2f03.png)

![](media/3ed6fdca936242d305c294115ec6cbdf.png)

将黄色led模块接到io12接口

![](media/dee7f3e88287d34129e271bf6834ba17.png)

![](media/639e6962dbff4a6cd6a5826df9cebf68.png)

将水滴传感器接到io34接口

![](media/a097c2ed19ca090ac15b216f4ed126f9.png)

![Img](./media/img-20250221132325.png)

风扇模块接线(IN+对应io19，IN-对应io18）使用的杜邦线：4根散开的杜邦线

![](media/564748f356a1505a10be98c9d83231f0.png)

![Img](./media/img-20250221132405.png)


将人体红外传感器接到io14接口

![](media/18528bd687745d288023d88a31931f11.png)

![Img](./media/img-20250221132429.png)

将左边按键模块接到io16接口

![](media/4e2f43c0bd54b1370aa7defd9ccc0411.png)

![Img](./media/img-20250221132447.png)


将右边按键模块接到io27接口

![](media/7103ee842492f58503b23203b22d9ecc.png)

![Img](./media/img-20250221132506.png)


将RFID模块接到IIC接口

![](media/aa7064dc8e93d46305881d5f74a4e826.png)

![](media/5d634445f0f53e6731126144235e612a.png)

将LCD1602显示屏接到IIC接口

![](media/25a5df6fc902c8d510249452daadab9d.png)

![Img](./media/img-20250221132527.png)


将6812RGB灯接到io26接口

![](media/73bdbe72c7dcd62ae8e33643b3427bea.png)

![Img](./media/img-20250221132540.png)


将气体传感器的白线接到io23接口，棕线不用接。

![](media/0c8102d71c577fc60476fed9fc435b07.png)

![Img](./media/img-20250221132558.png)

将蜂鸣器接到io25接口

![](media/6f95574775292225daad0c1620f418b2.png)

![Img](./media/img-20250221132610.png)


将控制窗户的舵机接到io5接口

![Img](./media/img-20250221132645.png)


![Img](./media/img-20250221132621.png)


将控制门的舵机接到io13接口

![](media/b10b214bc34fa16056d8f26d97a9a3e9.png)

![Img](./media/img-20250221132704.png)

电源接线

![Img](./media/img-20250221130118.png)


**安装20**

安装所需零件

![](media/e1f174a556103e22aca4256f30c3dad2.jpg)

安装

![](media/911fd515c605caeff4d4f1baf898010a.jpg)

完成

![](media/0337055aacdb901d175a6a7e19537048.jpg)

安装所需零件

![](media/72dc15e5daf6e69b9ccf991c4b720086.jpg)

安装

![](media/d7c429dc34e3cd2c03e43936e47c902a.jpg)

完成

![](media/de92cdd43f8f30e6f0d108f933075249.jpg)
