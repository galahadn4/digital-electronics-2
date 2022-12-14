# Lab 1: Nicolás González Mazuelos

### Morse code

1. Listing of C code which repeats one "dot" and one "comma" (BTW, in Morse code it is letter `A`) on a LED. Always use syntax highlighting, meaningful comments, and follow C guidelines:

```c

#define Delay_Bt_Puls 300 // Delay betwen pulsations (dots and commas) --> 0.3 sec
#define Delay_Bt_Letters 2000 // Delay between letters --> 2 sec
#define Delay_Dot 500 // Time led is on to simulate a dot --> 0.5 sec
#define Delay_Com 1500 //Time led is on to simulate a comma --> 1.5 sec

#define LED_GREEN PB0 //Define de LED_GREEN pin

int main(void)
{
    // Set pin where on-board LED is connected as output
    pinMode(LED_GREEN, OUTPUT);

    // Infinite loop
    while (1)
    {
        // Generate a lettre `A` Morse code

        //Dot simulation
         digitalWrite(LED_GREEN, HIGH); //Led turned on
         _delay_ms(Delay_Dot); //Delay
         digitalWrite(LED_GREEN, LOW); //Led turned off

         _delay_ms(Delay_Bt_Puls)//Time between dot and comma

         digitalWrite(LED_GREEN, HIGH); //Led turned on
         _delay_ms(Delay_Comma); //Delay
         digitalWrite(LED_GREEN, LOW); //Led turned off

         _delay_ms(Delay_Bt_Letters) 
         // At this point we have produced our first letter A, now the led is off during 2 seconds and the process will start again to produce another A

    }

    // Will never reach this
    return 0;
}
```

2. Scheme of Morse code application, i.e. connection of AVR device, LED, resistor, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![](https://github.com/galahadn4/digital-electronics-2/blob/main/lab1-blink_arduino/unnamed.jpg)
