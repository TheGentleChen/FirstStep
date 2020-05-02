#include<iostream>
using namespace std;
int main()
{
    int x,y;
    cin>>x;
    if(x<10&&x>5)
    {
        y=2*x;
    }
    else
    {
        if(x<=5)
        {
            y=x;
        }
        else
        {
            y=3*x;
        }
    }
    cout<<y<<endl;
    return 0;
}
