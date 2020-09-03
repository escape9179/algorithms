public class MergeSort {
    public static void main(String[] args) {
        new MergeSort();
    }

    MergeSort() {
        int[] array = mergeSort(new int[]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
        for (int i = 0; i < array.length; i++)
            System.out.println(array[i]);
    }

    public int[] mergeSort(int[] array) {
        if (array.length <= 1) {
            return array;
        }
        int[] arrayOne = new int[array.length / 2];
        int[] arrayTwo = new int[array.length - arrayOne.length];
        System.arraycopy(array, 0, arrayOne, 0, arrayOne.length);
        System.arraycopy(array, arrayOne.length, arrayTwo, 0, arrayTwo.length);
        int[] sortedArrayOne = mergeSort(arrayOne);
        int[] sortedArrayTwo = mergeSort(arrayTwo);
        return merge(sortedArrayOne, sortedArrayTwo);
    }

    public int[] merge(int[] arrayOne, int[] arrayTwo) {
        int i = 0;
        int j = 0;
        int[] finalArray = new int[arrayOne.length + arrayTwo.length];
        for (int k = 0; k < finalArray.length; k++) {
            if (arrayOne[i] < arrayTwo[j]) {
                finalArray[k] = arrayOne[i];
                i += 1;
                if (i > arrayOne.length - 1) {
                    System.arraycopy(arrayTwo, j, finalArray, k + 1, arrayTwo.length - j);
                }
            } else {
                finalArray[k] = arrayTwo[j];
                j += 1;
                if (j > arrayTwo.length - 1) {
                    System.arraycopy(arrayOne, i, finalArray, k + 1, arrayOne.length - i);
                    return finalArray;
                }
            }
        }
        return finalArray;
    }
}
