#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 105;

bool Less(const char * s,int p,int q);

int main()
{
    char s[maxn];
    int T;
    cin >> T;
    while (T--)
    {
        cin >> s;
        int ans = 0;
        int n = strlen(s);
        for (int i = 1;i < n;i++)
        {
            if (Less(s,i,ans))
            {
                ans = i;
            }
        }
        for (int i = 0;i < n;i++)
        {
            cout.put(s[(ans + i) % n]);
        }
        cout.put('\n');
    }
    return 0;
}

bool Less(const char * s,int p,int q)
{
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[(p + i) % n] != s[(q + i) % n])
        {
            return s[(p + i) % n] < s[(q + i) % n];
        }
    }
    return false;
}
