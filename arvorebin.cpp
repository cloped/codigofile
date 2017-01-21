#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct ArvoreBin {
	struct ArvoreBin *direita;
	struct ArvoreBin *esquerda;

	int dado;

} ArvoreBin;

//Metodos de varredura
void preOrdem(ArvoreBin *raiz){
	if(raiz==NULL)	return;
	cout << raiz->dado <<" ";
	preOrdem( raiz->esquerda );
	preOrdem( raiz->direita );
}

void central(ArvoreBin *raiz){
	if(raiz==NULL)	return;
	central( raiz->esquerda );
	cout << raiz->dado <<" ";
	central( raiz->direita );
}

void posOrdem(ArvoreBin *raiz){
	if(raiz==NULL)	return;
	posOrdem( raiz->esquerda );
	posOrdem( raiz->direita );
	cout << raiz->dado <<" ";
}

// Sucessor e predecessor
ArvoreBin * sucessorArvore(ArvoreBin **atual){
	if((*atual)->esquerda == NULL) return *atual;

	sucessorArvore(&(*atual)->esquerda);
}

ArvoreBin * antecessorArvore(ArvoreBin **atual){
	if((*atual)->direita == NULL) return *atual;

	antecessorArvore(&(*atual)->direita);
}

void insereArvore(ArvoreBin **no, int dado){

	if(*no==NULL){
		*no = (ArvoreBin *) malloc(sizeof(ArvoreBin));

		(*no)->esquerda = NULL;
		(*no)->direita = NULL;
		(*no)->dado = dado;
		
	}else {
		if(dado < (*no)->dado)
			insereArvore(&(*no)->esquerda,dado);

		else if(dado > (*no)->dado)
			insereArvore(&(*no)->direita,dado);

	}

}


ArvoreBin * removeArvore(ArvoreBin **no, int dado)
{
    ArvoreBin *aux,*apaga;

	if(*no == NULL){
		cout << "Numero nao encontrado" << endl;
		return NULL;
	}

	if(dado < (*no)->dado){
		(*no)-> esquerda = removeArvore(&(*no)->esquerda, dado);
		
	} else if(dado > (*no)->dado){
		(*no)-> direita = removeArvore(&(*no)->direita, dado);

	} else {
        if( (*no)->direita && (*no)->esquerda )
        {	
            aux = sucessorArvore(&(*no)->direita);

            (*no)-> dado = aux->dado;

            (*no)-> direita = removeArvore(&(*no)->direita,aux->dado);	

        } else {
        	apaga = *no;

            if((*no)->direita == NULL){
            	*no = (*no)->esquerda; 

            } else if((*no)->esquerda == NULL){
            	*no = (*no)->direita; 

            } else {
            	*no = NULL;
            }

            free(apaga);

        }
    }

	
    return *no;

}


int main(){
	ArvoreBin *raiz=NULL;

	insereArvore(&raiz,30);
	insereArvore(&raiz,25);
	insereArvore(&raiz,70);
	insereArvore(&raiz,27);
	insereArvore(&raiz,10);


	preOrdem(raiz);
	cout << endl;

	cout << endl;

	removeArvore(&raiz,8);

	preOrdem(raiz);
	cout << endl;

}