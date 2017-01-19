// Codigo baseado no livro Algoritmos: Teoria e Prática (Thomas H Cormen)

#include <iostream>
using namespace std;

void quickSort(int vetor[], int esquerda, int direita){
    int pivot = direita, i, aux, j, gamb;  
    
    i = esquerda - 1;   

    for( aux = esquerda ; aux <= direita - 1 ; aux++ ){       

        if(vetor[pivot] > vetor[aux]){
            i++;

            gamb = vetor[aux];
            vetor[aux] = vetor[i];
            vetor[i] = gamb;

        }  

    }

    gamb = vetor[pivot];
    vetor[pivot] = vetor[i+1];
    vetor[i+1] = gamb;


    if(i > esquerda){              
        quickSort(vetor,esquerda,i);      
    }
    if(i+2 < direita){              
        quickSort(vetor,i+2,direita);      
    }  
 }

 int main(){
    int vetor[]={34,5,11,6,8,22,4};

    quickSort(vetor,0,6);

    for (int i = 0; i < 7; ++i)
    {
       cout << vetor[i] <<" ";
    }
    cout << endl;




    return 0;
 }