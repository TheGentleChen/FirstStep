#include <iostream>
using namespace std;

int main()                              //本人设计
{
    int x, y;
    cin >> x >> y;
    int counter = 0;
    while (x != 0 || y != 0)
    {
        int xt = x % 2;
        int yt = y % 2;
        if (xt != yt)   counter++;
        x /= 2;
        y /= 2;
    }
    cout << counter << endl;
    return 0;
}
//下列方法转自https://www.cnblogs.com/grandyang/p/6201215.html
class Solution {//自下向上按位求异或
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if ((x & (1 << i)) ^ (y & (1 << i))) {
                ++res;
            }
        }
        return res;
    }
};

class Solution {//求异或，按位检测为1的个数
public:
    int hammingDistance(int x, int y) {
        int res = 0, exc = x ^ y;
        for (int i = 0; i < 32; ++i) {
            res += (exc >> i) & 1;
        }
        return res;
    }
};

class Solution {//**高效**    求异或，之后每次循环去除最后一个1，并统计个数
public:
    int hammingDistance(int x, int y) {
        int res = 0, exc = x ^ y;
        while (exc) {
            ++res;
            exc &= (exc - 1);//去除exc中最后一个1
        }
        return res;
    }
};

class Solution {//递归调用，每次求最后一位异或值，并朝前推进一位，直至异或结果为0终止      //1010101001          得1
public:                                                                                            //101010100           得0
    int hammingDistance(int x, int y) {                                                            //...
        if ((x ^ y) == 0) return 0;                                                                //0                   得0，并终止
        return (x ^ y) % 2 + hammingDistance(x / 2, y / 2);
    }
};
