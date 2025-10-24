#include <stdio.h>
#include <stdbool.h>
// ktra xem so n > 0 co so doi xung hay k?
VD: 121, 11, 12321
int tim_M(int n);

int main1() {
    int n = 112321;
    int m = tim_M(n);
    int i = n;
    int n1;
    int n2;
    bool is_palindrome = 1;
    if (n >= 0 && n <= 9) {
        printf("n=%d la so doi xung\n",n);
        return 0;
    }
    while(true){
        n1 = n / m;
        n2 = n % 10;
        if (n1 == n2) {
            n = n / 10;
            m /= 10;
            if (m ==0) {
                break;
            }
            n = n % m;
            m /= 10;
            
        } else {
            is_palindrome = 0;
            break;
        }
        
    }
    if (is_palindrome) {
        printf("n=%d la so doi xung\n",i );
    } else {
        printf("n=%d khong la so doi xung\n",i );
    }
}

int tim_M(int n) {
    int m = 1;
    while (n != 0) {
        n = n / 10;
        if (n == 0) {
            break;
        }
        m *= 10;
    }
    return m;
}



bool is_palindrome2(int n);

int main() {
    int n = 123454321;
    if (is_palindrome2(n)) {
        printf("n = %d is a palindrome\n", n);
    } else {
        printf("n = %d is not a palindrome\n", n);
    }
}

int reverse(int n) {
    int reverse = 0;
    while(n != 0){
        reverse = reverse*10 + (n % 10); 
        n = n / 10;
    } 
    return reverse;
}
bool is_palindrome2(int n) {
    return n == reverse(n);

}