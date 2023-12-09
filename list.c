#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#define faux 0
#define vrai 1


void initListe(Liste* li,int type,char* (*afficher)(Objet*), int(*comparer)(Objet*, Objet*)){
    li->premier = NULL;
    li->dernier = NULL;
    li->courant = NULL;
    li->nbElt = 0;
    li->type = type;
    li->afficher = afficher;
    li->comparer = comparer;
}

Liste* creerListe (int type, char* (*afficher) (Objet*), int (*comparer) (Objet*, Objet*) ){
	Liste* li=(Liste*)malloc(sizeof(Liste));
	initListe(li,type,afficher,comparer);
	return li;
}

booleen listeVide(Liste* li){
	return li->nbElt == 0;
}

int nbElement(Liste* li){
	return li->nbElt;
}

static Element* creerElement(){
	return (Element*) malloc(sizeof(Element));
	//return new Element();
}

void insererEnTeteDeListe(Liste* li, Objet* objet) {
    Element* nouveau = creerElement();
    nouveau->reference = objet;
    nouveau->suivant = li->premier;
    li->premier = nouveau;
    if (li->dernier == NULL) {
        li->dernier = nouveau;
    }
    li->nbElt++;
}

static void insererApres (Liste* li, Element* precedent, Objet* objet){
	if (precedent == NULL){
		insererEnTeteDeListe(li, objet);
	} else {
		Element* nouveau = creerElement();
		nouveau->reference = objet;
		nouveau->suivant = precedent->suivant;
		precedent->suivant = nouveau;
		if(precedent == li->dernier) {
			li->dernier = nouveau;
		}
		li->nbElt++;
	}
}

void insererEnFinDeListe(Liste* li, Objet* objet){
	insererApres(li, li->dernier, objet);
}

void ouvrirListe (Liste* li){
	li->courant = li->premier;
}

booleen finListe (Liste* li){
	return li->courant == NULL;
}

static Element* elementCourant(Liste* li){
	Element* ptc = li->courant;
	if(li->courant != NULL){
		li->courant = li->courant->suivant;
	}
	return ptc;
}

Objet* objetCourant (Liste* li){
	Element* ptc = elementCourant(li);
	return ptc == NULL ? NULL : ptc ->reference;
}

void listerListe (Liste* li){
	ouvrirListe(li);
	while(!finListe(li)){
		Objet* objet = objetCourant(li);
		printf("%s\t", li->afficher(objet));
	}
}

Objet* chercherUnObjet(Liste* li, Objet* objetCherche){
	booleen trouve = faux;
	Objet* objet; //pointeur courant
	ouvrirListe(li);
	while(!finListe(li) && !trouve){
		objet = objetCourant(li);
		trouve = li->comparer (objetCherche, objet) == 0;
	}
	return trouve ? objet : NULL;
}

Objet* extraireEnTeteDeListe (Liste* li){
	Element* extrait = li->premier;
	if(!listeVide(li)) {
		li->premier = li->premier->suivant;
		if(li->premier==NULL){
			li->dernier=NULL;
		}
		li->nbElt--;
	}
	return extrait != NULL ? extrait->reference : NULL;
}

static Objet* extraireApres(Liste* li, Element* precedent){
	if(precedent == NULL){
		return extraireEnTeteDeListe(li);
	}
	Element* extrait = precedent -> suivant;
	if(extrait != NULL){
		precedent->suivant = extrait->suivant;
		if(extrait == li -> dernier){
			li ->dernier = precedent;
		}
		li->nbElt--;
	}
	return extrait != NULL ? extrait->reference : NULL;
}

Objet* extraireEnFinDeListe(Liste* li){
	Objet* extrait;
	if (listeVide(li)){
		extrait = NULL;
	} else if (li->premier == li->dernier){
		extrait = extraireEnTeteDeListe(li);
	} else {
		Element* ptc = li->premier;
		while(ptc->suivant != li->dernier){
			ptc = ptc->suivant;
		}
		extrait = extraireApres(li, ptc);
	}
	return extrait;
}

booleen extraireUnObjet(Liste* li, Objet* objet){
	Element* precedent = NULL;
	Element* ptc = NULL;
	booleen trouve = faux;
	ouvrirListe(li);
	while(!finListe(li) && !trouve){
		precedent = ptc;
		ptc = elementCourant(li);
		trouve = (ptc->reference == objet) ? vrai : faux;
	}
	if (!trouve) return faux;
	Objet* extrait = extraireApres(li, precedent);
	return vrai;
}

void detruireListe(Liste* li){
	ouvrirListe (li);
	while(!finListe (li)){
		Element* ptc = elementCourant(li);
			//free(ptc->reference);
	free(ptc);
	}
	initListe(li, 0, afficher, comparerInt);
}

char*  afficher (Objet* objet) {
    int * entier = (int*) objet;
    char* output = (char*) malloc (sizeof (int));
    snprintf(output, sizeof(int), "%d \n", *entier);
    return output;
}

int comparerInt(Objet* objet1, Objet* objet2) {
    int * a = (int*) objet1;
    int * b = (int*) objet2;
    if (*a > *b)
    {
      return 1;
    }
    else if (*a == *b)
    {
      return 0;
    }
    else
    {
      return -1;
    }
}
