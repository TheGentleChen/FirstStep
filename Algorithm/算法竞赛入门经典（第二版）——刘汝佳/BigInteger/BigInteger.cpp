#include "BigInteger.hpp"

BigInteger BigInteger::operator = (long long num)
{
    s.clear();
    do
    {
        s.push_back(num % BASE);
        num /= BASE;
    }while (num > 0);
    return *this;
}

BigInteger BigInteger::operator = (const string &str)
{
    s.clear();
    int x, len = (str.length() - 1) / WIDTH + 1;
    for (int i = 0;i < len;++i)
    {
        int end = str.length() - i * WIDTH;
        int start = max(0, end - WIDTH);
        stringstream ss(str.substr(start, end - start));
        ss >> x;
        s.push_back(x);
    }

    return *this;
}

BigInteger BigInteger::operator + (const BigInteger &b)const
{
    BigInteger c;
    c.s.clear();
    for (int i = 0, g = 0; ;++i)
    {
        if (g == 0 && i >= s.size() && i >= b.s.size()) break;
        int x = g;
        if (i < s.size())   x += s[i];
        if (i < b.s.size()) x += b.s[i];
        c.s.push_back(x % BASE);
        g = x / BASE;
    }
    return c;
}

bool BigInteger::operator < (const BigInteger &b)const
{
    if (s.size() != b.s.size()) return s.size() < b.s.size();
    for (int i = s.size() - 1;i >= 0;--i)
    {
        if (s[i] != b.s[i]) return s[i] < b.s[i];
    }
    return false;
}
