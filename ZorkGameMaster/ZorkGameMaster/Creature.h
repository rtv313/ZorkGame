#pragma once
#include "Entity.h"
#include "Item.h"

class Room;
class Creature :
	public Entity
{
public:
	Item* Tool;
	bool Alive;
	list<Entity*> Locations;
	Creature(const char* Name, const char* Description, Room* Room,const list<Entity*> &Locations,bool Alive);
	~Creature();
	virtual bool Move(const vector<string>& args);
	virtual void Look(const vector<string>& args) const;
	virtual bool Take(const vector<string>& args);
	virtual bool Drop(const vector<string>& args);
	virtual void Inventory() const;
	virtual bool Equip(const vector<string>& args);
	virtual bool UnEquip(const vector<string>& args);
	bool PlayerInRoom() const;
};

