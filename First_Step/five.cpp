#include<iostream>
using namespace std;
int min(int i,int j)
{
    int e;
    if(i<=j)
    e=i;
    else e=j;
        return(e);
}
int main()
{
    int i,j,m;
    cin>>i>>j>>m;
    m=min(i,j);
    cout<<"��Сֵ��"<<m<<endl;
    return 0;
}
