#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const int maxn = 81;
const char alpha[] = {"CHON"};
const double weight[] = {12.01, 1.008, 16.00, 14.01};

int main()
{
    char ch[maxn];
    double quality;
    cin >> ch;
    int i = 0;
    while (ch[i])
    {
        int num;
        int j;
        for (j = 0;j < 4;j++)
        {
            if (ch[i] == alpha[j])
                break;
        }
        i++;
        num = 1;
        if (isdigit(ch[i]))
        {
            num = ch[i++] - '0';
        }
        if (isdigit(ch[i]))
        {
            num = num * 10 + (ch[i++] - '0');
        }
        quality += num * weight[j];
    }
    cout << "Quality = " << quality  << "g/mol" << endl;
    return 0;
}
