#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 5
#define RST_PIN 22
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println(" Approximate your card to the reader...");
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  Serial.print("UID tag: ");
  String content = " ";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
      content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  content.toUpperCase();
  if (content.substring(1) == " 13 D2 A1 D9")
  {
      Serial.print("Name: ");
      Serial.println("Nazareth Aguas");
      Serial.print("Grade & Section: ");
      Serial.println("12 - Gosling");
      Serial.println();
      delay(3000);
  }
  else if (content.substring(1) == " 92 F2 33 02")
  {
     Serial.print("Name: ");
      Serial.println("Greymher Loleng");
      Serial.print("Grade & Section: ");
      Serial.println("12 - Gosling");
      Serial.println();
      delay(3000);
  }
   else if (content.substring(1) == " 0D 23 FA 03")
  {
      Serial.print("Name: ");
      Serial.println("Januel Lising");
      Serial.print("Grade & Section: ");
      Serial.println("12 - Gosling");
      Serial.println();
      delay(3000);
  }

  else {

      Serial.println("(!) Error, unregistered UID");
      Serial.println();
      delay(3000);
      
  }

}
