#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int i , j;
    double sqrti;
    i = 50;
    sqrti = sqrt(i);
    while(i<=100)
    {
    for(j=2;j<sqrti;j += 1)
    {
    if(i%j==0) break;
    }
    if(sqrti<j)
    {
    cout << i << endl;
    }
    ++i;
    }
    return 0;
}
