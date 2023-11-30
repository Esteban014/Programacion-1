/*6.Realizar una función que devuelva distancia entre las posiciones de la letra “A” 
y la letra “B” del vector cargado en el ejercicio anterior. */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 30

void cargar(char v[], int n);
void distancias(int, int);

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
    distancias(posicion_a, posicion_b);
}

void distancias(int p_a, int p_b){
    int d;
    if(p_a < p_b){
        d = p_b - p_a;
    }
    else{
        d = p_a - p_b;
    }
    printf("\nLa distancia es %d", d - 1);
}