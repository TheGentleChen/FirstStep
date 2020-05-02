#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums;                       //”¶”√Õ∞≈≈–Ú
    vector<int> hashtable(20001, 0);
    for (size_t i = 0;i < nums.size();++i)
    {
        hashtable[nums[i] + 10000]++;
    }

    int flag = 0, sum = 0;
    for (size_t i = 0;i < hashtable.size();)
    {
        if (hashtable[i] > 0 && flag == 0)
        {
            hashtable[i]--;
            flag = 1;
            sum += i - 10000;
        }
        else if (hashtable[i] > 0 && flag == 1)
        {
            hashtable[i]--;
            flag = 0;
        }
        else
        {
            i++;
        }
    }
    return sum;
}
