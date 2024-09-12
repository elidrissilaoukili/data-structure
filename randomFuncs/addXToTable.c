#include <stdio.h>

void affiche(int *tab, int taille) {
    printf("\n");
    for (int i = 0; i < taille; i++)
        printf("%d, ", tab[i]);
    printf("\n");
}

int inserer(int *tab, int *taille, int maxtaille, int valeur) {
    if (*taille >= maxtaille) {
        return -1;
    }

    int i;
    for (i = 0; i < *taille; i++) 
        if (tab[i] < valeur) 
            break;

    // for (int j = *taille; j > i; j--) 
    //     tab[j] = tab[j - 1];

    for (int j = *taille; j > i; j--) 
        tab[j] = tab[j - 1];

    *(tab + i) = valeur;
    (*taille)++;

    return i;
}

int main() {
    int tab[10] = {70, 60, 50, 40, 30, 20, 10}; // Adjust size as needed
    int taille = 7;  // Current size of the array
    int maxtaille = 10; // Maximum size of the array
    int arr[] = {45, 65};

    affiche(tab, taille);

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        int index = inserer(tab, &taille, maxtaille, arr[i]);
        printf("%d | ", index);
    }

    affiche(tab, taille);

    return 0;
}
