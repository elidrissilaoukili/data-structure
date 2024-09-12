public class Exam7 {
    public static void main(String[] args) {
        int a = 2, c = 3, x = 4, y = 5;
        int b = 8, d = 6;
        int a_t;
        a = (x + 5);
        a_t = x + 5;
        System.out.println("1) " + a + " " + a_t);
        a = (c = y) + 2;
        a_t = c = y + 2;
        System.out.println("2) " + a + " " + a_t);
        a = (x = (y + 2));
        a_t = x = y + 2;
        System.out.println("3) " + a + " " + a_t);

        if ((a < b) && (c < d)) {
            System.out.println("4) true");
        } else {
            System.out.println("4) false");
        }

    }
}
