/*1.Escribir una función que reciba un arreglo de caracteres e indique si se 
encuentran ordenados de menor a mayor o no.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void cargar(char v[], int n);
void ordenados(char v[], int n);
void auxiliar();
//(122 - 97 + 1) + 97
int main(){
    char v[N];
    srand(time(NULL));
    cargar(v, N);
    ordenados(v, N);
    auxiliar();
    return 0;
}

void cargar(char v[], int n){
    for(int i = 0; i < n; i++){
        v[i] = rand() % (122 - 97 + 1) + 97;
        printf(" %c", v[i]);
    }
}

void ordenados(char v[], int n){
    int i = 0, j = 1;
    while(j < n && v[i] <= v[j]){
        i++;
        j++;
    }
    if(j == n){
        printf("\nSI");
    }else{
        printf("\nNO");
    }
}

void auxiliar(){
    char v[5] = {'a', 'b', 'c', 'd', 'f'};
    printf("\nFuncion Auxiliar:");
    ordenados(v, 5);
}