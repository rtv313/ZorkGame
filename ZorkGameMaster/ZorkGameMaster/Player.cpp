#include "stdafx.h"
#include "Player.h"
#include "Npc.h"

Player::Player(const char* Name, const char* Description, Room* Room, const list<Entity*> Locations):Creature(Name,Description,Room,Locations,true){
	Type = PLAYER;
}


Player::~Player(){
}


void Player::Look(const vector<string>& args,vector<Exit*>Exits) const{
	if (args.size() > 1){
		for (list<Entity*>::const_iterator it = Parent->Container.begin(); it != Parent->Container.cend(); ++it){
			if (CompareStrings((*it)->Name,args[1])){ // Look for certain object
				(*it)->Look();
				return;
			}
		}
	}
	else{
		Parent->Look(); // Watch  the things in the room 
		for (vector<Exit*>::const_iterator it = Exits.begin(); it != Exits.cend(); ++it){
			if ((*it)->Room1 == Parent || (*it)->Room2 == Parent){
				cout << "\nDoor:" << (*it)->Name;
			}
		}
	}
}

bool Player::Take(const vector<string>& args){

	if(args.size() == 4){ // Check in Container
	
		Item* item = (Item*)Parent->Find(args[3], ITEM); // First LOOK IN ROOM 

		// we could pick something from a container in our inventory ...
		if (item == NULL) {
			item = (Item*)Find(args[3], ITEM);
		}

		if (item == NULL){
			cout << "\nCannot find '" << args[3] << "' in this room or in your inventory.";
			return false;
		}

		Item* subitem = (Item*)item->Find(args[1], ITEM);

		if (subitem == NULL){
			cout << "\n" << item->Name << " does not contain '" << args[1] << "'.";
			return false;
		}

		cout << "\nYou take " << subitem->Name << " from " << item->Name << ".";
		subitem->ChangeParent(this);

	}else if (args.size() == 2){ // Pick From Room

		Item* item = (Item*)Parent->Find(args[1], ITEM);

		if (item == NULL){
			cout << "\nThere is no item here with that name.";
			return false;
		}

		cout << "\nYou take " << item->Name << ".";
		item->ChangeParent(this);

		return true;
	}

	return false;
}

bool Player::Drop(const vector<string>& args){

	if (args.size() == 2){ // Drop Item in Room
	
		Item* item = (Item*)Find(args[1], ITEM);

		if (item == NULL){
			cout << "\nThere is no item on you with that name.";
			return false;
		}

		cout << "\nYou drop " << item->Name << "...";
		item->ChangeParent(Parent);

		return true;
	}

	if (args.size() == 4){ // Drop Item in container
	
		Item* item = (Item*)Find(args[1], ITEM);

		if (item == NULL){
			cout << "\nCan not find '" << args[1] << "' in your inventory.";
			return false;
		}

		Item* container = (Item*)Parent->Find(args[3], ITEM);

		if (container == NULL){
			container = (Item*)Find(args[3], ITEM);
			cout << "\nCan not find '" << args[3] << "' in your inventory or in the room.";
			return false;
		}

		cout << "\nYou put " << item->Name << " into " << container->Name << ".";
		item->ChangeParent(container);

		return true;
	}

	return false;
}

void Player::Inventory()const{
	list<Entity*> items;
	FindAll(ITEM,items);

	if (items.size() == 0){
		cout << "\nYou do not own any item.";
		return;
	}

	for (list<Entity*>::const_iterator it = items.begin(); it != items.cend(); ++it){
		if (*it == Tool)
			cout << "\n" << (*it)->Name << " (as Tool)";
		else
			cout << "\n" << (*it)->Name;
	}
}


bool Player::Equip(const vector<string>& args){
	Item* item = (Item*)Find(args[1], ITEM);

	if (item == NULL){
		cout << "\nCannot find '" << args[1] << "' is not in your inventory.";
		return false;
	}

	switch (item->Item_Type){
	case TOOL:
		Tool = item;
		break;

	default:
		cout << "\n" << item->Name << " cannot be equipped.";
		return false;
	}

	cout << "\nYou equip " << item->Name << "...";

	return true;
}

bool Player::UnEquip(const vector<string>& args){
	if (!Alive)
		return false;

	Item* item = (Item*)Find(args[1], ITEM);

	if (item == NULL){
		cout << "\n" << args[1] << " is not in your inventory.";
		return false;
	}

	if (item == Tool) {
		Tool = NULL;

	}
	else{
		cout << "\n" << item->Name << " is not equipped.";
		return false;
	}

	cout << "\nYou un-equip " << item->Name << "...";

	return true;
}



bool Player::UseObject(const vector<string> &args){
	// arg0 Use , arg1 Object, arg2 Action , arg3 ENTITY
	if (Tool == NULL || !(CompareStrings(Tool->Name , args[0]))) {
		cout << "\nYou dont have equiped " << args[0];
		return false;
	}

	if (CompareStrings(Tool->Name,"PDA")){
		return ScanObject(args);
	}

	if (CompareStrings(Tool->Name,"Notebook")){
		list<Entity*> Notes;
		Tool->FindAll(ITEM, Notes);

		if (Notes.size() <= 0){
			cout << "\nYou dont have notes";
			return false;
		}

		if (CompareStrings(args[1],"LIST")) {
			cout << "\nNotes in you're Notebook:";
		}

		for (list<Entity*>::const_iterator it = Notes.begin(); it != Notes.cend(); ++it){
			if (CompareStrings((*it)->Name,args[2]) && CompareStrings(args[1],"READ")){
				cout << "\nReading Note:"<<(*it)->Name << "\n Content:" << " " << (*it)->Description;
				return true;
			}
			else {
				cout << "\nNote:" << (*it)->Name << " ,Content:" << " " << (*it)->Description;
			}

		}

		if (!(CompareStrings(args[1],"LIST"))){
			cout << "\nThat Note is not in the Notebook";
			return false;
		}
		return true;
	}

}

void Player::CheckMap(){

	for (list<Entity*>::const_iterator it = Locations.begin(); it != Locations.cend(); ++it){
		cout << "\nRoom:" << (*it)->Name<<",Description:"<< (*it)->Description;
	}
	return;
}

bool Player::Sentence(const vector<string>& args){
	Entity* Suspect =Parent->Find(args[1], NPC);
	if (Suspect != NULL) {
		cout << "\nThe Suspect:" << Suspect->Name << " is found to be guilty of the murder";
		return true;
	}
	cout << "\nThat Suspect is not in the room";
	return false;
}

void Player::Talk(const vector<string>& args) {
	Npc* Character =(Npc *) Parent->Find(args[1], NPC);
	if (Character != NULL) {
		Character->Speak();
		return;
	}
	cout << "\nThat Suspect is not in the room\n";
	return;
}

bool Player::Move(const vector<string>& args, vector<Exit*>Exits){

	for (vector<Exit*>::const_iterator exit = Exits.begin(); exit != Exits.cend(); ++exit){
		if ((*exit)->Room1 == Parent && CompareStrings((*exit)->Room2->Name,args[1])){
			ChangeParent((*exit)->Room2);
			cout << "\n" << Name << " is in " << (*exit)->Room2->Name;
			return true;
		}

		if ((*exit)->Room2 == Parent && CompareStrings((*exit)->Room1->Name, args[1])){
			ChangeParent((*exit)->Room1);
			cout << "\n" << Name << " is in " << (*exit)->Room1->Name;
			return true;
		}
	}
	cout << "\nYou cant get to that room from here or that room doesn't exist";

	return false;
}

bool Player::ScanObject(const vector<string>&args){
	Item* Notebook = (Item*)Find("Notebook", ITEM);
	list<Entity*> PosibleNotes;
	Entity* item = Parent->Find(args[2], ITEM); // First Search for items 

	if(item != NULL){ 
		item->FindAll(ITEM, PosibleNotes);
	}else{
		item = Parent->Find(args[2], CREATURE);
		if (item != NULL) {
			item->FindAll(ITEM, PosibleNotes);
		}
		else {
			cout << "\nthat object doesn't exist or cannot be scanned";
			return false;
		}
	}

	if (Notebook == NULL) {
		cout << "\n You dont have the notebook, you need it for add Notes";
	}

	for (list<Entity*>::const_iterator it = PosibleNotes.begin(); it != PosibleNotes.cend(); ++it) {
		if ((((Item*)(*it))->Item_Type == NOTE)) {
			if (Notebook != NULL) {
				(*it)->ChangeParent(Notebook);
				cout << "\nNote added to Notebook";
			}
			cout << "\nNote: " << (*it)->Name << " Description: " << (*it)->Description;
			return true;
		}
	}
	cout << "\nThe object has been already scan check you're notes";
	return false;
}

void Player::Help(){

	string message = "\nWelcome to my Zork Detective Game";

	message += "\nAbout: \nIn this game you must find the suspect that commit the murder you must analize evidence,\ncorpse,talk to suspects and witness,";
	message += "\n\nINSTRUCTIONS:";

	message += "\n\nPLAYER ACTIONS:";

	message += "\n\n\"Help\" = Display Instrucctions";
	message += "\n\"Rooms\" = Display a list of the rooms";
	message += "\n\"Quit\" = Close the game";
	message += "\n\"Look\" = Show you a list of the characters and stuffs in the room";
	message += "\n\"Inventory\" = Displays the items you have";

	// Two Parameters
	message += "\n\"Look\" {ObjectName} ,this allows you to look inside Containers";
	message += "\n\"Move\" {RoomName} ,this allows you to move between rooms";
	message += "\n\"Take\" {ItemName} ,this allows you to take an item in the room";
	message += "\n\"Take\" {ItemName} in {ItemName} ,this allows you to take an item inside another item";
	message += "\n\"Drop\" {ItemName} ,this allows you to drop an item in the room";
	message += "\n\"Equip\" {ItemName} ,this allows you to equip an item from you're inventory";
	message += "\n\"UnEquip\" {ItemName} ,this allows you to Unequip an item and return it to the inventory";
	message += "\n\"Talk\" {Character Name} ,this allows you to start a conversation with a character who is in the same room";
	message += "\n\"Sentence\" {SuspectName} ,this allows you to end the game choosing who is the murder";

	// Three Parameters
	message += "\n\nPLAYER TOOLS: \n*You must have and equiped this items before you can use them.\n";
	message + "Tools and how to use them:";
	message += "\n\"PDA\" \"SCAN\" {EVIDENCE/CHARACTER} ,this allows you to search more info about characters or evidence \nand add a note to your notebook,HINT:The object must be in the room for scan not inside other object";
	message += "\n\"Notebook\" \"READ\" {NoteName} ,this allows you to read a specific note";
	message += "\n\"Notebook\" \"LIST\" \"NOTES\" ,Display all the notes in you're Notebook";

	cout << message;
	return;
}
