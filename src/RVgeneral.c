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
}

int init_gpio(gpio* pins, int vector_size){
    for (int i = 0; i < vector_size; i++){
        gpio_init(pins[i].pin);
        gpio_set_dir(pins[i].pin, pins[i].pin_dir);
        if (pins[i].pin_dir == 0)
            gpio_pull_up(pins[i].pin);
        else
            gpio_put(pins[i].pin, 1);
    }

    return 0;
}

void debug_gpio(gpio* pins, int vector_size){
    printf("Entrou aqui!");
    for (int i = 0; i < vector_size; i++){
        print_gpio(pins[i]);
    }
}

void print_gpio(gpio pin){
    printf("\nGPIO");
    printf("\nDireção do pino %d: %s", pin.pin, gpio_get_dir(pin.pin) == 0 ? "IN" : "OUT");
    printf("\nNível: %s", gpio_get(pin.pin) == 0 ? "0V" : "3,3V");
}