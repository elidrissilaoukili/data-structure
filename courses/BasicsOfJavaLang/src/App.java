class MostUsedFuncs {
    void msg(String message){
        System.out.println(message); 
    }
}

public class App {
    public static void main(String[] args) throws Exception {
        MostUsedFuncs f = new MostUsedFuncs();

        String s1  = "JAVA";
        String s2  = "java";

        f.msg(s1 + " compared to " + s2 + " = " + s1.compareTo(s2));
    }
}
