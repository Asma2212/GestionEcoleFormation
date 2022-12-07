#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#include "SessionFormation.h"


 bool existeCodeSf(SESSIONFORMATION* sf,int n,int c){
     for(int i=0;i<n;i++){
        if((sf+i)->codeSF == c){
            return true ;
        }
     }
     return false ;
 }

FORMATEURSESSIONS** allocFormDem(FORMATEURSESSIONS** fSess ,int n){

  fSess=(FORMATEURSESSIONS**) malloc (sizeof(FORMATEURSESSIONS*));
printf("zzzz %p zzzzz",fSess);
    if(!fSess) exit(-1);

    return fSess ;

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

FORMATEURSESSIONS** saisieSF(SESSIONFORMATION *sf,int n,int deb,FORMATEURSESSIONS** fSess ,int *n1)
{
    int i, nFtot=0 ;
    FORMATEURSESSIONS** formateurSess = NULL ;
     DATE d ;
  for(i=deb;i<n;i++)
   {
(sf+i)->formateurs = NULL ;
(sf+i)->formations = NULL ;
        (sf+i)->nbCandidat = 0;
     (sf+i)->nbFormateur = 0;
     (sf+i)->nbFormation = 0;

    printf("\n saisir les informations de la session de formation %d\n",i+1);
    do{
    printf("\n saisir le code ");
    scanf("%d",&(sf+i)->codeSF);
       if(existeCodeSf(sf,i,(sf+i)->codeSF))
        printf("\n Attention ! le code du session doit etre unique\n");
   }while(existeCodeSf(sf,i,(sf+i)->codeSF));
    printf("\n saisir le titre ");
    fflush(stdin);
    gets((sf+i)->titreSF);

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
    (sf+i)->formations = allocationForm((sf+i)->formations,(sf+i)->nbFormation);
    saisieFormation((sf+i)->formations,(sf+i)->nbFormation,0);
    //*********** formateur *********
    printf("\n saisir le nombre des formateurs ");
    scanf("%d",&(sf+i)->nbFormateur);

    nFtot += (sf+i)->nbFormateur ;
    (sf+i)->formateurs = allocationForm((sf+i)->formateurs,(sf+i)->nbFormateur);
    saisieFormateur((sf+i)->formateurs,(sf+i)->nbFormateur,0);
    (sf+i)->candidats = NULL;
        printf("\n saisir le nombre maximale des candidats ");
    scanf("%d",&(sf+i)->nbMaxCandidat);
   }

    formateurSess = allocFormDem(formateurSess ,nFtot);
    saisieFormateurParSess(sf,n,formateurSess,nFtot);
    ajoutNbSessAuFormateur(formateurSess,nFtot);
    *n1 = nFtot ;
    return formateurSess ;
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
            fflush(stdin);
    gets((sf+i)->titreSF);
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
    (sf+i)->formations = allocationForm((sf+i)->nbFormation,(sf+i)->nbFormation);
    saisieFormation((sf+i)->formations,(sf+i)->nbFormation,0);
    //*********** formateur *********
    printf("\n saisir le nombre des formateurs ");
    scanf("%d",&(sf+i)->nbFormateur);
    (sf+i)->formateurs = allocationForm((sf+i)->nbFormateur,(sf+i)->nbFormateur);
    saisieFormateur((sf+i)->formateurs,(sf+i)->nbFormateur,0);
    (sf+i)->candidats = NULL;
        printf("\n saisir le nombre maximale des candidats ");
    scanf("%d",&(sf+i)->nbMaxCandidat);


}
}

void supprimerSF(SESSIONFORMATION *sf,int* n){

  int i=0,codeSF1;
  char choix[3] ;
  if(sf==NULL){
    printf("tableau VIDE");
    }
  else{
    printf("entrer le code du formateur à supprimer ");
    scanf("%d",&codeSF1);

    while((i<*n) && ( (sf+i)->codeSF != codeSF1 )){
         i++;
         }

    }
  if(i==*n){
      printf("\n !!!! Ce code n'existe pas !!!!");
  }
   else{

     printf(" *** Les informations de la session à supprimer : \n");
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

     printf(" \n---- Confirmation -------- : \n");
     do{
       printf("\n Voulez-vous supprimer definitivement ce formateur ? (tapez O ou N)");
       scanf("%s",&choix);
       if( (strcmp(choix,"O")) && (strcmp(choix,"N")) ){
         printf("\n !!! Priére de taper O pour Confirmer ou N pour annuler la suppression");
         }
       }while((strcmp(choix,"O")) && ( strcmp(choix,"N")));
     if(strcmp(choix,"O") == 0){
       *n = *n - 1 ;
       for(int j=i;j<(*n);j++){
          (sf+j)->codeSF = (sf+(j+1))->codeSF;
          strcpy((sf+j)->titreSF , (sf+(j+1))->titreSF);
          (sf+j)->dateDebSF = (sf+(j+1))->dateDebSF ;
          (sf+j)->dateFinSF = (sf+(j+1))->dateFinSF ;
          (sf+j)->nbFormation = (sf+(j+1))->nbFormation ;
          (sf+j)->formations = (sf+(j+1))->formations ;
          (sf+j)->nbFormateur = (sf+(j+1))->nbFormateur ;
          (sf+j)->formateurs = (sf+(j+1))->formateurs;
          (sf+j)->nbMaxCandidat = (sf+(j+1))->nbMaxCandidat;
        }
       if((*n) == 0){
         free(sf);
         sf=NULL;
         printf("tableau videeee");
         }
       else
         sf = (SESSIONFORMATION*) realloc(sf,(*n) * sizeof(SESSIONFORMATION));
       printf("suppression effectuer avec succees ");
       }
     else
       printf("suppression annuler ");
  }


void filtrerParDate(SESSIONFORMATION *sf,int n){
    DATE d1,d2;
    int i ;
    printf("\n Les sessions de formation disponible ce mois : \n");
    d1= dateCourante();
    d2= dateCourante();
    if(d2.mois == 12){
    d2.mois = 1 ;
    d2.annee +=1 ;
    }
    else
    d2.mois += 1 ;
    for(i=0;i<n;i++){
        if((verifDateSf((sf+i)->dateDebSF , d2) )&& (verifDateSf( d1,(sf+i)->dateDebSF))){
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
     if(i == 0)
            printf("aucune session ce mois");
}
void filtrerParTitre(SESSIONFORMATION *sf,int n){
  int i=0;
  char Ts[20];
  bool trouver=false;
  printf("donner le titre de la session ");
  scanf("%s",&Ts);
  while((i<n) && (trouver=true))
  {
      if ((strstr((sf+i)->titreSF , Ts)!=NULL) || (strstr(Ts, (sf+i)->titreSF )!=NULL))
      {
          printf("\n*********************\n");
       printf("\n informations sur la session de formation : %s\n",Ts);
       printf("\n c'est la session %d",i+1);
       printf("\n code : %d ",(sf+i)->codeSF) ;
       printf("\n date debut : %02d/%02d/%d",(sf+i)->dateDebSF.jour,(sf+i)->dateDebSF.mois,(sf+i)->dateDebSF.annee);
       printf("\n date fin : %02d/%02d/%d",(sf+i)->dateFinSF.jour,(sf+i)->dateFinSF.mois,(sf+i)->dateFinSF.annee);
       printf("\n--------- LES FORMATEUR(S) : -------- \n ");
         afficherFormateur((sf+i)->formateurs,(sf+i)->nbFormateur);
       printf("\n--------- LES FORMATION(S) : -------- \n ");
         afficherFormation((sf+i)->formations,(sf+i)->nbFormation);
       printf("\n--------- LES CANDIDATS(S) : -------- \n ");
         afficherCandidat((sf+i)->candidats,(sf+i)->nbCandidat);
        trouver= true;
      }
      i++;
  }
  if (trouver==false)
    printf("cette session n'existe pas ");
}

void candidatAge(SESSIONFORMATION* sf, int n){
    for(int i=0;i<n;i++){
                 printf("\n*********************\n");
     printf("\n informations sur la session de formation %d\n",i+1);
     printf("\n code : %d ",(sf+i)->codeSF) ;
     printf("\n titre : %s",(sf+i)->titreSF);
     pourcentCandidatParAge((sf+i)->candidats,(sf+i)->nbCandidat);


}}


void ajoutNbSessAuFormateur(FORMATEURSESSIONS** fSess,int n)
{
    int ce,c =1;
for(int i = 0 ; i<n ; i++){
ce = (*(fSess+i))->ceF ;
for(int j=i+1;j<n-1;j++){
        if(ce == (*(fSess+j))->ceF){
            (*(fSess+i))->nbSess ++ ;
        }

}}
//affFormParSess(fSess,n);

}


int meilleurformateur(FORMATEURSESSIONS** fSess,int n)
{
    int max=0 , i;
for(int i =1 ; i<n-1 ; i++){
        if((*(fSess+max))->nbSess < (*(fSess+i))->nbSess){
            max = i ;
        }
}
return max ;

}


void afficheMeilleur(FORMATEURSESSIONS** fSess,int i)
{
  printf("\n Le Formateur le plus demande est \n");
   printf("\n Code : %d ",(*(fSess+i))->ceF) ;
     printf("\n Nom : %s ",(*(fSess+i))->nomForm) ;
     printf("\n Prenom : %s ",(*(fSess+i))->prenomForm) ;
     printf("\n Titre Session : %s",(*(fSess+i))->titreSess);
     printf("\n Nombre des sessions qu'il forme : %d",(*(fSess+i))->nbSess);
        printf("\n Nombre des Specialités qu'il possede: %d",(*(fSess+i))->nbSpecialite);
   for(int j=0;j<(*(fSess+i))->nbSpecialite;j++){
   //printf("\n\t- code Specialite : %d ",((*(fSess+i))->spF+j)->codeSp);
   printf("\n\t- nom Specialite %s",((*(fSess+i))->spF+j)->nomSp);
   }

}



void affFormParSess(FORMATEURSESSIONS** fSess,int n){
printf("---%d---",n);
        for(int i=0;i<n;i++)
   {
     printf("\n*********************\n");
     printf("\n Les Formateurs les plus demandees %d\n",i+1);
   printf("\n code : %d ",(*(fSess+i))->ceF) ;
     printf("\n nom : %s ",(*(fSess+i))->nomForm) ;
     printf("\n titre Session : %s",(*(fSess+i))->titreSess);
    printf("\n nombre des sessions qu'il forme: %d",(*(fSess+i))->nbSess);
        printf("\n nombre des Specialités qu'il possede: %d",(*(fSess+i))->nbSpecialite);
   for(int j=0;j<(*(fSess+i))->nbSpecialite;j++){
   //printf("\n\t- code Specialite : %d ",((*(fSess+i))->spF+j)->codeSp);
   printf("\n\t- nom Specialite %s",((*(fSess+i))->spF+j)->nomSp);
   }

   }
}

void saisieFormateurParSess(SESSIONFORMATION* sf, int n,FORMATEURSESSIONS** fSess,int nfs)
{
   // int nbSessF ;
    FORMATEURSESSIONS* formS;
    int c=0 ;
    printf("*************************************");
    for(int i=0;i<n;i++){
      for(int j=0 ; j<(sf+i)->nbFormateur;j++){

        (*(fSess+c)) =(FORMATEURSESSIONS*) malloc (sizeof(FORMATEURSESSIONS));
        printf("etape1");
        (*(fSess+c))->ceF = (((sf+i)->formateurs)+j)->ceF ;
        strcpy((*(fSess+c))->nomForm , (((sf+i)->formateurs)+j)->nomF);
        strcpy((*(fSess+c))->prenomForm , (((sf+i)->formateurs)+j)->prenomF);
        (*(fSess+c))->nbSpecialite = (((sf+i)->formateurs)+j)->nbSpecialite;
        (*(fSess+c))->spF = (((sf+i)->formateurs)+j)->spF ;
        strcpy((*(fSess+c))->titreSess , (sf+i)->titreSF);
        //formS.sessForm = NULL ;
       (*(fSess+c))->nbSess = 1 ;
       c++;

    }
    }


}

