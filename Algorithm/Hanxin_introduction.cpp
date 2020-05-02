#include <iostream>
using namespace std;

int main()
{
    unsigned int num1, num2, num3;
    int result;
    while (cin >> num1 >> num2 >> num3)
    {
        int count = 0;
        for (int x = 10; x < 100; x++)
        {
            if (x % 3 == num1 && x % 5 == num2 && x % 7 == num3)
            {
                result = x;
                if (result > x)
                {
                    result = x;
                }
                cout << "case " << ++count << ": " << result << endl;
            }
        }
        if (0 == count)
        {
            cout << "No answer" << endl;
        }
    }
    return 0;
}
