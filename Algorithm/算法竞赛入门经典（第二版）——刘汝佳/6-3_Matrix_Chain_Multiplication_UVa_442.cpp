#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Matrix
{
    int a, b;
    Matrix(int ax = 0, int bx = 0):a(ax), b(bx){}
}m[26];

stack<Matrix> s;

int main()
{
    int n;
    cin >> n;
    for (int i = 0;i < n;++i)\
    {
        string name;
        cin >> name;
        int k = name[0] - 'A';
        cin >> m[k].a >> m[k].b;
    }
    string expr;
    while (cin >> expr)
    {
        int len = expr.length();
        bool error = false;
        int ans = 0;
        for (int i = 0;i < len;++i)
        {
            if (isalpha(expr[i]))   s.push(m[expr[i] - 'A']);
            else if (expr[i] == ')')
            {
                Matrix m2 = s.top();    s.pop();
                Matrix m1 = s.top();    s.pop();
                if (m1.b != m2.a)   {error = true; break;}
                ans += m1.a * m1.b * m2.b;
                s.push(Matrix(m1.a, m2.b));
            }
        }
        if (error)  cout << "error\n";
        else    cout << ans << endl;
    }

    return 0;
}
