#include <stdio.h>
#include <stdlib.h>

typedef struct noeud_s
{
    int valuer;
    struct noeud_s *gauche; // Correction de "gouche" à "gauche"
    struct noeud_s *droit;
} *noeud_t;

typedef noeud_t arbre_t;

arbre_t cree_node(int valuer){
    arbre_t a = (arbre_t)malloc(sizeof(struct noeud_s));
    a->valuer = valuer;
    a->gauche = NULL;
    a->droit = NULL;
    return a;
}

arbre_t insert_arbre(arbre_t a, int valuer)
{
    if (a == NULL){
        return cree_node(valuer);
    }
    if (valuer < a->valuer)
        a->gauche = insert_arbre(a->gauche, valuer);
    if (valuer > a->valuer)
        a->droit = insert_arbre(a->droit, valuer);

    return a;    
}

void detruire_arbre(arbre_t a)
{
    if (a == NULL)
        return; 
    detruire_arbre(a->gauche);
    detruire_arbre(a->droit);
    free(a);
}


void printtabs(int numbtabs)
{
    for (int i = 0; i < numbtabs; i++)
        printf("\t");
}

void printtree(arbre_t a, int level)
{
    if (a == NULL)
    {
        printtabs(level);
        printf("---<empty>---\n");
        return;
    }
    printtabs(level);
    printf("value = %d\n", a->valuer);
    printtabs(level);
    
    printf("left\n");
    printtree(a->gauche, level + 1);
    printtabs(level);

    printf("right\n");
    printtree(a->droit, level + 1);
    printtabs(level);
    
    printf("DONE!\n");
}
int main()
{
    arbre_t a = NULL;
    int arr[] = {50, 65, 2, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
        a = insert_arbre(a, arr[i]);

    printf("\nArbre avant:\n");
    printtree(a, 0);

    printf("\nArbre apre:\n");
    detruire_arbre(a);
    printtree(a, 0);
}
