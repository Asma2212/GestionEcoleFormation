#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#include "Candidat.h"


bool verifDate(int nj,int nm,int na)
{
    if((nj>=1) && (nj<=29))
    {if((nm>=1) && (nm<=12))
      {
          if((na>1900) && (na<=2022)) return true;
          else printf("l'annee n'existe pas ");
      }
     else printf("le mois n'existe pas");
    }
    else if (nj==30)
    {
        if(nm>=1 && nm<=12 && nm!=2) return true;
        else printf("le jour n'est pas compatible avec le mois");
    }
    else if (nj==31)
    {
        if(nm==1 && nm==3 && nm==5 && nm==7 && nm==8 && nm==10 && nm==12) return true;
        else printf("le jour n'est pas compatible avec le mois");
    }
    else printf("le jour n'existe pas");
}
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
CANDIDAT* allocationCand(int n)
{
    CANDIDAT *c;
    c=(CANDIDAT*) malloc (n*sizeof(CANDIDAT));
    if(!c) exit(-1);
    return c;
}

void saisiecandidat(CANDIDAT *c,int n)
{
  int i;
  for(i=0;i<n;i++)
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
     {printf("\n saisir la date de naissance (JJ MM AAAA)");
      scanf("%d %d %d",&(c+i)->dateNaiss.jour,&(c+i)->dateNaiss.mois,&(c+i)->dateNaiss.annee);}
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
  if((c+1)->ce == 0){
    printf("tableau VIDE");
  }else{
    for(i=0;i<n;i++)
   {
     printf("\n*********************\n");
     printf("\n informations sur le candidat %d\n",i+1);
     printf("\n code : %d ",(c+i)->ce) ;
     printf("\n nom: %s",(c+i)->nom);
     printf("\n prenom : %s",(c+i)->prenom);
     printf("\n date de naissance : %d/%d/%d \n",(c+i)->dateNaiss.jour,(c+i)->dateNaiss.mois,(c+i)->dateNaiss.annee);
     printf("\n numero de telephone : %d",(c+i)->numTel);
     printf("\n adresse mail : %s",(c+i)->email);
   }
}}

void modifierCandidat(CANDIDAT *c,int n)
{
  int i=0,cd;
  if((c+1)->ce == 0){
    printf("tableau VIDE");
  }else{
  printf("entrer le code du Candidat à supprimer");
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
     printf("\n date de naissance : %d/%d/%d",(c+i)->dateNaiss.jour,(c+i)->dateNaiss.mois,(c+i)->dateNaiss.annee);
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
     {printf("\n saisir la date de naissance (JJ MM AAAA) \n");
      scanf("%d %d %d",&(c+i)->dateNaiss.jour,&(c+i)->dateNaiss.mois,&(c+i)->dateNaiss.annee);}
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

      char choix[3] ;
  if((c+1)->ce == 0){
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
    if( (strcmp(choix,"O") == 0 ) && (strcmp(choix,"N") == 0) ){
        printf("\n !!! Priére de taper O pour Confirmer ou N pour annuler la suppression");
    }
    }while((strcmp(choix,"O") == 0 ) && ( strcmp(choix,"N") == 0));
    if(strcmp(choix,"O") == 0){
    for(int j=i;j<*n-1;j++){
        (c+j)->ce = (c+j+1)->ce ;
        strcpy((c+j)->nom , (c+j+1)->nom);
        strcpy((c+j)->prenom , (c+j+1)->prenom );
        (c+j)->dateNaiss = (c+j+1)->dateNaiss ;
        strcpy((c+j)->email , (c+j+1)->email );
        strcpy((c+j)->numTel , (c+j+1)->numTel ) ;
    }
    *n = *n - 1 ;
    if((*n) == 0)
        free(c);
    else
    c = (CANDIDAT*) realloc(c,(*n) * sizeof(CANDIDAT));
    printf("suppression effectuer avec succees ");

  }else
  printf("suppression annuler ");
  }

}}

