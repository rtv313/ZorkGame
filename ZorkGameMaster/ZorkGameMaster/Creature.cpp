#include "stdafx.h"
#include "Item.h"
#include "Creature.h"


Creature::Creature(const char* Name, const char*Description, Room* Room, list<Entity*> const Locations):
	Entity(Name,Description,(Entity *)Room)
{
	Type = CREATURE;
	this->Locations = Locations;
}


Creature::~Creature()
{
}

bool Creature::Move(const vector<string>& args){
	if (!Alive) {
		return false;
	}
		for (list<Entity*>::const_iterator room = Locations.begin(); room != Locations.cend(); ++room)
		{
			if ((*room)->Name== args[1]) {
				ChangeParent((*room));
				return true;
			}
		}

	return false; //room doesnt exist
}

void Creature::Look(const vector<string>& args)const {

	if (Alive)
	{
		cout << Name << "\n";
		cout << Description << "\n";
	}
	else
	{
		cout << Name << "'s corpse\n";
		cout << "Here lies dead: " << Description << "\n";
	}
	
	return;
}

bool Creature::Take(const vector<string> & args) {
	Item* item = (Item*)Parent->Find(args[1], ITEM); //Pick from room

	if (args.size() > 1)
	{
		// we could pick something from a container in our inventory ...
		if (item == NULL)
			item = (Item*)Find(args[1], ITEM);

		if (item == NULL)
			return false;

		Item* subitem = (Item*)item->Find(args[3], ITEM);

		if (subitem == NULL)
			return false;

		if (PlayerInRoom())
			cout << Name << " looks into " << item->Name << "...\n";

		item = subitem;
	}

	if (item == NULL)
		return false;

	if (PlayerInRoom())
		cout << Name << " takes " << item->Name << ".\n";

	item->ChangeParent(this);

	return true;
}

bool Creature::Drop(const vector<string>& args) {
	if (!Alive)
		return false;

	Item* item = (Item*)Find(args[1], ITEM);

	if (item == NULL)
		return false;

	if (PlayerInRoom())
		cout << Name << " drops " << item->Name << "...\n";

	item->ChangeParent(Parent);
}

void Creature::Inventory()const {
	list<Entity*> items;
	FindAll(ITEM, items);

	if (items.size() == 0)
	{
		cout << Name << " does not own any items\n";
		return;
	}

	cout << "\n" << Name << " owns:\n";
	for (list<Entity*>::const_iterator it = items.begin(); it != items.cend(); ++it)
	{
		if (*it == Tool)
			cout << (*it)->Name << " (as Tool)\n";
		else
			cout << (*it)->Name << "\n";
	}
}


bool Creature::Equip(const vector<string>& args) {
	if (!Alive)
		return false;

	Item* item = (Item*)Find(args[1], ITEM);

	if (item == NULL)
		return false;

	switch (item->Type)
	{
	case TOOL:
		Tool = item;
		break;

	default:
		return false;
	}

	if (PlayerInRoom())
		cout << Name << " equips " << item->Name << "...\n";

	return true;
}

bool Creature::UnEquip(const vector<string>& args) {
	if (!Alive)
		return false;

	Item* item = (Item*)Find(args[1], ITEM);

	if (item == NULL)
		return false;

	if (item == Tool)
		Tool = NULL;
	else
		return false;

	if (PlayerInRoom())
		cout << Name << " un-equips " << item->Name << "...\n";
}


bool Creature::PlayerInRoom() const
{

	return Parent->Find(PLAYER) != NULL;
}


