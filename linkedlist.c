#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
  int valor;
  struct Node *next;
}node;

//funcao para criar node
node *create(int valor){
  node *novo = malloc(sizeof(node));
  novo->valor = valor;
  novo->next = NULL;
  return novo;
}
//funcao para inserir node no comeco
void inserirComeco(node **head, int valor){
  node *novo = create(valor);
  novo->next = *head;
  *head = novo;
}
//funcao para inserir node fo final
void inserirFim(node **head, int valor){
  node *novo = create(valor);
  node *temp = *head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next=novo;
}
//funcao para verificar se um numero esta na lista
void verificarNum(node *head, int num){
  node *temp = head;
  while(temp != NULL){
    if(temp->valor == num){
      printf("Numero %d encontrado!", num);
      return;
    }
    temp = temp->next;
  }
      printf("Numero %d nao foi encontrado!\n", num);
}

void imprimir(node *head){
  node *temp = head;
  while(temp != NULL){
    printf("%d ", temp->valor);
    temp = temp->next;
  }
  printf("\n");
}

int main(){

  node *head = NULL;

  int num,qtd;
  printf("Digite quantos nodes deseja inserir na lista:\n");
  scanf("%d", &qtd);

  printf("Digite os numeros a serem inseridos:\n");
  for(int i = 0; i < qtd; i++){
    scanf("%d", &num);
    inserirComeco(&head,num);
  }
  imprimir(head);
  printf("Numero a ser adicionado na ultima posicao:\n");
  scanf("%d", &num);
  inserirFim(&head, num);

  imprimir(head);

  printf("Numero para verificar se existe: \n");
  scanf("%d", &num);
  verificarNum(head,num);
  return 0;
}
