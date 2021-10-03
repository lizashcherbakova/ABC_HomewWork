#include "container.h"

// Initializing the container.
void Init(container *c)
{
    c->len = 0;
    for(int i = 0;i<MAX_LEN;++i){
        c->p_arr[i] = &(c->arr[i]);
    }
}

// Clearing the container.
void Clear(container *c)
{
   c->len = 0;
}

// Input all transportation from the file. If meets a mistake stops reading.
void In(container *c, FILE *file)
{
    while (In(&(c->arr[c->len]), file)) {
        ++c->len;
    }
}

// Outputs items in the container to the given file.
void Out(container *c, FILE *file)
{
    fprintf(file, "%s %d %s", "Container cotains ", c->len, " elements.\n");
    for(int i = 0; i < c->len; i++) {
        fprintf(file, "%d %s", i, " : ");
        if(!Out(c->p_arr[i], file)){
            fprintf(file, "%s"," Error occured.\n");
            break;
        }
    }
}

// Creating random transportation with given size.
void InRnd(container *c, int size)
{
    while(c->len < size) {
           InRnd(&(c->arr[c->len++]));
       }
}

// Counts total max distance.
double MaxDistSum(container *c)
{
    long long int sum = 0;
    for(int i = 0; i < c->len; i++) {
        sum += Max_dist(&(c->arr[i]));
    }
    return sum;
}
