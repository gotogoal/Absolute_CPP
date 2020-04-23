#include <iostream>
using namespace std;

//ʾ��6.2
//�����ṹ��Ա�Ľṹ
struct Date
{
    int month;
    int day;
    int year; 
};

//�Ľ������ڱ�ʾ���д��Ľṹ
struct CDAccount
{
    double initialBalance;
    double interestRate;
    int term; //���ڵ�������
    Date maturity;
    double balanceAtMaturity;
};

void getCDData(CDAccount &theAccount);
//ִ�н����theAccount.balance,
//theAccount.interestRate,
//theAccount.term�Ѿ�ͨ��������������Ӧ��ֵ

void getData(Date &theDate);
//ִ�н����theDate.month, theDate.day,
//theDate.year�Ѿ�ͨ���û����̵����뱻��ֵ


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

//ʹ��iostream
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