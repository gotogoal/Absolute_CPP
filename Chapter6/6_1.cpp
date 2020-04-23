#include <iostream>
using namespace std;

//示例6.1
//用于表示银行存款单的结构
struct CDAccountV1
{
    double balance;
    double interestRate;
    int term; //存款期限，用月份表示
};

void getData(CDAccountV1 &theAccount);
//执行结果：theAccount.balance,
//theAccount.interestRate,
//theAccount.term已经通过键盘输入了相应的值

int main(void) {
    cout<<"this is c++ test" << endl;
    
    CDAccountV1 account;
    getData(account);
    
    double rateFraction, interest;
    rateFraction = account.interestRate / 100.0;
    interest = account.balance *(rateFraction*(account.term / 12.0));
    account.balance = account.balance + interest;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout 
        << "When your CD matures in "
        << account.term << " months,\n"
        << "it will have a balance of $"
        << account.balance << endl;
        
    return 0;
}

//使用iostream
void getData(CDAccountV1 &theAccount)
{
    cout << "Enter account balance: $" << endl;
    cin >> theAccount.balance;
    cout << "Enter account interest rate: " << endl;
    cin >> theAccount.interestRate;
    cout << "Enter the number of months until maturity: " << endl;
    cin >> theAccount.term;
}