#include "config.hpp"

/* ========================================================================== */

void setReadingInterval(int interval);

/**
 * The number of milliseconds between updates of the temperature and humidity.
 * The value should NOT be less than 2000 for the DHT22 sensor.
 */
static int readingUpdateInterval = 30000;

/**
 * Given the width of the screen and the reading update interval we can
 * calculate the number of milliseconds each pixel represents. This becomes the
 * delay for the loop so the progress bar will update smoothly.
 */
static int displayRefreshRate = readingUpdateInterval / SCREEN_WIDTH;

/**
 * Based on the desired interval between sensor readings and how long a loop
 * will wait for the next iteration we can determine the number of iterations we
 * need to skip before refreshing the sensor readings.
 */
static int maxTickCount = readingUpdateInterval / displayRefreshRate;


/* -------------------------------------------------------------------------- */

void setReadingInterval(int interval) {
	readingUpdateInterval = interval;
	displayRefreshRate = interval / SCREEN_WIDTH;
	maxTickCount = interval / displayRefreshRate;
}

/* -------------------------------------------------------------------------- */

int getMaxTickCount() {
	return maxTickCount;
}

int getDisplayRefreshRate() {
	return displayRefreshRate;
}

int getReadingUpdateInterval() {
	return readingUpdateInterval;
}

void updateReadingUpdateInterval(int interval) {
	if (interval < 2000) {
		return;
	}

	setReadingInterval(interval);
}
