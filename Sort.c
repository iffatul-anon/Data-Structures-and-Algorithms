#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return;
}

void insertionSort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    return;
}

void merge(int array[], int low, int mid, int high) {
    int i = low;     
    int j = mid + 1;     
    int k = low;    
    int copy_array[high + 1];
    while (i <= mid && j <= high) {
        if (array[i] <= array[j]) {
            copy_array[k++] = array[i++];
        }
        else {
            copy_array[k++] = array[j++];
        }
    }
    while (i <= mid) {
        copy_array[k++] = array[i++];
    }
    while (j <= high) {
        copy_array[k++] = array[j++];
    }
    for (k = low; k <= high; k++) {
        array[k] = copy_array[k];
    }
    return;
}

void mergeSort(int array[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(array, low, mid);      
        mergeSort(array, mid + 1, high);  
        merge(array, low, mid, high); 
    }
    return;
}

int Partition(int array[], int low, int high) {
    int pivot = array[low];
    int start = low;
    int end = high;
    while (start < end) {
        while (array[start] <= pivot) {
            start++;
        }
        while (array[end] > pivot) {
            end--;
        }
        if (start < end) {
            int tem = array[start];
            array[start] = array[end];
            array[end] = tem;
        }
    }
    int tem = array[low];
    array[low] = array[end];
    array[end] = tem;
    return end;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int position = Partition(array, low, high);
        quickSort(array, low, position - 1);  
        quickSort(array, position + 1, high); 
    }
    return;
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int size;
    clock_t start, end;
    double bubble_time,insertion_time,merge_time,quick_time;
    printf("\nEnter the array size: ");
    scanf("%d",&size);
    int array[size],bubble_array[size],insertion_array[size],merge_array[size],quick_array[size];
    printf("\nEnter elements of the array: ");
    for(int i=0;i<size;i++){
        scanf("%d",&array[i]);
        bubble_array[i]=array[i];
        insertion_array[i]=array[i];
        merge_array[i]=array[i];
        quick_array[i]=array[i];
    }

    start = clock();
    bubbleSort(bubble_array, size);
    end = clock();
    bubble_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    insertionSort(insertion_array, size);
    end = clock();
    insertion_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    mergeSort(merge_array, 0, size-1);
    end = clock();
    merge_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    quickSort(quick_array, 0, size-1);
    end = clock();
    quick_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\n\n");
    printf("Bubble Sort:\n");
    printf("Sorted Array: ");
    printArray(bubble_array, size);
    printf("Runtime for sort %d elements = %lf seconds\n\n",size,bubble_time);
    printf("Insertion Sort:\n");
    printf("Sorted Array: ");
    printArray(insertion_array, size);
    printf("Runtime for sort %d elements = %lf seconds\n\n",size,bubble_time);
    printf("Merge Sort:\n");
    printf("Sorted Array: ");
    printArray(merge_array, size);
    printf("Runtime for sort %d elements = %lf seconds\n\n",size,bubble_time);
    printf("Quick Sort:\n");
    printf("Sorted Array: ");
    printArray(quick_array, size);
    printf("Runtime for sort %d elements = %lf seconds\n\n",size,bubble_time);
    return 0;
}