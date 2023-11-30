#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int main(void){
    int x;
    int y;
    printf("Ingrese dos numeros: ");
    scanf("%d", &x);
    scanf("%d", &y);
    int s = suma(x, y);
    int r = resta(x, y);
    int m = producto(x, y);
    printf("Los resultados son: %d, %d, %d\n", s, r, m);
    system("pause");
    return 0;
}