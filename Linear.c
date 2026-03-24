#include <stdio.h>

int main() {
    int A[] = {10, 4, 21, 23, 9, 23, 3, 100, 1, 93};
    int length = 10;
    int key, i, flag = 0;

    printf("Enter key to search: ");
    scanf("%d", &key);

    for (i = 0; i < length; i++) {
        if (key == A[i]) {
            printf("Element found at index %d\n", i);
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("Element not found in array\n");

    return 0;
}
