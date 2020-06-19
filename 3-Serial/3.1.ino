void setup()
{
  Serial.begin(9600);
}

void loop()
{
    char ch=" DD";
    if (Serial.available()>0){
        Serial.println("Hello world") //打印数据至串口
    }
}