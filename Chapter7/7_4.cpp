#include <iostream>
#include <cstdlib> // exit()函数所在库
#include <cmath>
using namespace std;

//示例7.4 常量修饰词const的使用
//重写了示例7.2中的类BankAccount，所有应使用const的地方加上const
//银行账户数据由两项组成：账户余额总数以及利率百分数
class BankAccount
{
public:
    BankAccount(double balance, double rate);
    //根据给定参数值进行balance和rate初始化
    
    BankAccount(int dollars, int cents, double rate);
    //将账户余额初始化为$dollars.cents形式
    //负的账户余额，dollars和cents都必须为负
    //初始化利率为rate的百分数
    
    BankAccount(int dollars, double rate);
    //将账户余额初始化为$dollars.00，同时将利率初始化为rate的百分数
    
    BankAccount();
    //账户余额初始化为$0.00，利率初始化为0.0%
    
    void update(); //将一年的利息加入到账户余额中
    void input();
    
    void output() const;
    double getBalance() const;
    int getDollars() const;
    int getCents() const;
    double getRate() const; //返回利率的百分数
    
    void setBalance(double balance);
    void setBalance(int dollars, int cents);
    //会检查参数是否同时为非负或者同时为非正
    
    void setRate(double newRate);
    //如果newRate非负，就设置为新的利率，否则终止程序
    
private:
    //负的账户余额用负的dollars和负的cents来表示
    //如-$4.50将accountDollars设置为-4，将accountCents设置为-50
    int accountDollars; //账户余额的元部分
    int accountCents; //账户余额的分部分
    double rate; //百分数
    int dollarsPart(double amount) const;
    int centsPart(double amount) const;
    int round(double number) const;
    
    double fraction(double percent) const;
    //将百分数转变为小数，如fraction(50.3)返回0.503
};

//如果account1中的账户余额比account2中的账户余额大，则返回true
//否则返回false
bool isLarger(const BankAccount &account1, const BankAccount &account2);
void welcome(const BankAccount &yourAccount);


int main(void) {
    cout<<"this is c++ test" << endl;
    
    BankAccount account1(6543.21, 4.5), account2;
    welcome(account1);
    
    cout << "Enter data for account2:\n";
    account2.input();
    
    if(isLarger(account1, account2))
        cout << "\naccount1 is larger.\n";
    else
        cout << "account2 is at least as large as account1.\n";
        
    return 0;
}

bool isLarger(const BankAccount &account1, const BankAccount &account2)
{
    return (account1.getBalance() > account2.getBalance());
}

void welcome(const BankAccount &yourAccount)
{
    cout
        << "Welcome to our bank.\n" 
        << "The status of your account is:\n";
    yourAccount.output();
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
    cout << "\nEnter interest rate (NO percent sign): ";
    cin >> rate;
    setRate(rate);
}

void BankAccount::output() const
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

double BankAccount::getBalance() const
{
    return (accountDollars + accountCents * 0.01);
}

int BankAccount::getDollars() const
{
    return accountDollars;
}

int BankAccount::getCents() const
{
    return accountCents;
}

double BankAccount::getRate() const
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

int BankAccount::dollarsPart(double amount) const
{
    return static_cast<int>(amount); //把amount转换成int
}

//使用cmath
int BankAccount::centsPart(double amount) const
{
    double doubleCents = amount * 100;
    //abs是对整数取绝对值，而fabs是对浮点数取绝对值
    int intCents = (round(fabs(doubleCents))) % 100; //%对负数可能会处理不当
    if(amount < 0)
        intCents = -intCents;
    return intCents;
}

//使用cmath
int BankAccount::round(double number) const
{
    return static_cast<int>(floor(number + 0.5));
}

double BankAccount::fraction(double percent) const
{
    return (percent / 100.0);
}