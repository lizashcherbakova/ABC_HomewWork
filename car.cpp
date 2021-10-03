#include "car.h"

// Input car parameters from the file.
bool In(car *c, FILE *file)
{
   return fscanf(file, "%hu", &(c->max_speed));
}

// Output car parameters.
bool Out(car *c, FILE *file)
{
   return fprintf(file, "%s %d","This is a car: maximum speed = ", c->max_speed);
}

// Creating random parameters for the car.
void InRnd(car *c)
{
    c->max_speed = rand()%256;
}
