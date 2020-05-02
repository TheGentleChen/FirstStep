#include <iostream>
#include <Cstdlib>
using namespace std;

static int count = 0;
void Tower_of_Hanoi(int n, char A, char B, char C)
{
    if (1 == n)
    {
      count++;
      cout << count << " : " << A << " move to " << C << endl;
    }
    else
    {
        Tower_of_Hanoi(n - 1, A, C, B);
        count++;
        cout << count << " : " << A << " move to " << C << endl;
        Tower_of_Hanoi(n - 1, B, A, C);
    }
}

int main()
{
    Tower_of_Hanoi(3, 'A', 'B', 'C');
    system("pause");
    return 0;
}
