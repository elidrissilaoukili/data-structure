class Suite {
    static int U0 = 1;
    static int U1 = 2;
    static int Un;
    int n;

    public Suite(int n) {
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

public class Suite1 {
    public static void main(String[] args) {
        Suite s = new Suite(10);
        s.print_sequence();
    }
}