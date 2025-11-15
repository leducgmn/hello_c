#include <stdio.h>
#include <stdbool.h>

typedef enum {
    UNITS = 1,
    TENS,
    HUNDREDS,
} Place;

void read_digit(int digit, int place, int tens, int units) {
    switch (digit) {
        case 0: // 0 o hang tram => doc la khong khi co so dung truoc 0, neu k thi se bo qua so 0
            if (place == HUNDREDS) {
                printf("không ");
            } else if (place == UNITS && tens > 1) {
                printf("mươi ");
            } 
            break;
        case 1:
            if (place == TENS) {
                printf("mười ");
            } else if (place == UNITS && tens >= 2) {
                printf("mốt ");
            } else {
                printf("một ");
            }
            break;
        case 2:
            printf("hai ");
            break;
        case 3:
            printf("ba ");
            break;
        case 4:
            if (place == UNITS && tens > 1) {
                printf("tư ");
            } else {
                printf("bốn ");
            }
            break;
        case 5:
            if (place == UNITS && tens >= 1) {
                printf("lăm ");
            } else {
                printf("năm ");
            }
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

void read_group(int number, char* class_name, bool is_start) {
    int hundreds = number / 100;
    int units = number % 10;
    int tens = (number / 10) % 10;
    if (hundreds != 0 || !is_start) {
        read_digit(hundreds, HUNDREDS, tens, units);
        printf("trăm ");
    }
    if (tens > 1) {
        read_digit(tens, TENS, tens, units);
        printf("mươi ");
    } else if (tens == 1) {
        read_digit(tens, TENS, tens, units);
    } else if (units != 0 && (!is_start || hundreds != 0)) { 
        printf("lẻ ");
    }   
    read_digit(units, UNITS, tens, units);
    printf("%s ", class_name);
}

int main() {
    int number;
    printf("Nhập số: ");
    scanf("%d", &number);
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
    // neu i = count - 1 thi khong doc so dau tien
    // if (i == count - 1) {}
    // 
    for (int i = count - 1; i >= 0; i-- ) {
        int is_start = i == count - 1;
        // printf("\n%03d: ", class[i]);
        // printf("%d\n", i);
        read_group(class[i], class_name[i], is_start);
    }
    printf("\n");
}