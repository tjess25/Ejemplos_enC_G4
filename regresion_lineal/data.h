#include <stdlib.h>

#define MAXLINE 100


int countLines(char *path) {

  FILE *codePtr;
  char linea[MAXLINE];
  int i = 0;

  if ((codePtr = fopen(path, "r")) == NULL) {
    printf("**ERROR** No se puede abrir el archivo\n");
  } else {
    fgets(linea, MAXLINE, codePtr);
    ++i;
    while (!feof(codePtr)) {
      fgets(linea, MAXLINE, codePtr);
      ++i;
    }
  }
  fclose(codePtr);
  return i;
}


void readData(float *x, float *y, int n, char path[]) {

    
    
    FILE *dataPtr;
    int i;
    char aux;

    if ((dataPtr = fopen(path, "r")) == NULL) {
        printf("**ERROR** No se puede abrir el archivo\n");
    } else {
        for(i = 0; i < n; i++) {
            fscanf(dataPtr, "%f%c%f", &x[i], &aux, &y[i]);
        }
    }
}