function setup() {
  createCanvas(800, 800, WEBGL);
}

function draw() {
  orbitControl();
  background(60);
  
  push();
  // line(0,0,100,100);
  translate(0,0,0);
  fill(255,0,0,100);
  box(200,200);
  pop();
  
  push();
  translate(200,0,0);
  fill(0,255,0,100);
  box(100, 100);
  pop();
}
