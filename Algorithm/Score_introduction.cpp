#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100;

int main()
{
    char ch[maxn];
    int in_to_ch[maxn] = {0};
    int total = 0;
    cin >> ch;
    for (int i = 0; i < strlen(ch); i++)
    {
        if (ch[i] == 'O')
        {
            if (ch[i - 1] == 'O')
            {
                in_to_ch[i] = in_to_ch[i - 1] + 1;
            }
            else
                in_to_ch[i] = 1;
        }
    }
    cout << "Total = " << total << endl;
    return 0;
}
