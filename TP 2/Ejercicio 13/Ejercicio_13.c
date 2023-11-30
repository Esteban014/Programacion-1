/*13.Hacer una función que reciba un vector con n elementos numéricos y 
llamando a las funciones de los 3 ítems anteriores, muestre por pantalla la 
cantidad de números positivos, ceros y negativos que se encuentran en el vector. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conjuntos_numericos.h"
#define N 20

void cargar(int v[], int n);

int main(){
    int v[N];
    cargar(v,N);
    printf("\nPositivos: %d\nCeros: %d\nNegativos: %d\n", positivos(v, N), ceros(v, N), negativos(v, N));
    return 0;
}

void cargar(int v[], int n){
    for(int i = 0; i < n; i++){
        v[i] = rand() % 40 - 20;
        printf("%d ", v[i]);
    }
}