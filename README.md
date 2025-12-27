# 📦 ESP32 + MPU6050 Motion-Controlled 3D Visualization + OLED View Indicator

Real-time motion-controlled 3D visualization system using **ESP32 + MPU6050**, where physical tilt controls a 3D object on the computer, while a small OLED display shows the current viewing direction.

This project combines embedded systems, sensor fusion, serial communication and computer graphics — perfect for gesture interfaces, interactive demos and educational projects.

## 🚀 Project Overview

- Control a **3D cube** rendered on PC using real physical motion
- MPU6050 tilt data drives real-time 3D rotation
- OLED display shows current viewing direction:
  - FRONT
  - BACK
  - LEFT
  - RIGHT
  - CENTER
- Smooth serial communication between ESP32 and **Processing**
- Auto-calibrated for stable, low-drift motion tracking

## ✨ Features

- 🎯 Real-time 3D cube rotation using MPU6050 (X & Y tilt)
- 🔄 Smooth and low-latency serial communication
- 🖥️ OLED visual orientation indicator
- ⚙️ Auto-calibration for consistent readings
- 🎨 Fully customizable visuals, thresholds and sensitivity
- 🧩 Modular and beginner-friendly code structure

## 🛠️ Hardware Used

- ESP32 Dev Module
- MPU6050 (6-axis: Accelerometer + Gyroscope)
- SSD1306 OLED Display (128×64, I²C)
- Jumper wires
- USB cable

## 🔌 Wiring Overview

**ESP32 I²C Pins**

| Signal | GPIO     |
|--------|----------|
| SDA    | GPIO 21  |
| SCL    | GPIO 22  |

**MPU6050 → ESP32**

| MPU6050 | ESP32    |
|---------|----------|
| VCC     | 3.3V     |
| GND     | GND      |
| SDA     | GPIO 21  |
| SCL     | GPIO 22  |

**OLED → ESP32**

| OLED    | ESP32    |
|---------|----------|
| VCC     | 3.3V     |
| GND     | GND      |
| SDA     | GPIO 21  |
| SCL     | GPIO 22  |

> **Note:** MPU6050 and OLED **share the same I²C bus**  
> **Important:** Common ground connection is mandatory

## 📥 Required Arduino Libraries

Install via **Arduino Library Manager**:

- `MPU6050_light`
- `Adafruit SSD1306`
- `Adafruit GFX`

## 🖥️ Software Stack

- **Arduino IDE** → reading sensors & sending data over Serial
- **Processing** → 3D visualization & cube rendering

## 🔄 How It Works

1. MPU6050 continuously calculates **AngleX** and **AngleY**
2. ESP32 sends angle values over Serial (115200 baud)
3. Processing receives data and rotates 3D cube in real-time
4. OLED shows current main viewing direction based on tilt thresholds

## 🎨 Customization Options

You can easily change:

- Cube color / size / wireframe style
- Background color
- Replace cube with sphere, model, or custom shape
- OLED font size and layout
- Tilt angle thresholds for direction detection
- Sensitivity / smoothing of rotation

## 🧪 How to Run

1. Connect ESP32, MPU6050 and OLED according to the wiring
2. Install required Arduino libraries
3. Upload the ESP32 sketch
4. **Close** Arduino Serial Monitor
5. Open the Processing sketch
6. Select correct COM port (e.g. COM5, /dev/ttyUSB0...)
7. Tilt the sensor → watch the cube rotate instantly!
8. Check OLED for current viewing direction

## 📚 Use Cases

- Motion-controlled user interfaces
- Game input devices
- VR/AR interaction prototypes
- Robotics orientation feedback
- Gesture-based control systems
- School & university mini-projects

## 📄 License

This project is **open-source**.  
Feel free to modify, distribute and use for personal, academic or hackathon purposes.

## 🤝 Contributions

Contributions are very welcome!  
Feel free to fork the repository, add features/improvements and submit a pull request 🚀
