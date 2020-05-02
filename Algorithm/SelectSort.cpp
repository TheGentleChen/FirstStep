#include <iostream>
using namespace std;

void SelectSort(int * pData,int Count)
{
	int iTemp;
	int iPos;

	for (int i = 0;i < Count - 1;i++)
	{
		iTemp = pData[i];
		iPos = i;
		for (int j = i + 1;j < Count;j++)
		{
			if (pData[j] < iTemp)
			{
				iTemp = pData[j];
				iPos = j;
			}
		}
		pData[iPos] = pData[i];
		pData[i] = iTemp;
	}
}

void main()
{
	int data[] = {10,9,8,7,6,15,4,3};
	int size = sizeof(data) / sizeof(int);
	SelectSort(data,size);
	for (int i = 0;i < size;i++)
		cout << data[i] << " ";
	cout << "\nDone!\n";
}