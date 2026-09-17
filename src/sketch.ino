#include "Obstacledetect.h"

float limits[2][2]={{20,140},{30,150}};

#define VERSERVOPIN 16
#define HORSERVOPIN 17

#define ECHOPIN 18
#define TRIGPIN  5

#define SYSTEMPIN 4

Obstacledetect Obd(VERSERVOPIN,HORSERVOPIN,TRIGPIN,ECHOPIN,limits);

void setup(){
  Serial.begin(115200);
  Serial.println("System Initialized");
  pinMode(SYSTEMPIN, OUTPUT);
  digitalWrite(SYSTEMPIN, HIGH);
  delay(2000);
  digitalWrite(SYSTEMPIN,LOW);
}

void loop(){
  Obd.gimbal_obstacle_detect();
}
