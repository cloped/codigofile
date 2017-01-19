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

typedef lista Circular;

void criarCircular(Circular **head){
	*head = NULL;
}

void inserirCircular(Circular **head, int id, char nome[20], char endereco[40]){
	Circular *atual, *novo;
	tipoDados *dado;

	if(*head==NULL){
		dado = (tipoDados *) malloc(sizeof(tipoDados));
		(*head) = (Circular *) malloc(sizeof(Circular));
		
		strcpy(dado->nome,nome);
		strcpy(dado->endereco,endereco);
		dado->id = id;

		(*head)-> dado = dado;
		(*head)-> prox = (*head);

	} else {

		atual = *head;

		dado = (tipoDados *) malloc(sizeof(tipoDados));
		novo = (Circular *) malloc(sizeof(Circular));

		strcpy(dado->nome,nome);
		strcpy(dado->endereco,endereco);
		dado->id = id;

		novo-> dado = dado;
		novo-> prox = atual->prox;

		atual->prox = novo;

	}
}

void removerCircular(Circular **head,int chave){
	Circular *atual,*apaga , *aux;
	int achou = 0;
	
	atual = (*head)->prox;
	aux = atual ->prox;

	while(atual!=*head){
		if(aux->dado->id == chave ) achou = 1;
		if(achou == 1) break;
		atual = atual->prox;
		aux = atual ->prox;
	
	}

	aux = (*head)->prox;

	if(achou == 1 || aux->dado->id == chave ){
		if(aux->dado->id == chave) atual = (*head);

		apaga = atual->prox;

		atual->prox = apaga->prox;

		if(apaga== *head) (*head) = (*head)-> prox;

		free(apaga);
	} else{
		printf("Nao foi possivel remover\n");
	}

}

int contaOcorrencia(Circular **head,int chave){
	Circular *atual;
	int cont = 0;

	if ((*head)->dado->id == chave)  cont ++;

	atual = (*head)->prox;
	while(atual!=(*head)){
		if(atual->dado->id == chave) cont ++;
		atual = atual->prox;
		
	}

	return cont;

}

int main(){
	Circular *head, *atual , *aux;

	criarCircular(&head);
	inserirCircular(&head,2,"Nome Fulano","Rua Eoq");
	inserirCircular(&head,1,"Nome nhanhanhanha","Rua pq");
	inserirCircular(&head,0,"eu","av roleplay");
	removerCircular(&head,0);
	inserirCircular(&head,1,"Nome nhanhanhanha","Rua pq");
	inserirCircular(&head,1,"Nome nhanhanhanha","Rua pq");
	inserirCircular(&head,1,"Nome nhanhanhanha","Rua pq");
	printf("Ocorrencias:%d\n",contaOcorrencia(&head,1));
	atual = head->prox;
	printf("Id: %d\tNome: %s\tEndereco: %s\n",head->dado->id,head->dado->nome,head->dado->endereco);
	while(atual!=head){
		printf("Id: %d\tNome: %s\tEndereco: %s\n",atual->dado->id,atual->dado->nome,atual->dado->endereco);
		aux = atual->prox;
		free(atual);
		atual = aux;
	}
	free(head);



	return 0;
}