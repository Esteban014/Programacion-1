#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float promedio(float, float);

int main(){
    float alumnos, nota1, nota2;
    float promedios = 0;
    float promedio_curso;
    srand (time(NULL));
    printf("Ingrese la cantidad de alumnos: \n");
    scanf("%f", &alumnos);
    for(int i = 1; i <= alumnos; i++){
        nota1 = rand()%11;
        nota2 = rand()%11;
        printf("%.2f\n", nota1);
        printf("%.2f\n", nota2);
        promedios += promedio(nota1, nota2);
    }
    promedio_curso = promedios / alumnos;
    printf("%.2f %.2f\n", promedios, alumnos);
    printf("El promedio del curso es: %.2f\n", promedio_curso);
    system("pause");
    return 0;
}

float promedio(float a, float b){
    float prom = (a + b) / 2.0;
    return prom;
}