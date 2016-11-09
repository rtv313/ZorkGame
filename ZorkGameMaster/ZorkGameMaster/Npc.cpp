#include "stdafx.h"
#include "Npc.h"


Npc::Npc(const char* Name, const char* Description, Room* Room, const list<Entity*> Locations):Creature(Name,Description,Room,Locations)
{

}


Npc::~Npc()
{
}
