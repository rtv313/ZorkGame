#pragma once
#include<vector>
#include<string>
#include <iostream>
#include "Item.h"
#include "Room.h"
#include "Player.h"

class World
{
public:
	
	World();
	~World();
	void SendInstrucction(const vector<string>& args);

private:
	vector<Entity*> Entities;
	Player * Player;
};

