#include <stdio.h>
#include "data.h"

int main() {

    float *x, *y;
    int n, i;



    n = countLines("data.txt");
    x = (float*) malloc (n * sizeof(float));
    y = (float*) malloc (n * sizeof(float));
    readData(x, y, n, "data.txt");
    printf("funcion\n");

    for(i = 0; i < n; i++) {
        printf("%f,%f\n", x[i], y[i]);
    }

    return 0;
}