#include "MazeMap.h"
using namespace std;
MazeMap::MazeMap(char wall /* = 'X' */):m_cWall(wall),m_cRoad(' ')
{
	m_pMap = nullptr;
}

MazeMap::~MazeMap()
{
	if (m_pMap)
	{
		for (int i = 0;i < m_iMapRow;i++)
		{
			delete m_pMap[i];
			m_pMap[i] = nullptr;
		}
		delete m_pMap;
	}
}

void MazeMap::setMazeMap(int * mazemap,int row,int col)
{
	m_iMapRow = row;
	m_iMapCol = col;
	m_pMap = new int *[m_iMapRow];
	for(int i = 0;i < m_iMapRow;i++)
		m_pMap[i] = new int[m_iMapCol];

	for (int i = 0;i < m_iMapRow;i++)
	{
			for(int j = 0;j < m_iMapCol;j++)
		{
			m_pMap[i][j] = *mazemap;
			mazemap++;
		}
	}
}

void MazeMap::pintMazeMap()
{
	system("cls");
	for(int i = 0;i < m_iMapRow;i++)
	{
		for(int j = 0;j < m_iMapCol;j++)
		{
			if (m_pMap[i][j])
				cout << m_cWall;
			else
				cout << m_cRoad;
		}
		cout << endl;
	}
}


int ** MazeMap::getMap()
{
	return m_pMap;
}

void MazeMap::setExitPosition(int x,int y)
{
	m_COORDExitPostion.X = x;
	m_COORDExitPostion.Y = y;
}