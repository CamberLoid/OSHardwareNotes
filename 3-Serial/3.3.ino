// Enable VSCode Intelisense
#include<HardwareSerial0.cpp>

// With L293D
// See 3.md#L293D
void reset(){
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
}
void setup(){
    Serial.begin(9600);
    // Init Pinmode
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    // Init digitalWrite
    reset();
    // Finish Init
    Serial.println("Setup ready");
}
/*
 * f = forward/left/non-clockwise
 * b = backward/right/clockwise
 * D6 -> INPUT3 -> Motor2
 * D7 -> INPUT4 -> Motor2
 * D8 -> INPUT1 -> Motor1
 * D9 -> INPUT2 -> Motor1
 */


void loop(){ // while(true){
    String __input(4);
    __input = Serial.readString();
    // Echo
    Serial.println("$ " + __input);
    // Controlling Motor 1
    if(__input == "1f"){
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
    } 
    else if(__input == "1b") {
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
    } 
    else if(__input == "1s") {
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
    } 

    /*else*/ if(__input == "2f") {
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
    } 
    else if(__input == "2b") {
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
    } 
    else if(__input == "2s") {
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
    } 
    // Controlling all Motor
    /*else*/ if(__input == "f"){
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
    }
    else if(__input == "b"){
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
    }
    else if(__input == "s"){
        reset();
    }
}