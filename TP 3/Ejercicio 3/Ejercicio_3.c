/*3.Realizar un programa que permita, a través de una función actualizar un 
arreglo ordenado  de n elementos. Esta función recibe cuatro parámetros : 
el arreglo a actualizar, la cantidad de elementos, la acción a realizar que 
puede ser I, B o A  y  un valor entero. Si la acción es I deberá agregar el 
valor en la última posición. Si es B deberá encontrar el valor dentro del 
arreglo y borrarlo (si no lo encuentra devolver mensaje de error) y si es A 
deberá ingresar un nuevo valor en la posición que indique valor*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 7

void cargar(int v[], int n);
void opciones(char accion, int v[], int *n, int valor);

int main(){
    int v[N] = {0, 4, 5, 9, 13, 21};
    int valor_ingresado;
    char opcion;
    int x = 6;
    printf("Ingrese una opcion:\nI. Agregar valor al final\nB. Eliminar el valor ingresado\nA. Agregar valor en la posicion ingresada\n");
    scanf("%c", &opcion);
    opcion = toupper(opcion);
    while ((opcion != 'A') && (opcion != 'B') && (opcion != 'I')){
        printf("Ingrese una opcion valida:\nI. Agregar valor al final\nB. Eliminar el valor ingresado\nA. Agregar valor en la posicion ingresada\n");
        scanf("%c", &opcion);
        opcion = toupper(opcion);
    }
    printf("Ingrese un valor:\n");
    scanf("%d", &valor_ingresado);
    printf("Arreglo original\n{");
    for(int i = 0; i < x; i++){
        printf(" %d", v[i]);
    }
    printf(" }\n");
    opciones(opcion, v, &x, valor_ingresado);
    printf("Arreglo modificado\n{");
    for(int i = 0; i < x; i++){
        printf(" %d", v[i]);
    }
    printf(" }\n");
    system("pause");
    return 0;
}

void opciones(char accion, int v[], int *n, int valor){
    int i, posicion;
    switch(accion){
        case 'I':
            if(*n <= N){
                v[*n] = valor;
                *n += 1;
            }
            break;
        case 'B':
            i = 0;
            while(i < *n && v[i] != valor){
                i++;
            }
            if(i < *n){
                for(; i < *n - 1; i++){
                    v[i] = v[i + 1];
                }
                (*n)--;
            }else{
                printf("No se encontro el valor\n");
            }
            break;
        default:
            printf("Ingrese la posicion donde quiere agregar el valor: ");
            scanf("%d", &posicion);
            if(*n < N){
                if(posicion >= 0 && posicion <= *n){
                    for(int i = *n; i > posicion; i--){
                        v[i] = v[i - 1];
                    }
                v[posicion] = valor;
                (*n)++;
                }
            }
            break;
    }
}