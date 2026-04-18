#include <stdio.h>

int binary_search(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int result = binary_search(arr, size, key);

    if (result != -1) {
        printf("Key %d found at index %d\n", key, result);
    } else {
        printf("Key %d not found in the array\n", key);
    }

    return 0;
}