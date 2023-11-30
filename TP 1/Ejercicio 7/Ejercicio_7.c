#include <stdio.h>

void promedio(float a, float b){
    float prom = (a + b) / 2;

    if (prom >= 7 && a >= 7 && b >= 7){
        printf("Promovido");
    }
    else if(prom < 7 && a >= 4 && b >= 4){
        printf("Regular");
    }
    else{
       printf("Libre");
    }
}

int main(){
    float nota1, nota2;
    printf("Ingrese la primer nota: \n");
    scanf("%f", &nota1);
    printf("Ingrese la segunda nota: \n");
    scanf("%f", &nota2);
    promedio(nota1, nota2);
    return 0;
}