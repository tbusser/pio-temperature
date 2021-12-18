#ifndef CONFIG_H
#define CONFIG_H

/* -------------------------------------------------------------------------- */

#define DHT_PIN 4
#define DHT_TYPE DHT22

/* -------------------------------------------------------------------------- */

#define SCREEN_ADDRESS 0x3C
#define SCREEN_HEIGHT 64
#define SCREEN_RESET -1
#define SCREEN_WIDTH 128

/* -------------------------------------------------------------------------- */

/**
 * @brief Returns the number of loops needed between sensor reading refreshes.
 *
 * @return int
 */
int getMaxTickCount();

/**
 * @brief Returns the number of milliseconds to delay the loop to ensure a
 *        smooth running progress bar.
 *
 * @return int
 */
int getDisplayRefreshRate();

/**
 * @brief Returns the number of milliseconds to wait between updating the
 *        temperature and humidity readings.
 *
 * @return int
 */
int getReadingUpdateInterval();

void updateReadingUpdateInterval(int interval);

#endif