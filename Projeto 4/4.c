// Objetivo: Inverter uma string;

#include<stdio.h>
#include<stdlib.h>

int main(){

    char digitado[20];
    printf("Digite algo e ele saira com os caracteres ao contrario: ");
    fgets(digitado, 20, stdin);
    /*
     usa strcspn(digitado, "\n") para descobrir onde está
     o \n (caso ele tenha sido lido);
    */
    digitado[strcspn(digitado, "\n")] = '\0'; // ← depois remove '\n'

    int len = strlen(digitado);
    printf("Invertido: ");
    for(int i = len - 1; i >= 0; i--){
            // Imprime um caractere sozinho, sem usar %c nem printf.
            putchar(digitado[i]);
    }
    printf("\n");

return 0;
}
