#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[high]);
    return i + 1;
}

int random_partition(int A[], int low, int high) {
    srand(time(NULL));
    int r = low + rand() % (high - low + 1);
    swap(&A[r], &A[high]);
    return partition(A, low, high);
}

void randomized_quick_sort(int A[], int low, int high) {
    if (low < high) {
        int pi = random_partition(A, low, high);
        randomized_quick_sort(A, low, pi - 1);
        randomized_quick_sort(A, pi + 1, high);
    }
}

int main() {
    int n, A[10];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++) scanf("%d", &A[i]);

    randomized_quick_sort(A, 0, n - 1);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) printf("%d ", A[i]);
    return 0;
}
