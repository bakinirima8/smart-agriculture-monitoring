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

![Wokwi Simulation](wokwi-simulation.png)

### Hardware Implementation Concept

![Hardware Implementation Concept](real-life-concept.png)
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
  
  # Author
  Rima Bakini 

## Author
