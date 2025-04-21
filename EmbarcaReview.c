#include <RVgeneral.h>


int main(){

    gpio button_a = {.pin = 5, .pin_dir = 0 };
    gpio button_b = {.pin = 6, .pin_dir = 0 };
    gpio button_j = {.pin = 22, .pin_dir = 0 };
    gpio led_g = { .pin = 11, .pin_dir = 1 };
    gpio led_b = { .pin = 12, .pin_dir = 1 };
    gpio led_r = { .pin = 13, .pin_dir = 1 };


    gpio g_pins[6] = {button_a, button_b, button_j, led_r, led_g, led_b};

    ssd1306_t ssd;

    adc joystick_x = {.pin = 26, .channel = 0};
    adc joystick_y = {.pin = 27, .channel = 1};

    adc a_pins[2] = {joystick_x, joystick_y};
    bool color = true;

    init_interfaces();
    init_gpio(g_pins, 6);
    init_display(&ssd);

    config_adc(a_pins, 2);


    debug_display(&ssd, color);

    while(true){
        //printf("Olá!");
        //debug_gpio(pins, 6);
        debug_adc(a_pins, 2);
        sleep_ms(1000);
    }
}