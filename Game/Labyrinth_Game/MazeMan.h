#ifndef MAZEMAN_H_
#define MAZEMAN_H_

#include <Windows.h>
#include "MazeMap.h"

enum direction{U,D,L,R};

class MazeMan
{
public:
	MazeMan(char man = 'T',char manface = R);
	void setPosition(int x,int y);
	void setMap(MazeMap * map);
	bool walkUp();
	bool walkDown();
	bool walkLeft();
	bool walkRight();
	void moveForward(direction direct);
	void start();
private:
	char m_cMan;
	char m_cManFace;
	int m_iSteps;
	COORD m_COORDManCurrentPosition;
	MazeMap * m_pMap;
};

#endif