#pragma once
#include "Creature.h"
#include "Player.h"
class Npc :
	public Creature
{
public:
	Npc(const char* Name, const char* Description, Room* Room, const list<Entity*> Locations,bool Alive);
	~Npc();
	vector <string> Conversations;
	void Speak(Player* player);
};

