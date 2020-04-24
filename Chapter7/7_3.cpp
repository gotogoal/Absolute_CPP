#include <iostream>
#include <cstdlib>
using namespace std;

//示例7.3 类类型成员变量

class DayOfYear
{
public:
    DayOfYear(int monthValue, int dayValue);
    DayOfYear(int monthValue);
    DayOfYear();
    
    void input();
    void output();
    int getMonthNumber();
    int getDay();

private:
    int month;
    int day;
    void testDate();
};

class Holiday
{
public:
    Holiday(); //初始化为1月1日，没有强迫泊车
    Holiday(int month, int day, bool theEnforcement);
    
    void output();
    
private:
    DayOfYear date;
    bool parkingEnforcement;
    //如果有强制泊车，则为True
};


int main(void) {
    cout<<"this is c++ test";
    
    Holiday h(2, 14, true);
    cout << "Testing the class Holiday.\n";
    h.output();
    
    return 0;
}

Holiday::Holiday():date(1,1), parkingEnforcement(false)
{}

Holiday::Holiday(int month, int day, bool theEnforcement):
    date(month, day), parkingEnforcement(theEnforcement)
{}

void Holiday::output()
{
    date.output();
    cout << endl;
    if(parkingEnforcement)
        cout << "Parking laws will be enforced!\n";
    else
        cout << "Parking laws will not be enforced!\n";
}

DayOfYear::DayOfYear(int monthValue, int dayValue):
        month(monthValue), day(dayValue)
{
    testDate();
}

//使用iostream和cstdlib
void DayOfYear::testDate()
{
    if((month < 1) || (month > 12))
    {
        cout << "Illegal month value!\n";
        exit(1);
    }
    if((day < 1) || (day > 31))
    {
        cout << "Illegal day value!\n";
        exit(1);
    }
}

//使用iostream
void DayOfYear::output()
{
    switch(month)
    {
        case 1: cout << "January "; break;
        case 2: cout << "February "; break;
        case 3: cout << "March "; break;
        case 4: cout << "April "; break;
        case 5: cout << "May "; break;
        case 6: cout << "June "; break;
        case 7: cout << "July "; break;
        case 8: cout << "August "; break;
        case 9: cout << "September "; break;
        case 10: cout << "October "; break;
        case 11: cout << "November "; break;
        case 12: cout << "December "; break;
        default:
            cout << "Error in DayOfYear::output. Contact software vendor.";
    }
    
    cout << day;
}