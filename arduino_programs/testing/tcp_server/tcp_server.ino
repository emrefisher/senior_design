byte mac[] = { 0x90, 0xA2, 0xDA, 0x10, 0x18, 0x36 }; //MAC address of the shield
byte ip[] = { 169,254,10,177 }; //Ethernet shield IP address
Server server = 80; //server port to listen on


#define MAX_SIZE 32 // maximum packet size
byte packetBuffer[MAX_SIZE]; // buffer to hold incoming packet
int packetSize; // holds received packet size

int i;

/* SETUP: init Ethernet shield, Start TCP listening, open serial port */
void setup() {
 Ethernet.begin(mac,ip);
 server.begin();
 Serial.begin(9600);
}

/* LOOP: wait for incoming packets and print each packet to the serial port*/
void loop()
{

 if(server.available()) {

   //if there's data available, read a packet
   
   packetSize = server.read(packetBuffer,MAX_SIZE);
   
     Serial.print("Received packet of size ");
     Serial.println(abs(packetSize));

     Serial.println("Contents:");
     for(i=0; i<min(MAX_SIZE,abs(packetSize)); i++) {
       Serial.print(packetBuffer[i],BYTE);
     }
     Serial.println("");
     
 }
 //wait a bit
 delay(10);  
}
