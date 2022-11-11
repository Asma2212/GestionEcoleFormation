#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include <string.h>
#include <stdbool.h>
bool verif(char ch[20])
{
    char ch1[40]="";
    int i=strlen(ch)-10;
    while(i<=strlen(ch))
    {
        strcat(ch1,ch[i]);
        i+=1;
    }
     return  ch=="@gmail.com";

}

void main()
{  bool c;
   CANDIDAT *cd[1];
   cd[1]=(CANDIDAT*) malloc (sizeof(CANDIDAT));
   if(!cd[1]) exit(-1);
   printf("\n saisir les informations du candidat \n");
   printf("\n saisir le code ");
   scanf("%d",&cd[1]->ce);
   printf("\n saisir le nom ");
   scanf("%s",&cd[1]->nom);
   printf("\n saisir le prenom ");
   scanf("%s",&cd[1]->prenom);
   printf("\n saisir la date de naissance ");
   scanf("%d%d%d",&cd[1]->dateNaiss.jour,&cd[1]->dateNaiss.mois,&cd[1]->dateNaiss.annee);
   printf("\n saisir le numero de telephone ");
   scanf("%d",&cd[1]->numTel);
   do
   {
     printf("\n saisir l'adresse mail ");
     scanf("%s",&cd[1]->email);
   }
   while(verif(cd[1]->email));
   printf("%s",c);
   printf("\n*********************\n");
   printf("\n informations sur le candidat\n");
   printf("\n code : %d ",cd[1]->ce) ;
   printf("\n nom: %s",cd[1]->nom);
   printf("\n prenom : %s",cd[1]->prenom);
   printf("\n date de naissance : %d/%d/%d",cd[1]->dateNaiss.jour,cd[1]->dateNaiss.mois,cd[1]->dateNaiss.annee);
   printf("\n numero de telephone : %d",cd[1]->numTel);
   printf("\n adresse mail : %s",cd[1]->email);




   getch();
}
