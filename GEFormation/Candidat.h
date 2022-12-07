#ifndef CANDIDAT_H_INCLUDED
#define CANDIDAT_H_INCLUDED

#include <stdbool.h>
bool existeCodeC(CANDIDAT*,int,int);
bool verifDate(int,int,int);
void saisiecandidat(CANDIDAT *,int);
void afficherCandidat(CANDIDAT *,int);
CANDIDAT* allocationCand(int);
int saisieInt1();
void modifierCandidat(CANDIDAT* ,int);
void supprimerCandidat(CANDIDAT* ,int*);
int AgeCandidat(int);
void pourcentCandidatParAge(CANDIDAT*,int);
#endif
