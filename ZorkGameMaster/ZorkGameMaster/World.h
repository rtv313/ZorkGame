#pragma once
#include<vector>
#include <list>
#include<string>
#include <iostream>
#include "Item.h"
#include "Room.h"
#include "Creature.h"
#include "Player.h"

class World
{
public:
	
	World();
	~World();
	void SendInstrucction(const vector<string>& args);

private:
	vector<Entity*> Entities;
	list<Entity*> Locations;
	Player * player;
};

