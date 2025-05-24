#include <assert.h>
#include <stdio.h>

int leftmost_one(unsigned x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x ^ (x >> 1);
}

void test_leftmost_one();

int main() {
    test_leftmost_one();
    return 0;
}

void test_leftmost_one() {
    // Edge case: zero input
    assert(leftmost_one(0x00000000) == 0x00000000);

    // Single bit cases
    assert(leftmost_one(0x00000001) == 0x00000001);
    assert(leftmost_one(0x00000002) == 0x00000002);
    assert(leftmost_one(0x80000000) == 0x80000000);

    // General cases
    assert(leftmost_one(0x0000FF00) == 0x00008000);  // leftmost 1 is bit 15
    assert(leftmost_one(0x00006600) == 0x00004000);  // leftmost 1 is bit 14
    assert(leftmost_one(0x00F00000) == 0x00800000);  // bit 23
    assert(leftmost_one(0x0F000000) == 0x08000000);  // bit 27
    assert(leftmost_one(0x7FFFFFFF) == 0x40000000);  // bit 30
    assert(leftmost_one(0xFFFFFFFF) == 0x80000000);  // bit 31

    // Random values
    assert(leftmost_one(0x00000100) == 0x00000100);  // bit 8
    assert(leftmost_one(0x01000000) == 0x01000000);  // bit 24
    assert(leftmost_one(0x00ABCDEF) == 0x00800000);  // bit 23

    printf("All test cases passed!\n");
}