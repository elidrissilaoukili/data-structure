#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max_PILE 10
typedef int cle;
typedef struct
{
    cle elements[Max_PILE];
    int sommet;
} pile;

pile initialisation_pile()
{
    pile p;
    p.sommet = -1;
    return p;
}

bool est_vide(pile p)
{
    return (p.sommet == -1);
}

int sommet(pile p)
{
    if (p.sommet == -1)
    {
        printf("pile est vide!\n");
        return -1;
    }
    return p.elements[p.sommet];
}

pile empile(pile p, cle e)
{
    if (p.sommet + 1 == Max_PILE)
        printf("La pile de trop-plein\n");
    p.sommet++;
    p.elements[p.sommet] = e;
    return p;
}

pile depile(pile p)
{
    if (p.sommet == -1)
        printf("underflow, le pile is empty!\n");
    p.sommet--;
    return p;
}

void affiche_pile(pile p)
{
    if (p.sommet == -1)
    {
        printf("pile contient 0 element\n");
        return;
    }
    for (int i = p.sommet; i >= 0 ; i--)
    {
        printf("----------------\n");
        printf("\t%d\n", p.elements[i]);
    }
}

int main()
{
    pile p = initialisation_pile();
    char cont;
    int choice, element;
    do
    {
        printf("1- empile.\n");
        printf("2- depile.\n");
        printf("3- affiche.\n");
        printf("4- Sommet.\n");
        printf("Entre votre choise:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Entre element: ");
            scanf("%d", &element);
            p = empile(p, element);
            break;
        case 2:
            p = depile(p);
            break;
        case 3:
            affiche_pile(p);
            break;
        case 4:
            printf("Sommet est %d\n", sommet(p));
            break;
        default:
            printf("please chooce a numbern");
            break;
        }
        // printf("Voulez-vous continuer? (y/n): ");
        // scanf(" %c", &cont);
    } while (1);
}
