package oop.encapsulation;

// elidrissilaoukili.netlify.app
// elidrissi laoukili

class Person {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        if (age > 0)
            this.age = age;
    }
}

public class Encapsulation {
    public static void main(String[] args) {
        Person person = new Person("Elidrissi", 23);
        System.out.println("Name: " + person.getName() + ", Age: " + person.getAge());
    }
}
