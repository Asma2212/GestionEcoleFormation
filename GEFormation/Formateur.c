#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"


int main()
{
FORMATEUR * f ;

   f=(FORMATEUR*) malloc (sizeof(FORMATEUR));
   if(!f) exit(-1);
   printf("\n saisir les informations du formateur \n");
   printf("\n saisir le code ");
   scanf("%d",&f->ceF);
   do{
   printf("\n saisir le nom");
   scanf("%s",&f->nomF);
   }while(!verifName(f->nomF));
   do{
   printf("\n saisir le prenom ");
   scanf("%s",&f->prenomF);
   }while(!verifName(f->nomF));
    printf("entrer le jour de naissance");
        scanf("%d",&f->dateNaissF.jour);
    printf("entrer le mois de naissance");
        scanf("%d",&f->dateNaissF.mois);
    printf("entrer l'annee de naissance");
        scanf("%d",&f->dateNaissF.annee);
   printf("\n saisir le numero de telephone ");
   scanf("%d",&f->numTel);

   printf("\n*********************\n");
   printf("\n informations sur le formateur\n");
   printf("\n code : %d ",f->ceF) ;
   printf("\n nom: %s",f->nomF);
   printf("\n prenom : %s",f->prenomF);
   printf("\n date de naissance : %d/%d/%d",f->dateNaissF.jour,f->dateNaissF.mois,f->dateNaissF.annee);
   printf("\n numero de telephone : %d",f->numTel);




   return 0 ;

}
