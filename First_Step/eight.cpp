#include<iostream>
using namespace std;
int main()
{
    cout<<"������������:"<<endl;
    int a,b,c;
    cin>>a>>b>>c;
    if(a<b)
    {
        if(b<c)
        {
            cout<<"��С��������˳��Ϊ:"<<a<<"\t"<<b<<"\t"<<c<<endl;
        }
        else
        {
            if(c<a)
            {
                cout<<"��С��������˳��Ϊ:"<<c<<"\t"<<a<<"\t"<<b<<endl;
            }
            else
            {
                cout<<"��С��������˳��Ϊ:"<<a<<"\t"<<c<<"\t"<<b<<endl;
            }
        }
    }
    else
    {
        if(c<b)
        {
            cout<<"��С��������˳��Ϊ:"<<c<<"\t"<<b<<"\t"<<a<<endl;
        }
        else
        {
            if(c<a)
            {
                cout<<"��С��������˳��Ϊ:"<<b<<"\t"<<c<<"\t"<<a<<endl;
            }
            else
            {
                cout<<"��С��������˳��Ϊ:"<<b<<"\t"<<a<<"\t"<<c<<endl;
            }
        }
    }
    return 0;
}
