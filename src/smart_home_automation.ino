/*
  Smart Home Automation System
  Board: ESP32 Dev Module
  Author: Your Name

  Description:
  Controls 4 relays (appliances) via a web dashboard hosted on the ESP32,
  and displays live temperature & humidity from a DHT11 sensor.
  Physical push buttons act as manual override switches.
*/

#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

// ---------- WiFi Credentials ----------
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// ---------- Pin Definitions ----------
#define RELAY1 26
#define RELAY2 27
#define RELAY3 14
#define RELAY4 12

#define BUTTON1 32
#define BUTTON2 33
#define BUTTON3 25
#define BUTTON4 13

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
WebServer server(80);

bool relayState[4] = {false, false, false, false};
int relayPins[4] = {RELAY1, RELAY2, RELAY3, RELAY4};
int buttonPins[4] = {BUTTON1, BUTTON2, BUTTON3, BUTTON4};

// ---------- Web Dashboard HTML ----------
String getDashboardHTML() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  String html = "<!DOCTYPE html><html><head><title>Smart Home Dashboard</title>";
  html += "<meta http-equiv='refresh' content='2'>";
  html += "<style>body{font-family:Arial;text-align:center;background:#f2f2f2;}";
  html += "h1{color:#333;} .btn{padding:15px 30px;margin:10px;font-size:18px;border:none;border-radius:8px;cursor:pointer;}";
  html += ".on{background:#4CAF50;color:white;} .off{background:#f44336;color:white;}";
  html += ".sensor{margin-top:30px;font-size:20px;color:#555;}</style></head><body>";
  html += "<h1>🏠 Smart Home Dashboard</h1>";

  for (int i = 0; i < 4; i++) {
    html += "<div>Appliance " + String(i + 1) + ": ";
    html += "<a href='/toggle?relay=" + String(i) + "'>";
    html += "<button class='btn " + String(relayState[i] ? "on" : "off") + "'>";
    html += relayState[i] ? "ON" : "OFF";
    html += "</button></a></div>";
  }

  html += "<div class='sensor'>🌡️ Temperature: " + String(temp) + " °C</div>";
  html += "<div class='sensor'>💧 Humidity: " + String(hum) + " %</div>";
  html += "</body></html>";
  return html;
}

// ---------- Route Handlers ----------
void handleRoot() {
  server.send(200, "text/html", getDashboardHTML());
}

void handleToggle() {
  if (server.hasArg("relay")) {
    int r = server.arg("relay").toInt();
    if (r >= 0 && r < 4) {
      relayState[r] = !relayState[r];
      digitalWrite(relayPins[r], relayState[r] ? HIGH : LOW);
    }
  }
  server.sendHeader("Location", "/");
  server.send(303);
}

// ---------- Setup ----------
void setup() {
  Serial.begin(115200);
  dht.begin();

  for (int i = 0; i < 4; i++) {
    pinMode(relayPins[i], OUTPUT);
    digitalWrite(relayPins[i], LOW);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected!");
  Serial.print("Dashboard IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/toggle", handleToggle);
  server.begin();
}

// ---------- Main Loop ----------
void loop() {
  server.handleClient();

  // Manual override via physical push buttons
  for (int i = 0; i < 4; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      relayState[i] = !relayState[i];
      digitalWrite(relayPins[i], relayState[i] ? HIGH : LOW);
      delay(300); // simple debounce
    }
  }
}
