//mao_pao_sort
#include <iostream>
using namespace std;

void BulleSort(int * pData,int Count)
{
	int iTemp = 0;
	for (int i = 0;i < Count;i++)
		for (int j = Count - 1;j >= i;j--)
			if(pData[j] < pData[j - 1])
			{
				iTemp = pData[j];
				pData[j] = pData[j - 1];
				pData[j - 1] = iTemp;
			}
}

void main()
{
	int data[] = {10,7,8,3,0,5,1};
	BulleSort(data,7);
	for (int i = 0;i < 7;i++)
		cout << data[i] << " ";
	cout << "\nDone!\n";
}
