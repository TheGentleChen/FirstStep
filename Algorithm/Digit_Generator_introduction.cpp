#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100005;

int main()
{
    int ans[maxn];
    memset(ans,0,sizeof(ans));
    for (int i = 1;i < maxn;i++)
    {
        int x = i;
        int y = i;
        while (x > 0)
        {
            y += x % 10;
            x /= 10;
        }
        if (ans[y] == 0 || i < ans[y])
        {
            ans[y] = i;
        }
    }
    int T;
    int n;
    cin >> T;
    while (T-- != 0)
    {
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}
