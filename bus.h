#ifndef BUS_H
#define BUS_H

#include <stdio.h>
#include <cstdlib>

struct bus{
     unsigned short passenger_capacity;
};

// Input bus parameters from the file.
bool In(bus *t,  FILE *file);

// Output bus parameters.
void InRnd(bus *t);

// Creating random parameters for the bus.
bool Out(bus *t, FILE *file);


#endif // BUS_H
