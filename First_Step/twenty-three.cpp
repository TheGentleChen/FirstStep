#include<iostream>
using namespace std;
int main()
{
 bool b=true;
 while(b)
 {
     cout<<"��������������?������'Y'����'N'";
     char c;
     cin>>c;
     switch(c)
     {
     case'Y':
        cout<<"�����������ꡣ"<<endl;
        b=false;
        break;
     case'N':
        cout<<"����û�����ꡣ"<<endl;
        b=false;
        break;
     default:
        cout<<"�������˴�����ַ���"<<endl;
     }
 }
 return 0;
}
