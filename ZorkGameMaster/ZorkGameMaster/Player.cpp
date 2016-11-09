#include "stdafx.h"
#include "Player.h"


Player::Player(const char* Name, const char* Description, Room* Room, const list<Entity*> Locations):Creature(Name,Description,Room,Locations,true)
{
	Type = PLAYER;
}


Player::~Player()
{
}


void Player::Look(const vector<string>& args) const {
	if (args.size() > 1)
	{
		for (list<Entity*>::const_iterator it = Parent->Container.begin(); it != Parent->Container.cend(); ++it)
		{
			if ((*it)->Name == args[1]) // Look for certain object
			{
				(*it)->Look();
				return;
			}
		}

		if (args[1]=="me")
		{
			cout << "\n" << Name << "\n";
			cout << Description << "\n";
		}
	}
	else
	{
		Parent->Look(); // Watch  the things in the room 
	}
}

bool Player::Take(const vector<string>& args) {

	if (args.size() == 4) // Check in Container
	{
		Item* item = (Item*)Parent->Find(args[3], ITEM); // First LOOK IN ROOM 

		// we could pick something from a container in our inventory ...
		if (item == NULL)
			item = (Item*)Find(args[3], ITEM);

		if (item == NULL)
		{
			cout << "\nCannot find '" << args[3] << "' in this room or in your inventory.\n";
			return false;
		}

		Item* subitem = (Item*)item->Find(args[1], ITEM);

		if (subitem == NULL)
		{
			cout << "\n" << item->Name << " does not contain '" << args[1] << "'.\n";
			return false;
		}

		cout << "\nYou take " << subitem->Name << " from " << item->Name << ".\n";
		subitem->ChangeParent(this);

	}else if (args.size() == 2){ // Pick From Room

		Item* item = (Item*)Parent->Find(args[1], ITEM);

		if (item == NULL)
		{
			cout << "\nThere is no item here with that name.\n";
			return false;
		}

		cout << "\nYou take " << item->Name << ".\n";
		item->ChangeParent(this);
	}

	return false;
}

bool Player::Drop(const vector<string>& args) {

	if (args.size() == 2) // Drop Item in Room
	{
		Item* item = (Item*)Find(args[1], ITEM);

		if (item == NULL)
		{
			cout << "\nThere is no item on you with that name.\n";
			return false;
		}

		cout << "\nYou drop " << item->Name << "...\n";
		item->ChangeParent(Parent);

		return true;
	}

	if (args.size() == 4) // Drop Item in container
	{
		Item* item = (Item*)Find(args[1], ITEM);

		if (item == NULL)
		{
			cout << "\nCan not find '" << args[1] << "' in your inventory.\n";
			return false;
		}

		Item* container = (Item*)Parent->Find(args[3], ITEM);

		if (container == NULL)
		{
			container = (Item*)Find(args[3], ITEM);
			cout << "\nCan not find '" << args[3] << "' in your inventory or in the room.\n";
			return false;
		}

		cout << "\nYou put " << item->Name << " into " << container->Name << ".\n";
		item->ChangeParent(container);

		return true;
	}

	return false;
}

void Player::Inventory()const {
	list<Entity*> items;
	FindAll(ITEM, items);

	if (items.size() == 0)
	{
		cout << "\nYou do not own any item.\n";
		return;
	}

	for (list<Entity*>::const_iterator it = items.begin(); it != items.cend(); ++it)
	{
		if (*it == Tool)
			cout << "\n" << (*it)->Name << " (as Tool)";
		else
			cout << "\n" << (*it)->Name;
	}

	cout << "\n";
}


bool Player::Equip(const vector<string>& args) {
	Item* item = (Item*)Find(args[1], ITEM);

	if (item == NULL)
	{
		cout << "\nCannot find '" << args[1] << "' is not in your inventory.\n";
		return false;
	}

	switch (item->Item_Type)
	{
	case TOOL:
		Tool = item;
		break;

	default:
		cout << "\n" << item->Name << " cannot be equipped.\n";
		return false;
	}

	cout << "\nYou equip " << item->Name << "...\n";

	return true;
}

bool Player::UnEquip(const vector<string>& args) {
	if (!Alive)
		return false;

	Item* item = (Item*)Find(args[1], ITEM);

	if (item == NULL)
	{
		cout << "\n" << item->Name << " is not in your inventory.\n";
		return false;
	}

	if (item == Tool) {
		Tool = NULL;

	}
	else
	{
		cout << "\n" << item->Name << " is not equipped.\n";
		return false;
	}

	cout << "\n You un-equip " << item->Name << "...\n";

	return true;
}