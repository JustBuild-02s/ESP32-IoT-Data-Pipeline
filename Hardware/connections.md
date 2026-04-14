# 🔌 Hardware Connections (ESP32 + IR Sensor)

This section explains how to connect the IR sensor to ESP32.

---

## 📦 Components Used

* ESP32
* IR Obstacle Avoidance Sensor
* Jumper Wires

---

## 🔗 Connections Table

| IR Sensor Pin | ESP32 Pin |
| ------------- | --------- |
| VCC           | 3.3V      |
| GND           | GND       |
| OUT           | GPIO 21   |

---

## ⚠️ Important Notes

* Use **3.3V**, NOT 5V (ESP32 can get damaged)
* Ensure proper ground connection
* Sensor OUT pin gives digital signal (0 or 1)

---

## 🧠 Working Logic

* No object → Sensor output = HIGH
* Object detected → Sensor output = LOW
* ESP32 reads this change and increments counter

---

## 🧪 Testing

* Power the ESP32
* Open Serial Monitor
* Move hand in front of sensor
* You should see count increasing

---
