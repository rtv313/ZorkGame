#include "stdafx.h"
#include "Item.h"


Item::Item(const char* Name, const char* Description, Entity* Parent, ItemType Item_type):
	Entity(Name,Description,Parent)
{
	this->Item_Type = Item_type;
	Type = ITEM;
}


Item::~Item()
{
}


void Item::Look()const {

	cout << "\n" << Name << "\n";
	cout << Description << "\n";

	list<Entity*> Stuff;
	FindAll(ITEM, Stuff);

	if (Stuff.size() > 0)
	{
		cout << "It contains: " << "\n";
		for (list<Entity*>::const_iterator it = Stuff.begin(); it != Stuff.cend(); ++it) {
			cout << (*it)->Name << "\n";
		}
	}
	
}