#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int linearSearch(int array[], int n, int element) {
    for (int i = 0; i < n; i++){
        if (array[i] == element) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int array[], int low, int high, int element) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == element) {
            return mid;
        }
        if (array[mid] < element) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int size,element;
    clock_t start, end;
    double linear_time,binary_time;
    printf("\nEnter the array size: ");
    scanf("%d",&size);
    int array[size];
    printf("\nEnter elements of the array: ");
    for(int i=0;i<size;i++){
        scanf("%d",&array[i]);
    }
    printf("\nEnter searched element: ");
    scanf("%d",&element);

    start = clock();
    int linear_result = linearSearch(array, size, element);
    end = clock();
    linear_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    int binary_result = binarySearch(array, 0, size-1, element);
    end = clock();
    binary_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("\n\n");
    printf("Linear Search:\n");
    if(linear_result==-1){
        printf("Element not found\n");
    }
    else{
        printf("Element found at index: %d\n", linear_result+1);
    }
    printf("Runtime for search (%d inputs) = %lf seconds\n\n",size,linear_time);
    printf("Binary Search:\n");
    if(binary_result==-1){
        printf("Element not found\n");
    }
    else{
        printf("Element found at index: %d\n", binary_result+1);
    }
    printf("Runtime for search (%d inputs) = %lf seconds\n\n",size,binary_time);
    return 0;
}