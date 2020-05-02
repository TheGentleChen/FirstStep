#include "MazeMan.h"
#include "MazeMap.h"

#define MapRow 11
#define MapCol 11

int main()
{
	int map[MapRow][MapCol] = {
		{WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
		{WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD},
		{WALL, ROAD, WALL, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL},
		{WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, WALL},
		{WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, WALL},
		{WALL, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, WALL, ROAD, WALL},
		{WALL, ROAD, WALL, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL},
		{WALL, ROAD, WALL, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, WALL},
		{WALL, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL, ROAD, WALL},
		{ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, WALL},
		{WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}
	};
	MazeMap * mm = new MazeMap();
	mm->setMazeMap(&map[0][0],MapRow,MapCol);
	mm->setExitPosition(10,1);
	mm->pintMazeMap();
	MazeMan * man = new MazeMan();
	man->setPosition(0,9);
	man->setMap(mm);
	man->start();
	delete mm;
	mm = nullptr;
	delete man;
	man = nullptr;
	std::cout << "Nice,You have done!!" << std::endl;
	system("pause");
}