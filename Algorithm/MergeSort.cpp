#include <iostream>
#include <malloc.h>
using namespace std;

void merge(int data[],int p,int q,int r)
{
	int i , k;
	int begin1,end1,begin2,end2;
	int * temp = (int *)malloc((r - p + 1) * sizeof(int));
	begin1 = p; end1 = q;
	begin2 = q + 1; end2 = r;
	k = 0;
	while ((begin1 <= end1) && (begin2 <= end2))
	{
		if (data[begin1] < data[begin2])
		{
			temp[k] = data[begin1++];
		}
		else
		{
			temp[k] = data[begin2++];
		}
		k++;
	}
	while (begin1 <= end1)
	{
		temp[k++] = data[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[k++] = data[begin2++];
	}

	for (i = 0;i < (r - p + 1);i++)
	{
		data[p + i] = temp[i];
		free(temp);
	}
}

void MergeSort(int data[],unsigned int first,unsigned int last)
{
	int mid = 0;
	if (first < last)
	{
		mid = (first + last) / 2;
		MergeSort(data,first,mid);
		MergeSort(data,mid + 1,last);
		merge(data,first,mid,last);
	}
}

void main()
{
	int data[] = {1,5,2,3,6,100,1,125,156,15,852};
	int size = sizeof(data) / sizeof(int);
	MergeSort(data,0,size - 1);
	for (int i = 0;i < size;i++)
		cout << data[i] << " ";
	cout << "\nDone!\n";
}