/*5.Escribir un algoritmo que permita procesar 2 arreglos ordenados de n 
elementos. Legajos(n) y Notas (n * 3) ya que por cada legajo hay 3 notas 
consecutivas. Se desea obtener un listado con el promedio de cada 
alumno.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 6

void cargar_notas(int Notas[], int n);
void cargar_legajos(int Legajos[], int n);
void ordenar_legajos(int Legajos[], int n);
void promedio_notas(float promedios[], int Notas[], int n);
void mostrar_arreglos(int Legajos[], int Notas[], float promedios[], int n);

int main(){
    int Legajos[MAX], Notas[MAX * 3];
    float promedios[MAX];
    srand(time(NULL));
    cargar_notas(Notas, MAX * 3);
    cargar_legajos(Legajos, MAX);
    ordenar_legajos(Legajos, MAX);
    promedio_notas(promedios, Notas, MAX * 3);
    mostrar_arreglos(Legajos, Notas, promedios, MAX);
    return 0;
}

void cargar_notas(int Notas[], int n){
    for(int i = 0; i < n; i++){
        Notas[i] = rand() % (10 - 1 + 1) + 1;
    }
}

void cargar_legajos(int Legajos[], int n){
    for(int i = 0; i < n; i++){
        Legajos[i] = rand() % (400000 - 100000 + 1) + 100000;
    }
}

void ordenar_legajos(int Legajos[], int n){
    int i, j, aux;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(Legajos[i] > Legajos[j]){
                aux = Legajos[i];
                Legajos[i] = Legajos[j];
                Legajos[j] = aux;
            }
        }
    }
}

void promedio_notas(float promedios[], int Notas[], int n){
    int i, j = 0, contador = 0;
    float acumulador = 0;
    for(i = 0; i < n; i++){
        contador++;
        acumulador += Notas[i];
        if(contador == 3){
            contador = 0;
            promedios[j] = acumulador / 3;
            acumulador = 0;
            j++;
        }
    }
}

void mostrar_arreglos(int Legajos[], int Notas[], float promedios[], int n){
    int i, j = 0, contador = 0;
    for(i = 0; i < n; i++){
        printf("Legajo: %d notas ", Legajos[i]);
        while(contador != 3){
            printf("%d ", Notas[j]);
            contador++;
            j++;
        }
        contador = 0;
        printf("promedio %.2f", promedios[i]);
        printf("\n");
    }
}