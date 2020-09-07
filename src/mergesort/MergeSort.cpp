#include <iostream>

void arrayCopy(int *source, int indexOne, int *dest, int indexTwo, int length) {
    for (int i = 0; i < length; i++) {
        dest[indexTwo + i] = source[i + indexOne];
    }
}

int *merge(int *arrayOne, int *arrayTwo, int sizeOne, int sizeTwo) {
    int i = 0;
    int j = 0;
    int sortedSize = sizeOne + sizeTwo;
    int *sortedArray = new int[sortedSize];
    for (int k = 0; k < sortedSize; k++) {
        if (arrayOne[i] < arrayTwo[j]) {
            sortedArray[k] = arrayOne[i];
            i += 1;
            if (i > sizeOne - 1) {
                arrayCopy(arrayTwo, j, sortedArray, k + 1, sizeTwo - j);
                return sortedArray;
            }
        } else {
            sortedArray[k] = arrayTwo[j];
            j += 1;
            if (j > sizeTwo - 1) {
                arrayCopy(arrayOne, i, sortedArray, k + 1, sizeOne - i);
                return sortedArray;
            }
        }
    }
    return sortedArray;
}

int *mergeSort(int *array, int size) {
    if (size <= 1) {
        return array;
    }
    int sizeOne = size / 2;
    int sizeTwo = size - sizeOne;
    int *arrayOne = new int[sizeOne];
    int *arrayTwo = new int[sizeTwo];
    for (int i = 0; i < sizeOne; i++) {
        arrayOne[i] = array[i];
    }
    for (int i = 0; i < sizeTwo; i++) {
        arrayTwo[i] = array[sizeOne + i];
    }
    int *firstSorted = mergeSort(arrayOne, sizeOne);
    int *secondSorted = mergeSort(arrayTwo, sizeTwo);
    return merge(firstSorted, secondSorted, sizeOne, sizeTwo);
}

int main() {
    int *array = new int[10]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    array = mergeSort(array, 10);
    for (int i = 0; i < 10; i++) {
        std::cout << array[i] << std::endl;
    }
}