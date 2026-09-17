<div align="center">

# 🎯 Obstacle Detecting Gimbal

### *2-Axis Gimbal Based Spatial Obstacle Detection System*

**Embedded C++ • ESP32 • Arduino Framework • Wokwi • Servo Control • Ultrasonic Sensing**

[![Stars](https://img.shields.io/github/stars/Sushantaman108Durgadas/Obstacle_Detecting_Gimbal?style=for-the-badge)](https://github.com/Sushantaman108Durgadas/Obstacle_Detecting_Gimbal/stargazers)
[![Forks](https://img.shields.io/github/forks/Sushantaman108Durgadas/Obstacle_Detecting_Gimbal?style=for-the-badge)](https://github.com/Sushantaman108Durgadas/Obstacle_Detecting_Gimbal/network)
[![Issues](https://img.shields.io/github/issues/Sushantaman108Durgadas/Obstacle_Detecting_Gimbal?style=for-the-badge)](https://github.com/Sushantaman108Durgadas/Obstacle_Detecting_Gimbal/issues)
[![License](https://img.shields.io/badge/License-MIT-blue.svg?style=for-the-badge)](LICENSE)

**A 2-axis servo gimbal based obstacle detection system using ESP32,
ultrasonic distance sensing, and Object-Oriented C++**

</div>

---

# 📖 Overview

This project implements a **2-axis gimbal-based obstacle detection system**
using an ESP32.

A distance sensor mounted on the gimbal is positioned using independent
horizontal and vertical servo motors. The system scans a configurable
angular region and measures the distance at each angular position.

The measured distance and corresponding gimbal angles are then used to
determine the spatial position of detected objects.

The project was developed and simulated using **Wokwi** with the
Arduino framework.

---

# 🧠 Working Principle

The system follows a sensing pipeline:

```text
             Horizontal Servo
                    │
                    ▼
             ┌─────────────┐
             │   Distance  │
             │    Sensor   │
             └──────┬──────┘
                    │
             Vertical Servo
                    │
                    ▼
             Angular Position
                    │
                    ▼
            Distance Measurement
                    │
                    ▼
          Coordinate Transformation
                    │
                    ▼
             Obstacle Detection
````

At every gimbal position:

1. The horizontal servo is positioned.
2. The vertical servo is positioned.
3. Distance is measured using the ultrasonic sensor.
4. The measured distance is combined with the gimbal angles.
5. The detected point is converted into Cartesian coordinates.
6. The point is evaluated against the configured threshold.

---

# 🎯 Gimbal Scanning

The scanning region is configurable through a 2D array:

```cpp
float limits[2][2] = {
    {20, 140},   // Horizontal limits
    {30, 150}    // Vertical limits
};
```

The gimbal scans the configured region with a **5° angular step**.

```text
Vertical Angle
      ↑
150°  ─────────────────────────
      •  •  •  •  •  •  •  •
130°  ─────────────────────────
      •  •  •  •  •  •  •  •
110°  ─────────────────────────
      •  •  •  •  •  •  •  •
 90°  ─────────────────────────
      •  •  •  •  •  •  •  •
 70°  ─────────────────────────
      •  •  •  •  •  •  •  •
 50°  ─────────────────────────
      •  •  •  •  •  •  •  •
 30°  ─────────────────────────
      20°                    140°
              Horizontal Angle
```

Each point in the scan represents a specific combination of horizontal
and vertical gimbal angles.

---

# 📐 Coordinate Transformation

The system converts the measured distance and gimbal angles into
Cartesian components.

```text
              Distance + Angles
                     │
                     ▼
             ┌───────────────┐
             │  Coordinate   │
             │ Transformation│
             └───────┬───────┘
                     │
              ┌──────┼──────┐
              ▼      ▼      ▼
              X      Y      Z
```

The transformation uses trigonometric relationships to convert the
sensor measurement from the angular coordinate system into a
3-dimensional Cartesian representation.

This provides spatial information about the detected point rather than
using distance alone.

---

# 🧩 Software Architecture

The project uses an Object-Oriented C++ structure.

```text
                    Obstacledetect
                          │
          ┌───────────────┼───────────────┐
          │               │               │
          ▼               ▼               ▼
   Gimbal Control   Distance Sensing   Spatial Processing
          │               │               │
      ┌───┴───┐           │         Coordinate
      ▼       ▼           ▼         Transformation
   Vertical Horizontal  Ultrasonic        │
    Servo     Servo       Sensor          ▼
                                      X / Y / Z
                                           │
                                           ▼
                                   Obstacle Detection
```

The scanning configuration is passed to the class using a pointer to a
2D array:

```cpp
float (*angularlimits)[2];
```

The pointer allows the class to access the externally defined scanning
limits without creating another copy of the configuration array.

---

# ✨ Features

## 🎯 Gimbal System

* 2-axis servo-based gimbal
* Independent horizontal and vertical positioning
* Configurable angular scanning range
* 5° scanning resolution

---

## 📡 Distance Sensing

* Ultrasonic distance measurement
* Distance calculation from echo pulse duration
* Distance measurement at every gimbal position

---

## 📐 Spatial Processing

* Horizontal and vertical angle tracking
* Spherical-to-Cartesian coordinate conversion
* X, Y and Z spatial components

---

## 🧠 Embedded Software

* Object-Oriented C++
* Modular class-based architecture
* Configurable scanning parameters
* ESP32 Arduino framework

---

# ⚙ Technologies Used

## Hardware

* ESP32
* Servo Motors
* Ultrasonic Distance Sensor

---

## Software

* Embedded C++
* Arduino Framework
* ESP32Servo Library

---

## Simulation

* Wokwi

---

# 🖥️ Simulation

The complete system is simulated using **Wokwi**.

The simulation allows the gimbal movement, sensor measurements and
scanning logic to be tested without requiring physical hardware.

### 🔗 Wokwi Simulation

[Open Wokwi Simulation](YOUR_WOKWI_LINK)

### 🔗 GitHub Repository

[View the Complete Source Code on GitHub](https://github.com/YOUR_USERNAME/Obstacle-Detecting-Gimbal)

---

# 🚀 Getting Started

## Clone the Repository

```bash
git clone https://github.com/YOUR_USERNAME/Obstacle-Detecting-Gimbal.git
```

## Install Required Libraries

The project requires:

* ESP32Servo

## Run the Project

1. Clone the repository.
2. Open the project in an Arduino-compatible development environment.
3. Select the appropriate ESP32 board.
4. Install the required libraries.
5. Compile and upload the program.

For simulation, open the corresponding Wokwi project.

---

# 📂 Project Structure

```text
Obstacle-Detecting-Gimbal/
│
├── src/
│   ├── main.cpp
│   ├── Obstacledetect.cpp
│   └── Obstacledetect.h
│
├── diagram.json
├── wokwi.toml
├── README.md
└── LICENSE
```

---

# 🔮 Future Scope

Possible extensions include:

* Improved distance validation
* Sensor filtering
* Servo position settling
* Persistent scan data
* Direction-based obstacle classification
* Improved spatial mapping
* Integration with mobile robotic platforms

---

# 👤 Author

**Suyash Subodh Shirsat**

---

# 🤝 Contributing

Contributions are welcome.

If you'd like to improve the project:

1. Fork the repository
2. Create a new branch
3. Commit your changes
4. Push the branch
5. Open a Pull Request

---

# 📜 License

This project is licensed under the **MIT License**.

See the **LICENSE** file for details.

---

<div align="center">

### ⭐ If you found this project interesting, consider giving it a star!

*"Good embedded systems begin with understanding the physical world they interact with."*

</div>
```
