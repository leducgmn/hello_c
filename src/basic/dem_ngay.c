#include <stdio.h>

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int cal_days_of_month(int month, int year) {
    if (month != 2) {
        return days[month - 1];
    }
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0) ? 29 : 28;
}

int print_calendar(int day_of_week, int days, int month, int year) {
    printf("Lịch tháng %d năm %d\n", month, year);
    printf("Mon Tue Wed Thu Fri Sat Sun\n");
    for (int i = 0; i < day_of_week;i++) {
        printf("    ");
    }
    for (int i = 1; i <= days; i++) {
        printf("%3d ", i);
        if ((i + day_of_week) % 7 ==0) {
            printf("\n");
        }
    }
}

int cal_day_of_week(int month, int year) {
    int pre_year = year - 1;
    int day_of_week = (pre_year + (pre_year / 4 - pre_year / 100 + pre_year / 400)) % 7;
    for (int i = 1; i < month; i++) {
        day_of_week += cal_days_of_month(i, year);
    }
    return day_of_week % 7;
}


int calendar_main() {
    int month;
    int year;
    printf("Nhập tháng: ");
    scanf("%d", &month);
    printf("Nhập năm: ");
    scanf("%d", &year);
    
    if (month < 1 || month > 12) {
        printf("thang k hop le\n");
        return 0;
    }
    
    int days = cal_days_of_month(month, year);
    int day_of_week = cal_day_of_week(month, year);
    print_calendar(day_of_week, days, month,year);
    
    printf("\nThang %d nam %d co %d ngay\n", month, year, days);
    return 0; 
} 

int main() {
    int day = 4;
    int month = 6;
    int year =2026;
    char *dates[] = {"Chu Nhat", "thu Hai", "thu Ba", "thu Tu", "thu Nam", "thu Sau", "thu Bay" };
    // calendar_main();
    int day_of_week = cal_day_of_week(month, year);
    int date = (day_of_week + day) % 7;
    printf("Ngay %d thang %d nam %d la ngay %s\n", day, month, year, dates[date]);
    
} 