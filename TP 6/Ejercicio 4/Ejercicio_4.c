/*Utilizando el ejercicio 3 del TP5, realice las modificaciones necesarias 
para que la lista de estudiantes esté siempre ordenada alfabéticamente.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#define A 3
#define N 2
#define C 10

typedef struct{
    int dia;
    int mes;
    int anio;
} t_fecha_nac;

typedef struct{
    char nombre[15];
    char apellido[15];
    t_fecha_nac fecha_nac;
    int notas[C];
} t_alumno;

typedef struct{
    char nivel[15];
    char profesor[30];
    t_alumno alumnos[A];
} t_clase;

typedef t_clase t_tabla_clases[N];

void cargar_clase(t_clase* clases);
void cargar_alumno(t_alumno* alumno);
void ordenar_alumnos(t_clase* clases);
void mostrar_clase(t_clase clases);
void mostrar_alumnos(t_alumno alumno);

int main(){
    int i;
    t_tabla_clases clases_c;
    srand(time(NULL));
    for (i = 0; i < N; i++){
        cargar_clase(&clases_c[i]);
    }
    for(i = 0; i < N; i++){
        ordenar_alumnos(&clases_c[i]);
        }
    for(i = 0; i < N; i++){
        printf("\nClase %d\n", i + 1);
        mostrar_clase(clases_c[i]);
    }
    return 0;
}

void cargar_clase(t_clase* clases){
    printf("\nCARGA DE DATOS.\n\n");
    printf("Nivel: ");
    fgets(clases->nivel, 15, stdin);
    if(clases->nivel[strlen(clases->nivel) - 1] == '\n'){
        clases->nivel[strlen(clases->nivel) - 1] = '\0';
    }
    fflush(stdin);
    printf("Nombre del profesor: ");
    fgets(clases->profesor, 30, stdin);
    if(clases->profesor[strlen(clases->profesor) - 1] == '\n'){
        clases->profesor[strlen(clases->profesor) - 1] = '\0';
    }
    fflush(stdin);
    for(int i = 0; i < A; i++){
        cargar_alumno(&clases->alumnos[i]);
    }
}

void cargar_alumno(t_alumno* alumno){
    printf("\nDATOS DEL ALUMNO\n\n");
    printf("Nombre: ");
    fgets(alumno->nombre, 15, stdin);
    if(alumno->nombre[strlen(alumno->nombre) - 1] == '\n'){
        alumno->nombre[strlen(alumno->nombre) - 1] = '\0';
    }
    fflush(stdin);
    printf("Apellido: ");
    fgets(alumno->apellido, 15, stdin);
    if(alumno->apellido[strlen(alumno->apellido) - 1] == '\n'){
        alumno->apellido[strlen(alumno->apellido) - 1] = '\0';
    }
    fflush(stdin);
    alumno->fecha_nac.dia = rand() % (30 - 1 + 1) + 1;
    fflush(stdin);
    alumno->fecha_nac.mes = rand() % (12 - 1 + 1) + 1;
    fflush(stdin);
    alumno->fecha_nac.anio = rand() % (2010 - 2005 + 1) + 2005;
    fflush(stdin);
    for(int i = 0; i < C; i++){
        alumno->notas[i] = rand() % (10 - 1 + 1) + 1;
        fflush(stdin);
    }
}

void ordenar_alumnos(t_clase* clases){
    int i, j;
    char aux[15];
    for(i = 0; i < A; i++){
        for(j = 1; j < A; j++){
            if (clases->alumnos[j - 1].nombre[0] > clases->alumnos[j].nombre[0]){
                strncpy(aux, clases->alumnos[j].nombre, 15);
                strncpy(clases->alumnos[j].nombre, clases->alumnos[j - 1].nombre, 15);
                strncpy(clases->alumnos[j - 1].nombre, aux, 15);
            }
        }
    }
}

void mostrar_clase(t_clase clases){
    int i;
    printf("Nivel %s\n", clases.nivel);
    printf("Profesor %s\n", clases.profesor);
    for(i = 0; i < A; i++){
        mostrar_alumnos(clases.alumnos[i]);
        printf("\n");
    }
}

void mostrar_alumnos(t_alumno alumno){
    printf("Alumno: %s %s  Fecha de nacimiento: %d/%d/%d  ", alumno.nombre, alumno.apellido,
    alumno.fecha_nac.dia, alumno.fecha_nac.mes, alumno.fecha_nac.anio);
    printf("Notas: ");
    for (int i = 0; i < C; i++){
        printf("%d ", alumno.notas[i]);
    }
}