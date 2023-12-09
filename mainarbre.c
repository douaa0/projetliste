#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "liste.h"

int menu () {
printf ("\n\n GESTION DARBRES \n\n");
printf ("\n\n ARBRES BINAIRES \n\n");
printf (" 0 - Fin du programme\n");
printf ("\n");
printf (" 1 - Creation de larbre genealogique\n");
printf (" 2 - Creation de larbre de lexpression arithmetique\n");
printf ("\n");
printf (" 3 - Parcours prefixe\n");
printf (" 4 - Parcours infixe\n");
printf (" 5 - Parcours postfixe\n");
printf ("\n");
printf ("Votre choix ? ");
int cod; scanf ("%d", &cod); getchar();
printf ("\n");
return cod;
}

int main()
{
	Arbre *A2;
	Arbre *A1;
	int stop = 1;
	Noeud *racine = cNd((char *)"Samir",
	cNd((char *)"Kamal",
	cNd((char *)"Yassine",
	NULL,
	cNd((char *)"Hind", NULL,
	cF((char *)"Yasmine"))),
	cNd((char *)"Sarah",
	cF((char *)"Karim"),
	NULL)),
	NULL);
	Noeud *racine1 = cNd((char *)"-", cNd((char *)"*", cNd((char *)"+",
                    cF((char *)"a"), cF((char *)"b")), cNd((char *)"-",
                    cF((char *)"c"), cF((char *)"d"))), cF((char *)"e"));
	while (stop)
	{
		int cod = menu();
		switch (cod)
		{
		case 0:
			stop = 0;
			break;
		case 1:

			A1 = creerArbre(racine, afficherChar, comparerInt);
			break;
		case 2:

			A2 = creerArbre(racine1, afficherChar, comparerInt);
			break;
		case 3:
			printf("Arbre genealogique : ");
			prefixe(racine, afficherChar);
			printf("\nArbre arithmetique : ");
			prefixe(racine1, afficherChar);
			break;
		case 4:
			printf("Arbre genealogique : ");
			infixe(racine, afficherChar);
			printf("\nArbre arithmetique : ");
			infixe(racine1, afficherChar);
			break;
		case 5:
			printf("Arbre genealogique : ");
			postfixe(racine, afficherChar);
			printf("\nArbre arithmetique : ");
			postfixe(racine1, afficherChar);
			break;
		case 6:
		{
			printf("Trouver Noeud dans Arbre genealogique\n\n");
			printf("Saisir le Noeud : ");
			char trouve[20];
			scanf("%s", trouve);
			if (trouverNoeud(racine, trouve, comparerInt) != NULL)
			{
				printf("Le Noeud %s existe.",
                    afficher(trouverNoeud(racine, trouve, comparerInt)->reference));
			}
			else
			{
				printf("Le Noeud est introuvable.");
			}
			printf("\nTrouver Noeud dans Arbre arithmetique\n\n");
			printf("Saisir le Noeud : ");
			char trouve1[20];
			scanf("%s", trouve1);

			if (trouverNoeud(racine1, trouve1, comparerInt) != NULL)
			{
				printf("Le Noeud %s existe.",
                   afficher(trouverNoeud(racine1, trouve1, comparerInt)->reference));
			}
			else
			{
				printf("Le Noeud est introuvable.");
			}
			break;
		}
		case 7:
			printf("Taille Arbre genealogique : ");
			printf("%d", taille(racine));
			printf("\nTaille Arbre arithmetique : ");
			printf("%d", taille(racine1));
			break;
		case 8:
			printf("Hauteur Arbre genealogique : ");
			printf("%d", hauteur(racine));
			printf("\nHauteur Arbre arithmetique : ");
			printf("%d", hauteur(racine1));
			break;
		case 9:
			printf("Arbre genealogique : ");
			enLargeur(racine, afficherChar);
			printf("\nArbre arithmetique : ");
			enLargeur(racine1, afficherChar);
			break;
		}
	}
	return 0;
}

