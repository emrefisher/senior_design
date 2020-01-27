
LED_BUILTIN




#include <SPI.h>
#include <Ethernet.h>

int joystick_pin = A0;		// select the input pin for the potentiometer
int joystick_value = 0;	// variable to store the value coming from the sensor
bool pos_flag = false;
bool stop_flag = false;
bool neg_flag = false;

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network
byte mac[] = { 0x90, 0xA2, 0xDA, 0x10, 0x18, 0x36 };
IPAddress ip( 192,168,10,177 );

// Enter the IP address of the server you're connecting to
IPAddress server( 192,168,10,30 );   // IP address of Parker Motor Compumotor 6K4

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to
EthernetClient client;

void setup() {

	pinMode(LED_BUILTIN, OUTPUT);		// initialize built-in LED, status LED for connectivity
	digitalWrite(LED_BUILTIN, LOW);

	// start the Ethernet connection
	Ethernet.begin(mac, ip);

	// Open serial communications and wait for port to open
	Serial.begin(9600);
	while (!Serial) {
		; // wait for serial port to connect. Needed for native USB port only
	}

	// Check for Ethernet hardware present
	if (Ethernet.hardwareStatus() == EthernetNoHardware) {
		Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
		while (true) {
			delay(1); // do nothing, no point running without Ethernet hardware
		}
	}
	while (Ethernet.linkStatus() == LinkOFF) {
		Serial.println("Ethernet cable is not connected.");
		delay(500);
	}

	// give the Ethernet shield a second to initialize
	delay(1000);
	Serial.println("connecting...");

	// if you get a connection, report back via serial
	if (client.connect(server, 5002)) {
		Serial.println("connected");
		digitalWrite(LED_BUILTIN, HIGH);
	} else {
		// if you didn't get a connection to the server
		Serial.println("connection failed");
	}









}

void loop() {

	// read the value from the sensor:
	joystick_value = analogRead(joystick_pin);    
	//Serial.println(joystick_value);
	if (joystick_value > 600) {
		 //Serial.println("POSF");
		 pos_flag = true;
	}
	if (joystick_value > 500 && joystick_value < 515) {
		 //Serial.println("!K");
		 stop_flag = true;
	}
	if (joystick_value < 400) {
		 //Serial.println("NEGF");
		 neg_flag = true;
	}

		 
	// if there are incoming bytes available
	// from the server, read them and print them:
	if (client.available()) {
		char c = client.read();
		Serial.print(c);
	}

	// as long as there are bytes in the serial queue,
	// read them and send them out the socket if it's open:
	while (Serial.available() > 0) {
		char inChar = Serial.read();
		if (pos_flag == true) {
		 char posf[5] = "POSF\r\n";
		 client.print(posf);
//     client.print("\r");
		 pos_flag = false;
		}

//    if (stop_flag == true) {
//     char kill[3] = "!K";
//     client.print(kill);
//     client.print("\r\n");
//     stop_flag = false;
//    }

		if (neg_flag == true) {
		 char negf[5] = "NEGF";
		 client.print(negf);
		 client.print("\r\n");
		 neg_flag = false;
		}
		
		if (client.connected()) {
			client.print(inChar);
		}
	}

	// if the server's disconnected, stop the client:
	if (!client.connected()) {
		Serial.println();
		Serial.println("disconnecting.");
		client.stop();
		// do nothing:
		while (true) {
			delay(1);
		}
	}
}










// =========================================================================================
/*
	Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13. 
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead(). 
 
 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground
 
 * Note: because most Arduinos have a built-in LED attached 
 to pin 13 on the board, the LED is optional.
 
 
 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe
 
 This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/AnalogInput
 
 */
/*
int joystick_pin = A0;    // select the input pin for the potentiometer
int joystick_value = 0;  // variable to store the value coming from the sensor
bool pos_flag = false;
bool stop_flag = false;
bool neg_flag = false;

void setup() {
	Serial.begin(9600);
}

void loop() {
	// read the value from the sensor:
	joystick_value = analogRead(joystick_pin);    
	//Serial.println(joystick_value);
	if (joystick_value > 600) {
		 //Serial.println("POSF");
		 pos_flag = true;
	}
	if (joystick_value > 500 && joystick_value < 515) {
		 //Serial.println("!K");
		 stop_flag = true;
	}
	if (joystick_value < 400) {
		 //Serial.println("NEGF");
		 neg_flag = true;
	}

	if (pos_flag == true) {
		 Serial.println("POSF");
		 pos_flag = false;
	}

	if (stop_flag == true) {
		 Serial.println("!K");
		 stop_flag = false;
	}

	if (neg_flag == true) {
		 Serial.println("NEGF");
		 neg_flag = false;
	}
 
}

*/
