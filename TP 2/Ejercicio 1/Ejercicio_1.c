/*1.	Crear una función con cuatro parámetros 
(v, N, menor, mayor) que cargue un vector v de longitud N  
con números enteros aleatorios comprendidos entre menor  y mayor.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 7

void cargar_array(int v[], int n, int menor, int mayor);

int main(){
    int v[N], menor, mayor;
    printf("Ingrese el primer valor del intervalo: \n");
    scanf("%d", &menor);
    printf("Ingrese el segundo valor del intervalo: \n");
    scanf("%d", &mayor);
    cargar_array(v, N, menor, mayor);
}

void cargar_array(int v[], int n, int men, int may){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        v[i] = rand()%(may - men + 1) + men;
        printf("Posicion |%d| - Numero |%d|\n", i, v[i]);
    }
}