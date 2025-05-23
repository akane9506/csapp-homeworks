#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    unsigned mask = ~(0xFF << (i << 3));  // create a mask
    unsigned replace = b << (i << 3);     // pad the target byte
    return (x & mask) | replace;
}

int main(int argc, char* argv[]) {
    unsigned res_1 = replace_byte(0x12345678, 2, 0xAB);
    printf("%x\n", res_1);
    unsigned res_2 = replace_byte(0x12345678, 0, 0xAB);
    printf("%x\n", res_2);
    return 0;
}