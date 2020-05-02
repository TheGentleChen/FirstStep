#include<iostream>//预处理命令
using namespace std;//使用命名空间
class student//声明一个类
{
private://以下为类的私有部分
    int num;//私有变量num
    int score;//私有变量score
public://以下为类的公有部分
    void setdata()//定义公用函数setdata
    {
        cin>>num;//输入num
        cin>>score;//输入score
    }
    void display()//定义公用函数display
    {
        cout<<"num="<<num<<endl;//输出num
        cout<<"score="<<score<<endl;//输出score
    };
};//类的声明结束
student stud1,stud2;//定义stud1和stud2是stude类的变量，称为对象
int main()//主函数首部
{
    stud1.setdata();//调用对象stud1的setdata函数
    stud2.setdata();//调用对象stud2的setdata函数
    stud1.display();//调用对象stud1的display函数
    stud2.display();//调用对象stud2的display函数
    return 0;
}
