#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// bai 3. char str[100] . chuan hoa dau cau trong cau

bool is_punctuation(char c) {
    return (c == '.' || c == ',' || c == '!' || c == '?');
}
bool is_whitespace(char c) {
    return (c == ' ' || c == '\t');
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
    bool uppercase = true;
    for (int i = 0; str[i] != '\0'; i++) {
        if (uppercase && is_lower(str[i])) {
            str[i] = to_upper(str[i]);
            uppercase = false;
        } else if (!uppercase && is_upper(str[i])) {
            str[i] = to_lower(str[i]);
        } 
        if (str[i] == '.' || str[i] == '!' || str[i] == '?' || str[i] =='\n') {
            uppercase = true;
        }
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
    str[len + 1] = '\0';
}

void remove_spaces(char str[]) {
    int i = 0;
    int j = 0;
    bool space = false;
    while (is_whitespace(str[i])) {
        i++;
    }
    for (; str[i] != '\0'; i++) {
        if (!is_whitespace(str[i])) {
            str[j++] = str[i];
            space = false;
        } else if (!space) {
            str[j++] = ' ';
            space = true;
        }
    }
    printf("%3d: '%s'\n", __LINE__, str);

    if (j > 0 && str[i - 1] == ' ') { 
        j--;
    }
    str[j] = '\0';
    printf("%3d: '%s'\n", __LINE__, str);


}

void them_dau_cham_truoc_xuong_dong(char str[]) {
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] == '\n' && !is_punctuation(str[i - 1])) {
            shift_right(str, i);
            str[i - 1] = '.';
            i++;     
        }
    }
    printf("%3d: '%s'\n", __LINE__, str);

}

void xoa_khoang_trang_sau_xuong_dong(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        while (str[i] == '\n' && str[i + 1] == ' ') {
            shift_left(str, i + 1);
        }
    }
    printf("%3d: '%s'\n", __LINE__, str);
}

// void

int main() {
    char str[100] = "\n  hom    nay \n \t\t\ttroi\t  mua  \n nGay mai ,Troi nang,";
    // char str[100] = "Hom nay troi\tmua.\nNgay mai, troi nang.";

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

    them_dau_cham_truoc_xuong_dong(str);
    xoa_khoang_trang_sau_xuong_dong(str);

    // while (str[0] == ' ') {
    //     shift_left(str, 0);
    // }
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

