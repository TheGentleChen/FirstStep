#include<iostream>
using namespace std;
int main()
{
    int r,h;
    double c,s1,s2,v1,v2;
    cout << "请输入半径和高：";
    cin >> r >> h;
    c = 2*3.14*r;
    s1 = 3.14*r*r;
    s2 = 4*3.14*r*r;
    v1 = (4/3)*3.14*r*r*r;
    v2 = 3.14*r*r*h;
    cout << "圆周长:" << c
         << "圆面积:" << s1
         << "圆球面积:" << s2
         << "圆球体积:" << v1
         << "圆柱体积:" << v2 << endl;
    return 0;
}
