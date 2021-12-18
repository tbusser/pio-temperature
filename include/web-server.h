#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <Arduino.h>
#include <string.h>

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "credentials.h"
#include "config.h"

void startWebServer();

#endif