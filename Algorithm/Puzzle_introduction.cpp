#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const char inst[] = {"ABLR"};
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main()
{
    int t = 0;
    char s[5][6];
    char ch;
    while (s[0][0] = getchar() != 'z')
    {
        int bi = 0;
        int bj = 0;
        for (int i = 0;i < 5;i++)
        {
            for(int j = 0;j < 5;j++)
            {
                if (!i && !j)
                {
                    continue;
                }
                s[i][j] = getchar();
                if (s[i][j] == ' ')
                {
                    bi = i;
                    bj = j;
                }
            }
            getchar();
        }
        bool legal = true;
        while (ch = getchar() != '0')
        {
            if (legal == false || ch == '\n')
                continue;
            int k;
            for (k = 0;k < 4;k++)
            {
                if (ch == inst[k])
                    break;
            }
            if (k == 4)
                legal = false;
            else
            {
                int ni = bi + dir[k][0];
                int nj = bj + dir[k][1];
                if (0 <= ni && ni < 5 && 0 <= nj && nj < 5)
                {
                    swap(s[bi][bj], s[ni][nj]);
                    bi = ni;
                    bj = nj;
                }
                else
                    legal = false;
            }
        }
        if (++t > 1)
            cout << "\n";
        cout << "Puzzle #" << t << endl;
        if (legal == false)
        {
            cout << "This puzzle has no final configuration.\n";
        }
        else
        {
            for (int i = 0;i < 5;i++)
                for (int j = 0;j < 5;j++)
                    cout << s[i][j] << (j == 4 ? "\n" : " ");
        }
        getchar();
    }
    return 0;
}
