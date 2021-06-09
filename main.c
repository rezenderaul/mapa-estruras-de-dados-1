#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define QUEUE_MAX 5
#define CHAR_MAX 10

struct activity
{
    char ra[CHAR_MAX];
    char file[CHAR_MAX];
    char extension[CHAR_MAX];
    char registration[CHAR_MAX];
};

struct activity activities;

struct activity_queue
{
    struct activity data[QUEUE_MAX];
    int init;
    int end;
};

struct activity_queue queue;

void queueAdd()
{
    if (queue.end == QUEUE_MAX)
    {
        printf("\nA fila está cheia.\n");
    }
    else
    {
        printf("\nDigite o RA do aluno: ");
        scanf("%s", queue.data[queue.end].ra);
        printf("\nDigite o nome do arquivo: ");
        scanf("%s", queue.data[queue.end].file);
        printf("\nDigite a extensão do arquivo: ");
        scanf("%s", queue.data[queue.end].extension);
        printf("\nDigite a matrícula do professor: ");
        scanf("%s", queue.data[queue.end].registration);
        queue.end++;
    }
}

void removeFirst()
{
    if (queue.init == queue.end)
    {
        printf("\nFila vazia.\n\n");
    }
    else
    {
        int i;
        for (i = 0; i < QUEUE_MAX; i++)
        {
            strcpy(queue.data[i].ra, queue.data[i + 1].ra);
            strcpy(queue.data[i].file, queue.data[i + 1].file);
            strcpy(queue.data[i].extension, queue.data[i + 1].extension);
            strcpy(queue.data[i].registration, queue.data[i + 1].registration);
        }
        strcpy(queue.data[queue.end].ra, "");
        strcpy(queue.data[queue.end].file, "");
        strcpy(queue.data[queue.end].extension, "");
        strcpy(queue.data[queue.end].registration, "");
        queue.end--;
    }
}

void clear()
{
    while (queue.init != queue.end)
    {
        removeFirst();
    }
    printf("\nFila vazia.\n\n");
}

void showQueue()
{
    if (queue.init == queue.end)
    {
        printf("\nLista vazia!\n");
    }
    else
    {
        int i;
        for (i = 0; i < queue.end; i++)
        {
            printf("\n##### Registro número: 0%d #####", i + 1);
            printf("\nRA: %s ", queue.data[i].ra);
            printf("\nNome arquivo: %s ", queue.data[i].file);
            printf("\nExtensão: %s ", queue.data[i].extension);
            printf("\nMatrícula: %s \n", queue.data[i].registration);
        }
    }
}

void menu() {
    printf("\nEscolha uma opção desejada:");
    printf("\n1 - Inserir");
    printf("\n2 - Remover");
    printf("\n3 - Esvaziar");
    printf("\n4 - Sair\n");
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    bool exit = false;
    int option = 1;
    while(exit == false) {
        showQueue();
        menu();
        printf("\n");
        scanf("%d", &option);
        switch (option) {
        case 1:
            queueAdd();
            system("cls");
            break;
        case 2:
            removeFirst();
            system("pause");
            system("cls");
            break;

        case 3:
            clear();
            system("pause");
            system("cls");
            break;
        
        case 4:
            exit = true;
            break;
        
        default:
            printf("\nOpção inválida");
            system("pause");
            break;
        }
    }
}
