#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int menu () {
printf ("\n\n GESTION D'UNE LISTE D'ENTIERS \n\n");
printf ("1 - Creer une liste\n");
printf ("2 - Insertion en tete de liste \n");
printf ("3 - Insertion en fin de liste \n");
printf ("4 - Retrait en tete de liste \n");
printf ("5 - Retrait en fin de liste \n");
printf ("6 - Retrait dun objet a partir de sa reference\n");
printf ("7 - Afficher les objets de la liste \n");
printf ("8 - Chercher Un objet \n");
printf ("9 - Destruction de la liste \n");
printf ("10 - Fin\n");
printf ("\n");
printf ("Votre choix ? ");
int cod; scanf ("%d", &cod); getchar();
printf ("\n");
return cod;
}

int main() {
    Liste* maListe = NULL;

    int choix;
    do {
        choix = menu();

        switch (choix) {
            case 1:
                if (maListe != NULL) {
                    detruireListe(maListe);
                }
                maListe = creerListe(NONORDONNE, afficher, comparerInt);
                break;

            case 2:
                if (maListe != NULL) {
                    int valeur;
                    printf("Entrez la valeur a inserer : ");
                    scanf("%d", &valeur);
                    insererEnTeteDeListe(maListe, &valeur);
                } else {
                    printf("Veuillez creer une liste d'abord.\n");
                }
                break;

            case 3:
                if (maListe != NULL) {
                    int valeur;
                    printf("Entrez la valeur à inserer : ");
                    scanf("%d", &valeur);
                    insererEnFinDeListe(maListe, &valeur);
                } else {
                    printf("Veuillez creer une liste d'abord.\n");
                }
                break;

            case 4:
                if (maListe != NULL && !listeVide(maListe)) {
                    int* valeurRetiree = (int*)extraireEnTeteDeListe(maListe);
                    printf("Objet retire : %d\n", *valeurRetiree);
                } else {
                    printf("La liste est vide.\n");
                }
                break;

            case 5:
                if (maListe != NULL && !listeVide(maListe)) {
                    int* valeurRetiree = (int*)extraireEnFinDeListe(maListe);
                    printf("Objet retire : %d\n", *valeurRetiree);
                } else {
                    printf("La liste est vide.\n");
                }
                break;

            case 6:
                if (maListe != NULL && !listeVide(maListe)) {
                    int valeurRecherchee;
                    printf("Entrez la valeur a rechercher et retirer : ");
                    scanf("%d", &valeurRecherchee);

                    int* objetRetire = (int*)extraireUnObjet(maListe, &valeurRecherchee);
                    if (objetRetire != NULL) {
                        printf("Objet retire : %d\n", *objetRetire);
                    } else {
                        printf("Objet non trouve dans la liste.\n");
                    }
                } else {
                    printf("La liste est vide.\n");
                }
                break;

            case 7:
                if (maListe != NULL) {
                    listerListe(maListe);
                } else {
                    printf("La liste est vide.\n");
                }
                break;

            case 8:
                if (maListe != NULL && !listeVide(maListe)) {
                    int valeurRecherchee;
                    printf("Entrez la valeur a rechercher : ");
                    scanf("%d", &valeurRecherchee);

                    int* objetTrouve = (int*)chercherUnObjet(maListe, &valeurRecherchee);
                    if (objetTrouve != NULL) {
                        printf("Objet trouve : %d\n", *objetTrouve);
                    } else {
                        printf("Objet non trouve dans la liste.\n");
                    }
                } else {
                    printf("La liste est vide.\n");
                }
                break;

            case 9:
                if (maListe != NULL) {
                    detruireListe(maListe);
                    maListe = NULL;
                    printf("La liste a ete detruite.\n");
                } else {
                    printf("La liste est deja vide.\n");
                }
                break;

            case 10:
                printf("Fin du programme.\n");
                if (maListe != NULL) {
                    detruireListe(maListe);
                }
                break;

            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }

    } while (choix != 10);

    return 0;
}
