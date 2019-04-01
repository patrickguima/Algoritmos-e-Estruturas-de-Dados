#include <stdlib.h>
#include <stdio.h>

void Quicksort(int* data, int left, int right);
void exibevetor(int* vet, int n);

int main(int argc, char **argv)
{
    int *sorted, tam, i;
    tam = 10;

    sorted = (int *)malloc(sizeof(int)*tam);

    for(i=0; i<tam; i++){
        sorted[i] = rand()%tam;
    }
    printf("Antes: ");
    exibevetor(sorted, tam);
    Quicksort(sorted, 0, 9);
    printf("\nDepois: ");
    exibevetor(sorted, tam);
    return 0;
}

void exibevetor(int* vet, int n){
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", vet[i]);
}

void Quicksort(int *data, int left, int right){
    int pivo, tmp, i, j,meio;
    i = left;
    j = right;
	meio=(left+right)/2;
    pivo = (int)(data[meio]);

    do{	
        while(data[i] < pivo)
            i++;
        while(pivo < data[j])
            j--;

        if(i<=j){
            tmp = data[j];
            data[i] = data[j];
            data[j] = tmp;

            i++;
            j--;
        }
    }while (i > j);

    if(left < j)
        Quicksort(data,left,j);

    if(i < right)
        Quicksort(data,i,right);

}
