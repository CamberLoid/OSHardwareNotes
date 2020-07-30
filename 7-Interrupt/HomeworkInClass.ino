#include<HardwareSerial0.cpp>
#include<MsTimer2.h>

int pinInterrupt = 2; //接中断信号的脚
volatile int cnt=0;

void onChange()
{
    Serial.println("Key Down");
    setNum(0);
    cnt=0;
}

int setNum(int num){
    if(num>=10)return -1; //本来应该报错退出的.
    // unlock(display);
    digitalWrite(3,((num>>0)%2==1)?HIGH:LOW);
    digitalWrite(4,((num>>1)%2==1)?HIGH:LOW);
    digitalWrite(5,((num>>2)%2==1)?HIGH:LOW);
    digitalWrite(6,((num>>3)%2==1)?HIGH:LOW);
    // lockAll();
    return 0;
}

void onTimer(){
    cnt++;
    setNum(cnt%10);
}

void setup()
{
    Serial.begin(9600); //打开串口
    
    pinMode(pinInterrupt, INPUT);//设置管脚为输入
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(6, OUTPUT);
    //Enable中断管脚, 中断服务程序为onChange(), 监视引脚变化
    attachInterrupt(digitalPinToInterrupt(pinInterrupt), onChange, CHANGE);
    MsTimer2::set(1000, onTimer); //设置中断，每1000ms进入一次中断服务程序 onTimer()
    MsTimer2::start(); //开始计时
}
 
void loop()
{
    
}