package oop.inheritance;

public class main {
    public static void main(String[] args){
        Animal animals = new Animal();
        Animal myDog = new Dog();
        Animal myCat = new Cat();
        animals.makeSound();
        myDog.makeSound();
        myCat.makeSound();
    }
}
