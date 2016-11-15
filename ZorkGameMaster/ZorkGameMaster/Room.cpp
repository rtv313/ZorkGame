#include "stdafx.h"
#include "Room.h"
#include "Npc.h"
#include <iostream>


Room::Room(const char* Name, const char* Description):Entity(Name,Description,NULL)
{
	Type = ROOM;
}


Room::~Room()
{

}

void Room::Look()const {

	cout << "\nIn Room " << Name;
	cout << "\nDescription:" << Description;

	// Displays Creatures in Room
	for (list<Entity*>::const_iterator it = Container.begin(); it != Container.cend(); ++it){
		if ((*it)->Type == CREATURE){
			Creature * creature = (Creature*)*it;
			cout << "\nCharacter:" << creature->Name;
		}
		else if ((*it)->Type == PLAYER){
			Player * player = (Player*)*it;
			cout << "\nPlayer:" << player->Name;
		}
		else if ((*it)->Type == NPC){
			Npc * npc = (Npc*)*it;
			cout << "\nCharacter:" << npc->Name;

		}else if ((*it)->Type == ITEM) {
			Item* item = (Item*)*it;
			cout << "\nItem:" << item->Name;
		}
	}
}