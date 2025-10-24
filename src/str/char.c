#include <stdio.h>

int main() {
    // bai 1. viet hoa moi tu   "le duc Anh" -> "LE DUC ANH"
    char str[] = "le duc anh";
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    printf("%s\n", str);
    return 0;
}