#include <assert.h>
#include <stdio.h>

int odd_ones(unsigned x) {
    x = x ^ (x >> 16);
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    return x & 0x1;
}

void test_odd_ones();

int main() {
    test_odd_ones();
    return 0;
}

void test_odd_ones() {
    printf("Testing odd_ones function...\n");

    // Test case 1: 0 (zero 1-bits - even)
    assert(odd_ones(0x0) == 0);
    printf("✓ Test 0x0 (0 ones): %d\n", odd_ones(0x0));

    // Test case 2: 1 (one 1-bit - odd)
    assert(odd_ones(0x1) == 1);
    printf("✓ Test 0x1 (1 one): %d\n", odd_ones(0x1));

    // Test case 3: 3 (two 1-bits - even)
    assert(odd_ones(0x3) == 0);
    printf("✓ Test 0x3 (2 ones): %d\n", odd_ones(0x3));

    // Test case 4: 7 (three 1-bits - odd)
    assert(odd_ones(0x7) == 1);
    printf("✓ Test 0x7 (3 ones): %d\n", odd_ones(0x7));

    // Test case 5: 15 (four 1-bits - even)
    assert(odd_ones(0xF) == 0);
    printf("✓ Test 0xF (4 ones): %d\n", odd_ones(0xF));

    // Test case 6: All 1s (32 ones - even)
    assert(odd_ones(0xFFFFFFFF) == 0);
    printf("✓ Test 0xFFFFFFFF (32 ones): %d\n", odd_ones(0xFFFFFFFF));

    // Test case 7: Alternating pattern (16 ones - even)
    assert(odd_ones(0xAAAAAAAA) == 0);
    printf("✓ Test 0xAAAAAAAA (16 ones): %d\n", odd_ones(0xAAAAAAAA));

    // Test case 8: Other alternating pattern (16 ones - even)
    assert(odd_ones(0x55555555) == 0);
    printf("✓ Test 0x55555555 (16 ones): %d\n", odd_ones(0x55555555));

    // Test case 9: Single bit in high position (1 one - odd)
    assert(odd_ones(0x80000000) == 1);
    printf("✓ Test 0x80000000 (1 one): %d\n", odd_ones(0x80000000));

    // Test case 10: Pattern with 5 ones (odd)
    assert(odd_ones(0x1F) == 1);
    printf("✓ Test 0x1F (5 ones): %d\n", odd_ones(0x1F));

    // Test case 11: Pattern with 6 ones (even)
    assert(odd_ones(0x3F) == 0);
    printf("✓ Test 0x3F (6 ones): %d\n", odd_ones(0x3F));

    // Test case 12: Scattered bits (13 ones - odd)
    assert(odd_ones(0x12345678) == 1);
    printf("✓ Test 0x12345678 (13 ones): %d\n", odd_ones(0x12345678));

    // Test case 13: Another scattered pattern (8 ones - even)
    assert(odd_ones(0x81818181) == 0);
    printf("✓ Test 0x81818181 (8 ones): %d\n", odd_ones(0x81818181));

    // Test case 14: Edge case - one bit set in each byte (4 ones - even)
    assert(odd_ones(0x01010101) == 0);
    printf("✓ Test 0x01010101 (4 ones): %d\n", odd_ones(0x01010101));

    // Test case 15: Maximum odd case (31 ones - odd)
    assert(odd_ones(0x7FFFFFFF) == 1);
    printf("✓ Test 0x7FFFFFFF (31 ones): %d\n", odd_ones(0x7FFFFFFF));

    printf("\nAll tests passed! ✓\n");
}