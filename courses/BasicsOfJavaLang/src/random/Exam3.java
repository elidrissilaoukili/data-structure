
import java.util.ArrayList;

public class Exam3 {
    public static void main(String[] args) {
        ArrayList<Double> notes = new ArrayList<>();
        double[] notesT = { 12.0, 16.0, 13.0, 10.5, 11.5, 17.5 };

        notes.add(12.0);
        notes.add(16.0);
        notes.add(13.0);
        notes.add(10.5);
        notes.add(11.5);
        notes.add(17.5);

        double moy;
        int sum = 0;
        for (Double note : notes) {
            sum += note;
        }

        int nstd = notes.size();
        moy = sum / nstd;

        Double max = notes.get(0);
        for (int i = 0; i < nstd; i++) {
            if (max < notes.get(i)) {
                max = notes.get(i);
            }
        }
        System.out.println(max);

        Double min = notes.get(0);
        for (int i = 0; i < nstd; i++) {
            if (min > notes.get(i)) {
                min = notes.get(i);
            }
        }
        System.out.println(min);

        for (int i = 0; i < notesT.length - 1; i++) {
            for (int j = i + 1; j < notesT.length; j++) {
                if (notesT[i] > notesT[j]) {
                    double temp = notesT[i];
                    notesT[i] = notesT[j];
                    notesT[j] = temp;
                }
            }
        }

        for (int i = 0; i < notesT.length; i++) {
            System.out.print(notesT[i] + " ");
        }
    }
}
