#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "mylib.h"
bool verifEmail(char ch[20])
{
bool test1=false;
int i=0,n=0,p=0 ;
do{
    if(ch[i]=='@'){
        n++;
        test1 = true ;

    }
    if(test1 && ch[i]=='.'){
        p++;
    }
    i++;
}while(i<strlen(ch));
if(p!=1 || n!=1 )
printf("l email doit etre de la forme xxxx@yyyy.www");
else
return true ;

}
bool verifName(char ch[20]){
    for(int i=0;i<strlen(ch);i++)
        if(isdigit(ch[i])){
            printf("!cette chaine ne doit pas contenir des chiffres");
            return false ;
        }
    return true ;
}

int saisieNbFormateur()
{
    int nbF;
do{
printf("entrer le nombre des formateurs ");
scanf("%d",&nbF);
}while(nbF<=0);
    return nbF;

}
FORMATEUR* allocationForm(int n)
{
    FORMATEUR* f;
    f=(FORMATEUR*) malloc (n * sizeof(FORMATEUR));
    if(!f) exit(-1);
    return f;
}

void saisieSpecialite(int n,SPECIALITE* spF){
for(int i=0;i<n;i++){
   printf("\n saisir le code Specialite");
   scanf("%d",&(spF+i)->codeSp);
   printf("\n saisir le nom");
   scanf("%s",&(spF+i)->nomSp);
}

}
void saisieFormateur(FORMATEUR* f,int n){

  for(int i=0;i<n;i++){
   printf("\n saisir les informations du formateur ** %d ** \n",i+1);
   printf("\n saisir le code ");
   scanf("%d",&(f+i)->ceF);
   do{
   printf("\n saisir le nom");
   scanf("%s",&(f+i)->nomF);
   }while(!verifName(f->nomF));
   do{
   printf("\n saisir le prenom ");
   scanf("%s",&(f+i)->prenomF);
   }while(!verifName((f+i)->nomF));
    printf("entrer le jour de naissance");
        scanf("%d",&(f+i)->dateNaissF.jour);
    printf("entrer le mois de naissance");
        scanf("%d",&(f+i)->dateNaissF.mois);
    printf("entrer l'annee de naissance");
        scanf("%d",&(f+i)->dateNaissF.annee);
   printf("\n saisir le numero de telephone ");
   scanf("%d",&(f+i)->numTel);

do{
   printf("\n saisir l' email ");
   scanf("%s",&(f+i)->emailF);
}while(!verifEmail((f+i)->emailF));

    printf("entrer le nombre des specialité qu'il possede");
        scanf("%d",&(f+i)->nbSpecialite);
(f+i)->spF=(SPECIALITE*) malloc ( (f+i)->nbSpecialite * sizeof(SPECIALITE));
saisieSpecialite((f+i)->nbSpecialite,(f+i)->spF);
  }

}

void afficherFormateur(FORMATEUR* f,int n){
for(int i=0;i<n;i++){
   printf("\n*********************\n");
   printf("\n informations sur le formateur ** %d ** \n",i+1);
   printf("\n code : %d ",(f+i)->ceF) ;
   printf("\n nom: %s ",(f+i)->nomF);
   printf("\n prenom : %s ",(f+i)->prenomF);
   printf("\n date de naissance : %d/%d/%d",(f+i)->dateNaissF.jour,(f+i)->dateNaissF.mois,(f+i)->dateNaissF.annee);
   printf("\n numero de telephone : %d",(f+i)->numTel);
   printf("\n numero de nbSpecialités : %d",(f+i)->nbSpecialite);
   for(int i=0;i<(f+i)->nbSpecialite;i++){
   printf("\n code Specialite : %d ",((f+i)->spF+i)->codeSp);
   printf("\n nom Specialite %s",&((f+i)->spF+i)->nomSp);

}
}
}
