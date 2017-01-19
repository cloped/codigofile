#include <iostream>
#include <cstdlib>

using namespace std;

void mergeNome(int vetor[], int comeco, int fim) {
    int i, j, k, metadeTamanho;
    int *vetorTemp;

    if(comeco == fim) return;

    // ordenacao recursiva das duas metades
    metadeTamanho = (comeco + fim ) / 2;
    mergeNome(vetor, comeco, metadeTamanho);
    mergeNome(vetor, metadeTamanho + 1, fim);

    // intercalacao no vetor temporario t
    i = comeco;
    j = metadeTamanho + 1;
    k = 0;

    vetorTemp = (int *) malloc(sizeof(int) * (fim - comeco + 1));

    while(i < metadeTamanho + 1 || j  < fim + 1) {

        if ( i == metadeTamanho + 1 ) { 
            vetorTemp[k] = vetor[j];
            j++;
            k++;

        }
        else if ( j == fim + 1 ) {
            vetorTemp[k] = vetor[i];
            i++;
            k++;

        } else {
            if ( vetor[i] < vetor [j] ) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;

            }
            else {
                vetorTemp[k] = vetor[j];
                j++;
                k++;
            
            }
        }

    }

    // copia vetor intercalado para o vetor original
    for(i = comeco; i <= fim; i++) {
        vetor[i] = vetorTemp[i - comeco];
    }

    free(vetorTemp);
}

int main()
{
    int vetor[]={34,5,11,6,8,22,4};

    mergeNome(vetor,0,6);

    for (int i = 0; i < 7; ++i)
    {
       cout << vetor[i] <<" ";
    }
    cout << endl;

    return 0;
}