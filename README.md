# Obstacle Detecting Gimbal

A 2-axis servo gimbal-based obstacle detection system developed using
ESP32 and the Arduino framework and simulated in Wokwi.

The system scans a configurable 2D angular region using two servos and
performs distance measurements at each angular position. The measured
distance and corresponding gimbal angles can then be used to determine
the spatial position of detected obstacles.

## Features

- 2-axis servo-based gimbal
- Configurable horizontal and vertical scanning range
- 5° scanning resolution
- Ultrasonic distance measurement
- Distance-to-coordinate conversion
- Obstacle threshold detection
- Object-oriented C++ implementation
- ESP32 Arduino framework
- Wokwi simulation

## Working Principle

The gimbal consists of:

- Horizontal servo
- Vertical servo
- Ultrasonic distance sensor

The sensor scans the environment by moving through predefined
horizontal and vertical angles.

At each position:

1. The gimbal is positioned at the required angles.
2. Distance is measured using the ultrasonic sensor.
3. The measured distance is combined with the gimbal angles.
4. The detected point is converted into Cartesian coordinates.
5. The coordinates are evaluated against the configured threshold.

```text
        Horizontal Servo
               │
               ▼
        ┌─────────────┐
        │             │
        │   Sensor    │──────► Distance
        │             │
        └──────┬──────┘
               │
        Vertical Servo
               │
               ▼
       Angular Position
               │
               ▼
      Coordinate Conversion
               │
               ▼
      Obstacle Detection