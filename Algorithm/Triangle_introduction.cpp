#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = n;i > 0;i--)
    {
        for (int j = n;j > i;j--)
        {
            cout << ' ';
        }
        for (int j = 1;j < i * 2;j++)
        {
            cout << '#';
        }
        cout << endl;
    }
    return 0;
}
