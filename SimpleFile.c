#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 20
int main() {
  char nomeFile[MAXLEN], s[MAXLEN];
  int x, y;
  printf("Dammi il nome del file: ");
  scanf("%s", nomeFile);
  FILE *fp=NULL;
  fp=fopen(nomeFile, "r"); //sto creando in maniera dinamica una struct file, che al suo interno accede con un puntatore alla testa del file di nome nomeFile
  if(fp==NULL) printf("Non riesco ad aprire il file (forse non esiste!)\n");
  else { //il file si e aperto in maniera corretta!
    fscanf(fp, "%s %d %d", s,&x,&y);
    printf("%s %d %d\n", s,x,y);
    fscanf(fp, "%s %d %d", s,&x,&y);
    printf("%s %d %d\n", s,x,y);

    fclose(fp);
  }

  return 0;
}
