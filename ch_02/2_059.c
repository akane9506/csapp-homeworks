#include <stdio.h>

unsigned combine_bytes(unsigned x, unsigned y) {
    unsigned a = x & 0xFF;        // preserve the least significant byte
    unsigned b = y & 0xFFFFFF00;  // remove the least significant byte
    return a | b;
}

int main(int argc, char* argv[]) {
    unsigned result = combine_bytes(0x89ABCDEF, 0x76543210);
    printf("%x\n", result);
    return 0;
}