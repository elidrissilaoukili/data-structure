
class A {
    public int a;
}

public class Exam1 {
    public static void main(String[] args) {
        A[] objA = new A[10];
        objA[0] = new A();  // Initialize objA[0]
        objA[0].a = 2;
        System.out.println(objA[0].a);  // Output: 2
    }
}