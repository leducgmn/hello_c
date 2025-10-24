#include <stdio.h>

// signature
// khai bao(declaration): <kieu tra ve> <ten ham> ([kieu input])
int count_digit_ref(int *n, int base);
int count_digit_value(int n, int base); 

int main() {
    int n = 123456;
    int base = 10;
    int count = count_digit_ref(&n, base); // su dung ham(usage)
    // pass by value 
    printf("main: so n=%d co %d chu so\n", n, count);
}

// dem so chu so cua so n 
// dem so chu so cua so am 
// chia so n cho co so (10), dem so lan chia, chia den khi kqua=0 thi dung lai n>0 => n/10 => dem++
int count_digit_ref(int *n, int base) { //dinh nghia(definition)
//    pass by reference
    if (*n == 0) {
        return 1;
    }
    int count = 0;
    while (*n != 0) {
        *n = *n / base;
        count++;
    }
    printf("so n=%d co %d chu so\n", *n, count);      
    return count;

}

int count_digit_value(int n, int base) {
//    pass by reference
    if (n == 0) {
        return 1;
    }
    int count = 0;
    while (n != 0) {
        n =  n / base;
        count++;
    }
    printf("so n=%d co %d chu so\n", n, count);      
    return count;

}

