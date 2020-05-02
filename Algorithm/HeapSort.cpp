#include <iostream>
using namespace std;

void heapRebuild(int arr[],int root,int size);
void heapSort(int arr[],int size);

int main()
{
	const int SIZE = 10;
	int arr[SIZE] = {10,2,13,41,23,52,7,31,65,90};
	cout << "original array arr: " << endl;
	for (int i = 0;i < SIZE;i++)
		cout << i + 1 << " item is: " << arr[i] << endl;
	cout << "after heap sorting: " << endl;
	heapSort(arr,SIZE);
	for (int i = 0;i < SIZE;i++)
		cout << i + 1 << " item is: " << arr[i] << endl;
	return 0;
}

void heapRebuild(int arr[],int root,int size)
{
	int child = root * 2 + 1;
	if (child <= size - 1)
	{
		int rightchild = child + 1;
		if (rightchild <= size - 1)
			if (arr[child] < arr[rightchild])
				child = rightchild;
		if (arr[root] < arr[child])
		{
			int temp = arr[child];
			arr[child] = arr[root];
			arr[root] = temp;
			heapRebuild(arr,child,size);
		}
	}
}

void heapSort(int arr[],int size)
{
	for (int i = size - 1;i >= 0;i--)
		heapRebuild(arr,i,size);
	int last = size - 1;
	for (int i = 1;i <= size;i++,last--)
	{
		int temp = arr[0];
		arr[0] = arr[last];
		arr[last] = temp;
		heapRebuild(arr,0,last);
	}
}