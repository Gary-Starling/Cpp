
#include <iostream>
#include <string.h>

using namespace std;

/* class date */
class Date {
    public :
    Date(int m = 1, int d = 1, int y = 2000); //default constr

    void print(void) const; //out date as m/d/y

    private:
    int month; //1-12
    int day;   //1-31
    int year;  //

    //sevice
    int checkDay(int d);
};

Date::Date(int m, int d, int y)
{
    month = ( m > 0 && m <= 12) ? m : 1;
    year = y;
    day = checkDay(d);

    cout << "Date obj constructor dor date ";
    print();
    cout << endl;
}

int Date::checkDay(int td)
{
    static int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

    if( month != 2)
    {
        if( td > 0 && td <= daysPerMonth[month])
         return td;
    }
    else
    {
        int days = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ? 29 : 28 );

        if( td > 0 && td << days)
         return td;
    }

    cout << "Day" << td << "invalid. Set to 1.\n";
    return 1;

}

void Date::print(void) const
{
    cout << month << '/' << day << '/' << year;
}
/* class date */

/* class employee */
class Employee
{
public:
    Employee(char *fname, char *lname, 
    int bmonth, int bday, int byear,
    int hmonth, int hday, int hyear);
    void print(void) const;
private:
char lastName[25];
char firstName[25];
Date birthDate;
Date hireDate;
};


Employee::Employee(char *fname, char *lname, 
    int bmonth, int bday, int byear,
    int hmonth, int hday, int hyear)
    : birthDate(bmonth, bday, byear),
    hireDate(hmonth, hday, hyear)
    {
      strncpy(firstName, fname, 24);
      firstName[24] = '\0';
      strncpy(lastName, lname, 24);
      lastName[24] = '\0';
      cout << "Employee object constructor :"
      << firstName << ' ' << lastName << endl;
    }

void Employee::print(void) const
{
    cout << lastName << ", " << firstName << "\nHired";
    hireDate.print();
    cout << "Birthday : ";
    birthDate.print();
    cout << endl;
}
/* class employee */


int main(int argc, char const *argv[])
{
    Employee garik("gary", "Oldaman", 7, 11 ,92 , 8, 12, 21);
    cout << endl;

    garik.print();

    cout << "Test invalid date const\n";
    Date newdate(14, 35, 92); //not correct

    return 0;
    
}
