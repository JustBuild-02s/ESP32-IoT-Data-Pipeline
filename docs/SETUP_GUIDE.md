# ⚙️ IoT Data Pipeline – Commands Guide

This file contains all terminal commands used in this project.

---

## 🐳 1. Docker Installation Check

```bash
docker --version
```

---

## 🚀 2. Run Test Container

```bash
docker run hello-world
```

---

## 📁 3. Navigate to Project Folder

```bash
cd IoT-Data-Pipeline/docker
```

---

## ▶️ 4. Start All Services (MQTT + InfluxDB + Grafana)

```bash
docker compose up
```

Keep this terminal open.

---

## 🔍 5. Check Running Containers

(Open new terminal)

```bash
docker ps
```

---

## 📡 6. Subscribe to MQTT Messages

```bash
docker exec -it iot-docker-project-mqtt-1 mosquitto_sub -t sensor/object_count
```

You should see live values from ESP32.

---

## 🔄 7. Remove Old Bridge Container (if exists)

```bash
docker rm mqtt-influx-bridge
```

---

## 🌉 8. Create MQTT → InfluxDB Bridge

```bash
docker run -d --name mqtt-influx-bridge --network=iot-docker-project_default alpine sh -c "apk add --no-cache mosquitto-clients curl && mosquitto_sub -h iot-docker-project-mqtt-1 -t sensor/object_count | while read line; do curl -XPOST 'http://iot-docker-project-influxdb-1:8086/write?db=iot_data' --data-binary \"object_count value=$line\"; done"
```

---

## 🔍 9. Verify All Containers Running

```bash
docker ps
```

You should see:

* mqtt
* influxdb
* grafana
* mqtt-influx-bridge

---

## 🌐 10. Open Grafana Dashboard

Open browser:

```bash
http://localhost:3000
```

Login:

* username: admin
* password: admin

---

## 🌐 11. Find Your PC IP Address (Windows)

```bash
ipconfig
```

Look for:

```
IPv4 Address
```

---

## 📡 12. Git Commands (Upload to GitHub)

```bash
git init
git add .
git commit -m "Initial commit - IoT Data Pipeline"
git branch -M main
git remote add origin https://github.com/YOUR_USERNAME/IoT-Data-Pipeline.git
git push -u origin main
```

---

## 🧹 13. Stop Containers (Optional)

```bash
docker compose down
```

---

## 🧠 Notes

* Keep `docker compose up` running while using the system
* Use a new terminal for other commands
* Ensure ESP32 and PC are on same WiFi network

---
