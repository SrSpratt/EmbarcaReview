#ifndef RVGPIO_H
#define RVGPIO_H

#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include <ssd1306.h>
#include <stdio.h>

#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define ADDRESS 0x3C

#define PWM_WRAP 20000
#define PWM_CLKDIV 125.0f


typedef struct gpio_pinout{
    uint8_t pin;
    bool pin_dir;
} gpio;

typedef struct adc_pinout{
    uint8_t pin;
    uint8_t channel;
} adc;

typedef struct pwm_pinout{
    uint8_t pin;
    uint8_t slice;
} pwm;

typedef struct interruption_context{
    
} irq_context;


void init_interfaces();
void init_display(ssd1306_t*);
void debug_display(ssd1306_t*, bool);

int init_gpio(gpio*, uint8_t);
void debug_gpio(gpio*, uint8_t);
void print_gpio(gpio);

void config_adc(adc*, uint8_t);
void read_adc(uint16_t*, adc*, uint8_t);
void debug_adc(adc*, uint8_t);

void config_pwm(pwm*, uint8_t);
void debug_pwm(pwm*, uint8_t);
void print_pwm(pwm);

#endif