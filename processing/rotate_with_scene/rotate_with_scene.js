let cam_zoom=0;

function setup() {
  createCanvas(800, 800, WEBGL);

}

function draw() {
  background(60);
  perspective();
  
  fill(0,0,255);
  box(5,100,0);
  box(100,5,0);
  box(0,5,100);
  
  translate(0, 100, 0);
  fill(255,255,0);
  box(1000,1,1000);
  translate(0, -500, -500);
  fill(255,0,255);
  box(1000, 1000, 1);
  
  // fill(0,0,255);
  // box(5,100,0);
  // box(100,5,0);
  // box(0,5,100);
  
  camera(0,0,(height/2)/tan(PI/6),0,0,0,0,1,0);
  // translate(cam_zoom,0,0);
  rotateY(-frameCount/10);
  // rotate(-frameCount/10, [0,1,0]);
  
  // translate(height/2, width/2);
  translate(250,0);
  
  
  
  push();
  translate(0,0,0);
  fill(0,0,255,100);
  box(10,10);
  pop();
  
  push();
  line(0,0,100,100);
  translate(0,0,0);
  fill(255,0,0,100);
  box(200,200);
  pop();
  
  push();
  translate(200,0,00);
  fill(0,255,0,100);
  box(100, 100);
  pop();
  

}

function mouseWheel(event) {
  cam_zoom += event.delta/2;
}
