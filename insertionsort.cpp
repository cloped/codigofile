#include <iostream>

using namespace std;

void insertionSort(int vetor[], int comeco, int fim){
	int j,pivot;

	for (int i = comeco+1 ; i <= fim; ++i)
	{
		j = i;
		pivot = vetor[i];

		while(j > comeco and vetor[j-1] > pivot ){

			vetor[j] = vetor[j-1];
			j--;

		}

		vetor[j] = pivot;

	}

}

int main()
{
    int vetor[]={34,5,11,6,8,22,4};

    insertionSort(vetor,0,6);

    for (int i = 0; i < 7; ++i)
    {
       cout << vetor[i] <<" ";
    }
    cout << endl;

    return 0;
}