#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Fila {
  int dados[5];
  int start;
  int end;
} fila;

int menu();
void CreateEmptyQueue(fila *queue);
int isEmpty(int start, int end);
int isFull(int end, int start);
int enQueue(fila *queue, int valor);
int deQueue(fila *queue);
int peek(fila *queue);
void printQueue(fila *queue);
void order(fila *queue);

int main(void) {
  fila *queue = (fila *)malloc(sizeof(fila));
  int op = 0;
  int dado;

  CreateEmptyQueue(queue);

  while (op != 7) {
    printf(" ~ Implementaçõa de fila ~\n");
    op = menu();
    switch (op) {
    case 1:
      system("clear");
      printf((isEmpty(queue->start, queue->end))
                 ? "A fila ainda não tem nenhum elemento.\n\n"
                 : "A fila já tem um elemento.\n\n");
      usleep(1000 * 1000);
      system("clear");
      break;

    case 2:
      system("clear");
      printf((isFull(queue->end, queue->start))
                 ? "A fila está cheia.\n\n"
                 : "A fila ainda não está cheia.\n\n");
      usleep(1000 * 1000);
      system("clear");
      break;

    case 3:
      system("clear");
      printf("Digite o valor a ser enfileirado: ");
      scanf("%d", &dado);
      if (enQueue(queue, dado)) {
        printf("\nEnfileirando...\n");
      } else {
        printf("Fila cheia...\n");
      }
      usleep(1000 * 1000);
      system("clear");
      break;

    case 4:
      system("clear");
      deQueue(queue);
      printf("\nDesenfileirando...\n");
      usleep(1000 * 1000);
      system("clear");
      break;

    case 5:
      system("clear");
      dado = peek(queue);
      printf("O proximo elemento da fila é: %d\n\n", dado);
      usleep(1000 * 1000);
      system("clear");
      break;

    case 6:
      printQueue(queue);
      usleep(7000 * 1000);
      system("clear");
      break;
    }
  }
  printf("Até logo!");
  return 0;
}

void CreateEmptyQueue(fila *queue) {
  queue->start = -1;
  queue->end = -1;
  return;
}
int isEmpty(int start, int end) { return ((start == -1) || (start > end)); }

int isFull(int end, int start) { return (((end + 1) % 5) == (start % 5)); }

int enQueue(fila *queue, int valor) {
  if (!isFull(queue->end, queue->start)) {
    if (queue->start == -1) {
      queue->start += 1;
    }
    int aux;
    queue->end += 1;
    aux = queue->end % 5;
    queue->dados[aux] = valor;
    order(queue);
    return 1;
  } else {
    return 0;
  }
}

int deQueue(fila *queue) {
  int filaVazia;
  filaVazia = isEmpty(queue->start, queue->end);
  if (filaVazia == 1) {
    return 1;
  } else {
    queue->start += 1;
    return 0;
  }
}

int peek(fila *queue) { return queue->dados[queue->start % 5]; }

void printQueue(fila *queue) {
  int i;
  for (i = queue->start; i < queue->start + 5; i++) {
    printf("\n %d \n", queue->dados[i % 5]);
    if (i == queue->end) {
      return;
    }
  }
  return;
}

int menu() {
  int opcao;
  printf("\n1 - Verificar se a fila está vazia\n");
  printf("\n2 - Verificar se a fila está cheia\n");
  printf("\n3 - Enfileirar um elemento\n");
  printf("\n4 - Desenfileirar um elemento\n");
  printf("\n5 - Ler o próximo elemento da fila\n");
  printf("\n6 - Imprimir elementos da fila\n");
  printf("\n7 - Sair\n\n");
  scanf("%d", &opcao);
  if (opcao < 1 || opcao > 7) {
    printf("\n\nOpção não encontrada!\n\n");
    usleep(1000 * 1000);
    system("clear");
    return 0;
  }
  system("clear");
  return opcao;
}

void order(fila *queue) {
  int aux;
  int i = queue->end;
  while (i  != (queue->start % 5)) {
    if (queue->dados[(i % 5) - 1] < 60 && queue->dados[i % 5] >= 60) {
      aux = queue->dados[i - 1];
      queue->dados[i - 1] = queue->dados[i];
      queue->dados[i] = aux;
    }
    i--;
  }
  return;
}
