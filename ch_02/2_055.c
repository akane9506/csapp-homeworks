#include <stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%.2x", start[i]);
    }
    printf("\n");
}

void show_int(int ival) { show_bytes((byte_pointer)&ival, sizeof(int)); }
void show_float(float fval) { show_bytes((byte_pointer)&fval, sizeof(float)); }

int main(int argc, char *argv[]) {
    int ival = 4;
    float fval = 1.25;
    show_int(ival);
    show_float(fval);
}