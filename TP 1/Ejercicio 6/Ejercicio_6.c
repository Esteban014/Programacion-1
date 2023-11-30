#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cadenas(char a[], char b[], char c[]){
    char nuevo[10];
    int j = 0, resultado;
    for(int i = 0; i < 3; i++){
        nuevo[j++] = a[i];
    }
    for(int i = 0; i < 3; i++){
        nuevo[j++] = b[i];
    }
    for(int i = 0; i < 3; i++){
        nuevo[j++] = c[i];
    }
    nuevo[j] = '\0';
    printf("%s\n", nuevo);
    if(strncmp (a, b, 40) == 0 && strncmp(b, c, 40) == 0){
        resultado = 3;
    }else if(strncmp(b, c, 40) == 0){
        resultado = 2;
    }else if(strncmp(a, b, 40) == 0){
        resultado = 0;
    }else{
        resultado = 4;
    }
    return resultado;
}

int main(){
    char x[40], y[40], z[40];
    int result;
    printf("Ingrese una frase: ");
    fgets(x, 40, stdin);
    printf("Ingrese otra frase: ");
    fgets(y, 40, stdin);
    printf("Ingrese una frase mas: ");
    fgets(z, 40, stdin);
    result = cadenas(x, y, z);
    printf("%d\n", result);
    system("pause");
    return 0;
}