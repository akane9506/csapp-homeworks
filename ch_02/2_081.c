#include <assert.h>
#include <stdio.h>

unsigned bit_pattern_a(unsigned k) {
    if (k >= sizeof(unsigned) << 3) return 0;
    return ~0x0U << k;
}

unsigned bit_pattern_b(unsigned j, unsigned k) {
    if (k == 32) return ~0x0;
    if (k == 0) return 0;
    return (~0x0U >> (32 - k - j)) & (~(0x0) << j);
}

void test_bit_pattern_a();
void test_bit_pattern_b();

int main() {
    test_bit_pattern_a();
    test_bit_pattern_b();
    return 0;
}

void test_bit_pattern_a() {
    assert(bit_pattern_a(0) == 0xFFFFFFFF);   // All ones
    assert(bit_pattern_a(1) == 0xFFFFFFFE);   // 31 ones, 1 zero
    assert(bit_pattern_a(2) == 0xFFFFFFFC);   // 30 ones, 2 zeros
    assert(bit_pattern_a(4) == 0xFFFFFFF0);   // 28 ones, 4 zeros
    assert(bit_pattern_a(8) == 0xFFFFFF00);   // 24 ones, 8 zeros
    assert(bit_pattern_a(16) == 0xFFFF0000);  // 16 ones, 16 zeros
    assert(bit_pattern_a(31) == 0x80000000);  // 1 one, 31 zeros
    assert(bit_pattern_a(32) == 0x00000000);

    printf("All bit_pattern_a tests passed.\n");
}

void test_bit_pattern_b() {
    assert(bit_pattern_b(0, 1) == 0x00000001);  // 000...0001
    assert(bit_pattern_b(0, 4) == 0x0000000F);  // 000...1111
    assert(bit_pattern_b(4, 4) == 0x000000F0);  // 000...11110000
    assert(bit_pattern_b(8, 8) == 0x0000FF00);  // 000000001111111100000000
    assert(bit_pattern_b(16, 8) ==
           0x00FF0000);  // 00000000111111110000000000000000
    assert(bit_pattern_b(24, 8) ==
           0xFF000000);  // 11111111000000000000000000000000

    assert(bit_pattern_b(0, 32) == 0xFFFFFFFF);  // All ones
    assert(bit_pattern_b(31, 1) == 0x80000000);  // One at MSB
    assert(bit_pattern_b(32, 0) == 0x00000000);  // No ones
    assert(bit_pattern_b(0, 0) == 0x00000000);   // No ones

    assert(bit_pattern_b(20, 13) == 0);  // 33 bits
    assert(bit_pattern_b(31, 2) == 0);   // 33 bits

    printf("All bit_pattern_b tests passed.\n");
}