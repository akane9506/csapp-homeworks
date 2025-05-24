#include <assert.h>
#include <stdio.h>

unsigned rotate_left(unsigned x, int n) {
    if (n == 0) return x;
    unsigned left_part = x << n;
    unsigned right_part = x >> (32 - n);
    return left_part | right_part;
}

void test_rotate_left();

int main() {
    test_rotate_left();
    return 0;
}

void test_rotate_left() {
    // Basic rotation
    assert(rotate_left(0x12345678, 0) == 0x12345678);   // No rotation
    assert(rotate_left(0x12345678, 4) == 0x23456781);   // Rotate by 4
    assert(rotate_left(0x12345678, 8) == 0x34567812);   // Rotate by 8
    assert(rotate_left(0x12345678, 12) == 0x45678123);  // Rotate by 12
    assert(rotate_left(0x12345678, 16) == 0x56781234);  // Halfway
    assert(rotate_left(0x12345678, 20) == 0x67812345);  // From example
    assert(rotate_left(0x12345678, 28) == 0x81234567);  // Near full

    // Rotating all 1s
    assert(rotate_left(0xFFFFFFFF, 1) == 0xFFFFFFFF);  // All 1s remain
    assert(rotate_left(0xFFFFFFFF, 31) == 0xFFFFFFFF);

    // Rotating 0
    assert(rotate_left(0x00000000, 5) == 0x00000000);  // All 0s remain

    // Edge values
    assert(rotate_left(0x80000000, 1) == 0x00000001);   // MSB rotates to LSB
    assert(rotate_left(0x00000001, 31) == 0x80000000);  // LSB rotates to MSB

    printf("All tests passed!\n");
}