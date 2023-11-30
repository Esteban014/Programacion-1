#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void corte_bancario(FILE* fp){
    int codi,nrocuenta,nro_cuenta_ant;
    double importe;
    rewind(fp);
    printf("\n\tNUMERO DE CUENTA\tSALDO\n\n");
    fscanf(fp,"%d,%d,%lf",&nrocuenta,&codi,&importe);
    while (!feof(fp)){
        double saldoneto = 0.00;
        nro_cuenta_ant = nrocuenta;
        while (!feof(fp) && (nrocuenta == nro_cuenta_ant)){
            if (codi == 1){
                saldoneto += importe;
            }
            else{
                saldoneto -= importe;
            }
            fscanf(fp,"%d,%d,%lf",&nrocuenta,&codi,&importe);
        }
        printf("\t%d\t\t%.2f\n", nro_cuenta_ant, saldoneto);
        fscanf(fp,"%d,%d,%lf",&nrocuenta,&codi,&importe);
    }
}
int main(){
    FILE* fp;
    fp = fopen("movimientos.txt","r");
    corte_bancario(fp);
    fclose(fp);
    return 0;
}


/*3- Producir un informe con los sueldos de los empleados de una compañía, emitiendo subtotales por departamento y por sucursal. 
Cada empleado tiene un único registro en el archivo maestro de nómina con los siguientes datos:
• Código de sucursal (cod_suc:entero)
• Código de departamento  (cod_dpto:entero)
• Código de empleado  (cod_emp:entero)
• Sueldo mensual (sueldo:real)
El archivo está ordenado en forma ascendente por código de sucursal y, dentro de sucursal por departamento (Archivo sueldos2.txt)
*/