#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// bai 3. char str[100] . chuan hoa dau cau trong cau
bool is_punctuation(char a) {
    return (a == '.' ||a == ',' ||a == '!' ||a == '?');
}

bool is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

bool is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

char to_upper(char c) {
    if (is_lower(c)) return c - 32;
    return c;
}

char to_lower(char c) {
    if (is_upper(c)) return c + 32;
    return c;
}

void standardize(char str[]) {
    bool viet_hoa = true;
    for (int i = 0; str[i] != '\0'; i++) {
        if (viet_hoa && is_lower(str[i])) {
            str[i] = to_upper(str[i]);
            viet_hoa = false;
        }
        else if (!viet_hoa && is_upper(str[i])) {
            str[i] = to_lower(str[i]);
        }
        if (str[i] == '.' || str[i] == '!' || str[i] == '?') {
            viet_hoa = true;
        }
        // else if (str[i] == ',') {
        //     viet_hoa = false;
        // }
    }
}

void shift_left(char str[], int from) {
    for (int j = from; str[j] != '\0'; j++) {
        str[j] = str[j + 1];
    } 
}

void shift_right(char str[], int from) {
    int len = strlen(str);
    for (int j = len; j > from; j--) {
        str[j] = str[j - 1];
    }
    printf("len=%d\n", len);
    str[from] = ' ';
}

void remove_spaces(char str[]) {
    int i = 0;
    int j = 0;
    bool space = false;
    while (str[i] == ' ') {
        i++;
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
            space = false;
        } else if (!space) {
            str[j++] = ' ';
            space = true;
        }
    }
    printf("'%s'\n", str);

    if (j > 0 && str[i - 1] == ' ') { 
        j--;
    }
    str[j] = '\0';
    printf("'%s'\n", str);

}

int main() {
    char str[100] = "  hom nay troi   mua  .  ngay mai ,Troi nang,";
    remove_spaces(str);
    for (int i = 0; str[i] != '\0';) {
        if (str[i] == ' ' && is_punctuation(str[i + 1])) {
            shift_left(str, i);                                                     
        } else if (is_punctuation(str[i])) {
            if (str[i + 1] == '\0') { 
                str[i] = '\0'; 
            } else if (str[i + 1] != ' ') {
                shift_right(str, i + 1);
            } else {
                i++;
            }
        } else {
            i++;
        }
    }
    while (str[0] == ' ') {
        shift_left(str, 0);
    }
    int len = strlen(str);
    printf("len=%d\n", len);
    if (!is_punctuation(str[len -1])) {
        str[len] = '.';
        str[len + 1] = '\0';
    }
    standardize(str);
    printf("%s\n", str);
    return 0;
}

