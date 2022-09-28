
#include "catch.hpp"
#include "Time.h"

TEST_CASE("Default parameters")
{
    Time time{};
    REQUIRE(time.hour == 0);
    REQUIRE(time.second == 0);
    REQUIRE(time.minute == 0);
}

TEST_CASE("Is valid")
{
    Time time{12, 57, 39};
    REQUIRE(is_valid(time));
    Time wrongtime_all{27, 64, 64};
    Time wrongtime_hour{27, 59, 59};
    Time wrongtime_hourandmin{27, 64, 59};
    Time wrongtime_hourandsec{27, 59, 64};
    REQUIRE_FALSE(is_valid(wrongtime_all));
    REQUIRE_FALSE(is_valid(wrongtime_hour));
    REQUIRE_FALSE(is_valid(wrongtime_hourandmin));
    REQUIRE_FALSE(is_valid(wrongtime_hourandsec));
    Time wrongtime_min{23, 69, 32};
    Time wrongtime_minandsec{24, 495, 64};
    Time wrongtime_sec{23, 59, 64};
    REQUIRE_FALSE(is_valid(wrongtime_min));
    REQUIRE_FALSE(is_valid(wrongtime_minandsec));
    REQUIRE_FALSE(is_valid(wrongtime_sec));

}

TEST_CASE("Is AM?")
{
    Time time_am{11, 56, 27};
    REQUIRE(is_am(time_am));
    Time time_pm{12, 0, 1};
    CHECK_FALSE(is_am(time_pm));
}

TEST_CASE("Output")
{
    Time time_am{06, 43, 12};
    CHECK(to_string(time_am, false) == "06:43:12");
    CHECK(to_string(time_am, true) == "06:43:12 am");
    Time time_pm{13, 43, 12};
    CHECK(to_string(time_pm, true) == "01:43:12 pm");
    CHECK(to_string(time_pm, false) == "13:43:12");
}

TEST_CASE("Operator +")
{
    Time time{23, 59, 59};
    CHECK(to_string((time + 86401), false) == "00:00:00");
}

TEST_CASE("Operator time++")
{
    Time time{23, 59, 58};
    CHECK(to_string(time, false) == "23:59:58");
    time++;
    CHECK(to_string(time, false) == "23:59:59");
}

TEST_CASE("Operator -")
{
    Time time{23, 0, 0};
    CHECK(to_string((time - 72), false) == "22:58:48");
}

TEST_CASE("Operator ++time")
{
    Time time{23, 59, 59};
    ++time;
    CHECK(to_string(time, false) == "00:00:00");
}

TEST_CASE("Operator time--")
{
    Time time{23, 59, 58};
    CHECK(to_string(time, false) == "23:59:58");
    time--;
    CHECK(to_string(time, false) == "23:59:57");
}

TEST_CASE("Operator --time")
{
    Time time{0, 0, 0};
    --time;
    CHECK(to_string(time, false) == "23:59:59");
}

TEST_CASE("Operator <")
{
    Time time1{23, 59, 58};
    Time time2{23, 59, 59};
    CHECK(time1 < time2);
}

TEST_CASE("Operator >")
{
    Time time1{23, 59, 58};
    Time time2{23, 59, 59};
    CHECK_FALSE(time1 > time2);
}

TEST_CASE("Operator <=")
{
    Time time1{23, 59, 59};
    Time time2{23, 59, 59};
    Time time3{23, 59, 57};
    CHECK(time1 <= time2);
    CHECK_FALSE(time2 <= time3);
}

TEST_CASE("Operator >=")
{
    Time time1{23, 59, 59};
    Time time2{23, 59, 59};
    Time time3{23, 59, 57};
    CHECK(time1 >= time2);
    CHECK_FALSE(time3 >= time2);
}

TEST_CASE("Operator <<")
{
    Time time{23, 56, 42};
    ostringstream oss{};
    oss << time;
    CHECK(oss.str() == "23:56:42");
}

TEST_CASE("Operator >>")
{
    Time time{23, 56, 42};
    Time t{};
    istringstream iss{"23:56:42"};
    iss >> t;
    CHECK_FALSE(iss.fail());
    CHECK(to_string(t, false) == to_string(time, false));
}

TEST_CASE("Operator ==")
{
    Time time1{23, 56, 42};
    Time time2{23, 56, 42};
    REQUIRE(time1 == time2);
    Time time3{23, 57, 42};
    REQUIRE_FALSE(time1 == time3);
}
