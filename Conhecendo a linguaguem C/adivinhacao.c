#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();

    int numerosecreto = numerogrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    while (1)
    {

        printf("Tentativa %d \n", tentativas);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi %d.\n", chute);

        if (chute < 0)
        {
            printf("Você não pode chutar números negativos! \n");
            continue;
        }

        int acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if (acertou)
        {
            printf("Parabéns ! Você acertou !\n");
            break;
        }
        else if (maior)
        {
            printf("Seu chute foi maior que o número secreto\n");
        }
        else
        {
            printf("Seu chute foi menor que o número secreto\n");
        }
        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }
    printf("Fim de Jogo\n");
    printf("Você acertou em %d de tentativas ! \n", tentativas);
    printf("Total de pontos: %.1f  \n", pontos);
}