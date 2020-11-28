/*Title: Smart Helmet Lock Design
 * 
 * Author: Simon
 * 
 * Date: 28th, Feb, 2020
 * 
 */

// Initialize all the libs needed 
#include <SoftwareSerial.h>
#include <SPI.h>
#include <MFRC522.h>

SoftwareSerial ble(5,6); // creates and instance of the software serial and attaches bluetooth module's tx and rx to pins 5 and 6

#define SS_PIN 10 
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create and instance of the  MFRC522(the name is absolutely random).


#define trigger1 4
#define trigger2 3
#define trigger3 2
#define input_trig 7
#define led_pin A0


int bluetooth_state;
int flag = 0; // ensures that only one state is printed on the serial
int input_state = 0; // stores the state values on the input pad
void setup() {
  Serial.begin(9600);   // Initiate a serial communication
  pinMode(trigger1, OUTPUT);
  pinMode(trigger2, OUTPUT);
  pinMode(trigger3, OUTPUT);
  pinMode(input_trig, INPUT);
  pinMode(led_pin, OUTPUT);
  
  SPI.begin(); // Initialize SPI bus
  mfrc522.PCD_Init(); // Initialize MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
}
void loop(){
//test_mcu(); // Uncomment to test and confirm MCU is okay, LED on the board should blink at intervals of 1/2 a sec

access_via_rfid(); // Unlocks via rfid

access_via_bluetooth(); // Unlocks via bluetooth app

access_via_signal_input(); // Unlocks via signal input
} 

void access_via_rfid(){
    // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();

 // ******** AUTHORIZATION *********
 //change here the UID "BD 31 15 2B" of the card/cards that you want to give access
  if (content.substring(1) == "BD 31 15 2B"){
    digitalWrite(trigger1, HIGH);
    Serial.println("Authorized access");
    Serial.println();
    delay(3000);
  }else{
    Serial.println(" Access denied");
    delay(3000);
  }
}

void access_via_bluetooth(){
   if(Serial.available() > 0){     
      bluetooth_state = Serial.read();   
      flag=0;
    } 

  // Checks if correct code was sent to authorise access
   if(bluetooth_state == "1"){
    digitalWrite(trigger1, HIGH); // unlocks the helmet
   } else {
     digitalWrite(trigger1, LOW); // does nothing if no code or the wrong code was sent
   }
   
}

void access_via_signal_input(){
  input_state = digitalRead(input_trig);
  if(input_state == 1){
    digitalWrite(trigger1, HIGH); // unlocks the helmet
  } else {
    digitalWrite(trigger1, LOW); // does nothing
  }
}


void test_mcu(){
  digitalWrite(led_pin, HIGH);
  delay(500);
  digitalWrite(led_pin, LOW);
  delay(500);
}
