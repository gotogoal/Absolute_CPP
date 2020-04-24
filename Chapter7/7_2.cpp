#include <iostream>
#include <cstdlib> // exit()函数所在库
#include <cmath>
using namespace std;

//示例7.2
//银行账户类BankAccount
//银行账户数据由两项组成：账户余额总数以及利率百分数
class BankAccount
{
public:
    BankAccount(double balance, double rate); //给定参数值进行初始化
    BankAccount(int dollars, int cents, double rate);
    //将账户余额初始化为$dollars.cents形式
    //初始化利率为rate的百分数
    
    BankAccount(int dollars, double rate);
    //将账户余额初始化为$dollars.00，同时将利率初始化为rate的百分数
    BankAccount();
    //账户余额初始化为$0.00，利率初始化为0.0%
    
    void update(); //将一年的利息加入到账户余额中
    void input();
    void output();
    double getBalance();
    int getDollars();
    int getCents();
    double getRate(); //返回利率的百分数
    
    void setBalance(double balance);
    void setBalance(int dollars, int cents);
    //会检查参数是否同时为非负或者同时为负
    
    void setRate(double newRate);
    //如果newRate非负，就设置为新的利率，否则终止程序
    
private:
    int accountDollars; //账户余额的元部分
    int accountCents; //账户余额的分部分
    double rate; //百分数
    int dollarsPart(double amount);
    int centsPart(double amount);
    int round(double number);
    
    double fraction(double percent);
    //将百分数转变为小数，如fraction(50.3)返回0.503
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
    //检查数据是否正确
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

//使用cstdlib
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

//使用cstdlib
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
    return static_cast<int>(amount); //把amount转换成int
}

//使用cmath
int BankAccount::centsPart(double amount)
{
    double doubleCents = amount * 100;
    //abs是对整数取绝对值，而fabs是对浮点数取绝对值
    int intCents = (round(fabs(doubleCents))) % 100; //%对负数可能会处理不当
    if(amount < 0)
        intCents = -intCents;
    return intCents;
}

//使用cmath
int BankAccount::round(double number)
{
    return static_cast<int>(floor(number + 0.5));
}

double BankAccount::fraction(double percent)
{
    return (percent / 100.0);
}