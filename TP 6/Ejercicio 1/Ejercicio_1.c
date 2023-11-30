/*Realizar un programa que permita, a través de una función ordenar un 
arreglo de 20 elementos. Esta función recibirá dos parámetros : 
el primero indicará arreglo a ordenar, y el segundo indicará si el orden será 
“A” - Ascendente (de menor a mayor) o “D” Descendente (de mayor a menor)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define T 20

void cargar(int v[], int t);
void ordenar(int v[], int t, char opcion);
void mostrar_ordenado(int v[], int t);

int main(){
    int v[T];
    char accion;
    printf("Ingrese el orden del arreglo('A' - Ascendente o 'D' - Descendente): ");
    scanf("%c", &accion);
    fflush(stdin);
    accion = toupper(accion);
    printf("\n");
    while (accion != 'A' && accion != 'D'){
        printf("Ingrese una opcion valida('A' - Ascendente o 'D' - Descendente): ");
        scanf("%c", &accion);
        fflush(stdin);
        accion = toupper(accion);
        printf("\n");
    }
    srand(time(NULL));
    cargar(v, T);
    ordenar(v, T, accion);
    mostrar_ordenado(v, T);
    system("pause");
    return 0;
}

void cargar(int v[], int t){
    int i;
    for(i = 0; i < t; i++){
        v[i] = (rand() % 51) - 10;
    }
    for(i = 0; i < t; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void ordenar(int v[], int t, char opcion){
    int i, j, aux;
    if (opcion == 'A'){
        for(i = 0; i < t; i++){
            for(j = 1; j < t - i; j++){
                if(v[j - 1] > v[j]){
                    aux = v[j];
                    v[j] = v[j - 1];
                    v[j - 1] = aux;
                }
            }
        }
    } else if (opcion == 'D'){
        for(i = 0; i < t; i++){
            for(j = 1; j < t - i; j++){
                if(v[j - 1] < v[j]){
                    aux = v[j];
                    v[j] = v[j - 1];
                    v[j - 1] = aux;
                }
            }
        }
    }
}

void mostrar_ordenado(int v[], int t){
    for(int i = 0; i < t; i++){
        printf("%d ", v[i]);
    }
}