#include <stdio.h>
#include <stdint.h>

void printBits(uint32_t a, uint32_t b, int size) {
    for (int i = size - 1; i >= 0; i--) printf("%d", (a >> i) & 1);
    printf(" | ");
    for (int i = size - 1; i >= 0; i--) printf("%d", (b >> i) & 1);
    printf("\n");
}

void swapBit(uint32_t* a, uint32_t* b, int pos) {
    uint32_t bitA = (*a >> pos) & 1;
    uint32_t bitB = (*b >> pos) & 1;
    if (bitA != bitB) {
        *a ^= (1 << pos);
        *b ^= (1 << pos);
    }
}

void heapAlgorithm(uint32_t* a, uint32_t* b, int size) {
    int swaps[size];
    for (int i = 0; i < size; i++) swaps[i] = 0;

    printBits(*a, *b, size);

    int i = 0;
    while (i < size) {
        if (swaps[i] < i) {
            int pos = swaps[i];
            swapBit(a, b, pos);
            printBits(*a, *b, size);
            swaps[i]++;
            i = 0;
        }
        else {
            swaps[i] = 0;
            i++;
        }
    }
}

int main() {
    uint32_t a = 0b101; // Example binary values
    uint32_t b = 0b010;
    int size = 3;

    heapAlgorithm(&a, &b, size);

    return 0;
}
