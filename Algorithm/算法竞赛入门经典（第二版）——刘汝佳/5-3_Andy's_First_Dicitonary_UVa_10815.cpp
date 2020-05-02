#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

set<string> dric;

int main()
{
    string s, buf;

    while (cin >> s)
    {
        for (int i = 0;i < s.length();++i)
        {
            if (isalpha(s[i]))  s[i] = tolower(s[i]);
            else    s[i] = ' ';
        }

        stringstream ss(s);
        while (ss >> buf)   dric.insert(buf);
    }
    for (set<string>::iterator pos = dric.begin(); pos != dric.end(); pos++)
        cout << *pos << "\n";

    return 0;
}
