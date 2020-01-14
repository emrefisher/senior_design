/*
 Chat Server

 A simple server that distributes any incoming messages to all
 connected clients.  To use, telnet to your device's IP address and type.
 You can see the client's input in the serial monitor as well.
 Using an Arduino Wiznet Ethernet shield.

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13

 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe

 */

#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network.
// gateway and subnet are optional:
byte mac[] = {
     0x90, 0xA2, 0xDA, 0x10, 0x18, 0x36
     };
IPAddress ip(192, 168, 10, 177);
IPAddress myDns(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

#define PORT 12345

String incoming_data;
char incoming_data_chars[48];

// telnet defaults to port 23
EthernetServer server(PORT);
boolean alreadyConnected = false; // whether or not the client was connected previously

void setup() {
     // You can use Ethernet.init(pin) to configure the CS pin
     //Ethernet.init(10);  // Most Arduino shields
     //Ethernet.init(5);   // MKR ETH shield
     //Ethernet.init(0);   // Teensy 2.0
     //Ethernet.init(20);  // Teensy++ 2.0
     //Ethernet.init(15);  // ESP8266 with Adafruit Featherwing Ethernet
     //Ethernet.init(33);  // ESP32 with Adafruit Featherwing Ethernet

     // initialize the ethernet device
     Ethernet.begin(mac, ip, myDns, gateway, subnet);
     
     // Open serial communications and wait for port to open:
     Serial.begin(9600);
          while (!Serial) {
     ; // wait for serial port to connect. Needed for native USB port only
     }

  // Check for Ethernet hardware present
     if (Ethernet.hardwareStatus() == EthernetNoHardware) {
          Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
          while (true) {
          delay(1); // do nothing, no point running without Ethersnet hardware
          }
     }
     if (Ethernet.linkStatus() == LinkOFF) {
          Serial.println("Ethernet cable is not connected.");
     }

     // start listening for clients
     server.begin();
     
     Serial.print("Chat server address: ");
     Serial.println(Ethernet.localIP());
     Serial.print("Port number: ");
     Serial.println(PORT);
}

void loop() {
     // wait for a new client:
     EthernetClient client = server.available();
     
     // when the client sends the first byte, say hello:
     if (client) {
          if (!alreadyConnected) {
               // clear out the input buffer:
               client.flush();
               Serial.println("We have a new client");
               //client.println("Hello, client!");
               alreadyConnected = true;
          }

          if (client.available() > 0) {
               // read the bytes incoming from the client:
               char thisChar = client.read();
               // echo the bytes back to the client:
               //server.write(thisChar);
               // echo the bytes to the server as well:
               //Serial.write(thisChar);
               incoming_data += thisChar;
          }
          if (client.available() == 0) {          // if there is no more data available to read
               Serial.println(incoming_data);     // print the incoming data to the serial monitor
               incoming_data.toCharArray(incoming_data_chars, incoming_data.length()+1);
               server.write(incoming_data_chars); // echo the incoming data back to the client
               incoming_data = "";                // reset the incoming data placeholder to nothing, ready for next incoming string
          }
     }
}
