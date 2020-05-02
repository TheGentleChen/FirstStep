#include <iostream>
#include <vector>

using namespace std;

vector<int> main(string s)                  //Greedy Algorithm:������ֽ�����ɸ������⣬�����������õ�����������Ž⣬ֱ���ֲ��������պϲ��õ�ȫ�ֵ����Ž�
{                                           //Time Complexity: O(N)O(N), where NN is the length of S.
    vector<int> ans;                        //Space Complexity: O(N)O(N).
    int hi = s.length();
    int lo = 0;
    for (int i = 0;i < len;++i)
    {
        if (s[i] == 'I')    ans.push_back(lo++);
        else                ans.push_back(hi--);
    }
    ans.push_back(lo);
    return ans;
}

//vector<int> main(string s)
//{
//    int len = s.length();
//    vector<int> ans(len + 1, 0);
//    int index = 0;
//    for (int i = 0;i < len;++i)
//    {
//        if (s[i] == 'I')    ans[i] = index++;
//    }
//    ans[len] = index++;
//    for (int i = len - 1;i >= 0;--i)
//    {
//        if (s[i] == 'D')    ans[i] = index++;
//    }
//    return ans;
//}
