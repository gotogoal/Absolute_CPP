#include <iostream>
#include <vector>
using namespace std;

//ʾ��7.7 ������ʹ��
//�������ر𣬿���ʹ��v[i]�����������е�i��Ԫ�ص�ֵ
//������ʹ��v[i]�ķ�ʽ����ʼ�������е�i��Ԫ�ص�ֵ
//Ϊ�˸����������µ�Ԫ�أ���Ҫ�ó�Ա����push_back()
//vector <double> sample;
//sample.push_back(0.0);
//sample.push_back(1.1);
//sample.push_back(2.2);
//���Ͽ��Զ�����ǰ����Ԫ�أ��±�0,1,2�����г�ʼ��
//vector <int> v(10); ���Ը��ݲ���ֵ��������10����������ǰ10��Ԫ�ؽ��г�ʼ��Ϊ0

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
