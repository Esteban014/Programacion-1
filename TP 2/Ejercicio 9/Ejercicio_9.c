/*9.Escribir una función que acepte como parámetro un vector que contiene
números positivos, que puede contener valores duplicados, y reemplace 
cada elemento repetido por -1 (menos uno).  El procedimiento debe retornar 
el vector modificado y la cantidad de veces que fue modificado.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void cargar(int v[], int n);
int repeticiones(int v[], int n);

int main(){
    int v[N], modificaciones;
    cargar(v, N);
    for(int i = 0; i < N; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    modificaciones = repeticiones(v, N);
    printf("\nLa cantidad de modificaciones es de %d.", modificaciones);
    return 0;
}

void cargar(int v[], int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        v[i] = rand() % (10 - 5 + 1) + 5;
    }
}
int repeticiones(int v[], int n){
    int contador = 0, i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(v[j] != (-1) && v[j] == v[i] && i != j){
                v[j] = -1;
                contador++;
            }
        }
    }
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    return contador;
}