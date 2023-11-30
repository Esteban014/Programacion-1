// En un archivo secuencial (de texto, por ejemplo “lluvias.txt”) se almacenan datos 
// sobre la lluvia caída en un cierto período. Cada línea corresponde a un día y 
// contiene los siguientes datos: 
// Día-Mes-Anio-Precipitaciones (0 si no llovió)  
// Preparar un algoritmo con los procedimientos necesarios para: 

// a) cargar los datos correspondientes a los 30 días del mes de septiembre del corriente año. 

// b) leer el archivo e informar por pantalla:cuántos días hubo sin lluvias, 
// cuántos días llovió  menos de 50 mm y cuántos llovió 50 mm ó más.  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define C 30

void cargar_archivo(FILE** fp, int c);
void dias_lluvia(FILE* fp);
int mas_menos_cero(int milimetros);

int main(void){
    FILE* fp = NULL;
    srand(time(NULL));
    cargar_archivo(&fp, C);
    dias_lluvia(fp);
    return 0;
}

void cargar_archivo(FILE** fp, int c){
    int dia, mes = 9, anio = 2023;
    *fp = fopen("lluvia.txt", "w");
    for(dia = 1; dia <= c; dia++){
        int mm = rand() % 101;
        fprintf(*fp, "%d - %d - %d - %d\n", dia, mes, anio, mm);
    }
    fclose(*fp);
}

void dias_lluvia(FILE* fp){
    int dia, mes, anio, milim;
    int cero = 0, mas = 0, menos = 0, contador = 0;
    fp = fopen("lluvia.txt", "r");
    fscanf(fp, "%d - %d - %d - %d\n", &dia, &mes, &anio, &milim);
    while(contador < 30){
        int opcion = mas_menos_cero(milim);
        switch (opcion)
        {
        case 1:
            cero++;
            break;
        case 2:
            mas++;
            break;
        default:
            menos++;
            break;
        }
        fscanf(fp, "%d - %d - %d - %d\n", &dia, &mes, &anio, &milim);
        contador++;
    }
    fclose(fp);
    printf("Dias sin lluvia: %d\nDias con lluvia menor a 50mm: %d\nDias con lluvia mayor o igual a 50mm: %d\n", cero, menos, mas);
}

int mas_menos_cero(int milimetros){
    int resultado;
    if(milimetros == 0){
        resultado = 1;
    }else if(milimetros >= 50){
        resultado = 2;
    }else{
        resultado = 3;
    }
    return resultado;
}