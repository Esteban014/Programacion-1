/*14.Realizar un programa que reciba un vector con n elementos numéricos y 
muestre por pantalla el mayor de los valores del vector. Haga una función 
auxiliar que pruebe la correctitud del programa.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void cargar(int v[], int n);
void numero_mayor(int v[], int n);
void auxiliar();

int main(){
    int v[N];
    cargar(v, N);
    numero_mayor(v, N);
    auxiliar();
    return 0;
}

void cargar(int v[], int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        v[i] = rand() % 101;
    }
}

void numero_mayor(int v[], int n){
    int mayor = 0, i;
    for(i = 0; i < n; i++){
        if(v[i] > mayor){
            mayor = v[i];
        }
    }
    printf("El numero mayor es %d\n", mayor);
}

void auxiliar(){
    int v[] = {1,5,6,3,2,1};
    numero_mayor(v, 6);
}