#ifndef CANDIDAT_H_INCLUDED
#define CANDIDAT_H_INCLUDED

#include <stdbool.h>

bool verifDate(int,int,int);
void saisiecandidat(CANDIDAT *,int);
void afficherCandidat(CANDIDAT *,int);
CANDIDAT* allocationCand(int);
int saisieInt1();

#endif
