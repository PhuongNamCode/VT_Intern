// File main.c

#include <stdio.h>
#include "library.h"

int main() {
    int a = 5;
    int b = 3;
    int result;

    result = add(a, b);
    printf("Sum: %d\n", result);

    result = subtract(a, b);
    printf("Difference: %d\n", result);

    return 0;
}
