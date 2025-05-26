#include <assert.h>
#include <limits.h>
#include <stdio.h>

int divide_power2(int x, int k) {
    int sign = x >> 31;
    int bias = ((1 << k) - 1) & sign;
    return (x + bias) >> k;
}

void test_divide_power2();

int main() {
    test_divide_power2();
    return 0;
}

void test_divide_power2() {
    // Test 1: Positive number, no remainder
    assert(divide_power2(32, 3) == 4);  // 32 / 8 = 4

    // Test 2: Positive number, with remainder
    assert(divide_power2(35, 3) ==
           4);  // 35 / 8 = 4.375 → round toward zero → 4

    // Test 3: Zero
    assert(divide_power2(0, 5) == 0);  // 0 / 32 = 0

    // Test 4: Negative number, exact division
    assert(divide_power2(-16, 2) == -4);  // -16 / 4 = -4

    // Test 5: Negative number, with remainder
    assert(divide_power2(-17, 2) ==
           -4);  // -17 / 4 = -4.25 → round toward zero → -4
    assert(divide_power2(-19, 2) ==
           -4);  // -19 / 4 = -4.75 → round toward zero → -4
    assert(divide_power2(-20, 2) == -5);  // -20 / 4 = -5.0 → exact

    // Test 6: Smallest negative number (to test for edge conditions)
    assert(divide_power2(INT_MIN, 1) == INT_MIN / 2);
    assert(divide_power2(INT_MIN, 5) == INT_MIN / 32);

    // Test 7: Largest positive number
    assert(divide_power2(INT_MAX, 1) == INT_MAX / 2);
    assert(divide_power2(INT_MAX, 5) == INT_MAX / 32);

    printf("All tests passed.\n");
}