#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void emitir_datos(FILE* fp);

int main(){
    FILE* fp;
    fp = fopen("sueldos2.txt","r");
    emitir_datos(fp);
    fclose(fp);
}

void emitir_datos(FILE* fp){
    int suc, dpto, suc_ant, dpto_ant;
    long int emp;
    double sueldo;
    printf("\t\t\tREPORTE DE SUELDO\n\n\n");
    fscanf(fp, "%d,%d,%ld,%lf", &suc, &dpto, &emp, &sueldo);
    while (!feof(fp)){
        double acum_sueldo_suc = 0.0;
        suc_ant = suc;
        printf("SUCURSAL %d\n\n", suc);
        while (!feof(fp) && (suc_ant == suc)){
            printf("Codigo Departamento\tCodigo Empleado\t\tSueldo\n\n");
            double acum_sueldo_dpto = 0.0;
            dpto_ant = dpto;
            acum_sueldo_suc += sueldo;
            while (!feof(fp) && (dpto_ant == dpto)){
                acum_sueldo_dpto += sueldo;
                printf("\t%d\t\t\t%ld\t\t%.2f\n", dpto, emp, sueldo);
                fscanf(fp, "%d,%d,%ld,%lf", &suc, &dpto, &emp, &sueldo);
            }
            acum_sueldo_suc += acum_sueldo_dpto;
            printf("\nTotal Departamento\t\t\t\t%.2f\n\n", acum_sueldo_dpto);
            fscanf(fp, "%d,%d,%ld,%lf", &suc, &dpto, &emp, &sueldo);
        }
        printf("Total Sucursal\t\t%.2f\n\n", acum_sueldo_suc);
    }
}