#include <stdio.h>
#include <stdlib.h> // Pour malloc, free
#include <limits.h> // Pour INT_MIN

// Définition d'un noeud de la pile
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Définition de la pile
typedef struct {
    Node* top;
} Pile;

// Fonction pour initialiser la pile
void initPile(Pile* p) {
    p->top = NULL;
}

// Fonction pour empiler un élément
void empiler(Pile* p, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        // Gestion de l'erreur d'allocation
        perror("Erreur d'allocation mémoire");
        exit(EXIT_FAILURE);
    }
    newNode->data = val;
    newNode->next = p->top;
    p->top = newNode;
}

// Fonction pour dépiler un élément
int depiler(Pile* p) {
    if (p->top == NULL) {
        // La pile est vide, donc gérer l'erreur
        perror("La pile est vide, impossible de dépiler");
        return INT_MIN; // Utiliser INT_MIN comme valeur d'erreur
    }
    
    Node* temp = p->top;
    int val = temp->data;
    p->top = temp->next;
    free(temp);
    return val;
}

// Fonction pour vérifier si la pile est vide
int estVide(Pile* p) {
    return p->top == NULL;
}

// Fonction pour obtenir la valeur maximale de la pile sans la modifier
int MaxPile(Pile p) {
    if (estVide(&p)) {
        // La pile est vide, donc retourner une valeur spécifique ou gérer l'erreur
        return INT_MIN; // Utiliser INT_MIN comme valeur d'erreur
    }
    
    int max = p.top->data;
    Node* current = p.top;
    while (current != NULL) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    return max;
}

// Fonction pour libérer la mémoire de la pile
void viderPile(Pile* p) {
    Node* current = p->top;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    p->top = NULL;
}

// Exemple d'utilisation
int main() {
    Pile maPile;
    initPile(&maPile);
    
    empiler(&maPile, 5);
    empiler(&maPile, 2);
    empiler(&maPile, 9);
    empiler(&maPile, 3);
    
    printf("La valeur maximale de la pile est : %d\n", MaxPile(maPile));
    
    printf("Depile : %d\n", depiler(&maPile));
    printf("Depile : %d\n", depiler(&maPile));
    
    printf("La valeur maximale apres depilement est : %d\n", MaxPile(maPile));
    
    viderPile(&maPile);
    
    return 0;
}
