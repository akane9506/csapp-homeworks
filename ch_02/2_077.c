#include <assert.h>
#include <limits.h>
#include <stdio.h>

int mult_17(int val) { return (val << 4) + val; }
int mult_n_7(int val) { return val - (val << 3); }
int mult_60(int val) { return (val << 6) - (val << 2); }
int mult_n_112(int val) { return (val << 4) - (val << 7); }

void test_mult_fns();

int main() {
    test_mult_fns();
    return 0;
}

void test_mult_fns() {
    // Test K = 17
    assert(mult_17(10) == 10 * 17);
    assert(mult_17(0) == 0 * 17);
    assert(mult_17(-25) == 0 - 25 * 17);
    assert(mult_17(INT_MAX) == INT_MAX * 17);
    assert(mult_17(INT_MIN) == INT_MIN * 17);

    // Test K = -7
    assert(mult_n_7(10) == 10 * -7);
    assert(mult_n_7(0) == 0 * -7);
    assert(mult_n_7(-25) == -25 * -7);
    assert(mult_n_7(INT_MAX) == INT_MAX * -7);
    assert(mult_n_7(INT_MIN) == INT_MIN * -7);

    // Test K = 60
    assert(mult_60(10) == 10 * 60);
    assert(mult_60(0) == 0 * 60);
    assert(mult_60(-25) == -25 * 60);
    assert(mult_60(INT_MAX) == INT_MAX * 60);
    assert(mult_60(INT_MIN) == INT_MIN * 60);

    // Test K = 112
    assert(mult_n_112(10) == 10 * -112);
    assert(mult_n_112(0) == 0 * -112);
    assert(mult_n_112(-25) == -25 * -112);
    assert(mult_n_112(INT_MAX) == INT_MAX * -112);
    assert(mult_n_112(INT_MIN) == INT_MIN * -112);

    printf("All tests passed.\n");
}
