#include <stdio.h>

int main() {
    // bai 2. viet hoa chu cai dau "le duC ANh" -> "Le Duc Anh"
    char str[] = "le duC ANh";
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 || str[i - 1] == ' ') {
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - 32;            
            // } else {
            //     if (str[i] >= 'A' && str[i] <= 'Z') {
            //         str[i] = str[i] - 32;
            //     }
            }
        } else {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                    str[i] = str[i] + 32;
            }

        }
    }
    printf("%s\n", str);
    return 0;
}