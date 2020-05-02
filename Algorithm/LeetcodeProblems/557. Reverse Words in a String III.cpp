class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string item = "";
        string ret = "";
        bool is_first = true;
        while (getline(ss, item, ' '))
        {
            reverse(item.begin(), item.end());

            if (is_first)
            {
                ret += item;
                is_first = false;
            }
            else
            {
                ret += " " + item;
            }
        }
        return ret;
    }
};
