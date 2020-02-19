float angle = 0.0;
float d = 60;
float cameraZ = ((height/2.0) / tan(PI*60.0/360.0));

void setup() {
  size(400, 300, P3D);
}

void draw(){
  angle += PI/300;
  //camera(
  //  cos(angle)*d, 30, sin(angle)*d,
  //  0, 10, 0,
  //  0, -1, 0
  //);
  
  camera(
    cos(angle)*d, 30, sin(angle)*d,
    0, 10, 0,
    0, -1, 0
  );
  
  background(255);
  perspective(PI/8.0, float(width)/float(height), cameraZ/10.0, cameraZ*10.0);
  line(-200, 0, 0, 200, 0, 0);
  line(0, -200, 0, 0, 200, 0);
  line(0, 0, -200, 0, 0, 200);
  
  fill(60);
  translate(10,10,0);
  box(10);
  

} 
