/*


*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Prototipos
void cargar_array(int v1[], int v2[], int longitud);
int sumatoria(int v1[], int v2[], int longitud);

int main(){
    int n;
    printf("Ingrese la longitud de los vectores(Numero par): \n");//Ingreso de la longitud de los arrays.
    scanf("%d", &n);
    while(n % 2 != 0){//Validacion de la longitud
        printf("Vuelve a ingresar una longitud valida(Numero par): \n");
        scanf("%d", &n);
    }
    int v1[n], v2[n];
    cargar_array(v1, v2, n);
    int resultado = sumatoria(v1, v2, n);
    printf("La sumatoria es igual a %d\n", resultado);
    return 0;
}

void cargar_array(int v1[], int v2[], int longitud){//Funcion para cargar los arrays.
    int numero;
    for(int i = 0; i < longitud; i++){//Carga del primer array.
        printf("Vector A\n");
        printf("Ingrese un numero en la posicion %d: \n", i);
        scanf("%d", &numero);
        v1[i] = numero;
    }
    for(int i = 0; i < longitud; i++){//Carga del segundo array.
        printf("Vector B\n");
        printf("Ingrese un numero en la posicion %d: \n", i);
        scanf("%d", &numero);
        v2[i] = numero;
    }
}

int sumatoria(int v1[], int v2[], int longitud){//Funcion para sumar elementos de los arrays.
    int acumulador = 0;
    for(int i = 0; i < longitud; i++){
        if(i % 2 == 0){//Suma de los elementos en las posiciones pares del primer array.
            acumulador += v1[i];
        }
        if(i % 2 != 0){//Suma de los elementos posiciones impares del segundo array.
            acumulador += v2[i];
        }
    }
    return acumulador;
}