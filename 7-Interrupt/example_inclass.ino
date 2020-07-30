#include<MsTimer2.h>     //定时器库的头文件
#include<HardwareSerial0.cpp>

int tick = 0; //计数值
int state = 0; 

//中断服务程序
void onTimer()
{
    Serial.print("timer ");
    Serial.println(tick++);
    state=~state;
}
 
void setup()
{
    Serial.begin(9600); //初始化串口
    
    MsTimer2::set(1000, onTimer); //设置中断，每1000ms进入一次中断服务程序 onTimer()
    MsTimer2::start(); //开始计时0-
}
 
void loop()
{
    
}