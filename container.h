#ifndef CONTAINER_H
#define CONTAINER_H
#define MAX_LEN 10000
#include "transportation.h"

struct container {
    int len; // Current length.
    transportation arr[MAX_LEN];
    transportation* p_arr[MAX_LEN];
};

// Initializing the container.
void Init(container *c);

// Clearing the container.
void Clear(container *c);

// Input all transportation from the file. If meets a mistake stops reading.
void In(container *c, FILE *file);

// Creating random transportation with given size.
void InRnd(container *c, int size);

// Outputs items in the container to the given file.
void Out(container *c, FILE *file);

// Counts total max distance.
double MaxDistSum(container *c);

#endif // CONTAINER_H
