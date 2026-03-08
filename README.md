# Automatic Water Monitoring System (Arduino)

## Overview
This project is an automatic irrigation system built using an Arduino Uno.  
The system monitors soil moisture and automatically controls a water pump using a relay module. When the soil becomes dry, the pump turns ON, and when the soil is wet, the pump turns OFF.

## Components
- Arduino UNO  
- Soil Moisture Sensor  
- DHT11 Temperature & Humidity Sensor  
- PIR Motion Sensor  
- Relay Module (5V)  
- Water Pump  
- External Power Supply  

## Working Principle
1. The soil moisture sensor measures the moisture level.
2. Arduino reads the sensor value through an analog pin.
3. If the soil is dry, Arduino activates the relay.
4. The relay turns ON the water pump.
5. When the soil becomes wet, the relay turns OFF the pump.

## Wiring Summary
Relay Control Side  
- VCC → Arduino 5V  
- GND → Arduino GND  
- IN → Arduino Pin 8  

Pump Circuit  
- External Power + → Relay COM  
- Relay NO → Pump +  
- Pump − → External Power −  

Important: External power ground is connected to Arduino GND.

## Future Improvements
- IoT monitoring
- Mobile app control
- Data logging
