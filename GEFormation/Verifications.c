#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool verifDate(int nj,int nm,int na)
{
    if((nj>=1) && (nj<=29))
    {if((nm>=1) && (nm<=12))
      {
          if((na>1900) && (na<=2022)) return true;
          else {printf("l'annee n'existe pas ");
          return false;}
      }
     else {printf("le mois n'existe pas");
          return false;}
    }
    else if (nj==30)
    {
        if(nm>=1 && nm<=12 && nm!=2) return true;
         else{ printf("le jour n'est pas compatible avec le mois");
         return false;}
    }
    else if (nj==31)
    {
        if(nm==1 && nm==3 && nm==5 && nm==7 && nm==8 && nm==10 && nm==12) return true;
        else {printf("le jour n'est pas compatible avec le mois");
              return false;}
    }
    else{ printf("le jour n'existe pas");
          return false;}
}

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

