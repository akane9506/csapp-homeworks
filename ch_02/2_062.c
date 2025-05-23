#include <stdio.h>
int int_shift_are_arithmetic() {
    int x = ~0;  // #-1 0xFFFFFFFF
    int shifted = x >> 1;
    return shifted == x;
}

int main() {
    int is_arithmetic = int_shift_are_arithmetic();
    printf("Shift method: %s\n", is_arithmetic ? "Arithmetic" : "Logical");
}