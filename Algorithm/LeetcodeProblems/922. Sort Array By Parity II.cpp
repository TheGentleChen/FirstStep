#include <iostream>
#include <vector>

using namespace std;

vector<int> main()
{
    vector<int> nums;
    vector<int> ans;
    int odd = 0;
    int even = 0;
    for (int i = 0;i < nums.size() / 2;++i)
    {
        while(num[odd++] % 2 != 0); ans.push_back(num[odd]);

        while(num[even++] % 2 != 1);    ans.push_back(num[even]);
    }
    return ans;
}

vector<int> main()
{
    vector<int> nums;
    vector<int> ans;
    int odd;
    int even = 1;
    for (odd = 0;odd < nums.size();odd += 2)    //算法可行前提：有多少处在错误位置上的odd就有多少处在错误位置上的even
    {
        if (nums[odd] % 2 == 1)                 //寻找一个处在错误位置上的odd
        {
            while (nums[even] % 2 == 1)         //寻找一个处在错误位置上的even
            {
                even += 2;
            }
            swap(nums[odd], num[even]);         //交换二者
        }
    }
    return ans;
}
