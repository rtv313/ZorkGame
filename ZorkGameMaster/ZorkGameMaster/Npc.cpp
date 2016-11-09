#include "stdafx.h"
#include "Npc.h"


Npc::Npc(const char* Name, const char* Description, Room* Room, const list<Entity*> Locations,bool Alive):Creature(Name,Description,Room,Locations,Alive)
{

}


Npc::~Npc()
{
}
