#include "bus.h"

// Input bus parameters from the file.
bool In(bus *b, FILE *file)
{
   return fscanf(file, "%hu", &(b->passenger_capacity));
}

// Output bus parameters.
bool Out(bus *b, FILE *file)
{
   return fprintf(file, "%s %d","This is a bus: Passenger capacity = ", b->passenger_capacity);
}

// Creating random parameters for the bus.
void InRnd(bus *b)
{
    b->passenger_capacity = rand()%256;
}
