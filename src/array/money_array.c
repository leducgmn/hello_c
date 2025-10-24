#define length(x) (sizeof(x) / sizeof(x[0]))

#include <stdio.h>

// 1000, 2000, 5000, 10000, 20k, 50k, 100k, 200k, 500k

// tra ve so tien
void exchange_money(int *money, int face_value, int *notes, int quantity);
// tra ve so to tien
// int exchange_notes(int *money, int face_value);

int main() {
    int money = 1374;
    int face_value[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int available[] = {1, 4, 1, 5, 20, 1, 10, 10, 10};
    
    int notes = 0;
    int len = length(face_value);

    printf("so tien ban dau; %d\n", money);
    for (int i = 0; i < len; i++) {
        exchange_money(&money, face_value[i], &notes, available[i]);
        if (money == 0) {
            break;
        } /*else if (money > 0) {
            // printf("con lai so tien la: %d\n", money);
        } */
    }
    printf("tong so to da doi: %d\n", notes);
    return 0;
}

void exchange_money(int *money, int face_value, int *notes, int available) {
    int n_notes = *money / face_value;
    if (n_notes >= available) {
        n_notes = available;
    }
    if (n_notes != 0) {
        *notes = *notes + n_notes;
        *money = *money - (n_notes * face_value);
        printf("menh gia %3d: %2d to; con lai: %3d\n", face_value, n_notes, *money);
    }
}

/*
int exchange_notes(int *money, int face_value)
{
    int n_notes = *money / face_value;
    if (n_notes > 0)
    {
        printf("so to %d la %d\n", face_value, n_notes);
    }
    *money %= face_value;
    return n_notes;
}
*/