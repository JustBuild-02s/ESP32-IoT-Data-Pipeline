# 🚀 IoT Data Pipeline using ESP32, Docker, MQTT, InfluxDB & Grafana

An end-to-end IoT system that captures real-time sensor data from ESP32 and visualizes it using a fully containerized backend.

---

## 📌 Overview

This project demonstrates how to build a complete IoT data pipeline:

**IR Sensor → ESP32 → MQTT Broker → InfluxDB → Grafana Dashboard**

It uses Docker to run all backend services, making the setup simple, scalable, and production-ready.

---

## 🧰 Tech Stack

* ESP32 (WiFi-enabled microcontroller)
* MQTT Broker (Eclipse Mosquitto)
* InfluxDB (Time-series database)
* Grafana (Visualization dashboard)
* Docker (Containerization)

---

## ⚙️ Features

* 📡 Real-time object detection using IR sensor
* 🔄 Live data transmission via MQTT
* 📊 Time-series data storage in InfluxDB
* 📈 Interactive dashboards using Grafana
* 🐳 Fully containerized backend

---

## 🐳 Setup Instructions

### 1. Clone the Repository

```bash
git clone https://github.com/YOUR_USERNAME/IoT-Data-Pipeline.git
cd IoT-Data-Pipeline/docker
```

---

### 2. Start Docker Services

```bash
docker compose up
```

This will start:

* MQTT Broker
* InfluxDB
* Grafana

---

### 3. Open Grafana

Go to:

```
http://localhost:3000
```

Login credentials:

* Username: `admin`
* Password: `admin`

---

### 4. Add InfluxDB as Data Source

Fill these details:

* URL: `http://influxdb:8086`
* Database: `iot_data`
* User: `admin`
* Password: `admin123`

Click **Save & Test**

---

## 📡 ESP32 Setup

1. Open `esp32/object_counter.ino`

2. Update:

   * WiFi SSID & Password
   * MQTT Server IP (your PC IP)

3. Upload code to ESP32 using Arduino IDE

---

## 🔍 Verify MQTT Data

Run:

```bash
docker exec -it iot-docker-project-mqtt-1 mosquitto_sub -t sensor/object_count
```

Move your hand in front of the IR sensor.
You should see live values like:

```
1
2
3
4
```

---

## 🌉 MQTT to InfluxDB Bridge

Run:

```bash
docker run -d --name mqtt-influx-bridge --network=iot-docker-project_default alpine sh -c "apk add --no-cache mosquitto-clients curl && mosquitto_sub -h iot-docker-project-mqtt-1 -t sensor/object_count | while read line; do curl -XPOST 'http://iot-docker-project-influxdb-1:8086/write?db=iot_data' --data-binary \"object_count value=$line\"; done"
```

---

## 📊 Visualization in Grafana

* Go to **Dashboard → Create Panel**
* Select InfluxDB data source
* Query:

```
SELECT * FROM object_count
```

You will see real-time graph updates 🎉

---

## 🧠 How It Works

* ESP32 reads IR sensor data
* Sends count via MQTT
* Mosquitto receives messages
* Bridge pushes data into InfluxDB
* Grafana reads and displays data

---

## 🚀 Future Improvements

* ☁️ Deploy on AWS / Azure
* 📱 Mobile dashboard integration
* 🔔 Real-time alerts
* 📦 Add multiple sensors
* 🔐 Secure MQTT communication

---

## 🤝 Contribution

Feel free to fork this repo and improve it.

---

## ⭐ Support

If you like this project, give it a ⭐ on GitHub!
