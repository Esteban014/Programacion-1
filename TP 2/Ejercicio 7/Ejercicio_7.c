/*7.Ingresar 1000 edades en un vector e indicar cuál es la edad de mayor frecuencia (la que más se repite). 
Haga una función auxiliar que pruebe la correctitud del programa.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

void cargar(int v[], int n);
int repeticion(int v[], int n);
void auxiliar();

int main(){
    int v[N];
    cargar(v, N);
    printf("La edad con mas frecuencia es la de %d años\n", repeticion(v, N));
    auxiliar();
    return 0;
}

void cargar(int v[], int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        v[i] = rand() % (99 - 1 + 1) + 1;
    }
}

int repeticion(int v[], int n){
    int i, j;
    int may_repetido = 0, numero = 0;
    for(i = 0; i < n; i++){
        int repetido = 0;
        for(j = 0; j < n; j++){
            if(v[j] == v[i]){
                repetido++;
            }
        }
        if(repetido >= may_repetido){
            may_repetido = repetido;
            numero = v[i];
        }
    }
    return numero;
}

void auxiliar(){
    int v[] = {20, 30, 50, 70, 50, 70, 20, 70, 34, 70, 23, 10};
    printf("Resultado es %d\n", repeticion(v, 12));
}