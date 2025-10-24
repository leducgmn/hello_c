#include <stdio.h>

// 1000, 2000, 5000, 10000, 20k, 50k, 100k, 200k, 500k

// tra ve so tien
int exchange_money(int money, int face_value, int *notes);
// tra ve so to tien
int exchange_notes(int *money, int face_value);


int main1() {
    int money = 1373;
    int notes = 0;
    int money500 = exchange_money( money, 500, &notes);
    int money200 = exchange_money( money500, 200, &notes);
    int money100 = exchange_money( money200, 100, &notes);
    int money50 = exchange_money( money100, 50, &notes);
    int money20 = exchange_money( money50, 20, &notes);
    int money10 = exchange_money( money20, 10, &notes);
    int money5 = exchange_money( money10, 5, &notes);
    int money2 = exchange_money( money5, 2, &notes);
    int money1 = exchange_money( money2, 1, &notes);
    printf("doi duoc %d to tien\n", notes);
}

int main2() {
    int money = 1373;
    int notes = 0;
    int note1 = exchange_notes( &money, 500);
    int note2 = exchange_notes( &money, 200);
    int note3 = exchange_notes( &money, 100);
    int note4 = exchange_notes( &money, 50);
    int note5 = exchange_notes( &money, 20);
    int note6 = exchange_notes( &money, 10);
    int note7 = exchange_notes( &money, 5);
    int note8 = exchange_notes( &money, 2);
    int note9 = exchange_notes( &money, 1);
    printf("doi duoc %d to tien\n", note1 + note2 + note3 + note4 + note5 + note6 + note7 + note8 + note9);
}

int main() {
    // main1();
    main2();
}

int exchange_money(int money, int face_value, int *notes) {
    int so_to = money / face_value;
    if (so_to > 0) {
        printf("so to %d la %d\n", face_value, so_to);
    }
    *notes += so_to;
    money %= face_value;
    return money;
}



int exchange_notes(int *money, int face_value) {
    int n_notes = *money / face_value;
    if (n_notes > 0) {
        printf("so to %d la %d\n", face_value, n_notes);
    }
    *money %= face_value;
    return n_notes;
}