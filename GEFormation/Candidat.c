#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//#include "Candidat.h"



int saisieInt1()
{
    int x;
    do
    {
      printf("saisir le nombre de candidat ");
      scanf("%d",&x);
    }
    while(x<=0);
    return x;

}
CANDIDAT* allocationCand( CANDIDAT *c,int n)
{
    if(c != NULL){
            printf("***%d",(c+1)->ce);
    c = (CANDIDAT*) realloc(c,n * sizeof(CANDIDAT));
  }else{
    c=(CANDIDAT*) malloc (n*sizeof(CANDIDAT));}
    if(!c) exit(-1);
    return c;
}

void saisiecandidat(CANDIDAT *c,int n,int deb)
{
  int i;
  for(i=deb;i<n;i++)
   {
    printf("\n saisir les informations du candidat %d\n",i+1);
    printf("\n saisir le code ");
    scanf("%d",&(c+i)->ce);
    do
     {printf("\n saisir le nom ");
      scanf("%s",&(c+i)->nom);}
    while(!verifName((c+i)->nom));
   do
     {printf("\n saisir le prenom ");
      scanf("%s",&(c+i)->prenom);}
    while(!verifName((c+i)->prenom));
    do
     {printf("\n saisir la date de naissance (JJ/MM/AAAA)");
      scanf("%d/%d/%d",&(c+i)->dateNaiss.jour,&(c+i)->dateNaiss.mois,&(c+i)->dateNaiss.annee);}
     while(!verifDate((c+i)->dateNaiss.jour,(c+i)->dateNaiss.mois,(c+i)->dateNaiss.annee));
   do{
    printf("\n saisir le numero de telephone ");
    scanf("%d",&(c+i)->numTel);
    if(((c+i)->numTel < 10000000) || ((c+i)->numTel > 99999999))
        printf("\n le numero doit contenir 8 chiffres \n");
   }while(((c+i)->numTel < 10000000) || ((c+i)->numTel > 99999999));
    do
    {printf("\n saisir l'adresse mail ");
      scanf("%s",&(c+i)->email);}
    while(!verifEmail((c+i)->email));
   }
}

void afficherCandidat(CANDIDAT *c,int n)
{   int i;
  if(c==NULL){
    printf("tableau VIDE");
  }else{
    for(i=0;i<n;i++)
   {
     printf("\n*********************\n");
     printf("\n informations sur le candidat %d\n",i+1);
     printf("\n code : %d ",(c+i)->ce) ;
     printf("\n nom: %s",(c+i)->nom);
     printf("\n prenom : %s",(c+i)->prenom);
     printf("\n date de naissance : %02d/%02d/%02d \n",(c+i)->dateNaiss.jour,(c+i)->dateNaiss.mois,(c+i)->dateNaiss.annee);
     printf("\n numero de telephone : %d",(c+i)->numTel);
     printf("\n adresse mail : %s",(c+i)->email);
   }
}}

void modifierCandidat(CANDIDAT *c,int n)
{
  int i=0,cd;
  if(c == NULL){
    printf("tableau VIDE");
  }else{
  printf("entrer le code du Candidat à modifier");
  scanf("%d",&cd);

  while((i<n) && ( (c+i)->ce != cd )){
        i++;

  }
 if(i==n){
      printf("!!!! Ce code est inexistant !!!!");
  }
    else{
    printf(" *** Les anciens informations de ce candidat : \n");
     printf("\n nom: %s",(c+i)->nom);
     printf("\n prenom : %s",(c+i)->prenom);
     printf("\n date de naissance : %02d/%02d/%02d",(c+i)->dateNaiss.jour,(c+i)->dateNaiss.mois,(c+i)->dateNaiss.annee);
     printf("\n numero de telephone : %d",(c+i)->numTel);
     printf("\n adresse mail : %s",(c+i)->email);

      printf("\n saisir les nouvelles données du candidat %d\n",i+1);

         do
     {printf("\n saisir le nom ");
      scanf("%s",&(c+i)->nom);}
    while(!verifName((c+i)->nom));
    do
     {printf("\n saisir le prenom ");
      scanf("%s",&(c+i)->prenom);}
    while(!verifName((c+i)->prenom));
    do
     {printf("\n saisir la date de naissance (JJ/MM/AAAA) \n");
      scanf("%d/%d/%d",&(c+i)->dateNaiss.jour,&(c+i)->dateNaiss.mois,&(c+i)->dateNaiss.annee);}
     while(!verifDate((c+i)->dateNaiss.jour,(c+i)->dateNaiss.mois,(c+i)->dateNaiss.annee));
   do{
    printf("\n saisir le numero de telephone ");
    scanf("%d",&(c+i)->numTel);
    if(((c+i)->numTel < 10000000) || ((c+i)->numTel > 99999999))
        printf("\n le numero doit contenir 8 chiffres \n");
   }while(((c+i)->numTel < 10000000) || ((c+i)->numTel > 99999999));
    do
    {printf("\n saisir l'adresse mail ");
      scanf("%s",&(c+i)->email);}
    while(!verifEmail((c+i)->email));
  }

}}

void supprimerCandidat(CANDIDAT *c,int* n){

      int i=0,cd;
      CANDIDAT * cs;

      char choix[3] ;
  if(c == NULL){
    printf("tableau VIDE");
  }else{
  printf("entrer le code du Candidat à supprimer ");
  scanf("%d",&cd);

  while((i<*n) && ( (c+i)->ce != cd )){
        i++;
  }

  if(i==*n){
      printf("\n !!!! Ce code est inexistant !!!!");
  }
    else{

    printf(" *** Les informations du candidat à supprimer : \n");
     printf("\n nom: %s",(c+i)->nom);
     printf("\n prenom : %s",(c+i)->prenom);
     printf("\n date de naissance : %d/%d/%d",(c+i)->dateNaiss.jour,(c+i)->dateNaiss.mois,(c+i)->dateNaiss.annee);
     printf("\n numero de telephone : %d",(c+i)->numTel);
     printf("\n adresse mail : %s",(c+i)->email);

    printf(" \n---- Confirmation -------- : \n");
    do{
    printf("\n Voulez-vous supprimer definitivement ce candidat ? (tapez O ou N)");
    scanf("%s",&choix);
    if( (strcmp(choix,"O") ) && (strcmp(choix,"N")) ){
        printf("\n !!! Priere de taper O pour Confirmer ou N pour annuler la suppression");
    }
    }while((strcmp(choix,"O") ) && ( strcmp(choix,"N") ));
    if(strcmp(choix,"O") == 0){
                *n = *n - 1 ;

printf("position = %d",i);
    for(int j=i;j<(*n);j++){
printf("parcours = %d total %d",j,*n);
        (c+j)->ce = (c+(j+1))->ce ;
        strcpy((c+j)->nom , (c+(j+1))->nom);
        strcpy((c+j)->prenom , (c+(j+1))->prenom );
        (c+j)->dateNaiss = (c+(j+1))->dateNaiss ;
        strcpy((c+j)->email , (c+(j+1))->email );
        (c+j)->numTel = (c+(j+1))->numTel ;
printf("FIN parcours = %d total %d",j,*n);
    }

    if((*n) == 0){
        free(c);
        c = NULL ;
     printf("tableau videeeee ");
    }
    else{

    c = (CANDIDAT*) realloc(c,(*n) * sizeof(CANDIDAT));
    }
    printf("suppression effectuer avec succees ");

  }else
  printf("suppression annuler ");
  }

}}

