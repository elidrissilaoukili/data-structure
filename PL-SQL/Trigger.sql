-- Création du trigger
CREATE OR REPLACE TRIGGER update_places_disponibles
AFTER INSERT OR DELETE ON Etudiant
FOR EACH ROW
BEGIN
    -- Lors d'une insertion dans la table Etudiant
    IF INSERTING THEN
        -- Met à jour la table Filière pour réduire le nombre de places disponibles
        UPDATE Filière
        SET places_disponibles = places_disponibles - 1
        WHERE id_filiere = :NEW.id_filiere;
        
        -- Vérifie si le nombre de places disponibles est devenu négatif et corrige
        IF (SELECT places_disponibles FROM Filière WHERE id_filiere = :NEW.id_filiere) < 0 THEN
            RAISE_APPLICATION_ERROR(-20001, 'Le nombre de places disponibles est insuffisant pour la filière ' || :NEW.id_filiere);
        END IF;

    -- Lors d'une suppression dans la table Etudiant
    ELSIF DELETING THEN
        -- Met à jour la table Filière pour augmenter le nombre de places disponibles
        UPDATE Filière
        SET places_disponibles = places_disponibles + 1
        WHERE id_filiere = :OLD.id_filiere;

        -- Vérifie si le nombre de places disponibles est devenu négatif et corrige
        IF (SELECT places_disponibles FROM Filière WHERE id_filiere = :OLD.id_filiere) < 0 THEN
            RAISE_APPLICATION_ERROR(-20001, 'Le nombre de places disponibles est insuffisant pour la filière ' || :OLD.id_filiere);
        END IF;
    END IF;
END;
/
