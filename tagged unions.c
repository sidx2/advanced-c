#include <stdio.h>
#include <float.h>
#include <stdbool.h>

enum tag {
    TAG_INT,
    TAG_FLOAT,
    TAG_BOOL,
};

struct dynamic {
    enum tag t;
    union {
        int i;
        float f;
        bool b;
    } value;
};

int main() {
    struct dynamic d;
    d.value.i = 23;
    d.t = TAG_INT;
    printf("%i\n", sizeof(struct dynamic));
}