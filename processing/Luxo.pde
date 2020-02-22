import net.java.games.input.*;
import org.gamecontrolplus.*;
import org.gamecontrolplus.gui.*;

import processing.serial.*;

ControlDevice cont;
ControlIO control;
Serial mySerial;
float pitch;
float pitchOld;

void setup() {
  print(Serial.list());
  mySerial = new Serial(this, Serial.list()[0], 9600);
  size(360, 200);
  control = ControlIO.getInstance(this);
  cont = control.getMatchedDevice("xboxLuxo");
  
  if (cont == null) {
    println("can't connect to controller!");
    System.exit(-1);
  }
  pitchOld = 92.0;
}

void draw() {
  
  mySerial.write("DRIVE1\n");
  getUserInput();
  background(pitch, 100, 255);
  println(pitch);
  delay(50);
  
  //change in movement conditional
  if(pitchOld <= 60 && pitch > 60) {
    mySerial.write("!K\n");
  }
  else if(pitchOld >= 120 && pitch < 120) {
    mySerial.write("!K\n");
  }
  
  //movement conditional
  if(pitch >= 0 && pitch <= 60) {
    mySerial.write("POSF\n");
  }
  //else if(pitch > 60 && pitch <= 85) {
  //  mySerial.write("!K\n");
  //  mySerial.write("POSS\n");
  //}
  else if(pitch > 85 && pitch < 95) {
    mySerial.write("!K\n");
  }
  //else if(pitch >=95 && pitch < 120) {
  //  mySerial.write("!K\n");
  //  mySerial.write("NEGS\n");
  //}
  else if(pitch >= 120) {
    mySerial.write("NEGF\n");
  }
  delay(100);
  pitchOld = pitch;
}

public void getUserInput() {
  pitch = map(cont.getSlider("Pitch").getValue(), -1.0, 1.0, 0.0, 180.0);
}
