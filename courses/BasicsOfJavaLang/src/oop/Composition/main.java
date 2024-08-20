package oop.Composition;

public class main {
    public static void main(String[] args) {
        Library library = new Library();

        library.addBook(new Book("Python", "elidrissi"));
        library.addBook(new Book("PHP", "laoukili"));
        library.displayBooks();
    }
}
