#ifndef MAZEMAP_H_
#define MAZEMAP_H_

#include <iostream>
#include <Windows.h>

#define WALL 1
#define ROAD 0

class MazeMap
{
public:
	MazeMap(char wall = 'X');
	~MazeMap();
	void setMazeMap(int * mazemap,int row,int col);
	void pintMazeMap();
	int ** getMap();
	const char m_cRoad;
	void setExitPosition(int x,int y);
	COORD m_COORDExitPostion;
private:
	const char m_cWall;
	int ** m_pMap;
	int m_iMapRow;
	int m_iMapCol;
};

#endif