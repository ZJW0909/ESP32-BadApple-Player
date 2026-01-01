# ESP32-BadApple-Player
Use the ESP32 to control the X-axis linear motor to vibrate and produce sound. You can press the motor against an object, or you can even bite it with your teeth.

## Components
1. ESP32
2. L9110S (Motor Driver Board)
3. X-axis Linear Motor (1 or 2 units)
4. Push Button

## Wiring Instructions
1. The X-axis linear motor has no positive or negative polarity and can be connected arbitrarily.

2. ESP32 → L9110S
   - GPIO2 connected to A-1A;
   - GPIO4 connected to A-1B;
   - GPIO5 connected to B-1A;
   - GPIO18 connected to B-1B;
   - 3V connected to VCC;
   - GND connected to GND;
   
3. Push Button
   - GPIO19 connected to one end of the button;
   - The other end of the button connected to GND of the ESP32;
