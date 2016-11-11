#pragma once
#include "Creature.h"
class Player :
	public Creature
{
public:
	Player(const char* Name, const char* Description, Room* Room, const list<Entity*> Locations);
	~Player();
	
	void Look(const vector<string>& args) const;
	bool Take(const vector<string>& args);
	bool Drop(const vector<string>& args);
	void Inventory() const;
	bool Equip(const vector<string>& args);
	bool UnEquip(const vector<string>& args);
	bool UseObject(const vector<string>& args);
	
};


