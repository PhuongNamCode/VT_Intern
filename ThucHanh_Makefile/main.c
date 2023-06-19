#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <someone.h>

#define MAX_PEOPLE 10

void cadge(someone_t person) {
    printf("lam on lam phuoc\n");
}

void stole(someone_t person) {
    printf("!!!\n");
}

void work(someone_t person) {
    if (strcmp(person.type, "congnhan") == 0) {
        printf("%d\n", person.income_int);
    }
}

int main() {
    someone_t people[MAX_PEOPLE];
    int N = MAX_PEOPLE;  // Số người muốn tạo

    // Khởi tạo bộ sinh số ngẫu nhiên
    srand(time(NULL));

    // Tạo ngẫu nhiên N người
    for (int i = 0; i < N; i++) {
        int randomType = rand() % 3;

        if (randomType == 0) {
            strcpy(people[i].type, "anxin");
            strcpy(people[i].income_str, "tuytam");
            people[i].action = cadge;
        } else if (randomType == 1) {
            strcpy(people[i].type, "antrom");
            strcpy(people[i].income_str, "henxui");
            people[i].action = stole;
        } else {
            strcpy(people[i].type, "congnhan");
            people[i].income_int = 500000;
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
        someone_t person = people[i];
        person.action(person);
        fprintf(file, "%s - %s\n", person.type, person.income_str);
    }

    // Đóng file
    fclose(file);

    return 0;
}
