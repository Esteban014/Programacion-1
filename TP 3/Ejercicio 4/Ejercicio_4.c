/*4.Se tienen dos arreglos  de números enteros, ordenados de mayor a menor, 
de n elementos cada uno: A(n) y B(n). Se pide realizar un algoritmo que 
permita obtener un  nuevo arreglo C, que contenga únicamente  los 
elementos  iguales que existan en los dos y no pueden estar repetidos.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 7

void cargar(int v[], int n);
void ordenar(int v[], int n);
void mezclar(int A[], int B[], int n);

int main(){
    int A[N], B[N];
    srand(time(NULL));
    cargar(A, N);
    cargar(B, N);
    ordenar(A, N);
    ordenar(B, N);
    mezclar(A, B, N);
    return 0;
}

void cargar(int v[], int n){
    printf("Areglo\n{ ");
    for(int i = 0; i < n; i++){
        v[i] = rand() % (10 - 1 + 1) + 1;
        printf("%d ", v[i]);
    }
    printf("}\n");
}

void ordenar(int v[], int n){
    int i, j, aux;
    printf("Arreglo ordenado\n{ ");
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(v[i] > v[j]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
        printf("%d ", v[i]);
    }
    printf("}\n");
}

void mezclar(int A[], int B[], int n){
    int C[N + N], k = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(A[i] == B[j]){
                if(k == 0 || C[k - 1] != A[i]){
                    C[k] = A[i];
                    k++;
                }
            }
        }
    }
    int i = 0;
    printf("Nuevo arreglo\n{ ");
    while(i < k){
        printf("%d ", C[i]);
        i++;
    }
    printf("}\n");
}