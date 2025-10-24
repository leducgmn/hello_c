#include <stdio.h>
#include <stdbool.h>

bool b_true() {
    printf("true ");
    return true;
}

bool b_false() {
    printf("false ");
    return false;
}

int main() {
    if (b_true() || b_false()) {
        printf("-> done!\n");
    } else {
        printf("-> false!\n");
    }
    if (b_false() || b_true()) {
        printf("-> done!\n");
    } else {
        printf("-> false!\n");
    }
    if (b_true() && b_false()) {
        printf("-> done!\n");
    } else {
        printf("-> false!\n");
    }
    if (b_false() && b_true()) {
        printf("-> done!\n");
    } else {
        printf("-> false!\n");
    }
}