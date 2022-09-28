#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Time{
    int hour;
    int minute;
    int second;
};

bool is_valid(Time time);

bool is_am(Time time);

string to_string(Time time, bool ampm);

Time operator+(Time time, int t);

Time operator ++(Time& time, int i);

Time& operator ++(Time& time);

Time operator-(Time time, int t);

Time operator--(Time& time, int);

Time& operator--(Time& time);

bool operator <(Time const& time1, Time const& time2);

bool operator <=(Time const& time1, Time const& time2);

bool operator >(Time const& time1, Time const& time2);

bool operator >=(Time const& time1, Time const& time2);

istream& operator>>(istream & is, Time & time);

ostream& operator<<(ostream& os, Time & time);

bool operator==(Time const & time1, Time const& time2);