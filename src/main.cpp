#include <Arduino.h>

#include "../lib/mcp4xxx/mcp4xxx.h"

using namespace icecave::arduino;

MCP4XXX *digipot;

void setup() {
  digipot = new MCP4XXX();
  digipot->set(0);

  Serial.begin(9600);
  Serial.println("ESP32 Rolec Solar Diverter");
  Serial.println(digipot->max_value(), 10);
}

void loop() {
  for (int pos = 0; pos < digipot->max_value(); pos++) {
    digipot->set(pos);
    Serial.println(pos);
    delay(100);
  }
}