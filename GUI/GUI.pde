import controlP5.*;
import processing.serial.*;

//API for processing: https://processing.org/reference/

Serial port;

ControlP5 cp5;
PFont font;
PFont titleFont;


void setup() {
  size(300,300);
  font = createFont("Book Antiqua", 20);
  titleFont = createFont("Book Antiqua", 50);
 
  printArray(Serial.list()); //list all available ports
  
  //port = new Serial(this, "COM3", 9600);
  //printArray(PFont.list());
  
  //add a button
  cp5 = new ControlP5(this);
  cp5.addButton("start")
  .setPosition(100,140)
  .setSize(100,80)
  .setFont(font);
}

void draw() {
  background(255);
  textSize(30);
  fill(0,0,0); //text color
  textFont(titleFont);
  textAlign(CENTER);
  text("Shirley Bot", 150, 100);  
}

void start(){
  //port.write('1');
  println("start");
}
