#include <iostream>
using namespace std;

const int maxn = 10001;
const int SIZE = 10;

int main()
{
    char ch[maxn];
    int n;
    cin >> n;
    while (n--)
    {
        int digit[SIZE] = {0};
        cin >> ch;
        int i = 0;
        while (ch[i])
        {
            digit[int(ch[i++] - '0')]++;
        }
        for (i = 0;i < 10;i++)
            cout << digit[i] << " ";
        cout << endl;
    }
    return 0;
}
