/*4. Dado un arreglo de N elementos, 
escribir un programa que permita desplazar los elementos del arreglo una posición a la derecha,
de tal forma que el primero pase a la segunda posición, el segundo a la tercera y así sucesivamente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargar(int v1[], int x);

int main(){
    int n;
    printf("Ingrese la longitud del arreglo: \n");
    scanf("%d", &n);
    int v1[n];
    cargar(v1, n);
}

void cargar(int v1[], int x){
    int numero, v2[x];
    for(int i = 0; i < x; i++){
        printf("Ingrese un valor para guardar en el vector: \n");
        scanf("%d", &numero);
        v1[i] = numero;
        v2[i] = numero;
    }
    v1[0] = v2[x-1];
    for(int i = 1, j = 0; i < x; i++, j++){
        v1[i] = v2[j];
    }
    for(int i = 0; i < x; i++){
        printf("Posicion %d - Numero %d\n", i, v1[i]);
    }
}