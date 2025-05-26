#include <assert.h>
#include <limits.h>
#include <stdio.h>

int threefourths(int x) {
    int q = x >> 2;   // quotient
    int r = x & 0x3;  // remainder

    int q3 = (q << 1) + q;  // quotient times 3
    int r3 = (r << 1) + r;  // remainder times 3

    // get correction from the remainder
    int sign = x >> 31;
    int bias = sign & ((1 << 2) - 1);
    int correction = (r3 + bias) >> 2;

    return q3 + correction;
}

void test_threefourths();

int main() {
    test_threefourths();
    return 0;
}

void test_threefourths() {
    // Basic cases
    assert(threefourths(0) == 0);  // 3/4 * 0 = 0
    assert(threefourths(4) == 3);  // 3/4 * 4 = 3
    assert(threefourths(8) == 6);  // 3/4 * 8 = 6
    assert(threefourths(1) == 0);  // 3/4 = 0.75 → round toward 0
    assert(threefourths(2) == 1);  // 1.5 → 1
    assert(threefourths(3) == 2);  // 2.25 → 2

    // Negative inputs
    assert(threefourths(-1) == 0);   // -0.75 → 0
    assert(threefourths(-2) == -1);  // -1.5 → -1
    assert(threefourths(-3) == -2);  // -2.25 → -2
    assert(threefourths(-4) == -3);  // -3

    // Edge of rounding
    assert(threefourths(5) == 3);    // 3.75 → 3
    assert(threefourths(-5) == -3);  // -3.75 → -3
    assert(threefourths(7) == 5);    // 5.25 → 5
    assert(threefourths(-7) == -5);  // -5.25 → -5

    // Edge cases for overflow safety
    assert(threefourths(INT_MAX) == (int)(((long long)INT_MAX * 3) / 4));
    assert(threefourths(INT_MIN) == (int)(((long long)INT_MIN * 3) / 4));

    // Exhaustive small range test
    for (int x = -100; x <= 100; x++) {
        int expected =
            (int)(((long long)x * 3) / 4);  // Ground truth with no overflow
        assert(threefourths(x) == expected);
    }

    printf("All tests passed.\n");
}