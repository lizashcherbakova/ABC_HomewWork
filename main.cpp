#include <stdio.h>
#include <cstring>
#include "container.h"

// the algorithm was taken from here http://mindhalls.ru/quick-sort-c-cpp/
void quick_sort(transportation **mas, int size) {
    // Pointers to the start and to the end of the array.
    int i = 0;
    int j = size - 1;
    // The middle element.
    double mid = Max_dist(mas[size / 2]);
    // Spliting the array.
    do {
        while(Max_dist(mas[i]) < mid) {
            i++;
        }
        while(Max_dist(mas[j]) > mid) {
            j--;
        }
        // Flipping elements.
        if (i <= j) {
            transportation* tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    // Checking if there is something left to sort.
    if(j > 0) {
        // Left half.
        quick_sort(mas, j + 1);
    }
    if (i < size) {
        // Right half.
        quick_sort(&mas[i], size - i);
    }
}

void errMessage1() {
    printf("%s", "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n");
}

void errMessage2() {
     printf("%s","incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n");
}

// 1 - file or random
// 2 - the file or size of container
// 3 - name file for output
// 4 - name file for max distance output
// Here are examples.
// abc_hw -n 15 out1.txt out2.txt
// abc_hw -f in5.txt out1.txt out2.txt

int main(int argc, char** argv)
{
    if(argc != 5) {
        errMessage1();
        return 1;
    }

    printf("%s", "Start\n");
    container c;
    Init(&c);
    FILE * file;
    if(!strcmp(argv[1], "-f")) {
        file = fopen(argv[2],"r");
        if(file){
             In(&c, file);
             fclose(file);
        }else{
           printf("%s", "Failed to open input file.\n");
           return 2;
        }
    }
    else if(!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            printf("%s %d %s","incorrect numer of transport = ", size, ". Set 0 < number <= 10000\n" );
            return 3;
        }
        InRnd(&c, size);
    }
    else {
        errMessage2();
        return 4;
    }
    if(c.len)
     if(file = fopen(argv[3],"w")){
         quick_sort(c.p_arr, c.len);
         Out(&c, file);
         fclose(file);
     }else{
         printf("%s", "Failed to open the output file:(\n");
         return 5;
     }

    if(file = fopen(argv[4],"w")){
        fprintf(file, "%s %f %s","Total max distance = ", MaxDistSum(&c), "\n");
        fclose(file);
    }else{
        printf("%s", "Failed to open the output file for total distance:(\n");
        return 6;
    }
    Clear(&c);
    printf("%s", "Stop\n");
    return 0;
}
