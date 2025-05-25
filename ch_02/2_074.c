#include <assert.h>
#include <limits.h>
#include <stdio.h>

int tsub_ok(int x, int y) {
    int sub = x + (~y + 1);
    int sx = x >> 31;
    int sy = y >> 31;
    int ssub = sub >> 31;
    int overflow = (sx ^ sy) & (sx ^ ssub);
    return !overflow;
}

void test_tsub_ok();

int main() {
    test_tsub_ok();
    return 0;
}

void test_tsub_ok() {
    // Test Case 1: Normal cases without overflow
    assert(tsub_ok(5, 3) == 1);      // 5 - 3 = 2
    assert(tsub_ok(-5, -3) == 1);    // -5 - (-3) = -2
    assert(tsub_ok(0, 0) == 1);      // 0 - 0 = 0
    assert(tsub_ok(100, -50) == 1);  // 100 - (-50) = 150
    assert(tsub_ok(-100, 50) == 1);  // -100 - 50 = -150

    // Test Case 2: Edge cases at boundaries (should not overflow)
    assert(tsub_ok(INT_MAX, 0) == 1);  // INT_MAX - 0 = INT_MAX
    assert(tsub_ok(INT_MIN, 0) == 1);  // INT_MIN - 0 = INT_MIN
    assert(tsub_ok(0, INT_MAX) == 1);  // 0 - INT_MAX = -INT_MAX

    // Test Case 3: Positive overflow cases
    assert(tsub_ok(INT_MAX, -1) ==
           0);  // INT_MAX - (-1) = INT_MAX + 1 (overflow)
    assert(tsub_ok(INT_MAX, -2) ==
           0);  // INT_MAX - (-2) = INT_MAX + 2 (overflow)
    assert(tsub_ok(1000000000, -1500000000) ==
           0);  // Large positive - large negative

    // Test Case 4: Negative overflow cases
    assert(tsub_ok(INT_MIN, 1) == 0);  // INT_MIN - 1 (underflow)
    assert(tsub_ok(INT_MIN, 2) == 0);  // INT_MIN - 2 (underflow)
    assert(tsub_ok(-1000000000, 1500000000) ==
           0);  // Large negative - large positive

    // Test Case 5: Boundary cases that should work
    assert(tsub_ok(INT_MAX - 1, -1) == 1);  // (INT_MAX-1) - (-1) = INT_MAX
    assert(tsub_ok(INT_MIN + 1, 1) == 1);   // (INT_MIN+1) - 1 = INT_MIN

    // Test Case 6: Special edge cases
    assert(tsub_ok(INT_MAX, INT_MAX) == 1);  // INT_MAX - INT_MAX = 0
    assert(tsub_ok(INT_MIN, INT_MIN) == 1);  // INT_MIN - INT_MIN = 0
    assert(tsub_ok(INT_MIN, INT_MAX) == 0);  // INT_MIN - INT_MAX (underflow)

    // Test Case 7: Zero cases
    assert(tsub_ok(0, INT_MIN) == 0);
    assert(tsub_ok(-1, INT_MIN) == 1);

    // Test Case 8: Same sign subtractions (should generally be safe)
    assert(tsub_ok(10, 5) == 1);    // Both positive
    assert(tsub_ok(-10, -5) == 1);  // Both negative
    assert(tsub_ok(-5, -10) == 1);  // Both negative, result positive

    printf("All tests passed!\n");
}