#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FILE 10

typedef int cle;

typedef struct
{
    cle elements[MAX_FILE];
    int tete;
    int queue;
} file;

file initialisation_file()
{
    file f;
    f.tete = 0;
    f.queue = -1;
    return f;
}

bool est_vide(file f)
{
    return (f.queue == 0);
}

cle tete_file(file f)
{
    if (est_vide(f))
    {
        printf("file est vide!\n");
        return -1;
    }
    f.elements[f.tete];
}

cle queue_file(file f)
{
    if (est_vide(f))
    {
        printf("file est vide!\n");
        return -1;
    }
    return f.elements[f.queue];
}

file enfile(file f, cle e)
{
    if (f.queue + 1 == MAX_FILE)
        printf("le file est plien\n");
    f.queue++;
    f.elements[f.queue] = e;
    return f;
}

file defile(file f)
{
    if (est_vide(f))
        printf("file est vide\n");
    else
        for (int i = f.tete; i < f.queue; i++)
            f.elements[i] = f.elements[i + 1];
        f.queue--;
    return f;
}

void afficher_file(file f)
{
    for (int i = f.tete; i <= f.queue; i++)
    {
        printf("%d---", f.elements[i]);
    }
    printf("\n");
}

int main()
{
    file f = initialisation_file();
    f = enfile(f, 1);
    f = enfile(f, 2);
    f = enfile(f, 3);
    f = enfile(f, 4);
    f = enfile(f, 5);
    afficher_file(f);

    f = defile(f);
    afficher_file(f);
}