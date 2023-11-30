/*6.En un arreglo M(3, 4, 20) donde el primer índice señala número de centro de estudios, el 
segundo el número de  curso y el tercero el número alumno, se almacenan en cada celda, las 
notas de los alumnos.  Se solicita:
●	La nota media por curso.
●	La nota media por centro.
●	La nota media general. 
●	La posición del mejor alumno de cada curso con su correspondiente nota. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Z 3
#define Y 4
#define X 20

void cargar(int M[][Y][X], int z, int y, int x);
void mostrar(int M[][Y][X], int z, int y, int x);
//void promedios(int M[][Y][X], int z, int y, int x);

int main(){
    int M[Z][Y][X];
    srand(time(NULL));
    cargar(M, Z, Y, X);
    mostrar(M, Z, Y, X);
    //promedios(M, Z, Y, X);
    system("pause");
    return 0;
}

void cargar(int M[][Y][X], int z, int y, int x){
    int p, f, c;
    for(p = 0; p < z; p++){
        for(f = 0; f < y; f++){
            for(c = 0; c < x; c++){
                M[p][f][c] = rand() % (10 - 1 + 1) + 1;
            }
        }
    }
}

void mostrar(int M[][Y][X], int z, int y, int x){
    int p, f, c;
    for(p = 0; p < z; p++){
        printf("Centro de estudio %d\n\n", p + 1);
        for(f = 0; f < y; f++){
            printf("Curso %d -", f + 1);
            for(c = 0; c < x; c++){
                printf(" %d", M[p][f][c]);
            }
            printf("\n");
        }
        printf("\n");
    }
}