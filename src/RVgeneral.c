#include <RVgeneral.h>
#include <stdio.h>

void init_interfaces(){
    stdio_init_all();

    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
}

void init_display(ssd1306_t* ssd){
    ssd1306_init(ssd, WIDTH, HEIGHT, false, ADDRESS, I2C_PORT);
    ssd1306_config(ssd);
    ssd1306_send_data(ssd);

    ssd1306_fill(ssd, false);
    ssd1306_send_data(ssd);
}

void debug_display(ssd1306_t* ssd, bool color){
    ssd1306_fill(ssd, !color);
    ssd1306_rect(ssd, 3, 3, 120, 60, color, !color);
    ssd1306_draw_string(ssd, "DEBUG!", (128/2) - ((6*8)/2), 64/2);
    ssd1306_send_data(ssd);
    printf("\nDepuração de um retângulo de 120x60 no display de %dx%d!\n", WIDTH, HEIGHT);
}

void config_adc(adc* pins, uint8_t vector_size){
    adc_init();
    for (uint8_t i =0; i < vector_size; i++)
        adc_gpio_init(pins[i].pin);
}

void read_adc(uint16_t* readings, adc* pins, uint8_t vector_size){
    for (uint8_t i = 0; i < vector_size; i++){
        adc_select_input(pins[i].channel);
        readings[i] = adc_read();
    }
}

void debug_adc(adc* pins, uint8_t vector_size){
    printf("\nADC\n");
    printf("\nReadings:\n");
    uint16_t readings[vector_size];
    read_adc(readings, pins, vector_size);
    for (uint8_t i = 0; i < vector_size; i++){
        printf("Pin %d, channel %d: %d\n", pins[i].pin, pins[i].channel, readings[i]);
    }
}

int init_gpio(gpio* pins, uint8_t vector_size){
    for (uint8_t i = 0; i < vector_size; i++){
        gpio_init(pins[i].pin);
        gpio_set_dir(pins[i].pin, pins[i].pin_dir);
        if (pins[i].pin_dir == 0)
            gpio_pull_up(pins[i].pin);
        else
            gpio_put(pins[i].pin, 1);
    }

    return 0;
}

void debug_gpio(gpio* pins, uint8_t vector_size){
    printf("Entrou aqui!");
    for (uint8_t i = 0; i < vector_size; i++){
        print_gpio(pins[i]);
    }
}

void print_gpio(gpio pin){
    printf("\nGPIO");
    printf("\nDireção do pino %d: %s", pin.pin, gpio_get_dir(pin.pin) == 0 ? "IN" : "OUT");
    printf("\nNível: %s", gpio_get(pin.pin) == 0 ? "0V" : "3,3V");
}

void config_pwm(pwm* pins, uint8_t vector_size){
    for(uint8_t i = 0; i < vector_size; i++){
        gpio_set_function(pins[i].pin, GPIO_FUNC_PWM);
        pins[i].slice = pwm_gpio_to_slice_num(pins[i].pin);

        if (i > 0 && pins[i].slice == pins[i-1].slice)
            continue;

        pwm_set_wrap(pins[i].slice, PWM_WRAP);
        pwm_set_clkdiv(pins[i].slice, PWM_CLKDIV);
        pwm_set_enabled(pins[i].slice, true);
    }
}

void debug_pwm(pwm* pins, uint8_t vector_size){
    for(uint8_t i = 0; i < vector_size; i++)
        print_pwm(pins[i]);
}

void print_pwm(pwm pin){
    printf("\nPWM");
    printf("\nContador do pino %d: %d", pin.pin, pwm_get_counter(pin.slice));
}