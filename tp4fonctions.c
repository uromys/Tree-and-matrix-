#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"

Sommet * creerSommet(int cle){
    Sommet * nouv = malloc(sizeof(Sommet));
    nouv->cle = cle;
    nouv->Pere = NULL;
    nouv->FD = NULL;
    nouv->FG = NULL;
    return nouv;
}

void insererSommet(Arbre * a, int cle){
    Arbre noeudCourant = *a;
    if(rechercheSommet(*a,cle)) return;
    if(noeudCourant == NULL){
        *a = creerSommet(cle);
    }
    else{
        Arbre nouv = creerSommet(cle);
        while(noeudCourant != NULL){
            if(noeudCourant->cle > cle){
                if(noeudCourant->FG != NULL)
                    noeudCourant = noeudCourant->FG;
                else{
                    noeudCourant->FG = nouv;
                    nouv->Pere = noeudCourant;
                    return;
                }
            }
            else{
                if(noeudCourant->FD != NULL)
                    noeudCourant = noeudCourant->FD;
                else{
                    noeudCourant->FD = nouv;
                    nouv->Pere = noeudCourant;
                    return;
                }
            }
        }

    }
}


int rechercheSommet(Arbre a, int cle){
    Arbre pntr = a;
    if(pntr == NULL) return 0;
    else{
        while(pntr != NULL){
            if(pntr->cle == cle){
                return 1;
            }
            if(pntr->cle < cle){
                pntr = pntr->FD;
            }
            else pntr = pntr->FG;
        }
    }
    return 0;
}

void afficherArbre(Arbre a){
    /*if(a == NULL) return;
    else{
        arbre temp = a;
        while(temp->FG != NULL){
            temp = temp->FG;
        }
        printf("%d\n",temp->cle);


    }*/

    Arbre temp = a;
    if(a == NULL) return;

    if(temp->FG != NULL) {
        afficherArbre(temp->FG);
    }
    printf("%d\n",temp->cle);

    if(temp->FD != NULL){
            afficherArbre(temp->FD);
    }
}

void afficherArbre1(Arbre a){
    if (a == NULL) return;
    if (a != NULL){
        afficherArbre1(a->FG);
        printf("%d\n",a->cle);
        afficherArbre1(a->FD);
    }
}

SommetCompact * creerSommetCompact(int cle){
    SommetCompact * nouv = malloc(sizeof(SommetCompact));
    nouv->gauche = NULL;
    nouv->droit = NULL;
    nouv->inf = cle;
    nouv->sup = cle;
    return nouv;
}

void insererElement(int cle, ArbreCompact * a){

    ArbreCompact temp = *a;
    ArbreCompact pere = NULL;
    ArbreCompact nouv = creerSommetCompact(cle);
    if(rechercheElement(cle, a)) return;  //L'element est deja dans l'arbre
    if(temp == NULL){
        temp = nouv;
    }
    else{
        while(temp != NULL){
            if(temp->inf - 1 > cle){
                pere = temp;
                temp = temp->gauche;
            }
            else if(temp->sup + 1 < cle){
                pere = temp;
                temp = temp->droit;
            }
            else if(temp->inf - 1 == cle){
                temp->inf = temp->inf - 1;
                if((temp->gauche != NULL) && (abs((temp->gauche)->sup - temp->inf) == 1)){  //Les 2 ensembles etaient séparés de l'element qu'on a ajouté
                    ArbreCompact tempGauche = temp->gauche; //nouvelle variable temporaire pour permutation
                    temp->inf = temp->gauche->inf;
                    //free(temp->gauche);
                    if(tempGauche->gauche != NULL){
                        temp->gauche = tempGauche->gauche;
                    }
                    else {
                        temp->gauche = NULL;
                    }
    //On se trouve dans le cas ou le fait d'ajouter un nouveau nombre
    //implique qu'on doit rassembler deux ensembles
                }
                return;
            }
            else if(temp->sup + 1 == cle){ //Idem a droite
                temp->sup = temp->sup + 1;
                if((temp->droit != NULL) && (((temp->droit)->inf - temp->sup) == 1 || ((temp->droit)->inf - temp->sup) == -1)){
                    ArbreCompact tempDroite = temp->droit; //nouvelle variable temporaire pour permutation
                    temp->sup = tempDroite->sup;
                    //free(temp->droit);
                    if(tempDroite->droit != NULL){
                        temp->droit = tempDroite->droit;
                    }
                    else {
                        temp->droit = NULL;
                    }
                }
                return;
            }
        }
        if(pere->inf > cle){
            temp = nouv;
            pere->gauche = temp;
        }
        if(pere->sup < cle){
            temp = nouv;
            pere->droit = temp;
        }

    }
}

int rechercheElement(int cle, ArbreCompact *a){
    ArbreCompact temp = *a;
    if(temp == NULL){
        return 0;         //0 signifie que l'element n'est pas dans l'arbre
    }
    else{
        while(temp != NULL){
            if(temp->inf <= cle && temp->sup >= cle){
                return 1;
            }
            if(temp->inf > cle) {
                temp = temp->gauche;
            }
            else {
                temp = temp->droit;
            }
        }
    return 0;
    }
}

void afficherArbreCompact(ArbreCompact a){
    if(a == NULL) return;
    afficherArbreCompact(a->gauche);
    /*for(int i = a->inf; i<=a->sup; i++){
        printf("%d\n",i);
    */
    if(a->inf != a->sup){
        printf("Borne inferieure :%d\n",a->inf);
        printf("Borne superieure :%d\n",a->sup);
    }
    else{
        printf("Element unique :%d\n",a->inf);
    }
    printf("\n");
    afficherArbreCompact(a->droit);
    return;
}

int nombreSommets(ArbreCompact a, int * nbSommets){
    //int * pnt = &nbSommets;
    if(a == NULL) return 0;
    else{
    nombreSommets(a->gauche,nbSommets);
    (*nbSommets)++;
    nombreSommets(a->droit,nbSommets);
    }
    return *nbSommets;
}

int tailleArbre(ArbreCompact a, int nbSommets){
    int taille = 0;
    //int * pnt = &nbSommets;
    taille = nbSommets*sizeof(SommetCompact); // Equivalent a nbSommets*(2*sizeof(int) + 2*sizeof(SommetCompact*))
    return taille;
}



