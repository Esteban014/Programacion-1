/*2.    Hacer un programa que almacene en un arreglo de registros la siguiente información de N trabajadores:
 nombre, edad, sexo (F o M), estado civil(S(soltero), C(casado), D(divorciado) y O(otro)) y salario base.
Calcular y mostrar por pantalla la cantidad de trabajadores del sexo masculino, la cantidad de trabajadoras 
casadas, el nombre del/a empleado/a más joven y la suma de todos los salarios.
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 5

typedef struct{
    char nombre[30];
    int edad;
    char sexo;
    char estado_civil;
    long int salario;
} t_trabajador;

typedef t_trabajador t_empleados[N];

void cargar(t_trabajador* empleado);
int hombres(t_trabajador* empleados, int n);
int casadas(t_trabajador* empleados, int n);
int joven(t_trabajador* empleados, int n);
long int salarios(t_trabajador* empleados, int n);
void mostrar(t_trabajador empleado);

int main(){
    int i;
    t_empleados empleados;
    srand(time(NULL));
    for(i = 0; i < N; i++){
        cargar(&empleados[i]);
    }
    int h = hombres(empleados, N);
    int c = casadas(empleados, N);
    int j = joven(empleados, N);
    long int s = salarios(empleados, N);
    for(i = 0; i < N; i++){
        mostrar(empleados[i]);
    }
    printf("La cantidad de hombres es de %d\n", h);
    printf("La cantidad de trabajadoras casadas es de %d\n", c);
    printf("El/La trabajador/a mas joven es %s\n", empleados[j].nombre);
    printf("La suma de todos los salarios es de %ld", s);
    return 0;
}

void cargar(t_trabajador *empleado){
    printf("\nINGRESO DE DATOS\n\n");
    printf("Nombre y apellido: ");
    fgets(empleado->nombre, 30, stdin);
    if (empleado->nombre[strlen(empleado->nombre) - 1]  == '\n'){
        empleado->nombre[strlen(empleado->nombre) - 1]  = '\0';
    }
    fflush(stdin);
    printf("\nEdad: ");
    scanf("%d", &empleado->edad);
    fflush(stdin);
    printf("\nSexo(F o M): ");
    scanf("%c", &empleado->sexo);
    fflush(stdin);
    empleado->sexo = toupper(empleado->sexo);
    fflush(stdin);
    printf("\nEstado civil (S(soltero), C(casado), D(divorciado) u O(otro)): ");
    scanf("%c", &empleado->estado_civil);
    empleado->estado_civil = toupper(empleado->estado_civil);
    fflush(stdin);
    empleado->salario = rand() % (300000 - 60000 + 1) + 60000;
}

int hombres(t_trabajador* empleados, int n){
    int i, contador = 0;
    for(i = 0; i < n; i++){
        if (empleados[i].sexo == 'M'){
            contador += 1;
        }
    }
    return contador;
}

int casadas(t_trabajador* empleados, int n){
    int i, contador = 0;
    for(i = 0; i < n; i++){
        if ((empleados[i].sexo == 'F') && (empleados[i].estado_civil == 'C')){
            contador += 1;
        }
    }
    return contador;
}

int joven(t_trabajador* empleados, int n){
    int i, mas_joven = 100, pos;
    for(i = 0; i < n; i++){
        if (empleados[i].edad < mas_joven){
            mas_joven = empleados[i].edad;
            pos = i;
        }
    }
    return pos;
}

long int salarios(t_trabajador* empleados, int n){
    int i;
    long int acumulador = 0;
    for(i = 0; i < n; i++){
        acumulador += empleados[i].salario;
    }
    return acumulador;
}

void mostrar(t_trabajador empleado){
    printf("Nombre y apellido: %s", empleado.nombre);
    printf("Edad: %d", empleado.edad);
    printf("Sexo: %c", empleado.sexo);
    printf("Estado Civil: %c", empleado.estado_civil);
    printf("Salario %ld\n", empleado.salario);
}