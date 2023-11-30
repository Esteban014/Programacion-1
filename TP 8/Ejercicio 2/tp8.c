#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


//ejercicio 1
// void crear(char nom_arch[],char modo[]){
//     FILE *arch;
//     arch=fopen(nom_arch,modo);
//     fclose(arch);
// }

// void carga_empleado(char nom_arch[],char modo[]){
//     srand(time(NULL));
//     FILE *arch;
//     arch=fopen(nom_arch,modo);
//     int sucursal,empleado;
//     float sueldo;
//     printf("ingrese la sucursal o 0 para salir: ");
//     scanf("%i",&sucursal);
//     while (sucursal!=0)
//     {
//         empleado=rand() % 500;
//         printf("ingrese el sueldo: ");
//         scanf("%f",&sueldo);
//         fprintf(arch,"%i-%i-%f\n",sucursal,empleado,sueldo);
//         printf("ingrese la sucursal o 0 para salir: ");
//         scanf("%i",&sucursal);
//     }
//    fclose(arch);
// }

// void corte(char nom_arch1[]){
//     int sucursal,empleado;
//     float sueldo;
//     int sucursal_ant;
//     float total_sucursal;
//     FILE *arch;
//     arch=fopen(nom_arch1,"r");
//     rewind(arch);
//     fscanf(arch,"%i-%i-%f",&sucursal,&empleado,&sueldo);
//     while (!feof(arch))
//     {
//         sucursal_ant=sucursal;
//         total_sucursal=0.0;
//         while (!feof(arch) && sucursal==sucursal_ant)
//         {
//             total_sucursal=total_sucursal + sueldo;
//             fscanf(arch,"%i-%i-%f",&sucursal,&empleado,&sueldo);
//         }
//         printf(" El total de sueldos de la sucursal %i es: %.2f\n",sucursal_ant,total_sucursal);
//     }
    
// }

// int main(){
//     char nombre[]= "sueldos.txt";
//     char modow[]="w";
//     crear(nombre,modow);
//     carga_empleado(nombre,modow);
//     corte(nombre);
//     system("Pause");
// }

//ejercicio 2
//1 es deposito 2 es extraccion

void corte(FILE* arch){
    int cuenta,movimiento;
    float importe;
    int cuenta_ant;
    float total_importe;
    rewind(arch);
    fscanf(arch,"%i,%i,%f",&cuenta,&movimiento,&importe);
    while (!feof(arch))
    {
        cuenta_ant=cuenta;
        total_importe=0.0;
        while (!feof(arch) && cuenta==cuenta_ant)
        {
            if(movimiento==1){
                total_importe=total_importe+ importe;
            }
            else if (movimiento==2)
            {
                total_importe=total_importe-importe;
            }
            
            fscanf(arch,"%i,%i,%f",&cuenta,&movimiento,&importe);
        }
        printf(" Numero de cuenta: %i \t\t\t Saldo:%.2f\n",cuenta_ant,total_importe);
    }
    
}

int main(){
    FILE* fp;
    fp = fopen("movimientos.txt", "r");
    corte(fp);
    fclose(fp);
    system("Pause");
}


//ejercicio 3

// void crear(char nom_arch[],char modo[]){
//     FILE *arch;
//     arch=fopen(nom_arch,modo);
//     fclose(arch);
// }

// void carga_empleado(char nom_arch[],char modo[]){
//     srand(time(NULL));
//     FILE *arch;
//     arch=fopen(nom_arch,modo);
//     int sucursal,empleado,departamento;
//     float sueldo;
//     printf("ingrese la sucursal o 0 para salir: ");
//     scanf("%i",&sucursal);
//     while (sucursal!=0)
//     {
//         printf("ingrese el departamento: ");
//         scanf("%i",&departamento);
//         empleado=rand() % 500;
//         printf("ingrese el sueldo: ");
//         scanf("%f",&sueldo);
//         fprintf(arch,"%i-%i-%i-%f\n",sucursal,departamento,empleado,sueldo);
//         printf("ingrese la sucursal o 0 para salir: ");
//         scanf("%i",&sucursal);
//     }
//    fclose(arch);
// }

// void corte(char nom_arch1[]){
//     int sucursal,departamento,empleado;
//     float sueldo;
//     int sucursal_ant,departamento_ant;
//     float total_sucursal,total_departamento;
//     FILE *arch;
//     arch=fopen(nom_arch1,"r");
//     rewind(arch);
//     fscanf(arch,"%i-%i-%i-%f",&sucursal,&departamento,&empleado,&sueldo);
//     while (!feof(arch))
//     {
//         sucursal_ant=sucursal;
//         total_sucursal=0.0;
//         while (!feof(arch) && sucursal==sucursal_ant)
//         {
//             total_sucursal=total_sucursal + sueldo;
//             departamento_ant=departamento;
//             total_departamento=0.0;
//             while (!feof(arch) && departamento==departamento_ant)
//             {
//                 total_departamento=total_departamento+sueldo;
//                 fscanf(arch,"%i-%i-%i-%f",&sucursal,&departamento,&empleado,&sueldo);
//             }
//             printf("REPORTE DE SUELDO\n\n");
//             printf("SUCURSAL %i\n",sucursal_ant);
//             printf(" Codigo departamento %i\t\t Total Departamento:%.2f\n",departamento_ant,total_departamento);
//             fscanf(arch,"%i-%i-%i-%f",&sucursal,&departamento,&empleado,&sueldo);
//         }
        
//         printf("Total sucursal: %.2f\n",total_sucursal);
//     }
    
// }

// int main(){
//     char nombre[]= "sueldos2.txt";
//     char modow[]="w";
//     crear(nombre,modow);
//     carga_empleado(nombre,modow);
//     corte(nombre);
//     system("Pause");
// }