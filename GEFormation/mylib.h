#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED
struct date
{
    int jour;
    int mois;
    int annee;

};
typedef struct date DATE;

struct specialite
{
    int codeSp;
    char nomSp[20];

};
typedef struct specialite SPECIALITE;

struct candidat
{
    int ce;
    DATE dateNaiss;
    int numTel;
    char nom[20];
    char prenom[20];
    char email[20];


};
typedef struct candidat CANDIDAT;

struct formateur
{
    int ceF;
    DATE dateNaissF;
    int numTel;
    char nomF[20];
    char prenomF[20];
    char emailF[20];
    int nbSpecialite ;
    SPECIALITE *spF ;

};
typedef struct formateur FORMATEUR;

struct formation
{
    int codeFormation;
    char titre[20] ;
    char desc[40] ;

};
typedef struct formation FORMATION;

struct sessionformation
{
    int codeSF;
    char titreSF[20] ;
    DATE dateDebSF;
    DATE dateFinSF;
    int nbMaxCandidat;
    float prix ;
    int nbCandidat;
    int nbFormateur;
    int nbFormation;
    CANDIDAT * candidats;
    FORMATEUR * formateurs;
    FORMATION * formations;
};
typedef struct sessionformation SESSIONFORMATION;

struct FormateurSession
{
    int ceF;
    char nomForm[20];
    char prenomForm[20];

    int nbSpecialite ;
    SPECIALITE *spF ;

    int nbSess ;
    char titreSess[20];
    //SESSIONFORMATION * sessForm;
};
typedef struct FormateurSession FORMATEURSESSIONS;


#endif // MYLIB_H_INCLUDED






