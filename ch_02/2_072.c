#include <memory.h>

void copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes >= (int)sizeof(val)) {
        memcpy(buf, (void *)&val, sizeof(val));
    }
}