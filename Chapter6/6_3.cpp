#include <iostream>
using namespace std;

//示例6.3
//演示一个非常简单的类的示例程序
class DayOfYear
{
public:
    void output();
    int month;
    int day;
};

int main(void) {
    cout<<"this is c++ test" << endl;
    
    DayOfYear today, birthday;
    cout << "Enter today's date:\n";
    cout << "Enter month as a number: ";
    cin >> today.month;
    
    cout << "Enter the day of the month: ";
    cin >> today.day;
    
    cout << "Enter your birthday:\n";
    cout << "Enter month as a number: ";
    cin >> birthday.month;
    
    cout << "Enter the day of the month: ";
    cin >> birthday.day;
    
    cout << "Today's date is: ";
    today.output();
    cout << endl;
    
    cout << "Your birthday is: ";
    birthday.output();
    cout << endl;
    
    if (today.month == birthday.month && today.day == birthday.day)
        cout << "Happy Birthday!\n";
    else
        cout << "Happy Unbirthday!\n";
        
    return 0;
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