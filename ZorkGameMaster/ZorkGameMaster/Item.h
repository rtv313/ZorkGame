#pragma once
#include "Entity.h"


enum ItemType
{
	TOOL
};

class Item :
	public Entity
{
public:
	Item(const char* Name, const char* Description, Entity* Parent, ItemType item_type = TOOL);
	~Item();
	void Look()const;
	ItemType Item_Type;
};

