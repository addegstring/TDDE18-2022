#include <iostream>
#include <string>
#include <iomanip>
#include "Time.h"
using namespace std;

bool is_valid(Time time)
{
    bool boolret{false};
    if (time.hour >= 0 && time.minute >= 0 && time.second >= 0)
    {
        if (time.hour < 24 && time.minute < 60 && time.second < 60)
        {
            boolret = true;
        }
    }
    return boolret;
}

bool is_am(Time time)
{
    if (time.hour >= 12)
    {
        return false;
    }
    return true;
}

string to_string(Time time, bool ampm)
{
    string str{};
    string minFill{};
    string secFill{};
    if (ampm && time.hour - 12 < 10)
    {
        str += "0";
    } else if(time.hour < 10)
        str += "0";
    if (time.minute < 10)
    {
        minFill = "0";
    }
    if (time.second < 10)
    {
        secFill = "0";
    }
    if (ampm)
    {
        str += to_string(time.hour % 12) + ":" + minFill + to_string(time.minute) + ":" + secFill + to_string(time.second);
        if (!is_am(time))
        {
            str += " pm";
        }
        else
        {
            str += " am";
        }
        return str;
    }
    return (str + to_string(time.hour) + ":" + minFill + to_string(time.minute) + ":" + secFill + to_string(time.second));
}

Time operator+(Time time, int t)
{
    int totalTime{};
    totalTime += time.hour * 3600 + time.minute * 60 + time.second + t;
    totalTime = totalTime % 86400;
    time.hour = totalTime / 3600;
    time.minute = (totalTime - time.hour * 3600) / 60;
    time.second = ((totalTime - time.hour * 3600 - time.minute * 60));
    return time;
}

Time operator-(Time time, int t)
{
    int totalTime{};
    totalTime += time.hour * 3600 + time.minute * 60 + time.second - t;

    if (totalTime < 0)
    {
        totalTime = 86400 + (totalTime % 86400);
    }

    time.hour = totalTime / 3600;
    time.minute = (totalTime - time.hour * 3600) / 60;
    time.second = ((totalTime - time.hour * 3600 - time.minute * 60));

    return time;
}

bool operator>(Time const &time1, Time const &time2)
{
    int totalTime1{};
    totalTime1 = time1.hour * 3600 + time1.minute * 60 + time1.second;
    int totalTime2{};
    totalTime2 = time2.hour * 3600 + time2.minute * 60 + time2.second;

    if (totalTime1 > totalTime2)
    {
        return true;
    }
    return false;
}

bool operator>=(Time const &time1, Time const &time2)
{
    int totalTime1{};
    totalTime1 = time1.hour * 3600 + time1.minute * 60 + time1.second;
    int totalTime2{};
    totalTime2 = time2.hour * 3600 + time2.minute * 60 + time2.second;

    if (totalTime1 >= totalTime2)
    {
        return true;
    }
    return false;
}

bool operator<(Time const &time1, Time const &time2)
{
    int totalTime1{};
    totalTime1 = time1.hour * 3600 + time1.minute * 60 + time1.second;
    int totalTime2{};
    totalTime2 = time2.hour * 3600 + time2.minute * 60 + time2.second;

    if (totalTime1 < totalTime2)
    {
        return true;
    }
    return false;
}

bool operator<=(Time const &time1, Time const &time2)
{
    int totalTime1{};
    totalTime1 = time1.hour * 3600 + time1.minute * 60 + time1.second;
    int totalTime2{};
    totalTime2 = time2.hour * 3600 + time2.minute * 60 + time2.second;

    if (totalTime1 <= totalTime2)
    {
        return true;
    }
    return false;
}

Time operator++(Time &time, int)
{ // time++
    Time tmp{time};
    time = time + 1;
    return tmp;
}

Time &operator++(Time &time)
{ //++time
    time = time + 1;
    return time;
}

Time operator--(Time &time, int)
{ // time--
    Time tmp{time};
    time = time - 1;
    return tmp;
}

Time &operator--(Time &time)
{ //--time
    time = time - 1;
    return time;
}

bool operator==(Time const& time1, Time const& time2)
{
    int totalTime1{};
    totalTime1 = time1.hour * 3600 + time1.minute * 60 + time1.second;
    int totalTime2{};
    totalTime2 = time2.hour * 3600 + time2.minute * 60 + time2.second;
    if(totalTime1 == totalTime2)
    {
        return true;
    }
    return false;
}

ostream &operator<<(ostream &os, Time &time)
{
    os << to_string(time, false);
    return os;
}

istream &operator>>(istream &is, Time &time)
{
    is >> time.hour;
    is.ignore(1, ':');
    is >> time.minute;
    is.ignore(1, ':');
    is >> time.second;

    if (!is_valid(time))
    {
        is.setstate(std::ios::failbit);
    }
    return is;
}