#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int cle;

typedef struct Node {
    cle valeur;
    struct Node* suivant;
} node;

node* debut = NULL;

// Function to initialize a new node with a given value
node* initialisation_pile(cle v) {
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->valeur = v;
    newnode->suivant = NULL;
    return newnode;
}

// Function to check if the stack is empty
bool est_vide() {
    return (debut == NULL);
}

// Function to push a value onto the stack
void empile(cle v) {
    node* newnode = initialisation_pile(v);
    newnode->suivant = debut;  // Link the new node to the current top
    debut = newnode;           // Update the top to the new node
}

// Function to pop a value from the stack
cle depile() {
    if (est_vide()) {
        printf("Stack underflow, the stack is empty!\n");
        return -1;
    }
    node* temp = debut;
    cle poped_cle = debut->valeur;
    debut = debut->suivant;  // Move the top to the next node
    free(temp);              // Free the memory of the old top node
    return poped_cle;
}

// Function to display the stack
void affiche_pile() {
    if (est_vide()) {
        printf("Stack is empty!\n");
        return;
    }
    node* temp = debut;
    while (temp != NULL) {
        printf("%d -> ", temp->valeur);
        temp = temp->suivant;
    }
    printf("NULL\n");
}

// Function to return the top value of the stack
cle sommet() {
    if (est_vide()) {
        printf("Stack is empty!\n");
        return -1;
    }
    return debut->valeur;
}

int main() {
    char cont;
    int choice, element;
    do {
        printf("-----------------------\n");
        printf("1- empile.\n");
        printf("2- depile.\n");
        printf("3- affiche.\n");
        printf("4- Sommet.\n");
        printf("Entre votre choix: ");
        scanf("%d", &choice);
        printf("-----------------------\n");
        switch (choice) {
        case 1:
            printf("Entre element: ");
            scanf("%d", &element);
            empile(element);
            break;
        case 2:
            printf("Le nombre popped est %d\n", depile());
            break;
        case 3:
            affiche_pile();
            break;
        case 4:
            printf("Sommet est %d\n", sommet());
            break;
        default:
            printf("Please choose a valid number.\n");
            break;
        }
        // printf("Voulez-vous continuer? (y/n): ");
        // scanf(" %c", &cont);
    } while (1);

    return 0;
}
