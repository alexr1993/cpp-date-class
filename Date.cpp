/* chapter 9.4.2 - improved date class using member functions (of a struct)
   to ensure that dates are initialised before use, an add_day member function
   is also created

*/

#include <iostream>

using namespace std;

/* A stuct is essentially an all public class - you cannot effectively impose
   invariants on it's members */
struct Date {
  int y, m, d;
  Date (int y, int m, int d); // constructor - check validity
  void add_day(int n); // incrememnt date by n days
  enum Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dev
  };
};

// Date last(2000, 12, 31); colloqially initialises last
// Date christmas = Date(1976, 12, 24); verbosely initialises christmas
// Date birthday; error - no initialisation

Date::Date(int y, int m, int d) {

  // ... need to check constraints and initialise
}

void Date::add_day(int n) {

  // need to implement
}

int main() {
  return 0;
}
