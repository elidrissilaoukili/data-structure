public class Exam4 {

    public static void main(String[] args) {

        double e1, e2, e3, e3_v, e4, e4_v, e5, e6;
        int a = 2, b = 3, c = 4, d = 5;

        e1 = (a + b) - (2 * c);
        e2 = (a + 3) * (d % b);
        e3 = (-d) % (-(b+c));
        e3_v = -d % -(b+c);
        e4 = (d/b) % (-a);
        e4_v = d/b % -a;


        System.out.println(e1);
        System.out.println(e2);
        System.out.println(e3 + " " + e3_v);
        System.out.println(e4 + " " + e4_v);
    }
}
