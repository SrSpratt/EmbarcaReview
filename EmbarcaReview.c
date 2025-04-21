#include <RVgeneral.h>
#include <RVsketches.h>


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

    pwm buzzer_a = {.pin = 21, .slice = 0};
    pwm buzzer_b = {.pin = 10, .slice = 0};

    pwm p_pins[2] = {buzzer_a, buzzer_b};

    pio pio = {
        .pin = 7,
        .address = 0,
        .offset = 0,
        .state_machine = 0
    };

    rgb main_color = {.red = 0.0, .green = 0.05, .blue = 0.0};
    rgb background_color = {.red = 0.05, .green = 0.05, .blue = 0.05};

    sketch sketch = {
        .figure = {
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0
        },
        .index = -1,
        .main_color = main_color ,
        .background_color = background_color
    };

    bool color = true;

    init_interfaces();
    init_gpio(g_pins, 6);
    init_display(&ssd);

    config_adc(a_pins, 2);

    config_pwm(p_pins, 2);

    config_pio(&pio);

    vector_copy(sketch.figure, sketch_array('o'), matrix);
    draw(sketch, 0, pio, matrix);

    debug_display(&ssd, color);

    while(true){
        //printf("Olá!");
        //debug_gpio(pins, 6);
        //debug_adc(a_pins, 2);
        debug_pwm(p_pins, 2);
        debug_pio(pio);
        sleep_ms(1000);
    }
}