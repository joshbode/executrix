// Executrix Button

#include <TrinketKeyboard.h>

// pins
const unsigned char BUTTON = 0;
const unsigned char LED = 1;

// debouncing
const unsigned short DEBOUNCE_DELAY = 50;
unsigned long debounce_expiry = 0;
bool button_state = HIGH, prev_reading = HIGH;

// press counting
const unsigned short COUNT_DELAY = 500;
unsigned long count_expiry = 0;
const unsigned short MAX_COUNT = 4;
unsigned short count = 0;


// setup button
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  digitalWrite(BUTTON, HIGH);

  TrinketKeyboard.begin();
}


// main loop
void loop() {
  TrinketKeyboard.poll();

  unsigned long time = millis();

  // process if outside of sample window
  if (count && (time > count_expiry)) {
    switch (count) {
      case 1:
        TrinketKeyboard.pressKey(KEYCODE_MOD_LEFT_SHIFT, KEYCODE_APP);
        break;
      case 2:
        TrinketKeyboard.pressKey(KEYCODE_MOD_RIGHT_SHIFT, KEYCODE_APP);
        break;
      case 3:
        TrinketKeyboard.pressKey(KEYCODE_MOD_RIGHT_ALT | KEYCODE_MOD_RIGHT_CONTROL, KEYCODE_DELETE);
        break;
      default:
        break;
    }
    TrinketKeyboard.pressKey(0, 0);  // lift key

    //TrinketKeyboard.print(count);
    //TrinketKeyboard.print("\n");

    // reset count
    count = 0;
  } else {
    bool reading = digitalRead(BUTTON);
    digitalWrite(LED, !reading);

    // debounce reading
    if (reading != prev_reading) {
      debounce_expiry = time + DEBOUNCE_DELAY;
    } else if (time > debounce_expiry) {
      if (reading != button_state) {
        if (reading == LOW) {
          if (count < MAX_COUNT) {
            // increment count and reset sample window
            count++;
            count_expiry = time + COUNT_DELAY;
          } else {
            // max presses reached so invalidate window
            count_expiry = 0;
          }
        }

        button_state = reading;
      } else {

      }
    }

    prev_reading = reading;
  }
}
