#include <assert.h>
#include <stdio.h>

int any_odd_one(unsigned x) { return !!(x & 0xAAAAAAAA); }
void test_any_odd_one();

int main() {
    test_any_odd_one();
    return 0;
}

void test_any_odd_one() {
    printf("Running assertion tests for any_odd_one function...\n");
    printf(
        "Odd bit positions: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, "
        "29, 31\n\n");

    // Test cases that should return 1 (has odd bits set)

    // Single odd bits
    assert(any_odd_one(0x00000002) == 1);  // bit 1 set
    assert(any_odd_one(0x00000008) == 1);  // bit 3 set
    assert(any_odd_one(0x00000020) == 1);  // bit 5 set
    assert(any_odd_one(0x00000080) == 1);  // bit 7 set
    assert(any_odd_one(0x00000200) == 1);  // bit 9 set
    assert(any_odd_one(0x00000800) == 1);  // bit 11 set
    assert(any_odd_one(0x00002000) == 1);  // bit 13 set
    assert(any_odd_one(0x00008000) == 1);  // bit 15 set
    assert(any_odd_one(0x00020000) == 1);  // bit 17 set
    assert(any_odd_one(0x00080000) == 1);  // bit 19 set
    assert(any_odd_one(0x00200000) == 1);  // bit 21 set
    assert(any_odd_one(0x00800000) == 1);  // bit 23 set
    assert(any_odd_one(0x02000000) == 1);  // bit 25 set
    assert(any_odd_one(0x08000000) == 1);  // bit 27 set
    assert(any_odd_one(0x20000000) == 1);  // bit 29 set
    assert(any_odd_one(0x80000000) == 1);  // bit 31 set

    // Multiple odd bits
    assert(any_odd_one(0x0000000A) == 1);  // bits 1 and 3 set
    assert(any_odd_one(0x000000AA) == 1);  // bits 1,3,5,7 set
    assert(any_odd_one(0x0000AAAA) == 1);  // bits 1,3,5,7,9,11,13,15 set
    assert(any_odd_one(0xAAAAAAAA) == 1);  // all odd bits set

    // Mixed even and odd bits
    assert(any_odd_one(0xFFFFFFFF) == 1);  // all bits set
    assert(any_odd_one(0x12345678) == 1);  // has some odd bits
    assert(any_odd_one(0x87654321) == 1);  // has some odd bits
    assert(any_odd_one(0xDEADBEEF) == 1);  // has some odd bits

    // Edge case - highest bit (31) set with others
    assert(any_odd_one(0x80000001) == 1);  // bits 0 and 31 set
    assert(any_odd_one(0x80000000) == 1);  // only bit 31 set

    // Test cases that should return 0 (no odd bits set)

    // No bits set
    assert(any_odd_one(0x00000000) == 0);  // no bits set

    // Only even bits set
    assert(any_odd_one(0x00000001) == 0);  // bit 0 set
    assert(any_odd_one(0x00000004) == 0);  // bit 2 set
    assert(any_odd_one(0x00000010) == 0);  // bit 4 set
    assert(any_odd_one(0x00000040) == 0);  // bit 6 set
    assert(any_odd_one(0x00000100) == 0);  // bit 8 set
    assert(any_odd_one(0x00000400) == 0);  // bit 10 set
    assert(any_odd_one(0x00001000) == 0);  // bit 12 set
    assert(any_odd_one(0x00004000) == 0);  // bit 14 set
    assert(any_odd_one(0x00010000) == 0);  // bit 16 set
    assert(any_odd_one(0x00040000) == 0);  // bit 18 set
    assert(any_odd_one(0x00100000) == 0);  // bit 20 set
    assert(any_odd_one(0x00400000) == 0);  // bit 22 set
    assert(any_odd_one(0x01000000) == 0);  // bit 24 set
    assert(any_odd_one(0x04000000) == 0);  // bit 26 set
    assert(any_odd_one(0x10000000) == 0);  // bit 28 set
    assert(any_odd_one(0x40000000) == 0);  // bit 30 set

    // Multiple even bits
    assert(any_odd_one(0x00000005) == 0);  // bits 0 and 2 set
    assert(any_odd_one(0x00000055) == 0);  // bits 0,2,4,6 set
    assert(any_odd_one(0x00005555) == 0);  // bits 0,2,4,6,8,10,12,14 set
    assert(any_odd_one(0x55555555) == 0);  // all even bits set

    // Specific patterns
    assert(any_odd_one(0x11111111) ==
           0);  // pattern 0001000100010001... (only even bits)
    assert(any_odd_one(0x44444444) ==
           0);  // pattern 0100010001000100... (only even bits)

    // Boundary cases
    assert(any_odd_one(0x00000001) == 0);  // smallest non-zero, even bit
    assert(any_odd_one(0x00000002) == 1);  // smallest odd bit
    assert(any_odd_one(0x40000000) == 0);  // largest even bit
    assert(any_odd_one(0x80000000) == 1);  // largest odd bit

    printf("All assertion tests passed! ✓\n");

    // Additional verification with manual checking
    printf("\nVerification examples:\n");
    printf("0x00000002 (bit 1): %d\n", any_odd_one(0x00000002));  // Should be 1
    printf("0x00000001 (bit 0): %d\n", any_odd_one(0x00000001));  // Should be 0
    printf("0xAAAAAAAA (all odd): %d\n",
           any_odd_one(0xAAAAAAAA));  // Should be 1
    printf("0x55555555 (all even): %d\n",
           any_odd_one(0x55555555));  // Should be 0
    printf("0xFFFFFFFF (all bits): %d\n",
           any_odd_one(0xFFFFFFFF));  // Should be 1
    printf("0x00000000 (no bits): %d\n",
           any_odd_one(0x00000000));  // Should be 0
}
