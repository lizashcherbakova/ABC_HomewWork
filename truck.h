#ifndef TRUCK_H
#define TRUCK_H

#include <stdio.h>
#include <cstdlib>

struct truck{
   int load_capacity;
};

// Input truck parameters from the file.
bool In(truck *t,  FILE *file);

// Creating random parameters for the truck.
void InRnd(truck *t);

// Output track parameters.
bool Out(truck *t, FILE *file);


#endif // TRUCK_H
