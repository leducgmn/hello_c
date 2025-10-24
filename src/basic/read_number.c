#include <stdio.h>

void read_digit(int digit, int position) {
    switch (digit) {
        case 0:
            printf("không ");
            break;
        case 1:
            printf("một ");
            break;
        case 2:
            printf("hai ");
            break;
        case 3:
            printf("ba ");
            break;
        case 4:
            printf("bốn ");
            break;
        case 5:
            printf("năm ");
            break;
        case 6:
            printf("sáu ");
            break;
        case 7:
            printf("bảy ");
            break;
        case 8:
            printf("tám ");
            break;
        case 9:
            printf("chín ");
            break;
        default:
            break;
    }
}

void read_class(int number, char* class_name) {
    int hundreds = number / 100;
    int tens = number / 10;
    tens = tens % 10;
    int units = number % 10;
    read_digit(hundreds, 3);
    printf("trăm ");
    read_digit(tens, 2);
    printf("mươi ");
    read_digit(units, 1);
    printf("%s ", class_name);
}

int main() {
    int number = 107218300; //147 258 369
    int class[5];
    char* class_name[] = {"", "nghìn", "triệu", "tỉ", "nghìn tỉ"};
    int remainder;
    int count = 0;
    while (number != 0) {
        remainder = number % 1000;
        class[count++] = remainder;
        number = number / 1000;
        // printf("number = %d; remaider = %d\n", number, remainder);
    }
    for (int i = count - 1; i >= 0; i-- ) {
        // printf("%d\n", class[i]);
        read_class(class[i], class_name[i]);
    }
    printf("\n");
}