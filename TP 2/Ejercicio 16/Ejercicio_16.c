/*16.	Escribir una función que reciba como argumentos un arreglo de N
elementos de tipo entero  y un número entero X, y haga lo siguiente:
a.Busque todos los elementos que coincidan con X y devuelva la
cantidad de coincidencias encontradas.

b.Busque la primera coincidencia del elemento en la lista y devuelva su
posición. Si X no existe en el arreglo debe devolver -1.

c.Utilizando la función anterior, busque todos los elementos que 
coincidan con X y devuelva un arreglo con las posiciones que ocupan 
estos elementos en el arreglo original. Si no hay elementos 
coincidentes, devolverá un arreglo vacío.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void cargar(int v[], int n){
    for(int i = 0; i < n; i++){
        v[i] = rand() % 6;
        printf("%d ", v[i]);
    }
}

int cantidad_elementos(int v[], int n, int clave){
    int cantidad = 0;
    for(int i = 0; i < n; i++){
        if(clave == v[i]){
            cantidad++;
        }
    }
    return cantidad;
}

int primera_coincidencia(int v[], int n, int clave){
    int posicion, i = 0;
    while((i < n) && (v[i] != clave)){
        i++;
    }
    if(v[i] == clave){
        posicion = i;
    }else{
        posicion =-1;
    }
    return posicion;
}

void array_posiciones(int v[], int n, int clave){
    int longitud = cantidad_elementos(v, N, clave);
    int j = 0, v_nuevo[longitud];
    for(int i = 0; i < n; i++){
        if (v[i] == clave){
            v_nuevo[j] = i;
            j++;
        }
    }
    printf("{ ");
    for(int i = 0; i < longitud; i++){
        printf("%d ", v_nuevo[i]);
    }
    printf("}\n");
}

int main(){
    int v[N], a, b;
    srand(time(NULL));
    int X = rand() % 6;
    cargar(v, N);
    a = cantidad_elementos(v, N, X);
    b = primera_coincidencia(v, N, X);
    printf("\nLa cantidad de elementos igual a %d es de %d", X, a);
    printf("\nLa posicion de la primer coincidencia es %d\n", b);
    array_posiciones(v, N, X);
}