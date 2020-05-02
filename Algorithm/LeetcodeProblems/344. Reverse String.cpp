class Solution {
public:
    string reverseString(string s) {
        int len = s.length();
        if (len <= 1)
            return s;
        string leftStr = s.substr(0, len / 2);
        string rightStr = s.substr(len / 2);
        return reverseString(rightStr) + reverseString(leftStr);
    }
};
