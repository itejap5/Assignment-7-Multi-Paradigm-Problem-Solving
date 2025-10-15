#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

double mean_proc(const int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    return (double)sum / (double)n;
}

double median_proc(const int *sorted, int n) {
    if (n % 2) return sorted[n / 2];
    return (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;
}

void modes_proc(const int *sorted, int n) {
    int maxc = 0, i = 0;
    while (i < n) {
        int j = i + 1;
        while (j < n && sorted[j] == sorted[i]) j++;
        int count = j - i;
        if (count > maxc) maxc = count;
        i = j;
    }

    printf("Mode(s): ");
    i = 0;
    int first = 1;
    while (i < n) {
        int j = i + 1;
        while (j < n && sorted[j] == sorted[i]) j++;
        int count = j - i;
        if (count == maxc) {
            if (!first) printf(", ");
            printf("%d", sorted[i]);
            first = 0;
        }
        i = j;
    }
    printf(" (freq = %d)\n", maxc);
}

int main(void) {
    // Default dataset
    int data[] = {1, 2, 2, 3, 4, 5, 5, 5, 6};
    int n = sizeof(data) / sizeof(data[0]);

    // Sort copy
    int *sorted = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) sorted[i] = data[i];
    qsort(sorted, n, sizeof(int), cmp_int);

    printf("[Auto mode: default data used]\n");
    printf("Input count: %d\n", n);
    printf("Mean: %.2f\n", mean_proc(sorted, n));
    printf("Median: %.2f\n", median_proc(sorted, n));
    modes_proc(sorted, n);

    free(sorted);
    return 0;
}