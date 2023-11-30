/*Escribir una función que reciba un arreglo ordenado y un elemento x. Si el 
elemento x se encuentra en el arreglo, debe encontrar su posición mediante 
búsqueda binaria y devolver la posición. Si no se encuentra, debe agregar x al 
vector en la posición correcta y devolver esa nueva posición.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T 20

void cargar(int v[], int *t);
void ordenar(int v[], int *t);
void mostrar(int v[], int *t);
int buscar(int v[], int *t, int clave);

int main(){
    int t = 20;
    int v[t], dato;
    srand(time(NULL));
    cargar(v, &t);
    ordenar(v, &t);
    mostrar(v, &t);
    printf("\n");
    printf("Ingrese el numero que quiere buscar: ");
    scanf("%d", &dato);
    int posicion = buscar(v, &t, dato);
    printf("\n%d\n", posicion);
    mostrar(v, &t);
    return 0;
}

void cargar(int v[], int *t){
    for(int i = 0; i < *t; i++){
        v[i] = rand() % 51;
    }
}

void ordenar(int v[], int *t){
    int i, j , aux;
    for(i = 0; i < *t; i++){
        for(j = 1; j < *t - i; j++){
            if (v[j - 1] > v[j]){
                aux = v[j];
                v[j] = v[j - 1];
                v[j - 1] = aux;
            }
        }
    }
}

void mostrar(int v[], int *t){
    for(int i = 0; i < *t; i++){
        printf("%d ", v[i]);
    }
}

int buscar(int v[], int *t, int clave){
    int superior, inferior, centro, res;
    inferior = 0;
    superior = (*t) - 1;
    int encontrado = 0;
    while((inferior <= superior) && (encontrado == 0)){
        centro = (inferior + superior) / 2;
        if (clave == v[centro]){
            res = centro;
            encontrado = 1;
        }else{
            if (clave < v[centro]){
                superior = centro - 1;
            }else{
                inferior = centro + 1;
            }
        }

    }
    if (encontrado == 0){
        int i;
        (*t) += 1;
        for(i = *t - 1; i > centro; i--){
            v[i] = v[i - 1];
        }
        v[centro] = clave;
        res = centro;
    }

    return res;
}