1 week = 7 days
1 year = 365 / 366 (leap year) days
leap year = year % 400 == 0 || year % 4 == 0 && year % 100 != 0

1/1/1 -> Monday
8/1/1 -> Monday

M T W T F S S
1 2 3 4 5 6 7
8

1/1/2 = 1/1/1 + 1 year = Monday + 1 = Tuesday

1/1/1000 = 1/1/1 + 999 years = Monday + (n days) % 7 = day of week
999 year 
= (999 * 365 + (leap year)) % 7
= (999 * 365 + (999 / 4 - 999 / 100 + 999 / 400)) % 7
= (999 + (999 / 4 - 999 / 100 + 999 / 400)) % 7
= (999 + ()) % 7
=  % 7 = 3


1/1/2025 = Monday + 2024 year

2025 year
= (2024 + (2024 / 4 - 2024 / 100 + 2024 / 400)) % 7
= 2

1/10/2025
= 1/1/2025 + 9 months
= Wednesday + (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30) % 7
= Wednesday + (3 + 0 + 3 + 2 + 3 + 2 + 3 + 3 + 2) % 7
= Wednesday + 0
= Wednesday

Mon Tue Wed Thu Fri Sat Sun
          1   2   3   4   5
  6   7   8   9  10  11  12
 13  14  15  16  17  18  19
 20  21  22  23  24  25  26
 27  28  29  30  31 
Thang 10 nam 2025 co 31 ngay