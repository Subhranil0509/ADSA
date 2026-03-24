#include <stdio.h>

#define MAX 100

// Structure for a 3-tuple sparse representation
typedef struct {
    int row;
    int col;
    int val;
} Triple;

// Function to read matrix and convert to sparse
int createSparse(int mat[10][10], int r, int c, Triple sp[]) {
    int k = 1; // Start from index 1 (index 0 stores metadata)
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 0) {
                sp[k].row = i;
                sp[k].col = j;
                sp[k].val = mat[i][j];
                k++;
            }
        }
    }
    sp[0].row = r;
    sp[0].col = c;
    sp[0].val = k - 1; // number of non-zero elements
    return k - 1;
}

// Print sparse matrix
void printSparse(Triple sp[]) {
    printf("\nRow  Col  Val\n");
    for (int i = 0; i <= sp[0].val; i++)
        printf("%3d  %3d  %3d\n", sp[i].row, sp[i].col, sp[i].val);
}

// Sparse Matrix Addition
void addSparse(Triple a[], Triple b[], Triple c[]) {
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        printf("\nAddition not possible\n");
        return;
    }

    int i = 1, j = 1, k = 1;
    c[0].row = a[0].row;
    c[0].col = a[0].col;

    while (i <= a[0].val && j <= b[0].val) {
        if (a[i].row == b[j].row && a[i].col == b[j].col) {
            c[k].row = a[i].row;
            c[k].col = a[i].col;
            c[k].val = a[i].val + b[j].val;
            i++; j++; k++;
        }
        else if (a[i].row < b[j].row ||
                (a[i].row == b[j].row && a[i].col < b[j].col)) {
            c[k++] = a[i++];
        }
        else {
            c[k++] = b[j++];
        }
    }

    while (i <= a[0].val) c[k++] = a[i++];
    while (j <= b[0].val) c[k++] = b[j++];

    c[0].val = k - 1;
}

// Sparse Matrix Subtraction
void subSparse(Triple a[], Triple b[], Triple c[]) {
    b[0].val = b[0].val;  
    for (int i = 1; i <= b[0].val; i++)
        b[i].val = -b[i].val; // negate

    addSparse(a, b, c);
}

// Sparse Matrix Multiplication
void multiplySparse(Triple a[], Triple b[], Triple c[]) {
    if (a[0].col != b[0].row) {
        printf("\nMultiplication not possible\n");
        return;
    }

    int k = 1;
    c[0].row = a[0].row;
    c[0].col = b[0].col;

    for (int i = 1; i <= a[0].val; i++) {
        for (int j = 1; j <= b[0].val; j++) {
            if (a[i].col == b[j].row) {
                int r = a[i].row;
                int col = b[j].col;
                int val = a[i].val * b[j].val;

                int found = 0;
                for (int x = 1; x < k; x++) {
                    if (c[x].row == r && c[x].col == col) {
                        c[x].val += val;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    c[k].row = r;
                    c[k].col = col;
                    c[k].val = val;
                    k++;
                }
            }
        }
    }

    c[0].val = k - 1;
}

int main() {
    int r1, c1, r2, c2;
    int mat1[10][10], mat2[10][10];
    Triple sp1[MAX], sp2[MAX], sum[MAX], diff[MAX], prod[MAX];

    // Input matrix 1
    printf("Enter rows & cols of Matrix 1: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter Matrix 1:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &mat1[i][j]);

    // Input matrix 2
    printf("Enter rows & cols of Matrix 2: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter Matrix 2:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &mat2[i][j]);

    // Convert to sparse
    createSparse(mat1, r1, c1, sp1);
    createSparse(mat2, r2, c2, sp2);

    printf("\nSparse Matrix 1:");
    printSparse(sp1);

    printf("\nSparse Matrix 2:");
    printSparse(sp2);

    // Addition
    addSparse(sp1, sp2, sum);
    printf("\nAddition (Sparse):");
    printSparse(sum);

    // Subtraction
    subSparse(sp1, sp2, diff);
    printf("\nSubtraction (Sparse):");
    printSparse(diff);

    // Multiplication
    multiplySparse(sp1, sp2, prod);
    printf("\nMultiplication (Sparse):");
    printSparse(prod);

    return 0;
}
