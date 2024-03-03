#include "Arduino_SensorKit.h"
#include <WiFiS3.h>

// Uncomment line below if using DHT20 (black sensor)
#define Environment Environment_I2C

const char* ssid = "DLK";         // WiFi hálózat neve
const char* password = "1RKq<@+MWpdaCWT"; // WiFi jelszó
const char* server = "igi.artidas.hu";    // Szerver címe
const int port = 80;              // Szerver portja

int sound_sensor = A2;            // Assign to pin A2

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Environment.begin();
  Pressure.begin();

  // WiFi kapcsolat inicializálása
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  float temperature = Environment.readTemperature();
  float humidity = Environment.readHumidity();
  int sound = analogRead(sound_sensor);

  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Sound = ");
  Serial.print(sound);
  Serial.println(" 1-1000");

  // Atmospheric pressure and altitude readings
  long pressure = Pressure.readPressure();
  float altitude = Pressure.readAltitude();

  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println(" Pa");

  Serial.print("Altitude = ");
  Serial.print(altitude);
  Serial.println(" m");

  // Adatok
  String postData = "temperature=" + String(temperature) + "&humidity=" + String(humidity) + "&sound=" + String(sound) +
                    "&pressure=" + String(pressure) + "&altitude=" + String(altitude);
  sendPostRequest(postData);

  delay(5000); // 5 másodperc várakozás a következő adatküldés előtt
}

void sendPostRequest(String data) {
  WiFiClient client;

  if (client.connect(server, port)) {
    Serial.println("Connected to server");

    // HTTP POST kérés összeállítása
    String request = "POST /process.php HTTP/1.1\r\n";
    request += "Host: " + String(server) + "\r\n";
    request += "Content-Type: application/x-www-form-urlencoded\r\n";
    request += "Content-Length: " + String(data.length()) + "\r\n";
    request += "\r\n";
    request += data;

    Serial.println("Sending request:");
    Serial.println(request);

    // Kérés küldése a szervernek
    client.print(request);

    delay(1000); // Várakozás a szerver válaszára

    // Szerver válaszának olvasása
    while (client.available()) {
      String response = client.readStringUntil('\r');
      Serial.print(response);
    }

    Serial.println("Request sent");
    client.stop();
  } else {
    Serial.println("Unable to connect to server");
  }
}
