/*
	Created by Martin Mulder - deFEEST, April 2021
	Released into the public domain
*/

#ifndef SonosButtons_h
#define SonosButtons_h

#include "Arduino.h"

// Define default button ranges
#ifndef PLAY_MIN
#define PLAY_MIN 2580
#endif
#ifndef PLAY_MAX
#define PLAY_MAX 2680
#endif
#ifndef PREV_MIN
#define PREV_MIN 1040
#endif
#ifndef PREV_MAX
#define PREV_MAX 1150
#endif
#ifndef NEXT_MIN
#define NEXT_MIN 1420
#endif
#ifndef NEXT_MAX
#define NEXT_MAX 1530
#endif

#ifndef SONOS_BTN_PIN
#define SONOS_BTN_PIN 13
#endif

class SonosButtons
{
	public:
		SonosButtons(bool debug = false);

		void handle();
		void setup();

	private:
		unsigned long timer_now = 0;
		int readValue = 0;
		int currentState = 0;
		bool isPlaying = false;

		bool _debug;
		void readButtonState();
		bool isPlayPause(int value);
		bool isNext(int value);
		bool isPrevious(int value);

};	

#endif
