#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
//#include "SessionFormation.h"

DATE dateCourante(){
DATE d;
time_t now;
int day, mois, an;
time(&now);
struct tm *local = localtime(&now);

d.jour = local->tm_mday;
d.mois = local->tm_mon + 1;
d.annee = local->tm_year + 1900;
return d ;
}

bool verifDateSf(DATE d,DATE d1){
if(d1.annee < d.annee)
    return false ;
else
    if(d1.mois < d.mois)
        return false ;
    else
        if (d1.jour < d.jour)
            return false ;

return true ;

}
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
SESSIONFORMATION* allocationSf(SESSIONFORMATION *sf,int n)
{

  if(sf != NULL){
              printf("***%d",(sf+1)->codeSF);
    sf = (SESSIONFORMATION*) realloc(sf,n * sizeof(SESSIONFORMATION));
  }else{
  sf=(SESSIONFORMATION*) malloc (n*sizeof(SESSIONFORMATION));
  }

    if(!sf) exit(-1);
    return sf;
}

void saisieSF(SESSIONFORMATION *sf,int n,int deb)
{
    int i ;
     DATE d ;
  for(i=deb;i<n;i++)
   {
        (sf+i)->nbCandidat = 0;
     (sf+i)->nbFormateur = 0;
     (sf+i)->nbFormation = 0;
    printf("\n saisir les informations de la session de formation %d\n",i+1);
    printf("\n saisir le code ");
    scanf("%d",&(sf+i)->codeSF);
    printf("\n saisir le titre ");
    scanf("%s",&(sf+i)->titreSF);

    do{
    d = dateCourante();
    printf("\n saisir la date de debut (JJ/MM/AAAA)");
    scanf("%d/%d/%d",&(sf+i)->dateDebSF.jour,&(sf+i)->dateDebSF.mois,&(sf+i)->dateDebSF.annee);
    if(!verifDateSf(d,(sf+i)->dateDebSF)){
       printf("la date entree doit etre superieure a la date courante %02d/%02d/%d\n", d.jour, d.mois, d.annee);
        }
    }
     while(!verifDateSf(d,(sf+i)->dateDebSF));

    do{
    printf("\n saisir la date de fin (JJ/MM/AAAA)");
    scanf("%d/%d/%d",&(sf+i)->dateFinSF.jour,&(sf+i)->dateFinSF.mois,&(sf+i)->dateFinSF.annee);
    if(!verifDateSf((sf+i)->dateDebSF,(sf+i)->dateFinSF)){
       printf("la date entree doit etre superieure a la date debut %02d/%02d/%d\n", (sf+i)->dateFinSF.jour, (sf+i)->dateFinSF.mois, (sf+i)->dateFinSF.annee);
        }
    }
     while(!verifDateSf((sf+i)->dateDebSF,(sf+i)->dateFinSF));
    //********** formation *************
    printf("\n saisir le nombre des formations ");
    scanf("%d",&(sf+i)->nbFormation);
    (sf+i)->formations = allocationForm((sf+i)->nbFormation);
    saisieFormation((sf+i)->formations,(sf+i)->nbFormation,0);
    //*********** formateur *********
    printf("\n saisir le nombre des formateurs ");
    scanf("%d",&(sf+i)->nbFormateur);
    (sf+i)->formateurs = allocationForm((sf+i)->nbFormateur);
    saisieFormateur((sf+i)->formateurs,(sf+i)->nbFormateur);
    (sf+i)->candidats = NULL;
        printf("\n saisir le nombre maximale des candidats ");
    scanf("%d",&(sf+i)->nbMaxCandidat);
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
     printf("\n date debut : %02d/%02d/%d",(sf+i)->dateDebSF.jour,(sf+i)->dateDebSF.mois,(sf+i)->dateDebSF.annee);
     printf("\n date fin : %02d/%02d/%d",(sf+i)->dateFinSF.jour,(sf+i)->dateFinSF.mois,(sf+i)->dateFinSF.annee);
     printf("\n--------- LES FORMATEUR(S) : -------- \n ");
     afficherFormateur((sf+i)->formateurs,(sf+i)->nbFormateur);
    printf("\n--------- LES FORMATION(S) : -------- \n ");
     afficherFormation((sf+i)->formations,(sf+i)->nbFormation);
    printf("\n--------- LES CANDIDATS(S) : -------- \n ");
    afficherCandidat((sf+i)->candidats,(sf+i)->nbCandidat);



   }
}
void AjouterCandidatSF(SESSIONFORMATION *sf,int n)
{
 int i=0,code,nbC;
  CANDIDAT *c;
  bool trouve = false,max=false ;
  printf("enter le code de session");
  scanf("%d",&code);
  do{
        if(code==(sf+i)->codeSF){
            trouve = true ;
            if((sf+i)->nbCandidat == (sf+i)->nbMaxCandidat){
                printf("oops! cette session est pleine ");
            }
            else{
                printf("entrer le nombre de candidat à ajouter ");
                scanf("%d",&nbC);
                    if(nbC > (sf+i)->nbMaxCandidat - (sf+i)->nbCandidat)
                        printf("nombre est limitée il vous reste seulement %d libre(s)",(sf+i)->nbMaxCandidat - (sf+i)->nbCandidat);
                    else{
                            printf("***");
                            (sf+i)->nbCandidat += nbC ;
                            printf("111***  %d",(sf+i)->nbCandidat);
                            (sf+i)->candidats = allocationCand((sf+i)->candidats,(sf+i)->nbCandidat);
                            saisiecandidat((sf+i)->candidats,(sf+i)->nbCandidat,(sf+i)->nbCandidat-nbC);

                    }


            }
        }
    i++;
  }while(!trouve && i<n);
  if(!trouve){
    printf("\n!!ce code de session est inexistant \n");
  }

}

void modifierSF(SESSIONFORMATION *sf,int n){

      int i=0,codeSF1;
      DATE d;
      char choix[3] ;
  if(sf==NULL){
    printf("tableau VIDE");
  }else{
  printf("entrer le code de la session  à modifier ");
  scanf("%d",&codeSF1);

  while((i<n) && ( (sf+i)->codeSF != codeSF1 )){
        i++;
  }

  if(i==n){
      printf("\n !!!! Ce code n'existe pas !!!!");
  }
    else{
     printf(" *** Les informations de la session à modifier : \n");
     printf("\n titre : %s",(sf+i)->titreSF);
     printf("\n date debut : %02d/%02d/%d",(sf+i)->dateDebSF.jour,(sf+i)->dateDebSF.mois,(sf+i)->dateDebSF.annee);
     printf("\n date fin :  %02d/%02d/%d",(sf+i)->dateFinSF.jour,(sf+i)->dateFinSF.mois,(sf+i)->dateFinSF.annee);
     printf("--------- LES FORMATEUR(S) : -------- \n ");
      afficherFormateur((sf+i)->formateurs,(sf+i)->nbFormateur);
     printf("--------- LES FORMATION(S) : -------- \n ");
      afficherFormation((sf+i)->formations,(sf+i)->nbFormation);
     printf("--------- LES CANDIDATS(S) : -------- \n ");
      afficherCandidat((sf+i)->candidats,(sf+i)->nbCandidat);

     }
      printf("\n saisir les nouvelles données de la session de formation %d\n",i+1);

    printf("\n saisir le titre ");
    scanf("%s",&(sf+i)->titreSF);
    do{
    d = dateCourante();
    printf("\n saisir la date de debut (JJ/MM/AAAA)");
    scanf("%d/%d/%d",&(sf+i)->dateDebSF.jour,&(sf+i)->dateDebSF.mois,&(sf+i)->dateDebSF.annee);
    if(!verifDateSf(d,(sf+i)->dateDebSF)){
       printf("la date entree doit etre superieure a la date courante %02d/%02d/%d\n", d.jour, d.mois, d.annee);
        }
    }
     while(!verifDateSf(d,(sf+i)->dateDebSF));

    do{

    printf("\n saisir la date de fin (JJ/MM/AAAA)");
    scanf("%d/%d/%d",&(sf+i)->dateFinSF.jour,&(sf+i)->dateFinSF.mois,&(sf+i)->dateFinSF.annee);
    if(!verifDateSf((sf+i)->dateDebSF,(sf+i)->dateFinSF)){
       printf("la date entree doit etre superieure a la date debut %02d/%02d/%d\n", (sf+i)->dateFinSF.jour, (sf+i)->dateFinSF.mois, (sf+i)->dateFinSF.annee);
        }
    }
     while(!verifDateSf((sf+i)->dateDebSF,(sf+i)->dateFinSF));
    //********** formation *************
    printf("\n saisir le nombre des formations ");
    scanf("%d",&(sf+i)->nbFormation);
    (sf+i)->formations = allocationForm((sf+i)->nbFormation);
    saisieFormation((sf+i)->formations,(sf+i)->nbFormation,0);
    //*********** formateur *********
    printf("\n saisir le nombre des formateurs ");
    scanf("%d",&(sf+i)->nbFormateur);
    (sf+i)->formateurs = allocationForm((sf+i)->nbFormateur);
    saisieFormateur((sf+i)->formateurs,(sf+i)->nbFormateur);
    (sf+i)->candidats = NULL;
        printf("\n saisir le nombre maximale des candidats ");
    scanf("%d",&(sf+i)->nbMaxCandidat);


}
}
