/*3.Realizar un programa que, dada una matriz cuadrada con valores enteros 
entre 1 y 50 (al azar), la muestra y se obtenga su traspuesta (permutación 
de filas y columnas, utilizando un procedimiento que permuta dos 
elementos), y la muestre nuevamente..*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4

void cargar(int m[][N], int n);
void permutar(int m[][N], int n);

int main(){
    int m[N][N];
    srand(time(NULL));
    cargar(m, N);
    printf("\n\n");
    permutar(m, N);
    return 0;
}

void cargar(int m[][N], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            m[i][j] = 0;
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            m[i][j] = rand() % (50 - 1 + 1) + 1;
        }
    }
    for(i = 0; i < n; i++){
        printf("{");
        for(j = 0; j < n; j++){
            printf(" %d", m[i][j]);
        }
        printf(" }\n");
    }
}

void permutar(int m[][N], int n){
    int i, j, aux;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
    }
    for(i = 0; i < n; i++){
        printf("{");
        for(j = 0; j < n; j++){
            printf(" %d", m[i][j]);
        }
        printf(" }\n");
    }
}