
//Color Pins
const int redPin = 2; 
const int greenPin = 1; 
const int bluePin= 0; 

//mapping ints
const int redX = 512;
const int redY = 1023;
const int greenX = 1023;
const int greenY = 0;
const int blueX = 0;
const int blueY = 0;

void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {

  //reading the joystick axis
  int xAxis = analogRead(A2);
  int yAxis = analogRead(A3);

  
  xAxis = map(xAxis, 0, 1023, 0, 1023);
  yAxis = map(yAxis, 0, 1023, 1023, 0345);

  int distanceRed = sqrt(pow(abs(redX - xAxis), 2) +  pow(abs(redY - yAxis), 2));
  int distanceGreen = sqrt(pow(abs(greenX - xAxis), 2) +  pow(abs(greenY - yAxis), 2));
  int distanceBlue = sqrt(pow(abs(blueX - xAxis), 2) +  pow(abs(blueY - yAxis), 2));

  int brightRed = 255 - constrain(map(distanceRed, 0, 1023, 0, 255), 0, 255);
  int brightGreen = 255 - constrain(map(distanceGreen, 0, 1023, 0, 255), 0, 255);
  int brightBlue = 255 - constrain(map(distanceBlue, 0, 1023, 0, 255), 0, 255);

  analogWrite(redPin, brightRed);
  analogWrite(greenPin, brightGreen);
  analogWrite(bluePin, brightBlue);

 
  delay(100);
}
   
