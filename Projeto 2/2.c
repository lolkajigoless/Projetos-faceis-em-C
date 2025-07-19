/*
O computador escolhe um n�mero secreto aleat�rio, e o jogador tenta adivinhar. O programa diz se o palpite est� acima, abaixo ou correto.
O jogo continua at� o jogador acertar.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int tentativas = 0, numero_aleatorio = 0, numero_usuario = 0;
     srand(time(NULL));
     numero_aleatorio = rand() % 100 + 1;

    printf("Bem vindo ao game de adivinhacao\n");
do{

  printf("digite seu palpite(1 - 100): ");
  scanf("%d", &numero_usuario);
  tentativas++;

  if(numero_usuario > numero_aleatorio){
   printf("O numero digitado esta acima!\n");
  }
  else if(numero_usuario < numero_aleatorio){
    printf("O numero digitado esta abaixo!\n");
  }
  else{
    printf("Voce ganhou!!!! parabens!!!\n\n");
  }

}while(numero_usuario != numero_aleatorio);
return 0;
}
