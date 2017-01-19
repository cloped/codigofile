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

typedef lista Pilha;

void criarPilha(Pilha **topo){
	*topo = NULL;
}

void inserirPilha(Pilha **topo, int id, char nome[20], char endereco[40]){
	Pilha *atual, *novo;
	tipoDados *dado;

	if(*topo==NULL){
		dado = (tipoDados *) malloc(sizeof(tipoDados));
		(*topo) = (Pilha *) malloc(sizeof(Pilha));
		
		strcpy(dado->nome,nome);
		strcpy(dado->endereco,endereco);
		dado->id = id;

		(*topo)-> dado = dado;
		(*topo)-> ant = NULL;

	} else {
		atual = *topo;

		dado = (tipoDados *) malloc(sizeof(tipoDados));
		novo = (Pilha *) malloc(sizeof(Pilha));

		strcpy(dado->nome,nome);
		strcpy(dado->endereco,endereco);
		dado->id = id;

		novo-> dado = dado;
		novo-> ant = atual;

		*topo = novo;

	}
}

void removerPilha(Pilha **topo){

	Pilha *novo_topo,*apaga;
	novo_topo = (*topo)->ant;
	apaga = *topo;

	free(apaga);

	*topo = novo_topo;

}

int main(){
	
	Pilha *topo, *atual;

	criarPilha(&topo);
	inserirPilha(&topo,2,"Nome Fulano","Rua Eoq");
	inserirPilha(&topo,2123123,"Nome nhanhanhanha","Rua pq");
	inserirPilha(&topo,0,"eu","av roleplay");
	removerPilha(&topo);

	atual = topo;
	while(atual!=NULL){
		printf("Id: %d\tNome: %s\tEndereco: %s\n",atual->dado->id,atual->dado->nome,atual->dado->endereco);
		topo = atual->ant;
		free(atual);
		atual = topo;
	}


	return 0;
}