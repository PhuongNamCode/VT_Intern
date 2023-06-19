#include <stdio.h>
#include "someone.h"

void cadge(someone_t person) {
    printf("lam on lam phuoc\n");
}

void stole(someone_t person) {
    printf("!!!\n");
}

void work(someone_t person) {
    printf("%d\n", person.income_int);
}
