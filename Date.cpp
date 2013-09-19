/* chapter 9.7.4 making some member functions const, making some 
 * helper functions (which are not members) to practice useing 
 * the const constraint
 *
 * Also overloaded << operator to write Date objects to ostreams
 * nicely
 */

#include <iostream>

using namespace std;

/* A stuct is essentially an all public class - you cannot effectively impose
   invariants on it's members */
class Date {
  
public:

  Date (int y, int m, int d); // constructor - check validity
  void add_day(int n); // incrememnt date by n days
  void add_month(int n);
  void add_year(int n);

  int month() const { return m; }
  int day()  const  { return d; }
  int year() const { return y; }
  
  enum Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
  };
  
  class Invalid {};

private:
  int y, m, d;
};

// Date last(2000, 12, 31); colloqially initialises last
// Date christmas = Date(1976, 12, 24); verbosely initialises christmas
// Date birthday; error - no initialisation

Date::Date(int y, int m, int d) {


  if (d <= 0) throw Invalid();

  /* ignoring leap year problem for now */
  switch (m) {

    case Date::apr: case Date::jun: case Date::sep: case Date::nov:
      if (d > 30) throw Invalid();
      break;

    case Date::feb:
      if (d > 29) throw Invalid();
      break;

    default: // month must be invalid
      if (d > 31) throw Invalid();
  }

  Date::y = y;
  Date::m = m;
  Date::d = d;
  // ... need to check constraints and initialise
}

void Date::add_year(int n) {
  Date::y += n;
}

void Date::add_month(int n) {

  Date::m = (Date::m + n) % 12;
  this->add_year(n / 12); // truncation intentional
}

void Date::add_day(int n) {



  int total = Date::d + n;
  /* ignoring leap year problem for now */
  switch (Date::m) {

    case Date::apr: case Date::jun: case Date::sep: case Date::nov:
      if (total > 30) {
        this->add_month(1);
        this->add_day(total - 30);
      }
      else Date::d = total;
      break;

    case Date::feb:
      if (total > 29) {
        this->add_month(1);
        this->add_day(total - 29);
      }
      else  Date::d = total;

      break;

    default: // month must be invalid
      if (total > 31) {
        this->add_month(1);
        this->add_day(total - 31);       
      }
      else Date::d = total;

  }

}

Date tomorrow(const Date& d) {
  Date tmrw = d;
  tmrw.add_day(1);
  return tmrw;
}

ostream& operator<<(ostream& os, Date d) {
  return os << d.year() << "-" << d.month() << "-" << d.day();
}

int main() {

  Date a(2000, 3, 12);
  a.add_year(2);
  a.add_month(24);
  a.add_day(23);
  Date b = tomorrow(a);
  cout << a << endl;
  cout << b << endl;
  return 0;
}
