#include <Ethernet.h>
#include <SPI.h>

#define PORT 12345

byte mac[] = { 
     0x90, 0xA2, 0xDA, 0x10, 0x18, 0x36
     };
byte ip[] = { 192, 168, 10, 177 };
byte server[] = { 192, 168, 10, 34 };

EthernetClient client;

void setup()
{
  Ethernet.begin(mac, ip);
  Serial.begin(9600);

  delay(1000);

  Serial.println("connecting...");

  if (client.connect(server, PORT)) {
    Serial.println("connected");
  } else {
    Serial.println("connection failed");
  }
}

void loop()
{
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  if (!client.available()) {
    Serial.println("connection failed, trying again...");
    client.connect(server, PORT);
    delay(1000);
  }
/*
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    for(;;)
      ;
  }
  */
}
