#include <iostream>

using namespace std;

bool isSDNum(int num);

int main()
{
    cout << isSDNum(21);
    return 0;
}

bool isSDNum(int num)
{
    bool is = true;
    int testNum = num;
    while (testNum != 0)
    {
        int t = testNum % 10;
        testNum /= 10;
        if (t ==0 || num % t != 0)
            return false;
    }

    return is;
}
