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


========================================================================

function setup(){
	createCanvas(800, 800, WEBGL);
}
function draw(){
  
	background(240);
    fill(0,255,0);
    box(5,5);

	// move the origin to the pivot point
	// translate(height/2, width/2); 

	// then rotate the grid around the pivot point by a
	// number of degrees equal to the frame count of the sketch
	rotate(radians(frameCount));

	// and draw the square at the origin
    translate(100,100);
	fill(255,0,0);
	box(100, 100);

}



========================================================================

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
  
  fill(0,0,255);
  box(5,100,0);
  box(100,5,0);
  box(0,5,100);
  
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


========================================================================

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
  fill(255);
  box(1000,1,1000);
  translate(0, -500, -500);
  fill(100);
  box(1000, 1000, 1);
  
  
  let mouseX_scale = map(mouseX,0,width,-600,600);
  // let mouseY_scale = map(mouseY,0,width,-600,600);
  let mouseY_scale = 0;
  
  // camera(mouseX_scale,mouseY_scale,(height/2)/tan(PI/6),0,0,0,0,1,0);
  camera(0,0,(height/2)/tan(PI/6),0,0,0,0,1,0);
  // translate(cam_zoom,0,0);
  rotate(-frameCount/10, [0,1,0]);
  // rotate(mouseX/100, [0,1,0]);
  
  
  // translate(height/2, width/2);
  translate(250,0);
  
  
  
  // push();
  // translate(0,0,0);
  // fill(0,0,255,100);
  // box(10,10);
  // pop();
  
  push();
  // line(0,0,100,100);
  translate(0,0,0);
  fill(255,0,0,100);
  box(200,200);
  pop();
  
  push();
  translate(0,0,200);
  fill(0,255,0,100);
  box(100, 100);
  pop();
  

}

function mouseWheel(event) {
  cam_zoom += event.delta/2;
}



========================================================================


let j = 0;
let cosj = 0;

function setup() {
  createCanvas(800,800, WEBGL);
}

function draw() {
  background(220);
  

  
  let mouseX_scale = map(mouseX, 0, width, 600, -600);
  // let mouseX_scale = frameCount * 10;
  let mouseY_scale = map(mouseY, 0, width, 600, -600);
  
  cosj = cos(radians(j)) * 1000;

  camera(cosj, mouseY_scale, (height/2)/tan(PI/6), cosj/2, mouseY_scale, 0, 0, 1, 0);
  
  line(0,0,0,0,-500,-500);
  line(0,0,0,0,0,-500);
  line(0,-500,-500,0,0,-500);
  
  for (let i = -4; i <= 4; i+=2) {
    push();
    translate(70*i,0,0);
    fill(255,0,0);
    box(50,50,50);
    pop();
  }
  
  j += 1;

  
}