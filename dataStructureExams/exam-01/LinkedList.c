#include <stdio.h>
#include <stdlib.h>

typedef struct etudiant
{
    char Nom[30];
    float Note;
    int CNE;
} Etudiant;

typedef struct maillon
{
    Etudiant data;
    struct maillon *suivant;
} Maillon;

typedef Maillon *Liste;

void insererFin(Liste *L, Etudiant E)
{
    Maillon *etudiant = (Maillon *)malloc(sizeof(Maillon));
    etudiant->data = E;
    etudiant->suivant = NULL;
    if (*L == NULL)
        *L = etudiant;
    else
    {
        Maillon *temp = *L;
        while (temp->suivant != NULL)
            temp = temp->suivant;
        temp->suivant = etudiant;
    }

    printf("Inserted!\n");
}

Maillon *rechercheMajorant(Liste L)
{
    Maillon *major = NULL;
    float note = 0;

    Maillon *temp = L;
    while (temp != NULL)
    {
        if (temp->data.Note > note)
        {
            note = temp->data.Note;
            major = temp;
        }
        temp = temp->suivant;
    }
    return major;
}

float MoyennePromotion(Liste L)
{
    int count = 0;
    float moy = 0;
    Maillon *temp = L;
    while (temp != NULL)
    {
        moy += temp->data.Note;
        count += 1;
        temp = temp->suivant;
    }
    return moy / count;
}

// void ConstruireListe(Liste L, Liste *R)
// {
//     Maillon *temp = L;
//     while (temp != NULL)
//     {
//         if (temp->data.Note < 10)
//             insererDebut(R, temp->data);
//         if (temp->data.Note >= 10)
//             insererFin(R, temp->data);

//         temp = temp->suivant;
//     }
// }

void suppremeNonValid(Liste *L)
{
    Maillon *temp = *L, *temp2;
    while (*L != NULL && (*L)->data.Note < 10)
    {
        temp = *L;
        *L = (*L)->suivant;
        free(temp);
    }

    temp = *L;
    while (temp != NULL && temp->suivant != NULL)
    {
        if (temp->suivant->data.Note < 10)
        {
            temp2 = temp->suivant;
            temp->suivant = temp2->suivant;
            free(temp2);
        }
        temp = temp->suivant;
    }
}

void SupprimerNonValide(Liste *L)
{
    Maillon *m, *ptr, *pred;
    while (*L != NULL && (*L)->data.Note < 10)
    {
        ptr = *L;
        *L = (*L)->suivant;
        free(ptr);
    }

    if (*L != NULL)
    {
        pred = *L;
        ptr = (*L)->suivant;
        while (ptr != NULL)
        {
            if (ptr->data.Note < 10)
            {
                m = ptr;
                pred->suivant = ptr->suivant;
                ptr = ptr->suivant;
                free(m);
            }
            else
            {
                pred = ptr;
                ptr = ptr->suivant;
            }
        }
    }
}
int main()
{
    Liste studentList = NULL; // Initialize the list to be empty

    // Example students
    Etudiant student1 = {"Alice", 15.5, 123456};
    Etudiant student2 = {"Bob", 18.2, 789012};
    Etudiant student5 = {"BOOOk", 4.2, 87686};
    Etudiant student3 = {"Charlie", 14.8, 345678};
    Etudiant student4 = {"Khlaid", 9.8, 5245454};

    insererFin(&studentList, student1);
    insererFin(&studentList, student2);
    insererFin(&studentList, student5);
    insererFin(&studentList, student3);
    insererFin(&studentList, student4);

    // Perform deletion of students with Note < 10
    SupprimerNonValide(&studentList);

    // Print remaining students' notes
    Maillon *current = studentList;
    while (current != NULL)
    {
        printf("%.2f\n", current->data.Note);
        current = current->suivant;
    }

    return 0;
}
