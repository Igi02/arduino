#include "movingdick.h"
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

void setup() {
  Serial.begin(115200);
  matrix.loadSequence(movingdick);
  matrix.begin();

  matrix.play(true);
}

uint32_t frame[] = {
  0, 0, 0, 0xFFFF
};

void loop() {
  delay(500);
}