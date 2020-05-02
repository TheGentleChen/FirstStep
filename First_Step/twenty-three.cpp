#include<iostream>
using namespace std;
int main()
{
 bool b=true;
 while(b)
 {
     cout<<"现在正在下雨嘛?请输入'Y'或者'N'";
     char c;
     cin>>c;
     switch(c)
     {
     case'Y':
        cout<<"现在正在下雨。"<<endl;
        b=false;
        break;
     case'N':
        cout<<"现在没有下雨。"<<endl;
        b=false;
        break;
     default:
        cout<<"你输入了错误的字符！"<<endl;
     }
 }
 return 0;
}
