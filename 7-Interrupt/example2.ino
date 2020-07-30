#include<HardwareSerial0.cpp>

int pinInterrupt = 2; //接中断信号的脚
 
void onChange()
{
   if ( digitalRead(pinInterrupt) == LOW )
      Serial.println("Key Down");
   else
      Serial.println("Key UP");
}
 
void setup()
{
   Serial.begin(9600); //打开串口
 
   pinMode( pinInterrupt, INPUT);//设置管脚为输入
   
   //Enable中断管脚, 中断服务程序为onChange(), 监视引脚变化
   attachInterrupt( digitalPinToInterrupt(pinInterrupt), onChange, CHANGE);
}
 
void loop()
{
  // 模拟长时间运行的进程或复杂的任务。
  for (int i = 0; i < 100; i++)
  {
    // 什么都不做，等待10毫秒
    delay(10); 
  }
}