package oop.Polymorphisme;

public class Main {
    public static void main(String[] args) {
        
        Shape[] shapes = {
            new Circle(5),
            new Rectangle(4, 6)
        };

        for(Shape shape : shapes){
            System.out.println("Area is: " + shape.area());
        }
    }
}
