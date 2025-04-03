#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Time {
    char nomeTime[30];
    int pontos;
};
typedef struct Time Time;

void calculoPontuacao(Time Equipes[], int size);
void classificacoes(Time Equipes[], int size);

int main() {
    FILE *arq;
    Time Equipes[10];
    char nomeTime1[30];
    int gols1;
    char nomeTime2[30];
    int gols2;
    int numJogos = 45;

    arq = fopen("TimesGols.txt", "rt");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int numTimes = 0;

    for (int i = 0; i < numJogos; i++) {
        fscanf(arq, "%s %d %s %d", nomeTime1, &gols1, nomeTime2, &gols2);

        int index1 = -1;
        for (int j = 0; j < numTimes; j++) {
            if (strcmp(Equipes[j].nomeTime, nomeTime1) == 0) {
                index1 = j;
                break;
            }
        }

        if (index1 == -1) {
            strcpy(Equipes[numTimes].nomeTime, nomeTime1);
            Equipes[numTimes].pontos = 0;
            numTimes++;
        }

        int index2 = -1;
        for (int j = 0; j < numTimes; j++) {
            if (strcmp(Equipes[j].nomeTime, nomeTime2) == 0) {
                index2 = j;
                break;
            }
        }

        if (index2 == -1) {
            strcpy(Equipes[numTimes].nomeTime, nomeTime2);
            Equipes[numTimes].pontos = 0;
            numTimes++;
        }

        if (gols1 > gols2) {
            Equipes[index1].pontos += 3;
        } else if (gols1 == gols2) {
            Equipes[index1].pontos += 1;
            Equipes[index2].pontos += 1;
        } else {
            Equipes[index2].pontos += 3;
        }
    }

    fclose(arq);

    int escolha;
    printf("Deseja ver as classificacoes?\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            classificacoes(Equipes, numTimes);
            break;
        case 2:
            printf("Ok... pode sair.\n");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }

    return 0;
}

void classificacoes(Time Equipes[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (Equipes[j].pontos < Equipes[j + 1].pontos) {
                Time temp = Equipes[j];
                Equipes[j] = Equipes[j + 1];
                Equipes[j + 1] = temp;
            }
        }
    }

    FILE *saida = fopen("classificacoes.txt", "wt");
    if (saida == NULL) {
        printf("Erro ao criar o arquivo de classificacoes.\n");
        return;
    }

    fprintf(saida, "Classificacoes:\n");
    for (int i = 0; i < size; i++) {
        fprintf(saida, "%dº Lugar: %s | Pontos: %d\n", i + 1, Equipes[i].nomeTime, Equipes[i].pontos);
    }

    fclose(saida);
    printf("Arquivo com as classificacoes criado!\n");
}

