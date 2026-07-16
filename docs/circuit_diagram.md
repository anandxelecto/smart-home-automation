# 🔌 Circuit Diagram & Wiring Guide

## Pin Connection Table

### ESP32 → Relay Module
| ESP32 Pin | Relay Module Pin |
|---|---|
| GPIO 26 | IN1 (Relay 1) |
| GPIO 27 | IN2 (Relay 2) |
| GPIO 14 | IN3 (Relay 3) |
| GPIO 12 | IN4 (Relay 4) |
| 5V | VCC |
| GND | GND |

### ESP32 → Push Buttons (Manual Override)
| ESP32 Pin | Button |
|---|---|
| GPIO 32 | Button 1 (other leg → GND) |
| GPIO 33 | Button 2 (other leg → GND) |
| GPIO 25 | Button 3 (other leg → GND) |
| GPIO 13 | Button 4 (other leg → GND) |

> Buttons use `INPUT_PULLUP` mode in code, so no external resistor needed.

### ESP32 → DHT11 Sensor
| ESP32 Pin | DHT11 Pin |
|---|---|
| GPIO 4 | Data |
| 3.3V | VCC |
| GND | GND |

---

## ⚠️ Important Safety Notes

- If controlling **AC appliances** (bulbs, fans) through the relay module, ensure:
  - Proper insulation on all AC wiring
  - Relay module is rated for the load (check current rating)
  - Ideally get supervision from someone experienced with mains wiring
- For testing/demo purposes, it's safer to use **DC loads** (LEDs, small DC motors, buzzers) connected via the relay instead of mains AC.

---

## 🖼️ Block Diagram

```
                ┌─────────────────┐
                │      ESP32      │
                │                 │
   DHT11 ───────┤ GPIO4           │
   Button1 ──────┤ GPIO32          │
   Button2 ──────┤ GPIO33          │
   Button3 ──────┤ GPIO25          │
   Button4 ──────┤ GPIO13          │
                │                 │
                │ GPIO26,27,14,12 ├───────┐
                └─────────────────┘       │
                                           ▼
                                 ┌──────────────────┐
                                 │  4-Ch Relay Module│
                                 └────────┬─────────┘
                                          │
                                          ▼
                                 Appliances (Lights/Fan/Plug)
```

Add your own hand-drawn or Fritzing-exported circuit diagram image in the `images/` folder and link it here once ready:

```markdown
![Circuit Diagram](../images/circuit_diagram.png)
```
