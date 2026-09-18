#ifndef OBSTACLE_DETECT_H
#define OBSTACLE_DETECT_H

#include <Arduino.h>
#include <ESP32Servo.h>
#include <cmath>

#define PI 3.141592653

class Obstacledetect{
  private:
  //Gimabal formation using 2 servos
  // Custom Lidar like simulation
    float thresdist=10.00;
    int verservopin;
    int horservopin;
    int distechopin;
    int disttrigpin;
    Servo VerServo;
    Servo HorServo;
    float (*angularlimits)[2];
    float xdirdist;
    float ydirdist;
    float zdirdist;
    bool obstacle_arr[3]={false,false,false};

  public:
    Obstacledetect(int verservopin,int horservopin, int disttrigpin, int distechopin, float limits[2][2]);
    float distcal();
    void split_in_comp(float distance,float verang,float horang);
    void gimbal_obstacle_detect();
    void check_thres_condition();
};
#endif
