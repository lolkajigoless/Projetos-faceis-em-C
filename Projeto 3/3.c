/*
Conversor de Celsius para Fahrenheit e vice-versa.
*/
#include<stdio.h>

int main(){
int valor = 0;
char escolha;

do{

printf("1 - Celcius para Fahrenheit\n2 - Fahrenheit para Celsius\n0 - Sair\n: ");
scanf(" %c", &escolha);

    switch(escolha){
    case '1':
        printf("Coloque o valor de celcius para ser convertido para fahrenheit: ");
        scanf("%d", &valor);
        printf("%d C = %d F\n\n", valor, CelciusToFahrenheit(valor));
        break;

    case '2':
        printf("Coloque o valor de fahrenheit para ser convertido para celcius: ");
        scanf("%d", &valor);
        printf("%d F = %d C\n\n", valor, FahrenheitToCelcius(valor));
        break;

    case '0':
        printf("tchau");
        break;

    default:
        printf("Erro");
    }

}while(escolha != '0');

return 0;
}

int CelciusToFahrenheit(int valor){
int fah = (valor * 9/5) + 32;
return fah;
}

int FahrenheitToCelcius(int valor){
int cel = (valor - 32) * 5/9;
return cel;
}


