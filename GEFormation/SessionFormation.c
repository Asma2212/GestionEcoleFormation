#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "mylib.h"

int saisieNbSF()
{
    int x;
    do
    {
      printf("saisir le nombre de Session de formation ");
      scanf("%d",&x);
    }
    while(x<=0);
    return x;

}
SESSIONFORMATION* allocationSf(int n)
{
    SESSIONFORMATION *c;
    c=(SESSIONFORMATION*) malloc (n*sizeof(SESSIONFORMATION));
    if(!c) exit(-1);
    return c;
}

void saisieSF(SESSIONFORMATION *sf,int n)
{
  int i;
  for(i=0;i<n;i++)
   {
    printf("\n saisir les informations de la session de formation %d\n",i+1);
    printf("\n saisir le code ");
    scanf("%d",&(sf+i)->codeSF);
    printf("\n saisir le titre ");
    scanf("%s",&(sf+i)->titreSF);
    do{
    printf("\n saisir la date de debut ");
    scanf("%d%d%d",&(sf+i)->dateDebSF.jour,&(sf+i)->dateDebSF.mois,&(sf+i)->dateDebSF.annee);}
     while(!verifDate((sf+i)->dateDebSF.jour,(sf+i)->dateDebSF.mois,(sf+i)->dateDebSF.annee));
    do{
    printf("\n saisir la date de fin ");
    scanf("%d%d%d",&(sf+i)->dateFinSF.jour,&(sf+i)->dateFinSF.mois,&(sf+i)->dateFinSF.annee);
    }while(!verifDate((sf+i)->dateFinSF.jour,(sf+i)->dateFinSF.mois,(sf+i)->dateFinSF.annee));
    printf("\n saisir le nombre maximale des candidats ");
    scanf("%d",&(sf+i)->nbMaxCandidat);
    //********** formation *************
    printf("\n saisir le nombre des formations ");
    scanf("%d",&(sf+i)->nbFormation);
    (sf+i)->formations = allocationForm((sf+i)->nbFormation);
    saisieFormation((sf+i)->formations,(sf+i)->nbFormation);
    //*********** formateur *********
    printf("\n saisir le nombre des formateurs ");
    scanf("%d",&(sf+i)->nbFormateur);
    (sf+i)->formateurs = allocationForm((sf+i)->nbFormateur);
    saisieFormateur((sf+i)->formateurs,(sf+i)->nbFormateur);
   }
}

void afficherSF(SESSIONFORMATION *sf,int n)
{   int i;
    for(i=0;i<n;i++)
   {
     printf("\n*********************\n");
     printf("\n informations sur la session de formation %d\n",i+1);
     printf("\n code : %d ",(sf+i)->codeSF) ;
     printf("\n titre : %s",(sf+i)->titreSF);
     printf("\n date debut : %d/%d/%d",(sf+i)->dateDebSF.jour,(sf+i)->dateDebSF.mois,(sf+i)->dateDebSF.annee);
     printf("\n date fin : %d/%d/%d",(sf+i)->dateFinSF.jour,(sf+i)->dateFinSF.mois,(sf+i)->dateFinSF.annee);
     afficherFormateur((sf+i)->formateurs,(sf+i)->nbFormateur);
     afficherFormation((sf+i)->formations,(sf+i)->nbFormation);

   }
}
void AjouterCandidatSF(int code,SESSIONFORMATION *sf,int n)
{
  int i=0;
  bool trouve = false ;
  do{
        if(code==(sf+i)->codeSF){
            trouve = true ;
        }
    i++;
  }while(!trouve && i<n);

}


