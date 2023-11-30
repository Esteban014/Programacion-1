#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 10

typedef struct{
    int legajo;
    char nombre[15];
    char apellido[15];
    float nota1;
    float nota2;
    float nota3;
    float promedio;
    char condicion[10];
} t_alumno;

typedef t_alumno t_tabla_alumnos[N];

void cargar(t_alumno *alumno, int c);
void promedios(t_alumno *alumno);
void condiciones(t_alumno *alumno);
void mostrar(t_alumno alumno);

int main(){
    t_alumno alumno;
    t_tabla_alumnos alumnos;
    int i;
    int n = 0;
    for(i = 0; i < N; i++){
        cargar(&alumnos[i], n);
        n += 100;
    }
    for(i = 0; i < N; i++){
        promedios(&alumnos[i]);
    }
    for(i = 0; i < N; i++){
        condiciones(&alumnos[i]);
    }
    for(i = 0; i < N; i++){
        mostrar(alumnos[i]);
    }
    return 0;
}

void cargar(t_alumno *alumno, int c){
    (*alumno).legajo = 1 + c;
    printf("Ingrese el nombre del alumno");
    fgets((*alumno).nombre, 15, stdin);
    if ((*alumno).nombre[strlen((*alumno).nombre) - 1] == '\n'){
        (*alumno).nombre[strlen((*alumno).nombre) - 1] = '\0';
    }
    fflush(stdin);
    printf("Ingrese el apellido del alumno");
    fgets((*alumno).apellido, 15, stdin);
    if ((*alumno).apellido[strlen((*alumno).apellido) - 1] == '\n'){
        (*alumno).apellido[strlen((*alumno).apellido) - 1] = '\0';
    }
    fflush(stdin);
    printf("Ingrese la primer nota");
    scanf("%d", &(*alumno).nota1);
    fflush(stdin);
    printf("Ingrese la segunda nota");
    scanf("%d", &(*alumno).nota2);
    fflush(stdin);
    printf("Ingrese la tercer nota");
    scanf("%d", &(*alumno).nota3);
    fflush(stdin);
}

void promedios(t_alumno 