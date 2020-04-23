#include <iostream>
using namespace std;

//示例6.2
//包含结构成员的结构
struct Date
{
    int month;
    int day;
    int year; 
};

//改进的用于表示银行存款单的结构
struct CDAccount
{
    double initialBalance;
    double interestRate;
    int term; //存款到期的总月数
    Date maturity;
    double balanceAtMaturity;
};

void getCDData(CDAccount &theAccount);
//执行结果：theAccount.balance,
//theAccount.interestRate,
//theAccount.term已经通过键盘输入了相应的值

void getData(Date &theDate);
//执行结果：theDate.month, theDate.day,
//theDate.year已经通过用户键盘的输入被赋值


int main(void) {
    cout<<"this is c++ test" << endl;
    
    CDAccount account;
    cout << "Enter account data on the day account was opened:\n";
    getCDData(account);
    
    double rateFraction, interest;
    rateFraction = account.interestRate / 100.0;
    interest = account.initialBalance *(rateFraction*(account.term / 12.0));
    account.balanceAtMaturity = account.initialBalance + interest;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout 
        << "When the CD matured on "
        << account.maturity.month << "-" << account.maturity.day
        << "-" << account.maturity.year << endl
        << "it had a balance of $"
        << account.balanceAtMaturity << endl;
        
    return 0;
}

//使用iostream
void getCDData(CDAccount &theAccount)
{
    cout << "Enter account initial balance: $" << endl;
    cin >> theAccount.initialBalance;
    cout << "Enter account interest rate: " << endl;
    cin >> theAccount.interestRate;
    cout << "Enter the number of months until maturity: " << endl;
    cin >> theAccount.term;
    cout << "Enter the maturity date:\n" << endl;
    getData(theAccount.maturity);
}

void getData(Date & theDate)
{
    cout << "Enter month: ";
    cin >> theDate.month;
    cout << "Enter day: ";
    cin >> theDate.day;
    cout << "Enter year: ";
    cin >> theDate.year;
}