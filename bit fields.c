#include <stdio.h>

struct foo {
    int first_4 : 4; // 4 bits
    int next_4  : 4; // 4 bits
    int alone   : 1; // 1 bits
    int rest    : 7; // 7 bits
};

struct bar {
    char c_0_3  : 4;
    char c_4_7  : 4;
    char c2_0_3 : 4;
    char c2_4_7 : 4;
    
    short s     : 1;
};

int main() {
    struct foo f;
    f.first_4 = 15;
    f.alone = 1;
    f.rest = 127;
    
    printf("%zu", sizeof(struct foo));
    printf("%zu", sizeof(struct bar));
}