#include <Arduino.h>
#include <Bounce2.h>

const int BUTTON_PIN = D3;
const int LED_PIN = D10;

Bounce debouncer = Bounce();
bool ledState = false;

void setup() {
  Serial.begin(115200);
  delay(2000);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, ledState ? HIGH : LOW);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  debouncer.attach(BUTTON_PIN);
  debouncer.interval(25);

  Serial.println("Ready: press button to toggle LED");
}

void loop() {
  debouncer.update();

  if (debouncer.fell()) { // HIGH -> LOW (active low)
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);

    Serial.print("Button pressed - LED is now: ");
    Serial.println(ledState ? "ON" : "OFF");
  }
}
