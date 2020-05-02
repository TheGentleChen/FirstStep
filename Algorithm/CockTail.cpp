#include <iostream>
using namespace std;

void CockTail(int * pData,int Size)
{
	int tail = Size - 1;
	for (int i = 0;i < tail;)
	{
		for (int j = tail;j >= i;j--)
			if (pData[j] < pData[j - 1])
			{
				int temp = pData[j];
				pData[j] = pData[j - 1];
				pData[j - 1] = temp;
			}
			++i;
			for (int j = i;j < tail;j++)
			{
				if (pData[j] > pData[j + 1])
				{
					int temp = pData[j];
					pData[j] = pData[j + 1];
					pData[j + 1] = temp;
				}
			}
			tail--;
	}		
}

void main()
{
	int data[] = {10,5,16,123,2,45,12,12,48,100,1000};
	CockTail(data,sizeof(data) / sizeof(int));
	for (int i = 0;i < 11;i++)
		cout << data[i] << " ";
	cout << "\n";
	int a = sizeof(data) / sizeof(int);
	cout << "a = " << a << endl;
}