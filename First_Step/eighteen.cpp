#include<iostream>
using namespace std;
int main()
{
    int a,b,temp;
    cout<<"�����a��b��ֵΪ:";
    cin>>a>>b;
    temp=a;
    a=b;
    b=temp;
    cout<<"�����a��b��ֵΪ:"<<a<<"\t"<<b<<endl;
    return 0;
}
