/*15.Imprimir y sumar los elementos que ocupan las posiciones impares de un
vector de 50 elementos numéricos*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void cargar_array(int v[], int n);
void sumatoria(int v[], int n);

int main(){
    int v[N];
    cargar_array(v, N);
    sumatoria(v, N);
    return 0;
}

void cargar_array(int v[], int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        v[i] = rand()% 21;
        printf("%d ", v[i]);
    }
}

void sumatoria(int v[], int n){
    int acumulador = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 != 0){
            acumulador += v[i];
        }
    }
    printf("\nEl resultado es %d", acumulador);
}