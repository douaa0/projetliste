#ifndef LIST_H
#define LIST_H
#include <stdbool.h>
typedef int  booleen;
typedef void Objet;

#define faux   0
#define vrai   1
#define NONORDONNE  0
#define CROISSANT   1
#define DECROISSANT 2

// un élément de la liste
typedef struct element {
  Objet* reference;
  struct element* suivant;
} Element;

// le type Liste
typedef struct {
  Element* premier;
  Element* dernier;
  Element* courant;
  int      nbElt;
  int      type;    // 0:simple, 1:croissant, 2:décroissant
  char*    (*afficher) (Objet*);
  int      (*comparer) (Objet*, Objet*);
} Liste;

void initListe (Liste* li, int type, char* (*afficher) (Objet*), int (*comparer) (Objet*, Objet*));
Liste* creerListe (int type, char* (*afficher) (Objet*), int (*comparer) (Objet*, Objet*) );

booleen listeVide (Liste* li);
int nbElement (Liste* li);

void insererEnTeteDeListe (Liste* li, Objet* objet);

void ouvrirListe(Liste* li);

booleen finListe(Liste* li);

Objet* objetCourant(Liste* li);

void listerListe (Liste* li);

Objet * chercherUnObjet(Liste* li, Objet* objetCherche);

Objet* extraireEnTeteDeListe (Liste* li);

booleen listeVide(Liste* li);

Objet* extraireEnFinDeListe (Liste* li);

booleen extraireUnObjet(Liste* li, Objet* objet);

void detruireListe(Liste* li);

void insererEnFinDeListe(Liste* li, Objet* objet);

char *afficher(Objet *objet);

int comparerInt(Objet* objet1, Objet *objet2);

#endif

