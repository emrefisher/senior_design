float mouseX_scale;
float mouseY_scale;
float j = 0;
float cosj = 0;
float cameraZ = ((height/2.0) / tan(PI*60.0/360.0));


void setup() {
  size(640, 360, P3D);
  fill(204);
  
}



void draw() {
  lights();
  background(220);
  perspective();

  mouseX_scale = map(mouseX, 0, width, 600, -600);
  mouseY_scale = map(mouseY, 0, width, 600, -600);

  cosj = cos(radians(j)) * 1000;
  perspective(PI/8.0, float(width)/float(height), cameraZ/10.0, cameraZ*100.0);

  //camera(cosj, mouseY_scale, (height/2)/tan(PI/6), 
  //  cosj/2, mouseY_scale, 0, 
  //  0, 1, 0);

  camera(cosj, 0, (height/2)/tan(PI/6), 
    0, 0, -500, 
    0, 1, 0);

  fill(255,0,0);
  line(0,0,0,0,-500,-500);
  line(0,0,0,0,0,-500);
  line(0,-500,-500,0,0,-500);
  
  line(-100, 0, 0, 100, 0, 0);
  line(0, -100, 0, 0, 100, 0);
  line(0, 0, -100, 0, 0, 100);
  
  
  for (int i = -4; i <= 4; i+=2) {
    push();
    translate(70*i,0,0);
    fill(255,0,0);
    box(50,50,500);
    pop();
  }
  
  j += 1;
  
}
