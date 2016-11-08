#include "stdafx.h"
#include "Room.h"
#include <iostream>


Room::Room(const char* Name, const char* Description):Entity(Name,Description,NULL)
{
	Type = ROOM;
}


Room::~Room()
{

}

void Room::Look()const {

	cout << "\n" << Name << "\n";
	cout << "\n" << Description << "\n";

	for (list<Entity*>::const_iterator it = Container.begin(); it != Container.cend(); ++it)
	{
		if ((*it)->Type == ITEM)
		{
			/*Item* item = (Item*)*it;
			cout << "\nThere is an item here: " << item->name;*/
			cout << "Displaying Items" << "\n";
		}
	}
}