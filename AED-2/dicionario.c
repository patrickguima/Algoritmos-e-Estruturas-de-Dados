#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct node Node;
struct node{
    char word[100];
    Node *next;
};
typedef struct tableHash TableHash;
struct tableHash{
  Node **nodo;  
};

double loadFactor=0.70;
int tableSize=50;
int numElements=0;
unsigned int hash(char word[]);
void regWord(char word[],TableHash *hashS);
void removeWord(char word[],TableHash *hashS);
int findWord(char word[],TableHash *hashS);
void wordT(char *word,TableHash *hashS);
TableHash *rehash(TableHash *hashS);
void strdown(char word[]);
void hashDestroy(TableHash *hashS);

int main(){
  TableHash *hashS=malloc(sizeof(TableHash));
  hashS->nodo=calloc(50,sizeof(Node));
  char input[100];
  char lastInput[100];
  strcpy(lastInput,"");
   
  while(scanf("%s",input)){
    if(input[0]=='+' || input[0]=='-' || input[0]=='*'){
       if(input[0]=='*'){
          break;
        }
      if(lastInput[0]=='+' || lastInput[0]=='-' || strcmp(lastInput,"")==0){
         printf("fail\n");
      }
      else{
        if(input[0]=='+'){
          if(findWord(lastInput,hashS)==1){
            printf("fail %s\n",lastInput);
            strcpy(lastInput,"");
          }
          else{
            regWord(lastInput,hashS);
            printf("ok %s\n",lastInput);
            strcpy(lastInput,"");
            if((double)numElements/(double)tableSize > loadFactor){
              hashS=rehash(hashS);
              }
          }
        }
        if(input[0]=='-'){
          if(findWord(lastInput,hashS)==0){
            printf("fail %s\n",lastInput);
            strcpy(lastInput,"");
          }
          else{
            removeWord(lastInput,hashS);
            printf("ok %s\n",lastInput);
            strcpy(lastInput,"");
          }

        }
   
      }

    }
    else{
      strdown(input);
      if(input[0]<97 || input[0]>122){
        printf("fail\n");
        strcpy(lastInput,"");
      }
      else{
      if(findWord(input,hashS)==1){
        printf("ok %s\n",input);
      }
      else{
        wordT(input,hashS);
      }
      strcpy(lastInput,input);}
    }
  }

hashDestroy(hashS);
return 0;
}
unsigned int hash(char word[])
{
  int size=strlen(word);
  unsigned int sum = 677;
  for (int i=0;i<size;i++){
    sum=sum^(word[i]);
    sum=sum*16777619;
  }
 // printf("pos: %d\n",sum % tableSize); 
  return sum % tableSize;
}

void strdown(char word[]){
unsigned char *p = word;
  while (*p) {
     *p = tolower(*p);
      p++;
  }
}
void hashDestroy(TableHash *hashS){
Node *aux,*aux2;
for (int i;i<tableSize;i++){
  aux=hashS->nodo[i];
  if(aux!=NULL){
    do{
      aux2=aux;
      aux=aux->next;
      free(aux2);
    }while(aux!=NULL);
  }
}
free(hashS);
return;
}

TableHash *rehash(TableHash *hashS){
  TableHash *newHash=malloc(sizeof(TableHash));
  tableSize=tableSize*2;
  newHash->nodo=calloc(tableSize,sizeof(Node));
  Node *aux2;
  numElements=0;
  for (int i;i<tableSize/2;i++){
    Node *aux=hashS->nodo[i];
    if(aux!=NULL){
      do{
        regWord(aux->word,newHash);
        aux2=aux->next;
        free(aux);
        aux=aux2; 
      }while(aux!=NULL);
    }
  }
  free(hashS);
  return newHash;
}

void regWord(char word[],TableHash *hashS){
    unsigned int pos;
    pos = hash(word);
    Node *aux=calloc(1,sizeof(Node));
    aux->next=NULL;
    strcpy(aux->word,word);
    /* Posicao vazia, basta incluir aqui */
    if(hashS->nodo[pos] == NULL)
    {   
        hashS->nodo[pos]=aux;
        
    }
    else{
       Node *aux2= hashS->nodo[pos];
       hashS->nodo[pos]=aux;
       aux->next=aux2;
    }
    numElements=numElements+1;
    return;
}
int findWord(char word[],TableHash *hashS){

    unsigned int pos = hash(word);
    if(hashS->nodo[pos]==NULL){
      return 0;
    }
    else{
      Node *aux=hashS->nodo[pos];
      do{
        if(strcmp(aux->word,word)==0){
          return 1;
        }
        aux=aux->next;}
        while(aux!=NULL);
      }
    return 0;
}
    
void removeWord(char word[],TableHash *hashS){
    unsigned int pos = hash(word);
    Node *aux=hashS->nodo[pos];
    Node *aux2=aux;
  do{ 
    if(strcmp(word, aux->word)==0){ 
      numElements=numElements-1;
      if(aux==hashS->nodo[pos]){ 
        hashS->nodo[pos]=aux->next;
        free(aux);
        return;
      }
      else if(aux->next!=NULL){ 
        aux2->next=aux->next;
        free(aux);
        return;
      }
      else{
        aux2->next=NULL;
        free(aux);
        return;
      }
    }
    aux2=aux;
    aux=aux->next;
  }while(aux!=NULL);
}
 
void wordT(char *word,TableHash *hashS){
  int inputSize;
  int i,j,k,flag=0;
  char newInput[101]="";
  char auxInput[101]="";
  inputSize= strlen(word);
  // printf("LETRA A MAIS\n");
  for(i=0;i<inputSize;i++){
    strcpy(auxInput,word);
    for(int j=i;j<inputSize;j++){
     auxInput[j]=auxInput[j+1];
   }
     if(findWord(auxInput,hashS)==1){
      flag=1;
      if(strcmp(auxInput,newInput)!=0){
       printf("%s\n", auxInput);
      }
      strcpy(newInput,auxInput);
     }
   }
   
  //printf("LETRAS TROCADAS\n");
  strcpy(auxInput,word);
  strcpy(newInput,auxInput);
  char aux;
  for(i=0;i<inputSize-1;i++){
    aux=auxInput[i];
    auxInput[i]=auxInput[i+1];
    auxInput[i+1]=aux;
     if(findWord(auxInput,hashS)==1){
       printf("%s\n",auxInput);
       flag=1;
      }
    strcpy(auxInput,newInput);
  }
//printf(" UMA LETRA ERRADA\n");
  strcpy(auxInput,word);
  strcpy(newInput,auxInput);
  for (i='a';i<='z';i++){
    for (j=0;j<inputSize;j++){
      newInput[j]=i;
      for (k=0;k<inputSize;k++){
        if(j!=k){
          newInput[k]=auxInput[k];}
        }
        if(findWord(newInput,hashS)==1){
        printf("%s\n",newInput);
        flag=1;
      }
    strcpy(newInput,"");
    }
  }
  strcpy(auxInput,word);
  strcpy(newInput,auxInput);
  i='-';
    for (j=0;j<inputSize;j++){
      newInput[j]=i;
      for (k=0;k<inputSize;k++){
        if(j!=k){
          newInput[k]=auxInput[k];}
        }
        if(findWord(newInput,hashS)==1){
        printf("%s\n",newInput);
        flag=1;
      }
    strcpy(newInput,"");
    }
  

 //printf("UMA LETRA A MENOS\n");
  strcpy(auxInput,word);
  strcpy(newInput,auxInput);
  for (i='a';i<='z';i++){
    for (j=0;j<inputSize+1;j++){
    newInput[j]=i;
      for (k=0;k<inputSize;k++){
        if(k>=j){
          newInput[k+1]=auxInput[k];
        }
        else{
          newInput[k]=auxInput[k];
        }
      }
      if(findWord(newInput,hashS)==1){
       printf("%s\n",newInput);
       flag=1;
       break;
      }
      strcpy(newInput,"");
    } 
  }

  strcpy(auxInput,word);
  strcpy(newInput,auxInput);
  i='-';
    for (j=0;j<inputSize+1;j++){
    newInput[j]=i;
      for (k=0;k<inputSize;k++){
        if(k>=j){
          newInput[k+1]=auxInput[k];
        }
        else{
          newInput[k]=auxInput[k];
        }
      }
      if(findWord(newInput,hashS)==1){
       printf("%s\n",newInput);
       flag=1;
       break;
      }
      strcpy(newInput,"");
    } 
  
  if(flag==0){
    printf("not found\n");}

  return;


}