#pragma once
#include "Creature.h"
class Npc :
	public Creature
{
public:
	Npc(const char* Name, const char* Description, Room* Room, const list<Entity*> Locations,bool Alive);
	~Npc();
};

