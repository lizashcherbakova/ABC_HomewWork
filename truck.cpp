#include "truck.h"

// Input truck parameters from the file.
bool In(truck *t, FILE *file)
{
   return fscanf(file, "%d", &(t->load_capacity));
}

// Output track parameters.
bool Out(truck *t, FILE *file)
{
   return fprintf(file, "%s %d","This is a truck: Load capacity = ", t->load_capacity);
}

// Creating random parameters for the truck.
void InRnd(truck *t)
{
    t->load_capacity = rand()%28000;
}

