#include <stdlib.h>
#include <stdio.h>

void SelectionSort(int* v, int tam);
void exibevetor(int* vet, int n);

int main(int argc, char **argv)
{
    int *sorted, tam, i;
    tam = 15;

    sorted = malloc(sizeof(int)*tam);

    for(i=0; i<tam; i++){
        sorted[i] = rand()%1000;
    }

    printf("Antes: ");
    exibevetor(sorted, tam);
    SelectionSort(sorted, tam);
    printf("\nDepois: ");
    exibevetor(sorted, tam);
    return 0;
}

void SelectionSort(int* v, int tam){
    int i, j, menor, aux;

    for(j=0; j<tam-1;j++){
        menor = j;
        for(i=(j+1); i<tam; i++){
            if(v[i] < v[menor]){ //busca pelo menor elemento atraves do indice
                menor = i; //salva o novo indice como menor
            }
        }
        //troca e coloca o menor elemento para frente
        if(j != menor){
            aux = v[menor];
            v[menor] = v[j];
            v[j] = aux;
        }
        }

}

void exibevetor(int* vet, int n){
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", vet[i]);
}
