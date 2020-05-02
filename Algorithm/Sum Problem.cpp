#include <iostream>

using namespace std;

int Sum(int n);
int main()
{
    int n;
    while (cin >> n)
    {
        cout << Sum(n) << endl << endl;
    }
    return 0;
}

int Sum(int n)
{
    int sum = 0;
    for (int i = 1;i <= n;++i)
    {
        sum += i;
    }
    return sum;
}
