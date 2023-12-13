#include <stdio.h>
#include <stdlib.h>
#include "graphemat.h"
#define faux 0
#define vrai 1
#define INFINI INT_MAX

int menu () {
printf ("\n\n GESTION DUN GRAPHE \n\n");
printf ("1 – Creer un graphe\n");
printf ("2 - ajouter Un Sommet \n");
printf ("3 - ajouter Un Arc \n");
printf ("4 - ecrire Graphe \n");
printf ("5 - parcours Profond \n");
printf ("6 - Destruction du graph\n");
printf ("7 - Floyd \n");
printf ("\n");
printf ("Votre choix ? ");
int cod; scanf ("%d", &cod); getchar();
printf ("\n");
return cod;
}

int main () {
	GrapheMat* monGraphe = NULL;

    int choix;
    do {
        choix = menu();

        switch (choix) {
            case 1:  // Créer un graphe
                if (monGraphe != NULL) {
                    detruireGraphe(monGraphe);
                }
                int nMax, value;
                printf("Entrez le nombre maximal de sommets : ");
                scanf("%d", &nMax);
                printf("Le graphe est valué (1) ou non-valué (0) ? ");
                scanf("%d", &value);
                monGraphe = creerGrapheMat(nMax, value);
                break;

            case 2:  // ajouter Un Sommet
                if (monGraphe != NULL) {
                    NomSom nom;
                    printf("Entrez le nom du sommet : ");
                    scanf("%s", nom);
                    ajouterUnSommet(monGraphe, nom);
                } else {
                    printf("Veuillez créer un graphe d'abord.\n");
                }
                break;

            case 3:  // ajouter Un Arc
                if (monGraphe != NULL) {
                    NomSom somD, somA;
                    int cout;
                    printf("Entrez le nom du sommet de départ : ");
                    scanf("%s", somD);
                    printf("Entrez le nom du sommet d'arrivée : ");
                    scanf("%s", somA);
                    printf("Entrez le coût de l'arc : ");
                    scanf("%d", &cout);
                    ajouterUnArc(monGraphe, somD, somA, cout);
                } else {
                    printf("Veuillez créer un graphe d'abord.\n");
                }
                break;

            case 4:  // ecrire Graphe
                if (monGraphe != NULL) {
                    ecrireGraphe(monGraphe);
                } else {
                    printf("Le graphe est vide.\n");
                }
                break;

            case 5:  // parcours Profond
                if (monGraphe != NULL) {
                    parcoursProfond(monGraphe);
                } else {
                    printf("Veuillez créer un graphe d'abord.\n");
                }
                break;

            case 6:  // Destruction du graphe
                if (monGraphe != NULL) {
                    detruireGraphe(monGraphe);
                    monGraphe = NULL;
                    printf("Le graphe a été détruit.\n");
                } else {
                    printf("Le graphe est déjà vide.\n");
                }
                break;
            case 7:  // Floyd
                if (monGraphe != NULL) {
                    floyd(monGraphe);
                } else {
                    printf("Veuillez créer un graphe d'abord.\n");
                }
            break;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }

    } while (choix != 7);

    return 0;
}
