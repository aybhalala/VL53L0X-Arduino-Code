/*
============================================================================
Created by Aditya Patel
Email: me@pateladitya.com
Year 2018
================================================================================
*/
#include <Wire.h>
#include <VL53L0X.h>

#define XSHUT_pin1 5 //connect sensor 1 XSHUT pin to arduino D5
#define XSHUT_pin2 6 //connect sensor 2 XSHUT pin to arduino D6
#define XSHUT_pin3 7 //connect sensor 3 XSHUT pin to arduino D7

#define Sensor1_newAddress 42
#define Sensor2_newAddress 43
#define Sensor3_newAddress 45

VL53L0X Sensor1;
VL53L0X Sensor2;
VL53L0X Sensor3;


void setup() {
 pinMode(XSHUT_pin1, OUTPUT);
 pinMode(XSHUT_pin2, OUTPUT);
 pinMode(XSHUT_pin3, OUTPUT);

 Serial.begin(9600);
 Wire.begin();

 pinMode(XSHUT_pin1, INPUT);
 delay(10);
 Sensor1.setAddress(Sensor1_newAddress);
 pinMode(XSHUT_pin2, INPUT);
 delay(10);
 Sensor2.setAddress(Sensor2_newAddress);
 pinMode(XSHUT_pin3, INPUT);
 delay(10);
 Sensor3.setAddress(Sensor3_newAddress);
 delay(10);

 Sensor1.init();
 Sensor2.init();
 Sensor3.init();
 Sensor1.setTimeout(500);
 Sensor2.setTimeout(500);
 Sensor3.setTimeout(500);
 Sensor1.startContinuous();
 Sensor2.startContinuous();
 Sensor3.startContinuous();

}

void loop() {
  Serial.print(Sensor1.readRangeContinuousMillimeters());
  Serial.println("    sensor 1");
  delay(500);
  Serial.print(Sensor2.readRangeContinuousMillimeters());
  Serial.println("    sensor 2");
  delay(500);
  Serial.print(Sensor3.readRangeContinuousMillimeters());
  Serial.println("    sensor 3");
  delay(500);

}
