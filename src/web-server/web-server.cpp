/* =============================================================================

Ensure there is a credentials.h file present which defines WIFI_SSID
and WIFI_PASSWORD. Without this file the project won't build.

============================================================================= */

#include "web-server.h"

/* ========================================================================== */

String processor(const String& var);

/* ========================================================================== */

const char* valuePlaceholder = "VALUE_PLACEHOLDER";
const char* intervalParam = "interval";

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8"/>
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>Alarm clock config</title>
	<style>label { display: block; } input { width: 100vw; } button {margin-top: 1.5em;}</style>
</head>
<body>
<h1>Settings</h1>
<form action="/set">
	<div>
		<label>Refresh interval: <span id="display"></span></label>
		<input id="interval" name="interval" type="range" min="2" max="120" value="%VALUE_PLACEHOLDER%" list="tickmarks">
		<datalist id="tickmarks">
			<option value="2" label="2s"></option>
			<option value="30"></option>
			<option value="60"></option>
			<option value="90"></option>
			<option value="120" label="2m"></option>
		</datalist>
	</div>
	<button>Set</button>
</form>
<script>
const input = document.getElementById('interval');
const display = document.getElementById('display');
function updateInterval(interval) {
	display.textContent = `${interval}s`;
}
input.addEventListener('input', event => {
	updateInterval(event.target.value);
});
updateInterval(input.value);
</script>
</body>
</html>
)rawliteral";

/* -------------------------------------------------------------------------- */

AsyncWebServer server(80);

/* -------------------------------------------------------------------------- */

String processor(const String& var) {
	Serial.println(var);
	Serial.println(String(getReadingUpdateInterval() / 1000));
	if (var == "VALUE_PLACEHOLDER") {
		return String(getReadingUpdateInterval() / 1000);
	}

	return String();
}

void startWebServer() {
	Serial.print(F("Connecting to "));
	Serial.print(WIFI_SSID);

	WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(F("."));
	}

	Serial.println(F(""));
	Serial.println(WiFi.localIP());

	server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
		request->send_P(200, "text/html", index_html, processor);
	});

	server.on("/set", HTTP_GET, [](AsyncWebServerRequest *request) {
		Serial.println("Handling post");

		String value;
		if (request->hasParam(intervalParam)) {
			value = request->getParam(intervalParam)->value();
			Serial.print(F("Updating reading interval: "));
			Serial.println(value.toInt() * 1000);
			updateReadingUpdateInterval(value.toInt() * 1000);
		}

		request->send_P(200, "text/html", index_html, processor);
	});

	server.begin();
}
