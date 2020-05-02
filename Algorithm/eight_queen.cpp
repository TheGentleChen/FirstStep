#include <iostream>
using namespace std;

static int gEightQueen[8] = {0} , gCount = 0;

void print();
bool chack_pos_vaild(int row,int col);
void eight_queen(int row);

int main()
{
	eight_queen(0);
	cout << "total = " << gCount << endl;
	return 0;
}

void print()
{
	for(int i = 0;i < 8;i++)
	{
		int inner;
		for(inner = 0;inner < gEightQueen[i];inner++)
			cout << "0";
		cout << "#";
		for(inner = gEightQueen[i] + 1;inner < 8;inner++)
			cout << "0";
		cout << endl;
	}
	cout << "==============================\n";
}

bool chack_pos_vaild(int row,int col)
{
	int r;
	int c;
	for(r = 0;r < row;r++)
	{
		c = gEightQueen[r];
		if (col == c)
			return false;
		if ((r + c) == (row + col))
			return false;
		if ((r - c) == (row - col))
			return false;
	}
	return true;
}

void eight_queen(int row)
{
	int col;
	for (col = 0;col < 8;col++)
	{
		if (chack_pos_vaild(row,col))
		{
			gEightQueen[row] = col;
			if (7 == row)
			{
				gCount++;
				print();
				gEightQueen[row] = 0;
				return;
			}
			eight_queen(row + 1);
			gEightQueen[row] = 0;
		}
	}
}