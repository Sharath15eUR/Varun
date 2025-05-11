//3. Sorting the entire 2D array and searching for a key

#include <stdio.h>
#include <stdbool.h>

void sortMatrix(int matrix[][100], int n) {
    int temp[n * n];
    int index = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[index++] = matrix[i][j];
   for (int i = 0; i < n * n - 1; i++) {
        for (int j = 0; j < n * n - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }
   index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = temp[index++];
}

bool searchMatrix(int matrix[][100], int n, int key) {
    int row = 0, col = n - 1;
    while (row < n && col >= 0) {
        if (matrix[row][col] == key)
            return true;
        else if (matrix[row][col] > key)
            col--;
        else
            row++;
    }
    return false;
}

void printMatrix(int matrix[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, key;
    int matrix[100][100];

    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter the elements of the %d x %d matrix:\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    printf("\nOriginal Matrix:\n");
    printMatrix(matrix, n);

    sortMatrix(matrix, n);

    printf("\nMatrix after full sorting:\n");
    printMatrix(matrix, n);

    printf("\nEnter the key to search: ");
    scanf("%d", &key);

    if (searchMatrix(matrix, n, key))
        printf("Key %d found.\n", key);
    else
        printf("Key %d not found.\n", key);

    return 0;
}
