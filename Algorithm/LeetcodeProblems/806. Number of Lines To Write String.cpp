class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int line = 1;
        int last = 0;
        for (auto item:S)
        {
            int width = widths[item - 'a'];
            last += width;
            if (last > 100)
            {
                line++;
                last = width;
            }
        }

        vector<int> ret;
        ret.push_back(line);
        ret.push_back(last);
        return ret;
    }
};
