/*10.Hacer una función que reciba un vector con n elementos numéricos
 y retorne la cantidad de números negativos que se encuentran en el vector.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void cargar(int v[], int n);
int negativos(int v[], int n);

int main(){
    int v[N], cantidad_negativos;
    cargar(v,N);
    cantidad_negativos = negativos(v, N);
    printf("\nLa cantidad de negativos es de %d", cantidad_negativos);
    return 0;
}

void cargar(int v[], int n){
    for(int i = 0; i < n; i++){
        v[i] = rand() % 40 - 20;
        printf("%d ", v[i]);
    }
}

int negativos(int v[], int n){
    int cantidad = 0, i;
    for(i = 0; i < n; i++){
        if(v[i] < 0){
            cantidad++;
        }
    }
    return cantidad;
}