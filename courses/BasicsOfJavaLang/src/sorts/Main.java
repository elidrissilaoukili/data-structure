
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Sorts quicksort = new Sorts();
        Random rand = new Random();
        int[] numbers = new int[10];

        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = rand.nextInt(100);
        }

        System.out.println("Before sorting:");
        quicksort.printArray(numbers);

        quicksort.quickSort(numbers, 0, numbers.length - 1);

        System.out.println("Before sorting:");
        quicksort.printArray(numbers);
    }
}