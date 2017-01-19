#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char nome[20];
	char endereco[40];
	int id;
} tipoDados;


typedef struct{
	tipoDados *dado;
	struct lista *prox;
	struct lista *ant;
} lista;

typedef lista Fila;

void criarFila(Fila **head){
	*head = NULL;
}

void inserirFila(Fila **head, int id, char nome[20], char endereco[40]){
	Fila *atual, *novo;
	tipoDados *dado;

	if(*head==NULL){
		dado = (tipoDados *) malloc(sizeof(tipoDados));
		(*head) = (Fila *) malloc(sizeof(Fila));
		
		strcpy(dado->nome,nome);
		strcpy(dado->endereco,endereco);
		dado->id = id;

		(*head)-> dado = dado;
		(*head)-> prox = NULL;

	} else {

		atual = *head;
		while(atual->prox != NULL){
			atual = atual->prox;
		}

		dado = (tipoDados *) malloc(sizeof(tipoDados));
		novo = (Fila *) malloc(sizeof(Fila));

		strcpy(dado->nome,nome);
		strcpy(dado->endereco,endereco);
		dado->id = id;

		novo-> dado = dado;
		novo-> prox = NULL;

		atual->prox = novo;

	}
}

void removerFila(Fila **head){

	Fila *novo_head,*apaga;
	novo_head = (*head)->prox;
	apaga = *head;

	free(apaga);

	*head = novo_head;

}

int main(){
	Fila *head, *atual;

	criarFila(&head);
	inserirFila(&head,2,"Nome Fulano","Rua Eoq");
	inserirFila(&head,2123123,"Nome nhanhanhanha","Rua pq");
	inserirFila(&head,0,"eu","av roleplay");
	removerFila(&head);

	atual = head;
	while(atual!=NULL){
		printf("Id: %d\tNome: %s\tEndereco: %s\n",atual->dado->id,atual->dado->nome,atual->dado->endereco);
		head = atual->prox;
		free(atual);
		atual = head;
	}
	return 0;
}