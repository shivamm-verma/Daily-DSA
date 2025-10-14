#include <stdio.h>
#include <stdlib.h>

// comparator function for descending order sorting
int compareDesc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int costVer[] = {2, 1, 3, 1, 4};   // vertical cuts
    int costHor[] = {4, 1, 2};   // horizontal cuts
    int m = sizeof(costVer) / sizeof(costVer[0]);
    int n = sizeof(costHor) / sizeof(costHor[0]);

    // sort in descending order
    qsort(costVer, m, sizeof(int), compareDesc);
    qsort(costHor, n, sizeof(int), compareDesc);

    int h = 0, v = 0, hp = 1, vp = 1;
    int cost = 0;

    while (h < n && v < m) {
        if (costHor[h] >= costVer[v]) {
            cost += costHor[h] * vp;
            h++; hp++;
        } else {
            cost += costVer[v] * hp;
            v++; vp++;
        }
    }

    while (h < n) cost += costHor[h++] * vp;
    while (v < m) cost += costVer[v++] * hp;

    printf("Total minimum cost: %d\n", cost);
    return 0;
}
