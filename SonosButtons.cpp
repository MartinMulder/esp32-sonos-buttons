#include "Arduino.h"
#include "SonosButtons.h"

SonosButtons::SonosButtons(bool debug)
{
	_debug = debug;
	Serial.begin(115200);
}

void SonosButtons::setup()
{
	Serial.println("SonosButtons setup");
	pinMode(SONOS_BTN_PIN, OUTPUT);
}

void SonosButtons::handle()
{
	readButtonState();
}

/* Private functions */
bool SonosButtons::isPlayPause(int value)
{
	return (value > PLAY_MIN && value < PLAY_MAX);
}

bool SonosButtons::isNext(int value)
{
	return (value > NEXT_MIN && value < NEXT_MAX);
}

bool SonosButtons::isPrevious(int value)
{
	return (value > PREV_MIN && value < PREV_MAX);
}

void SonosButtons::readButtonState()
{
	// Create a temp current state to find out if the current state is changed
	int newState;

	// Read the current value
	readValue = analogRead(SONOS_BTN_PIN);
	// Calculate the new state
	if (isPlayPause(readValue)) {
		newState = 1;
	} else if (isNext(readValue)) {
		newState = 2;
	} else if (isPrevious(readValue)) {
		newState = 3;
	} else {
		// Unknown readValue
		// If the buttons are released, the value is 0
		// reset the currentState to zero
		if (readValue == 0) {
			newState = 0;
		}
	}

	// Only act when newState differs from currentState
	if (newState != currentState) {
		// Set the new current state
		currentState = newState;
		switch (currentState) {
			case 1:
				Serial.print("Play button pressed: ");
				break;
			case 2:
				Serial.print("Next button pressed: ");
				break;
			case 3:
				Serial.print("Previous button pressed: ");
				break;
			default:
				break;
		}
		Serial.println(readValue);
	}
}
