#include<iostream>
using namespace std;
int main()
{
    int i,j,z;
    for(i=1;i<7;++i)
    {
        for(j=1;j<i;++j)
        {
            cout<<" ";
        }
        for(z=7;z>i;--z)
            {
                cout<<"#";
            }
        cout<<"\n";
    }
    return 0;
}
