// Define an interface
interface Animal {
    // Abstract method (does not have a body)
    void makeSound();
    
    // Default method (with implementation)
    default void sleep() {
        System.out.println("The animal is sleeping.");
    }
}

// Implement the interface in a class
class Dog implements Animal {
    // Implement the abstract method
    public void makeSound() {
        System.out.println("Woof!");
    }
}

// Main class to test the interface implementation
public class Main {
    public static void main(String[] args) {
        Dog myDog = new Dog();
        myDog.makeSound(); // Output: Woof!
        myDog.sleep();     // Output: The animal is sleeping.
    }
}
