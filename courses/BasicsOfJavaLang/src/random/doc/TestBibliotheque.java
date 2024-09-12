package doc;

import java.util.ArrayList;

abstract class Document {
    protected static int nextNum = 1;
    protected int num;
    protected String auteur;
    protected String titre;

    public Document(String auteur, String titre) {
        this.num = nextNum++;
        this.auteur = auteur;
        this.titre = titre;
    }

    public abstract String toString();
}

class Livre extends Document {
    private int nbrPage;

    public Livre(String auteur, String titre, int nbrPage) {
        super(auteur, titre);
        this.nbrPage = nbrPage;
    }

    @Override
    public String toString() {
        return "Livre [Numéro: " + num + ", Auteur: " + auteur + ", Titre: " + titre + ", Nombre de pages: " + nbrPage
                + "]";
    }
}

class Roman extends Document {
    private double prix;

    public Roman(String auteur, String titre, double prix) {
        super(auteur, titre);
        this.prix = prix;
    }

    @Override
    public String toString() {
        return "Roman [Numéro: " + num + ", Auteur: " + auteur + ", Titre: " + titre + ", Prix: " + prix + "]";
    }
}

class PlusDePlaceException extends Exception {
    public PlusDePlaceException(String message) {
        super(message);
    }
}

class Bibliotheque {
    private String nom;
    private int capacite;
    private ArrayList<Document> documents;

    public Bibliotheque(String nom, int capacite) {
        this.nom = nom;
        this.capacite = capacite;
        this.documents = new ArrayList<>();
    }

    public void addDocument(Document doc) throws PlusDePlaceException {
        if (documents.size() >= capacite) {
            throw new PlusDePlaceException("Plus de place dans la bibliothèque !");
        }
        documents.add(doc);
    }

    public void findDocuments() {
        for (Document doc : documents) {
            System.out.println(doc);
        }
    }

    public void findDocumentByTitre(String titre) {
        for (Document doc : documents) {
            if (doc.titre.equalsIgnoreCase(titre)) {
                System.out.println(doc);
                return;
            }
        }
        System.out.println("Document avec le titre " + titre + " non trouvé.");
    }
}

public class TestBibliotheque {
    public static void main(String[] args) {
        try {
            // a. Créer Deux livres
            Livre livre1 = new Livre("Auteur1", "Titre1", 150);
            Livre livre2 = new Livre("Auteur2", "Titre2", 300);

            // b. Créer Deux romans
            Roman roman1 = new Roman("Auteur3", "Titre3", 45.99);
            Roman roman2 = new Roman("Auteur4", "Titre4", 60.50);

            // c. Créer Une bibliothèque
            Bibliotheque biblio = new Bibliotheque("Bibliothèque Centrale", 4);

            // d. Ajouter les quatre documents à la bibliothèque
            biblio.addDocument(livre1);
            biblio.addDocument(livre2);
            biblio.addDocument(roman1);
            biblio.addDocument(roman2);

            // e. Afficher la liste des documents de la bibliothèque
            biblio.findDocuments();

        } catch (PlusDePlaceException e) {
            System.out.println(e.getMessage());
        }
    }
}
