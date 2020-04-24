#include <iostream>
#include <cstdlib> // exit()�������ڿ�
#include <cmath>
using namespace std;

//ʾ��7.2
//�����˻���BankAccount
//�����˻�������������ɣ��˻���������Լ����ʰٷ���
class BankAccount
{
public:
    BankAccount(double balance, double rate); //��������ֵ���г�ʼ��
    BankAccount(int dollars, int cents, double rate);
    //���˻�����ʼ��Ϊ$dollars.cents��ʽ
    //��ʼ������Ϊrate�İٷ���
    
    BankAccount(int dollars, double rate);
    //���˻�����ʼ��Ϊ$dollars.00��ͬʱ�����ʳ�ʼ��Ϊrate�İٷ���
    BankAccount();
    //�˻�����ʼ��Ϊ$0.00�����ʳ�ʼ��Ϊ0.0%
    
    void update(); //��һ�����Ϣ���뵽�˻������
    void input();
    void output();
    double getBalance();
    int getDollars();
    int getCents();
    double getRate(); //�������ʵİٷ���
    
    void setBalance(double balance);
    void setBalance(int dollars, int cents);
    //��������Ƿ�ͬʱΪ�Ǹ�����ͬʱΪ��
    
    void setRate(double newRate);
    //���newRate�Ǹ���������Ϊ�µ����ʣ�������ֹ����
    
private:
    int accountDollars; //�˻�����Ԫ����
    int accountCents; //�˻����ķֲ���
    double rate; //�ٷ���
    int dollarsPart(double amount);
    int centsPart(double amount);
    int round(double number);
    
    double fraction(double percent);
    //���ٷ���ת��ΪС������fraction(50.3)����0.503
};

int main(void) {
    cout<<"this is c++ test" << endl;
    
    BankAccount account1(1345.52, 2.3), account2;
    
    cout << "account1 initialized as follows:\n";
    account1.output();
    
    cout << "account2 initialized as follows:\n";
    account2.output();
    
    account1 = BankAccount(999, 99, 5.5);
    cout << "account1 reset to the following:\n";
    account1.output();
    
    cout << "Enter new data for account2:\n";
    account2.input();
    cout << "account2 reset to the following:\n";
    account2.output();
    
    account2.update();
    cout << "In one year account2 will grow to:\n";
    account2.output();
        
    return 0;
}

BankAccount::BankAccount(double balance, double rate):
    accountDollars(dollarsPart(balance)), accountCents(centsPart(balance))
{
    setRate(rate);
}

BankAccount::BankAccount(int dollars, int cents, double rate)
{
    setBalance(dollars, cents);
    setRate(rate);
    //��������Ƿ���ȷ
}

BankAccount::BankAccount(int dollars, double rate):
    accountDollars(dollars), accountCents(0)
{
    setRate(rate);
}

BankAccount::BankAccount():accountDollars(0), accountCents(0), rate(0.)
{}

void BankAccount::update()
{
    double balance = accountDollars + accountCents * 0.01;
    balance = balance + fraction(rate) * balance;
    accountDollars = dollarsPart(balance);
    accountCents = centsPart(balance);
}

void BankAccount::input()
{
    double balanceAsDouble;
    cout << "Enter account balance $";
    cin >> balanceAsDouble;
    accountDollars = dollarsPart(balanceAsDouble);
    accountCents = centsPart(balanceAsDouble);
    cout << "Enter interest rate (NO percent sign): ";
    cin >> rate;
    setRate(rate);
}

void BankAccount::output()
{
    int absDollars = abs(accountDollars);
    int absCents = abs(accountCents);
    cout << "Account balance: $";
    if(accountDollars < 0)
        cout << "-";
    cout << absDollars;
    
    if(absCents >= 10)
        cout << "." << absCents << endl;
    else
        cout << "." << "0" << absCents << endl;
    
    cout << "Rate: " << rate << "%\n";
}

double BankAccount::getBalance()
{
    return (accountDollars + accountCents * 0.01);
}

int BankAccount::getDollars()
{
    return accountDollars;
}

int BankAccount::getCents()
{
    return accountCents;
}

double BankAccount::getRate()
{
    return rate;
}

void BankAccount::setBalance(double balance)
{
    accountDollars = dollarsPart(balance);
    accountCents = centsPart(balance);
}

//ʹ��cstdlib
void BankAccount::setBalance(int dollars, int cents)
{
    if((dollars < 0 && cents > 0) || (dollars > 0 && cents < 0))
    {
        cout << "Inconsistent account data.\n";
        exit(1);
    }
    
    accountDollars = dollars;
    accountCents = cents;
}

//ʹ��cstdlib
void BankAccount::setRate(double newRate)
{
    if(newRate >= 0.0)
        rate = newRate;
    else
    {
        cout << "Cannot have a negative interest rate.\n";
        exit(1);
    }
}

int BankAccount::dollarsPart(double amount)
{
    return static_cast<int>(amount); //��amountת����int
}

//ʹ��cmath
int BankAccount::centsPart(double amount)
{
    double doubleCents = amount * 100;
    //abs�Ƕ�����ȡ����ֵ����fabs�ǶԸ�����ȡ����ֵ
    int intCents = (round(fabs(doubleCents))) % 100; //%�Ը������ܻᴦ����
    if(amount < 0)
        intCents = -intCents;
    return intCents;
}

//ʹ��cmath
int BankAccount::round(double number)
{
    return static_cast<int>(floor(number + 0.5));
}

double BankAccount::fraction(double percent)
{
    return (percent / 100.0);
}