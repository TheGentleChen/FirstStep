#include <iostream>
#include <vector>

using namespace std;


int main(vector<int>& A)        //Binary Search��Ӧ�ã�ʱ�临�Ӷ�O��logN�����ռ临�Ӷ�O��1��
{
    int lo = 0, hi = A.size() - 1;
    while (lo < hi)
    {
        int mi = lo + (hi - lo) / 2;
        if (A[mi] < A[mi + 1])
        {
            lo = mi + 1;
        }
        else
        {
            hi = mi;
        }
    }

    return lo;
}


//int main(vector<int>& A)      ʱ�临�Ӷ�O��N�����ռ临�Ӷ�O��1��
//{
//    size_t i = 0;
//    while (i != A.size() && A[i] < A[i + 1])
//    {
//        ++i;
//    }
//    return i;
//}
//
//int main(vector<int>& A)
//{
//    for (size_t i = 0;i < A.size() - 1;++i)
//    {
//        if (A[i] > A[i + 1])
//            return i;
//    }
//    return A.size() - 1;
//}
