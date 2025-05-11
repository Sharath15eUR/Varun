//2. Pointers – Even Before Odd

#include <stdio.h>

void rearrange(int *arr, int size) {
    int temp[size]; 
    int i = 0;
    for (int j = 0; j < size; ++j)
        if (arr[j] % 2 == 0)
            temp[i++] = arr[j];
    for (int j = 0; j < size; ++j)
        if (arr[j] % 2 != 0)
            temp[i++] = arr[j];
   for (int j = 0; j < size; ++j)
        arr[j] = temp[j];
}

void printArray(const int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int size;
    
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("\nOriginal array:\t");
    printArray(arr, size);
    
    rearrange(arr, size);
    printf("\nArray after rearranging (evens first):\t");
    printArray(arr, size);
    return 0;
}
