# Mini-Nathan

This is my first hardware project.
A desktop robot that functions as both an interactive pet and a basic music player. It scans its surroundings by panning side to side and goes into a "sleeping" mode if no one is detected after a while.
The build features two servos that provide 2-axis (pan/tilt) movement for the head, a passive buzzer to play melodies, a capacitive touch sensor, and an LED indicator.

## Materials & Components

- 1x Arduino Uno R3
- 2x SG90 Micro Servos
- 1x Passive Buzzer
- 1x 5mm LED
- 1x HC-SR04 Ultrasonic Distance Sensor
- 1x TTP223B Capacitive Touch Sensor
- 1x Battery Holder (for 2x 18650 batteries)
- 2x 18650 Li-ion Rechargeable Batteries (3.7V)
- 1x 220 Ω Resistor

## Firmware Compilation & Flashing Instructions

1. Download and install the [Arduino IDE](https://www.arduino.cc/).
2. Open the file 'Code/Mini-Nathan/Mini-Nathan.ino' in the Arduino IDE.
3. Select your board: **Tools > Board > Arduino AVR Boards > Arduino Uno**.
4. Connect the Arduino Uno via USB, select the corresponding serial port under **Tools > Port**, and click **Upload**.

## 3D Printing

This project is fully designed to be manufactured using standard 3D printers. All print-ready STL files are located in the 'Hardware/Design/STL_Files' directory.

## Circuit Schematic & Hardware Layout

### Schematic Diagram

![Schematic Diagram](Hardware/Schematic/Schematic%20Diagram.jpg)

### Hardware Layout & Wiring
*Note: This assembly uses a breadboard for wiring rather than a custom PCB.*

Below is the physical layout and pin configuration used in the project:

![Layout](Hardware/Schematic/Layout.png)

*Note: In the diagram above, a push button is used as a placeholder to represent the TTP223 capacitive touch sensor, and the generic battery pack represents the 18650 rechargeable Li-ion batteries.*

## Bill of Materials (BOM)

The full component list, quantities, and reference links required to build this project can be found in the **[BOM](./BOM.csv)** file.
