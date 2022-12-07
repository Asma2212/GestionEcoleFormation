#ifndef FORMATION_H_INCLUDED
#define FORMATION_H_INCLUDED
#include <stdbool.h>

bool existeCodeF(FORMATION* ,int,int);
int saisieInt2();
void afficherFormation(FORMATION *,int);
void saisieFormation(FORMATION*,int);
FORMATION * allocationFormation(int);
void modifierFormation(FORMATION* ,int);
void supprimerFormation(FORMATION* ,int*);
#endif
