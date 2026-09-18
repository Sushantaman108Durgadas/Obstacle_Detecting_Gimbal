#include "Obstacledetect.h"
#include <cmath>

#define PI 3.141592653

Obstacledetect::Obstacledetect(
  int verservopin,
  int horservopin,
  int disttrigpin,
  int distechopin,
  float limits[2][2]
)
{
  this->verservopin = verservopin;
  this->horservopin = horservopin;
  this->disttrigpin = disttrigpin;
  this->distechopin = distechopin;

  angularlimits = limits;

  VerServo.attach(verservopin);
  HorServo.attach(horservopin);

  pinMode(distechopin, INPUT);
  pinMode(disttrigpin, OUTPUT);

  digitalWrite(disttrigpin, LOW);

  Serial.println("Obstacle detection system initialized......");
}
float Obstacledetect::distcal()
{
  digitalWrite(disttrigpin, LOW);
  delay(2);

  digitalWrite(disttrigpin, HIGH);
  delay(10);

  digitalWrite(disttrigpin, LOW);

  float timing = pulseIn(distechopin, HIGH);
  float distance = timing * 0.017;

  return distance;
}
void Obstacledetect::split_in_comp(
  float distance,
  float verang,
  float horang
)
{
  zdirdist = distance * cos(PI * verang / 180);

  float projxy = distance * sin(PI * verang / 180);

  ydirdist = projxy * sin(PI * horang / 180);

  xdirdist = projxy * cos(PI * horang / 180);
}
void Obstacledetect::gimbal_obstacle_detect()
{
  for (
    float i = angularlimits[1][0];
    i <= angularlimits[1][1];
    i += 5.0
  )
  {
    VerServo.write(i);

    for (
      float j = angularlimits[0][0];
      j <= angularlimits[0][1];
      j += 5.0
    )
    {
      HorServo.write(j);

      float distance = distcal();

      Serial.print("Distance in cm @ angles (");
      Serial.print(j);
      Serial.print(",");
      Serial.print(i);
      Serial.print(") is: ");
      Serial.println(distance);

      split_in_comp(distance, i, j);

      check_thres_condition();

      delay(50);
    }
  }
}
void Obstacledetect::check_thres_condition()
{
  if (xdirdist < thresdist)
    obstacle_arr[0] = true;
  else
    obstacle_arr[0] = false;

  if (ydirdist < thresdist)
    obstacle_arr[1] = true;
  else
    obstacle_arr[1] = false;

  if (zdirdist < thresdist)
    obstacle_arr[2] = true;
  else
    obstacle_arr[2] = false;
}
