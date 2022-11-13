#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "Formateur.c"
#include "Candidat.c"
#include "Formation.c"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
FORMATEUR* f;
int nbF,nbC,nbFT;
do{
printf("entrer le nombre des formateurs ");
scanf("%d",&nbF);
}while(nbF<=0);


f=(FORMATEUR*) malloc (nbF * sizeof(FORMATEUR));
 if(!f) exit(-1);
    saisieFormateur(f,nbF);
    afficherFormateur(f,nbF);

CANDIDAT *c;
nbC=saisieInt1();
allocationCand(nbC);
saisiecandidat(c,nbC);
afficherCandidat(c,nbC);

FORMATION *ft;
nbFT=saisieInt2();
allocationFormation(nbFT);
saisieFormation(ft,nbFT);
afficherFormation(ft,nbFT);
   return 0 ;
}
