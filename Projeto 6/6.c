 // Objetivo: Tabuada salva em arquivo

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main() {

/*
time_t é um tipo de dado usado para armazenar tempo em segundos desde 1 de janeiro de 1970 (Epoch time).
A variável agora vai guardar o tempo atual do sistema.
*/
time_t agora;

/*
struct tm é uma estrutura que armazena a data/hora detalhadamente, com campos como:
tm_mday → dia do mês (1 a 31)
tm_mon → mês (0 a 11)
tm_year → anos desde 1900
tm_hour, tm_min, tm_sec, etc.

infoTempo será um ponteiro para essa estrutura.
*/
struct tm *infoTempo;

time(&agora);  // pega o tempo atual em segundos (Unix time)

/*
Converte os segundos (agora) para uma data legível (local), armazenando no formato struct tm.
A função localtime() retorna um ponteiro para uma estrutura tm com o tempo convertido para fuso local.
*/
infoTempo = localtime(&agora);  // converte esse tempo para data/hora local

FILE *arquivo;
char conta[50], frase[20];
int resultado,escolha = 0;
arquivo = fopen("tabuadas.txt", "a");
if(arquivo == NULL){
    printf("Erro ao abrir o arquivo.\n");
    return 1;
}

printf("Escolha uma tabuada entre 1 a 20: ");
scanf("%d", &escolha);

if(escolha < 1 || escolha > 20){
    printf("Número inválido. Digite de 1 a 20.\n");
    return 1;
}

/*
sprintf -> serve para escrever dados formatados em uma string, em vez de imprimir na tela;
ex:
    char buffer[100];
    int idade = 25;
    sprintf(buffer, "Minha idade é %d anos.", idade);
    printf("%s\n", buffer);  // saída: Minha idade é 25 anos.
*/

sprintf(frase, "Tabuada do %d (%02d/%02d/%04d):\n", escolha, infoTempo->tm_mday, // Dia do mês (com 2 dígitos, ex: 07)
                                                    infoTempo->tm_mon + 1, // Mês do ano (de 1 a 12 — somamos 1 pois começa em 0)
                                                    infoTempo->tm_year + 1900); // Ano (ex: 125 → 2025, pois tm_year é contado desde 1900)
fputs(frase, arquivo);

for(int i = 1; i <= 10; i++){

    resultado = escolha * i;

    if(i == 10){
        sprintf(conta, "%d * %d = %d\n\n", escolha, i, resultado);
        fputs(conta, arquivo);
        }
    else{
        sprintf(conta, "%d * %d = %d\n", escolha, i, resultado);
        fputs(conta, arquivo);
    }
    }
    printf("Tabuada salva no arquivo com sucesso!");
    fclose(arquivo);

return 0;
}
