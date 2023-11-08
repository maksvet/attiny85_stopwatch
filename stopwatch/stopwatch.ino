e#include <TinyWireM.h> // Use TinyWireM for ATtiny85
#include <Tiny4kOLED.h>
#include <font16x32digits.h> // This includes the font definition
enum StopwatchState {
  STOPPED,
  RUNNING,
  RESET
};

// 
StopwatchState state = STOPPED;
long startTime = 0;
long elapsedSeconds = 0;
long buttonPressStart = 0;
int buttonPin = 3;  // Using PB3 on ATTiny85

void setup() {
  oled.begin(64, 32, sizeof(tiny4koled_init_64x32br), tiny4koled_init_64x32br);
  oled.clear();
  oled.on();
  oled.setFont(FONT16X32DIGITS);
  
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  long currentTime = millis();
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && buttonPressStart == 0) {
    buttonPressStart = currentTime;
  }

  if (buttonState == HIGH && buttonPressStart != 0) {
    long buttonPressDuration = currentTime - buttonPressStart;
    
    if (buttonPressDuration >= 2000) {
      state = RESET;
    } else if (state != RESET) {
      state = (state == RUNNING) ? STOPPED : RUNNING;
    }
    
    buttonPressStart = 0;
  }

  if (buttonPressStart != 0 && (currentTime - buttonPressStart >= 2000)) {
    elapsedSeconds = 0;
  }

  switch (state) {
    case RUNNING:
      if ((currentTime - startTime) >= 1000) {
        startTime = currentTime;
        elapsedSeconds++;
      }
      break;

    case STOPPED:
      break;

    case RESET:
      elapsedSeconds = 0;
      state = STOPPED;
      break;
  }

  if (elapsedSeconds > 999) {
    elapsedSeconds = 999;
  }
	

	char buffer[4];
	sprintf(buffer, "%03d", elapsedSeconds);

  oled.setCursor(0, 0);
  oled.print(buffer);
}
