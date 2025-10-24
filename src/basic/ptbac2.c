#include <stdio.h>
#include <math.h>

void ptrinh_bac_1(double a,double b);

void ptrinh_bac_2(double a, double b, double c);

int main() {
    //ax^2 + bx +c = 0
    double a = 0;
    double b = 2;
    double c = 0;
    if (a == 0) {
        printf("ptrinh la ptrinh bac 1\n");
        ptrinh_bac_1(b, c);
    } else {
        printf("ptrinh la ptrinh bac 2\n");
        ptrinh_bac_2(a, b, c);
    }    
}

// ax + b = 0
void ptrinh_bac_1(double a,double b) {
    if (a != 0) {
        double x = -b/a;
        printf("nghiem cua ptr la x=%f\n", x);
        return;
    }    
    if (b == 0) {
        printf("ptr co vo so nghiem\n"); 
    } else {
        printf("ptr vo nghiem\n");
    }
     
}
// ax^2 + bx + c = 0
void ptrinh_bac_2(double a, double b, double c) {
    double delta = b*b - 4*a*c;
    if (delta < 0) {
        printf("ptr vo nghiem");
        return;
    }
    if (delta == 0) {
        double x = -b/(2*a);
        printf("ptr co nghiem kep la x=%f",x);
        return;
    }
    double x1 = (-b + sqrt(delta))/(2*a);
    double x2 = (-b - sqrt(delta))/(2*a);
    printf("ptr co 2 nghiem x1=%f x2=%f\n", x1, x2);
}


