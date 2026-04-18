#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void ls(int [], int, int, int);
void ls(int a1[], int begin, int stop, int search)
{
    if (begin == stop)
        printf("Element not found\n");
    else if (a1[begin] == search)
        printf("element found @ position %d\n", begin + 1);
    else
        ls(a1, begin + 1, stop, search);
}

int main()
{
    int a[10000], n = 10000, key, i;
    clock_t start, end;
    for (i = 0; i < n; i++)
        a[i] = rand() % 1000;
    key = rand() % 1000;
    start = clock();
    ls(a, 0, n, key);
    end = clock();
    printf("total time taken for execution is %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}