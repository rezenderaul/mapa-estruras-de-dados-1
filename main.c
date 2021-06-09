#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

#define QUEUE_MAX 5
#define CHAR_MAX 10

struct activity {
    char ra[CHAR_MAX];
    char file[CHAR_MAX];
    char extension[CHAR_MAX];
    char registration[CHAR_MAX];
};

struct activity activities;

struct activity_queue {
    struct activity data[QUEUE_MAX];
    int init;
    int end;
};

struct activity_queue queue;

void queueAdd() {
    printf("\nDigite o RA do aluno: ");
    scanf("%s", queue.data[queue.end].ra);
    printf("\nDigite o nome do arquivo: ");
    scanf("%s", queue.data[queue.end].file);
    printf("\nDigite a extensão do arquivo: ");
    scanf("%s", queue.data[queue.end].extension);
    printf("\nDigite a matrícula do professor: ");
    scanf("%s", queue.data[queue.end].registration);
    queue.end++;
    printf("\nRegistro adicionado com sucesso.\n");
}

void removeFirst() {
    int i;
    for (i = 0; i < QUEUE_MAX; i++) {
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
    system("cls");
    printf("O primeiro registro da lista foi removido com sucesso.\n");
}

void clear() {
    if (queue.init == queue.end) {
        printf("\nA lista está vazia.\n");
    }
    while (queue.init != queue.end) {
        removeFirst();
    }
    system("cls");
    printf("\nTodos os elementos da lista foram removidos.\n");
}

void showQueue() {
    int i;
    for (i = 0; i < queue.end; i++) {
        printf("\n##### Registro número: 0%d #####", i + 1);
        printf("\nRA: %s ", queue.data[i].ra);
        printf("\nNome arquivo: %s ", queue.data[i].file);
        printf("\nExtensão: %s ", queue.data[i].extension);
        printf("\nMatrícula: %s \n", queue.data[i].registration);
    }
}

bool queueFull() {
    return queue.end == QUEUE_MAX;
}

bool queueEmpty() {
    return queue.init == queue.end;
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
    int exit = 0;
    char option;

    while(exit != 1) {
        system("cls");
        (queueEmpty())  ? printf("A fila está vazia.\n") : showQueue();
        menu();

        /*
        https://pt.stackoverflow.com/questions/336557/como-ler-apenas-numeros-inteiros-no-scanf
        */
        while(scanf("%d", &option) != 1) {
            system("cls");
            (queueEmpty())  ? printf("A fila está vazia.\n") : showQueue();
            menu();
            static char temp[256];
            fgets(temp, sizeof(temp), stdin);
            printf("\nDigite um valor válido!\n");
            system("pause");
        }

        switch (option) {
        case 1:
            (queueFull()) ? printf("A fila está cheia.\n") : queueAdd();
            system("pause");
            break;
        case 2:
        (queueEmpty()) ? printf("A fila está vazia.\n") : removeFirst();
            system("pause");
            break;

        case 3:
            (queueEmpty()) ? printf("A fila está cheia.\n") : clear();
            system("pause");
            break;
        
        case 4:
            exit = 1;
            break;
        
        default:
            printf("\nOpção inválida\n");
            system("pause");
            break;
        }
    }
}
