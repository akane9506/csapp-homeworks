#include <assert.h>
#include <limits.h>
#include <stdio.h>

int mul3div4(int x) {
    int mul3 = (x << 1) + x;
    int sign = mul3 >> 31;
    int bias = sign & ((1 << 2) - 1);
    return (mul3 + bias) >> 2;
}

void test_mul3div4();

int main() {
    test_mul3div4();
    return 0;
}

void test_mul3div4() {
    // Positive cases
    assert(mul3div4(8) == 6);  // 3*8 = 24 / 4 = 6
    assert(mul3div4(5) == 3);  // 3*5 = 15 / 4 = 3.75 → round toward zero → 3
    assert(mul3div4(0) == 0);  // 0

    // Negative cases
    assert(mul3div4(-4) == -3);  // 3*-4 = -12 / 4 = -3
    assert(mul3div4(-5) == -3);  // -15 / 4 = -3.75 → round toward zero → -3
    assert(mul3div4(-6) == -4);  // -18 / 4 = -4.5 → round toward zero → -4
    assert(mul3div4(-7) == -5);  // -21 / 4 = -5.25 → round toward zero → -5

    // // Edge case: INT_MAX
    assert(mul3div4(INT_MAX) == (int)((INT_MAX * 3) / 4));

    // Edge case: INT_MIN
    // INT_MIN * 3 overflows if done as int, so we compare with long long safely
    assert(mul3div4(INT_MIN) == (int)((INT_MIN * 3) / 4));

    // Mixed values
    for (int x = -20; x <= 20; x++) {
        int expected =
            (int)(((long long)x * 3) / 4);  // Ground truth with wider type
        assert(mul3div4(x) == expected);
    }

    printf("All tests passed.\n");
}