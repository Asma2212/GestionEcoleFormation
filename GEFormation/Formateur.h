#ifndef FORMATEUR_H_INCLUDED
#define FORMATEUR_H_INCLUDED
#include <stdbool.h>


int saisieNbFormateur();
FORMATEUR* allocationForm(int);
void saisieFormateur(FORMATEUR*,int );
void afficherFormateur(FORMATEUR* ,int );
bool existeCode(FORMATEUR* ,int,int);
void saisieSpecialite(int ,SPECIALITE*);
void modifierFormateur(FORMATEUR* ,int*);
void supprimerFormateur(FORMATEUR* ,int*);
#endif
