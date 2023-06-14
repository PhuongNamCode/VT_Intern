#include <stdio.h>
#include "extern.h"

extern int a;
int testMain() {
    printf("Testing");
    printf("a = %d\n", a);
    a = 6;
    printf("a = %p\n", &a); 
    return 0;
}
