#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

#include "truck.h"
#include "bus.h"
#include "car.h"

struct transportation{
    int fuel_tank_capacity;
    double lit_per_100_km;
    enum key{ TRUCK = 0 , BUS, CAR };
    enum key k;
    union {
         truck t;
         bus b;
         car c;
    };
};

// Input general transportation from the file.
bool In(transportation *t,  FILE *file);

// Creating random parameters for generel transportation.
void InRnd(transportation *t);

// Outputs all parameters of transportation.
bool Out(transportation *t, FILE *file);

// Counting the maximum distance for general transportation.
double Max_dist(transportation *tr);

#endif // TRANSPORTATION_H
