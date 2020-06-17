#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 20
void leggiFile(FILE *fp);
void leggiEScriviFile(FILE *fp, FILE *fp2);
int main() {
  char nomeFile[MAXLEN];
  printf("Dammi il nome del file da leggere: ");
  scanf("%s", nomeFile);
  FILE *fp=NULL;
  FILE *fp2=NULL;
  fp=fopen(nomeFile, "r"); //sto creando in maniera dinamica una struct file, che al suo interno accede con un puntatore alla testa del file di nome nomeFile
  if(fp==NULL) printf("Non riesco ad aprire il file (forse non esiste!)\n");
  else { //il file si e aperto in maniera corretta!
    //leggiFile(fp);
    printf("Dammi il nome del file da scrivere: ");
    scanf("%s", nomeFile);
    fp2=fopen(nomeFile, "w");
    leggiEScriviFile(fp, fp2); //apro il file in scriuttura
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
