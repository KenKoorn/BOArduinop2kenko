const int Led1 = 2;
const int AfstandTrig = 8;  // Ultrasone sensor trigger pin
const int AfstandEcho = 9;  // Ultrasone sensor echo pin
const int DISTANCE_THRESHOLD = 20;  // Set the distance threshold to turn off the LED strip

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(AfstandTrig, OUTPUT);
  pinMode(AfstandEcho, INPUT);
  Serial.begin(115200);
}

void loop() {
  // Stuur ultrasone puls
  digitalWrite(AfstandTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(AfstandTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(AfstandTrig, LOW);

  // Meet de tijd die het duurt voordat het echo-signaal terugkomt
  int afstandWaarde = pulseIn(AfstandEcho, HIGH) * 0.034 / 2;

  // Print de gemeten afstand
  Serial.print("Afstand: ");
  Serial.print(afstandWaarde);
  Serial.println(" cm");

  // Controleer of de afstand minder is dan het drempelwaarde (threshold)
  if (afstandWaarde < DISTANCE_THRESHOLD) {
    // Zet het licht aan (LED)
    digitalWrite(Led1, HIGH);
  } else {
    // Zet het licht uit (LED)
    digitalWrite(Led1, LOW);
  }

  delay(1000); // Wacht 1 seconde voordat je opnieuw controleert
}

