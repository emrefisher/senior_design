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
