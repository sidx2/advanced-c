#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int foo(int x, int y) {
    return x + y;
}

bool predicate(int x) {
    return x && x % 3 == 0;
}

void print_if(int a[10], bool (*pred)(int)) {
    for (int i = 0; i < 10; i++) {
        if (pred(a[i])) {
            printf("%i\n", i);
        }
    }
}

int cmp(const void *a, const void *b) {
    return (*((int*)b)) - (*((int*)a));
}

int main() {
    int *a = malloc(sizeof(int) * 10);
    for(int i = 0; i < 10; i++) a[i] = i;
    
    bool (*p)(int) = predicate;
    
    print_if(a, p);
    
    qsort(a, (size_t)10, sizeof(int), cmp);
    
    printf("------------------\n");
    for (int i = 0; i < 10; i++) {
        printf("%i\n", a[i]);
    }
}