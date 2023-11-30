#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tipo_bomba(int x){
    switch (x)
    {
    case 0:
        printf("No hay establecido un valor definido para el tipo de bomba\n");
        break;
    case 1:
        printf("La bomba es una bomba de agua\n");
        break;
    case 2:
        printf("La bomba es una bomba de gasolina\n");
        break;
    case 3:
        printf("La bomba es una bomba de hormigon\n");
        break;
    case 4:
        printf("La bomba es una bomba de pasta alimenticia\n");
        break;
    default:
        printf("No existe un valor valido para el tipo de bomba\n");
    }
}

int main(){
    int numero;
    srand(time(NULL));
    numero = rand()%11;
    while(numero != 9){
        printf("%d\n", numero);
        tipo_bomba(numero);
        numero = rand()%11;
    }
    printf("\n--------------\n");
    printf("-----FIN.-----\n\n");
    return 0;
}