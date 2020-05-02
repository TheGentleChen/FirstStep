#ifndef BIGINTEGER_H_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class BigInteger
{
private:
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;
public:
    BigInteger(long long num = 0) {*this = num;}
    BigInteger operator = (long long num);
    BigInteger operator = (const string &str);
    BigInteger operator + (const BigInteger &b)const;
    bool operator < (const BigInteger &b)const;
};

#endif // BIGINTEGER_H_
