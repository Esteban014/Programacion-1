// En una estación meteorológica se registra diariamente la temperatura máxima y 
// mínima de todo un año con el siguiente diseño:
//         Día-Mes-Anio-Temperatura_Maxima-Temperatura_Minima (éstos dos 
//         últimos se pueden generar aleatoriamente).
// Preparar un algoritmo con los procedimientos necesarios para: 
// a) cargar los datos correspondientes a todos los días del corriente año en un archivo llamado “ temperaturas.txt”. 
// b) imprima por pantalla un reporte como el siguiente: 
// TEMPERATURA: INFORME ANUAL  
// Temperatura Mínima Del Año: xx 
// Registrada el Día: xx 
// Del Mes: xx 
// Temperatura Máxima Del Año: xx 
// Registrada el Día: xx 
// Del Mes: xx 
// Máxima Amplitud 
// Térmica: xx  
// Registrada el Día: xx  
// Del Mes: xx  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define A 2023

void cargar_archivo(FILE* fp, int a);
void minima(FILE* fp);
void maxima(FILE* fp);
void max_amplitud(FILE* fp);
int amplitud(int max, int min);

int main(void){
    FILE* arch;
    arch = fopen("temperaturas.txt", "w");
    fclose(arch);
    srand(time(NULL));
    cargar_archivo(arch, A);
    printf("\t\tTEMPERATURA: INFORME ANUAL\n");
    minima(arch);
    maxima(arch);
    max_amplitud(arch);
    return 0;
}

void cargar_archivo(FILE* fp, int a){
    int i, j;
    int temp_max, temp_min;
    fp = fopen("temperaturas.txt", "w");
    for(j = 1; j <= 12; j++){
        if(j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12){
            for(i = 1; i <= 31; i++){
                temp_min = rand() % (20 - (- 10) + 1) - 10;
                temp_max = rand() % (40 - 21 + 1) + 21;
                fprintf(fp, "%d - %d - %d - %d - %d\n", i, j, a, temp_min, temp_max);
            }
        }else if(j == 2){
            for(i = 1; i <= 28; i++){
                temp_min = rand() % (20 - (- 10) + 1) - 10;
                temp_max = rand() % (40 - 21 + 1) + 21;
                fprintf(fp, "%d - %d - %d - %d - %d\n", i, j, a, temp_min, temp_max);
            }
        }else{
            for(i = 1; i <= 30; i++){
                temp_min = rand() % (20 - (- 10) + 1) - 10;
                temp_max = rand() % (40 - 21 + 1) + 21;
                fprintf(fp, "%d - %d - %d - %d - %d\n", i, j, a, temp_min, temp_max);
            }
        }
    }
    fclose(fp);
}

void minima(FILE* fp){
    int dia, mes, anio, min, max;
    int dia_min, mes_min, temp_min = 50;
    fp = fopen("temperaturas.txt", "r");
    fscanf(fp, "%d - %d - %d - %d - %d", &dia, &mes, &anio, &min, &max);
    while(!feof(fp)){
        if(min < temp_min){
            temp_min = min;
            dia_min = dia;
            mes_min = mes;
        }
        fscanf(fp, "%d - %d - %d - %d - %d", &dia, &mes, &anio, &min, &max);
    }
    fclose(fp);
    printf("\t\tTemperatura Minima Del A%co: %d\n\t\tRegistrada el Dia: %d\n\t\tDel Mes: %d\n\n", 164, temp_min, dia_min, mes_min);
}

void maxima(FILE* fp){
    int dia, mes, anio, min, max;
    int dia_max, mes_max, temp_max = 0;
    fp = fopen("temperaturas.txt", "r");
    fscanf(fp, "%d - %d - %d - %d - %d", &dia, &mes, &anio, &min, &max);
    while(!feof(fp)){
        if(max > temp_max){
            temp_max = max;
            dia_max = dia;
            mes_max = mes;
        }
        fscanf(fp, "%d - %d - %d - %d - %d", &dia, &mes, &anio, &min, &max);
    }
    fclose(fp);
    printf("\t\tTemperatura Maxima Del A%co: %d\n\t\tRegistrada el Dia: %d\n\t\tDel Mes: %d\n\n", 164, temp_max, dia_max, mes_max);
}

void max_amplitud(FILE* fp){
    int dia, mes, anio, min, max;
    int dia_ma, mes_ma, amp, max_amp = 0;
    fp = fopen("temperaturas.txt", "r");
    fscanf(fp, "%d - %d - %d - %d - %d", &dia, &mes, &anio, &min, &max);
    while(!feof(fp)){
        amp = amplitud(max, min);
        if(amp > max_amp){
            max_amp = amp;
            dia_ma = dia;
            mes_ma = mes;
        }
        fscanf(fp, "%d - %d - %d - %d - %d", &dia, &mes, &anio, &min, &max);
    }
    fclose(fp);
    printf("\t\tMaxima Amplitud Termica: %d\n\t\tRegistrada el Dia: %d\n\t\tDel Mes: %d\n", max_amp, dia_ma, mes_ma);
}

int amplitud(int max, int min){
    return max - min;
}