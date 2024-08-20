package oop.BasicDesignClass;

public class Person {
    private String name; 
    private int age;
    private String addresse;  
    
    public Person(String name, int age, String addresse){
        this.name = name;
        this.age = age;
        this.addresse = addresse;
    }

    public void setName(String name){
        this.name = name;
    }
    public String getName(){
        return name;
    }

    public void setAddresse(String addresse){
        this.addresse = addresse;
    }
    public String getAddresse(){
        return addresse;
    }

    public void setAge(int age){
        this.age = age;
    }
    public int getAge(){
        return age;
    }

    public void display(){
        System.out.println("Name: " + getName());
        System.out.println("Age: " + getAge());
        System.out.println("Addresse: " + getAddresse());
    }
}
