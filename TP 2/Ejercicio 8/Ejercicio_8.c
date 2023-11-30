/*8.Realizar una función que determine si dos vectores cargados con números naturales, 
de igual cantidad de elementos, son idénticos.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void cargar(int v[], int v2[], int n);
void comparacion(int v[], int v2[], int n);
void testeo();

int main(){
    int v[N], v2[N];
    cargar(v, v2, N);
    comparacion(v, v2, N);
    testeo();
    return 0;
}

void cargar(int v[], int v2[], int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        v[i] = rand() % 10;
        v2[i] = rand() % 10;
    }
}

void comparacion(int v[], int v2[], int n){
    int contador = 0, i;
    for(i = 0; i < n; i++){
        if(v[i] == v2[i]){
            contador++;
        }
    }
    if(contador == 10){
        printf("Son iguales.\n");
    }
    else{
        printf("No son iguales.\n");
    }
}

void testeo(){
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int v2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    comparacion(v, v2, 10);
}