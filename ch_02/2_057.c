#include <limits.h>
#include <stdio.h>
typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%.2x", start[i]);
    }
    printf("\n");
}

void show_short(short sval) { show_bytes((byte_pointer)&sval, sizeof(short)); }

void show_long(long lval) { show_bytes((byte_pointer)&lval, sizeof(long)); }

void show_double(double dval) {
    show_bytes((byte_pointer)&dval, sizeof(double));
}

void show_pointer(void* start) {
    show_bytes((byte_pointer)start, sizeof(void*));
}

int main(int argc, char* argv[]) {
    short sval = 1024;
    long lval = INT_MAX;
    double dval = 0.125;
    show_short(sval);
    show_double(dval);
    show_long(lval);
    show_pointer(&sval);
    return 0;
}