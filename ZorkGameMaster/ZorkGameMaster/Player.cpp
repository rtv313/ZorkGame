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

		return true;
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
	FindAll(ITEM,items);

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

	cout << "\nYou un-equip " << item->Name << "...\n";

	return true;
}



bool Player::UseObject(const vector<string> &args) {
	// arg0 Use , arg1 Object, arg2 Action , arg3 ENTITY
	if (Tool == NULL || Tool->Name != args[0]) {
		cout << "\nYou dont have equiped " << args[0];
		return false;
	}

	if (Tool->Name == "PDA") {
		list<Entity*> CreaturesInRoom;
		Parent->FindAll(CREATURE, CreaturesInRoom);

		for (list<Entity*>::const_iterator it = CreaturesInRoom.begin(); it != CreaturesInRoom.cend(); ++it)
		{
			if ((*it)->Name == args[2]){
				cout << "\nScanning and Making Profile of Suspect \n Profile:" << "\n" << (*it)->Name <<" "<< (*it)->Description;
				// Create Note and Add To notebook
				return true;
			}
		}
		cout << "\nThe Suspect is not in the room";
		return false;
	}

	if (Tool->Name == "Notebook") {
		list<Entity*> Notes;
		Tool->FindAll(ITEM, Notes);

		if (Notes.size() <= 0) {
			cout << "\nYou dont have notes";
			return false;
		}

		if (args[1] == "List") {
			cout << "\nNotes in you're Notebook:";
		}

		for (list<Entity*>::const_iterator it = Notes.begin(); it != Notes.cend(); ++it)
		{
			if ((*it)->Name == args[2] && args[1] != "List") {
				cout << "\nReading Note:"<<(*it)->Name << "\n Content:" << " " << (*it)->Description;
				return true;
			}
			else {
				cout << "\nReading Note:" << (*it)->Name << "\n Content:" << " " << (*it)->Description;
			}

		}

		if (args[1] != "List") {
			cout << "\nThat Note is not in the Notebook";
			return false;
		}
		return true;
	}

}

void Player::CheckMap() {

	for (list<Entity*>::const_iterator it = Locations.begin(); it != Locations.cend(); ++it)
	{
		cout << "\nName:" << (*it)->Name<<" Description:"<< (*it)->Description;
		
	}

	return;
}

void Player::Help() {

	string message = "\nWelcome to my Zork Detective Game";

	message += "\nAbout: In this game you must find the suspect that commit the murder you must analize evidence,corpse,talk to suspects and witness,";
	message += "\nINSTRUCTIONS:";

	message += "\nPLAYER ACTIONS:";

	message += "\n\"Help\" = Display Instrucctions";
	message += "\n\"Map\" = Display a list of the rooms";
	message += "\n\"Quit\" = Close the game";
	message += "\n\"Look\" = Show you a list of the characters and stuffs in the room";
	message += "\n\"Inventary\" = Displays the items you have";

	// Two Parameters
	message += "\n \"Look\" {ObjectName} ,this allows you to look inside Containers";
	message += "\n \"Move\" {RoomName} ,this allows you to move between rooms";
	message += "\n \"Take\" {ItemName} ,this allows you to take an item in the room";
	message += "\n \"Equip\" {ItemName} ,this allows you to equip an item from you're inventory";
	message += "\n \"UnEquip\" {ItemName} ,this allows you to Unequip an item and return it to the inventory";
	message += "\n \"Talk\" {Character Name} ,this allows you to start a conversation with a character who is in the same room";
	message += "\n \"Sentence\" {SuspectName} ,this allows you to end the game choosing who is the murder";

	// Three Parameters
	message += "\nPLAYER TOOLS: \n You must have and equiped this items before you can use them.";
	message + "\n Tools and how to use them:";
	message += "\n \"PDA\" \"SCAN\" {EVIDENCE/CHARACTER} ,this allows you to search more info about characters or evidence and add a note to your notebook";
	message += "\n \"Notebook\" \"READ\" {NoteName} ,this allows you to read a specific note";
	message += "\n \"Notebook\" \"LIST\" \"NOTES\" ,Display all the notes in you're Notebook";
	return;
}
