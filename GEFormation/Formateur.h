#ifndef FORMATEUR_H_INCLUDED
#define FORMATEUR_H_INCLUDED
#include <stdbool.h>

bool verifEmail(char[]);
bool verifName(char[]);
int saisieNbFormateur();
void afficherFormateur(FORMATEUR* ,int );
void saisieFormateur(FORMATEUR*,int );
void saisieSpecialite(int ,SPECIALITE*);
FORMATEUR* allocationForm(int);


#endif
