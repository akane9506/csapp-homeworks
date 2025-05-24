#include <assert.h>
#include <stdio.h>

int fits_bits(int x, int n) {
    int shift = 32 - n;
    return ((x << shift) >> shift) == x;
}

void test_fits_bits();

int main() {
    test_fits_bits();
    return 0;
}

void test_fits_bits() {
    // Basic small integers
    assert(fits_bits(0, 1) == 1);   // 0 fits in 1 bit
    assert(fits_bits(-1, 1) == 1);  // -1 fits in 1 bit (two's complement)
    assert(fits_bits(1, 1) == 0);   // 1 does not fit in 1 bit
    assert(fits_bits(1, 2) == 1);   // 1 fits in 2 bits
    assert(fits_bits(-2, 2) == 1);  // -2 fits in 2 bits
    assert(fits_bits(-3, 2) == 0);  // -3 doesn't fit in 2 bits

    // Edge cases for small n
    assert(fits_bits(3, 3) == 1);  // 3 is max in 3-bit: 011
    assert(fits_bits(4, 3) == 0);  // 100 -> -4 in 3-bit two's complement

    // Larger positive and negative values
    assert(fits_bits(127, 8) == 1);   // Max positive for 8-bit
    assert(fits_bits(128, 8) == 0);   // Just outside 8-bit
    assert(fits_bits(-128, 8) == 1);  // Min for 8-bit
    assert(fits_bits(-129, 8) == 0);  // Just outside

    // 16-bit and 32-bit checks
    assert(fits_bits(0x7FFF, 16) == 1);   // 32767
    assert(fits_bits(-0x8000, 16) == 1);  // -32768
    assert(fits_bits(0x8000, 16) == 0);   // 32768 doesn't fit
    assert(fits_bits(-0x8001, 16) == 0);  // Too negative

    // Full 32-bit edge
    assert(fits_bits(0x7FFFFFFF, 32) == 1);  // Max int
    assert(fits_bits(0x80000000, 32) == 1);  // Min int

    printf("All tests passed!\n");
}
