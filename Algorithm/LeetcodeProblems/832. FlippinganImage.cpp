#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//int main()
//{
//    vector<vector<int> > A;
//    vector<int> a1;
//    a1.push_back(1);
//    a1.push_back(1);
//    a1.push_back(0);
//    vector<int> a2;
//    a2.push_back(1);
//    a2.push_back(0);
//    a2.push_back(1);
//    A.push_back(a1);
//    A.push_back(a2);
//    for (int a = 0;a < A.size();++a)
//    {
//        for (int i = 0;i < A[a].size() / 2;++i)
//        {
//            int t = A[a][A[a].size() - i - 1] ^ 1;
//            A[a][A[a].size() - i - 1] = A[a][i] ^ 1;
//            A[a][i] = t;
//        }
//        if (A[a].size() % 2 == 1)
//            A[a][A[a].size() / 2] ^= 1;
//    }
//
//    for (vector<int> tA:A)
//    {
//        for (int i : tA)
//        {
//            cout << i << '\t';
//        }
//
//        cout << endl;
//    }
//
//    return 0;
//}

//int main()
//{
//    vector<vector<int> > A;
//    vector<int> a1;
//    a1.push_back(1);
//    a1.push_back(1);
//    a1.push_back(0);
//    vector<int> a2;
//    a2.push_back(1);
//    a2.push_back(0);
//    a2.push_back(1);
//    A.push_back(a1);
//    A.push_back(a2);
//    for (int a = 0;a < A.size();++a)
//    {
//        for (int i = 0;i < A[a].size() / 2;++i)
//        {
//            if (A[a][i] != A[a][A[a].size() - i - 1])
//            {
//                int t = A[a][A[a].size() - i - 1];
//                A[a][A[a].size() - i - 1] = A[a][i];
//                A[a][i] = t;
//            }
//            A[a][i] ^= 1;
//            A[a][A[a].size() - i - 1] ^= 1;
//        }
//        if (A[a].size() % 2 == 1)
//            A[a][A[a].size() / 2] ^= 1;
//    }
//
//    for (vector<int> tA:A)
//    {
//        for (int i : tA)
//        {
//            cout << i << '\t';
//        }
//
//        cout << endl;
//    }
//
//    return 0;
//}

//int main()
//{
//    vector<vector<int> > A;
//    vector<int> a1;
//    a1.push_back(1);
//    a1.push_back(1);
//    a1.push_back(0);
//    vector<int> a2;
//    a2.push_back(1);
//    a2.push_back(0);
//    a2.push_back(1);
//    A.push_back(a1);
//    A.push_back(a2);
//    vector<vector<int> > B;
//    for (vector<int> tA:A)
//    {
//        vector<int> tB;
//        for(int i = tA.size() - 1;i >= 0;--i)
//        {
//            tB.push_back(tA[i] ^ 1);
//        }
//        B.push_back(tB);
//    }
//
//    for (vector<int> tB:B)
//    {
//        for (int i : tB)
//        {
//            cout << i << '\t';
//        }
//
//        cout << endl;
//    }
//
//    return 0;
//}

int main()
{
    vector<vector<int> > A;
    vector<int> a1;
    a1.push_back(1);
    a1.push_back(1);
    a1.push_back(0);
    vector<int> a2;
    a2.push_back(1);
    a2.push_back(0);
    a2.push_back(1);
    A.push_back(a1);
    A.push_back(a2);
    for (vector<int>& tA:A)
    {
        for (int i = 0;i < (tA.size() + 1) / 2;++i)
        {
            if (tA[i] == tA[tA.size() - i - 1])
            {
                int t = tA[tA.size() - i - 1] ^ 1;
                tA[tA.size() - i - 1] = tA[i] ^ 1;
                tA[i] = t;
            }
        }
    }

    for (vector<int> tA:A)
    {
        for (int i : tA)
        {
            cout << i << '\t';
        }

        cout << endl;
    }

    return 0;
}
