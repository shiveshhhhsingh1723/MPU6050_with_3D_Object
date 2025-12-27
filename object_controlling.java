import processing.serial.*;

Serial myPort;
float xAngle = 0;
float yAngle = 0;

void setup() {
  size(600, 600, P3D);

  // FIXED: list COM ports safely
  String[] ports = Serial.list();
  for (int i = 0; i < ports.length; i++) {
    println(i + ": " + ports[i]);
  }

  myPort = new Serial(this, "COM5", 115200);
  myPort.bufferUntil('\n');
}

void draw() {
  background(25);
  lights();
  translate(width/2, height/2);
  rotateX(radians(xAngle));
  rotateY(radians(yAngle));
  fill(150, 150, 255);
  stroke(255);
  strokeWeight(2);
  box(200);
}

void serialEvent(Serial port) {
  String data = port.readStringUntil('\n');
  if (data != null) {
    data = trim(data);
    String[] values = split(data, ',');
    if (values.length == 2) {
      xAngle = float(values[0]);
      yAngle = float(values[1]);
    }
  }
}
