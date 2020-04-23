#include <iostream>
#include <cstdlib>
using namespace std;

//示例6.4
//包含私有成员的类
class DayOfYear
{
public:
    void input();
    void output();
    void set(int newMonth, int newDay); //可以构成一个日期
    void set(int newMonth);
    //前提条件：1 <= newMonth <= 12
    //执行结果：日期被设定为给定月份的第一天
    int getMonthNumber(); //返回与月份相对应的数字
    int getDay();
    
private:
    int month;
    int day;
};

int main(void) {
    cout<<"this is c++ test" << endl;
    
    DayOfYear today, bachBirthday;
    cout << "Enter today's date:\n";
    today.input();
    cout << "Today's date is ";
    today.output();
    cout << endl;
    
    bachBirthday.set(3, 21);
    cout << "J. S. Bach's birthday is ";
    bachBirthday.output();
    cout << endl;
    
    if (today.getMonthNumber() == bachBirthday.getMonthNumber() 
        && today.getDay() == bachBirthday.getDay())
        cout << "Happy Birthday Johann Sebastian!\n";
    else
        cout << "Happy Unbirthday Johann Sebastian!\n";
        
    return 0;
}


void DayOfYear::set(int newMonth, int newDay)
{
    if((newMonth >= 1) &&(newMonth <= 12))
        month = newMonth;
    else
    {
        cout << "Illegal month value! Program aborted!\n";
        exit(1);
    }
    
    if((newDay >= 1) && (newDay <= 31))
        day = newDay;
    else
    {
        cout << "Illegal day value! Program abtorted!\n";
        exit(1);
    }
}

int DayOfYear::getMonthNumber()
{
    return month;
}

int DayOfYear::getDay()
{
    return day;
}

void DayOfYear::input()
{
    cout << "Enter the month as a number: ";
    cin >> month;
    
    cout << "Enter the day of the month: ";
    cin >> day;
    
    if((month < 1) || (month > 12) || (day < 1) || (day > 31))
    {
        cout << "Illegal date! Program abtorted!\n";
        exit(1);
    }
}

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