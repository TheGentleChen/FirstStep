#include<iostream>
using namespace std;
int main()
{
    int all=1,i;
    for(i=0;i<10;++i)
        all=2*(all+1);//计算前一天的桃子数目
    cout<<"猴子第一天摘了"<<all<<"个桃子"<<endl;
    return 0;
}
