#include "MazeMan.h"

MazeMan::MazeMan(char man,char manface)
{
	m_cMan = man;
	m_cManFace = manface;
	m_iSteps = 0;
}

void MazeMan::setMap(MazeMap * map)
{
	m_pMap = map;
}

void MazeMan::setPosition(int x,int y)
{
	unsigned long numWritten;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	m_COORDManCurrentPosition.X = x;
	m_COORDManCurrentPosition.Y = y;
	FillConsoleOutputCharacter(handle,m_cMan,1,m_COORDManCurrentPosition,&numWritten);
}

void MazeMan::moveForward(direction direct)
{
	unsigned long numWritten;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	FillConsoleOutputCharacter(handle,m_pMap->m_cRoad,1,m_COORDManCurrentPosition,&numWritten);
	switch(direct)
	{
	case U:
		m_COORDManCurrentPosition.Y -= 1;
		break;
	case D:
		m_COORDManCurrentPosition.Y += 1;
		break;
	case L:
		m_COORDManCurrentPosition.X -= 1;
		break;
	case R:
		m_COORDManCurrentPosition.X += 1;
		break;
	default:
		break;
	}

	FillConsoleOutputCharacter(handle,m_cMan,1,m_COORDManCurrentPosition,&numWritten);
		m_cManFace = direct;
}

bool MazeMan::walkUp()
{
	if (m_pMap->getMap()[m_COORDManCurrentPosition.Y - 1][m_COORDManCurrentPosition.X])
		return false;
	else
		moveForward(U);
	return true;
}

bool MazeMan::walkDown()
{
	if (m_pMap->getMap()[m_COORDManCurrentPosition.Y + 1][m_COORDManCurrentPosition.X])
		return false;
	else
		moveForward(D);
	return true;
}

bool MazeMan::walkLeft()
{
	if (m_pMap->getMap()[m_COORDManCurrentPosition.Y][m_COORDManCurrentPosition.X - 1])
		return false;
	else
		moveForward(L);
	return true;
}

bool MazeMan::walkRight()
{
	if (m_pMap->getMap()[m_COORDManCurrentPosition.Y][m_COORDManCurrentPosition.X + 1])
		return false;
	else
		moveForward(R);
	return true;
}

void MazeMan::start()
{
	while(true)
	{
		m_pMap->pintMazeMap();
		switch(m_cManFace)
		{
		case U:
			walkRight() || walkUp() || walkLeft() || walkDown();
			break;
		case D:
			walkLeft() || walkDown() || walkRight() || walkUp();
			break;
		case L:
			walkUp() || walkLeft() || walkDown() || walkRight();
			break;
		case R:
			walkDown() || walkRight() || walkUp() || walkLeft();
			break;
		default:
			break;
		}
		m_iSteps++;
		if(m_COORDManCurrentPosition.X == m_pMap->m_COORDExitPostion.X && m_COORDManCurrentPosition.Y == m_pMap->m_COORDExitPostion.Y)
			break;
		std::cout << "You have walk " << m_iSteps - 1 << " step.";
		Sleep(500);
	}
}