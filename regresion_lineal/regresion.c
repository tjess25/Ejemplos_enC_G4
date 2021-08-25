/***
 * Regresión Lineal Simple, Metodo de mínimos cuadrados
 * Programa creado para el curso de IoT
 * Fecha: 18.Ago.2021
 * Autor: Sarah Jessica Tinoco López
***/

/***
 * Sección de Bibliotecas
 * stdio.h para la función printf()
 * graph.h para las funciones grafDisp() y grafLineRegression()
***/
#include <stdio.h>
#include "graph.h"
 
int main() {
	float x[6]={10.0, 15.0, 20.0, 22.0, 30.0, 32.0};
	float y[6]={16.0, 32.0, 48.0, 56.0, 64.0, 80.0};
 
	int n;
	n = sizeof(x) / sizeof(x[0]);

	float ax, bx, mxy, axx, ayy, sum_x, sum_y, ay, by, sx, sy, sxy, asxy;
 
	ax = bx = ay = by = mxy = axx = ayy = sum_x = sum_y = sx = sy = sxy = asxy = 0.0;
 
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

    grafDisp(x, y, n);
    grafLineRegression(ax ,bx, x, n);
 
	return 0;
}