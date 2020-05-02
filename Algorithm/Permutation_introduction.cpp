#include <iostream>
using namespace std;

int main()
{
    int j = 0,z = 0;
    for (int i = 100; z <1000; i++)
    {
        bool test = true;
        j = 2 * i;
        z = 3 * i;
        bool yeah[10] = {false};
        int firi = i / 100;
        int seci = i / 10 % 10;
        int thii = i % 10;
        int firj = j / 100;
        int secj = j / 10 % 10;
        int thij = j % 10;
        int firz = z / 100;
        int secz = z / 10 % 10;
        int thiz = z % 10;
        yeah[firi] = yeah[seci] = yeah[thii] = yeah[firj] = yeah[secj] = yeah[thij] = yeah[firz] = yeah[secz] = yeah[thiz] = true;
        for (int n = 1; n <= 9; n++)
        {
            if (yeah[n] == false)
            {
                test = false;
                break;
            }
        }
        if (test)
        {
            cout << i << " " << j << " " << z << endl;
        }
    }
    return 0;
}
