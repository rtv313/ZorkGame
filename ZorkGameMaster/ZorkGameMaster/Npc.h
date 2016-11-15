#pragma once
#include "Player.h"
#include "Dialog.h"
class Npc :
	public Creature
{
public:
	Npc(const char* Name, const char* Description, Room* Room, const list<Entity*> Locations,bool Alive,vector<string>&Questions, vector <string>&Answers);
	~Npc();
	vector <string> Questions;
	vector <string> Answers;
	void Speak( );
};

