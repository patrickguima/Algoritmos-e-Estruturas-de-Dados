#include <stdlib.h>

#include <stdio.h>

void InsertionSort(int* v, int tam);
void exibevetor(int* vet, int n);

int main(int argc, char **argv)
{
    int *sorted, tam, i;
    tam = 15;

    sorted = malloc(sizeof(int)*tam);

    for(i=0; i<tam; i++){
        sorted[i] = rand();
    }
    printf("Antes: ");
    exibevetor(sorted, tam);
    InsertionSort(sorted, tam);
    printf("\nDepois: ");
    exibevetor(sorted, tam);
    return 0;
}

void InsertionSort(int* v, int tam){
    int i, j, tmp;
    for(i = 1; i < tam; i++){
        tmp = v[i]; //pega o elemento que será comparado
        for(j=i-1; j>0 && tmp<v[j];j--) //enquanto o elemento tmp for menor que o anterior, ocorre a troca
        {
            v[j+1]=v[j]; //faz o deslocamento para a direita
        }
        v[j+1] = tmp; //armazena o temporário no "espaço vazio"
    }

}

void exibevetor(int* vet, int n){
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", vet[i]);
}
