#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_WIFI_PASSWORD";

const char* mqtt_server = "YOUR_PC_IP";

WiFiClient espClient;
PubSubClient client(espClient);

#define IR_SENSOR 21

int counter = 0;
int lastState = 1;

void setup() {
  Serial.begin(115200);
  pinMode(IR_SENSOR, INPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");

  client.setServer(mqtt_server, 1883);
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Connecting MQTT...");

    if (client.connect("ESP32Counter")) {
      Serial.println("MQTT connected");
    } else {
      delay(2000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  int state = digitalRead(IR_SENSOR);

  if (state == 0 && lastState == 1) {
    counter++;

    Serial.print("Object Count: ");
    Serial.println(counter);

    String payload = String(counter);
    client.publish("sensor/object_count", payload.c_str());
  }

  lastState = state;

  delay(200);
}
