/*1.Dada una matriz de 3 filas por 4 columnas, calcular la sumatoria de sus 
elementos:  ΣM(i,j).*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3
#define M 4

void carga(int v[][M], int n, int m);
int sumatoria(int v[][M], int n, int m);

int main(){
    int v[N][M];
    srand(time(NULL));
    carga(v, N, M);
    int suma = sumatoria(v, N, M);
    printf("La suma de todos los elementos es igual a %d\n", suma);
    return 0;
}

void carga(int v[][M], int n, int m){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            v[i][j] = 0;
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            v[i][j] = rand() % (15 - 1 + 1) + 1;
        }
    }
    for(i = 0; i < n; i++){
        printf("{");
        for(j = 0; j < m; j++){
            printf(" %d", v[i][j]);
        }
        printf(" }\n");
    }
}

int sumatoria(int v[][M], int n, int m){
    int acumulador = 0, j, i;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            acumulador += v[i][j];
        }
    }
    return acumulador;
}