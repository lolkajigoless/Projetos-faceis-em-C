/*
Objetivo: Fazer cadastro de Alunos:

* Permita ao usuário cadastrar vários alunos, informando:
    - Nome (string)
    - Idade (int)
    - Nota final (float)

* O usuário deve digitar 1 para encerrar o cadastro.

* Cada aluno deve ser salvo em um arquivo alunos.txt, um por linha, no seguinte formato: Nome,Idade,Nota

* Depois do cadastro, o programa deve abrir o arquivo e ler todos os alunos, exibindo no terminal
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(){

FILE *arq;
int escolha = 0, idade = 0;
char nome[50],nota[50];
float nota_final = 0.0;

arq = fopen("alunos.txt", "a+"); // abre para leitura e escrita no final
fseek(arq, 0, SEEK_END);
if (ftell(arq) == 0) { // arquivo vazio
    fprintf(arq, "Nome,Idade,Nota\n\n");
}
fclose(arq);


do{

printf("1 - cadastrar alunos\n0 - sair\n:");
scanf("%d", &escolha);
while(getchar() != '\n'); // limpa o buffer após scanf

if(escolha == 0){
    printf("tchau\n");
    break;
}
else if(escolha == 1){

printf("Nome do aluno: ");
fgets(nome, sizeof(nome), stdin);
nome[strcspn(nome, "\n")] = '\0';

printf("Idade do aluno: ");
scanf("%d", &idade);
while(getchar() != '\n'); // limpa o buffer após scanf

printf("Nota Final do aluno: ");
fgets(nota, sizeof(nota), stdin);
nota[strcspn(nota, "\n")] = '\0';
for(int i = 0; nota[i] != '\0'; i++){
    if(nota[i] == ','){
        nota[i] = '.';
    }
}
printf("\n");

arq = fopen("alunos.txt", "a");
if(arq == NULL){
    printf("Erro ao abrir o arquivo.\n");
    return 1;
}
// fprintf -> é o printf sp que escreve em arquivo;
fprintf(arq, "%s,%d,%s\n", nome,idade,nota);
/*
fprintf(arq, "Idade: %d\n", idade);
fprintf(arq, "Nota: %s\n", nota);
*/
fputs("----\n", arq); // separador entre alunos
fclose(arq);
}
else{
    printf("Erro: Nenhuma opcao selecionada");
    continue;
}

}
while(1);
printf("Cadastro de alunos(as) feito com sucesso!\n");
printf("------------------------------------------\n\n");
printf("Alunos cadastrados: \n\n");

arq = fopen("alunos.txt", "r");
if(arq != NULL){
    char texto[100];

    while(fgets(texto, 100, arq) != NULL){
        printf(texto);
    }
    fclose(arq);
}
fclose(arq);
return 0;
}

