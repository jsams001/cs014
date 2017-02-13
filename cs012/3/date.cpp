#include <iostream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

class Date
{
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
 ­      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).

       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/1/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 1, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-­leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};

Date::Date() {
   
   month = 1;
   day = 1;
   monthName = "January";
   year = 2000;
}

Date::Date(unsigned m, unsigned d, unsigned y) {
   
   bool dchange = false; 
   bool mchange = false;
   
   if(m < 1) {
      month = 1;
      mchange = true;
   }
   else if (m > 12) {
      month = 12;
      mchange = true;
   }
   else
      month = m;
   
   if (d > daysPerMonth(month, y)) {
      day = daysPerMonth(month,y);
      dchange = true;
   }
   else if (d < 1) {
      day = 1;
      dchange = true;
   }
   else 
      day = d;
      
   year = y;
   
   if((mchange && dchange) || dchange) 
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   else if (mchange)
      cout << "Invalid month name: the Date was set to " << month << "/" << day << "/" << year << "." << endl;
      
   monthName = name(month);
   
}

Date::Date(const string &mn, unsigned d, unsigned y) {
   
   bool dchange = false;
   bool mchange = true;
   
   if(islower(mn.at(0))) {
      if(mn == "january")
         monthName = name(1);
      if(mn == "february")
         monthName = name(2);
      if(mn == "march")
         monthName = name(3);
      if(mn == "april")
         monthName = name(4);
      if(mn == "may")
         monthName = name(5);
      if(mn == "june")
         monthName = name(6);
      if(mn == "july")
         monthName = name(7);
      if(mn == "august")
         monthName = name(8);
      if(mn == "september")
         monthName = name(9);
      if(mn == "october")
         monthName = name(10);
      if(mn == "november")
         monthName = name(11);
      if(mn == "december")
         monthName = name(12);
   }
   else
      monthName = mn;
      
   for(unsigned int i = 0; i < MonthNames.size(); ++i) {
      if(monthName == MonthNames.at(i))
         mchange = false;
   }
      
   year = y;
   month = number(monthName);
   
   if(d > daysPerMonth(month, y)) {
      day = daysPerMonth(month,y);
      dchange = true;
   }
   else if(d < 1) {
      day = 1;
      dchange = true;
   }
   else 
      day = d;
    
   if(mchange) {
      monthName = "January";
      month = 1;
      day = 1;
      year = 2000;
      cout << "Invalid month name: the Date was set to " << month << "/" << day << "/" << year << "." << endl;
   }
   else if(dchange) 
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
}

void Date::printNumeric() const {
   
   cout << month << "/" << day << "/" << year;
   return;
}

void Date::printAlpha() const {
   
   cout << monthName << " " << day << ", " << year;
   return;
}

bool Date::isLeap(unsigned y) const {
   
   if (y % 4 == 0) {
      if (y % 400 == 0) {
         return true;
      }
      else if (y % 100 == 0) {
         return false;
      }
      else {
         return true;
      }
   }
   return false;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const { 
   
   if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
      return 31;
   else if (m == 4 || m == 6 || m == 9 || m == 11)
      return 30;
   else if (m == 2 && isLeap(y))
      return 29;
   else
      return 28;
   
}

string Date::name(unsigned month) const {
   
   vector<string> MonthNames(13);
   MonthNames.at(0) = "nothing";
   MonthNames.at(1) = "January";
   MonthNames.at(2) = "February";
   MonthNames.at(3) = "March";
   MonthNames.at(4) = "April";
   MonthNames.at(5) = "May";
   MonthNames.at(6) = "June";
   MonthNames.at(7) = "July";
   MonthNames.at(8) = "August";
   MonthNames.at(9) = "September";
   MonthNames.at(10) = "October";
   MonthNames.at(11) = "November";
   MonthNames.at(12) = "December";
   
   return MonthNames.at(month);
}

unsigned Date::number(const string &mn) const {
   
   vector<string> MonthNames(13);
   MonthNames.at(0) = "nothing";
   MonthNames.at(1) = "January";
   MonthNames.at(2) = "February";
   MonthNames.at(3) = "March";
   MonthNames.at(4) = "April";
   MonthNames.at(5) = "May";
   MonthNames.at(6) = "June";
   MonthNames.at(7) = "July";
   MonthNames.at(8) = "August";
   MonthNames.at(9) = "September";
   MonthNames.at(10) = "October";
   MonthNames.at(11) = "November";
   MonthNames.at(12) = "December";
   
   for(unsigned int i = 0; i < MonthNames.size(); ++i) {
      
      if(MonthNames.at(i) == mn)
         return i;
   }
   
   return 13;
}

Date getDate();

int main() {

   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;

   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}