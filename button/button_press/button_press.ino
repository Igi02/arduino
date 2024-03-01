int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT); 
} 
void loop() {
  digitalWrite(ledPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(3000);                      // wait for a second
  digitalWrite(ledPin, LOW);   // turn the LED off by making the voltage LOW
  delay(3000);                      // wait for a second
}
