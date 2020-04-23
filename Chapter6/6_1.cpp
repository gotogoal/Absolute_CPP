#include <iostream>
using namespace std;

//ʾ��6.1
//���ڱ�ʾ���д��Ľṹ
struct CDAccountV1
{
    double balance;
    double interestRate;
    int term; //������ޣ����·ݱ�ʾ
};

void getData(CDAccountV1 &theAccount);
//ִ�н����theAccount.balance,
//theAccount.interestRate,
//theAccount.term�Ѿ�ͨ��������������Ӧ��ֵ

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

//ʹ��iostream
void getData(CDAccountV1 &theAccount)
{
    cout << "Enter account balance: $" << endl;
    cin >> theAccount.balance;
    cout << "Enter account interest rate: " << endl;
    cin >> theAccount.interestRate;
    cout << "Enter the number of months until maturity: " << endl;
    cin >> theAccount.term;
}