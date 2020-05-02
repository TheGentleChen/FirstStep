#include <iostream>
#include <map>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

map<string, int> cnt;
vector<string> words;

string repr(const string &s);

int main()
{
    string s;
    while (cin >> s)
    {
        if (s[0] == '#')    break;
        words.push_back(s);
        string tmp = repr(s);
        if (!cnt.count(tmp))    cnt[tmp] = 0;
        cnt[tmp]++;
    }

    vector<string> ans;
    for (int i = 0;i < words.size();++i)
    {
        if (cnt[repr(words[i])] == 1) ans.push_back(words[i]);
    }
    sort(ans.begin(), ans.end());

    for (string t: ans)
        cout << t << "\n";

    return 0;
}

string repr(const string &s)
{
    string tmp = s;
    for (int i = 0;i < tmp.length();++i)
    {
        tmp[i] = tolower(tmp[i]);
    }
    sort(tmp.begin(), tmp.end());

    return tmp;
}
