#ifndef SESSIONFORMATION_H_INCLUDED
#define SESSIONFORMATION_H_INCLUDED
#include <stddef.h>
bool existeCodeSf(SESSIONFORMATION* ,int,int);
FORMATEURSESSIONS** allocFormDem(FORMATEURSESSIONS** ,int);
int saisieNbSF();
void AjouterCandidatSF(SESSIONFORMATION *,int);
void afficherSF(SESSIONFORMATION *,int);
SESSIONFORMATION* allocationSf(SESSIONFORMATION *,int)
void saisieSF(SESSIONFORMATION *,int,int);
void modifierSF(SESSIONFORMATION* ,int);
void supprimerSF(SESSIONFORMATION* ,int*);
void filtrerParDate(SESSIONFORMATION* ,int);
void filtrerParTitre(SESSIONFORMATION* ,int);
void candidatAge(SESSIONFORMATION* , int);
void ajoutNbSessAuFormateur(FORMATEURSESSIONS** ,int);
int meilleurformateur(FORMATEURSESSIONS** ,int);
void afficheMeilleur(FORMATEURSESSIONS** ,int);
void affFormParSess(FORMATEURSESSIONS** ,int);
void saisieFormateurParSess(SESSIONFORMATION* , int,FORMATEURSESSIONS** ,int);
#endif
