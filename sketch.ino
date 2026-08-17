#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

String password = "soilbox";
bool unlocked = false;

const int soilPin = 34;
const int pirPin = 27;

const int greenLED = 16;
const int yellowLED = 17;
const int redLED = 18;

const int buzzer = 25;
const int soilLimit = 30; 
const float tempLimit = 30.0; 

void setup() {
    Serial.begin(9600);
    dht.begin();
    pinMode(pirPin, INPUT);
    pinMode(greenLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    pinMode(redLED, OUTPUT);
    pinMode(buzzer, OUTPUT);
    
    Serial.println("Enter Password in Serial Monitor:");
}

void loop() {
    
    if (!unlocked) {
        if (Serial.available()) {
            String input = Serial.readStringUntil('\n');
            input.trim();
            if (input == password) {
                unlocked = true;
                Serial.println("WELCOME TO SOILBOX");
                digitalWrite(greenLED, HIGH);
                delay(1000);
                digitalWrite(greenLED, LOW);
            } else {
                Serial.println("Wrong Password");
            }
        }
        return;
    }

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    
    int rawSoil = analogRead(soilPin);
    int soilMoisture = map(rawSoil, 0, 4095, 0, 100);
    
    bool motion = digitalRead(pirPin);
    
    bool tempBad = (temperature > tempLimit);
    bool soilBad = (soilMoisture < soilLimit);

  
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    noTone(buzzer);

 
    if (tempBad && soilBad) {
       
        digitalWrite(redLED, HIGH);
        tone(buzzer, 2500);
    } 
    else if (tempBad || soilBad) {
  
        digitalWrite(yellowLED, HIGH);
        tone(buzzer, 1500);
    } 
    else {
        digitalWrite(greenLED, HIGH);
    }

    if (motion) {
        tone(buzzer, 2000);
    }


    Serial.print("Temp: "); Serial.print(temperature);
    Serial.print(" C | Soil: "); Serial.print(soilMoisture);
    Serial.print("% | Motion: "); Serial.println(motion ? "YES" : "NO");

    delay(1000);
}
