
typedef struct Sommet{
    int cle;
    struct Sommet * Pere;
    struct Sommet * FG;
    struct Sommet * FD;
}Sommet;

typedef struct SommetCompact{
    struct SommetCompact * gauche;
    struct SommetCompact * droit;
    int inf;
    int sup;
}SommetCompact;


typedef SommetCompact * ArbreCompact;



typedef Sommet * Arbre;

Sommet * creerSommet(int cle);
void insererSommet(Arbre * a, int cle);
int rechercheSommet(Arbre a, int cle);
void afficherArbre(Arbre a);
SommetCompact * creerSommetCompact(int cle);
void insererElement(int cle, ArbreCompact * a);
int rechercheElement(int cle, ArbreCompact *a);
void afficherArbreCompact(ArbreCompact a);
int nombreSommets(ArbreCompact a,int * nbSommets);
int tailleArbre(ArbreCompact a, int nbSommets);
