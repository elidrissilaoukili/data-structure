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
} File;

File initialisation_file()
{
    File f;
    f.tete = 0;
    f.queue = -1;
    return f;
}

bool est_vide(File f)
{
    return (f.queue == -1);  // Fixing the condition to check if the queue is empty
}

cle tete_file(File f)
{
    if (est_vide(f))
    {
        printf("File est vide!\n");
        return -1; // Indicate an error state
    }
    return f.elements[f.tete]; // Returning the first element
}

cle queue_file(File f)
{
    if (est_vide(f))
    {
        printf("File est vide!\n");
        return -1; // Indicate an error state
    }
    return f.elements[f.queue]; // Returning the last element
}

File enfile(File f, cle e)
{
    if (f.queue + 1 == MAX_FILE)
    {
        printf("le File est plein\n");
        return f; // Returning the unchanged queue
    }
    f.queue++;
    f.elements[f.queue] = e;
    return f;
}

File defile(File f)
{
    if (est_vide(f))
    {
        printf("File est vide\n");
        return f; // Returning the unchanged queue
    }
    f.tete++;
    if (f.tete > f.queue) {  // Resetting the queue when all elements are dequeued
        f.tete = 0;
        f.queue = -1;
    }
    return f;
}

void afficher_file(File f)
{
    if (est_vide(f)) {
        printf("File est vide!\n");
        return;
    }
    for (int i = f.tete; i <= f.queue; i++)
    {
        printf("%d---", f.elements[i]);
    }
    printf("\n");
}

int main()
{
    File f = initialisation_file();
    f = enfile(f, 1);
    f = enfile(f, 2);
    f = enfile(f, 3);
    f = enfile(f, 4);
    f = enfile(f, 5);
    afficher_file(f);

    f = defile(f);
    afficher_file(f);
    
    return 0;
}
