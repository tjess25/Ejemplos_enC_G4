#include <stdlib.h>
#include <stdio.h>

void grafDisp(float x[], float y[], int n) {

    int i;

    FILE *fp;
 	
 	fp = fopen ( "disp.py", "w" );
 	
 	fprintf(fp, "import matplotlib.pyplot as plt\n");
    fprintf(fp, "x = [");
    for (i = 0; i < n - 1 ; i++) {
        fprintf(fp, " %f, ", x[i]);
    }
    fprintf(fp, "%f ]\n", x[n-1]);


    fprintf(fp, "y = [");
    for (i = 0; i < n - 1 ; i++) {
        fprintf(fp, " %f, ", y[i]);
    }
    fprintf(fp, "%f ]\n", y[n-1]);

    fprintf(fp, "plt.scatter(x,y)\n");
    fprintf(fp, "plt.savefig(\"Dispersion.png\")\n");
    fclose (fp);
    system("python3 disp.py");
    system("rm disp.py");

}




void grafLineRegression(float a , float b, float x[], int n) {

    float g[n];
    int i;

    FILE *fp;

    for (i = 0; i < n; i++) {
        
        g[i] = a + b * x[i];
        
    }
 	
 	fp = fopen ( "line2.py", "w" );
 	
 	fprintf(fp, "import matplotlib.pyplot as plt\n");
    fprintf(fp, "x = [");
    for (i = 0; i < n - 1 ; i++) {
        fprintf(fp, " %f, ", g[i]);
    }
    fprintf(fp, "%f ]\n", g[n-1]);
    fprintf(fp, "plt.plot(x)\n");
    fprintf(fp, "plt.savefig(\"Regresion.png\")\n");
    fclose (fp);
    system("python3 line2.py");
    system("rm line2.py");

}
