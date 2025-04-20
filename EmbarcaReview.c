#include <RVgeneral.h>


int main(){

    gpio button_a = {.pin = 5, .pin_dir = 0 };
    gpio button_b = {.pin = 6, .pin_dir = 0 };
    gpio button_j = {.pin = 22, .pin_dir = 0 };
    gpio led_g = { .pin = 11, .pin_dir = 1 };
    gpio led_b = { .pin = 12, .pin_dir = 1 };
    gpio led_r = { .pin = 13, .pin_dir = 1 };


    gpio pins[6] = {button_a, button_b, button_j, led_r, led_g, led_b};

    init_interfaces();
    init_gpio(pins, 6);

    while(true){
        printf("Olá!");
        debug_gpio(pins, 6);
        sleep_ms(1000);
    }
}