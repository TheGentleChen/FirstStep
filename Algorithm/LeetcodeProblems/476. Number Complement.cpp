class Solution {
public:
    int findComplement(int num) {
        int OXR = ~0;
        while (num & OXR)
        {
            OXR <<= 1;
        }
        return num ^ ~OXR;
    }
};

class Solution {
public:
    int findComplement(int num) {
        int OXR = 1;
        while (num > OXR)
        {
            OXR <<= 1;
            OXR |= 1;
        }
        return num ^ OXR;
    }
};
