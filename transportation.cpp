#include "transportation.h"

// Input general transportation from the file.
bool In(transportation *transport, FILE *file)
{
   int key;
   if(!fscanf(file, "%d", &(key)))return false;
   switch(key) {
            case 0:
                transport->k = transportation::TRUCK;
                if(!In(&(transport->t), file))return false;
            break;
            case 1:
                transport->k = transportation::BUS;
                if(!In(&(transport->b), file))return false;
            break;
            case 2:
                transport->k = transportation::CAR;
                if(!In(&(transport->c), file))return false;
            break;
            default:
                return false;
     }
    return fscanf(file, "%d %lf", &(transport->fuel_tank_capacity), &(transport->lit_per_100_km));
}

// Outputs all parameters of transportation.
bool Out(transportation *transport, FILE *file)
{
    bool rez = false;
    switch(transport->k) {
            case transportation::TRUCK:
                 rez = Out(&(transport->t), file);
                 goto GENERAL_DATA_PRINT;
            case transportation::BUS:
                rez = Out(&(transport->b), file);
                goto GENERAL_DATA_PRINT;
            case transportation::CAR:
                rez = Out(&(transport->c), file);
            GENERAL_DATA_PRINT:
                fprintf(file, "%s %d %s %f",". Fuel tank capacity = ", transport->fuel_tank_capacity, "; Liters per 100 km needed ", transport->lit_per_100_km);
                fprintf(file, "%s %f %c", ". Max distance can be covered = ", Max_dist(transport), '\n');
            break;
            default:
                fprintf(file, "Incorrect figure!\n");
                 return false;
        }
    return rez;
}


// Creating random parameters for generel transportation.
void InRnd(transportation *t)
{   
    rand();rand();
    int k = rand() % 3;
    switch(k) {
        case 0:
            t->k = transportation::TRUCK;
            InRnd(&(t->t));
             t->fuel_tank_capacity = 200 + rand()%1300;
             t->lit_per_100_km = 1.0 * (100 + rand()%(1000-100))/10;
        break;
        case 1:
            t->k = transportation::BUS;
            InRnd(&(t->b));
            t->fuel_tank_capacity = 200 + rand()%100;
            t->lit_per_100_km = 1.0 * (410 + rand()%(1000-410))/10;
        break;
        case 2:
            t->k = transportation::CAR;
            InRnd(&(t->c));
            t->fuel_tank_capacity = 45 + rand()%(100 - 45);
            t->lit_per_100_km = 1.0 * (50 + rand()%100)/10;
        break;
    }
}

// Counting the maximum distance for transportation.
double Max_dist(transportation *tr)
{
    return  tr->lit_per_100_km * 100.0 * tr->fuel_tank_capacity;
}
