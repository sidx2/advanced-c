#include <stdio.h>
#include <stdarg.h>

int sum_all(int count, ...) {
    va_list v_args;
    va_start(v_args, count);
    
    int sum = 0;
    for (int i = 0; i < count; i++) {
        int arg = va_arg(v_args, int);
        sum += arg;
    }
    
    va_end(v_args);
    return sum;
}

int main() {
    printf("sum = %i\n", sum_all(2, 34, 35));
}