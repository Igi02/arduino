#include <WiFiS3.h>
#include <WiFiClient.h>

const char* ssid = "DLK";        // WiFi hálózat neve
const char* password = "1RKq<@+MWpdaCWT"; // WiFi jelszó
const char* server = "igi.artidas.hu";  // Szerver címe
const int port = 80;                     // Szerver portja

void setup() {
  Serial.begin(115200);

  // WiFi kapcsolat inicializálása
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  // Adatok
  String created_at = "2024-03-01T12:00"; // Példa datetime-local formátumban
  String temperature = "25.5";             // Példa hőmérséklet
  String humidity = "50";                  // Példa páratartalom

  // HTTP POST kérés létrehozása
  String postData = "created_at=" + created_at + "&temperature=" + temperature + "&humidity=" + humidity;
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
