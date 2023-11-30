#include <stdio.h>
#include <stdlib.h>

void tipo_bomba(int x){
    switch (x)
    {
    case 0:
        printf("No hay establecido un valor definido para el tipo de bomba");
        break;
    case 1:
        printf("La bomba es una bomba de agua");
        break;
    case 2:
        printf("La bomba es una bomba de gasolina");
        break;
    case 3:
        printf("La bomba es una bomba de hormigon");
        break;
    case 4:
        printf("La bomba es una bomba de pasta alimenticia");
        break;
    default:
        printf("No existe un valor valido paa el tipo de bomba");
    }
}

int main(){
    int bomba;
    printf("Ingrese un valor entre 0 y 4: ");
    scanf("%d", &bomba);
    tipo_bomba(bomba);
    return 0;
}