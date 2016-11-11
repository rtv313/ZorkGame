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

	list<Entity*> ItemsInside;
	FindAll(ITEM, ItemsInside);

	if (ItemsInside.size() > 0)
	{
		cout << "It contains: " << "\n";
		for (list<Entity*>::const_iterator it = ItemsInside.begin(); it != ItemsInside.cend(); ++it) {
			cout << (*it)->Name << "\n";
		}
	}else {
		cout << "There is nothing attach or inside in this Item: " << "\n";
	}
}

