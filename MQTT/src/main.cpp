#include <Arduino.h>
#include "WiFi.h"
#include "PubSubClient.h"
// Update these with values suitable for your network.

#define BUILTIN_LED 2
const char* ssid = "Xiaomi_kaylordut";
const char* password = "kaylordut.com";
const char* mqtt_server = "mqtt.kaylordut.com";
const int mqtt_port = 11111;
const char* mqtt_user  = "test";
const char* mqtt_passwd = "test";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  char _msg[length + 1]; 
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    _msg[i]  = (char) payload[i];
  }
   Serial.println();
  Serial.print("msg = ");
  _msg[length] = 0;
  Serial.println(_msg);

  
  if (std::string(_msg) == "ON" || std::string(_msg) == "On" || std::string(_msg) == "on" ) {
    digitalWrite(BUILTIN_LED, HIGH);   

  } else if(std::string(_msg) == "OFF" || std::string(_msg) == "Off" || std::string(_msg) == "off" ){
    digitalWrite(BUILTIN_LED, LOW);  
  }

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str(), mqtt_user, mqtt_passwd)) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");
      // ... and resubscribe
      client.subscribe("inTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;
    snprintf (msg, 50, "hello world #%ld", value);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("outTopic", msg);
  }
}