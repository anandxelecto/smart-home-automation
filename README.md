# 🏠 Smart Home Automation System (ESP32 + IoT)

A WiFi-based Smart Home Automation system built using **ESP32**, allowing users to control home appliances (lights, fans, plugs) remotely via a web dashboard, and monitor real-time temperature & humidity data.

![Status](https://img.shields.io/badge/status-active-brightgreen)
![Platform](https://img.shields.io/badge/platform-ESP32-blue)
![License](https://img.shields.io/badge/license-MIT-yellow)

---

## 📌 Features

- 📱 Control up to 4 appliances (relays) from a web dashboard — accessible on any device connected to the same WiFi
- 🌡️ Real-time temperature & humidity monitoring using DHT11 sensor
- 🔄 Manual override supported via physical push buttons (in case WiFi is down)
- 📊 Live sensor data auto-refreshes on the dashboard every 2 seconds
- 🔐 Simple and lightweight — no cloud dependency required (fully local control)
- 💡 Status LEDs indicate which appliance is currently ON

---

## 🛠️ Hardware Required

| Component | Quantity |
|---|---|
| ESP32 Dev Board | 1 |
| 4-Channel Relay Module | 1 |
| DHT11 Temperature & Humidity Sensor | 1 |
| Push Buttons | 4 |
| LEDs (status indicators) | 4 |
| 220Ω Resistors | 4 |
| Breadboard & Jumper Wires | as needed |
| 5V Power Supply | 1 |

> Full wiring/connection table available in [`docs/circuit_diagram.md`](docs/circuit_diagram.md)

---

## ⚙️ Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software) (v1.8.19 or later)
- ESP32 Board Package installed in Arduino IDE
- Required Libraries:
  - `WiFi.h` (built-in with ESP32 core)
  - `WebServer.h` (built-in with ESP32 core)
  - `DHT.h` — [Adafruit DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)

---

## 🚀 Getting Started

1. Clone this repository
   ```bash
   git clone https://github.com/your-username/smart-home-automation.git
   ```
2. Open `src/smart_home_automation.ino` in Arduino IDE
3. Update your WiFi credentials in the code:
   ```cpp
   const char* ssid = "YOUR_WIFI_SSID";
   const char* password = "YOUR_WIFI_PASSWORD";
   ```
4. Select **Board: ESP32 Dev Module** and correct COM Port
5. Upload the code
6. Open Serial Monitor (115200 baud) to find the ESP32's IP address
7. Enter that IP address in any browser on the same network to access the dashboard

---

## 📷 Project Preview

*(Add your own photos/GIFs of the working circuit and dashboard here once built)*

```
images/
  ├── circuit_photo.jpg
  ├── dashboard_screenshot.png
  └── demo.gif
```

---

## 📂 Repository Structure

```
smart-home-automation/
├── src/
│   └── smart_home_automation.ino   # Main ESP32 code
├── docs/
│   └── circuit_diagram.md          # Wiring diagram & pin table
├── images/                         # Photos/screenshots of the build
├── LICENSE
├── .gitignore
└── README.md
```

---

## 🔮 Future Improvements

- [ ] Add mobile app control via Blynk or custom app
- [ ] Voice control integration (Google Assistant / Alexa)
- [ ] Data logging to cloud (Firebase/ThingSpeak)
- [ ] Add scheduling/timer feature for appliances
- [ ] OTA (Over-the-Air) firmware updates

---

## 🤝 Contributing

Suggestions and improvements are welcome! Feel free to fork this repo and submit a pull request.

## 📄 License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

## 👤 Author

Built by Anand Raj — Electronics Engineering Student
Feel free to connect on [LinkedIn](https://www.linkedin.com/in/anand-raj-17b397319?utm_source=share_via&utm_content=profile&utm_medium=member_android) or check out more projects on [Instagram](https://www.instagram.com/core.electro?igsh=MWcwaWU0Z2ozY2tseA==).
