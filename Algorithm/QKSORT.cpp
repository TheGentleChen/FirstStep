//QKSORT_AlGERITHM
#include <iostream>

using namespace std;
void qsort(int x,int y,int * a);
int main()
{
	int a[10] = {2,1,3,5,4,6,8,9,7,10};
	qsort(0,9,a);
	for (int i = 0;i < 9;i++)
		cout << a[i] << " ";
	return 0;
}
void qsort(int x,int y,int * a)
{
	int h = x,r = y;
	int m = a[(x + y) >> 1];
	while (h < r)
	{
		while (a[h] <= m) h++;
		while (a[r] >= m) r--;
		if (h <= r)
		{
			int temp = a[h];
			a[h] = a[r];
			a[r] = temp;
			h++;r--;
		}
	}
	if (r > x) qsort(x,r,a);
	if (h < y) qsort(h,y,a);
}

