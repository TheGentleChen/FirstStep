#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    long a, b, c;
    while (cin >> a >> b >> c && a <= 1000000 && b <= 1000000 && c <= 100 && a != 0 && b != 0 && c != 0)
    {
        cout << fixed << setprecision(c) << a * 1.0 / b << endl;
    }
    return 0;
}

