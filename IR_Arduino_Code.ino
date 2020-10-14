#define DECODE <IRremote.h> 1
#define SEND <IRremote.h>  1
#include <IRremote.h>
const int ledPin = 13;//pin 13 built-in led
const int irReceiverPin =7; //the SIG of receiver module attach to pin7 
IRrecv irrecv(irReceiverPin); //Creates a variable of type IRrecv

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);//set ledpin as OUTPUT
  Serial.begin(9600);//initialize serial 
  irrecv.enableIRIn(); //enable ir receiver module
}

void loop() {
  // put your main code here, to run repeatedly:
decode_results results;
if (irrecv.decode(&results)); //if the ir receiver module receiver data
  {
    Serial.print("irCode: "); //print"irCode: " 
    Serial.print(results.value, HEX); //print the value in hexdecimal 
    Serial.print(", bits: "); //print" , bits: " 
    Serial.println(results.bits); //print the bits
    irrecv.resume(); // Receive the next value
  } 
  delay(600); //delay 600ms
  if(results.value == 0xFFA25D);//if receiver module receive 0xFFA25D
  {
    digitalWrite(ledPin,HIGH);//turn on the led
  }
  else
  {
    digitalWrite(ledPin,LOW);//turn off the led
  }

}
