#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "Formateur.c"
#include "Candidat.c"
#include "Formation.c"
#include "SessionFormation.c"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
FORMATEUR* ft;
int nbSf,nbC,nbFT,choix,nbf;
SESSIONFORMATION *sf ;
CANDIDAT *c;
FORMATION *f;
// menu : planification des sessions de formations // consulter la liste des formateurs //Ajouter un candidat à une session
// menu
do{
printf("___________________________________\n choisir l'un des traitements Suivants:\n___________________________________\n") ;
printf("1/ planifier une ou plusieurs session(s) de formations \n") ;
printf("2/ Consulter les sessions de formations  \n") ;
printf("3/ Ajouter un ou plusieurs formateur \n") ;
printf("4/ consulter la liste des formateurs  \n") ;
printf("5/ Ajouter un ou plusieurs candidat \n") ;
printf("6/ Consulter la liste des candidats \n") ;
printf("7/ Ajouter une ou plusieures formation \n") ;
printf("8/ Consulter la liste des formations \n") ;
printf("9/ Sortir  \n") ;
printf("\nTapez votre choix ") ;
scanf("%d",&choix);
switch(choix)
{
    case 1 :
        nbSf=saisieNbSF();
        allocationSf(nbSf);
        saisieSF(sf,nbSf);
        break ;
    case 2 : afficherSF(sf,nbSf);

     break ;
    case 3 :
        nbf=saisieNbFormateur();
        ft=allocationForm(nbf);
        saisieFormateur(ft,nbf);
     break ;
    case 4 : afficherFormateur(f,nbf);
     break ;
     case 5 :
         nbC=saisieInt1();
         c=allocationCand(nbC);
         saisiecandidat(c,nbC);
     break ;
     case 6 : afficherCandidat(c,nbC);
     break ;
     case 7 :
         nbFT=saisieInt2();
         f=allocationFormation(nbFT);
         saisieFormation(f,nbFT);
     break ;
     case 8 : afficherFormation(ft,nbFT);
     break ;
}
printf("\n ----------------------------- \n") ;
}while(choix!=9);

   return 0 ;
}
