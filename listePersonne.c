#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define faux 0
#define vrai 1
#include "personne.h"
#include "liste.h"

int menu () {
printf ("\n\nGESTION D'UNE LISTE DE PERSONNES\n\n");
printf ("0 - Fin\n");
printf ("1 - Insertion en tête de liste\n");
printf ("2 - Insertion en fin de liste\n");
printf ("3 - Retrait en tête de liste\n");
printf ("4 - Retrait en fin de liste\n");
printf ("5 - Retrait d'un élément à partir de son nom\n");
printf ("6 - Parcours de la liste\n");
printf ("7 - Recherche d'un élément à partir de son nom\n");
printf ("8 - Destruction de la liste\n");
printf ("\n");
printf ("Votre choix ? ");
int cod; scanf ("%d", &cod);
printf ("\n");
return cod;
}

int main()
{
	ch15 nom, prenom;
	Personne *nouveau;
	Personne *extrait;
	Personne *cherche;
	Personne *pp;
	Personne *personne_cherche;
	Liste *lp = creerListe(0, ecrirePersonne, comparerPersonne);
	booleen fini = faux;
	while (!fini)
	{
		switch (menu())
		{
		case 0:
			fini = vrai;
			break;
		case 1:
			printf("Nom de la personne a creer ? ");
			scanf("%s", nom);
			printf("Prenom de la personne a creer ? ");
			scanf("%s", prenom);
			nouveau = creerPersonne(nom, prenom);
			insererEnTeteDeListe(lp, nouveau);
			break;
		case 2:
			printf("Nom de la personne a creer ? ");
			scanf("%s", nom);
			printf("Prenom de la personne a creer ? ");
			scanf("%s", prenom);
			nouveau = creerPersonne(nom, prenom);
			insererEnFinDeListe(lp, nouveau);
			break;
		case 3:
			extrait = (Personne *)extraireEnTeteDeListe(lp);
			if (extrait != NULL)
			{
				printf("Element %s %s extrait en tete de liste.", extrait->nom, extrait->prenom);
			}
			else
			{
				printf("Liste vide.");
			}
			break;
		case 4:
			extrait = (Personne *)extraireEnFinDeListe(lp);
			if (extrait != NULL)
			{
				printf("Element %s %s extrait en fin de liste.", extrait->nom, extrait->prenom);
			}
			else
			{
				printf("Liste vide.");
			}
			break;
		case 5:
			printf("Nom de la personne à retirer ? ");
			scanf("%s", nom);
			cherche = creerPersonne(nom, "?");
			pp = (Personne *)chercherUnObjet(lp, cherche);
			if (extraireUnObjet(lp, pp))
			{
				printf("Element %s %s extrait de la liste.", pp->nom, pp->prenom);
			}
			break;
		case 6:
			listerListe(lp);

			break;
		case 7:
			printf("Saisir le nom a chercher : ");
			scanf("%s", nom);
			Personne *cherche = creerPersonne(nom, "?");
			Personne *pp = (Personne *)chercherUnObjet(lp, cherche);
			if (pp != NULL)
			{
				printf("%s  trouvé dans la liste!", nom);
			}
			else
			{
				printf("Element introuvable");
			}
			break;
		case 8:
			detruireListe(lp);
			break;
		}
	}
	return 0;
}
