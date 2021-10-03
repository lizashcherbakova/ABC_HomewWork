#ifndef CAR_H
#define CAR_H

#include <stdio.h>
#include <cstdlib>

struct car{
    unsigned short max_speed;
};
// Input car parameters from the file.
bool In(car *c,  FILE *file);

// Output car parameters.
void InRnd(car *c);

// Creating random parameters for the car.
bool Out(car *c, FILE *file);


#endif // CAR_H
