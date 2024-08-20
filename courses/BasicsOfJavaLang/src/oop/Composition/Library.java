package oop.Composition;

import java.util.ArrayList;
import java.util.List;

public class Library {
    private List<Book> books = new ArrayList<>();

    public void addBook(Book book){
        books.add(book);
    }

    public void displayBooks(){
        for (Book book : books) {
            System.out.println(book);
        }
    }
}
