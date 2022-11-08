/***********************************************************************
 * 
 * The I2C (TWI) bus scanner tests all addresses and detects chips and
 * modules that are connected to the SDA and SCL signals.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2017 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Defines -----------------------------------------------------------*/
#ifndef F_CPU
# define F_CPU 16000000  // CPU frequency in Hz required for UART_BAUD_SELECT
#endif


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <twi.h>            // I2C/TWI library for AVR-GCC
#include <uart.h>           // Peter Fleury's UART library
#include <stdlib.h>         // C library. Needed for number conversions


struct Air_parameters_structure {
    uint8_t humid_int;
    uint8_t humid_dec;
    uint8_t temp_int;
    uint8_t temp_dec;
    uint8_t checksum;
} air;



/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Use Timer/Counter1, send one I2C (TWI) address every 33 ms,
 *           and test all combinations. Send information about scanning
 *           process to UART.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Initialize I2C (TWI)
    twi_init();

    // Initialize USART to asynchronous, 8N1, 9600
    uart_init(UART_BAUD_SELECT(9600, F_CPU));

    // Configure 16-bit Timer/Counter1 to test one I2C address
    // Set prescaler to 33 ms and enable interrupt
    //TIM1_overflow_33ms();
    TIM1_overflow_1s();

    TIM1_overflow_interrupt_enable();

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Put strings to ringbuffer for transmitting via UART
    uart_puts("Scan I2C bus for devices:\r\n");
    uart_puts("Decimal");
    uart_puts("\t");
    uart_puts("Hexadecimal");
    uart_puts("\t");
    uart_puts("State");
    uart_puts("\r\n");

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}


/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Test one I2C Slave address from the range 8 to 119.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    //static uint8_t addr = 8;  // I2C Slave address
    uint8_t ack;              // ACK response from Slave
    char string[3];           // String for converting numbers by itoa()

//-----------------------------------Temperature-------------------
uint8_t sla = 0x5c; // address of sensor

ack = twi_start(sla, TWI_WRITE);

//Check if slave is available
if (ack == 0){
  twi_write(0x02);
  twi_stop();

  ack = twi_start(sla,TWI_READ);
  air.temp_int =  twi_read_ack(); //Gives the value from register 0x02
  air.temp_dec =  twi_read_nack();//Gives the value from register 0x03

  itoa(air.temp_int,string,10);
  uart_puts(string);
  uart_puts(".");
  itoa(air.temp_dec,string,10);
  uart_puts(string);
  uart_puts("Cº\r\n");


  twi_stop();
}





//---------------------------SCANNER-------------------------
    // if (addr < 120){
    //   ack = twi_start(addr, TWI_WRITE);
    //   twi_stop();
    //   // Test ACK/NACK value obtained from I2C bus and send info to UART
    //   if (ack == 0){
    //     //Decimal adress
    //     itoa(addr,string,10);
    //     uart_puts(string);
    //     uart_puts("\t");//tab key

    //     //Hex adress
    //     itoa(addr,string,16);
    //     uart_puts(string);
    //     uart_puts("\t\t");


    //     uart_puts("OK");
    //     uart_puts("\r\n");  

    //   }

    //   addr++;

    }
      

  

  
    

    
    
