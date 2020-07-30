#include<LiquidCrystal.h>
#include<HardwareSerial0.cpp>

LiquidCrystal lcd(10,12,6,7,8,9);

void setup() {
    lcd.begin(16, 2);
    lcd.print("LCD Ready.");
    Serial.begin(9600);
}

void printLCD(String input){
    String inputcut;
    if(input.length()>=17)
        inputcut=input.substring(16);
    lcd.setCursor(0,0);
    lcd.print(input);
    lcd.setCursor(0,1);
    lcd.print(inputcut);
}


void loop() {
    if(Serial.available()){
        String input;
        input=Serial.readString();
        printLCD(input);
    } else {
        lcd.setCursor(14, 1);
        lcd.print(millis() / 1000);
    }
}
