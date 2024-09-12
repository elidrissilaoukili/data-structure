
class Sorts {

    public void printArray(int[] numbers) {
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(numbers[i] + " ");
        }
        System.out.println();
    }

    public void quickSort(int[] array, int lowIndex, int highIndex) {

        if (lowIndex >= highIndex) {
            return;
        }

        int pivot = array[highIndex];

        int leftP = lowIndex;
        int rightP = highIndex;

        while (leftP < rightP) {
            while (array[leftP] <= pivot && leftP < rightP) {
                leftP++;
            }

            while (array[rightP] >= pivot && leftP < rightP) {
                rightP--;
            }

            swap(array, leftP, rightP);
        }
        swap(array, leftP, highIndex);

        quickSort(array, lowIndex, leftP - 1);
        quickSort(array, leftP + 1, highIndex);
    }

    private void swap(int[] array, int index1, int index2) {
        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }
}