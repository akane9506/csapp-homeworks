#include <stdio.h>

int int_size_is_32() {
    int set_msb = 1 << 31;
    /* C standard does warn full-width shift */
    // int beyond_msb = 1 << 32;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

int int_size_is_32_safe() {
    int set_msb = 1 << 15;
    set_msb <<= 15;
    set_msb <<= 1;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

int main() {
    int valid_int = int_size_is_32_safe();
    if (valid_int)
        printf("int is 32-bit on this machine\n");
    else
        printf("int is not 32-bit on this machine\n");
}
