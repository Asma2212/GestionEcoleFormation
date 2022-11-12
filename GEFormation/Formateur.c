#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "mylib.h"
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

void saisieSpecialite(int n,SPECIALITE* spF){
for(int i=0;i<n;i++){
   printf("\n saisir le code Specialite");
   scanf("%d",&(spF+i)->codeSp);
   printf("\n saisir le nom");
   scanf("%s",&(spF+i)->nomSp);
}

}
void saisieFormateur(FORMATEUR* f){

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

do{
   printf("\n saisir l' email ");
   scanf("%s",&f->emailF);
}while(!verifEmail(f->emailF));

    printf("entrer le nombre des specialité qu'il possede");
        scanf("%d",&f->nbSpecialite);
f->spF=(SPECIALITE*) malloc ( f->nbSpecialite * sizeof(SPECIALITE));
saisieSpecialite(f->nbSpecialite,f->spF);
}

void afficherFormateur(FORMATEUR* f){

   printf("\n*********************\n");
   printf("\n informations sur le formateur\n");
   printf("\n code : %d ",f->ceF) ;
   printf("\n nom: %s ",f->nomF);
   printf("\n prenom : %s ",f->prenomF);
   printf("\n date de naissance : %d/%d/%d",f->dateNaissF.jour,f->dateNaissF.mois,f->dateNaissF.annee);
   printf("\n numero de telephone : %d",f->numTel);
   printf("\n numero de nbSpecialités : %d",f->nbSpecialite);
   for(int i=0;i<f->nbSpecialite;i++){
   printf("\n code Specialite : %d ",(f->spF+i)->codeSp);
   printf("\n le nom %s",&(f->spF+i)->nomSp);
}

}
