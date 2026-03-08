#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int soilPin = A0;
int pirPin = 3;
int relayPin = 8;

int dryThreshold = 650;
int wetThreshold = 550;

bool pumpState = false;

void setup() {
  Serial.begin(9600);

  pinMode(soilPin, INPUT);
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);

  digitalWrite(relayPin, HIGH);

  dht.begin();
}

void loop() {

  int total = 0;
  for (int i = 0; i < 10; i++) {
    total += analogRead(soilPin);
    delay(10);
  }

  int soilValue = total / 10;

  int motion = digitalRead(pirPin);

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.print("Soil Moisture: ");
  Serial.println(soilValue);

  Serial.print("Temperature: ");
  Serial.println(temperature);

  Serial.print("Humidity: ");
  Serial.println(humidity);

  if (!pumpState && soilValue > dryThreshold) {
    digitalWrite(relayPin, LOW);
    pumpState = true;
    Serial.println("Pump ON");
  }

  if (pumpState && soilValue < wetThreshold) {
    digitalWrite(relayPin, HIGH);
    pumpState = false;
    Serial.println("Pump OFF");
  }

  delay(2000);
}
