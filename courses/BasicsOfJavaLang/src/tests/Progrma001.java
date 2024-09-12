package tests;

interface I {
    public int getI();
}

abstract class C implements I {
    int i;

    C(int i) {
        this.i = i;
    }
}

class D extends C implements I {
    D(int x) {
        super(x);
    }

    public int getI() {
        return this.i;
    }
}

public class Progrma001 {
    public static void main(String[] args) {
        D d = new D(1);
        int x = d.getI();
        System.out.println(x);
    }
}
