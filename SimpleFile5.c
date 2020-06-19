#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 20
void leggiFile(FILE *fp);
void leggiEScriviFile(FILE *fp, FILE *fp2);
int **leggiMatrice(FILE *fp, int *pM, int *pN);
void printMatrice(int **A, int M, int N);

int main() {
  char nomeFile[MAXLEN];
  int *pM,*pN;
  int A, M,N;
  printf("Dammi il nome del file da leggere: ");
  scanf("%s", nomeFile);
  FILE *fp=NULL;
  FILE *fp2=NULL;
  fp=fopen(nomeFile, "r"); //sto creando in maniera dinamica una struct file, che al suo interno accede con un puntatore alla testa del file di nome nomeFile
  if(fp==NULL) printf("Non riesco ad aprire il file (forse non esiste!)\n");
  else { //il file si e aperto in maniera corretta!
    //leggiFile(fp);
    //printf("Dammi il nome del file da scrivere: ");
    scanf("%s", nomeFile);
    //fp2=fopen(nomeFile, "w");
    //leggiEScriviFile(fp, fp2); //apro il file in scriuttura
    leggiMatrice(fp,pM,pN);
    printMatrice(A,M,N);
    fclose(fp);
    fclose(fp2);
  }
  return 0;
}

void leggiFile(FILE *fp){
  char s[MAXLEN];
  int x,y;
  while (fscanf(fp, "%s %d %d", s,&x,&y)==3){ //quando non sappiamo quante righe ci stanno
      printf("%s %d %d\n", s,x,y);
  }
}

void leggiEScriviFile(FILE *fp, FILE *fp2){
  char s[MAXLEN];
  int x,y;
  while (fscanf(fp, "%s %d %d", s,&x,&y)==3){ //quando non sappiamo quante righe ci stanno
      fprintf(fp2, "%s %d %d\n", s,x,y);
  }
}

int **leggiMatrice(FILE *fp, int *pM, int *pN){
  //so, in questo esempio, che la prima riga mi da informazioni su M e N
  int M,N, i, j;
  fscanf(fp,"%d %d", &M, &N);
  int **A=(int**)malloc(M*sizeof(int *));
  for (i=0; i<M; ++i) A[i]=(int *)malloc(N*sizeof(int));
  for (i=0; i<M; ++i)
    for(j=0; j<N; ++j) fscanf(fp, "%d", &A[i][j]);
    *pM=M;
    *pN=N;
  return A;
}

void printMatrice(int **A, int M, int N){
  int i,j;
  for (i=0; i<M; ++i){
    for(j=0; j<N; ++j) printf("%d", A[i][j]);
    printf("\n");
 }
}
