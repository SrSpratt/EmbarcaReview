#ifndef RVSKETCHES_H
#define RVSKETCHES_H

#include <RVgeneral.h>

#define matrix 25

typedef struct rgb{
    double red;
    double green;
    double blue;
} rgb;

typedef struct drawing {
    double figure[matrix];
    uint8_t index;
    rgb main_color;
    rgb background_color;
} sketch;

double* sketch_array(char character);
uint32_t rgb_matrix(rgb);
void draw(sketch, uint32_t, pio, const uint8_t);
void vector_copy(double*, double*, uint8_t);
void print_sketch(sketch);

#endif