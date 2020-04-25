#include <iostream>
using namespace std;

//示例7.6 静态成员
class Server
{
public:
    Server(char lettername);
    
    static int getTurn();
    static bool stillOpen();
    
    void serveOne();

private:
    static int turn;
    static int lastServed;
    static bool nowOpen;
    
    char name;
    
};

int Server::turn = 0;
int Server::lastServed = 0;
bool Server::nowOpen = true;

int main(void) {
    cout<<"this is c++ test";
    cout << endl;

    Server s1('A'), s2('B');
    int number, count;
    
    do
    {
        cout << "How many in your group?\n";
        cin >> number;
        cout << "Your turns are: ";
        for(count=0; count < number; count++)
        {
            cout << Server::getTurn() << " ";
        }
        cout << endl;
        s1.serveOne();
        s2.serveOne();
    }while(Server::stillOpen());
    
    cout << "Now closing service.\n";
    return 0;
}

Server::Server(char lettername):name(lettername)
{}

//getTurn是静态成员函数，只能引用类的静态成员
int Server::getTurn()
{
    turn++;
    return turn;
}

bool Server::stillOpen()
{
    return nowOpen;
}

void Server::serveOne()
{
    if(nowOpen && lastServed < turn)
    {
        lastServed++;
        cout << "Server " << name << " Now serving " << lastServed << endl;
    }
    if(lastServed >= turn)
        nowOpen = false;
}