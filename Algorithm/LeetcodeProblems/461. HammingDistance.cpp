#include <iostream>
using namespace std;

int main()                              //�������
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
//���з���ת��https://www.cnblogs.com/grandyang/p/6201215.html
class Solution {//�������ϰ�λ�����
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

class Solution {//����򣬰�λ���Ϊ1�ĸ���
public:
    int hammingDistance(int x, int y) {
        int res = 0, exc = x ^ y;
        for (int i = 0; i < 32; ++i) {
            res += (exc >> i) & 1;
        }
        return res;
    }
};

class Solution {//**��Ч**    �����֮��ÿ��ѭ��ȥ�����һ��1����ͳ�Ƹ���
public:
    int hammingDistance(int x, int y) {
        int res = 0, exc = x ^ y;
        while (exc) {
            ++res;
            exc &= (exc - 1);//ȥ��exc�����һ��1
        }
        return res;
    }
};

class Solution {//�ݹ���ã�ÿ�������һλ���ֵ������ǰ�ƽ�һλ��ֱ�������Ϊ0��ֹ      //1010101001          ��1
public:                                                                                            //101010100           ��0
    int hammingDistance(int x, int y) {                                                            //...
        if ((x ^ y) == 0) return 0;                                                                //0                   ��0������ֹ
        return (x ^ y) % 2 + hammingDistance(x / 2, y / 2);
    }
};
