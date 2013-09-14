// My interpretation of section 9.4.2

#include <iostream>
// #include "Date.h" // don't try to run before you can walk...

struct Date {
  int y; // year
  int m; // month
  int d; // day of month
}; 

void add_month(Date& dd, int n);
void add_year(Date& dd, int n);

void init_day(Date& dd, int y, int m, int d) {

  if (
    (y < 2100 && y > 1900) &&
    (m < 13   && m > 0   ) &&
    (d < 32   && d > 0   )) {

    dd.y = y;
    dd.m = m;
    dd.d = d;
  }
  else {
    std::cout << "Invalid Date" << std::endl;
  }
}

void add_day(Date&dd, int n) {
  
  int last_day_of_month = 31;
  
  if (dd.d == last_day_of_month) {
    add_month(dd, 1);
    dd.d = 0;
  }
  else {
    dd.d += n;
  }
}

void add_month(Date&dd, int n) {

  int last_month_of_year = 12;

  if (dd.m == last_month_of_year) {

    add_year(dd, 1);
    dd.m = 0;
  }

  else {
    dd.m += n;
  }
}

void add_year(Date&dd, int n) {

  dd.y += n;
}

int main() {
  Date today;

  init_day(today, 2005, 6, 5);

  Date tomorrow = today;
  add_day(tomorrow, 1);

   return 0;
 }

