#include <assert.h>
#include <limits.h>
#include <stdio.h>

int saturating_add(int x, int y) {
    int sum = x + y;
    int x_sign = x >> 31;
    int y_sign = y >> 31;
    int sum_sign = sum >> 31;

    int pos_over = ~x_sign & ~y_sign & sum_sign;
    int neg_over = x_sign & y_sign & ~sum_sign;

    int T_MIN = 0x1 << 31;
    int T_MAX = ~T_MIN;

    int overflow = pos_over | neg_over;
    int sat_val = (pos_over & T_MAX) | (neg_over & T_MIN);

    return (overflow & sat_val) | (~overflow & sum);
}

void test_saturating_add();

int main() {
    test_saturating_add();
    return 0;
}

void test_saturating_add() {
    // No overflow
    assert(saturating_add(10, 20) == 30);
    assert(saturating_add(-10, -20) == -30);
    assert(saturating_add(1000, -500) == 500);

    // Zero cases
    assert(saturating_add(0, 0) == 0);
    assert(saturating_add(0, INT_MAX) == INT_MAX);
    assert(saturating_add(0, INT_MIN) == INT_MIN);

    // Positive overflow
    assert(saturating_add(INT_MAX, 1) == INT_MAX);
    assert(saturating_add(INT_MAX, INT_MAX) == INT_MAX);
    assert(saturating_add(2000000000, 2000000000) == INT_MAX);

    // Negative overflow
    assert(saturating_add(INT_MIN, -1) == INT_MIN);
    assert(saturating_add(INT_MIN, INT_MIN) == INT_MIN);
    assert(saturating_add(-2000000000, -2000000000) == INT_MIN);

    // Mixed signs, no overflow
    assert(saturating_add(INT_MAX, -1) == INT_MAX - 1);
    assert(saturating_add(INT_MIN, 1) == INT_MIN + 1);

    printf("All assertion tests passed! ✓\n");
}