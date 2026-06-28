# Wearable-Posture-Feedback-Device

A wearable prototype that detects when the user's posture moves too far from a calibrated upright position and gives feedback through a buzzer.

I built this project to learn more about embedded systems, sensor calibration, wearable hardware, and the process of turning a rough idea into a working prototype.

## Overview

The device is mounted onto a support belt and powered by a USB power bank. It uses an accelerometer sensor to track the angle of the device while it is being worn. A button is used to calibrate the user's upright position, and if the sensor reading moves past the set threshold, the buzzer turns on.

This project is a prototype, not a finished product or medical device. The main goal was to build and test a working hardware system.

## Features

* Wearable belt-mounted design
* Accelerometer-based posture detection
* Calibration button to set the upright position
* Buzzer feedback when posture passes the threshold
* Microcontroller-controlled logic
* Portable power using a USB power bank
* Custom enclosure for holding the electronics

## Components Used

* Arduino Nano-compatible microcontroller
* Accelerometer sensor
* Push button
* Passive buzzer
* Jumper wires
* Breadboard for testing
* USB power bank
* Support belt
* 3D printed enclosure

## How It Works

1. The device is powered on using a USB power bank.
2. The accelerometer reads the angle of the device.
3. The user stands upright and presses the calibration button.
4. The current sensor reading is saved as the baseline position.
5. If the user's posture moves too far from that baseline, the buzzer activates.
6. When the user returns closer to the calibrated position, the buzzer turns off.

## Development Process

I started with a rough sketch of the device and planned how the sensor, button, buzzer, and microcontroller would fit onto a wearable belt. I first tested the circuit on a breadboard to make sure the sensor readings, button input, and buzzer output worked properly.

After the basic system was working, I moved the parts into a small enclosure and mounted it onto the belt. The final version is still rough, but it successfully demonstrates the main idea.

## Skills Practiced

* Reading sensor data with a microcontroller
* Using a button input for calibration
* Writing threshold-based control logic
* Wiring and debugging a small circuit
* Building a physical prototype
* Designing around size, comfort, and wearability
* Moving from concept sketch to working hardware

## Challenges

The hardest parts were getting reliable sensor readings, making the calibration work consistently, and fitting the electronics into the enclosure in a way that could still be worn on the body.

The wiring and enclosure could definitely be cleaner, but the project works as a functional prototype.

## Future Improvements

* Make the enclosure smaller and cleaner
* Improve wire management
* Add a smaller built-in rechargeable battery
* Replace the buzzer with vibration feedback
* Add adjustable sensitivity settings
* Improve sensor stability
* Make the device more comfortable to wear for longer periods of time

## Status

Prototype completed.
