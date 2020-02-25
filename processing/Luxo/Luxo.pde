import net.java.games.input.*;
import org.gamecontrolplus.*;
import org.gamecontrolplus.gui.*;

import processing.serial.*;

ControlDevice cont;
ControlIO control;
Serial mySerial;
float pitch;
float pitchOld;
float yaw;
float yawOld;
int posX=0;
int posY=0;

void setup() {
  print(Serial.list());
  mySerial = new Serial(this, Serial.list()[0], 9600);
  size(1040,820, P3D);
  control = ControlIO.getInstance(this);
  cont = control.getMatchedDevice("xboxLuxo");
  
  if (cont == null) {
    println("can't connect to controller!");
    System.exit(-1);
  }
  pitchOld = 92.0;
  yawOld = 92.0;
  
  //mySerial.write("DRIVE1100\n");
}

void draw() {
  
  
  
  getUserInput();
  
  //
  //
  //change in movement conditional
  
  //+o
  //if(pitchOld <= 60 && pitch > 60 && yawOld > 85 && yawOld < 95 && yaw > 85 && yaw < 95) {
  //  mySerial.write("!K\n");
  //}
  ////-o
  //else if(pitchOld >= 120 && pitch < 120 && yawOld > 85 && yawOld < 95 && yaw > 85 && yaw < 95) {
  //  mySerial.write("!K\n");
  //}
  ////o+
  //else if(yawOld <= 60 && yaw > 60 && pitchOld > 85 && pitchOld < 95 && pitch > 85 && pitch < 95) {
  //  mySerial.write("!K\n");
  //}
  ////o-
  //else if(yawOld >= 120 && yaw < 120 && pitchOld > 85 && pitchOld < 95 && pitch > 85 && pitch < 95) {
  //  mySerial.write("!K\n");
  //}
  ////++
  //else if(pitchOld <= 60 && pitch > 60 && yawOld <= 60 && yaw > 60) {
  //  mySerial.write("!K\n");
  //}
  
  ////+-
  //else if(pitchOld <= 60 && pitch > 60 && yawOld >= 120 && yaw < 120) {
  //  mySerial.write("!K\n");
  //}
  
  ////-+
  //else if(pitchOld >= 120 && pitch < 120 && yawOld <= 60 && yaw > 60) {
  //  mySerial.write("!K\n");
  //}
  
  ////--
  //else if(pitchOld >= 120 && pitch < 120 && yawOld >= 120 && yaw < 120) {
  //  mySerial.write("!K\n");
  //}
  

  

  String inBuffer = mySerial.readString();   
  if (inBuffer != null) {
    println(inBuffer);
  }

  
  //
  //
  //States
   //xPos yPos
   if(pitch >=0 && pitch <=60 && yaw >= 0 && yaw <= 60) {
    mySerial.write("INLVL000000\n");
    mySerial.write("INLVL110110\n");
    posX+=10;
    posY+=10;
  }
  //xPos yNeg
  else if(pitch >=0 && pitch <=60 && yaw>=120) {
    mySerial.write("INLVL000000\n");
    mySerial.write("INLVL110101\n");
    posX+=10;
    posY-=10;
  }
  
  //xNeg yPos
  else if(yaw >=0 && yaw <=60 && pitch>=120) {
    mySerial.write("INLVL000000\n");
    mySerial.write("INLVL101110\n");
    posX-=10;
    posY+=10;
  }
  
  //xNeg yNeg
  else if(yaw>=120 && pitch>=120) {
    mySerial.write("INLVL000000\n");
    mySerial.write("INLVL101101\n");
    posX-=10;
    posY-=10;
  }
  //Move xPos yNull
  else if(pitch >= 0 && pitch <= 60) {
    mySerial.write("INLVL000XXX\n");
    mySerial.write("INLVL110XXX\n");
    posX+=10;
  }
  //xNeg yNull
  else if(pitch >= 120) {
    mySerial.write("INLVL000XXX\n");
    mySerial.write("INLVL101XXX\n");
    posX-=10;
  }
  //xNull yNeg
  else if(yaw >= 120) {
    mySerial.write("INLVLXXX000\n");
    mySerial.write("INLVLXXX101\n");
    posY-=10;
  }
  //xNull yPos
  else if(yaw >= 0 && yaw <= 60) {
    mySerial.write("INLVLXXX000\n");
    mySerial.write("INLVLXXX110\n");
    posY+=10;
  }

  
  
  
  //Null all
  else if(pitch > 80 && pitch < 100 && yaw > 80 && yaw < 100) {
    mySerial.write("!K\n");
  }

  
  delay(100);
  pitchOld = pitch;
  yawOld = yaw;
  //mySerial.write("!TPC\n");
  //byte[] read = mySerial.readBytesUntil(13);
  //println(read);



  background(0);
  camera(posX+470, posY-200, (height/2) / tan(PI/6), posX+470, posY-200, 0, 0, 1, 0);
  
  // neon green box 
  translate(2.5*width/8, 2.5*height/8, 0);
  stroke(255);
  fill(0,255,0);
  box(100);
  line(0,0,0,0,0,-100000);
  
  // blue box
  translate(3*width/8, 3*height/8, 0);
  stroke(255);
  fill(0,0,255);
  box(100);
  line(0,0,0,0,0,-100000);
  
  // red box
  translate(-1.5*width/8, -1.5*height/8, -250);
  stroke(255);
  fill(255,0,0);
  box(100);
  line(0,0,0,0,0,-100000);
  
  // pink box
  translate(2*width/8, -2.5*height/8, -250);
  stroke(255);
  fill(255,0,255);
  box(100);
  line(0,0,0,0,0,-100000);
  
  // orange box
  translate(-4*width/8, 4*height/8, -250);
  stroke(255);
  fill(255,122,0);
  box(100);
  line(0,0,0,0,0,-100000);
  
  // neon blue box
  translate(2*width/8, -4.5*height/8, 800);
  stroke(255);
  fill(0,255,255);
  box(100);
  line(0,0,0,0,0,-100000);
  
  // purple box
  translate(-1.5*width/8, 3*height/8, 200);
  stroke(255);
  fill(152,0,255);
  box(100);
  line(0,0,0,0,0,-100000);
  
  // green box
  translate(-1.5*width/8, -4.5*height/8, -750);
  stroke(255);
  fill(17,82,2);
  box(100);
  line(0,0,0,0,0,-100000);
  
  // yellow box
  translate(5*width/8, 3*height/8, 500);
  stroke(255);
  fill(255,255,0);
  box(100);
  line(0,0,0,0,0,-1000000000);
  strokeWeight(2);
  println("PITCH: ",pitch);
  println("YAW: ",yaw);
}
public void getUserInput() {
  pitch = map(cont.getSlider("Pitch").getValue(), -1.0, 1.0, 0.0, 180.0);
  yaw = map(cont.getSlider("Yaw").getValue(), -1.0, 1.0, 0.0, 180.0);
}
