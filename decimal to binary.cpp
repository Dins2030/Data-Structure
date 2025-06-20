#include <stdio.h>
int main() {
    unsigned int n;
    int MAX_BITS=32;
    int bits[MAX_BITS];
    int index = 0;
    printf("Enter a non-negative decimal number: ");
    if (scanf("%u", &n) != 1) return 0;
    if (n == 0) {
        printf("Binary: 0\n");
        return 0;
    }
    while (n > 0) {
        bits[index++] = n % 2;
        n /= 2;
    }
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", bits[i]);
    }
    printf("\n");
    return 0;
}

