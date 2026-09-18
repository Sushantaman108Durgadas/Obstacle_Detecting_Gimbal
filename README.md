<div align="center">

# 🎯 Obstacle Detecting Gimbal

### *2-Axis Gimbal Based Spatial Obstacle Detection System*

**Embedded C++ • ESP32 • Arduino Framework • Wokwi • Servo Control • Ultrasonic Sensing**

[![Stars](https://img.shields.io/github/stars/Sushantaman108Durgadas/Obstacle_Detecting_Gimbal?style=for-the-badge)](https://github.com/Sushantaman108Durgadas/Obstacle_Detecting_Gimbal/stargazers)
[![Forks](https://img.shields.io/github/forks/Sushantaman108Durgadas/Obstacle_Detecting_Gimbal?style=for-the-badge)](https://github.com/Sushantaman108Durgadas/Obstacle_Detecting_Gimbal/network)
[![Issues](https://img.shields.io/github/issues/Sushantaman108Durgadas/Obstacle_Detecting_Gimbal?style=for-the-badge)](https://github.com/Sushantaman108Durgadas/Obstacle_Detecting_Gimbal/issues)
[![License](https://img.shields.io/badge/License-MIT-blue.svg?style=for-the-badge)](LICENSE)

**A 2-axis servo gimbal based spatial obstacle detection system using
ESP32, ultrasonic distance sensing, and Object-Oriented C++**

</div>

---

# 📖 Overview

This project implements a **2-axis gimbal-based spatial obstacle detection
system** using an ESP32.

An ultrasonic distance sensor mounted on the gimbal is positioned using
independent horizontal and vertical servo motors. The system scans a
configurable angular region and measures the distance at each angular
position.

The measured distance and corresponding gimbal angles are then used to
determine the spatial position of detected objects through
**coordinate transformation**.

The project is developed using **Embedded C++ with the Arduino framework**
and can be tested using the **Wokwi simulation environment**.

The repository also includes a reproducible **VS Code + Arduino CLI + Wokwi**
development setup for building and testing the firmware locally.

---

# 🧠 Working Principle

The system follows a spatial sensing pipeline:

```text
                 2-Axis Gimbal
                      │
                      ▼
              ┌──────────────┐
              │    Angular   │
              │   Position   │
              └──────┬───────┘
                     │
                     ▼
             Ultrasonic Sensor
                     │
                     ▼
             Distance Measurement
                     │
                     ▼
          Coordinate Transformation
                     │
                     ▼
                  X / Y / Z
                     │
                     ▼
             Obstacle Detection
````

At every gimbal position:

1. The horizontal servo is positioned.
2. The vertical servo is positioned.
3. The ultrasonic sensor measures the distance.
4. The measured distance is combined with the gimbal angles.
5. The measurement is converted into Cartesian coordinates.
6. The resulting spatial information is evaluated against the configured
   obstacle threshold.

---

# 🎯 Gimbal Scanning

The scanning region is configurable through a 2D array:

```cpp
float limits[2][2] = {
    {20, 140},   // Horizontal limits
    {30, 150}    // Vertical limits
};
```

The gimbal scans the configured region using a **5° angular step**.

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

Each scan point represents a specific combination of horizontal and
vertical gimbal angles.

This allows the system to obtain spatial measurements across an angular
region rather than relying on a single fixed distance measurement.

---

# 📐 Coordinate Transformation

The system converts the measured distance and gimbal angles into
Cartesian components.

Let:

* `r` = measured distance
* `θ` = vertical angle
* `φ` = horizontal angle

The current implementation calculates:

$$
z = r\cos(\theta)
$$

$$
r_{xy} = r\sin(\theta)
$$

$$
x = r_{xy}\cos(\phi)
$$

$$
y = r_{xy}\sin(\phi)
$$

Therefore:

$$
x = r\sin(\theta)\cos(\phi)
$$

$$
y = r\sin(\theta)\sin(\phi)
$$

$$
z = r\cos(\theta)
$$

The resulting `(x, y, z)` values represent the detected point relative to
the sensor/gimbal coordinate frame.

This spatial representation provides the foundation for future
**environment mapping and robotic perception**.

---

# 🧩 Software Architecture

The project uses an **Object-Oriented C++ architecture** to separate the
main firmware entry point from the gimbal and sensing logic.

<p align="center">
  <img
    src="https://raw.githubusercontent.com/Sushantaman108Durgadas/Obstacle_Detecting_Gimbal/main/utils/architecture.png"
    alt="Obstacle Detecting Gimbal Architecture"
    width="750"
  >
</p>

The primary firmware entry point starts the Arduino lifecycle and invokes
the obstacle detection system.

The `Obstacledetect` class is responsible for:

* Servo positioning
* Ultrasonic triggering
* Distance measurement
* Angular scanning
* Coordinate transformation
* Obstacle condition processing

The project separates the main firmware from the detection logic:

```text
main/
└── sketch.ino

Obstacledetect/
├── Obstacledetect.cpp
└── Obstacledetect.h
```

---

# 🧮 Scanning Configuration

The scanning limits are passed to the `Obstacledetect` class using a
pointer to a 2D array:

```cpp
float (*angularlimits)[2];
```

The main firmware defines the actual configuration array:

```cpp
float limits[2][2] = {
    {20, 140},
    {30, 150}
};
```

The array is passed to the class, where the pointer provides access to
the same configuration.

This allows the scanning range to be configured externally without
creating another copy of the configuration array.

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
* Echo pulse duration based distance calculation
* Distance measurement at every gimbal position

---

## 📐 Spatial Processing

* Horizontal and vertical angle tracking
* Spherical-to-Cartesian coordinate transformation
* X, Y and Z spatial components
* Spatial representation of detected points

---

## 🧠 Embedded Software

* Object-Oriented C++
* Modular class-based architecture
* Configurable scanning parameters
* ESP32 Arduino framework
* Separate firmware entry point and detection library

---

## 🧪 Simulation

* Complete Wokwi simulation
* Simulated ESP32
* Simulated servo actuators
* Simulated ultrasonic sensing
* Serial diagnostic output

---

# ⚙️ Technologies Used

## Hardware

* ESP32
* Servo Motors
* Ultrasonic Distance Sensor

---

## Software

* Embedded C++
* Arduino Framework
* ESP32Servo Library
* Arduino CLI

---

## Simulation & Development

* Wokwi
* Visual Studio Code
* Wokwi for VS Code
* Arduino CLI

---

# 🖥️ Simulation

The system can be simulated using **Wokwi**, allowing the gimbal movement,
ultrasonic sensing, scanning logic, and spatial calculations to be tested
without requiring physical hardware.

### 🔗 Wokwi Simulation

[Open Wokwi Simulation](https://wokwi.com/projects/439553500260642817)

### 🔗 GitHub Repository

[View the Complete Source Code](https://github.com/Sushantaman108Durgadas/Obstacle_Detecting_Gimbal)

---

# 🚀 Getting Started

There are two ways to work with this project:

1. **Run the existing Wokwi simulation**
2. **Build and run the project locally using VS Code**

---

# 🌐 Run the Wokwi Simulation

The project can be simulated directly using Wokwi.

The simulation contains:

* ESP32 development board
* Two servo motors
* Ultrasonic distance sensor
* Required connections
* Project firmware configuration

### 🔗 Open the Simulation

[Open Wokwi Simulation](https://wokwi.com/projects/439553500260642817)

---

# 💻 Build the Project in VS Code

A dedicated local development setup is provided in:

```text
vscode-wokwi-setup/
```

This directory contains the files required to reproduce the local
**VS Code + Arduino CLI + Wokwi** workflow.

```text
vscode-wokwi-setup/
├── README.md
├── diagram.json
├── libraries.txt
├── Obstacledetect.cpp
├── Obstacledetect.h
├── ObstacleDetectingGimbal.ino
├── wokwi-project.txt
└── wokwi.toml
```

The detailed setup instructions are available in:

```text
vscode-wokwi-setup/README.md
```

---

## 1️⃣ Install Visual Studio Code

Install **Visual Studio Code**.

Install the following extension:

* **Wokwi for VS Code**

This extension is used to run the hardware simulation locally.

---

## 2️⃣ Install Arduino CLI

Arduino CLI is used to compile the ESP32 firmware.

Verify the installation:

```powershell
arduino-cli version
```

---

## 3️⃣ Configure the ESP32 Arduino Core

Initialize the Arduino CLI configuration:

```powershell
arduino-cli config init
```

Add the ESP32 board package repository:

```powershell
arduino-cli config add board_manager.additional_urls https://espressif.github.io/arduino-esp32/package_esp32_index.json
```

Update the board index:

```powershell
arduino-cli core update-index
```

Install the ESP32 Arduino Core:

```powershell
arduino-cli core install esp32:esp32
```

---

## 4️⃣ Install the Required Library

Install the `ESP32Servo` library:

```powershell
arduino-cli lib install ESP32Servo
```

The required library is also listed in:

```text
libraries.txt
```

---

## 5️⃣ Open the Setup Folder in VS Code

Open the following directory as the VS Code workspace:

```text
vscode-wokwi-setup/
```

Make sure the integrated terminal is opened inside this directory.

---

## 6️⃣ Configure VS Code Debugging

If using the provided VS Code debugging configuration, open:

```text
.vscode/launch.json
```

Some values in `launch.json` are **machine-specific**.

Replace the required project paths with paths corresponding to your own
local project directory.

For example:

```json
"cwd": "YOUR_PROJECT_PATH",
"program": "YOUR_PROJECT_PATH/build/..."
```

> ⚠️ Do not copy another user's absolute Windows paths directly.
> Replace machine-specific paths before running the configuration.

No passwords, API keys, tokens, or other secrets should be placed inside
`launch.json`.

---

## 7️⃣ Build the Firmware

Run the following command from inside the
`vscode-wokwi-setup/` directory:

```powershell
arduino-cli compile --fqbn esp32:esp32:esp32 --output-dir build .
```

Arduino CLI will compile:

* `ObstacleDetectingGimbal.ino`
* `Obstacledetect.cpp`
* `Obstacledetect.h`
* Required Arduino and ESP32 libraries

A successful build generates firmware artifacts inside:

```text
build/
```

These generated files are used by the Wokwi configuration.

---

## 8️⃣ Run the Wokwi Simulation

After a successful build, open:

```text
diagram.json
```

using the Wokwi extension.

The `wokwi.toml` file specifies the compiled firmware and ELF files
required by the simulation.

Start the simulation and monitor the generated measurements through the
Serial Monitor.

---

# 🔄 Development Workflow

The local development workflow can be summarized as:

```text
              Source Code
                   │
                   ▼
          Visual Studio Code
                   │
                   ▼
              Arduino CLI
                   │
                   ▼
           ESP32 Compilation
                   │
                   ▼
                build/
             ┌─────┴─────┐
             │           │
           .bin         .elf
             │           │
             └─────┬─────┘
                   ▼
             Wokwi Simulation
                   │
                   ▼
             Serial Monitor
```

The `build/` directory contains generated compilation artifacts and
should not be committed to the repository.

---

# 📘 Detailed VS Code Setup

For the complete setup instructions covering:

* Arduino CLI installation
* ESP32 Arduino Core installation
* ESP32Servo installation
* VS Code configuration
* Wokwi for VS Code
* `wokwi.toml`
* `launch.json`
* Machine-specific path configuration
* Firmware compilation
* Running the simulation
* Troubleshooting

see:

```text
vscode-wokwi-setup/README.md
```

The setup directory is intended to make the development environment
reproducible while keeping generated build files and machine-specific
paths separate from the primary project source.

---

# 📂 Project Structure

```text
Obstacle_Detecting_Gimbal/
│
├── LICENSE
│
├── utils/
│   └── architecture.png
│
├── src/
│   ├── README.md
│   ├── diagram.json
│   ├── libraries.txt
│   ├── wokwi-project.txt
│   │
│   ├── main/
│   │   └── sketch.ino
│   │
│   └── Obstacledetect/
│       ├── Obstacledetect.cpp
│       └── Obstacledetect.h
│
└── vscode-wokwi-setup/
    ├── README.md
    ├── diagram.json
    ├── libraries.txt
    ├── Obstacledetect.cpp
    ├── Obstacledetect.h
    ├── ObstacleDetectingGimbal.ino
    ├── wokwi-project.txt
    └── wokwi.toml
```

---

## 📁 `src/`

Contains the primary project source code and associated Wokwi project
files.

---

## 📁 `src/main/`

Contains the main Arduino firmware entry point:

```text
src/main/sketch.ino
```

This file is responsible for system initialization and starting the
obstacle detection process.

---

## 📁 `src/Obstacledetect/`

Contains the reusable obstacle detection implementation:

```text
Obstacledetect/
├── Obstacledetect.cpp
└── Obstacledetect.h
```

The class handles:

* Gimbal scanning
* Servo control
* Distance sensing
* Coordinate transformation
* Obstacle condition processing

---

## 📁 `utils/`

Contains supporting project documentation and visual assets.

```text
utils/
└── architecture.png
```

The architecture diagram provides a visual representation of the
firmware and hardware interaction.

---

## 📁 `vscode-wokwi-setup/`

Contains a self-contained local development and simulation environment.

It is intended to make the **VS Code + Arduino CLI + Wokwi** workflow
reproducible without mixing generated build files or machine-specific
paths into the primary source structure.

---

# 🔮 Future Scope

The current system provides the sensing and spatial-processing foundation
for more advanced robotic applications.

## 📡 Sensing Improvements

* Improved distance validation
* Sensor noise filtering
* Multiple measurements per scan point
* Improved ultrasonic measurement handling
* Servo position settling

---

## 🗺️ Spatial Mapping

* Persistent scan data
* Direction-based obstacle classification
* Occupancy/grid-based mapping
* Temporal weighting of map observations
* 3D spatial representation
* Environment reconstruction

---

## 🤖 Mobile Robotics

* Integration with a mobile robotic platform
* Robot pose estimation
* Wheel encoder based odometry
* IMU-based orientation estimation
* Sensor fusion
* Autonomous obstacle avoidance

---

## 🚀 Advanced Robotics

The spatial sensing system can eventually serve as a perception component
for a larger autonomous robotic system.

Potential future technologies include:

* ROS 2
* Localization
* Scan matching
* SLAM
* Autonomous navigation

---

# 👤 Author

**Suyash Subodh Shirsat**

Electronics & Telecommunication Engineering

**Embedded Systems • Firmware • Robotics • IoT**

---

# 🤝 Contributing

Contributions, improvements, and suggestions are welcome.

If you'd like to improve the project:

1. Fork the repository
2. Create a new branch
3. Commit your changes
4. Push the branch
5. Open a Pull Request

For major changes, please open an issue first to discuss the proposed
modification.

---

# 📜 License

This project is licensed under the **MIT License**.

See the **LICENSE** file for details.

---

<div align="center">

### ⭐ If you found this project interesting, consider giving it a star!

*"Good embedded systems begin with understanding the physical world they interact with."*

</div>
