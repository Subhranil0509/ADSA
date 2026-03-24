#include <stdio.h>

int main() {
    int A[] = {9, 8, 10, 11, 38, 56, 77, 81, 88, 91, 93, 95, 98, 99};
    int key, l = 0, h = 13, mid;
    
    printf("Enter key to search: ");
    scanf("%d", &key);

    while (l <= h) {
        mid = (l + h) / 2;

        if (key == A[mid]) {
            printf("Element found at index %d\n", mid);
            return 0;
        }

        if (key > A[mid])
            l = mid + 1;
        else
            h = mid - 1;
    }

    printf("Element not found\n");
    return 0;
}
