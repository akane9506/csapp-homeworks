#include <assert.h>
#include <stdio.h>

int any_bit_eq_1(int val) { return !!val; }
int any_bit_eq_0(int val) { return !!(~val); }
int any_lest_bit_eq_1(int val) { return !!(val & 0x000000FF); }
int any_most_bit_eq_0(int val) { return !!(~val & 0xFF000000); }

int main() {
    printf("Testing bit-level expressions...\n");

    // Test A: Any bit of x equals 1
    printf("Testing A (any bit equals 1):\n");
    assert(any_bit_eq_1(0x00000000) == 0);
    printf("  0x00000000: %d (expected 0) ✓\n", any_bit_eq_1(0x00000000));
    assert(any_bit_eq_1(0x00001000) == 1);
    printf("  0x00001000: %d (expected 1) ✓\n", any_bit_eq_1(0x00001000));
    assert(any_bit_eq_1(0xFFFFFFFF) == 1);
    printf("  0xFFFFFFFF: %d (expected 1) ✓\n", any_bit_eq_1(0xFFFFFFFF));

    // Test B: Any bit of x equals 0
    printf("\nTesting B (any bit equals 0):\n");
    assert(any_bit_eq_0(0xFFFFFFFF) == 0);
    printf("  0xFFFFFFFF: %d (expected 0) ✓\n", any_bit_eq_0(0xFFFFFFFF));
    assert(any_bit_eq_0(0x10111111) == 1);
    printf("  0x10111111: %d (expected 1) ✓\n", any_bit_eq_0(0x10111111));
    assert(any_bit_eq_0(0x00000000) == 1);
    printf("  0x00000000: %d (expected 1) ✓\n", any_bit_eq_0(0x00000000));

    // Test C: Any bit in the least significant byte of x equals 1
    printf("\nTesting C (any bit in LSB equals 1):\n");
    assert(any_lest_bit_eq_1(0xFFFFFF00) == 0);
    printf("  0xFFFFFF00: %d (expected 0) ✓\n", any_lest_bit_eq_1(0xFFFFFF00));
    assert(any_lest_bit_eq_1(0x00000000) == 0);
    printf("  0x00000000: %d (expected 0) ✓\n", any_lest_bit_eq_1(0x00000000));
    assert(any_lest_bit_eq_1(0x00000001) == 1);
    printf("  0x00000001: %d (expected 1) ✓\n", any_lest_bit_eq_1(0x00000001));

    // Test D: Any bit in the most significant byte of x equals 0
    printf("\nTesting D (any bit in MSB equals 0):\n");
    assert(any_most_bit_eq_0(0xFF000000) == 0);
    printf("  0xFF000000: %d (expected 0) ✓\n", any_most_bit_eq_0(0xFF000000));
    assert(any_most_bit_eq_0(0xFFFFFFFF) == 0);
    printf("  0xFFFFFFFF: %d (expected 0) ✓\n", any_most_bit_eq_0(0xFFFFFFFF));
    assert(any_most_bit_eq_0(0xEFFFFFFF) == 1);
    printf("  0xEFFFFFFF: %d (expected 1) ✓\n", any_most_bit_eq_0(0xEFFFFFFF));

    // Additional test cases for D
    printf("  0x7FFFFFFF: %d (expected 1) ✓\n", any_most_bit_eq_0(0x7FFFFFFF));
    printf("  0x00000000: %d (expected 1) ✓\n", any_most_bit_eq_0(0x00000000));

    printf("\nAll tests passed!\n");
    return 0;
}