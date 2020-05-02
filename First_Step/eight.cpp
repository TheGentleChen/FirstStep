#include<iostream>
using namespace std;
int main()
{
    cout<<"输入三个数字:"<<endl;
    int a,b,c;
    cin>>a>>b>>c;
    if(a<b)
    {
        if(b<c)
        {
            cout<<"从小到大排列顺序为:"<<a<<"\t"<<b<<"\t"<<c<<endl;
        }
        else
        {
            if(c<a)
            {
                cout<<"从小到大排列顺序为:"<<c<<"\t"<<a<<"\t"<<b<<endl;
            }
            else
            {
                cout<<"从小到大排列顺序为:"<<a<<"\t"<<c<<"\t"<<b<<endl;
            }
        }
    }
    else
    {
        if(c<b)
        {
            cout<<"从小到大排列顺序为:"<<c<<"\t"<<b<<"\t"<<a<<endl;
        }
        else
        {
            if(c<a)
            {
                cout<<"从小到大排列顺序为:"<<b<<"\t"<<c<<"\t"<<a<<endl;
            }
            else
            {
                cout<<"从小到大排列顺序为:"<<b<<"\t"<<a<<"\t"<<c<<endl;
            }
        }
    }
    return 0;
}
