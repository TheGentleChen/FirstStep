#include <iostream>
#include <stdlib.h>
using namespace std;
namespace myNum
{
	int x = 105;
}
int main()
{
	bool isFlag = false;
	if(myNum::x % 2 == 0)
	{
		isFlag = false;
	}
	else
	{
		isFlag = true;
	}
	if(isFlag)
	{
		cout << "xΪ����" << endl;
	}
	else
	{
		cout << "xΪż��" << endl;
	}
}
