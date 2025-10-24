#include <stdio.h>
int main() {
// Bài 1: Tính S(n) = 1 + 1.2 + 1.2.3 + … + 1.2.3….N
// int S2 = 0;
// int S = 1;
// int n = 3;
// for (int i=1; i <= n; i++) {
//     S = S * i;
//     S2 = S2 + S;
// }
// printf("S2=%d\n",S2);


// Bài 2: Tính tổng tất cả các “ ước số” của số nguyên dương n
// int S = 0;
// int n = 5;
// for (int i = 1; i <= n; i++) {
//     if (n % i == 0) {
//         S = S + i;
//     printf("uoc so cua n la=%d\n",i);
//     }
// }
// printf("tong cac uoc so cua n la=%d\n", S, n);
// Bài 3: Cho n là số nguyên dương. Hãy tìm giá trị nguyên dương k lớn nhất sao cho S(k)<n.
//        Trong đó chuỗi k được định nghĩa như sau: S(k) = 1 + 2 + 3 + … + k
int n = 5;
int S = 0;
int k= 1;


for (; k < n; k++) {
   if (S + k > n) {
        k = k - 1;    
        break;
    }
    S += k;
}
printf("S=%d\n k=%d\n", S, k);
return 0;
}

