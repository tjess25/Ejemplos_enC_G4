/***
 * Regresión Lineal Simple, Metodo de mínimos cuadrados
 * Programa creado para el curso de IoT
 * Fecha: 18.Ago.2021
 * Autor: Sarah Jessica Tinoco López
***/

/***
 * Sección de Bibliotecas
 * stdio.h para las funciones printf() y scanf
 * graph.h para las funciones grafDisp() y grafLineRegression()
 * data.h para las funciones countLines() y readData()
***/
#include <stdio.h>
#include "graph.h"
#include "data.h"
 
int main() {
	float *x;
	float *y;
 
	int n, op, i;

    FILE *fp;
	

	float ax, bx, mxy, axx, ayy, sum_x, sum_y, ay, by, sx, sy, sxy, asxy;
 
	ax = bx = ay = by = mxy = axx = ayy = sum_x = sum_y = sx = sy = sxy = asxy = 0.0;

    /***
     * 
     * Obtención de los datos y dimensión de los datos
     * 
    ***/
    n = countLines("data.txt");
    x = (float*) malloc (n * sizeof(float));
    y = (float*) malloc (n * sizeof(float));
    readData(x, y, n, "data.txt");

    printf("Graficando ...\n");
    //grafDisp(x, y, n);
    system("./FastChart data.txt");
    printf("Grafica generada\n");

    printf("Presione 1 para continuar:\t");
    scanf("%d", &op);

    if (op == 1) {
        /***
         * Calculo de la sumatoria de x
         * Calculo de la sumatoria de y
        ***/
        for (int i = 0; i < n; i++) {
            sum_x += x[i];
            sum_y += y[i];
        }

        /***
         * Calculo de x'
         * Calculo de y'
        ***/
        float X = sum_x / n;
        float Y = sum_y / n;
    
        /***
         * Calculo de la sumatoria de (x - x')^2
         * Calculo de la sumatoria de (y - y')^2
        ***/
        for (int i = 0; i != n; i++) {
            axx += (x[i] - X)*(x[i] - X);
            ayy += (y[i] - Y)*(y[i] - Y);
        }

        /***
         * Calculo de S^2x
         * Calculo de S^2y
        ***/
        sx = axx / n;
        sy = ayy / n;

        /***
         * Calculo de la sumatoria de (x - x')^2 (y - y')^2
        ***/
        for (int i = 0; i != n; i++) {
            asxy += (x[i] - X)*(y[i] - Y);
        }

        /***
         * Calculo de Sxy
        ***/
        sxy = asxy / n;


        /***
         * Calculo de a y b para la ecuacion Y' = a + bx
        ***/
        bx = sxy / sx;
        ax = Y - bx*X;

        /***
         * Calculo de a y b para la ecuacion X' = a + by
        ***/
        by = sxy / sy;
        ay = X - by*Y;
    
        printf("Y = %0.2f + %0.2fx\n", ax, bx);
        printf("X = %0.2f + %0.2fy\n", ay, by);

        printf("Graficando ...\n");
        //grafLineRegression(ax ,bx, x, n);
        fp = fopen ( "recta.txt", "w" );

        for (i = 0; i < n; i++) {
            fprintf(fp, " %f\n", ax + bx * x[i]);
        }
        fclose (fp);
        system("./FastChart recta.txt");
        printf("Grafica generada\n");
    }
    
 
	return 0;
}