#ifndef RVGPIO_H
#define RVGPIO_H

#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include <ssd1306.h>
#include <stdio.h>

#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define ADDRESS 0x3C


typedef struct gpio{
    int pin;
    bool pin_dir;
} gpio;

typedef struct interruption_context{
    
} irq_context;


void init_interfaces();
void init_display(ssd1306_t*);
void debug_display(ssd1306_t*, bool);
int init_gpio(gpio*, int);
void debug_gpio(gpio*, int);
void print_gpio(gpio);


#endif