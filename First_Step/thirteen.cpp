#include<iostream>
using namespace std;
int main()
{
    int r,h;
    double c,s1,s2,v1,v2;
    cout << "������뾶�͸ߣ�";
    cin >> r >> h;
    c = 2*3.14*r;
    s1 = 3.14*r*r;
    s2 = 4*3.14*r*r;
    v1 = (4/3)*3.14*r*r*r;
    v2 = 3.14*r*r*h;
    cout << "Բ�ܳ�:" << c
         << "Բ���:" << s1
         << "Բ�����:" << s2
         << "Բ�����:" << v1
         << "Բ�����:" << v2 << endl;
    return 0;
}
