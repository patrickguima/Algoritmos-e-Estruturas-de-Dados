#include <stdlib.h>
#include <stdio.h>

void Mergesort(int* data, int left, int right);
void exibevetor(int* vet, int n);

int main(int argc, char **argv)
{
    int *sorted, tam, i;
    tam = 10;

    sorted = malloc(sizeof(int)*tam);

    for(i=0; i<tam; i++){
        sorted[i] = rand()%tam;
    }
    printf("Antes: ");
    exibevetor(sorted, tam);
    Mergesort(sorted, tam/2, tam/2);
    printf("\nDepois: ");
    exibevetor(sorted, tam);
    return 0;
}

void exibevetor(int* vet, int n){
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", vet[i]);
}

void MergeSort(int *vetor,int inicio,int fim)
{
    int meio;
    if(inicio < fim) {
        meio = (inicio + fim)/ 2;
        MergeSort(vetor, inicio, meio);
        MergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

merge(int *vetor, int inicio, int meio, int fim)
{
    int indice_inicio, indice_meio, indice_aux, vetor_aux;

    indice_inicio = inicio;
    indice_meio = meio+1;
    indice_aux = 0;
    vetor_aux[fim-inicio+1];

    while(indice_inicio < meio+1 ou indice_meio < fim+1) {
        if (indice_inicio = meio+1) {
            vetor_aux[indice_aux] = vetor[indice_meio];
            indice_meio = indice_meio + 1;
            indice_aux++;
        }else
            if (indice_meio = fim+1) {
                vetor_aux[indice_aux] = vetor[indice_inicio];
                indice_inicio = indice_inicio + 1;
                indice_aux++;
            }else
                if (vetor[indice_inicio] <= vetor[indice_meio]) {
                    vetor_aux[indice_aux] = vetor[indice_inicio];
                    indice_inicio++;
                    indice_aux++;
                }else {
                    vetor_aux[indice_aux] = vetor[indice_meio];
                    indice_meio++;
                    indice_aux++;
                }


    }

    // copia vetor intercalado para o vetor original
    for(indice_inicio = inicio; indice_inicio <= fim; indice_inicio++)
        vetor[indice_inicio] = vetor_aux[indice_inicio-inicio];

    
}
