#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "Formation.h"

int saisieInt2()
{
    int x;
    do
    {
      printf("saisir le nombre de formation ");
      scanf("%d",&x);
    }
    while(x<=0);
    return x;
}
FORMATION * allocationFormation(int n)
{
    FORMATION *ft;
    ft=(FORMATION*) malloc (n*sizeof(FORMATION));
    if(!ft) exit(-1);
    return ft;
}
void saisieFormation(FORMATION*ft,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nsaisir les informations sur la formation %d \n",i+1);
        printf("saisir le code");
        scanf("%d",&(ft+i)->codeFormation);
        printf("saisir le titre ");
        scanf("%s",&(ft+i)->titre);
        printf("saisir la description");
        scanf("%s",&(ft+i)->desc);

    }
}
void afficherFormation(FORMATION *ft,int n)
{
    int i;
    if(ft == NULL)
        printf("tableau VIDE");
    else
    for(i=0;i<n;i++)
    {
        printf("\n*********************\n");
        printf("\n les informations sur la Formation %d \n",i+1);
        printf("\n code : %d \n",(ft+i)->codeFormation);
        printf("\n titre : %s\n",(ft+i)->titre);
        printf("\n description : %s",(ft+i)->desc);
    }
}
void modifierFormation(FORMATION *ft,int n){
  int i=0,cd;
  if(ft == NULL){
    printf("tableau VIDE");
  }else{
  printf("entrer le code du formation à modifier");
  scanf("%d",&cd);

  while((i<n) && ( (ft+i)->codeFormation != cd )){
        i++;

  }
 if(i==n){
      printf("!!!! Ce code est inexistant !!!!");
  }
    else{
    printf(" *** Les anciens informations de cette formation : \n");
        printf("\n titre : %s\n",(ft+i)->titre);
        printf("\n description : %s",(ft+i)->desc);

      printf("\n saisir les nouvelles données du formations %d\n",i+1);

        printf("saisir le titre ");
        scanf("%s",&(ft+i)->titre);
        printf("saisir la description");
        scanf("%s",&(ft+i)->desc);

  }

}}

void supprimerFormation(FORMATION *ft,int *n){
      int i=0,cd;

      char choix[3] ;
  if(ft == NULL){
    printf("tableau VIDE");
  }else{
  printf("entrer le code du formation à supprimer ");
  scanf("%d",&cd);

  while((i<*n) && ( (ft+i)->codeFormation != cd )){
        i++;
  }

  if(i==*n){
      printf("\n !!!! Ce code est inexistant !!!!");
  }
    else{

    printf(" *** Les informations du formation à supprimer : \n");
        printf("\n titre : %s\n",(ft+i)->titre);
        printf("\n description : %s",(ft+i)->desc);

    printf(" \n---- Confirmation -------- : \n");
    do{
    printf("\n Voulez-vous supprimer definitivement cette formation ? (tapez O ou N)");
    scanf("%s",&choix);
    if( (strcmp(choix,"O") ) && (strcmp(choix,"N")) ){
        printf("\n !!! Priere de taper O pour Confirmer ou N pour annuler la suppression");
    }
    }while((strcmp(choix,"O") ) && ( strcmp(choix,"N") ));
    if(strcmp(choix,"O") == 0){
    for(int j=i;j<*n-1;j++){
        (ft+j)->codeFormation = (ft+j+1)->codeFormation ;
        strcpy((ft+i)->titre , (ft+i+1)->titre);
        strcpy((ft+i)->desc , (ft+i+1)->desc );
    }
    *n = *n - 1 ;
    if((*n) == 0)
        free(ft);
    else
    ft = (FORMATION*) realloc(ft,(*n) * sizeof(FORMATION));
    printf("suppression effectuer avec succees ");

  }else
  printf("suppression annuler ");
  }

}}

