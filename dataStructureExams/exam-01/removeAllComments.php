<?php

$text = "
#include <stdio.h>
#include <stdlib.h>

// Define the Etudiant structure
typedef struct etudiant {
    char Nom[30];
    float Note;
    int CNE;
} Etudiant;

// Define the Maillon structure (linked list node)
typedef struct maillon {
    Etudiant data;          // Student data
    struct maillon *suivant;   // Pointer to the suivant node
} Maillon;

// Define Liste as a pointer to Maillon
typedef Maillon *Liste;

// Function to insert a student at the end of the list
void insererFin(Liste *L, Etudiant E) {
    Maillon *etudiant = (Maillon *)malloc(sizeof(Maillon)); // Allocate memory for new node
    if (etudiant == NULL) { // Check for memory allocation failure
        printf(\"Memory allocation failed!\n\");
        return;
    }

    etudiant->data = E;     // Set the student data
    etudiant->suivant = NULL;  // The suivant pointer is NULL for the new node (end of list)

    if (*L == NULL) {       // If the list is empty
        *L = etudiant;      // The new node is now the head of the list
    } else {
        Maillon *temp = *L; // Start from the head
        while (temp->suivant != NULL) { // Traverse to the end of the list
            temp = temp->suivant;
        }
        temp->suivant = etudiant; // Link the last node to the new node
    }

    printf(\"\nInserted!\n\");
}

int main() {
    Liste studentList = NULL; // Initialize the list to be empty

    // Example student
    Etudiant student1 = {\"Alice\", 15.5, 123456};
    insererFin(&studentList, student1);

    // Additional code to verify insertion
    Maillon *temp = studentList;
    while (temp != NULL) {
        printf(\"Nom: %s, Note: %.2f, CNE: %d\n\", temp->data.Nom, temp->data.Note, temp->data.CNE);
        temp = temp->suivant;
    }

    return 0;
}

";


// Regular expression to remove single-line and multi-line comments
$pattern = [
    '/\/\/[^\n]*\n/',    // Single-line comments (//)
    '/\/\*[\s\S]*?\*\//' // Multi-line comments (/* ... */)
];

// Replace all matches with an empty string
$newtext = preg_replace($pattern, '', $text);

echo "<pre>";
echo htmlspecialchars($newtext); // Use htmlspecialchars to display the code correctly
echo "</pre>";