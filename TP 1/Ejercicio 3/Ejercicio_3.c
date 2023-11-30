#include <stdio.h>

//Definimos la función producto
int producto(int, int);

//Programa principal
int main(void){
    int x; //Declaramos las variables que vamos a usar
    int y;
    printf("Ingrese dos numeros: "); //Pedimos al usuario que ingrese dos numeros
    scanf("%d", &x);
    scanf("%d", &y);
    printf("El resultado es %d", producto(x, y)); //Invocamos la funcion producto y muestra el resultado en pantalla
}

//Funcion resta
//Recibe dos parametros ingresados por el usuario y devuelve el producto de ambos numeros
int producto(int a, int b){
    return a * b;
}