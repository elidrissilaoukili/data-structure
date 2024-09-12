<?php
// Création d'un objet générique en utilisant stdClass
$personne = new stdClass();

// Ajout de propriétés à l'objet
$personne->nom = "Mohammed";
$personne->prenom = "Elidrissi";
$personne->age = 30;

// Affichage des propriétés de l'objet
echo "Nom: " . $personne->nom . "<br>";
echo "Prénom: " . $personne->prenom . "<br>";
echo "Âge: " . $personne->age . "<br>";

// Création d'un objet avec une méthode en utilisant une fonction anonyme
$voiture = new stdClass();
$voiture->marque = "Toyota";
$voiture->modele = "Corolla";
$voiture->afficherDetails = function() use ($voiture) {
    echo "Marque: " . $voiture->marque . "<br>";
    echo "Modèle: " . $voiture->modele . "<br>";
};

// Appel de la méthode
$afficherDetails = $voiture->afficherDetails;
$afficherDetails();


