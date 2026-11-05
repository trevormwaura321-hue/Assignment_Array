
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, position, value, choice;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = malloc((n + 1) * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d array elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\n1. Insert a value\n");
    printf("2. Delete a value\n");
    printf("Choose an operation: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter value to insert: ");
        scanf("%d", &value);

        printf("Enter position (1 to %d): ", n + 1);
        scanf("%d", &position);

        if (position < 1 || position > n + 1) {
            printf("Invalid position!\n");
        } else {
            for (i = n; i >= position; i--) {
                arr[i] = arr[i - 1];
            }

            arr[position - 1] = value;
            n++;

            printf("Array after insertion: ");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
        }
    }
    else if (choice == 2) {
        printf("Enter position to delete (1 to %d): ", n);
        scanf("%d", &position);

        if (position < 1 || position > n) {
            printf("Invalid position!\n");
        } else {
            for (i = position - 1; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }

            n--;

            printf("Array after deletion: ");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
        }
    }
    else {
        printf("Invalid choice!\n");
    }

    free(arr);
    return 0;
}
