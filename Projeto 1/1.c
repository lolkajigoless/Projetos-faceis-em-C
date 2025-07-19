#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tamanho = 15;
    char senha[tamanho + 1];  // espaço suficiente (+1 para '\0')

    gerarSenha(tamanho, senha);  // gera senha

    printf("Senha final no main: %s\n", senha);  // imprime no main também
    return 0;
}

void gerarSenha(int tamanho, char *destino) {
    char letras[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numeros[] = "0123456789";
    char simbolos[] = "!@#$%&*?";

    char senha[tamanho + 1]; // array local para a senha

    srand(time(NULL));  // semente do rand baseada no tempo

    for (int i = 0; i < tamanho; i++) {
        int tipo = rand() % 3;  // decide se vai ser letra, número ou símbolo

        if (tipo == 0) {
            int ind = rand() % (sizeof(letras) - 1);
            senha[i] = letras[ind];
        } else if (tipo == 1) {
            int ind = rand() % (sizeof(numeros) - 1);
            senha[i] = numeros[ind];
        } else {
            int ind = rand() % (sizeof(simbolos) - 1);
            senha[i] = simbolos[ind];
        }
    }

    senha[tamanho] = '\0';  // finaliza a string

    strcpy(destino, senha);  // copia para o array original no main
}
