/*5.Crear una función que cargue un vector de 30 elementos con la letra “x"
y coloque en una ubicación aleatoria una “A”
y en otra ubicación aleatoria que no sea la misma que tiene la letra “A” una letra “B” */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 30

void cargar(char v[], int n);

int main(){
    char v[N];
    cargar(v, N);
    return 0;
}

void cargar(char v[], int n){
    int posicion_a, posicion_b, i;
    for(i = 0; i < n; i++){
        v[i] = 'x';
    }
    srand(time(NULL));
    posicion_a = rand() % 30;
    v[posicion_a] = 'A';
    posicion_b = rand() % 30;
    while(posicion_b == posicion_a){
        posicion_b = rand() % 30;
    }
    v[posicion_b] = 'B';
    for(i = 0; i < n; i++){
        printf("%c, ", v[i]);
    }
}