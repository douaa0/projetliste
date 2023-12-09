#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int menu () {
printf ("\n\n GESTION D'UN GRAPHE \n\n");
printf ("1 – Créer un graphe\n");
printf ("2 - ajouter Un Sommet \n");
printf ("3 - ajouter Un Arc \n");
printf ("4 - ecrire Graphe \n");
printf ("5 - parcours Profond \n");
printf ("6 - Destruction du graph\n");
printf ("\n");
printf ("Votre choix ? ");
int cod; scanf ("%d", &cod); getchar();
printf ("\n");
return cod;
}

int main () {
	Liste* maListe = NULL;
	Objet* objet = NULL;
	int choix = 0;
	 do {
        choix = menu();
        switch (choix) {
            case 1:
                // Créeation d'un graphe
                
                break;
