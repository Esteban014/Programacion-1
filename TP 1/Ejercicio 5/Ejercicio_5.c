#include <stdio.h>
#include <string.h>

int contar_letras(char[]);
void mostrar(char[]);

int main(){
    char texto[100];
    int longi;
    printf("Ingrese texto: ");
    fgets(texto, 100, stdin);
    longi = contar_letras(texto);
    printf("La cantidad de letras es de %d\n", longi);
    mostrar(texto);
    return 0;
}

int contar_letras(char a[]){
    int j = 0;
    int i = 0;
    while(a[i] != '\0'){
        if(a[i] != '\n'){
            j++;
        }
        else{
            j--;
        }
        i++;
    }
    return j;
}

void mostrar(char a[100]){
    for(int i = 0; a[i] != '\0'; i++){
        if(a[i] == ' '){
            printf("\n");
        }
        else{
            printf("%c", a[i]);
        }
    }
}