#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PEOPLE 10

typedef struct Someone_t Someone_t;

struct Someone_t {
    char type[20];
    union {
        char income_str[20];
        int income_int;
    };
    void (*action)(Someone_t);
    char action_str[100];  // Thêm trường action_str để lưu chuỗi hành động
};

void cadge(Someone_t person) {
    printf("lam on lam phuoc\n");
}

void stole(Someone_t person) {
    printf("!!!\n");
}

void work(Someone_t person) {
    printf("%d\n", person.income_int);
}

int main() {
    Someone_t people[MAX_PEOPLE];
    int N = MAX_PEOPLE;  // Số người muốn tạo

    // Khởi tạo bộ sinh số ngẫu nhiên
    srand(time(NULL));

    // Tạo ngẫu nhiên N người
    for (int i = 0; i < N; i++) {
        int randomType = rand() % 3;

        if (randomType == 0) {
            strcpy(people[i].type, "anxin");
            strcpy(people[i].income_str, "tuytam");
            strcpy(people[i].action_str, "lam on lam phuoc");
            people[i].action = cadge;
        } else if (randomType == 1) {
            strcpy(people[i].type, "antrom");
            strcpy(people[i].income_str, "henxui");
            strcpy(people[i].action_str, "!!!");
            people[i].action = stole;
        } else {
            strcpy(people[i].type, "congnhan");
            people[i].income_int = 500000;
            sprintf(people[i].action_str, "%d", people[i].income_int);
            people[i].action = work;
        }
    }

    // Mở file "output.txt" để ghi kết quả
    FILE* file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return 1;
    }

    // Duyệt mảng và thực hiện hàm action của mỗi người
    for (int i = 0; i < N; i++) {
        Someone_t person = people[i];
        person.action(person);
        fprintf(file, "%s - %s\n", person.type, person.action_str); // Ghi cả kiểu người và chuỗi hành động vào file
    }

    // Đóng file
    fclose(file);

    return 0;
}
