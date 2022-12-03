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
     {printf("\n saisir la date de naissance ");
      scanf("%d%d%d",&(c+i)->dateNaiss.jour,&(c+i)->dateNaiss.mois,&(c+i)->dateNaiss.annee);}
     while(!verifDate((c+i)->dateNaiss.jour,(c+i)->dateNaiss.mois,(c+i)->dateNaiss.annee));
    printf("\n saisir le numero de telephone ");
    scanf("%d",&(c+i)->numTel);
    do
    {printf("\n saisir l'adresse mail ");
      scanf("%s",&(c+i)->email);}
    while(!verifEmail((c+i)->email));
   }
}
void afficherCandidat(CANDIDAT *c,int n)
{   int i;
    for(i=0;i<n;i++)
   {
     printf("\n*********************\n");
     printf("\n informations sur le candidat %d\n",i+1);
     printf("\n code : %d ",c->ce) ;
     printf("\n nom: %s",c->nom);
     printf("\n prenom : %s",c->prenom);
     printf("\n date de naissance : %d/%d/%d",c->dateNaiss.jour,c->dateNaiss.mois,c->dateNaiss.annee);
     printf("\n numero de telephone : %d",c->numTel);
     printf("\n adresse mail : %s",c->email);
   }
}

