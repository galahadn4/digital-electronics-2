# Lab 2: Nicolás González Mazuelos

### GPIO control registers

1. Complete the table for DDRB and PORTB control register values.

   | **DDRB** | **PORTB** | **Direction** | **Internal pull-up resistor** | **Description** |
   | :-: | :-: | :-: | :-: | :-- |
   | 0 | 0 | input | no | Tri-state,high-impedance |
   | 0 | 1 | input | yes |Tri-state, high-impedance |
   | 1 | 0 | output | no | Push-pull Zero Output |
   | 1 | 1 | output | no | Push-pull One Output |

### GPIO library

2. Complete the table with code sizes from three versions of the blink application.

   | **Version** | **Size [B]** |
   | :-- | :-: |
   | Arduino-style     | 480 |
   | Registers         | 182 |
   | Library functions | 182 |

### Traffic light

3. Scheme of traffic light application with one red/yellow/green light for cars, one red/green light for pedestrians, and one push button. Connect AVR device, LEDs, resistors, push button (for pedestrians), and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![](https://github.com/galahadn4/digital-electronics-2/blob/main/IMG-0169.jpg)