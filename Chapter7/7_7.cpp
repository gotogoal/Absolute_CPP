#include <iostream>
#include <vector>
using namespace std;

//示例7.7 向量的使用
//向量很特别，可以使用v[i]来更改向量中第i个元素的值
//但不能使用v[i]的方式来初始化向量中第i个元素的值
//为了给向量增加新的元素，需要用成员函数push_back()
//vector <double> sample;
//sample.push_back(0.0);
//sample.push_back(1.1);
//sample.push_back(2.2);
//以上可以对向量前三个元素（下标0,1,2）进行初始化
//vector <int> v(10); 可以根据参数值（本例是10）对向量的前10个元素进行初始化为0

int main(void) {
    cout<<"this is c++ test";
    cout << endl;

    vector <int> v;
    cout
        << "Enter a list of positive numbers.\n"
        << "Place a negative number at the end.\n";
    int next;
    cin >> next;
    while(next > 0)
    {
        v.push_back(next);
        cout << next << " added! ";
        cout << "v.size() = " << v.size() << endl;
        cin >> next;
    }
    
    cout << "Your entered:\n";
    for(unsigned int i=0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    
    cout << endl;
    return 0;
}
