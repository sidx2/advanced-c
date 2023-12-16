#include <stdio.h>
#include <stdint.h>

void* my_memset(void* data, int val, size_t n) {
    uint8_t* data_as_bytes = data;
    for (int i = 0; i < n; i++) {
        data_as_bytes[i] = val;
    }
    return data;
}

void map(void *xs, int n, int size, void (*f)(void*)) {
    uint8_t *xs_as_uint8_t = (uint8_t*)xs;
    for (int i = 0; i < n; i++) {
        f(&xs_as_uint8_t[i * size]);
    }
}

int sqr(void *x) {
    int *p = x;
    *p = *p * *p;
}

int main() {
    int xs[5] = {1, 2, 3, 4, 5};
    
    for (int i = 0; i < 5; i++) {
        printf("%i ", xs[i]);
    }
    printf("\n");
    
    // my_memset(xs, 0, sizeof(xs));
    
    for (int i = 0; i < 5; i++) {
        printf("%i ", xs[i]);
    }
    printf("\n------------------------\n");
    
    map(xs, 5, sizeof(int), sqr);
    for (int i = 0; i < 5; i++) {
        printf("%i ", xs[i]);
    }
}