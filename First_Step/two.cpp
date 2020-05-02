#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int num1=0;
    int num2=0;
    int ret=0;
    cin>>num1>>num2;
    while (num1<=num2)
    {
        cout<<num1<<' ';
        ++num1;
    }
    system("pause");
    return 0;
}
