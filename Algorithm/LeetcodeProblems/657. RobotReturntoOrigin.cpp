#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    char book[5] = {0};
    cin >> s;
    for (int i = 0;i < s.length();++i)
    {
        if (s[i] == 'L')
        {
            book[1] -= 1;
        }
        else if (s[i] == 'R')
        {
            book[1] += 1;
        }
        else if (s[i] == 'U')
        {
            book[2] += 1;
        }
        else
        {
            book[2] -= 1;
        }
    }
    if (book[1] == 0 && book[2] == 0)
        cout << true << endl;
    else
        cout << false << endl;
    return 0;
}
