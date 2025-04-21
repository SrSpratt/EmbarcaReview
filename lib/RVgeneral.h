#ifndef RVGPIO_H
#define RVGPIO_H

#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/adc.h"
#include <ssd1306.h>
#include <stdio.h>

#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define ADDRESS 0x3C


typedef struct gpio{
    uint8_t pin;
    bool pin_dir;
} gpio;

typedef struct adc_pinout{
    uint8_t pin;
    int channel;
} adc;

typedef struct interruption_context{
    
} irq_context;


void init_interfaces();
void init_display(ssd1306_t*);
void debug_display(ssd1306_t*, bool);

int init_gpio(gpio*, uint8_t);
void debug_gpio(gpio*, uint8_t);
void print_gpio(gpio);

void config_adc(adc*, uint8_t);
void read_adc(uint16_t* readings, adc* pins, uint8_t vector_size);
void debug_adc(adc* pins, uint8_t vector_size);

#endif