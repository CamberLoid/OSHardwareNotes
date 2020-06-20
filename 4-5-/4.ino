#include<HardwareSerial0.cpp>
/*
 * 相关说明
 * 咕咕咕
 */ 

// 一次设置全部的数码管

int inputChar = 0;
int setAllNum(int num){
    if(num>=10000)return 1;
    int i=9;
    // Debug
    Serial.println(num);
    while (num>0){
        // Debug
        setNum(i,num%10);
        num/=10;
        i++;
    }
    return 0;
}

// 解除某个数码管的锁定
void unlock(int display){
    if(display<9)display+=8;
    if(display>=13)return;

    digitalWrite(display, LOW);
}

// 锁定所有数码管
void lockAll(){
    for(int i=9;i<=12;i++)
        digitalWrite(i,HIGH);
}

// 设置单个数码管, 带解除锁定
int setNum(int display, int num){
    if(num>=10)return -1; //本来应该报错退出的.
    unlock(display);
    digitalWrite(3,((num>>0)%2==1)?HIGH:LOW);
    digitalWrite(4,((num>>1)%2==1)?HIGH:LOW);
    digitalWrite(5,((num>>2)%2==1)?HIGH:LOW);
    digitalWrite(6,((num>>3)%2==1)?HIGH:LOW);
    lockAll();
    return 0;
}

void test();
void empty();

void setup(){
    // initialize pinMode
    for(int i=3; i<=6; i++){
        pinMode(i,OUTPUT);
        digitalWrite(i,LOW);
        }
    for(int i=8; i<=12; i++){
        pinMode(i,OUTPUT);
        digitalWrite(i,HIGH);
        }
    Serial.begin(9600);
    for(int i=9;i<=12;i++)
        setNum(i,0);
}
void loop(){
    String input(10);
    int num, cnt;
    // 需要实现的: 滚动
    // 
    if(Serial.available()){
        inputChar %=1000;
        inputChar = inputChar*10 + (Serial.read() - '0');
        setAllNum(inputChar);
        }
}