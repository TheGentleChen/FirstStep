#include <iostream>
using namespace std;

int main()
{
    for (int i = 100;i < 1000;i++)
    {
        int fir = i / 100;
        int sec = i % 100 / 10;
        int thi = i % 10;
        if (i == fir * fir * fir + sec * sec * sec + thi * thi * thi)
        {
            cout << i << " is a daffodil." << endl;
        }
    }
    return 0;
}
