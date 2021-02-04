const int softPotPin = A1; // Pin connected to softpot wiper

const int GRAPH_LENGTH = 40; // Length of line graph

const int buzzerPin = 3;

const int threshold = 750;


void setup() {
  Serial.begin(9600);
  pinMode(softPotPin, INPUT);
}

void loop()  {

  pinMode(buzzerPin, OUTPUT);


  int softPotRead = analogRead(softPotPin);
  // Map the 0-1023 value to 0-40
  int softPotPosition = map(softPotRead, 0, 1023, 0, GRAPH_LENGTH);

  if (softPotRead > threshold) {
    digitalWrite(buzzerPin, LOW);

  }
  if (softPotRead < threshold) {
    digitalWrite(buzzerPin, HIGH);

    
//could not figure out how to map the SoftPot
    Serial.print(softPotPosition); // Starting end
    for (int i = 0; i < GRAPH_LENGTH; i++)
    {
      if (i == softPotPosition) Serial.print("|");
      else Serial.print("-");
    }
    Serial.println("> (" + String(softPotRead) + ")");


  }

}
