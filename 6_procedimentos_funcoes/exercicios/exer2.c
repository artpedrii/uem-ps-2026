
#include <stdio.h>

void matriz(int m, int n) { 
    int i, j; 
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d,%d ", i, j);
        }
        printf("\n");
    }
}

int main() { 
    matriz(3, 5);
    return 0;
}
