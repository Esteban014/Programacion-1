/*4.Realizar un programa que permita generar aleatoriamente las 
temperaturas mínimas y máximas correspondientes a los 30 días de un 
mes. Calcular y mostrar:
    ●	Promedio de temperaturas en el mes.
    ●	Día de máxima temperatura con su correspondiente temperatura.
    ●	Día de mínima temperatura con su correspondiente temperatura.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define F 30
#define C 2

void carga(int dias[][C], int f);
void promedio(int dias[][C], int f, int c);
void max_min_temp(int dias[][C], int f, int c);

int main(){
    int dias[F][C];
    srand(time(NULL));
    carga(dias, F);
    promedio(dias, F, C);
    max_min_temp(dias, F, C);
    return 0;
}

void carga(int dias[][C], int f){
    printf("Dia Minima Maxima\n");
    for(int i = 0; i < f; i++){
        dias[i][0] = rand() % (10 - (- 10) + 1) - 10;
        dias[i][1] = rand() % (30 - 10 + 1) + 10;
        printf("%d    %d   %d\n", i + 1, dias[i][0], dias[i][1]);
    }
}

void promedio(int dias[][C], int f, int c){
    int i, j;
    float acumulador = 0; 
    for(i = 0; i < f; i++){
        for(j = 0; j < c; j++){
            acumulador += dias[i][j];
        }
    }
    printf("El promedio del mes es de %.2f\n", (acumulador / 30));
}

void max_min_temp(int dias[][C], int f, int c){
    int i, j, max = -11, min = 40, pos_max = 0, pos_min = 0;
    for(i = 0; i < f; i++){
        for(j = 0; j < c; j++){
            if(dias[i][j] > max){
                max = dias[i][j];
                pos_max = i;
            }else if(dias[i][j] < min){
                min = dias[i][j];
                pos_min = i;
            }
        }
    }
    printf("El dia %d fue el dia de mayor temperatura de °%d y el dia %d fue el de la menor temperatura de °%d\n", pos_max + 1, max, pos_min + 1, min);
}