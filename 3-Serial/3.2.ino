
//#define HAVE_HWSERIAL0 //Needed by HardwareSerial0.cpp
#include<HardwareSerial0.cpp>

void setup()
{
    Serial.begin(9600);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    Serial.println("OK");
}
/*
 * 此处约定:
 * f = forward
 * b = backward
 * r = right
 * l = left
 * s = stop
 */
void loop()
{
    char ch;
    String str;
    if(Serial.available()>0){

        /*
        str = Serial.readString();
        if(str=="YES"){
            Serial.println("TRUE");
        } else {
            Serial.println("FALSE");
        }
        
        /* switch (ch)
        {
        case 'f':
            digitalWrite(6,HIGH);
            digitalWrite(7,LOW);
            digitalWrite(8,HIGH);
            digitalWrite(9,LOW);
            break;
        case 'b':
            digitalWrite(7,HIGH);
            digitalWrite(6,LOW);
            digitalWrite(9,HIGH);
            digitalWrite(8,LOW);
            break;
        case 'r':
            digitalWrite(7,HIGH);
            digitalWrite(6,LOW);
            digitalWrite(8,HIGH);
            digitalWrite(9,LOW);
            break;
        case 'l':
            digitalWrite(6,HIGH);
            digitalWrite(7,LOW);
            digitalWrite(9,HIGH);
            digitalWrite(8,LOW);
        break;
        case 's':
            digitalWrite(6,LOW);
            digitalWrite(7,LOW);
            digitalWrite(8,LOW);
            digitalWrite(9,LOW);
        break;
        default:
            digitalWrite(6,HIGH);
            digitalWrite(7,LOW);
            digitalWrite(8,HIGH);
            digitalWrite(9,LOW);
            break;
        }
        */

    }
}