/*2.Haga una función que reciba dos arreglos ordenados A(n) y B(m), y retorne 
un nuevo arreglo C que contenga los elementos de A y de B de tal forma 
que quede también ordenado. Si existen elementos repetidos en los 
arreglos originales, en C deberán aparecer solamente una vez.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 7
#define M 10

void cargar(int v[], int n);
void ordenar(int v[], int n);
void nuevo_arreglo(int A[], int B[], int C[], int n, int m, int nm);

int main(){
    int A[N], B[M], C[N + M];
    srand(time(NULL));
    cargar(A, N);
    cargar(B, M);
    ordenar(A, N);
    ordenar(B, M);
    nuevo_arreglo(A, B, C, N, M, N + M);
    system("pause");
    return 0;
}

void cargar(int v[], int n){
    for(int i = 0; i < n; i++){
        v[i] = rand() % 16;
        printf(" %d", v[i]);
    }
    printf("\n");
}

void ordenar(int v[], int n){
    int i, j, aux;
    for (i = 0; i < n; i++){
        for (j = i+1; j < n; j++){
            if (v[i] > v[j]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
        printf(" %d", v[i]);
    }
    printf("\n");
}

void nuevo_arreglo(int A[], int B[], int C[], int n, int m, int nm){
    int i = 0, j = 0, k = 0;
    while(i < n && j < m){
        if(A[i] <= B[j]){
            if(k == 0 || C[k - 1] != A[i]){
            C[k] = A[i];
            k++;
            }
            i++;
        }else{
            if(k == 0 || C[k - 1] != B[j]){
            C[k] = B[j];
            k++;
            }
            j++;
        }
    }
    if(i == N){
        for(;j < M; j++){
            if(C[k] < B[j]){
                C[k] = B[j];
                k++;
            }
        }
    }else if(j == M){
        for(;i < N; i++){
            if(C[k] < A[i]){
                C[k] = A[i];
                k++;
            }
        }
    }
    i = 0;
    while(i < k){
        printf(" %d", C[i]);
        i++;
    }
    printf("\n");
}