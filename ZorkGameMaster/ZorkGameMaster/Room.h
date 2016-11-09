#pragma once
#include "Entity.h"
#include "Item.h"
#include "Creature.h"
#include "Player.h"
#include <string>
#include <list>

using namespace std;

class Room : public Entity{

public:
	Room(const char* Name,const char* Description);
	void Look() const;
	~Room();
};

