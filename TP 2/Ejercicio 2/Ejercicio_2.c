/*2.	Dados dos vectores A y B de igual cantidad de elementos cargados con la función del punto 1,
obtener el producto escalar: Σ A(i) * B(i).*/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
void cargar_array(int v1[], int v2[], int n, int menor, int mayor);

int producto_escalar(int v1[], int v2[], int n);

int main(){
    int v1[N], v2[N], menor, mayor;
    printf("Ingrese el primer valor del intervalo: \n");
    scanf("%d", &menor);
    printf("Ingrese el segundo valor del intervalo: \n");
    scanf("%d", &mayor);
    cargar_array(v1, v2, N, menor, mayor);
    int resultado = producto_escalar(v1, v2, N);
    printf("\nEl producto escalar es igual a %d\n", resultado);
    for(int i = 0; i < N; i++){
        printf(" %d %d ", v1[i], v2[i]);
    }
    return 0;
}

void cargar_array(int v1[],int v2[], int n, int men, int may){
    printf("Primer Arreglo\n");
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        v1[i] = rand()%(may - men + 1) + men;
        printf(" |Posicion %d - Numero %d| ", i, v1[i]);
    }
    printf("\nSegundo Arreglo\n");
    for(int i = 0; i < n; i++){
        v2[i] = rand()%(may - men + 1) + men;
        printf(" |Posicion %d - Numero %d| ", i, v2[i]);
    }
}

int producto_escalar(int v1[], int v2[], int n){
    int acumulador = 0;
    for(int i = 0; i < n; i++){
        acumulador += (v1[i] * v2[i]);
    }
    return acumulador;
}