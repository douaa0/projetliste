#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphemat.h"

//mettre tous les champs à faux
static void razMarque(GrapheMat* graphe){
	int i;
	for(i=0; i<graphe->n; i++){
		graphe->marque[i] = faux;
	}
}

//allocation de graphe
GrapheMat* creerGrapheMat (int nMax, int value){
	GrapheMat* graphe = (GrapheMat*) malloc (sizeof(GrapheMat));
	graphe->n = 0;
	graphe->nMax = nMax;
	graphe->value = value;
	graphe->nomS = (NomSom*) malloc (sizeof(NomSom) *nMax);
	graphe->marque = (booleen*) malloc (sizeof(booleen) *nMax);
	graphe->element = (int*) malloc (sizeof(int) *nMax*nMax);
	graphe->valeur = (int*) malloc (sizeof(int) *nMax*nMax);
	
	int i;
	int j;
	for(i=0; i<nMax; i++){
		for(j=0; j<nMax; j++){
			graphe->element [i*nMax+j] = faux;
			graphe->valeur [i*nMax+j] = INFINI;
		}
	}
	razMarque(graphe);
	
	return graphe;
}

//desallocation d'un graphe
void detruireGraphe (GrapheMat* graphe){
	free(graphe->nomS);
	free(graphe->marque);
	free(graphe->element);
	free(graphe->valeur);
	free(graphe);
}

//fournit le rang dans le tableau nomS du nom
static int rang (GrapheMat* graphe, NomSom nom){
	int i=0;
	booleen trouve = faux;
	while((i<graphe->n) && !trouve){
		trouve = strcmp(graphe->nomS[i], nom)==0;
		if(!trouve) i++;
	}
	return trouve ? i : -1;
}

//insertion d'un sommet dans un graphe
void ajouterUnSommet (GrapheMat* graphe, NomSom nom){
	if(rang(graphe, nom) == -1){
		if(graphe->n < graphe->nMax){
			strcpy(graphe->nomS[graphe->n++], nom);
		} else {
			printf("\nNombre de sommets > %d\n", graphe->nMax);
		}
	} else {
		printf("\n%d deja defini\n", nom);
	}
}

//insertion d'un arc dans un  graphe, somD est de depart, somA d'arrive
void ajouterUnArc (GrapheMat* graphe, NomSom somD, NomSom somA, int cout){
	int nMax = graphe->nMax;
	int rd = rang(graphe, somD);
	int rg = rang(graphe, somA);
	graphe->element[rd*nMax+rg]=vrai; //rd*nMax+rg pour se positionner dans la matrice
	graphe->valeur[rd*nMax+rg]=cout;
}

//ecriture d'un graphe
void ecrireGraphe (GrapheMat* graphe){
	int nMax=graphe->nMax;
	int i;
	int j;
	for(i=0; i<graphe->n; i++){
		printf("%s",graphe->nomS[i])
	}
	printf(";\n");
	for(i=0; i<graphe->n; i++){
		printf("\n%s", graphe->nomS[i]);
		for(j=0; j<graphe->n; j++){
			if(graphe->element[i*nMax+j] == vrai){
				printf("%s", graphe->nomS[j]);
				if(graphe->value){
					printf("%d", graphe->valuer[i*nMax+j]);
				}
			}
		}
		printf(";");
	}
}

//function profondeur
static void profondeur(GrapheMat* graphe, int numSommet){
	int nMax = graphe->nMax;
	graphe->marque[numSommet] = vrai;
	printf("%s\n", graphe->nomS[numSommet]);
	int i;
	for(i=0; i<graphe->n; i++){
		if((graphe->element[numSommet*nMax+i] == vrai) && !graphe->marque[i]){
			profondeur(graphe, i);
		}
	}
}

//parcours en profondeur d'un graphe
void parcoursProfond (GrapheMat* graphe){
	razMarque(graphe);
	int i;
	for(i=0; i<graphe->n; i++){
		if(!graphe->marque[i]){
			profondeur(graphe, i);
		}
	}
}
