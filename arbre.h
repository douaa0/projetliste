#ifndef ARBRE_H
#define ARBRE_H

typedef void Objet;

typedef struct noeud
{
	Objet *reference;
	struct noeud *gauche;
	struct noeud *droite;
} Noeud;

typedef struct
{
	Noeud *racine;
	char *(*afficher)(Objet *);
	int (*comparer)(Objet *, Objet *);
} Arbre;

//       creation des noeuds et des feuilles
Noeud *cNd(Objet *, Noeud *, Noeud *);

//       creation d'un noeud et d'une feuille
Noeud *cF(Objet *);

//       initialisation d'un arbre
void initArbre(Arbre *, Noeud *, char *(*afficher)(Objet *),
                int (*comparer)(Objet *, Objet *));
Arbre *creerArbre(Noeud *, char *(*afficher)(Objet *),
                   int (*comparer)(Objet *, Objet *));

//       parcours préfixé
void prefixe(Noeud *, char *(*afficher)(Objet *));

//       parcours infixé
void infixe(Noeud *, char *(*afficher)(Objet *));

//       parcours postfixé
void postfixe(Noeud *, char *(*afficher)(Objet *));

//       trouver Noeud
Noeud *trouverNoeud(Noeud *, Objet *, int (*comparer)(Objet *, Objet *));

//       hauteur
int hauteur(Noeud *racine);

//       taille de l'arbre
int taille(Noeud *);

//       parcours en largeur
void enLargeur(Noeud *, char *(*afficher)(Objet *));

//       max
int max(int, int);

char *afficherChar(Objet *objet);
char *afficherInt(Objet *objet);
#endif
