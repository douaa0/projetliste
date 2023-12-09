#include <stdio.h>
#include <stdlib.h>
#include "personne.h"
#include "pile.h"

int main() {
    printf("GESTION Dune Pile de personne \n");
    Pile* p;
    p=creerPile(0,ecrirePersonne,comparerPersonne);
    int i=1;
    ch15 nom,prenom;
    Personne *Pr;
    while(i<4)
    {
        printf("Donner le nom de %d personne \n",i);
        scanf("%s",nom);
        printf("Donner le prenom de %d personne\n",i);
        scanf("%s",prenom);
        Pr= creerPersonne(nom,prenom);
        empiler(p,Pr);
        i++;
    }
    printf("\nles elements de la pile sont:\n");
    listerPile(p);
    Pr=depiler(p);
    printf("\nla dernier personnes inserer est :\n%s\t%s",Pr->nom,Pr->prenom);
    printf("\nles nouvelles elements de la pile sont:\n");
    listerPile(p);
    printf("\nla destruction de la pile");
    detruirePile(p);
    return 0;
}
