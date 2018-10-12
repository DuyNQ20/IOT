// Them thu vien
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include <DHT.h>
#include "index.h"

// Pin
// Su dung cam bien DHT11
#define DHTTYPE DHT22
#define DHTPIN D1
// Thiet lap DHT
DHT dht(DHTPIN, DHTTYPE);

// Thong so WiFi nha ban
const char* ssid = "DESKTOP-BDE4ACL 0105";
const char* password = "12345678";

// Tao server
ESP8266WebServer server(80);

void setup() {

  // Mo Serial
  Serial.begin(115200);
  delay(10);

  // Khoi tao DHT
  dht.begin();

  // Ket noi toi mang WiFi
  //Serial.println();
  //Serial.println();
  Serial.print("Ket noi toi mang ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Da ket noi WiFi");
  
  server.on("/", handleRoot);
  server.on("/temp", temperature);
  server.on("/humi", humidity);
  
  // Khoi dong server
  server.begin();
  Serial.println("Khoi dong Server");

  // In ra dia chi IP
  Serial.println(WiFi.localIP());
  
 
}

void loop(void){
  server.handleClient();          //Handle client requests
}

void handleRoot()
{
  String s = MAIN_page; //Doc trang HTML
  server.send(200, "text/html", s); // Gui HTML den client
}

void temperature()
{
    int temp = dht.readTemperature();
    server.send(200, "text/plane", String(temp));
}

void humidity()
{
    int humi = dht.readHumidity();
    server.send(200, "text/plane", String(humi));
}
