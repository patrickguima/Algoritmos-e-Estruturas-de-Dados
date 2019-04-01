#include <stdlib.h>
#include <stdio.h>

void BubbleSort(int* v, int tam);
void exibevetor(int* vet, int n);

int main(int argc, char **argv)
{
    int *sorted, tam, i;
    tam = 15;

    sorted = malloc(sizeof(int)*tam);

    for(i=0; i<tam; i++){
        sorted[i] = rand()%100;
    }
    printf("Antes: ");
    exibevetor(sorted, tam);
    BubbleSort(sorted, tam);
    printf("\nDepois: ");
    exibevetor(sorted, tam);
    return 0;
}

void BubbleSort(int* v, int tam){
    int i, j, troca, aux;;

    do{
        for(i=0;i<tam-1;i++){
            if(v[i]>v[i+1]){
                aux = v[i+1];
                v[i+1]=v[i];
                v[i] = aux;
                troca = i;
            }
        }
            tam--;

    }while(troca != i);

}

void exibevetor(int* vet, int n){
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", vet[i]);
}
