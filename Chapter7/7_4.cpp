#include <iostream>
#include <cstdlib> // exit()�������ڿ�
#include <cmath>
using namespace std;

//ʾ��7.4 �������δ�const��ʹ��
//��д��ʾ��7.2�е���BankAccount������Ӧʹ��const�ĵط�����const
//�����˻�������������ɣ��˻���������Լ����ʰٷ���
class BankAccount
{
public:
    BankAccount(double balance, double rate);
    //���ݸ�������ֵ����balance��rate��ʼ��
    
    BankAccount(int dollars, int cents, double rate);
    //���˻�����ʼ��Ϊ$dollars.cents��ʽ
    //�����˻���dollars��cents������Ϊ��
    //��ʼ������Ϊrate�İٷ���
    
    BankAccount(int dollars, double rate);
    //���˻�����ʼ��Ϊ$dollars.00��ͬʱ�����ʳ�ʼ��Ϊrate�İٷ���
    
    BankAccount();
    //�˻�����ʼ��Ϊ$0.00�����ʳ�ʼ��Ϊ0.0%
    
    void update(); //��һ�����Ϣ���뵽�˻������
    void input();
    
    void output() const;
    double getBalance() const;
    int getDollars() const;
    int getCents() const;
    double getRate() const; //�������ʵİٷ���
    
    void setBalance(double balance);
    void setBalance(int dollars, int cents);
    //��������Ƿ�ͬʱΪ�Ǹ�����ͬʱΪ����
    
    void setRate(double newRate);
    //���newRate�Ǹ���������Ϊ�µ����ʣ�������ֹ����
    
private:
    //�����˻�����ø���dollars�͸���cents����ʾ
    //��-$4.50��accountDollars����Ϊ-4����accountCents����Ϊ-50
    int accountDollars; //�˻�����Ԫ����
    int accountCents; //�˻����ķֲ���
    double rate; //�ٷ���
    int dollarsPart(double amount) const;
    int centsPart(double amount) const;
    int round(double number) const;
    
    double fraction(double percent) const;
    //���ٷ���ת��ΪС������fraction(50.3)����0.503
};

//���account1�е��˻�����account2�е��˻������򷵻�true
//���򷵻�false
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

int BankAccount::dollarsPart(double amount) const
{
    return static_cast<int>(amount); //��amountת����int
}

//ʹ��cmath
int BankAccount::centsPart(double amount) const
{
    double doubleCents = amount * 100;
    //abs�Ƕ�����ȡ����ֵ����fabs�ǶԸ�����ȡ����ֵ
    int intCents = (round(fabs(doubleCents))) % 100; //%�Ը������ܻᴦ������
    if(amount < 0)
        intCents = -intCents;
    return intCents;
}

//ʹ��cmath
int BankAccount::round(double number) const
{
    return static_cast<int>(floor(number + 0.5));
}

double BankAccount::fraction(double percent) const
{
    return (percent / 100.0);
}