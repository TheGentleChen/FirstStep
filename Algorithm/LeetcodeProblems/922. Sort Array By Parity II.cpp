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
    for (odd = 0;odd < nums.size();odd += 2)    //�㷨����ǰ�᣺�ж��ٴ��ڴ���λ���ϵ�odd���ж��ٴ��ڴ���λ���ϵ�even
    {
        if (nums[odd] % 2 == 1)                 //Ѱ��һ�����ڴ���λ���ϵ�odd
        {
            while (nums[even] % 2 == 1)         //Ѱ��һ�����ڴ���λ���ϵ�even
            {
                even += 2;
            }
            swap(nums[odd], num[even]);         //��������
        }
    }
    return ans;
}
