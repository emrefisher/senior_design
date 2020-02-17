function setup() {
  createCanvas(800,800, WEBGL);
}

function draw() {
  background(220);
  
  let mouseX_scale = map(mouseX, 0, width, 600, -600);
  // let mouseX_scale = frameCount * 10;
  let mouseY_scale = map(mouseY, 0, width, 600, -600);
  
  camera(mouseX_scale, mouseY_scale, (height/2)/tan(PI/6), mouseX_scale/3, mouseY_scale/3, 0, 0, 1, 0);
  
  line(0,0,0,0,-500,-500);
  line(0,0,0,0,0,-500);
  
  for (let i = -4; i <= 4; i+=2) {
    push();
    translate(70*i,0,0);
    fill(255,0,0);
    box(50,50,50);
    pop();
  }
}
