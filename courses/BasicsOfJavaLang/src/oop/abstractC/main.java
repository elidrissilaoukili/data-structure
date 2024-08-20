package oop.abstractC;

public class main {
    public static void main(String[] args) {
        Vehicle myBike = new Bike();
        Vehicle myCar = new Car();

        myBike.startEngine();
        myCar.startEngine();
    }
}
