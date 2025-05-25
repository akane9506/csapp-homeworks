#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *calloc(size_t nmemb, size_t size) {
    if (nmemb == 0 || size == 0) return NULL;
    if (size > SIZE_MAX / nmemb) return NULL;
    void *ptr = malloc(size * nmemb);
    if (ptr == NULL) return NULL;
    return memset(ptr, 0, size * nmemb);
}

void test_calloc();

int main() {
    test_calloc();
    return 0;
}

void test_calloc() {
    int *arr = (int *)calloc(10, sizeof(int));
    assert(arr != NULL);
    for (int i = 0; i < 10; i++) {
        assert(arr[i] == 0);
    }
    free(arr);

    // Test 2: Zero nmemb
    void *ptr1 = calloc(0, sizeof(int));
    assert(ptr1 == NULL);

    // Test 3: Zero size
    void *ptr2 = calloc(10, 0);
    assert(ptr2 == NULL);

    // Test 4: Overflow detection
    size_t huge = SIZE_MAX / 2 + 1;
    void *ptr3 = calloc(2, huge);
    assert(ptr3 == NULL);
    printf("All tests passed.\n");
}
