let point_1;
let point_2;

function setup() {
  createCanvas(500, 500, WEBGL);
  
}

function draw() {
  background(60);
  point_1 = 600 + sin(frameCount * 0.05) * 200;
  point_2 = (frameCount * 0.05) * 2;
  
  camera(cos(point_2)*100, -100 + sin(point_2)*100, 500, 0, -100, 0, 0, 1, 0);

  push();
  smooth();
  fill(255, 255, 0);
  sphere(50,24);
  pop();
  
  line(200,0,200,0,0,0);
  push();
  translate(200,0,200);
  smooth();
  fill(255,0,0);
  sphere(50,24);
  pop();
  
  line(-200,0,200,0,0,0);
  push();
  translate(-200,0,200);
  smooth();
  fill(0,255,0);
  sphere(50,24);
  pop();
  
  line(0,-200,200,0,0,0);
  push();
  translate(0,-200,200);
  smooth();
  fill(0,0,255);
  sphere(50,24);
  pop();
  
  line(200, 0, 200, -200, 0, 200);
  line(200, 0, 200, 0, -200, 200);
  line(-200, 0, 200, 0, -200, 200);
  
}
