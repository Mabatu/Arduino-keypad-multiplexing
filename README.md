# Arduino-keypad-multiplexing
Arduino based 4x4 tactile keypad multiplexing.
# How it works
Each row is activated individually by setting it to a low state, while the other three rows remain in a high state. The columns are then monitored to determine which button is pressed; any column that returns a low signal indicates a key press. The specific button pressed can be identified using the row and column numbers.

To prevent duplicate detections from key holds, two variables are used:

    currentButton – Stores the currently pressed button.
    previousButton – Stores the last recorded button press.

A button press is only registered when the current button differs from the previous one. If they match, the press is ignored.

## Wiring Diagram

### **Shift Register (74HC595) to Arduino**
| Shift Register Pin | Function        | Arduino Pin |
|-------------------|---------------|------------|
| 16 (VCC)         | Power          | 5V         |
| 8 (GND)         | Ground         | GND        |
| 13 (OE)         | Output Enable  | GND (Always enabled) |
| 10 (MR)         | Master Reset   | 5V (Disabled reset) |
| 14 (SER)        | Data Input     | D8         |
| 11 (SRCLK)      | Clock          | D9         |
| 12 (RCLK)       | Latch          | D10        |

### **Shift Register (74HC595) to Keypad (Rows)**
| Shift Register Pin | Function | Keypad Row |
|-------------------|----------|------------|
| 15 (Q0)          | Row 1    | R1         |
| 1 (Q1)           | Row 2    | R2         |
| 2 (Q2)           | Row 3    | R3         |
| 3 (Q3)           | Row 4    | R4         |

### **Keypad (Columns) to Arduino**
| Keypad Column | Arduino Pin |
|--------------|------------|
| C1          | D4         |
| C2          | D5         |
| C3          | D6         |
| C4          | D7         |
