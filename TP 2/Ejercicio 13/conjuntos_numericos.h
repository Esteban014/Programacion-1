#include <stdio.h>

int negativos(int v[], int n){
    int cantidad = 0, i;
    for(i = 0; i < n; i++){
        if(v[i] < 0){
            cantidad++;
        }
    }
    return cantidad;
}

int ceros(int v[], int n){
    int cantidad = 0, i;
    for(i = 0; i < n; i++){
        if(v[i] == 0){
            cantidad++;
        }
    }
    return cantidad;
}

int positivos(int v[], int n){
    int cantidad = 0, i;
    for(i = 0; i < n; i++){
        if(v[i] > 0){
            cantidad++;
        }
    }
    return cantidad;
}