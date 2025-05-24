#include <assert.h>
#include <limits.h>
#include <stdio.h>

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int)x >> k;
    unsigned mask = (~0x0U) >> k;
    return xsra & mask;
}

unsigned sra(int x, int k) {
    int xsrl = (unsigned)x >> k;
    int extended_bits = (INT_MIN & x) >> k;
    return xsrl | extended_bits;
}

void test_shift_functions();

int main() {
    test_shift_functions();
    return 0;
}

// Test function

void test_shift_functions() {
    printf("Running assertion tests for shift functions...\n");

    // SRL Tests - compare against standard logical right shift

    // Basic positive numbers
    assert(srl(0x12345678U, 4) == (0x12345678U >> 4));
    assert(srl(0x12345678U, 8) == (0x12345678U >> 8));
    assert(srl(0x12345678U, 0) == (0x12345678U >> 0));

    // Numbers with MSB set (critical test cases)
    assert(srl(0x80000000U, 1) == (0x80000000U >> 1));  // Should be 0x40000000
    assert(srl(0x80000000U, 4) == (0x80000000U >> 4));  // Should be 0x08000000
    assert(srl(0x80000000U, 31) ==
           (0x80000000U >> 31));  // Should be 0x00000001

    // All 1s pattern
    assert(srl(0xFFFFFFFFU, 1) == (0xFFFFFFFFU >> 1));  // Should be 0x7FFFFFFF
    assert(srl(0xFFFFFFFFU, 8) == (0xFFFFFFFFU >> 8));  // Should be 0x00FFFFFF
    assert(srl(0xFFFFFFFFU, 16) ==
           (0xFFFFFFFFU >> 16));  // Should be 0x0000FFFF
    assert(srl(0xFFFFFFFFU, 31) ==
           (0xFFFFFFFFU >> 31));  // Should be 0x00000001

    // Edge cases
    assert(srl(0x00000000U, 15) == (0x00000000U >> 15));
    assert(srl(0x00000001U, 1) == (0x00000001U >> 1));
    assert(srl(0x7FFFFFFFU, 1) == (0x7FFFFFFFU >> 1));

    // SRA Tests - compare against standard arithmetic right shift

    // Positive numbers
    assert(sra(0x12345678, 4) == (0x12345678 >> 4));
    assert(sra(0x12345678, 8) == (0x12345678 >> 8));
    assert(sra(0x12345678, 0) == (0x12345678 >> 0));
    assert(sra(0x7FFFFFFF, 1) == (0x7FFFFFFF >> 1));
    assert(sra(0x7FFFFFFF, 31) == (0x7FFFFFFF >> 31));

    // Negative numbers (critical test cases)
    assert(sra(-1, 1) == (-1 >> 1));    // Should remain -1
    assert(sra(-1, 8) == (-1 >> 8));    // Should remain -1
    assert(sra(-1, 31) == (-1 >> 31));  // Should remain -1

    assert(sra(INT_MIN, 1) == (INT_MIN >> 1));    // Should be 0xC0000000
    assert(sra(INT_MIN, 4) == (INT_MIN >> 4));    // Should be 0xF8000000
    assert(sra(INT_MIN, 31) == (INT_MIN >> 31));  // Should be -1

    assert(sra(-42, 2) == (-42 >> 2));
    assert(sra(-0x12345678, 4) == (-0x12345678 >> 4));

    // Zero
    assert(sra(0, 15) == (0 >> 15));

    // Specific critical values
    assert(sra(-2, 1) == (-2 >> 1));  // Should be -1
    assert(sra(-4, 2) == (-4 >> 2));  // Should be -1
    assert(sra(-8, 3) == (-8 >> 3));  // Should be -1

    // Test boundary between positive and negative
    assert(sra(0x7FFFFFFF, 1) == (0x7FFFFFFF >> 1));    // Largest positive
    assert(sra(-0x7FFFFFFF, 1) == (-0x7FFFFFFF >> 1));  // Large negative

    printf("All assertion tests passed! ✓\n");
}