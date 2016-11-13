#pragma once
#include<vector>
#include <list>
#include<string>
#include <iostream>
#include "Item.h"
#include "Room.h"
#include "Creature.h"
#include "Player.h"
#include "Helpers.h"
#include "Exit.h"

class World
{
public:
	
	World();
	~World();
	void SendInstrucction(const vector<string>& args,bool &ExitFlag);

private:
	vector<Entity*> Entities;
	vector<Exit*> Exits;
	list<Entity*> Locations;
	Player * player;
};

