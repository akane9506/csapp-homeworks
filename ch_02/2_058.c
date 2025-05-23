#include <stdio.h>

int is_little_endian() {
    int ival = 0xFF;
    unsigned char *ptr = (unsigned char *)&ival;
    if (ptr[0] == 0xFF) return 1;
    return 0;
}

int main(int argc, char *argv[]) {
    int result = is_little_endian();
    if (result == 1)
        printf("This is a little endian machine\n");
    else
        printf("This is a big-endian machine\n");
    return 0;
}