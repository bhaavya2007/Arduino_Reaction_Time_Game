# Arduino Reaction Time Game

A game that tests reaction time built using an Arduino UNO R4 Minima, a 16×2 I2C LCD, a push button and two LEDs.

The game checks how fast a player reacts to a signal and works out the minimum, maximum and average reaction times from three good tries.

## Components Used

- Arduino UNO R4 Minima
- 16×2 I2C LCD (Address: 0x27)
- Push Button
- Red LED
- Green LED
- Breadboard and Jumper Wires
- Current-limiting resistors for LEDs

## Features

- Random waiting times between 1 and 10 seconds
- Detection of pressing the button early
- Red LED shows when the button is pressed too early
- Green LED shows when the button is pressed successfully
- Three good reaction-time measurements
- Minimum, maximum and average reaction-time calculation
- Results shown on the LCD

## Pin Connections

| Component | Arduino Pin |
|---|---|
| Push Button | D3 |
| Red LED | D7 |
| Green LED | D8 |
| LCD SDA | SDA |
| LCD SCL | SCL |

The push button uses `INPUT_PULLUP` and should be connected between D3 and GND. Each LED should have a current-limiting resistor.

## Working Principle

1. The LCD shows "wait" while the Arduino creates a delay.
2. If the player presses the button before the delay is over, the red LED turns on. The try starts again.
3. After the waiting time, the LCD shows "press".
4. The Arduino measures the time between the signal and the button press using `millis()`.
5. The green LED turns on after a successful press.
6. The game goes on until three good tries are done.
7. The LCD shows the minimum, maximum and average reaction times in milliseconds.

## Libraries Used

- LiquidCrystal_I2C.h

## Source Code

[View Arduino Sketch](rxngame.ino)

## What I Learned

- Measuring time that has passed using `millis()`
- Checking button presses using `INPUT_PULLUP`
- Using loops and `break`/`continue`
- Connecting an I2C LCD
- Using arrays to hold measurements
- Calculating minimum, maximum and average reaction times
- Fixing and testing an interactive hardware project

## Future Improvements

- Adding a countdown between tries
- Making timing more exact
- Adding a high-score feature

## Author

**Bhaavya Jain**

Electronics and Computer Engineering

Thapar Institute of Engineering and Technology
