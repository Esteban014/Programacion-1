/*2.Leer una matriz de tres filas por tres columnas y calcular la suma de cada 
una de sus filas y de sus columnas, colocando los resultados en dos 
vectores, uno para la suma de las filas y otro para la suma de las columnas.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

void carga(int v[][N], int n);
void sumas_de_filas(int v[][N], int a[], int n);
void sumas_de_columnas(int v[][N], int a[], int n);

int main(){
    int v[N][N];
    int suma_filas[N];
    int suma_columnas[N];
    srand(time(NULL));
    carga(v, N);
    sumas_de_filas(v, suma_filas, N);
    sumas_de_columnas(v, suma_columnas, N);
    return 0;
}

void carga(int v[][N], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            v[i][j] = 0;
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            v[i][j] = rand() % (15 - 1 + 1) + 1;
        }
    }
    for(i = 0; i < n; i++){
        printf("{");
        for(j = 0; j < n; j++){
            printf(" %d", v[i][j]);
        }
        printf(" }\n");
    }
}

void sumas_de_filas(int v[][N], int suma_filas[], int n){
    int i, j, k, acumulador = 0;
    for(k = 0, i = 0; i < n; i++, k++){
        for(j = 0; j < n; j++){
            acumulador += v[i][j];
        }
        suma_filas[k] = acumulador;
        acumulador = 0;
    }
    printf("Suma de filas\n");
    for(i = 0; i < 3; i++){
        printf(" %d", suma_filas[i]);
    }
    printf("\n");
}


void sumas_de_columnas(int v[][N], int suma_columnas[], int n){
    int i, j, k, acumulador = 0;
    for(i = 0, k = 0; i < n; i++, k++){
        for(j = 0; j < n; j++){
            acumulador += v[j][i];
        }
        suma_columnas[k] = acumulador;
        acumulador = 0;
    }
    printf("Suma de columnas\n");
    for(i = 0; i < 3; i++){
        printf(" %d", suma_columnas[i]);
    }
    printf("\n");
}