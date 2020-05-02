#include <iostream>
using namespace std;

int ShellPass(int * pData,int d)
{
	int temp;
	int k = 0;
	for (int i = d;i < 12;i++)
	{
		if (pData[i] < pData[i - d])
		{
			temp = pData[i];
			int j = i - d;
			do 
			{
				pData[j + d] = pData[j];
				j = j - d;
				k++;
			} while ((j > 0) && (temp < pData[j]));
			pData[j + d] = temp;
		}
		k++;
	}
	return k;
}

void ShellSort(int * pData)
{
	int count = 0;
	int ShellCount = 0;
	int d = 12;
	do
	{
		d = d / 2;
		ShellCount = ShellPass(pData,d);
		count += ShellCount;
	} while (d >= 1);
		cout << "In the ShellSort,the number of moves of the keyword is: " << count << endl;
}

void main()
{
	int data[] = {10,9,8,7,6,5,4,3,2,1,-10,-1};
	int size = sizeof(data) / sizeof(int);
	cout << "size = " << size << endl;
	ShellSort(data);
	for (int i = 0;i < size;i++)
		cout << data[i] << " ";
	cout << "\nDone!\n";
}