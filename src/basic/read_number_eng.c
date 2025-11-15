#include <stdio.h>
#include <stdbool.h>

char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *tens_word[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

typedef enum {
    UNITS = 1,
    TENS,
    HUNDREDS,
} Place;

// doc 2 chu so
void read_digit(int tens, int units) {
    if (tens == 0) {
        if (units > 0)
            printf("%s", ones[units]);
    } else if (tens == 1) {
        printf("%s", teens[units]);
    } else {
        printf("%s", tens_word[tens]);
    
    if (units > 0)
        printf("-%s", ones[units]);
    }
}

// doc 3 chu so
void read_group(int number, char* class_name) {
    int hundreds = number / 100;
    int units = number % 10;
    int tens = number / 10;
    tens = tens % 10;
    
    if (hundreds > 0) {
        printf("%s hundred ", ones[hundreds]);
        if (tens == 0 && units > 0)
            printf("and ");
    }

    read_digit(tens, units);

    if (class_name[0] != '\0')
        printf(" %s ", class_name);
}

int main() {
    int number;
    printf("Nhập số: ");
    scanf("%d", &number);

    if (number == 0) {
        printf("zero\n");
        return 0;
    }

    int class[5];
    char *class_name[] = {"", "thousand", "million", "billion", "trillion"};
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
        read_group(class[i], class_name[i]);
    }
    printf("\n");
}