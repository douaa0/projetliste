#include "liste.h"

typedef Liste Pile;

char* ecrireEntier(Objet* objet);

Pile* creerPile(int type, char* (*afficher) (Objet*),
                 int (*comparer) (Objet*, Objet*) );

booleen pileVide(Pile *p);

void empiler(Pile* p,Objet *objet);

Objet* depiler(Pile* p);

void listerPile(Pile* p);

void detruirePile(Pile* p);
