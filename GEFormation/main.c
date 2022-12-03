#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "mylib.h"
/*
#include "Formateur.h"
#include "Candidat.h"
#include "Formation.h"
#include "SessionFormation.h"
*/
#include "Formateur.c"
#include "Candidat.c"
#include "Formation.c"
#include "SessionFormation.c"

#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
FORMATEUR* f;
int nbSf,nbC,nbFT,choix,nbf,d,tot=0;
SESSIONFORMATION *sf ;
CANDIDAT *c;
FORMATION *ft;
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
printf("9/ ajouter candidat à une session \n") ;
printf("10/ Sortir  \n") ;
printf("\nTapez votre choix ") ;
scanf("%d",&choix);


switch(choix)
{
    case 1 :

        nbSf=saisieNbSF();
        tot = tot + nbSf ;
        sf=allocationSf(sf,tot);

        saisieSF(sf,tot,tot-nbSf);

        break ;
    case 2 : afficherSF(sf,tot);

     break ;
    case 3 :
        nbf=saisieNbFormateur();
        f=allocationForm(nbf);
        saisieFormateur(f,nbf);
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
         ft=allocationFormation(nbFT);
         saisieFormation(ft,nbFT);
     break ;
     case 8 : afficherFormation(ft,nbFT);
     break ;
    case 9 : AjouterCandidatSF(sf,nbSf);
     break ;
}
printf("\n ----------------------------- \n") ;
}while(choix!=10);

   return 0 ;
}
