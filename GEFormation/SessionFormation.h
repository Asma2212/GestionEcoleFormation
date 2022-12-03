#ifndef SESSIONFORMATION_H_INCLUDED
#define SESSIONFORMATION_H_INCLUDED
#include <stdbool.h>

int saisieNbSF();
void AjouterCandidatSF(SESSIONFORMATION *,int);
void afficherSF(SESSIONFORMATION *,int);
SESSIONFORMATION* allocationSf(SESSIONFORMATION *,int)
void saisieSF(SESSIONFORMATION *,int,int);
#endif
