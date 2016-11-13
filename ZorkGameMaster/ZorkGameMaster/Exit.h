#pragma once
#include "Room.h"
class Exit :
	public Entity
{
public:
	Exit(const char* Name, const char* Description,Room*Room1,Room*Room2);
	~Exit();
	Room* Room1;
	Room* Room2;
};

