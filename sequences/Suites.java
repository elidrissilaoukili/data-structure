class Suite1 {
    static int U0 = 1;
    static int U1 = 2;
    static int Un;
    int n;

    public Suite1(int n) {
        this.n = n;
    }

    void print_sequence() {
        for (int i = 2; i <= n; i++) {
            Un = U1 + 2 * U0;
            U0 = U1;
            U1 = Un; 

            System.out.println("U " + i + " = " + Un);
        }
    }
}

class Suite2 {
    private int X0;  
    private int Xn;  

    public Suite2(int X0) {  
        this.X0 = X0; 
        Xn = X0; 
    }  

    void print_sequence() {
        System.out.println("X0 = " + X0);
        while (X0 != 1) {
            if (X0 % 2 == 0) {
                Xn = X0 / 2;
                X0 = Xn;
            } else {
                Xn = 3* X0 + 1;
                X0 = Xn;
            }
            System.out.println("Xn = " + Xn);
        }
    }
}


public class Suites {
    public static void main(String[] args) {
        Suite1 s = new Suite1(10);
        // s.print_sequence();

        Suite2 s2 = new Suite2(5);
        s2.print_sequence();
    }
}