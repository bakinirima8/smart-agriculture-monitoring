# Smart Agriculture Monitoring System

An ESP32-based smart agriculture monitoring system designed to monitor environmental conditions and simulate soil moisture levels using Wokwi.

## Project Overview

This project uses an ESP32 to collect information from different sensors and provide visual and audible alerts based on the detected conditions.

The system monitors:

- Temperature
- Humidity
- Soil moisture level
- Motion detection

Three LEDs are used to indicate the general condition of the environment, while a buzzer provides alerts when necessary.

For the Wokwi simulation, a potentiometer is used to simulate the output of a soil-moisture sensor.
## Project Preview

### Wokwi Simulation

![Wokwi Simulation](wokwi_simulation.png)

### Hardware Implementation Concept

![real life simulation](real_life_simulation.png)

## Components

- ESP32 DevKit
- DHT22 temperature and humidity sensor
- PIR motion sensor
- Potentiometer (soil-moisture simulation)
- Green LED
- Yellow LED
- Red LED
- 3 × 220Ω resistors
- Buzzer
## Testing and Results

The system was tested under different environmental and security conditions to verify the behavior of the sensors, LEDs, buzzer, and password system.

### 1. Password Authentication

The system requires a password before monitoring begins.

- Incorrect password → access denied
- Correct password → system unlocked and displays "WELCOME TO SOILBOX"

![Password Authentication](password-authentification.png)

### 2. temperature Condition 


**Test values:**
- Temperature: 80.0°C
- Soil moisture: 50%
- Motion: No
  
Expected behavior:
- Red LED turns ON
- Buzzer is activated
- Temperature is displayed in the Serial Monitor

![High Temperature Test](critical-alert.png)

### 4 .Soil Moisture condition

![Soil Moisture Test](warning-alert.png)

The potentiometer is used to simulate the soil moisture sensor. When the soil moisture level falls below 30%, the system detects dry soil.

Expected behavior:
- Soil moisture < 30% → dry soil detected
-  Yellow LED turns ON
-  Buzzer is activated
- The soil moisture value is displayed in the Serial Monitor


### 3. Normal Environmental Conditions

The temperature was set to approximately 21°C and soil moisture to 50%.

**Test values:**
- Temperature: 21.4°C
- Soil moisture: 50%
- Motion: No

Expected behavior:
- Green LED turns ON
- No alarm
- Sensor values are displayed in the Serial Monitor

![Normal Conditions](normal-conditions.png)

### 4. Motion Detection

The PIR sensor was triggered using the simulation controls.

Expected behavior:
- Motion is detected
- Buzzer is activated
- Serial Monitor displays `Motion: YES`

![Motion Detection](motion-alert.png)

## Conclusion

The simulation successfully demonstrates an ESP32-based smart agriculture monitoring system capable of monitoring temperature, soil moisture and motion. The system provides visual and audible alerts when abnormal conditions are detected.
## Pin Configuration

| Component | ESP32 GPIO |
|---|---:|
| DHT22 Data | GPIO 4 |
| PIR OUT | GPIO 27 |
| Soil Moisture / Potentiometer | GPIO 34 |
| Buzzer | GPIO 25 |
| Green LED | GPIO 16 |
| Yellow LED | GPIO 17 |
| Red LED | GPIO 18 |

## System Logic

The ESP32 continuously reads the sensors and evaluates the environmental conditions.

### Soil Moisture

- Green LED → normal soil condition
- Yellow LED → warning condition
- Red LED → dry soil condition

The soil moisture value is simulated using the potentiometer and converted into a percentage.

### Temperature

A temperature above 30°C is considered a high-temperature condition.

### Motion

The PIR sensor detects movement and activates an audible alert.

### Combined Conditions

| Condition | LED | Buzzer |
|---|---|---|
| Normal | 🟢 Green | OFF |
| Temperature high OR soil dry | 🟡 Yellow | ON |
| Temperature high AND soil dry | 🔴 Red | ON |
| Motion detected | Current status | Motion alert |

## Security

The system starts with a simple password-protection mechanism.

The password used in the simulation is:

`soilbox`

The monitoring system starts after the correct password is entered through the Serial Monitor.

## Simulation

The project was developed and tested using Wokwi.

The Wokwi simulation files are included in this repository:

- `diagram.json` — circuit configuration
- `sketch.ino` — ESP32 firmware

## Testing

The system was tested by changing the potentiometer value to simulate different soil-moisture levels and by changing the environmental conditions in the simulation.

The following functions were tested:

- DHT22 temperature readings
- DHT22 humidity readings
- Soil-moisture simulation
- PIR motion detection
- Green, yellow and red LED indicators
- Buzzer alerts
- Password protection
- Serial Monitor output

## Limitations
The current version is a simulation. The potentiometer is used instead of a physical soil-moisture sensor.

The system does not currently control a real irrigation pump or provide remote monitoring.

## Future Improvements
Possible improvements include:

- Replace the potentiometer with a real capacitive soil-moisture sensor
- Add automatic irrigation using a water pump
- Add a relay or MOSFET-based pump control
- Connect the ESP32 to Wi-Fi
- Create a web or mobile monitoring dashboard
- Store sensor measurements for later analysis
- Add notifications when the soil becomes too dry

## Technologies

- ESP32
- C++
- Arduino framework
- Wokwi
- DHT22
- PIR sensor
- ADC
 - Embedded systems

## Testing and Results

The system was tested in the Wokwi simulation under different conditions to verify the behavior of the sensors, LEDs, buzzer, and password authentication.

### 1. Password Authentication

The system starts by requesting a password through the Serial Monitor.

The correct password unlocks the monitoring system and displays a welcome message.

**Expected behavior:**
- Correct password → system unlocked
- Incorrect password → access denied
- Green LED briefly turns ON after successful authentication

![Password Authentication](password_authentification.png)

---

### 2. Normal Conditions

The system was tested under normal environmental conditions.

**Test values:**
- Temperature: 21.4°C
- Soil moisture: 50%
- Motion: No

**Expected behavior:**
- 🟢 Green LED turns ON
- Buzzer remains OFF
- Sensor readings are displayed in the Serial Monitor

![Normal Conditions](normal_conditions.png)

---

### 3. Soil Moisture Test

The potentiometer is used to simulate the soil-moisture sensor in the Wokwi environment.

When the soil moisture falls below the 30% threshold, the system detects a dry-soil condition.

**Expected behavior:**
- Soil moisture below 30% → dry soil detected
- 🟡 Yellow LED turns ON when temperature is normal
- 🔊 Buzzer is activated
- Soil moisture value is displayed in the Serial Monitor

![Soil Moisture Test](soil_test.png)

---

### 4. Warning Alert

The system was tested with one environmental condition exceeding its defined limit.

**Expected behavior:**
- One abnormal condition is detected
- 🟡 Yellow LED turns ON
- 🔊 Buzzer is activated
- Sensor values are displayed in the Serial Monitor

![Warning Alert](warning_alert.png)

---

### 5. Critical Alert

The system was tested with both high temperature and low soil moisture at the same time.

**Expected behavior:**
- High temperature is detected
- Dry soil is detected
- 🔴 Red LED turns ON
- 🔊 Buzzer produces a critical alert
- Sensor values are displayed in the Serial Monitor

![Critical Alert](critical_alert.png)

---

### 6. Motion Detection

The PIR sensor was tested by simulating movement in the Wokwi environment.

**Expected behavior:**
- Motion is detected
- Serial Monitor displays `Motion: YES`
- 🔊 Buzzer is activated
- The LED continues to indicate the current environmental condition

![Motion Detection](motion_alert.png)

---

## Test Summary

| Test | Condition | Expected Result |
|---|---|---|
| Password Authentication | Correct/incorrect password | Access granted or denied |
| Normal Conditions | Normal temperature and soil moisture | 🟢 Green LED |
| Soil Moisture | Soil moisture below 30% | 🟡 Yellow LED + buzzer |
| Warning Alert | One abnormal condition | 🟡 Yellow LED + buzzer |
| Critical Alert | High temperature + dry soil | 🔴 Red LED + buzzer |
| Motion Detection | PIR detects movement | 🔊 Buzzer alert |

## Conclusion

The Wokwi simulation successfully demonstrated the main functions of the Smart Agriculture Monitoring System. The ESP32 was able to read environmental data, evaluate soil moisture and temperature conditions, detect motion, and provide visual and audible alerts based on the detected conditions.


  
  # Author
  Rima Bakini 

## Author
