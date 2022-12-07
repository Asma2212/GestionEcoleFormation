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

#include "Verifications.c"

#include "Formateur.c"
#include "Candidat.c"
#include "Formation.c"
#include "SessionFormation.c"

#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
FORMATEUR* f =NULL;
int nbSf,nbC,nbFT,choix,nbf,d,tot=0,totCand=0,totFormation=0,ind,totFormateur=0;
SESSIONFORMATION *sf=NULL ;
CANDIDAT *c=NULL;
FORMATION *ft = NULL;
FORMATEURSESSIONS** formateurSess = NULL ;
int nbSessF =0;
// menu : planification des sessions de formations // consulter la liste des formateurs //Ajouter un candidat à une session
// menu
do{
printf("___________________________________\n choisir l'un des traitements Suivants:\n___________________________________\n") ;
printf("\n---- FORMATEUR ----\n") ;
printf("1/ Ajouter un ou plusieurs formateur \n") ;
printf("2/ consulter la liste des formateurs  \n") ;
printf("3/ Modifier un formateur  \n") ;
printf("4/ Supprimer un formateur  \n") ;

printf("\n---- CANDIDAT ----\n") ;
printf("5/ Ajouter un ou plusieurs candidat \n") ;
printf("6/ Consulter la liste des candidats \n") ;
printf("7/ Modifier un candidat \n") ;
printf("8/ Supprimer un candidat \n") ;

printf("\n---- FORMATION ----\n") ;
printf("9/ Ajouter une ou plusieures formation \n") ;
printf("10/ Consulter la liste des formations \n") ;
printf("11/ Modifier une formation \n") ;
printf("12/ Supprimer une formation \n") ;

printf("\n---- SESSION DE FORMAION ----\n") ;
printf("13/ planifier une ou plusieurs session(s) de formations \n") ;
printf("14/ Consulter les sessions de formations  \n");
printf("15/ ajouter un candidat à une session \n") ;
printf("16/ Modifier une session de formation \n") ;
printf("17/ supprimer une session de formation \n") ;
printf("\n---- PLUS ----\n") ;
printf("18/ les sessions de formation disponible ce mois \n") ;
printf("19/ chercher une session \n") ;
printf("20/ pourcentage des candidats selon leur age \n") ;
printf("21/ Le formateur le plus demande \n") ;
printf("------------\n22/ SORTIR  \n") ;
printf("\nTapez votre choix ") ;
scanf("%d",&choix);


switch(choix)
{
    case 1 :
        nbf=saisieNbFormateur();
        totFormateur += nbf ;
        f=allocationForm(f,totFormateur);
        saisieFormateur(f,totFormateur,totFormateur-nbf);
     break ;

    case 2 : afficherFormateur(f,nbf);
     break ;
      case 3 :modifierFormateur(f,nbf) ;
     break ;
     case 4 :supprimerFormateur(f,&nbf) ;
     break ;

     case 5 :
         nbC=saisieInt1();
         totCand = totCand + nbC ;
        c= allocationCand(c,totCand);
         saisiecandidat(c,totCand,totCand-nbC);
     break ;
     case 6 : afficherCandidat(c,totCand);
     break ;

     case 7 : modifierCandidat(c,nbC);
     break ;
     case 8 : supprimerCandidat(c,&nbC);
     break ;


     case 9 :
         nbFT=saisieInt2();
         totFormation = totFormation + nbFT ;
         ft=allocationFormation(ft,totFormation);
         saisieFormation(ft,totFormation,totFormation-nbFT);
     break ;
     case 10 : afficherFormation(ft,totFormation);
     break ;
      case 11 : modifierFormation(ft,nbFT);
     break ;
     case 12 : supprimerFormation(ft,&nbFT);
     break ;
         case 13 :

        nbSf=saisieNbSF();

        tot = tot + nbSf ;
        sf=allocationSf(sf,tot);
       formateurSess = saisieSF(sf,tot,tot-nbSf,formateurSess,&nbSessF);
printf("***** nb form %d *****",nbSessF);
        break ;
    case 14 : afficherSF(sf,tot);

     break ;
         case 15 : AjouterCandidatSF(sf,nbSf);
     break ;
     case 16 : modifierSF(sf,nbSf);
     break;
     case 17 : supprimerSF(sf,&nbSf);
     break;
     case 18 : filtrerParDate(sf,nbSf);
     break;
     case 19 : filtrerParTitre(sf,nbSf);
     break;
     case 20 : candidatAge(sf,nbSf);
     break;
    case 21 : ind = meilleurformateur(formateurSess,nbSessF);
    afficheMeilleur(formateurSess,ind);
     break;

}
printf("\n ----------------------------- \n") ;
}while(choix!=22);

   return 0 ;
}
