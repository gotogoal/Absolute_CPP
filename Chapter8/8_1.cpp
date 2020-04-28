#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

//���������ҼƵ�Money��
class Money
{
public:
    Money();
    Money(double amount);
    Money(int theDollars, int theCents);
    Money(int theDollars);
    
    double getAmount() const;
    int getDollars() const;
    int getCents() const;
    
    void input(); //ͬʱ������Ԫ���ź�����
    void output() const;

private:
    int dollars; //����������ʾ��Ԫ����Ϊ����ͬʱ����ҲΪ��
    int cents; //����$4.50��ʾ-4��-50

    int dollarsPart(double amount) const;
    int centsPart(double amount) const;
    
    int round(double number) const;
};

//��ʼ���ز�����
const Money operator +(const Money &amount1, const Money& amount2);
const Money operator -(const Money &amount1, const Money& amount2);
bool operator ==(const Money &amount1, const Money& amount2);

//���Ǹ�һԪ������������8.1.3������
const Money operator -(const Money &amount);


int main(void) {
    cout<<"this is c++ test";
    cout << endl;
    
    Money yourAmount, myAmount(10, 9);
    cout << "Enter an amount of money: ";
    yourAmount.input();
    
    cout << "Your amount is ";
    yourAmount.output();
    cout << endl;
    cout << "my amount is ";
    myAmount.output();
    cout << endl;
    
    if(yourAmount == myAmount)
        cout << "We have the same amounts.\n";
    else
        cout << "One of us is richer.\n";
        
    Money ourAmount = yourAmount + myAmount;
    yourAmount.output(); cout << " + "; myAmount.output();
    cout << " equals " ; ourAmount.output(); cout << endl;
    
    Money diffAmount = yourAmount - myAmount;
    yourAmount.output(); cout << " - "; myAmount.output();
    cout << " equals "; diffAmount.output(); cout << endl;
    
    return 0;
}

//���ز���������
const Money operator +(const Money &amount1, const Money& amount2)
{
    int allCents1 = amount1.getCents() + amount1.getDollars() * 100;
    int allCents2 = amount2.getCents() + amount2.getDollars() * 100;
    int sumAllCents = allCents1 + allCents2;
    int absAllCents = abs(sumAllCents); // Money����Ϊ��
    int finalDollars = absAllCents / 100;
    int finalCents = absAllCents % 100;
    
    if(sumAllCents < 0)
    {
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }
    
    return Money(finalDollars, finalCents);
}

const Money operator -(const Money &amount1, const Money& amount2)
{
    int allCents1 = amount1.getCents() + amount1.getDollars() * 100;
    int allCents2 = amount2.getCents() + amount2.getDollars() * 100;
    int diffAllCents = allCents1 - allCents2;
    int absAllCents = abs(diffAllCents);
    int finalDollars = absAllCents / 100;
    int finalCents = absAllCents % 100;
    
    if(diffAllCents < 0)
    {
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }
    
    return Money(finalDollars, finalCents);
}

bool operator ==(const Money &amount1, const Money& amount2)
{
    return (amount1.getDollars() == amount2.getDollars()
        && amount1.getCents() == amount2.getCents());
}

const Money operator -(const Money &amount)
{
    return Money(-amount.getDollars(), -amount.getCents());
}

//���ز�����������ɣ����湹�캯������

Money::Money():dollars(0), cents(0)
{}

Money::Money(double amount):
                            dollars(dollarsPart(amount)),
                            cents(centsPart(amount))
{}

Money::Money(int theDollars):dollars(theDollars), cents(0)
{}

Money::Money(int theDollars, int theCents)
{
    if((theDollars < 0 && theCents > 0) || (theDollars > 0 && theCents < 0))
    {
        cout << "Inconsistent money data.\n";
        exit(1);
    }
    
    dollars = theDollars;
    cents = theCents;
}

int Money::dollarsPart(double amount) const
{
    return static_cast<int>(amount); //��amountת����int
}

int Money::centsPart(double amount) const
{
    double doubleCents = amount * 100;
    //abs�Ƕ�����ȡ����ֵ����fabs�ǶԸ�����ȡ����ֵ
    int intCents = (round(fabs(doubleCents))) % 100; //%�Ը������ܻᴦ����
    if(amount < 0)
        intCents = -intCents;
    return intCents;
}

double Money::getAmount() const
{
    return (dollars + cents * 0.01);
}

int Money::getDollars() const
{
    return dollars;
}

int Money::getCents() const
{
    return cents;
}

//ʹ��iostream��cstdlib
void Money::input()
{
    char dollarSign;
    cin >> dollarSign; //���������ķ���ֵ
    if(dollarSign != '$') //ע�ⵥ����
    {
        cout << "No dollar sign in Money input.\n";
        exit(1);
    }
    
    double amountAsDouble;
    cin >> amountAsDouble;
    dollars = dollarsPart(amountAsDouble);
    cents =centsPart(amountAsDouble);
}

void Money::output() const
{
    int absDollars = abs(dollars);
    int absCents = abs(cents);
    if(dollars < 0 || cents < 0)
        cout << "$-";
    else
        cout << "$";
    cout << absDollars;
    
    if(absCents > 10)
        cout << "." << absCents;
    else
        cout << "." << "0" << absCents;
}

int Money::round(double number) const
{
    return static_cast<int>(floor(number + 0.5));
}