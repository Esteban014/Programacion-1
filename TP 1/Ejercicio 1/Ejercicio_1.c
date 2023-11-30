#include <stdio.h>

//Declaramos la función suma.
int suma(int, int);

//Programa principal.
int main(void){
    int x;
    int y;
    printf("Ingrese dos números para sumar: "); //Pedimos al usuario que ingrese dos valores por teclado.
    scanf("%d", &x);
    scanf("%d", &y);
    printf("El resultado es %d", suma(x, y));//Mostramos en pantalla el resultado de la operación.
    return 0;
}

//Función suma
//recibe como parametros los numeros ingresados por el usuario y devuelve el resultado de la suma entre ambos.
int suma(int a, int b){
    return a + b;
}
