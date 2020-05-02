#include<iostream>
using namespace std;
int max(int i,int j)
{
    int e;
    if(i>=j)
    e=i;
    else e=j;
    return(e);
}

 int main()
 {
 int i,j,m;
        cin>>i>>j>>m;
        m=max(i,j);
        cout<<"最大值是"<<m<<endl;
return 0;
}
