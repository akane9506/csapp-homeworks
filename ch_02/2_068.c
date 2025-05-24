#include <assert.h>
#include <stdio.h>

int lower_one_mask(int n) {
    int mask = ~0x0 << (n - 1);
    mask <<= 1;
    return ~mask;
}

void test_lower_one_mask();

int main() {
    test_lower_one_mask();
    return 0;
}

void test_lower_one_mask() {
    // Basic values
    assert(lower_one_mask(1) == 0x00000001);  // 000...0001
    assert(lower_one_mask(2) == 0x00000003);  // 000...0011
    assert(lower_one_mask(3) == 0x00000007);  // 000...0111

    // Byte-aligned sizes
    assert(lower_one_mask(8) ==
           0x000000FF);  // 00000000 00000000 00000000 11111111
    assert(lower_one_mask(16) ==
           0x0000FFFF);  // 00000000 00000000 11111111 11111111
    assert(lower_one_mask(24) ==
           0x00FFFFFF);  // 00000000 11111111 11111111 11111111

    // Non-byte aligned
    assert(lower_one_mask(5) == 0x0000001F);   // 000...11111
    assert(lower_one_mask(13) == 0x00001FFF);  // 000...1 1111 1111 1111
    assert(lower_one_mask(17) == 0x0001FFFF);  // 000...1 1111 1111 1111 1111
    assert(lower_one_mask(31) == 0x7FFFFFFF);  // 0111...1111

    // Edge case: full 32-bit mask
    assert(lower_one_mask(32) == 0xFFFFFFFF);  // All bits set

    printf("All tests passed!\n");
}