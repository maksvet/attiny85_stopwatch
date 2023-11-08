# Stopwatch for ATtiny85

This repository contains an Arduino sketch for a simple stopwatch using ATtiny85 microcontroller with an OLED display.

## Features

- Start, stop, and reset functionality
- Long press for reset
- Display count up to 999 seconds

## Prerequisites

Before you begin, ensure you have met the following requirements:

- Arduino IDE installed on your computer
- ATtiny85 microcontroller
- Arduino board or programmer
- An OLED 32x64 display with SSD1306 controller
- Installed `TinyWireM` and `Tiny4kOLED` libraries from the Arduino Library Manager

## Installation

1. Install the required libraries through the Arduino Library Manager:
   - `TinyWireM`
   - `Tiny4kOLED`

2. Configure the Arduino IDE for ATtiny85 following [this setup guide](https://github.com/SpenceKonde/ATTinyCore/tree/v2.0.0-devThis-is-the-head-submit-PRs-against-this/avr/extras/ATtiny85_doc).

- Don't overlook capacitors for the Arduino reset pin and the Attiny power supply.
- Use Optiboot as the bootloader
- Burn bootloader before uploading sketch

3. Connect your ATtiny85 to your programmer and computer.

4. Select the correct board and port in the Arduino IDE.

5. Upload the sketch to your ATtiny85.

## Usage

After uploading the sketch to ATtiny85, the stopwatch operates as follows:

- A short button press starts and stops the stopwatch.
- Next short press re-starts the stopwatch.
- A long button press (more than 2 seconds) resets the stopwatch to zero.
