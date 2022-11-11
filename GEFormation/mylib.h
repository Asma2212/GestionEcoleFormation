struct date
{
    int jour;
    int mois;
    int annee;

};
typedef struct date DATE;
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
