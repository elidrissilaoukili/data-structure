package algorithm;

/**
 * UsedFuncs
 */
class UsedFuncs {
    void change(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    void display(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + ", ");
        }
    }
}

class SortMethods {
    UsedFuncs usedfuncs = new UsedFuncs();

    void selectionSort(int arr[]) {
        System.out.println("\nSelection sorting:");
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] > arr[j]) {
                    usedfuncs.change(arr, i, j);
                }
            }
        }
        usedfuncs.display(arr);
    }

    void bubbleSort(int arr[]) {
        System.out.println("\nBubble sorting:");
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    usedfuncs.change(arr, j, j + 1);
                }
            }
        }
        usedfuncs.display(arr);
    }

    void insertionSort(int arr[]) {
        System.err.println("\nInsertion sorting:");
        for (int i = 1; i < arr.length; i++) {
            int min = arr[i];
            int j = i - 1;
            while ((j >= 0) && arr[j] > min) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = min;
        }
        usedfuncs.display(arr);
    }
}

public class Sorts {
    public static void main(String[] args) {
        UsedFuncs usedfuncs = new UsedFuncs();
        SortMethods sm = new SortMethods();

        int arr[] = { 5, 3, 2, 99, 1 };

        int[] arrForSelection = arr.clone();
        int[] arrForBubble = arr.clone();
        int[] arrForInsertion = arr.clone();

        sm.selectionSort(arrForSelection);
        sm.bubbleSort(arrForBubble);
        sm.insertionSort(arrForInsertion);
    }
}
