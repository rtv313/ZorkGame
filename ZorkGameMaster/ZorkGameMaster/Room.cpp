#include "stdafx.h"
#include "Room.h"


Room::Room(const char* Name, const char* Description):Entity(Name,Description)
{
	Type = ROOM;
}


Room::~Room()
{
}
