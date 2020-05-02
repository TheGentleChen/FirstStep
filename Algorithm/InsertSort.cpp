#include <iostream>
using namespace std;

void InsertSort(int * pData,int Count)
{
	int iTemp;
	int iPos;
	for (int i = 1;i < Count;i++)
	{
		iTemp = pData[i];
		iPos = i - 1;
		while ((iPos >= 0) && (iTemp < pData[iPos]))
		{
			pData[iPos + 1] = pData[iPos];
			iPos--;
		}
		pData[iPos + 1] = iTemp;
	}
}

void main()
{
	int data[] = {100,10,2,5,41,10,23,15,2};
	int size = sizeof(data) / sizeof(int);
	InsertSort(data,size);
	for (int i = 0;i < size;i++)
		cout << data[i] << " ";
	cout << "\nDone!\n";
}