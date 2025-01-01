#include <stdio.h>
#include <stdlib.h>

int *arr;
int size = 0;

// Function to display the array
void displayArray() {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element into the array
void insertElement() {
    int *temp = (int *) realloc(arr, (size + 1) * sizeof(int));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    arr = temp;
    printf("Enter the element to insert: ");
    if (scanf("%d", &arr[size]) != 1) {
        printf("Invalid input.\n");
        return;
    }
    size++;
    printf("Element inserted successfully.\n");
    displayArray();
}

// Function to delete an element from the array
void deleteElement() {
    if (size > 0) {
        printf("Enter the index of the element to delete (0-%d): ", size - 1);
        int index;
        if (scanf("%d", &index) != 1) {
            printf("Invalid input.\n");
            return;
        }
        if (index < 0 || index >= size) {
            printf("Invalid index.\n");
            return;
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        int *temp = (int *) realloc(arr, size * sizeof(int));
        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        arr = temp;
        printf("Element deleted successfully.\n");
        displayArray();
    } else {
        printf("Array is empty. Cannot delete elements.\n");
    }
}

// Function to sort the array in ascending order
void sortArray() {
    if (size > 0) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        printf("Array sorted successfully.\n");
        displayArray();
    } else {
        printf("Array is empty. Cannot sort.\n");
    }
}

// Function to merge two arrays
void mergeArrays(int *arr1, int size1, int *arr2, int size2) {
    int *mergedArray = (int *) malloc((size1 + size2) * sizeof(int));
    if (mergedArray == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArray[k] = arr1[i];
            i++;
        } else {
            mergedArray[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        mergedArray[k] = arr1[i];
        i++;
        k++;
    }

    while (j < size2) {
        mergedArray[k] = arr2[j];
        j++;
        k++;
    }

    printf("Merged array: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");
    free(mergedArray);
}

int main() {
    int choice;
    int *arr2;

    arr = (int *) malloc(sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    while (1) {
        printf("Menu:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Sort array\n");
        printf("4. Display array\n");
        printf("5. Merge with another array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            continue;
        }

        switch (choice) {
            case 1:
                insertElement();
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                sortArray();
                break;
            case 4:
                displayArray();
                break;
            case 5:
                printf("Enter the elements of the second array (separated by spaces): ");
                arr2 = (int *) malloc(sizeof(int));
                if (arr2 == NULL) {
                    printf("Memory allocation failed.\n");
                    continue;
                }
                int size2 = 0;
                while (1) {
                    if (scanf("%d", &arr2[size2]) != 1) {
                        printf("Invalid input.\n");
                        free(arr2);
                        continue;
                    }
                    size2++;
                    if (getchar() == '\n') break;
                }
                mergeArrays(arr, size, arr2, size2);
                free(arr2);
                break;
            case 6:
                printf("Exiting...\n");
                free(arr);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
