// Objetivo: Escrever nomes digitados pelo usuário num arquivo;

#include<stdio.h>;
#include <stdlib.h>
#include <string.h>

int main() {

    // FILE *arquivo;
    // -> Declara um ponteiro para arquivo. Ele será usado para abrir, ler ou escrever em arquivos.
    // Exemplo: FILE *arquivo = fopen("dados.txt", "w");
    FILE *arquivo;

    char nome[100];

    printf("Digite nomes para salvar (digite 'sair' para encerrar):\n");

    // o 1 representa verdadeiro, entao é a mesma coisa que true em java;
    while(1){

    printf("Nome: ");
    fgets(nome, 100, stdin);

    // strcspn(string, "\n");
    // -> Encontra a posição do primeiro '\n' na string e ajuda a removê-lo.
    // Muito útil depois do fgets.
    // Exemplo: nome[strcspn(nome, "\n")] = '\0';
    nome[strcspn(nome, "\n")] = '\0';

    // strcmp(str1, str2);
    // -> Compara duas strings. Retorna 0 se forem iguais.
    // Usado para verificar se o usuário digitou "sair" ou outra palavra-chave.
    // Exemplo: if (strcmp(nome, "sair") == 0) break;
    if (strcmp(nome, "sair") == 0) {
            break;
    }

    if (nome[0] == '\0') {
            printf("Nome vazio ignorado.\n");
            continue;
        }

    // fopen("arquivo.txt", "modo");
    // -> Abre ou cria um arquivo com o modo desejado ("w", "a", "r").
    // "w": escreve do zero (apaga o conteúdo)
    // "a": adiciona no final sem apagar
    // "r": apenas leitura (arquivo precisa existir)
    // Exemplo: arquivo = fopen("nomes.txt", "a");
    arquivo = fopen("nomes.txt", "a");
    if(arquivo == NULL){
         printf("Erro ao abrir o arquivo.\n");
         return 1;
    }

    // fputs(string, arquivo);
    // -> Escreve uma string no arquivo. Não adiciona \n automaticamente.
    // Exemplo: fputs(nome, arquivo); fputs("\n", arquivo);
    fputs(nome, arquivo);
    fputs("\n", arquivo);


    // fclose(arquivo);
    // -> Fecha o arquivo. Muito importante para garantir que tudo foi salvo corretamente.
    // Exemplo: fclose(arquivo);
    fclose(arquivo);
    }

   printf("Nomes salvos no arquivo 'nomes.txt'\n");
   return 0;
}
