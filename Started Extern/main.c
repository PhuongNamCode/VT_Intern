#include <stdio.h>
#include "extern.h"

int a;

int testMain(); // Khai báo hàm testMain

int main() {
    printf("Main");
    printf("a = %d\n", a);
    a = 5;
    printf("a = %d\n", a);

    // Gọi hàm testMain
    testMain();
    printf("a = %p\n", &a); 
    return 0;
}
