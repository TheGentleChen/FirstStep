#include<iostream>
using namespace std;
int main()
{
    int i;
    i=50;
    while(i<=100)
    {
        while(i%9==0)
    {
        cout<<i<<endl;
        ++i;
    }
    ++i;
    }
    return 0;
}
