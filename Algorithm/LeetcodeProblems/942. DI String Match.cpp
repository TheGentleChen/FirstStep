#include <iostream>
#include <vector>

using namespace std;

vector<int> main(string s)                  //Greedy Algorithm:将问题分解成若干个子问题，对子问题求解得到子问题的最优解，直至局部最优最终合并得到全局的最优解
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
