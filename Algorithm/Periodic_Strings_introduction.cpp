#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 81;

int main()
{
    int n;
    cin >> n;
    bool b = true;
    while (n--)
    {
        char str[maxn];

        cin >> str;
        int i;
        for (i = 1; i <= 80; i++)
        {
            int z = strlen(str);
            for (int j = 0; j < z - i; j++)
            {
                b = true;
                if (str[j] != str[j + i])
                    b = false;
            }
            if (b == true)
                break;
            if (i == z)
                break;
        }
        cout << i << endl;
    }
    return 0;;
}
