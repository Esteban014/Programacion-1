/*5.Realizar un programa que genere una matriz de 20 filas por 3 columnas donde la primera 
columna almacena el nombre, la segunda el apellido y la tercera el DNI. Luego dado un DNI, 
recorra la matriz, y si lo encuentra, muestre el nombre y apellido correspondientes. Sino, debe 
mostrar mensaje de error.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F 20
#define CNA 30

void cargar_nom_pila_dni(char nombres[][CNA], char apellidos[][CNA], int dni[][1], int f);
void mostrar(char nombres[][CNA], char apellidos[][CNA], int dni[][1], int f);
void busqueda(char nombres[][CNA], char apellidos[][CNA], int dni[][1], int f);

int main(){
    char nombres[F][CNA], apellidos[F][CNA];
    int dni[F][1];
    cargar_nom_pila_dni(nombres, apellidos, dni, F);
    mostrar(nombres, apellidos, dni, F);
    busqueda(nombres, apellidos, dni, F);
    return 0;
}

void cargar_nom_pila_dni(char nombres[][CNA], char apellidos[][CNA], int dni[][1], int f){
    for(int i = 0; i < f; i++){
        printf("Ingrese nombre en la posicion %d\n", i + 1);
        scanf("%s", nombres[i]);
        printf("Ingrese apellido en la posicion %d\n", i + 1);
        scanf("%s", apellidos[i]);
        printf("Ingrese dni en la posicion %d\n", i + 1);
        scanf("%d", &dni[i][0]);
    }
}

void mostrar(char nombres[][CNA], char apellidos[][CNA], int dni[][1], int f){
    int i;
    printf("Nombre    Apellido    DNI\n");
    for(i = 0; i < f; i++){
            printf("%s", nombres[i]);
            printf("   %s", apellidos[i]);
            printf("   %d\n", dni[i][0]);
    }
}

void busqueda(char nombres[][CNA], char apellidos[][CNA], int dni[][1], int f){
    int dato, i = 0;
    printf("Ingrese el dni que desea buscar: \n");
    scanf("%d", &dato);
    while((i < f) && (dni[i][0] != dato)){
        i++;
    }
    if(i == f){
        printf("El dato ingresado no existe.\n");
    }else{
        printf("El nombre y apellido con el dni %d es %s %s\n", dni[i][0], nombres[i], apellidos[i]);
    }
}