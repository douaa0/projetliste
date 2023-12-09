#include <stdio.h>
#include <string.h>
#include "pile.h"

Pile* creerPile(int type, char* (*afficher)(Objet*), int (*comparer)(Objet*, Objet*))
{
    return creerListe(type,afficher,comparer);
}

booleen pileVide(Pile *p)
{
    return listeVide(p);
}

void empiler(Pile* p,Objet *objet)
{
    insererEnTeteDeListe(p,objet);
}

Objet* depiler(Pile* p)
{
    if(pileVide(p)){
        return NULL;
    } else {
        return extraireEnTeteDeListe(p);
    }
}

void listerPile(Pile* p)
{
    listerListe(p);
}

void detruirePile(Pile* p)
{
    detruireListe(p) ;
}
