#include <iostream>
using namespace std;

inline void swap(int v[],int j,int k)
{
	int temp;
	temp = v[j];
	v[j] = v[k];
	v[k] = temp;
}

void qsort(int v[],int left,int right)
{
	int last;
	if (left >= right)
	{
		return;
	}

	swap(v,left,(left + right) / 2);
	last = left;

	for (int i = left + 1;i <= right;i++)
	{
		if (v[i] < v[left])
		{
			swap(v,++last,i);
		}
	}
	swap(v,left,last);
	qsort(v,left,last - 1);
	qsort(v,last + 1,right);
}

void main()
{
	int data[] = {10,15,2,158,23,10,25,147,189};
	int size = sizeof(data) / sizeof(int);
	qsort(data,0,size - 1);
	for (int i = 0;i < size;i++)
		cout << data[i] << " ";
	cout << "\nDone!\n";
}