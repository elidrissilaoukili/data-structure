package oop.Polymorphisme;

// elidrissilaoukili.netlify.app
// elidrissi laoukili

// Polymorphism requires a superclass reference (Animal) to point to a subclass object.
class Animal {
	void makeSound(){
		System.out.println("hi I am animal");
	}

	void eat(){
		System.out.println("Cat is eating");
	}
}

class Cat extends Animal {
	@Override
	void makeSound(){
		System.out.println("hi I am a cat");
	}
}

class Kitty extends Cat {
	@Override
	void makeSound(){
		System.out.println("hi I am a Kitty");
	}

	@Override
	void eat(){
		System.out.println("Kitty is eating");
	}
}

public class Polymorphisme {
	public static void main(String [] args) {
		Animal cat = new Cat(); // Polymorphisme Create object with Animal class
		cat.makeSound();

		Animal kitty = new Kitty();
		kitty.eat();
	}
} 
