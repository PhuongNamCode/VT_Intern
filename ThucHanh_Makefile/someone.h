#ifndef SOMEONE_H
#define SOMEONE_H

typedef struct someone_t someone_t;

struct someone_t {
    char type[20];
    union {
        char income_str[20];
        int income_int;
    };
    void (*action)(someone_t);
};

void cadge(someone_t person);
void stole(someone_t person);
void work(someone_t person);

#endif  // SOMEONE_H
