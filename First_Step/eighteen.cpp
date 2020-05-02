#include<iostream>
using namespace std;
int main()
{
    int a,b,temp;
    cout<<"输入的a，b的值为:";
    cin>>a>>b;
    temp=a;
    a=b;
    b=temp;
    cout<<"输出的a，b的值为:"<<a<<"\t"<<b<<endl;
    return 0;
}
